//append insert insert_front insert_after delete_node delete_node_position linear_search
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

Node* linear_search(Node* head, int key)
{
	while(head!=NULL)
	{
		if(head->data == key)
		return head;	
		
		head=head->next;
	}
	return NULL;
} 

void insert_after_node(Node* after_node, int new_data)
{
	if(after_node==NULL)
	{
	cout<<"Previous node cannot be null\n";	
	return;
	}

	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = after_node->next;
	after_node->next = new_node;
}

void append_or_create_linked_list(Node** head,int new_data)//head may change if linked list is empty so **
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = NULL;
	
	if((*head) == NULL)
	{
		(*head) = new_node;
		return;	
	}	

	Node* last = (*head);//otherwise last node will become head 
	while(last->next!=NULL)
	last=last->next;
	
	last->next = new_node;	
}

void insert_front(Node** head, int new_data)//head is changing so **
{
	Node* new_node = new Node();

	new_node->data = new_data;
	new_node->next = *head;

	*head = new_node;
}

void delete_node(Node** head, int key)
{
	Node* del_node = linear_search((*head),key);
	if(del_node==NULL)
	cout<<"node hai hi nahi\n";
	else
	{
		if(del_node == (*head))
		{
			(*head) = (*head)->next;
			delete del_node;
		}
		else
		{
			Node* prev_node = (*head);
			
			while(prev_node->next!=del_node)
			prev_node=prev_node->next;
			
			prev_node->next = del_node->next;

			delete del_node;
		}
	}	
}

void delete_node_position(Node** head,int pos)//pos starts from 0
{
	int p=pos-1;
	int count = -1;
	if((*head)!=NULL)
	{
		if(p==-1)
		{
			Node* tmp = (*head);
			(*head)=(*head)->next;
			delete tmp;
			return;
		}	

		Node* prev_node = (*head);
		count++; 
		while(prev_node!=NULL)
		{
			if(count==p)
			{
				Node* tmp = prev_node->next;
				prev_node->next = tmp->next;
				delete tmp;
				return;
			}
			count++;
			prev_node=prev_node->next;	
		}
	}	
	cout<<"aukat k bahar\n";
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	Node* head=NULL;
	Node* second=NULL;
	Node* third=NULL;

	head=new Node();
	second=new Node();
	third=new Node();

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	print_node("linked list formed ",head);

	insert_front(&head, 5);//O(1)

	print_node("linked_list after insertion at front",head);

	insert_after_node(second,10);//O(1)

	print_node("linked_list after insertion",head);

	append_or_create_linked_list(&head,20);//O(n)
	append_or_create_linked_list(&head,30);//O(n)
	append_or_create_linked_list(&head,40);//O(n)

	print_node("linked_list after append",head);

	Node* tmp = linear_search(head,15);
	if(tmp != NULL)
	cout<<"Item found-"<<tmp->data<<endl;
	else
	cout<<"Item not found\n";
	
	//Delete node by key
	delete_node(&head,5);
	print_node("linked_list after deletion",head);
	delete_node(&head,10);
	print_node("linked_list after deletion",head);
	delete_node(&head,11);
	delete_node(&head,20);
	print_node("linked_list after deletion",head);
	delete_node(&head,30);
	print_node("linked_list after deletion",head);
	delete_node(&head,40);
	print_node("linked_list after deletion",head);
	delete_node(&head,2);
	print_node("linked_list after deletion",head);
	delete_node(&head,1);
	print_node("linked_list after deletion",head);
	delete_node(&head,3);
	print_node("linked_list after deletion",head);

	//Delete node by position
	delete_node_position(&head,10);
	print_node("linked_list after deletion",head);
	delete_node_position(&head,3);
	print_node("linked_list after deletion",head);
	delete_node_position(&head,2);
	print_node("linked_list after deletion",head);
	delete_node_position(&head,1);
	print_node("linked_list after deletion",head);
	delete_node_position(&head,0);
	print_node("linked_list after deletion",head);
	delete_node_position(&head,0);
	print_node("linked_list after deletion",head);
	delete_node_position(&head,1);
	print_node("linked_list after deletion",head);
	delete_node_position(&head,0);
	print_node("linked_list after deletion",head);
}