#include<iostream>
#include"linklist.cpp"
using namespace std;


struct list
{
	int data;
	list *next;
};


struct Node
{
	char data;
	int num;
	Node *next;
	list *head;
};

class graph
{
	protected:
		Node *head;
		Node *tail;
	public:
		graph();
		~graph();
		void addInTheEnd(int info);
		void addInTheStart(int info);
		void addMultiple(int info, int val);
		void addFirst(int info, int val);
		void delMultiple(int info);
		void delFirst(int info);
		void searchMultiple(int info);
		void searchFirst(int info);
		void display();
};


graph::graph()
{
	head = NULL;
	tail = NULL;
}

graph::~graph()
{
	Node *pre;
	Node *query;
	query = head;
	while(query != NULL)
	{
		pre = query;
		query = query->next;
		delete pre;
	}
	delete query;
	delete head;
}

void graph::addInTheStart(int info)
{
	Node *temp = new Node;
	temp->data = info;
	temp->next = NULL;
	if(head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
	
}


void graph::addInTheEnd(int info)
{
	Node *temp = new Node;
	temp->data = info;
	temp->next = NULL;
	if(head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
	
}




void graph::display()
{
	if(head==NULL)
	{
		cout<<"graph is empty"<<endl;
	}
	else
	{
		int i = 1;
		Node *temp;
		temp = head;
		while(temp != NULL)
		{
			cout<<i<<" : "<<temp->data<<endl;
			temp = temp->next;
			i++;
		}
	}
}



int main()
{
	return 0;
}
