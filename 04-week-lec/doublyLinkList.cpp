#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
	Node *pre;
};


class doublyLinkList
{
	private:
		Node *head;

	public:
		doublyLinkList();
		~doublyLinkList();
		void addInTheEnd(int info);
		void addInTheStart(int info);
		void addFirst(int key, int info);
		void addMultiple(int key, int info);
		void delFirst(int info);
		void delMultiple(int info);
		void searchFirst(int info);
		void searchMultiple(int info);
		void display();
};


doublyLinkList::doublyLinkList()
{
	head = NULL;
}

doublyLinkList::~doublyLinkList()
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
}




void doublyLinkList::addInTheEnd(int info)
{
	if (head == NULL)
	{
		head = new Node;
		head->next = NULL;
		head->pre = NULL;
		head->data = info; 
	}
	else
	{
		Node *query;
		query = head;
		while(query != NULL)
		{
			if (query->next == NULL)
			{
				Node *temp = new Node;
				temp->data = info;
				temp->next = NULL;
				temp->pre = query;
				query->next = temp;
				return;
			}
			query = query->next;
		}
	}
}





void doublyLinkList::addInTheStart(int info)
{
	if (head == NULL)
	{
		head = new Node;
		head->next = NULL;
		head->pre = NULL;
		head->data = info; 
	}
	else
	{
		Node *temp = new Node;
		temp->data = info;
		temp->next = head;
		temp->pre = NULL;
		head->pre = temp;
		head = temp;
		return;
	}
}



void doublyLinkList::addFirst(int key, int info)
{
	if (head == NULL)
	{
		cout<<"doublyLinkList is empty"<<endl; 
	}
	else if (head->next == NULL && head->data == key)
	{
		Node *temp = new Node;
		temp->next = NULL;
		temp->pre = head;
		temp->data = info;
		head->next = temp;

	}	
	else
	{
		Node *query;
		query = head;
		while(query != NULL)
		{
			if (query == head && query->data == key)
			{
				Node *temp = new Node;
				temp->next = head->next;
				temp->pre = head;
				temp->data = info;
				head->next->pre = temp;
				head->next = temp;
				return;
			}
			else if (query->data == key && query->next == NULL)
			{
				Node *temp = new Node;
				temp->next = query->next;
				temp->pre = query;
				temp->data = info;
				query->next = temp;
				return;
			}
			else if (query->data == key)
			{
				Node *temp = new Node;
				temp->next = query->next;
				temp->pre = query;
				temp->data = info;
				query->next->pre = temp;
				query->next = temp;
				return;
			}
			query = query->next;
		}
	}
}


void doublyLinkList::addMultiple(int key, int info)
{
	if (head == NULL)
	{
		cout<<"doublyLinkList is empty"<<endl; 
	}
	else if (head->next == NULL && head->data == key)
	{
		Node *temp = new Node;
		temp->next = NULL;
		temp->pre = head;
		temp->data = info;
		head->next = temp;

	}	
	else
	{
		Node *query;
		query = head;
		while(query != NULL)
		{
			if (query == head && query->data == key)
			{
				Node *temp = new Node;
				temp->next = head->next;
				temp->pre = head;
				temp->data = info;
				head->next->pre = temp;
				head->next = temp;
				query = query->next;
			}
			else if (query->data == key && query->next == NULL)
			{
				Node *temp = new Node;
				temp->next = query->next;
				temp->pre = query;
				temp->data = info;
				query->next = temp;
				query = query->next;
			}
			else if (query->data == key)
			{
				Node *temp = new Node;
				temp->next = query->next;
				temp->pre = query;
				temp->data = info;
				query->next->pre = temp;
				query->next = temp;
				query = query->next;
				
			}
			query = query->next;
		}
	}
}


void doublyLinkList::delFirst(int key)
{
	if (head == NULL)
	{
		cout<<"doublyLinkList is empty"<<endl; 
	}
	else if (head->next == NULL && head->data == key)
	{
		head = NULL;

	}	
	else
	{
		Node *q;
		q = head;
		while(q != NULL)
		{
			if (q == head && q->data == key)
			{
				head = head->next;
				delete q;
				return;
			}
			else if (q->data == key && q->next == NULL)
			{
				q->pre->next = q->next;
				delete q;
				return;
			}
			else if (q->data == key)
			{
				q->pre->next = q->next;
				q = q->pre;
				delete q->next->pre;
				q->next->pre = q;
				return;
			}
			q = q->next;
		}
	}
}


void doublyLinkList::delMultiple(int key)
{
	if (head == NULL)
	{
		cout<<"doublyLinkList is empty"<<endl; 
	}
	else if (head->next == NULL && head->data == key)
	{
		head = NULL;

	}	
	else
	{
		Node *query;
		query = head;
		while(query != NULL)
		{
			if (query == head && query->data == key)
			{
				head = head->next;
				delete query;
				query = head;
			}
			else if (query->data == key && query->next == NULL)
			{
				query->pre->next = query->next;
				delete query;
				return;
			}

			else if (query->data == key)
			{
				query->pre->next = query->next;
				query = query->pre;
				delete query->next->pre;
				query->next->pre = query;
			}
			query = query->next;
		}
	}
}


void doublyLinkList::searchFirst(int key)
{
	if (head == NULL)
	{
		cout<<"doublyLinkList is empty"<<endl; 
	}
	else if (head->next == NULL && head->data == key)
	{
		cout<<key<<" is in doublyLinkList "<<endl;

	}	
	else
	{
		Node *q;
		q = head;
		while(q != NULL)
		{
			if (q->data == key)
			{
				cout<<key<<" is in doublyLinkList "<<endl;
				return;
			}
			q = q->next;
		}
	}
}



void doublyLinkList::searchMultiple(int key)
{
	if (head == NULL)
	{
		cout<<"doublyLinkList is empty"<<endl; 
	}
	else if (head->next == NULL && head->data == key)
	{
		cout<<key<<" is in doublyLinkList "<<endl;

	}	
	else
	{
		Node *query;
		query = head;
		while(query != NULL)
		{
			if (query->data == key)
			{
				cout<<key<<" is in doublyLinkList "<<endl;
			}
			query = query->next;
		}
	}
}

void doublyLinkList::display()
{
	Node *query;
	query = head;
	int count = 1;
	while(query != NULL)
	{
		cout<<count<<" : "<<query->data<<endl;
		query = query->next;
		count += 1;
	}
}


int main()
{
	doublyLinkList dll;
	dll.addInTheEnd(6);
	dll.addInTheStart(2);
	dll.addInTheEnd(4);
	dll.addInTheStart(8);
	dll.addInTheStart(5);
	dll.addInTheStart(4);
	dll.display();
	// dll.delFirst(5);
	// dll.display();
	dll.searchFirst(4);
	// dll.delMultiple(4);
	// dll.searchMultiple(4);
	dll.addFirst(4,6);
	dll.addMultiple(4,7);
	dll.delMultiple(4);
	dll.display();
	return 0;
}