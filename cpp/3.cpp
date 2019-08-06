#include <iostream>
#include <climits>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
#define INF 10000000
using namespace std;

int main() {
	int N, M, C1, C2;
	cin >> N >> M >> C1 >> C2;
	int team_num[N];
	// ��ʼ��ÿ�����еľ�Ԯ������ 
	for (int i = 0; i < N; i++) {
		cin >> team_num[i];
	}
	// ��ʼ���ڽӱ�ṹ
	// �����pair�У���һ��Ԫ�ر�ʾ�ڽӵĽڵ�ţ��ڶ���Ԫ�ر�ʾ���� 
	// ������캯���У�adj_table()���������ʾ�����ʼ������ 
	int adj_matrix[N][N] = {INF};
	fill(adj_matrix, adj_matrix + N * N, INF);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << adj_matrix[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < N; i++) {
		adj_matrix[i][i] = 0;
	}
	
	for (int i = 0; i < M; i++) {
		int c1, c2, dis;
		cin >> c1 >> c2 >> dis;
		adj_matrix[c1][c2] = dis;
		adj_matrix[c2][c1] = dis;
	}
	 
	// pair�д洢������ĿҪ����������·������������Ԯ������ 
	// results�Ǵ洢C1��ÿ�����һ��pairֵ 
	vector<pair<int, int> > results(N);
	// C1�Լ����Լ������·������Ϊ1����Ԯ����������C1�о�Ԯ�ӵ����� 
	results[C1] = pair<int, int>(1, team_num[C1]);
	// C1������������·�� 
	vector<int> distance(N, INF);
	distance[C1] = 0; 
	
	// �����ڵϽ�˹�����㷨���������Ƕ�̬�滮
	// Qָ����δ�ҵ����·���ĵ�ļ��ϣ�һ��ʼQ�������е� 
	set<int> Q;
	for (int i = 0; i < N; i++) {
		Q.insert(i);
	}
	
	// new_node��ʾ��һ���ҵ����·���Ľڵ� 
	while (!Q.empty()) {
		// ��Q���ϱ���һ�Σ��ҵ���Сֵ 
		int min_dis = INT_MAX, min_node = -1; 
		for (set<int>::iterator itr = Q.begin(); itr != Q.end(); itr++) {
			if (distance[*itr] < min_dis) {
				min_dis = distance[*itr];
				min_node = *itr;
			} 
		}
		for (int i = 0; i < distance.size(); i++) {
			cout << distance[i] << " ";
		}
		cout << endl << min_node << endl;
		// �ɳ�ÿ���ڵ� 
		for (int i = 0; i < N; i++) {
			if (distance[min_node] + adj_matrix[min_node][i] < distance[i]) {
				cout << "distance[i] = " << distance[i];
				cout << "adj_matrix[min_node][i] = " << adj_matrix[min_node][i];
				cout << endl;
				distance[i] = distance[min_node] + adj_matrix[min_node][i];
			}
		}
		
		// ����̵��Ǹ��ڵ��Ƴ� 
		Q.erase(min_node);
	}
	
	for (int i = 0; i < N; i++) {
		cout << i << ":" << distance[i] << endl;
	}
	//cout << results[C2] << std::endl;
	return 0;
} 
