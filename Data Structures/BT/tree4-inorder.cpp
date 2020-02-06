#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

void inorderTraversal(Node *root)
{
	stack<Node*> Stack;
	Node* current = root;
	while(current!=NULL || !Stack.empty())
	{
		while(current!=NULL)
		{
			Stack.push(current);
			current = current->left;
		}
		current = Stack.top()->right;
		cout<<Stack.top()->data<<" ";
		Stack.pop();
	}
	cout<<endl;
}

void inorderTraversalRecursion(Node* node)
{
	if(node==NULL)
	return;	
	inorderTraversalRecursion(node->left);
	cout<<node->data<<" ";
	inorderTraversalRecursion(node->right);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	Node* root = new Node(1);
	root->left = new Node(2);	
	root->right = new Node(3);	
	root->right->left = new Node(6);	
	root->right->right = new Node(7);	
	root->left->left = new Node(4);	
	root->left->right = new Node(5);
	inorderTraversal(root);
	inorderTraversalRecursion(root);
}