#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <set>
#include <climits>

using namespace std;

const int INF = 100000000;

int main() {
	int N, M, C1, C2;
	cin >> N >> M >> C1 >> C2;
	
	// �����Ԯ������ 
	vector<int> rescue(N);
	for (int i = 0; i < N; i++) {
		cin >> rescue[i];
	}
	
	// ����� 
	vector<vector<int> > adj_matrix;
	for (int i = 0; i < N; i++) {
		adj_matrix.push_back(vector<int>(N, INF));
		adj_matrix[i][i] = 0;
	}
	// �ڽӱ�
	vector<list<int> > adj_table(N);
	
	// �����·֮��ľ���
	for (int i = 0; i < M; i++) {
		int source, target, dis = 0;
		cin >> source >> target >> dis;
		adj_matrix[source][target] = dis;
		adj_matrix[target][source] = dis;
		
		adj_table[source].push_front(target);
		adj_table[target].push_front(source);
	} 
	
	// ���������ʾ���б�ţ�ֵ��һ��pair����һ��ֵΪ���·�����������ڶ���ֵΪ����Ԯ������ 
	vector<pair<int, int> > result(N);
	
	// �Ͻ�˹�����㷨 
	// ��̾������� 
	vector<int> distance(N);
	for (int i = 0; i < N; i++) {
		distance[i] = adj_matrix[C1][i];
	}
	
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cout << adj_matrix[i][j] << " ";
//		}
//		cout << endl;
//	} 
//	cout << endl;
	
	// ���ڼ�¼���·�������� 
	vector<int> path_num(N, 0);
	// ���ľ�Ԯ������ 
	vector<int> max_rescue(N, rescue[C1]);
	
	// �ҵ�/δ�ҵ����·���Ľ��id���ϣ�ʵ������һ�����飬1��ʾ���ҵ���0��ʾδ�ҵ� 
	vector<int> found(N, 0);
	found[C1] = 1;
	
	while (true) {
		int min_dis = INT_MAX, min_node = -1;
		for (int i = 0; i < N; i++) {
			if (found[i] == 0 && distance[i] < min_dis) {
				min_dis = distance[i];
				min_node = i;
			}
		}
		
		// Ѱ������Ԯ��
		// ������С�ڵ����ڵ����н�� 
		int min_num = 0;
		int max_r = 0;
		for (list<int>::iterator itr = adj_table[min_node].begin(); itr != adj_table[min_node].end(); itr++) {
			if (found[*itr] == 1 && min_dis == distance[*itr] + adj_matrix[*itr][min_node]) {
				min_num++;
				if (max_rescue[*itr] > max_r) {
					max_r = max_rescue[*itr];
				}
			}
		}
		max_rescue[min_node] = max_r + rescue[min_node];
		// cout << "max rescue " << min_node << ":" << max_rescue[min_node];
		
		// �ҵ����µ����·���� 
//		cout << "distance table: ";
//		for (int i = 0; i < N; i++) {
//			cout << distance[i] << " ";
//		}
//		cout << endl;
//		cout << "found new node :" << min_node << endl;
//		
//		cout << "max rescue: ";
//		for (int i = 0; i < N; i++) {
//			cout << max_rescue[i] << " ";
//		}
//		cout << endl;
		
		path_num[min_node] = min_num;
		
		if (min_node == C2) {
			break;
		}
		found[min_node] = 1;
		if (min_node != -1) {
			for (int i = 0; i < N; i++) {
				if (found[i] == 0 && distance[min_node] + adj_matrix[min_node][i] < distance[i]) {
					distance[i] = distance[min_node] + adj_matrix[min_node][i];
				}
			}
		}
	}
	
	cout << path_num[C2] << " " << max_rescue[C2] << endl;
}
