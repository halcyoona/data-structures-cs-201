#include <iostream>
using namespace std;

class list
{
	private:
		int *lst;
		int curr;
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
		int getCurrent();
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
	curr = 0;
	size = 0;
}

list::~list()
{
	delete lst;
}


void list::addInTheEnd(int val)
{
	curr = size;
	if (curr == 0)
	{
		lst[curr] = val;
		size += 1;
	}
	else if (curr < length)
	{
		lst[curr] = val;
		size += 1;
	}
	else
	{
		cout<<"Index out of bound"<<endl;
	}
}


void list::addAtPosition(int ind, int val)
{
	curr = size;
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
			for (int i = curr; i > 0 ; i--)
			{
				lst[i+1] = lst[i];
				if(ind == i)
				{
					lst[i] = val;
					size += 1;
					return;
				}
			}
		}
	}
	else
	{
		cout<<"Index out of bound"<<endl;
	}
}


void list::addInTheStart(int val)
{
	curr = size;
	if (curr == 0)
	{
		lst[curr] = val;
		size += 1;
	}
	else if (curr < length)
	{
		for (int i = curr-1; i >= 0; i--)
		{
			lst[i+1] = lst[i];
		}
		lst[0] = val;
		size += 1;
	}
	else
	{
		cout<<"Index out of bound"<<endl;
	}
}


void list::search(int val)
{
	for (int i = 0; i < size; i++)
	{
		if(lst[i] == val)
		{
			cout<<val<<" is at index "<<i<<endl;
			return;
		} 
	}
	cout<<val<<" is not in list"<<endl;
}



void list::deleteByValue(int val)
{
	for (int i = 0; i < size; i++)
	{
		if(lst[i] == val)
		{
			for (int j = i; j < size; j++)
			{
				lst[j] = lst[j+1];
			}
			size -= 1;
			return;
		} 
	}
	cout<<val<<" is not in list"<<endl;
}

void list::deleteByIndex(int ind)
{
	for (int i = ind; i < size; i++)
	{
		lst[i] = lst[i+1];
	}
	size -= 1;
	return;
}



int list::getCurrent()
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
	lst[curr] = val;
}




void list::next()
{
	curr += 1;
	if (curr == length)
	{
		cout<<"Index out of bound"<<endl;
		curr -= 1;
		return;
	}
	else{
		return;
	}
	
}




void list::back()
{
	curr -= 1;
	if (curr == 0)
	{
		cout<<"Index out of bound"<<endl;
		curr += 1;
		return;
	}
	else{
		return;
	}
	
}




void list::start()
{
	curr = 0;
}

void list::end()
{
	curr = size;
}

void list::show()
{
	cout<<"[";
	for (int i = 0; i < size; i++)
	{
		cout<<lst[i];
		if (i != size-1)
		{
			cout<<",";
		}
	}
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
	l.search(2);
	l.show();
	l.deleteByValue(4);
	l.show();
	return 0;
}