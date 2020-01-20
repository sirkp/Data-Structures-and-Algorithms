
#include <bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	Node* next;
	void push(Node** head,int data);
	void print(Node* head,string s);
};
void Node::push(Node** head,int data)
{
	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = NULL;
	if(*head==NULL)
	(*head) = new_node;
	else
	{
		Node* node = (*head);
		while(node->next!=NULL)
		node = node->next;
		node->next = new_node;	
	}	

}
void Node::print(Node* head,string s)
{
	cout<<s<<endl;
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}
void swap_linklist(Node** head, Node* nodeA,Node* nodeB)
{
	Node* node = (*head);
	while(node!=NULL)
	{
		if(node==nodeA||node==nodeB)
		break;
		node=node->next;	
	}
	Node* node1 = node;
	Node* node2;
	if(node==nodeA)
	node2 = nodeB;
	else
	node2 = nodeA;

	Node* prev_node1=NULL;
	Node* prev_node2=NULL;
	node = (*head);
	while(node!=NULL)
	{
		if(node->next==node1)
		break;	
		node=node->next;
	}	
	prev_node1 = node;

	node = (*head);
	while(node!=NULL)
	{
		if(node->next==node2)
		break;
		node=node->next;	
	}	
	prev_node2 = node;
	
	Node* temp =node2->next;
	if(node1!=(*head))
	prev_node1->next = node2;
	prev_node2->next = node1;
	node2->next = node1->next;
	node1->next = temp;

	if(node1==(*head))
	(*head) = node2;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	Node* head = NULL;
	head->push(&head,1);
	head->push(&head,2);
	head->push(&head,3);
	head->push(&head,4);
	head->push(&head,5);
	head->push(&head,6);
	head->push(&head,7);

	head->print(head,"");
	swap_linklist(&head,head,head->next->next->next);
	head->print(head,"");

}