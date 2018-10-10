#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};


class stack
{
	private:
		Node *top;
		int size;
	public:
		stack(int s);
		~stack();
		void push(int info);
		void pop();	
		void display();
};



stack::stack(int s)
{
	top = NULL;
	size = s;
}



stack::~stack()
{
	Node *temp = top;
	while(temp != NULL)
	{
		top = temp;
		temp = temp->next;
		delete top;
	}
	delete temp;
}



void stack::push(int info)
{
	if (size == 0)
	{
		cout<<"overflow"<<endl;
		return;
	}	
	Node *temp = new Node; 
	temp->next = top;
	temp->data = info;
	top = temp;
	size--;
}



void stack::pop()
{
	
	if (top == NULL)
	{
		cout<<"underflow"<<endl;
		return;
	}
	Node *temp = top;
	top = top->next;
	size++;
	delete temp;
}


void stack::display()
{
	Node *temp = top;
	while(temp != NULL)
	{
		cout<<temp->data<<endl;
		temp = temp->next;
	}
}



int main()
{
	stack obj(5);
	obj.pop();
	obj.push(2);
	obj.push(3);
	obj.push(4);
	obj.push(5);
	obj.push(6);
	obj.push(7);
	obj.display();
	obj.pop();
	obj.push(7);
	obj.push(9);

	// cout<<" "<<endl;
	obj.pop();
	obj.pop();
	obj.pop();
	obj.pop();
	obj.push(55);
	obj.push(11);
	// obj.pop();
	obj.pop();
	// obj.push(7);
	obj.display();
	return 0;
}