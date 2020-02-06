//Level order traversing https://www.geeksforgeeks.org/level-order-tree-traversal/
//BFS with each level printed at a line
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

int height(Node* node)
{
	if(node==NULL)
	return 0;
	
	int lheight = height(node->left);
	int rheight = height(node->right);
	return (max(lheight,rheight)+1);	
}

void printGivenLevel(Node* root, int level)
{
	if(root==NULL)
	return;
	if(level==0)
	cout<<root->data<<" ";
	else
	{
		printGivenLevel(root->left,level-1);
		printGivenLevel(root->right,level-1);
	}	

}

void bfs(Node* root)
{
	list<Node*> queue;
	queue.push_back(root);
	queue.push_back(NULL);

	while(!queue.empty())
	{
		Node* s = queue.front();
		queue.pop_front();
		if(s!=NULL)
		{
			cout<<s->data<<" ";
			if(s->left!=NULL)
			queue.push_back(s->left);
			if(s->right!=NULL)
			queue.push_back(s->right);

		}
		else
		{
			cout<<endl;	
			if(!queue.empty())
			queue.push_back(NULL);
		}

	}
	cout<<endl;
}

void dfs(Node *node)
{
	cout<<node->data<<endl;
	if(node->left!=NULL)
	dfs(node->left);
	if(node->right!=NULL)
	dfs(node->right);
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
	root->left->left = new Node(4);	
	root->left->right = new Node(5);
	root->right->left = new Node(6);	
	root->left->left->left = new Node(7);	
	bfs(root);	
	cout<<height(root)<<endl;
	cout<<height(root->left)<<endl;
	cout<<height(root->right)<<endl;
	
	printGivenLevel(root,3);
	cout<<endl;
	printGivenLevel(root,2);
	cout<<endl;

	dfs(root);
}