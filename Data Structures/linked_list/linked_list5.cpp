//Remove duplicates from a sorted linked list and unsorted linked list
//https://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-linked-list/ , 
// https://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/
#include <bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	Node* next;
};

void push(Node** head,int key)
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
		node = node->next;
		
		node->next = new_node;	
	}	
}
void remove_duplicates_sorted(Node* head)
{
	while(head!=NULL)
	{
		while((head->next!=NULL) && (head->data==(head->next)->data))
		{
			Node* next_node = (head->next);
			head->next = next_node->next;
			delete next_node;
		}
		head = head->next;
	}
}

void remove_duplicates_unsorted_brutforce(Node* head)
{
	while(head!=NULL)
	{
		Node* node = head;
		while(node->next!=NULL)
		{
			if((node->next)->data == head->data)
			{
				Node* del_node = node->next;
				node->next = del_node->next;
				delete del_node;
			}
			else
			node = node->next;	
		}
		head=head->next;
	}
}

void remove_duplicates_unsorted(Node* head)
{
	unordered_map<int,int> hash;
	Node* prev_node = head;
	while(head!=NULL)
	{
		if(hash.find(head->data)==hash.end())
		{
			hash[head->data] = 1;
			prev_node = head;
			head = head->next;
		}
		else
		{
			Node* c_node = head;
			prev_node->next = c_node->next;
			head = c_node->next;

			delete c_node;
		}	
	}

}

void print(Node* node, string s)
{
	cout<<s<<endl;
	while(node != NULL)
	{
		cout<<node->data<<" ";
		node = node->next;
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

	push(&head,3);
	push(&head,3);
	push(&head,4);
	push(&head,1);
	push(&head,4);
	push(&head,1);
	push(&head,2);
	push(&head,1);
	push(&head,2);
	push(&head,10);
	push(&head,1);
	push(&head,2);
	push(&head,4);
	push(&head,3);
	push(&head,9);
	push(&head,7);
	push(&head,5);
	push(&head,5);
	push(&head,7);
	push(&head,6);
	push(&head,10);
	push(&head,8);
	push(&head,7);

	print(head,"");
	remove_duplicates_unsorted_brutforce(head);
	print(head,"");

}