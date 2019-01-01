#include <iostream>
using namespace std;


struct Node
{
	int data;
	Node *next;
};


class queue
{

	private:
		Node *front;
		Node *rear;
		int size;
	public:
		queue(int s);
		~queue();
		void dQueue();
		void eQueue(int info);
		void display();
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
	Node *temp = front;
	while(temp != rear)
	{
		front = front->next;
		delete temp;
		temp = front;
	} 
	delete front, rear;
}


void queue::dQueue()
{
	if (front == NULL)
	{
		cout<<"underflow"<<endl;
		return;
	}

	if (front == rear)
	{
		node *temp = front;
		delete temp;
		front = NULL;
		rear = NULL;
		return;
	}
	Node *temp = front;
	front = front->next;
	size++;
	delete temp;
	return;
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
		rear = new Node;
		rear->next = NULL;
		rear->data = info;
		front = rear;
		size--;
		return;
	}
	rear->next = new Node;
	rear = rear->next;
	rear->next = NULL;
	rear->data = info;
	size--;
	return;
}

void queue::display()
{
	Node *temp = front;
	while(temp != rear)
	{
		cout<<temp->data;
		temp= temp->next;
	}
	cout<<rear->data<<endl;
}






int main()
{
	queue obj(4);
	obj.dQueue();
	obj.eQueue(5);
	obj.eQueue(8);
	// obj.dQueue();
	obj.eQueue(7);
	obj.eQueue(11);
	obj.eQueue(12);
	obj.display();
	obj.dQueue();
	obj.eQueue(55);
	obj.dQueue();
	obj.dQueue();
	obj.display();
	obj.dQueue();
	obj.dQueue();
	obj.dQueue();

	return 0;
}