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
	
	// 输入救援队数量 
	vector<int> rescue(N);
	for (int i = 0; i < N; i++) {
		cin >> rescue[i];
	}
	
	// 距离表 
	vector<vector<int> > adj_matrix;
	for (int i = 0; i < N; i++) {
		adj_matrix.push_back(vector<int>(N, INF));
		adj_matrix[i][i] = 0;
	}
	// 邻接表
	vector<list<int> > adj_table(N);
	
	// 输入道路之间的距离
	for (int i = 0; i < M; i++) {
		int source, target, dis = 0;
		cin >> source >> target >> dis;
		adj_matrix[source][target] = dis;
		adj_matrix[target][source] = dis;
		
		adj_table[source].push_front(target);
		adj_table[target].push_front(source);
	} 
	
	// 结果表，键表示城市编号，值是一个pair，第一个值为最短路径的数量，第二个值为最大的援救数量 
	vector<pair<int, int> > result(N);
	
	// 迪杰斯特拉算法 
	// 最短距离数组 
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
	
	// 用于记录最短路径的数量 
	vector<int> path_num(N, 0);
	// 最大的救援队数量 
	vector<int> max_rescue(N, rescue[C1]);
	
	// 找到/未找到最短路径的结点id集合，实际上是一个数组，1表示已找到，0表示未找到 
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
		
		// 寻找最大救援队
		// 遍历最小节点相邻的所有结点 
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
		
		// 找到了新的最短路径点 
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
