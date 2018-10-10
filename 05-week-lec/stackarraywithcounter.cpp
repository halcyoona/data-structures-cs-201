#include <iostream>
using namespace std;


class stack
{
	private:
		int *top;
		int count;
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
	top = new int [size];
	for (int i = 0; i < size; i++)
	{
		*(top+i) = 0;
	}
}



stack::~stack()
{
	// delete top;
	delete [] top;
}



void stack::push(int info)
{
	if (count == size)
	{
		cout<<"overflow"<<endl;
		return;
	}
	*(top+count) = info;
	count++;
	return;
	
}

void stack::pop()
{
	if (count == 0)
	{
		cout<<"underflow"<<endl;
		return;
	}
	count--;
}

void stack::display()
{
	int tempCount = 0;
	while(tempCount != count)
	{
		cout<<*(top+tempCount);
		tempCount++;
	}
	cout<<endl;
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
	obj.pop();
	// obj.pop();
	obj.push(23);
	// obj.pop();
	// obj.pop();
	// obj.pop();
	obj.display();
	return 0;
}