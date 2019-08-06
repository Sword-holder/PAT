#include <iostream>
#include <queue>

using namespace std;

struct Tree {
	int value;
	Tree* left;
	Tree* right;
	
	Tree(int value):value(value) {}
};

Tree* construct_tree(int *postorder, int post_begin, int post_end, int *inorder, int in_begin, int in_end) {
	if (post_begin == post_end) {
		return NULL;
	}
	
	// ����������ȡ���һ��Ϊ���ڵ� 
	int value = postorder[post_end - 1];
	Tree* root = new Tree(value);
	
	// �����������Ѱ�Ҹ��ڵ�λ�� 
	int pos = in_begin;
	while (pos < in_end) {
		if (inorder[pos] == value) {
			break;
		}
		pos++;
	}
	
	// �ݹ鹹���������� 
	root->left = construct_tree(postorder, post_begin, post_begin + pos - in_begin, inorder, in_begin, pos);
	root->right = construct_tree(postorder, post_begin + pos - in_begin, post_end - 1, inorder, pos + 1, in_end);
	return root;
}

// ���ղ�α�����˳����� 
void level_traversal(Tree* tree) {
	queue<Tree*> children;
	
	if (tree) {
		cout << tree->value;
		children.push(tree);
	}
	
	while (!children.empty()) {
		queue<Tree*> temp;
		while (!children.empty()) {
			Tree* child = children.front();
			if (child != tree) {
				cout << " " << child->value;
			}
			children.pop();
			if (child->left) {
				temp.push(child->left);
			}
			if (child->right) {
				temp.push(child->right);
			}
		}
		children = temp;
	}
}

int main() {
	// �������� 
	int N;
	cin >> N;
	int postorder[N];
	int inorder[N];
	for (int i = 0; i < N; i++) {
		cin >> postorder[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> inorder[i];
	}
	
	// �ݹ�ع������ṹ 
	Tree* tree = construct_tree(postorder, 0, N, inorder, 0, N);
	
	// ��α���������
	level_traversal(tree);
}
