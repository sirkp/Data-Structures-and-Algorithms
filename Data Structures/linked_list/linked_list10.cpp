// Reverse a linked list
//https://www.geeksforgeeks.org/write-a-function-to-reverse-the-nodes-of-a-linked-list/
#include <bits/stdc++.h>
using namespace std;

#define nl cout<<endl; 

class Node
{
public:
	int data;
	Node* next;
};

void print(Node* head,string s)
{
	cout<<s<<endl;
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	nl;
	nl;
}


void push(Node** head, int key)
{
	Node* new_node = new Node();
	new_node->data = key;
	new_node->next = NULL;

	if((*head)==NULL)
	(*head)=new_node;
	else
	{
		Node* node = (*head);
		while(node->next!=NULL)
		node=node->next;	
	
		node->next = new_node;
	}	
}

void reverse(Node** head)
{
	Node* prev_node = NULL;

	Node* node = (*head);
	while(node!=NULL)
	{
		Node* temp = node->next;
		node->next = prev_node;
		prev_node = node;
		node = temp;
	}
	(*head) = prev_node;
}

int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	Node* head = NULL;
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	push(&head,0);
	push(&head,-1);
	push(&head,-2);
	push(&head,-3);
	push(&head,-4);

	print(head,"head");

	reverse(&head);

	print(head,"head");
}