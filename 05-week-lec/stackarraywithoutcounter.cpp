#include <iostream>
using namespace std;



class stack
{
	private:
		int *top;
		int *lst;
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
	size = s;

	lst = new int [size];
	for (int i = 0; i < size; i++)
	{
		*(lst+i) = 0;
	}
	top = lst;
}



stack::~stack()
{
	// delete top;
	delete [] top;
}



void stack::push(int info)
{
	if (size == 0)
	{
		cout<<"overflow"<<endl;
		return;
	}
	*top = info;
	top++;
	size--;
	return;
	
}

void stack::pop()
{
	if (top == lst)
	{
		cout<<"underflow"<<endl;
		return;
	}
	size++;
	top--;
}

void stack::display()
{
	int *temp = lst;
	if (lst == top)
	{
		cout<<"stack is empty"<<endl;
		return;
	}
	while(temp != top)
	{
		cout<<*temp<<" ";
		temp++;
	}
	cout<<endl;
}

int main()
{
	stack obj(5);
	// obj.pop();
	obj.push(2);
	obj.push(3);
	// obj.push(4);
	// obj.push(5);
	obj.push(6);
	obj.push(7);
	obj.display();
	obj.pop();
	// obj.pop();
	obj.pop();
	// obj.push(5);
	obj.pop();
	// obj.push(4);
	// obj.pop();
	obj.pop();
	obj.display();
	return 0;
}