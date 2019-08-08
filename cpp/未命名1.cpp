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
	// ��ʼ��һ��ʱ��� 
	vector<pair<int, int> > time_table;
	for (int i = 0; i < N; i++) {
		int begin, end;
		cin >> begin >> end;
		time_table.push_back(pair<int, int>(begin, end));
	}
	
	// Ԥ�������ʱ����ϴ��ڰ�����ϵ����ȡ�̵�ʱ���
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
	
	// ����Ŀ���տ�ʼʱ������
	sort(time_table.begin(), time_table.end(), compare);
	
//	cout << "result after preprocessing.." << endl;
//	for (vector<pair<int, int> >::iterator itr = time_table.begin(); itr != time_table.end(); itr++) {
//		cout << itr->first << ", " << itr->second << endl;
//	}

	int num = 0;
	// ��һ�ν�����ʱ�䣬��ʼ��Ϊ0 
	int last_end = 0;
	for (int i = 0; i < time_table.size(); i++) {
		// ��������Ŀ����һ������֮ǰ�ſ�ʼ�ģ������� 
		if (time_table[i].first < last_end) {
			continue;
		}
		last_end = time_table[i].second;
		num++;
	}
	cout << num << endl;
} 
