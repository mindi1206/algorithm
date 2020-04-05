#include <iostream>
#include <stdio.h>
using namespace std;
typedef struct node {
	struct node* left;
	struct node* right;
	int num;

	node(int num) {
		left = nullptr;
		right = nullptr;
		this->num = num;
	}
	void insert(node* ref, int data) {
		// left
		if (data < ref->num) {
			if (ref->left == nullptr) {
				ref->left = new node(data);
			}
			else {
				insert(ref->left, data);
			}
		}
		// right
		else {
			if (ref->right == nullptr) {
				ref->right = new node(data);
			}
			else {
				insert(ref->right, data);
			}
		}
	}
	// left right root
	void postorder(node* ref) {
		if (ref == NULL) return;
		postorder(ref->left);
		postorder(ref->right);
		printf("%d\n", ref->num);
	}

}node;

int main() {
	int num;
	node* root = NULL;
	int a = 9;
	while (~scanf("%d", &num)) {
		if (root == NULL) {
			root = new node(num);
		}
		else {
			root->insert(root, num);
		}
	}
	root->postorder(root);
}
