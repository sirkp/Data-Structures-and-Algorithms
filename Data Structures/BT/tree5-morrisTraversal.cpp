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

void morristraversal(Node* root)
{
	Node* current = root;
	Node* pre = NULL; 
	while(current!=NULL)
	{
		if(current->left!=NULL)
		{
			pre = current->left;
			while(pre->right!=NULL && pre->right!=current)
			pre = pre->right;
			
			if(pre->right==NULL)
			{
				pre->right = current;
				current = current->left;
			}
			else
			{
				pre->right = NULL;
				cout<<current->data<<" ";
				current = current->right;
			}	
		}
		else
		{
			cout<<current->data<<" ";
			current = current->right;
		}
	}
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
	
	morristraversal(root);	
}