#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

class linklist
{
	protected:
		Node *head;
		Node *tail;
	public:
		linklist();
		~linklist();
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


linklist::linklist()
{
	head = NULL;
	tail = NULL;
}

linklist::~linklist()
{
	Node *p;
	Node *q;
	q = head;
	while(q != NULL)
	{
		p = q;
		q = q->next;
		delete p;
	}
}

void linklist::addInTheStart(int info)
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


void linklist::addInTheEnd(int info)
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



void linklist::addMultiple(int info, int val)
{
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
	}
	else if(head == tail)
	{
		if(head->data == info)
		{
			Node *temp = new Node;
			temp->next = NULL;
			temp->data = val;
			head ->next = temp;
			tail = temp;
		}
		else
		{
			cout<<info<<" There is no Node with this data"<<endl;
		}
	}
	else
	{
		Node *q;
		q = head;	
		while(q != NULL)
		{
			if(q->next == tail->next && q->data == info)
			{
				Node *temp = new Node;
				temp->data = val;
				temp->next = NULL;
				tail->next = temp;
				tail = temp;
			}
			else if(q->data == info)
			{
				Node *temp = new Node;
				temp->data = val;
				temp->next = q->next;
				q->next = temp;
			}	
			q = q->next;
		}
	}
}

void linklist::addFirst(int info, int val)
{
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
	}
	else if(head == tail)
	{
		if(head->data == info)
		{
			Node *temp = new Node;
			temp->next = NULL;
			temp->data = val;
			head ->next = temp;
			tail = temp;
		}
		else
		{
			cout<<info<<" There is no Node with this data"<<endl;
		}
	}
	else
	{
		Node *q;
		q = head;	
		while(q != NULL)
		{
			if(q->next == tail->next && q->data == info)
			{
				Node *temp = new Node;
				temp->data = val;
				temp->next = NULL;
				tail->next = temp;
				tail = temp;
				return;
			}
			else if(q->data == info)
			{
				Node *temp = new Node;
				temp->data = val;
				temp->next = q->next;
				q->next = temp;
				return;
			}	
			q = q->next;
		}
	}
}




void linklist::display()
{
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
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

void linklist::delMultiple(int info)
{
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
	}
	else if(head == tail)
	{
		if(head->data == info)
		{
			delete head;
			head = NULL;
			tail = NULL;
		}
		else
		{
			cout<<info<<endl;
			cout<<"There is no Node with this data"<<endl;
		}
	}
	else
	{
		Node *q;
		Node *p;
		q = head;
		p = q;		
		if(head->data == info)
		{
			head = head->next;
			delete q;
			q = p;
		}
		while(q != NULL)
		{
			if(q->data == tail->data && q->data == info)
			{
				tail = p;
				tail->next = NULL;
				delete q;
			}
			else if(q->data == info)
			{
				p->next = q->next;
				delete q;
				q = p;
			}
			else
			{
				p = q;
				q = q->next;
			}
		}
	
	}
}


void linklist::delFirst(int info)
{
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
	}
	else if(head == tail)
	{
		if(head->data == info)
		{
			delete head;
			head = NULL;
			tail = NULL;
		}
		else
		{
			cout<<info<<endl;
			cout<<"There is no Node with this data"<<endl;
		}
	}
	else
	{
		Node *q;
		Node *p;
		q = head;
		p = q;		
		if(head->data == info)
		{
			head = head->next;
			delete q;
			return;
		}
		while(q != NULL)
		{
			if(q->data == tail->data && q->data == info)
			{
				tail = p;
				tail->next = NULL;
				delete q;
			}
			else if(q->data == info)
			{
				p->next = q->next;
				delete q;
				return;
			}
			else
			{
				p = q;
				q = q->next;
			}
		}
	
	}
}


void linklist::searchMultiple(int info)
{
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
	}
	else if(head == tail)
	{
		if(head->data == info)
		{
			cout<<info<<" is in linklist"<<endl;
		}
		else
		{
			cout<<info<<endl;
			cout<<"There is no Node with this data"<<endl;
		}
	}
	else
	{
		Node *q;
		q = head;
		while(q != NULL)
		{	
			if(q->data == info)
			{
				cout<<info<<" is in linklist"<<endl;	
			}
			q = q->next;
		}
	
	}
}

void linklist::searchFirst(int info)
{
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
	}
	else if(head == tail)
	{
		if(head->data == info)
		{
			cout<<info<<" is in linklist"<<endl;
		}
		else
		{
			cout<<info<<endl;
			cout<<"There is no Node with this data"<<endl;
		}
	}
	else
	{
		Node *q;
		q = head;
		while(q != NULL)
		{	
			if(q->data == info)
			{
				cout<<info<<" is in linklist"<<endl;
				return;	
			}
			q = q->next;
		}
	
	}
}



int main()
{

	linklist l;
	l.addInTheEnd(25);
	l.addInTheEnd(40);
	l.addInTheEnd(23);
	// l.addInTheEnd(422);
	l.display();
	// l.del(40);
	l.addInTheStart(23);
	// l.addInTheStart(23);
	l.addMultiple(23,55);
	// l.addInTheEnd(24);
	// l.delFirst(23);
	// l.searchMultiple(23);
	// l.searchFirst(23);
	// l.del(24);
	l.display();
	return 0;
}
