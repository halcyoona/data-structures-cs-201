#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
	Node *pre;
};



class doublyRing
{
	private:
		Node *head;
	public:
		doublyRing();
		~doublyRing();
		void addInTheEnd(int info);
		void addInTheStart(int info);
		void addFirst(int key, int info);
		void addMultiple(int key, int info);
		void delFirst(int key);
		void delMultiple(int key);
		void searchFirst(int key);
		void searchMultiple(int key);
		void display();
};



doublyRing::doublyRing()
{
	head = NULL;
}

doublyRing::~doublyRing()
{
	Node *query = head->next;
	Node *pre = query;
	while(query->next != head)
	{
		pre = query;
		query = query->next;
		delete pre;
	}
	delete head, query;
}


void doublyRing::addInTheEnd(int info)
{
	if (head == NULL)
	{
		head = new Node;
		head->data = info;
		head->next = head;
		head->pre = head;
	}
	else
	{
		Node *query = head;
		while(query->next != head)
		{
			query = query->next;
		}
		Node *temp = new Node;
		temp->next = head;
		temp->pre = query;
		temp->data = info;
		head->pre = temp;
		query->next = temp;
	}
}



void doublyRing::addInTheStart(int info)
{
	if (head == NULL)
	{
		head = new Node;
		head->data = info;
		head->next = head;
		head->pre = head;
	}
	else
	{
		Node *query = head;

		while(query->next != head)
		{
			query = query->next;
		}
		Node *temp = new Node;
		temp->next = head;
		temp->pre = query;
		temp->data = info;
		query->next = temp;
		head->pre = temp;
		head = temp;	
	}
}



void doublyRing::addFirst(int key, int info)
{
	if (head == NULL)
	{
		cout<<"doublyRing is empty"<<endl;
	}
	else if (head->data == key && head->next == head)
	{
		Node *temp = new Node;
		temp->next = head;
		temp->pre = head;
		temp->data = info;
		head->next = temp;
		head->pre = temp;
	}
	else
	{
		Node *query = head;
		while(query->next != head)
		{
			if (query->data == key)
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
		if (query->data == key && query->next == head)
		{
			Node *temp = new Node;
			temp->next = head;
			temp->pre = query;
			temp->data = info;
			head->pre = temp;
			query->next = temp;
		}
	}
}


void doublyRing::addMultiple(int key, int info)
{
	if (head == NULL)
	{
		cout<<"doublyRing is empty"<<endl;
	}
	else if (head->data == key && head->next == head)
	{
		Node *temp = new Node;
		temp->next = head;
		temp->pre = head;
		temp->data = info;
		head->next = temp;
		head->pre = temp;
	}
	else
	{
		Node *query = head;
		while(query->next != head)
		{
			if (query->data == key)
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
		if (query->data == key && query->next == head)
		{
			Node *temp = new Node;
			temp->next = head;
			temp->pre = query;
			temp->data = info;
			head->pre = temp;
			query->next = temp;
		}
	}
}


void doublyRing::delFirst(int key)
{
	if (head == NULL)
	{
		cout<<"doublyRing is empty"<<endl;
	}
	else if (head->data == key && head->next == head)
	{
		Node *query = head;
		delete query;
		head = NULL; 
	}
	else
	{
		Node *query = head;
		while(query->next != head)
		{
			if (query->data == key && query == head)
			{
				head = head->next;
				head->pre = query->pre;
				query->pre->next = head;
				delete query;
				return;
			}
			if (query->data == key)
			{
				query->pre->next = query->next;
				query = query->pre;
				delete query->next->pre;
				query->next->pre = query; 
				return;
			}
			query = query->next;
		}
		if (query->data == key && query->next == head)
		{
			query->pre->next = query->next;
			query = query->pre;
			delete query->next->pre;
			query->next->pre = query;
			return;
		}
	}
}



void doublyRing::delMultiple(int key)
{
	if (head == NULL)
	{
		cout<<"doublyRing is empty"<<endl;
	}
	else if (head->data == key && head->next == head)
	{
		Node *query = head;
		delete query;
		head = NULL; 
	}
	else
	{
		Node *query = head;
		while(query->next != head)
		{
			if (query->data == key && query == head)
			{
				head = head->next;
				head->pre = query->pre;
				query->pre->next = head;
				delete query;
				query = head->pre;
			}
			if (query->data == key)
			{
				query->pre->next = query->next;
				query = query->pre;
				delete query->next->pre;
				query->next->pre = query; 
			}
			query = query->next;
		}
		if (query->data == key && query->next == head)
		{
			query->pre->next = query->next;
			query = query->pre;
			delete query->next->pre;
			query->next->pre = query;
			return;
		}
	}
}





void doublyRing::searchFirst(int key)
{
	if (head == NULL)
	{
		cout<<"doublyRing is empty"<<endl;
	}
	else if (head->data == key && head->next == head)
	{
		cout<<key<<" is in doublyRing"<<endl; 
	}
	else
	{
		Node *query = head;
		while(query->next != head)
		{
			if (query->data == key)
			{
				cout<<key<<" is in doublyRing"<<endl;
				return; 
			}
			query = query->next;
		}
		if (query->data == key && query->next == head)
		{
			cout<<key<<" is in doublyRing"<<endl;
			return;
		}
	}
}




void doublyRing::searchMultiple(int key)
{
	if (head == NULL)
	{
		cout<<"doublyRing is empty"<<endl;
	}
	else if (head->data == key && head->next == head)
	{
		cout<<key<<" is in doublyRing"<<endl; 
	}
	else
	{
		Node *query = head;
		while(query->next != head)
		{
			if (query->data == key)
			{
				cout<<key<<" is in doublyRing"<<endl; 
			}
			query = query->next;
		}
		if (query->data == key && query->next == head)
		{
			cout<<key<<" is in doublyRing"<<endl;
		}
	}
}





void doublyRing::display()
{
	if (head == NULL)
	{
		cout<<"singlyRing is empty"<<endl;
		return;
	}
	Node *query = head;
	if (query->next == head)
	{
		cout<<query->data<<" ";
	}
	else
	{
		while(query->next != head)
		{
			cout<<query->data<<" ";
			query = query->next;
		}	
		cout<<query->data<<" "<<endl;
		// cout<<query->data<<endl;
	}
}


int main()
{
	doublyRing obj;
	obj.addInTheStart(4);
	obj.addInTheStart(5);
	obj.addInTheEnd(1);
	obj.addInTheEnd(4);
	obj.delFirst(5);
	obj.display();
	obj.addInTheStart(7);
	obj.addInTheEnd(3);
	obj.delMultiple(4);
	obj.display();
	return 0;
}