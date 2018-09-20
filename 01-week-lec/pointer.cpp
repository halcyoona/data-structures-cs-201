#include <iostream>
#include <string>
using namespace std;

void simplePointer(){
	// int *integerPointer = new int;
	// int integerValue = 0;
	
	// cout<<"Enter a Integer: ";
	// cin>>*integerPointer;
	
	// integerValue = *integerPointer;


	// cout<<integerPointer<<endl;
	// cout<<*integerPointer<<endl;
	// cout<<&integerPointer<<endl;
	// cout<<&*integerPointer<<endl;
	// cout<<*&integerPointer<<endl;
	// cout<<integerValue<<endl;
	// cout<<&integerValue<<endl;
	// // cout<<&*integerValue<<endl; can not be done because it is not a pointer  
	// cout<<*&integerValue<<endl;

	float *floatPointer = new float;
	float floatValue = 0;
	
	cout<<"Enter a float: ";
	cin>>*floatPointer;
	
	floatValue = *floatPointer;


	cout<<floatPointer<<endl;
	cout<<*floatPointer<<endl;
	cout<<&floatPointer<<endl;
	cout<<&*floatPointer<<endl;
	cout<<*&floatPointer<<endl;
	cout<<floatValue<<endl;
	cout<<&floatValue<<endl;
	// cout<<&*integerValue<<endl; can not be done because it is not a pointer  
	cout<<*&floatValue<<endl;





 //    cout<<"-------CHAR------ "<<endl;

	// char *charPointer;
	// char charValue;
	// cout<<"Enter a character: ";
	// cin>>charValue;
	// charPointer = &charValue;

	// cout<<charPointer<<endl;
	// cout<<*charPointer<<endl;
	// cout<<&charPointer<<endl;
	// cout<<*&charPointer<<endl;
	// cout<<&*charPointer<<endl;
	// cout<<charValue<<endl;
	// cout<<&charValue<<endl;
	// // cout<<&*charValue<<endl; can not be done because it is not a pointer
	// cout<<*&charValue<<endl;

}


int main()
{
	simplePointer();
	return 0;
}