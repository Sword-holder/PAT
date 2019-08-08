#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	int N;
	cin >> N;
	// 初始化一个时间表 
	vector<pair<int, int> > time_table;
	for (int i = 0; i < N; i++) {
		int begin, end;
		cin >> begin >> end;
		time_table.push_back(pair<int, int>(begin, end));
	}
	
	// 预处理，如果时间段上存在包含关系，则取短的时间段
	vector<int> remove_list;
	for (int i = 0; i < time_table.size(); i++) {
		for (int j = i + 1; j < time_table.size(); j++) {
			if (time_table[i].first <= time_table[j].first && time_table[i].second >= time_table[j].second) {
				remove_list.push_back(i);
			}
			else if (time_table[i].first >= time_table[j].first && time_table[i].second <= time_table[j].second) {
				remove_list.push_back(j);
			}
		}
	}
	
//	cout << "remove list:" << endl;
//	for (int i = 0; i < remove_list.size(); i++) {
//		cout << remove_list[i] << " ";
//	}
//	cout << endl;
	
	int i = 0;
	vector<pair<int, int> > new_time_table;
	for (vector<pair<int, int> >::iterator itr = time_table.begin(); itr != time_table.end(); itr++) {
		if (find(remove_list.begin(), remove_list.end(), i) == remove_list.end()) {
			new_time_table.push_back(*itr);
		}
		i++;
	}
	time_table = new_time_table;
	
	// 将节目表按照开始时间排序
	sort(time_table.begin(), time_table.end(), compare);
	
//	cout << "result after preprocessing.." << endl;
//	for (vector<pair<int, int> >::iterator itr = time_table.begin(); itr != time_table.end(); itr++) {
//		cout << itr->first << ", " << itr->second << endl;
//	}

	int num = 0;
	// 上一次结束的时间，初始化为0 
	int last_end = 0;
	for (int i = 0; i < time_table.size(); i++) {
		// 如果这个节目是上一个结束之前才开始的，就跳过 
		if (time_table[i].first < last_end) {
			continue;
		}
		last_end = time_table[i].second;
		num++;
	}
	cout << num << endl;
} 
