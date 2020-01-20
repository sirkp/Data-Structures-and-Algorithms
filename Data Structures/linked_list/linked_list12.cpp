/*Given a Linked List of integers, write a function to modify the linked list such that all even 
numbers appear before all the odd numbers in the modified linked list. Also, keep the order of 
even and odd numbers same.
https://www.geeksforgeeks.org/segregate-even-and-odd-elements-in-a-linked-list/
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

void print(Node *node, string s)
{
	cout<<s<<endl;
	int i = 0;
	while(node!=NULL)
	{
		if(i>10)
		break;	
		cout<<node->data<<" ";
		node = node->next;
		i++;
	}
	cout<<endl;
}

void push(Node **head, int key)
{

	Node* new_node = new Node();
	new_node->data = key;
	new_node->next = NULL;

	if((*head) == NULL)
	(*head) = new_node;
	else
	{
		Node* node = (*head);
		
		while(node->next!=NULL)
		node = node->next;
		
		node->next = new_node;	
	}

}

Node* get_last_node(Node* head)
{
	while(head->next!=NULL)
	head = head->next;
	
	return head;	
}

void break_node(Node* prev, Node** head)
{
	Node* node = (*head);
	if(prev==NULL)
	(*head) = (*head)->next;
	else if(prev->next->next==NULL)
	prev->next = NULL;
	else
	prev->next = prev->next->next;
}

void append_last(Node** pos, Node* node)
{
	node->next = NULL;
	(*pos)->next = node;
	(*pos) = node;
}


void odd_even(Node** head)
{
	Node* last = get_last_node((*head));
	Node* lastNode = last;//for terminating loop
	Node* node = (*head);
	Node* next;
	Node* prev = NULL;

	while(node!=lastNode)
	{
		next = node->next;
		if(node->data%2 == 1)
		{
			break_node(prev,head);
			append_last(&last,node);
		}
		if(node->data%2==0)
		prev = node;
		node = next;
	}
	if(node->data%2 == 1 && last!=lastNode)//second condition checks if the same elment need to be shifted Eg- 8 9
	{
		break_node(prev,head);
		append_last(&last,node);
		print((*head),"linked list formed");
	}

}



int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	

	Node* head = NULL;
	push(&head,17);	
	push(&head,15);	
	push(&head,8);	
	push(&head,12);	
	push(&head,10);	
	push(&head,5);
	push(&head,4);
	push(&head,7);
	push(&head,6);
	print(head,"linked list formed");

	odd_even(&head);

	print(head,"linked list formed");
	

}