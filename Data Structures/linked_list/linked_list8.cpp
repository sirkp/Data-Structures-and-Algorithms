// Intersection of two Sorted Linked Lists
// https://www.geeksforgeeks.org/intersection-of-two-sorted-linked-lists/
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

void push(Node** head, int key)
{
	Node* new_node = new Node();
	new_node->data = key;
	new_node->next = NULL;

	if((*head)==NULL)
	(*head) = new_node;	
	else
	{
		Node* node = (*head);
		
		while(node->next!=NULL)
		node=node->next;
		
		node->next = new_node;	
	}
}

Node* intersection_sorted_increasing1(Node* head1,Node* head2)
{//dont preserve linked list1 and linked list2
	Node* head = NULL;
	Node* node = NULL;
	while(head1!=NULL && head2!=NULL)
	{
		if(head1->data == head2->data)
		{
			if(head==NULL)
			{
				head = head1;
				node = head;
			}
			else
			{
				node->next = head1;
				node = node->next;
			}	
		}
		if(head1->data < head2->data)
		head1 = head1->next;
		else
		head2 = head2->next;	
	}
	node->next=NULL;
	return head;
}

Node* intersection_sorted_increasing2(Node* head1,Node* head2)
{//preserve linked list1 and linked list2
	Node* head = NULL;
	Node* node = NULL;
	while(head1!=NULL && head2!=NULL)
	{
		if(head1->data == head2->data)
		push(&head, head1->data);	
		if(head1->data < head2->data)
		head1 = head1->next;
		else
		head2 = head2->next;	
	}
	return head;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif			

	Node* head1 = NULL;
	push(&head1,1);
	push(&head1,2);
	push(&head1,3);
	push(&head1,4);
	push(&head1,5);
	push(&head1,6);
	push(&head1,8);
	push(&head1,10);
	push(&head1,11);
	push(&head1,12);
	push(&head1,13);
	push(&head1,15);

	print(head1,"head1");

	Node* head2 = NULL;
	push(&head2,2);
	push(&head2,4);
	push(&head2,6);
	push(&head2,8);
	push(&head2,9);
	push(&head2,12);
	push(&head2,14);
	push(&head2,15);
	
	print(head2,"head2");

	Node* head = intersection_sorted_increasing2(head1,head2);

	print(head,"intersected linkedlist ");

	print(head1,"head1");

}