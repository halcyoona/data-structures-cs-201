#include <iostream>
using namespace std;



class queue
{
	private:
		int *front;
		int *rear;
		int *lst;
		int size;
	public:
		queue(int s);
		~queue();
		void eQueue(int info);
		void dQueue();
		void display();
};


queue::queue(int s)
{
	size = s;
	lst = new int[size];
	for (int i = 0; i < size; ++i)
	{
		*(lst+i) = 0;
	}
	front = NULL;
	rear = NULL;

}

queue::~queue()
{
	delete [] lst;
	front == NULL;
	rear == NULL;
	size = 0;	
}


void queue::eQueue(int info)
{
	if ((front == lst && rear == lst+(size-1)) || front-1 == rear) 
	{
		cout<<"overflow"<<endl;
		return;
	}
	if (rear == NULL) // first time
	{
		rear = lst;
		*rear = info;
		front = rear;
		return;
	}
	if (front != lst && rear == lst+(size-1))  // if rear is on last and front is not in start
	{
		rear = lst;
		*rear = info;
		return;
	}
	rear++;		// commonly
	*rear = info;
	return;
}

void queue::dQueue()
{
	if (front == NULL)
	{
		cout<<"underflow"<<endl;
		return;
	}
	if (front == rear) // if front == rear i.e empty lst
	{
		front=NULL;
		rear=NULL;
		return;
		// cout<<"hello"<<endl;
	}
	if (front == lst+(size-1) && rear != lst+(size-1)) // if front is in the last and rear in not meet at comming to last and rear is in the start
	{
		front = lst;
		return;
	}
	front++;

}


void queue::display()
{
	int *temp = front;
	if (temp == NULL)
	{
		cout<<"Empty queue"<<endl;	
		return;
	}
	while(temp != rear)
	{
		if (temp == lst+(size-1))
		{
			temp = lst;
		}
		cout<<*temp<<" ";
		temp++;
	}
	if (temp == rear)
	{
		cout<<*temp<<endl;
		return;
	}
}


int main()
{

	queue obj(5);
	obj.eQueue(3);
	obj.eQueue(4);
	obj.eQueue(5);
	obj.eQueue(6);
	obj.eQueue(7);
	// obj.eQueue(8);
	obj.display();
	obj.dQueue();
	obj.dQueue();
	obj.dQueue();
	obj.eQueue(4);
	obj.dQueue();
	obj.dQueue();
	obj.dQueue();
	obj.eQueue(5);
	obj.display();
	return 0;
}