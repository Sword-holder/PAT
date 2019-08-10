#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool socreCmp(const pair<int, double>& a, const pair<int, int>& b) {
	return a.second > b.second;
}

// 这道题看似简单，实际上不太好写 
int main() {
	// result用于存储最后的结果，键为学号，值为（最高名次， 学科号）二元组 
	map<int, pair<int, char> > result;
	
	// 这三个数据结构是表示C、M、E单科成绩表以及平均分成绩表，pair中第一个元素是学号，第二个元素是分数 
	vector<pair<int, int> > C, M, E, A;
	int N, Q;
	cin >> N >> Q;
	while (N--) {
		// 录入成绩 
		int id;
		double c_score, m_score, e_score, a_score;
		cin >> id >> c_score >> m_score >> e_score;
		a_score = (c_score + m_score + e_score) / 3;
		C.push_back(pair<int, int>(id, c_score));
		M.push_back(pair<int, int>(id, m_score));
		E.push_back(pair<int, int>(id, e_score));
		A.push_back(pair<int, int>(id, a_score));
		// 初始化结果表，内容先随便写着 
		result[id] = pair<int, char>(INT_MAX, 'N'); 
	}
	
	sort(A.begin(), A.end(), socreCmp);
	sort(C.begin(), C.end(), socreCmp);
	sort(M.begin(), M.end(), socreCmp);
	sort(E.begin(), E.end(), socreCmp);
	
	// 遍历单科成绩表，按照排名更新排名和科目代码 
	// 按照A、C、M、E的顺序更新，就可以保证优先级 
	int i = 0;
	int rank = 0;
	int last_score = -1;
	for (vector<pair<int, int> >::iterator itr = A.begin(); itr != A.end(); itr++, i++) {
		// 如果这门科目的成绩更高，就更新排名和科目代码
		if (last_score != itr->second) {
			last_score = itr->second;
			rank = i;
		}
		if (result[itr->first].first > rank) {
			result[itr->first].first = rank;
			result[itr->first].second = 'A';
		}
	} 
	i = 0;
	rank = 0;
	last_score = -1;
	for (vector<pair<int, int> >::iterator itr = C.begin(); itr != C.end(); itr++, i++) {
		if (last_score != itr->second) {
			last_score = itr->second;
			rank = i;
		}
		if (result[itr->first].first > rank) {
			result[itr->first].first = rank;
			result[itr->first].second = 'C';
		}
	} 
	i = 0;
	rank = 0;
	last_score = -1;
	for (vector<pair<int, int> >::iterator itr = M.begin(); itr != M.end(); itr++, i++) {
		if (last_score != itr->second) {
			last_score = itr->second;
			rank = i;
		}
		if (result[itr->first].first > rank) {
			result[itr->first].first = rank;
			result[itr->first].second = 'M';
		}
	} 
	i = 0;
	rank = 0;
	last_score = -1;
	for (vector<pair<int, int> >::iterator itr = E.begin(); itr != E.end(); itr++, i++) {
		if (last_score != itr->second) {
			last_score = itr->second;
			rank = i;
		}
		if (result[itr->first].first > rank) {
			result[itr->first].first = rank;
			result[itr->first].second = 'E';
		}
	} 
	
	// 输出查询结果 
	while (Q--) {
		int id;
		cin >> id;
		map<int, pair<int, char> >::iterator itr = result.find(id);
		if (itr != result.end()) {
			cout << itr->second.first + 1 << " " << itr->second.second << endl;
		}
		else {
			cout << "N/A" << endl;
		}
	}
} 

