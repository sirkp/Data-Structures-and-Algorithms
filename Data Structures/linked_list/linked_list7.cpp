// Pairwise swap elements of a given linked list
// https://www.geeksforgeeks.org/pairwise-swap-elements-of-a-given-linked-list/
#include <bits/stdc++.h>
using namespace std;

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
	cout<<endl;
}

void nl(){cout<<endl;}

void push(Node** head,int key)
{
	Node* new_node = new Node();
	new_node->data = key;
	new_node->next = NULL;

	if((*head==NULL))
	(*head) = new_node;
	else
	{
		Node* node = (*head);
		while(node->next!=NULL)
		node = node->next;
		
		node->next = new_node;	
	}	
}

void swap_two_nodes(Node** head, int keyA, int keyB)
{
	Node* nodeA = NULL;
	Node* nodeB=NULL;
	Node* prev_nodeA=NULL;
	Node* prev_nodeB=NULL;
	Node* node;

	node = (*head);
	while(node!=NULL)
	{
		if(node->data == keyA)
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
		if(node->data == keyB)
		{
			nodeB = node;
			break;
		}	
		prev_nodeB = node;
		node=node->next;
	}  
	
	if(nodeA==NULL||nodeB==NULL)
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

void pairwise_swap(Node** head)
{
	Node* node = (*head);
	while(node!=NULL && node->next!=NULL)
	{
		swap_two_nodes(head, node->data, (node->next)->data);
		node = node->next;
	}
}

void swap_first_last(Node** head)
{
	Node* last_node = (*head); 
	Node* prev_last_node = NULL;

	while(last_node->next!=NULL)
	{
		prev_last_node = last_node;		
		last_node=last_node->next;
	}
	

	last_node->next = (*head)->next;
	prev_last_node->next = (*head);
	(*head) = last_node;
	prev_last_node->next->next=NULL;

	
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
	push(&head,6);

	print(head,"linked list formed");
	nl();

	pairwise_swap(&head);

	print(head,"linked list after pairwise swapping\n");
	nl();

	swap_first_last(&head);

	print(head,"after swapping first and last\n");

}