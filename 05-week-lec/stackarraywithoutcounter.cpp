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
	top = NULL;
}



stack::~stack()
{
	// delete top;
	delete [] lst;
}





void stack::push(int info)
{
	if (top == lst+(size-1))
	{
		cout<<"overflow"<<endl;
		return;
	}
	if (top == NULL)
	{
		top = lst;
		*top = info;
		return;
	}
	top++;
	*top = info;
	return;
	
}



void stack::pop()
{
	if (top == NULL)
	{
		cout<<"underflow"<<endl;
		return;
	}
	if (top == lst)
	{
		top == NULL;
		return;
	}
	top--;
	return;
}




void stack::display()
{
	int temp = 0;
	if (lst == NULL)
	{
		cout<<"stack is empty"<<endl;
		return;
	}
	while(temp+lst <= top)
	{
		cout<<*(lst+temp)<<" ";
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
	// obj.push(7);
	obj.display();
	obj.pop();
	obj.pop();
	// obj.pop();
	obj.push(5);
	// obj.pop();
	obj.display();
	// obj.push(4);
	// obj.pop();
	// obj.pop();
	// obj.display();
	return 0;
}