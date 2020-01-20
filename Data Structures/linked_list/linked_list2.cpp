// Write a function to delete a Linked List
// https://www.geeksforgeeks.org/write-a-function-to-delete-a-linked-list/
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

void print_node(string s,Node* node)
{
	cout<<s<<endl;
	while(node!=NULL)
	{
		cout<<node->data<<" ";
		node=node->next;
	}	
	cout<<endl;
}

void delete_linked_list(Node** head)
{
	Node* current_node = (*head);
	*head = NULL;
	while(current_node != NULL)
	{
		Node* tmp = current_node;
		current_node=current_node->next;
		delete tmp;
	}
}

void push(Node** head,int key)
{
	Node* new_node = new Node();
	new_node->data = key;
	new_node->next = NULL;

	if((*head)==NULL)
	{
		(*head) = new_node;
		(*head)->next = NULL;
	}
	else
	{
		Node* last_node = (*head);
		while(last_node->next!=NULL)
		last_node=last_node->next;
		
		last_node->next = new_node;
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	Node* head = NULL;
	push(&head,1);
	print_node("linked list formed ",head);
	push(&head,2);
	print_node("linked list formed ",head);
	push(&head,3);
	print_node("linked list formed ",head);
	push(&head,4);
	print_node("linked list formed ",head);

	delete_linked_list(&head);

	print_node("linked list after deletion ",head);

}
