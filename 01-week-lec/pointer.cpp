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


    cout<<"-------CHAR------ "<<endl;

	char *charPointer;
	char charValue;
	cout<<"Enter a character: ";
	cin>>charValue;
	charPointer = &charValue;

	cout<<charPointer<<endl;
	cout<<*charPointer<<endl;
	cout<<&charPointer<<endl;
	cout<<*&charPointer<<endl;
	cout<<&*charPointer<<endl;
	cout<<charValue<<endl;
	cout<<&charValue<<endl;
	// cout<<&*charValue<<endl; can not be done because it is not a pointer
	cout<<*&charValue<<endl;
}


int main()
{
	simplePointer();
	return 0;
}