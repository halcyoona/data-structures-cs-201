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
	Node *query;
	query = head;
	if(head == NULL)
	{
		head = temp;
	}
	else
	{
		while(query->next != NULL)
		{
			query = query->next;
		}
		query->next = temp;
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
		Node *query;
		query = head;	
		while(query != NULL)
		{
			if(query->data == info)
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
		Node *query;
		query = head;	
		while(query != NULL)
		{
			if(query->data == info)
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
		Node *query;
		Node *pre;
		query = head;
		pre = query;		
		if(head->data == info)
		{
			head = head->next;
			delete query;
		}
		else
		{
			while(query != NULL)
			{
				if(query->data == info && query->next == NULL)
				{
					pre->next = NULL;
					delete query;
					return;
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
		Node *query;
		Node *pre;
		query = head;
		pre = query;		
	
		while(query != NULL)
		{
			if (query->data == info && query == head)
			{
				head = head -> next;
				delete query;
				query = head;
			}

			else if(query->data == info && query->next == NULL)
			{
				pre->next = NULL;
				delete query;
				query = pre->next;
			}
			else if(query->data == info)
			{
				pre->next = query->next;
				delete query;
				query = pre->next;
			}
			else
			{
				pre = query;
				query = query->next;
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
		Node *query;
		query = head;		
		while(query != NULL)
		{
			
			if(query->data == info)
			{
				cout<<info<<" is in linklist"<<endl;
				delete query;
				return;
			}
			query = query->next
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
		Node *query;
		query = head;		
		while(query != NULL)
		{
			if(query->data == info)
			{
				cout<<info<<" is in linklist"<<endl;
				count += 1;
			}
			query = query->next
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
