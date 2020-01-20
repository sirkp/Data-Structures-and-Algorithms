// QuickSort on Singly Linked List
//https://www.geeksforgeeks.org/quicksort-on-singly-linked-list/
#include <bits/stdc++.h>
using namespace std;
int counta = 0;
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

void swap_node(Node** head, Node* nodeA, Node* nodeB)
{
	if(nodeA == NULL || nodeB == NULL || nodeA == nodeB)
	return;

	Node* prevNodeA = NULL;
	Node* prevNodeB = NULL;

	Node* node = (*head);
	while(node!=nodeA)
	{
		prevNodeA = node;
		node = node->next;
	}

	node = (*head);
	while(node!=nodeB)
	{
		prevNodeB = node;
		node = node->next;
	}

	if(prevNodeA==NULL)
	(*head) = nodeB;
	else
	prevNodeA->next = nodeB;

	if(prevNodeB==NULL)
	(*head) = nodeA;
	else
	prevNodeB->next = nodeA;

	Node* temp = nodeB->next;
	nodeB->next = nodeA->next;
	nodeA->next = temp;
}

int get_size(Node* head)
{
	int size=0;
	while(head!=NULL)
	{
		head = head->next;
		size++;
	}

	return size;
}

Node* get_Node(Node* head, int pos)
{
	if(pos<get_size(head))
	{
		int i=0;
		while(i!=pos)
		{
			head = head->next;
			i++;
		}
		return head;
	}
	else
	return NULL;
}

void push(Node** head, int key)
{
	Node* new_node = new Node();
	new_node->data = key;
	new_node->next = NULL;

	if((*head)== NULL)
	(*head) = new_node;
	else
	{
		Node* node = (*head);
		while(node->next!=NULL)
		node = node->next;

		node->next = new_node;
	}
}

int partition(Node** head, int low, int high)
{
	int pivot = high-1;
	int ii = low-1;
	for(int i=low;i<(high-1);i++)
	{
		if(((get_Node((*head),i))->data)<((get_Node((*head),pivot))->data))
		{
			ii++;
			swap_node(head,get_Node((*head),i),get_Node((*head),ii));
		}
	}
	ii++;
	swap_node(head,get_Node((*head),ii),get_Node((*head),pivot));

	return ii;
}

void quicksort(Node** head, int low, int high)
{
	if(low<high)
	{
		int p = partition(head,low,high);
		quicksort(head,low,p);
		quicksort(head,p+1,high);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	Node* head = NULL;
	push(&head,4);
	push(&head,1);
	push(&head,2);
	push(&head,5);
	push(&head,3);
	print(head,"linked list formed");
	quicksort(&head,0,5);
	print(head,"linked list formed");
}
