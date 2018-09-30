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
	public:
		linklist();
		~linklist();
		void addInTheEnd(int info);
		void addInTheStart(int info);
		void addMultiple(int info, int val);
		void addFirst(int info, int val);
		void delFirst(int info);
		void delMultiple(int info);
		void SearchFirst(int info);
		void SearchMultiple(int info);
		void display();
};


linklist::linklist()
{
	head = NULL;
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
	Node *q;
	q = head;
	if(head == NULL)
	{
		head = temp;
	}
	else
	{
		while(q->next != NULL)
		{
			q = q->next;
		}
		q->next = temp;
	}
	
}


void linklist::addMultiple(int info, int val)
{
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
	}
	else if(head->next == NULL)
	{
		if(head->data == info)
		{
			Node *temp = new Node;
			temp->next = NULL;
			temp->data = val;
			head ->next = temp;
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
			if(q->data == info)
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
	else if(head->next == NULL)
	{
		if(head->data == info)
		{
			Node *temp = new Node;
			temp->next = NULL;
			temp->data = val;
			head ->next = temp;
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
			if(q->data == info)
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


// Delete First occurence
void linklist::delFirst(int info)
{
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
	}
	else if(head->data == info && head->next == NULL)
	{
		head = NULL;
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
		}
		else
		{
			while(q != NULL)
			{
				if(q->data == info && q->next == NULL)
				{
					p->next = NULL;
					delete q;
					return;
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
}




void linklist::delMultiple(int info)
{
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
	}
	else if(head->data == info && head->next == NULL)
	{
		head = NULL;
	}
	else
	{
		Node *q;
		Node *p;
		q = head;
		p = q;		
	
		while(q != NULL)
		{
			if (q->data == info && q == head)
			{
				head = head -> next;
				delete q;
				q = head;
			}

			else if(q->data == info && q->next == NULL)
			{
				p->next = NULL;
				delete q;
				q = p->next;
			}
			else if(q->data == info)
			{
				p->next = q->next;
				delete q;
				q = p->next;
			}
			else
			{
				p = q;
				q = q->next;
			}
		}
	}
}




void linklist::SearchFirst(int info)
{
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
	}
	else if(head->data == info && head->next == NULL)
	{
		cout<<info<<" is in linklist"<<endl;
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
				delete q;
				return;
			}
			q = q->next
		}
	}
}


void linklist::SearchFirst(int info)
{
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
	}
	else if(head->data == info && head->next == NULL)
	{
		cout<<info<<" is in linklist"<<endl;
	}
	else
	{
		int count = 0;
		Node *q;
		q = head;		
		while(q != NULL)
		{
			if(q->data == info)
			{
				cout<<info<<" is in linklist"<<endl;
				count += 1;
			}
			q = q->next
		}
		if (count == 0)
		{
			cout<<info<<" is not in linklist"<<endl;
		}
	}
}




int main()
{

	linklist l;
	l.addInTheEnd(41);
	l.addInTheEnd(41);
	l.addInTheEnd(41);
	// l.addInTheEnd(422);
	l.display();
	l.delMultiple(41);

	l.addInTheStart(12);
	l.addInTheStart(23);
	l.addInTheEnd(24);
	// // l.del(25);
	// l.del(24);
	l.display();
	return 0;
}
