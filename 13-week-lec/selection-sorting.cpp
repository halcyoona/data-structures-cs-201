#include<iostream>
using namespace std;


class selection
{
	private:
		int *arr;
		int size;
	public:
		selection(int *a, int s);
		// ~selection();
		void selectionSorting();
		void show();
};

selection::selection(int *a, int s)
{
	arr = a;
	size = s;
}

// selection::~selection()
// {
// 	delete arr;
// 	arr = NULL;
// }

void selection:: selectionSorting()
{
	for (int i = 0; i < size; i++)
	{
		int temp = arr[i];
		int count = i;
		for (int j = i;  j<size; j++)
		{
			if ( temp > arr[j])
			{
				temp = arr[j];
				count = j;
			}
		}
		arr[count] = arr[i];
		arr[i] = temp;

	}
}


void selection:: show()
{
	for (int i = 0; i < 6; i++)
	{
		cout<<arr[i]<<endl;
	}	
}

int main()
{
	int a[6] = {2,5,1,9,7,94};
	selection obj(a,6);
	obj.selectionSorting();
	obj.show();
	return 0;
}