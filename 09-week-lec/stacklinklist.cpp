#include <iostream>
#include "bstModified.cpp"
using namespace std;

struct node
{
	bst *data;
	node *next;
};


class stack
{
	private:
		
		int size;
	public:
		node *top;
		stack(int s);
		~stack();
		void push(bst *info);
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
	node *temp = top;
	while(temp != NULL)
	{
		top = temp;
		temp = temp->next;
		delete top;
	}
	delete temp;
}



void stack::push(bst *info)
{
	if (size == 0)
	{
		cout<<"overflow"<<endl;
		return;
	}	
	node *temp = new node; 
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
	node *temp = top;
	top = top->next;
	size++;
	delete temp;
}


void stack::display()
{
	node *temp = top;
	while(temp != NULL)
	{
		temp->data->in_ord(temp->data->root);
		temp = temp->next;
	}
}



int main()
{
	stack obj(5);
	bst *bstObj;
	bstObj->number = 5;
	// obj.pop();
	bstObj->insert(bstObj->root);
	obj.push(bstObj);
	// obj.push(3);
	// obj.push(4);
	// obj.push(5);
	// obj.push(6);
	// obj.push(7);
	// obj.display();
	// obj.pop();
	// obj.push(7);
	// obj.push(9);

	// // cout<<" "<<endl;
	// obj.pop();
	// obj.pop();
	// obj.pop();
	// obj.pop();
	// obj.push(55);
	// obj.push(11);
	// // obj.pop();
	// obj.pop();
	// obj.push(7);
	obj.display();
	return 0;
}