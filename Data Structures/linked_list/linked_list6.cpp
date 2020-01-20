//Swap nodes in a linked list without swapping data
//https://www.geeksforgeeks.org/swap-nodes-in-a-linked-list-without-swapping-data/
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;
};
void print(Node* n,string s);

void push(Node** head, int key)
{
	Node* new_node = new Node();
	new_node->data = key;
	new_node->next = NULL;

	if((*head)==NULL)
	{
		(*head) = new_node;
	}
	else
	{
		Node* c_node = (*head);
		while(c_node->next!=NULL)
		c_node = c_node->next;
		
		c_node->next = new_node;	
	}
}

void swap_node(Node** head, int keyA,int keyB)
{
	Node* nodeA=NULL;
	Node* nodeB=NULL;
	Node* prev_nodeA=NULL;
	Node* prev_nodeB=NULL;

	Node* node = (*head);
	while(node!=NULL)
	{
		if(node->data==keyA)
		{
			nodeA = node;
			break;
		}	

		prev_nodeA = node;
		node=node->next;	
	} 


	node = (*head);
	while(node!=NULL)
	{
		if(node->data==keyB)
		{
			nodeB = node;
			break;
		}	
		
		prev_nodeB = node;
		node = node->next;	
	}
	if(nodeA==NULL || nodeB==NULL)
	return;

	
	if(prev_nodeA==NULL)
	(*head) = nodeB;
	else
	prev_nodeA->next=nodeB;	

	if(prev_nodeB==NULL)
	(*head) = nodeA;	
	else
	prev_nodeB->next=nodeA;
	
	Node* temp = nodeB->next;
	nodeB->next = nodeA->next;
	nodeA->next = temp;	
}

void print(Node* head,string s)
{
	cout<<s<<endl;
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	Node* head = NULL;
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);

	print(head,"");

	swap_node(&head,2, 1);
	
	print(head,"");
}
