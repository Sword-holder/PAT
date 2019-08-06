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
	
	// 后续遍历中取最后一个为根节点 
	int value = postorder[post_end - 1];
	Tree* root = new Tree(value);
	
	// 从中序遍历中寻找根节点位置 
	int pos = in_begin;
	while (pos < in_end) {
		if (inorder[pos] == value) {
			break;
		}
		pos++;
	}
	
	// 递归构建左右子树 
	root->left = construct_tree(postorder, post_begin, post_begin + pos - in_begin, inorder, in_begin, pos);
	root->right = construct_tree(postorder, post_begin + pos - in_begin, post_end - 1, inorder, pos + 1, in_end);
	return root;
}

// 按照层次遍历的顺序输出 
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
	// 输入数据 
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
	
	// 递归地构建树结构 
	Tree* tree = construct_tree(postorder, 0, N, inorder, 0, N);
	
	// 层次遍历输出结果
	level_traversal(tree);
}
