#include <iostream>
#include <queue>
using namespace std;

// 树数据结构
// children是一个指针数组，指向每一个子节点
// ch_num表示子节点个数 
struct Tree {
	Tree **children;
	int id;
	int ch_num;
};


int main() {
	int N, M;
	cin >> N >> M;
	
	// nodes是所有的Tree指针数组 
	Tree** nodes = new Tree*[N];
	for (int i = 0; i < N; i++) {
		nodes[i] = new Tree;
		nodes[i]->id = i + 1;
		nodes[i]->ch_num = 0;
	}
	
	// 添加节点之间的从属关系 
	for (int i = 0; i < M; i++) {
		int id, num;
		cin >> id >> num;
		Tree* node = nodes[id - 1];
		node->ch_num = num;

		// 创建children数组 
		node->children = new Tree*[num];
		
		// 给每个children指针赋值 
		for (int i = 0; i < num; i++) {
			int ch_id;
			cin >> ch_id;
			node->children[i] = nodes[ch_id - 1];
		}
	}
	 
	vector<int> current_lv;
	current_lv.push_back(0);
	bool first = true;
	// 层次遍历整个树 
	while (!current_lv.empty()) {
		if (!first) {
			cout << " ";
		}
		first = false;
		
		// 遍历当前层次，并统计数量
		// 同时把下一层节点添加到 next_lv中，为下一轮遍历做准备 
		vector<int> next_lv;
		int count = 0;
		while (!current_lv.empty()) {
			int id = current_lv.back();
			current_lv.pop_back();
			if (nodes[id]->ch_num == 0) {
				count += 1;
			}
			for (int i = 0; i < nodes[id]->ch_num; i++) {
				next_lv.push_back( (nodes[id]->children[i])->id - 1 );
			}
		}
		current_lv = next_lv;
		
		cout << count;
	}
	
	// 释放内存空间 
	for (int i = 0; i < N; i++) {
		delete nodes[i];
	}
	delete nodes;
	
	return 0;
}
