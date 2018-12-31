#include <iostream>
using namespace std;


struct node
{
	int data;
	node *next;
};


class queue
{

	private:
		node *front;
		node *rear;
		int size;
	public:
		queue(int s);
		~queue();
		int dQueue();
		void eQueue(int info);
		int search(int info);
		int checkSize();
};


queue::queue(int s)
{
	front = NULL;
	rear = NULL;
	size = s;
}


queue::~queue()
{
	if (front == NULL)
	{
		return;
	}
	node *temp = front;
	while(temp != rear)
	{
		front = front->next;
		delete temp;
		temp = front;
	} 
	delete front, rear;
}


int queue::dQueue()
{
	if (front == NULL)
	{
		cout<<"underflow"<<endl;
		return 0;
	}
	if (front == rear)
	{
		node *temp = front;
		int num = temp->data;
		delete temp;
		front = NULL;
		rear = NULL;
		return num;
	}
	node *temp = front;
	front = front->next;
	size++;
	int num = temp->data;
	delete temp;
	return num;
}

void queue::eQueue(int info)
{
	if (size == 0)
	{
		cout<<"Overflow"<<endl;
		return;
	}
	if (rear == NULL)
	{
		rear = new node;
		rear->next = NULL;
		rear->data = info;
		front = rear;
		size--;
		return;
	}
	rear->next = new node;
	rear = rear->next;
	rear->next = NULL;
	rear->data = info;
	size--;
	return;
}

int queue::search(int info)
{
	node *temp = front;
	while(temp != rear)
	{
		if(temp->data == info)
			return 1;
		temp= temp->next;
	}
	if (rear != NULL)
	{

		if (rear->data == info)
			return 1;
	}
	return 0;
}


int queue::checkSize()
{
	return size;
}



