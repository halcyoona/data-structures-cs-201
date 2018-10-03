#include <iostream>
using namespace std;


struct Node
{
	int data;
	Node *next;
};


class singlyRing
{
	private:
		Node *head;
	public:
		singlyRing();
		~singlyRing();
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


singlyRing::singlyRing()
{
	head = NULL;
}

singlyRing::~singlyRing()
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

void singlyRing::addInTheEnd(int info)
{
	if (head == NULL)
	{
		head = new Node;
		head->data = info;
		head->next = head;
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
		temp->data = info;
		query->next = temp;
	}
}

void singlyRing::addInTheStart(int info)
{
	if (head == NULL)
	{
		head = new Node;
		head->data = info;
		head->next = head;
	}
	else
	{
		Node *query = head;
		if (query->next == head)
		{
			Node *temp = new Node;
			temp->next = head;
			temp->data = info;
			head->next = temp;
			head = temp;
		}
		else
		{
			while(query->next != head)
			{
				query = query->next;
			}
			Node *temp = new Node;
			temp->next = head;
			temp->data = info;
			query->next = temp;
			head = temp;	
		}
	}
}


void singlyRing::addFirst(int key, int info)
{
	if (head == NULL)
	{
		cout<<"singlyRing is empty"<<endl;
	}
	else if (head->data == key && head->next == head)
	{
		Node *temp = new Node;
		temp->next = head;
		temp->data = info;
		head->next = temp;
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
				temp->data = info;
				query->next = temp;
				return;
			}
			query = query->next;
		}
		if (query->data == key && query->next == head)
		{
			Node *temp = new Node;
			temp->next = head;
			temp->data = info;
			query->next = temp;
		}
	}
}



void singlyRing::addMultiple(int key, int info)
{
	if (head == NULL)
	{
		cout<<"singlyRing is empty"<<endl;
	}
	else if (head->data == key && head->next == head)
	{
		Node *temp = new Node;
		temp->next = head;
		temp->data = info;
		head->next = temp;
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
				temp->data = info;
				query->next = temp;
				query = query->next;
			}
			query = query->next;
		}
		if (query->data == key && query->next == head)
		{
			Node *temp = new Node;
			temp->next = head;
			temp->data = info;
			query->next = temp;
		}
	}
}



void singlyRing::delMultiple(int key)
{
	if (head == NULL)
	{
		cout<<"singlyRing is empty"<<endl;
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
		Node *pre = head;
		while(query->next != head)
		{
			if (query->data == key && query == head)
			{
				while(query->next != head)
				{
					query = query->next;
				}
				head = head->next;
				query->next = head;
				delete pre;
				pre = head;
			}
			if (query->data == key)
			{
				pre->next = query->next;
				delete query;
				query = pre;
			}
			pre = query;
			query = query->next;
		}
		if (query->data == key && query->next == head)
		{
			pre->next = query->next;
			delete query;
		}
	}
}


void singlyRing::delFirst(int key)
{
	if (head == NULL)
	{
		cout<<"singlyRing is empty"<<endl;
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
		Node *pre = head;
		while(query->next != head)
		{
			if (query->data == key && query == head)
			{
				while(query->next != head)
				{
					query = query->next;
				}
				head = head->next;
				query->next = head;
				delete pre;
				return;
			}
			if (query->data == key)
			{
				pre->next = query->next;
				delete query;
				return;
			}
			pre = query;
			query = query->next;
		}
		if (query->data == key && query->next == head)
		{
			pre->next = query->next;
			delete query;
			return;
		}
	}
}




void singlyRing::searchFirst(int key)
{
	if (head == NULL)
	{
		cout<<"singlyRing is empty"<<endl;
	}
	else if (head->data == key && head->next == head)
	{
		cout<<key<<" is in singlyRing"<<endl;
	}
	else
	{
		Node *query = head;
		while(query->next != head)
		{
			if (query->data == key)
			{
				cout<<key<<" is in singlyRing"<<endl;
				return;
			}
			query = query->next;
		}
		if (query->data == key && query->next == head)
		{
			cout<<key<<" is in singlyRing"<<endl;
			return;
		}
	}
}



void singlyRing::searchMultiple(int key)
{
	if (head == NULL)
	{
		cout<<"singlyRing is empty"<<endl;
	}
	else if (head->data == key && head->next == head)
	{
		cout<<key<<" is in singlyRing"<<endl;
	}
	else
	{
		Node *query = head;
		while(query->next != head)
		{
			if (query->data == key)
			{
				cout<<key<<" is in singlyRing"<<endl;
			}
			query = query->next;
		}
		if (query->data == key && query->next == head)
		{
			cout<<key<<" is in singlyRing"<<endl;
			return;
		}
	}
}




void singlyRing::display()
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
	singlyRing obj;
	obj.addInTheEnd(2);
	obj.addInTheEnd(4);
	obj.addInTheEnd(5);
	obj.display();
	obj.addInTheStart(7);
	obj.addFirst(5,5);
	obj.searchFirst(2);
	obj.addMultiple(5,5);
	obj.display();
	obj.delFirst(7);
	obj.searchMultiple(5);
	obj.delMultiple(5);
	obj.display();
	return 0;
}