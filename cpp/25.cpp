#include <iostream>
#include <algorithm> 
#include <vector>
#include <map>

using namespace std;


bool compare_score(const pair<string, int> &p1, const pair<string, int> &p2) {
	return p1.second > p2.second;
}
	
bool compare_id(const pair<string, vector<int> > &p1, const pair<string, vector<int> > &p2) {
	// c++ string 没有重载比较符，需要调用compare函数
	return (p1.first).compare(p2.first) < 0;
}

bool compare_rank(const pair<string, vector<int> > &p1, const pair<string, vector<int> > &p2) {
	return (p1.second)[0] < (p2.second)[0];
}

int main() {
	// 结果表 
	// 键为学号，值为三个整数，分别表示最终排名、区域号、区域排名 
	map<string, vector<int> > result;
	int N;
	cin >> N;
	// 最终排名表 
	vector<pair<string, float> > final_rank;
	for (int i = 0; i < N; i++) {
		// 区域排名表 
		vector<pair<string, float> > local_rank;
		int K;
		cin >> K;
		for (int j = 0; j < K; j++) {
			string id;
			float score;
			cin >> id >> score;
			vector<int> temp(3, 0);
			temp[1] = i + 1;
			result.insert(pair<string, vector<int> >(id, temp));
			local_rank.push_back(pair<string, float>(id, score));
			final_rank.push_back(pair<string, float>(id, score));
		}
		// 导入地方排名成绩 
		sort(local_rank.begin(), local_rank.end(), compare_score);
		int rank = 1;
		float last_score = -1;
		int last_rank = -1;
		for (vector<pair<string, float> >::iterator itr = local_rank.begin(); itr != local_rank.end(); itr++) {
			// 处理并列成绩 
			if (itr->second == last_score) {
				result[itr->first][2] = last_rank;
			}
			else {
				result[itr->first][2] = rank;
				last_rank = rank;
			}
			last_score = itr->second;
			rank++;
		}
	}
	
	// 和之前一样，导入最终成绩 
	sort(final_rank.begin(), final_rank.end(), compare_score);
	int rank = 1;
	float last_score = -1;
	int last_rank = -1;
 	for (vector<pair<string, float> >::iterator itr = final_rank.begin(); itr != final_rank.end(); itr++) {
		if (itr->second == last_score) {
			result[itr->first][0] = last_rank;
		}
		else {
			result[itr->first][0] = rank;
			last_rank = rank;
		}
		last_score = itr->second;
		rank++;
	}
	 
	// 先把map转化为vector
	vector<pair<string, vector<int> > > result_v;
	for (map<string, vector<int> >::iterator itr = result.begin(); itr != result.end(); itr++) {
		result_v.push_back(*itr);
	} 
	// 按照分数、学号的优先级排序，实际上就是先后执行两次稳定排序 
	// 注意一定要稳定排序，不稳定排序不能保证相等值的相对顺序不变 
	stable_sort(result_v.begin(), result_v.end(), compare_id);
	stable_sort(result_v.begin(), result_v.end(), compare_rank);
	
	// 输出结果表
	cout << result.size() << endl;
	for (vector<pair<string, vector<int> > >::iterator itr = result_v.begin(); itr != result_v.end(); itr++) {
		cout << itr->first << " " << itr->second[0] << " " << itr->second[1] << " " << itr->second[2] << endl;
	} 
}
