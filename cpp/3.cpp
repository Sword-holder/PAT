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
	// 初始化每个城市的救援队数量 
	for (int i = 0; i < N; i++) {
		cin >> team_num[i];
	}
	// 初始化邻接表结构
	// 里面的pair中，第一个元素表示邻接的节点号，第二个元素表示距离 
	// 这个构造函数中，adj_table()括号里面表示数组初始化长度 
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
	 
	// pair中存储的是题目要求输出的最短路径个数和最多救援队数量 
	// results是存储C1到每个点的一对pair值 
	vector<pair<int, int> > results(N);
	// C1自己到自己的最短路径数量为1，救援队数量就是C1中救援队的数量 
	results[C1] = pair<int, int>(1, team_num[C1]);
	// C1到其它点的最短路径 
	vector<int> distance(N, INF);
	distance[C1] = 0; 
	
	// 类似于迪杰斯特拉算法，本质上是动态规划
	// Q指的是未找到最短路径的点的集合，一开始Q就是所有点 
	set<int> Q;
	for (int i = 0; i < N; i++) {
		Q.insert(i);
	}
	
	// new_node表示上一次找到最短路径的节点 
	while (!Q.empty()) {
		// 把Q集合遍历一次，找到最小值 
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
		// 松弛每个节点 
		for (int i = 0; i < N; i++) {
			if (distance[min_node] + adj_matrix[min_node][i] < distance[i]) {
				cout << "distance[i] = " << distance[i];
				cout << "adj_matrix[min_node][i] = " << adj_matrix[min_node][i];
				cout << endl;
				distance[i] = distance[min_node] + adj_matrix[min_node][i];
			}
		}
		
		// 把最短的那个节点移除 
		Q.erase(min_node);
	}
	
	for (int i = 0; i < N; i++) {
		cout << i << ":" << distance[i] << endl;
	}
	//cout << results[C2] << std::endl;
	return 0;
} 
