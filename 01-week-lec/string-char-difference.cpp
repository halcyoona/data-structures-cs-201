#include <iostream>
#include <string>
using namespace std;

void funSimple()
{
	// char charchar[5];
	char charstring[5];
	// for (int i = 0; i < 5; i++)
	// {
	// 	cout<<"Enter a character : ";
	// 	cin>>charchar[i]; 
	// }
	cout<<"Enter a string : ";
	cin>>charstring;     // string always have a null character 

	// for (int i = 0; i < 5; i++)
	// {
	// 	cout<<charchar[i]<<endl;
	// }
	// for (int i = 0; i < 9; i++)
	// {
	// 	cout<<charstring[i]<<endl;
	// }
	cout<<charstring<<endl;
}

// void funPointer()
// {
// 	char *charPointer;
// 	char *stringPointer;
// 	charPointer = new char[5];
// 	stringPointer = new char[5];

// 	for (int i = 0; i < 5; i++)
// 	{
// 		cout<<"Enter a character : ";
// 		cin>>charPointer[i]; 
// 	}
// 	cout<<"Enter a string : ";
// 	cin>>stringPointer;

// 	for (int i = 0; i < 5; i++)
// 	{
// 		cout<<charPointer[i]<<endl;
// 	}
// 	cout<<stringPointer<<endl;
// }

int main()
{
	funSimple();
	return 0;
}