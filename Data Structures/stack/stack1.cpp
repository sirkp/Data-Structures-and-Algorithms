#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
class Stack
{
private:
	int arr[MAX];
	int top;
public:
	Stack(){
		top = -1;
	}
	void push(int data);
	int pop();
	int peek();
	int size();
	bool isEmpty();
	void print();
};

void Stack::push(int data)
{
	if(top>=(MAX-1))
	cout<<"Stack Overflow\n";
	else
	{
		top=top+1;
		arr[top] = data;
	}	
}

int Stack::size(){return top+1;}

int Stack::peek()
{	
	if(isEmpty())
	{
		cout<<"Stack is empty\n";
		return NULL;
	}	
	else
	{
		return arr[top];
	}
}

int Stack::pop()
{
	if(isEmpty())
	{
		cout<<"Stack is empty\n";
		return NULL;
	}
	else
	{
		top = top-1;
		return arr[top+1];
	}	
}
void Stack::print()
{
	for(int i=0;i<=top;i++)
	cout<<arr[i]<<" ";
	cout<<endl<<endl;	
}

bool Stack::isEmpty(){return (top<0);}

int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(8);

	s.print();

	cout<<s.size()<<endl;

	cout<<s.peek()<<endl;
}