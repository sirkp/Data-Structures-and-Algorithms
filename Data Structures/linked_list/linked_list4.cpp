// Function to check if a singly linked list is palindrome
//https://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	char data;
	Node* next;
};

void push(Node** node, char key)
{
	Node* new_node = new Node();
	new_node->data = key;
	new_node->next = NULL;

	if((*node)==NULL)
	(*node) = new_node;
	else
	{
		Node* c_node = (*node);
		while(c_node->next!= NULL)
		c_node = c_node->next;
		
		c_node->next = new_node; 	
	}
}

bool palindrome_stack(Node* head)
{
	if(head == NULL)
	{
		cout<<"no element\n";
		return false;
	}
	else
	{
		stack<char> s;
		Node* node = head;
		while(node!=NULL)
		{
			s.push(node->data);
			node = node->next;
		}

		node = head;

		while(node!=NULL)
		{
			if(s.top() == node->data)
			{
				s.pop();
				node = node->next;	
			}
			else
			return false;	
		}
		return true;

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
	push(&head,'a');
	push(&head,'b');
	push(&head,'a');
	push(&head,'c');
	push(&head,'a');
	push(&head,'b');
	push(&head,'a');
	push(&head,'a');
	print(head,"");

	if(palindrome_stack(head))
	cout<<"Yes\n";
	else
	cout<<"No\n";	


}