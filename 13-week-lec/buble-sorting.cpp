#include<iostream>
using namespace std;


class bubble
{
	private:
		int *arr;
		int size;
	public:
		bubble(int *a, int s);
		// ~bubble();
		void bubbleSorting();
		void show();
};

bubble::bubble(int *a, int s)
{
	arr = a;
	size = s;
}

// bubble::~bubble()
// {
// 	delete arr;
// 	arr = NULL;
// }

void bubble:: bubbleSorting()
{
	for (int i = 0; i < size-1; i++)
	{
		for (int j = size-1 ;  j > i; j--)
		{
			if (arr[j] < arr[j-1])
			{
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}
}


void bubble:: show()
{
	for (int i = 0; i < 6; i++)
	{
		cout<<arr[i]<<endl;
	}	
}

int main()
{
	int a[6] = {2,5,1,9,7,94};
	bubble obj(a,6);
	obj.bubbleSorting();
	obj.show();
	return 0;
}