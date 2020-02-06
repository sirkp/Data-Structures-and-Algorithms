#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	char data;
	Node* left;
	Node* right;
	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};
unordered_map<char,int> umap;
Node* buildFromInorderPreorder(string preorder, string inorder, int start, int end)
{
	if(start>end)
	return NULL;	

	static int preorderIndex = 0;
	Node* node = new Node(preorder[preorderIndex++]);
	int inorderIndex = umap[node->data];
	
	if(!(inorderIndex>=start && inorderIndex<=end))
	return NULL;	

	node->left = buildFromInorderPreorder(preorder,inorder,start,inorderIndex-1);
	node->right = buildFromInorderPreorder(preorder,inorder,inorderIndex+1,end);
	return node;
}

Node* buildFromInorderPostorder(string postorder, string inorder, int start, int end)
{
	if(start>end)
	return NULL;	

	static int postorderIndex = (int)postorder.length()-1;
	Node* node = new Node(postorder[postorderIndex--]);
	int inorderIndex = umap[node->data];
	
	if(!(inorderIndex>=start && inorderIndex<=end))
	return NULL;	
	node->right = buildFromInorderPostorder(postorder,inorder,inorderIndex+1,end);
	node->left = buildFromInorderPostorder(postorder,inorder,start,inorderIndex-1);
	return node;
}

void getLevelOrder(string inorder, string levelOrder, int start, int inorderIndex, string& leftLevelOrder, string& rightLevelOrder)
{
	unordered_set<char> hash;
	for(int i=start;i<=(inorderIndex-1);i++)
	hash.insert(inorder[i]);
	
	for(int i=1;i<(int)levelOrder.length();i++)
	{
		if(hash.find(levelOrder[i])!=hash.end())
		leftLevelOrder += levelOrder[i];
		else
		rightLevelOrder += levelOrder[i];
	}
}

Node* buildFromInorderLevelOrder(string inorder, string levelOrder, int start, int end)
{
	if(start>end)
	return NULL;
	
	Node* node = new Node(levelOrder[0]);

	int inorderIndex = umap[node->data];
	if(!(inorderIndex>=start && inorderIndex<=end))
	return NULL;
	
	string rightLevelOrder = "";	
	string leftLevelOrder = "";
	getLevelOrder(inorder, levelOrder, start, inorderIndex, leftLevelOrder, rightLevelOrder);	


	node->left = buildFromInorderLevelOrder(inorder,leftLevelOrder,start,inorderIndex-1);
	node->right = buildFromInorderLevelOrder(inorder,rightLevelOrder,inorderIndex+1,end);

	return node;		
}

void inorderTraversal(Node* node)
{
	if(node==NULL)
		return;

	inorderTraversal(node->left);
	cout<<node->data;
	inorderTraversal(node->right);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	string inorder = "EACKFHDBG";
	string preorder = "FAEKCDHGB";
	string postorder = "ECKAHBGDF";
	string levelOrder = "FADEKHGCB";
	for(int i=0;i<inorder.length();i++)
	umap[inorder[i]] = i;
	
	Node* root = buildFromInorderPreorder(preorder, inorder, 0, ((int)preorder.length()-1));
	inorderTraversal(root);
	cout<<endl;	
	
	root = buildFromInorderPostorder(postorder,inorder,0, ((int)postorder.length()-1));
	inorderTraversal(root);
	cout<<endl;

	root = buildFromInorderLevelOrder(inorder,levelOrder,0,((int)levelOrder.length()-1));
	inorderTraversal(root);
	cout<<endl;
}