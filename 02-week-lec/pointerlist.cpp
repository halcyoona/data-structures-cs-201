#include <iostream>
using namespace std;

class list
{
	private:
		int *lst;
		int *curr;
		int size;  //size is for filled index
		int length;	// length is total index
	public:
		list(int len);
		~list();
		void update(int val);
		void addInTheEnd(int val);
		void addAtPosition(int ind, int val);
		void addInTheStart(int val);
		void search(int val);
		void deleteByValue(int val);
		void deleteByIndex(int ind);
		int* getCurrent();
		int lengthOf();
		int sizeOf();
		void next(); 
		void back();
		void start();
		void end();
		void show();

};

list::list(int len)
{
	lst = new int[len];
	length = len;
	curr == NULL;
	size = 0;
}

list::~list()
{
	delete lst;
	delete curr;
}


void list::addInTheEnd(int val)
{
	curr = lst;
	if (size == 0)
	{
		*curr = val;
		size += 1;
		curr++;
	}
	else if (size < length)
	{
		*(curr + size) = val;
		curr++;
		size += 1;
	}
	else
	{
		cout<<"Index out of bound"<<endl;
	}
}


void list::addAtPosition(int ind, int val)
{
	if (size < length)
	{
		if (ind == 0)
		{
			addInTheStart(val);
			return;
		}
		else if (ind == size)
		{
			addInTheEnd(val);
		}
		else
		{
			curr = lst+size;
			ind = size - ind;
			while(ind != 0)
			{
				curr--;
				*(curr+1) = *curr;
				ind -= 1;
			}
			*curr = val;
			size += 1; 
		}
	}
	else
	{
		cout<<"Index out of bound"<<endl;
	}
}


void list::addInTheStart(int val)
{
	curr = lst + size;
	if (curr == lst)
	{
		*curr = val;
		size += 1;
	}
	else if (size < length)
	{
		while(curr != lst)
		{
			curr--;
			*(curr+1) = *curr;
		}
		*curr = val;
		size += 1;
	}
	else
	{
		cout<<"Index out of bound"<<endl;
	}
}


void list::search(int val)
{
	
	curr = lst;
	while(curr != lst + size)
	{
		if (*curr == val)
		{
			cout<<val<<" is in list "<<endl;
			return;
		}
		curr++;
	}
	cout<<val<<" is not in list"<<endl;
}



void list::deleteByValue(int val)
{
	curr = lst;
	while(curr != lst + size)
	{
		if (*curr == val)
		{
			while(curr != lst + size)
			{
				*curr = *(curr+1);
				curr++;
			}
			size -= 1;
			return;
		}
		curr++;
	}
	cout<<val<<" is not in list"<<endl;
}

void list::deleteByIndex(int ind)
{
	curr = lst + ind;
	while(curr != lst + size)
	{
		*(curr) = *(curr + 1); 
		curr++;
	}
	size -= 1;
	return;
}



int* list::getCurrent()
{
	return curr;
}





int list::lengthOf()
{
	return length;
}




int list::sizeOf()
{
	return size;
}




void list::update(int val)
{
	*curr = val;
}




void list::next()
{
	curr++;
	if (curr == lst + length)
	{
		cout<<"Index out of bound"<<endl;
		curr--;
		return;
	}
	else{
		return;
	}
	
}




void list::back()
{
	curr--;
	if (curr == lst)
	{
		cout<<"Index out of bound"<<endl;
		curr++;
		return;
	}
	else{
		return;
	}
	
}




void list::start()
{
	curr = lst;
}

void list::end()
{
	curr = lst + size;
}

void list::show()
{
	cout<<"[";
	curr = lst;
	while(curr != lst + size)
	{
		cout<<*curr;
		if (curr != lst+(size-1))
		{
			cout<<",";
		}
		curr++;
	}
	curr = NULL;
	cout<<"]"<<endl;
	cout<<length-size<<" place empty"<<endl;
}





int main()
{
	list l(5);
	l.addInTheEnd(1);
	l.addInTheEnd(12);
	l.addInTheStart(2);
	l.addAtPosition(2,4);
	l.addInTheEnd(7);
	l.addInTheStart(5);
	l.search(2);
	l.show();
	l.deleteByValue(4);
	l.addInTheEnd(88);
	l.addAtPosition(4,9);
	l.show();
	return 0;
}