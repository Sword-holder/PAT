#include <iostream>
#include <queue>
using namespace std;

// �����ݽṹ
// children��һ��ָ�����飬ָ��ÿһ���ӽڵ�
// ch_num��ʾ�ӽڵ���� 
struct Tree {
	Tree **children;
	int id;
	int ch_num;
};


int main() {
	int N, M;
	cin >> N >> M;
	
	// nodes�����е�Treeָ������ 
	Tree** nodes = new Tree*[N];
	for (int i = 0; i < N; i++) {
		nodes[i] = new Tree;
		nodes[i]->id = i + 1;
		nodes[i]->ch_num = 0;
	}
	
	// ��ӽڵ�֮��Ĵ�����ϵ 
	for (int i = 0; i < M; i++) {
		int id, num;
		cin >> id >> num;
		Tree* node = nodes[id - 1];
		node->ch_num = num;

		// ����children���� 
		node->children = new Tree*[num];
		
		// ��ÿ��childrenָ�븳ֵ 
		for (int i = 0; i < num; i++) {
			int ch_id;
			cin >> ch_id;
			node->children[i] = nodes[ch_id - 1];
		}
	}
	 
	vector<int> current_lv;
	current_lv.push_back(0);
	bool first = true;
	// ��α��������� 
	while (!current_lv.empty()) {
		if (!first) {
			cout << " ";
		}
		first = false;
		
		// ������ǰ��Σ���ͳ������
		// ͬʱ����һ��ڵ���ӵ� next_lv�У�Ϊ��һ�ֱ�����׼�� 
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
	
	// �ͷ��ڴ�ռ� 
	for (int i = 0; i < N; i++) {
		delete nodes[i];
	}
	delete nodes;
	
	return 0;
}
