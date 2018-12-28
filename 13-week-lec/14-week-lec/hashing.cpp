#include<iostream>
using namespace std;


class hashing
{
	private:
		int *arr;
		int *temp;
		int *temp2;
		// int size;
		int flag;
		int percent;
		int count;
	public:
		int size;
		hashing(int s);
		void insert(int num);
		void del(int num);
		void checking();
		int searchingPrime(int num);
		void show();
		// ~hashing();
};

hashing::hashing(int s)
{
	size = s;
	percent = s/2;
	arr = new int[size];
	temp = NULL;
	count = 0;
	flag = 0;
}

void hashing::insert(int num)
{
	int remainder = num % size;
	if (arr[remainder] == 0)
	{
		arr[remainder] = num;
		count += 1;
		if (flag == 0)
		{
			checking();
		}
		
	}
	else
	{
		while(arr[remainder] != 0)
		{
			remainder += 1;
		}
		arr[remainder] = num;
		count += 1;
		if (flag == 0)
		{
			checking();
		}
		
	}
}

void hashing::checking()
{
	if (count == percent)
	{
		flag = 1;
		temp = arr;
		int newSize = searchingPrime(size*2);
		temp2 = new int[newSize];

		int preSize = size;
		size = newSize;
		percent = size /2;
		arr = temp2;
		count = 0;
		for (int i = 0; i < preSize; i++)
		{
			if (temp[i] != 0)
			{
				insert(temp[i]);
			}
		}
		flag = 0;
	}
}

int hashing::searchingPrime(int num)
{
	
	int flag1 = 0;
	while(1)
	{
		for (int i = 2; i < (num+1)/2; i++)
		{
			if (num % i == 0)
			{	
				flag1 = 1;
				break;
			}
		}
		if (flag1 == 1)
		{	
			num += 1;
			flag1 = 0;
		}
		else
			return num;
	}
}


void hashing::show()
{
	for (int i = 0; i < size; i++)
	{
		cout<<arr[i]<<endl;
	}
}

int main()
{
	hashing obj(5);
	obj.insert(13);
	obj.insert(24);
	obj.insert(23);
	obj.insert(34);
	obj.insert(50);
	obj.show();
	return 0;
}