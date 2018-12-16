#include <iostream>
using namespace std;


class merge
{
	private:
		int *arr;
		int tsize;
	public:
		merge(int *a, int s);
		// ~merge();
		void mergeSort(int size, int *start, int *end);
		void merging(int size, int *start1, int *start2);
		void show();
};

merge::merge(int *a, int s)
{
	arr = a;
	tsize = s;
}


void merge:: mergeSort(int size, int *start, int *end)
{
	if (size  <= 1) 
	{
		// cout<<"size "<<size<<endl;
		return;
	}
	
	// cout<<"size " <<size<<endl;
	int mid = size / 2;
	int size2 = size-mid;
	int *start1 = start;
	int *end1 = start+mid-1;
	int *start2 = start+mid;
	int *end2 = end;
	mergeSort(mid, start1, end1);
	mergeSort(size2, start2, end2);
	merging(size2, start1, start2);

}


void merge:: merging(int size1, int *st1, int *st2)
{
	int flag = 0;
	// cout<<"count "<<"good"<<endl;
	for (int j = 0; j < size1; j++)
	{
		int *start1 = st1;
		int *start2 = st2;
		for (int i = 0; i < size1; i++)
		{
			// cout<<"start1 "<<*start1<<" start2 :"<<*start2<<endl;
			if (*start2 < *start1)
			{
				int temp = *start1;
				*start1 = *start2;
				*start2 = temp;
				start1++;
				start2++;
			}
			else
			{		
				start1++;
			}
			// cout<<"start1 "<<*start1<<" start2 :"<<*start2<<endl;
		}
	}

}


void merge:: show()
{
	for (int i = 0; i < tsize; i++)
	{
		cout<<arr[i]<<endl;
	}	
}

int main()
{
	int a[12] = {2,5,1,9,24,55,67,7,99,22,100,25};	
	merge obj(a, 12);
	int *start = a;
	// cout<<"start "<<*start<<endl;
	int *end = a+11;
	// cout<<"end "<<*end<<endl;
	obj.mergeSort(12, start, end);
	obj.show();
	return 0;
}