// Write a function to get the intersection point of two Linked Lists
//https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/
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

Node* find_intersection(Node* head1,Node* head2)
{
	Node* node1 = head1;
	int l1=0;
	while(node1!=NULL)
	{
		l1++;
		node1 = node1->next;	
	}


	Node* node2 = head2;
	int l2=0;
	while(node2!=NULL)
	{
		l2++;
		node2 = node2->next;	
	}

	int diff;
	Node* big_node;
	Node* small_node;
	if(l1>l2)
	{
		diff=l1-l2;
		big_node = head1;
		small_node = head2;
	}
	else
	{
		diff = l2-l1;
		big_node = head2;
		small_node = head1;
	}

	while(diff--)
	big_node = big_node->next;

	while(big_node != small_node && big_node!=NULL)
	{
		big_node = big_node->next;
		small_node = small_node->next;
	}	

	return big_node;
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

	print(head1,"head1");

	Node* head2 = NULL;
	push(&head2,6);
	push(&head2,7);
	push(&head2,8);

	head2->next->next->next = head1->next->next->next;

	print(head2,"head2");

	Node* intersect_node = find_intersection(head1,head2);

	cout<<"intersection at\n"<<intersect_node<<" ";
	if(intersect_node!=NULL)cout<<intersect_node->data;
	nl;
}