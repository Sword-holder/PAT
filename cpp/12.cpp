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

// ����⿴�Ƽ򵥣�ʵ���ϲ�̫��д 
int main() {
	// result���ڴ洢���Ľ������Ϊѧ�ţ�ֵΪ��������Σ� ѧ�ƺţ���Ԫ�� 
	map<int, pair<int, char> > result;
	
	// ���������ݽṹ�Ǳ�ʾC��M��E���Ƴɼ����Լ�ƽ���ֳɼ���pair�е�һ��Ԫ����ѧ�ţ��ڶ���Ԫ���Ƿ��� 
	vector<pair<int, int> > C, M, E, A;
	int N, Q;
	cin >> N >> Q;
	while (N--) {
		// ¼��ɼ� 
		int id;
		double c_score, m_score, e_score, a_score;
		cin >> id >> c_score >> m_score >> e_score;
		a_score = (c_score + m_score + e_score) / 3;
		C.push_back(pair<int, int>(id, c_score));
		M.push_back(pair<int, int>(id, m_score));
		E.push_back(pair<int, int>(id, e_score));
		A.push_back(pair<int, int>(id, a_score));
		// ��ʼ����������������д�� 
		result[id] = pair<int, char>(INT_MAX, 'N'); 
	}
	
	sort(A.begin(), A.end(), socreCmp);
	sort(C.begin(), C.end(), socreCmp);
	sort(M.begin(), M.end(), socreCmp);
	sort(E.begin(), E.end(), socreCmp);
	
	// �������Ƴɼ��������������������Ϳ�Ŀ���� 
	// ����A��C��M��E��˳����£��Ϳ��Ա�֤���ȼ� 
	int i = 0;
	int rank = 0;
	int last_score = -1;
	for (vector<pair<int, int> >::iterator itr = A.begin(); itr != A.end(); itr++, i++) {
		// ������ſ�Ŀ�ĳɼ����ߣ��͸��������Ϳ�Ŀ����
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
	
	// �����ѯ��� 
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

