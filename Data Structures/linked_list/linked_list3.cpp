// Detect loop in a linked list and find length of loop - Floyd cycle
//https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/ , https://www.geeksforgeeks.org/find-length-of-loop-in-linked-list/ 
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

void push_list(Node** head,int data)
{
	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = NULL;
	
	if((*head)==NULL)
	(*head)=new_node;
	else
	{
		Node* last = (*head);
		
		while(last->next!=NULL)
		last=last->next;
		
		last->next=new_node;	
	}
}

void print_list(string s,Node* head)
{
	cout<<s<<endl;
	int count = 0;
	while(head!=NULL)
	{
		if(count>30)
		break;	
		cout<<head->data<<" ";
		head=head->next;
		count++;
	}
	cout<<endl;
}

void floyd_cycle(Node* head)
{
	if(head!=NULL)
	{
		Node* slow_p = head;
		Node* fast_p = head;

		while(slow_p!=NULL && fast_p!=NULL && fast_p->next!=NULL)
		{
			slow_p=slow_p->next;
			fast_p=fast_p->next->next;
			if(slow_p==fast_p && slow_p!=NULL)
			{
				cout<<"loop hai\n";
				int count = 1;

				Node* temp = slow_p;

				slow_p=slow_p->next;
				while(slow_p!=fast_p)
				{
					count++;
					slow_p=slow_p->next;
				}
				cout<<"length of loop- "<<count<<endl;

				slow_p = head;
				fast_p = temp;

				while(slow_p!=fast_p)
				{
					slow_p=slow_p->next;
					fast_p=fast_p->next;
				}

				cout<<"Loop starts at "<<slow_p<<" "<<slow_p->data<<endl;

				return;
			}	
		}


		cout<<"loop nahi hai\n";
	}
	else
	{
		cout<<"koi hai hi nahi\n";
	}
}

int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	Node* head = NULL;
	push_list(&head,1);
	push_list(&head,2);
	push_list(&head,3);
	push_list(&head,4);
	push_list(&head,5);

	print_list("linked list formed",head);

	Node* two = head->next;

	Node* last = head->next->next->next->next;
	last->next = two;
	
	floyd_cycle(head);
}