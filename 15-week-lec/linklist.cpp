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
		int checking();
		void display();
};


linklist::linklist()
{
	head = NULL;
	tail = NULL;
}

linklist::~linklist()
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


int linklist::checking()
{
	if (head == NULL)
	{
		return 0;
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
		Node *query;
		query = head;	
		while(query != NULL)
		{
			if(query->next == tail->next && query->data == info)
			{
				Node *temp = new Node;
				temp->data = val;
				temp->next = NULL;
				tail->next = temp;
				tail = temp;
			}
			else if(query->data == info)
			{
				Node *temp = new Node;
				temp->data = val;
				temp->next = query->next;
				query->next = temp;
			}	
			query = query->next;
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
		Node *query;
		query = head;	
		while(query != NULL)
		{
			if(query->next == tail->next && query->data == info)
			{
				Node *temp = new Node;
				temp->data = val;
				temp->next = NULL;
				tail->next = temp;
				tail = temp;
				return;
			}
			else if(query->data == info)
			{
				Node *temp = new Node;
				temp->data = val;
				temp->next = query->next;
				query->next = temp;
				return;
			}	
			query = query->next;
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
		Node *query;
		Node *pre;
		query = head;
		pre = query;		
		if(head->data == info)
		{
			head = head->next;
			delete query;
			query = head;
		}
		while(query != NULL)
		{
			if(query->data == tail->data && query->data == info)
			{
				tail = pre;
				tail->next = NULL;
				delete query;
			}
			else if(query->data == info)
			{
				pre->next = query->next;
				delete query;
				query = pre;
			}
			else
			{
				pre = query;
				query = query->next;
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
		Node *query;
		Node *pre;
		query = head;
		pre = query;		
		if(head->data == info)
		{
			head = head->next;
			delete query;
			return;
		}
		while(query != NULL)
		{
			if(query->data == tail->data && query->data == info)
			{
				tail = pre;
				tail->next = NULL;
				delete query;
			}
			else if(query->data == info)
			{
				pre->next = query->next;
				delete query;
				return;
			}
			else
			{
				pre = query;
				query = query->next;
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
		Node *query;
		query = head;
		while(query != NULL)
		{	
			if(query->data == info)
			{
				cout<<info<<" is in linklist"<<endl;	
			}
			query = query->next;
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
		Node *query;
		query = head;
		while(query != NULL)
		{	
			if(query->data == info)
			{
				cout<<info<<" is in linklist"<<endl;
				return;	
			}
			query = query->next;
		}
	
	}
}


