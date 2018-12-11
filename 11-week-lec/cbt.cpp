#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *left,*right;
};



class cbt
{
	private:
		Node *temp;
		int height;
		int localHeight;
		int countNode;
	public:
		Node *root;
		int number;
		int flag;
		cbt();
		// ~cbt();
		// void delAll(Node *temp);
		void inOrder(Node *temp);
		void insert(Node *temp);
		int power(int height, int n);
};


cbt::cbt()
{
	root=temp=NULL;
	height = 0;
	localHeight = 0;
	countNode = 0;
	flag = 0;
	number=0;
}

// cbt::~cbt()
// {
// 	delAll(root);
// }

// void cbt::delAll(Node *temp)
// {
// 	if (temp->left!=NULL)
// 		delAll(temp->left);
// 	if (temp->right!=NULL)
// 		delAll(temp->left);
// 	delete temp;
// }

void cbt::inOrder(Node *temp)
{
	if (temp->left != NULL)
		inOrder(temp->left);
	cout<<temp->data<<" ";
	if (temp->right != NULL)
		inOrder(temp->right);
	return;
}





void cbt::insert(Node *temp)
{



	if (root == NULL)
	{
		cout<<"1"<<endl;
		temp=new Node;
		temp->data = number;
		temp->left=NULL;
		temp->right=NULL;
		root=temp;
		height = 0;
		countNode += 1;
		return;
	}

	if (((power(2,height+1))-1) == countNode) 
	{
		cout<<"2"<<endl;
		while(temp->left != NULL)
			temp = temp->left;
		Node *temp2 = new Node;
		temp2->data = number;
		temp2->left = NULL;
		temp2->right = NULL;
		temp->left = temp2;
		countNode += 1;
		height += 1;
		// flag = 1;
		return;
	}

	if (height-localHeight == 1 && temp->left != NULL && temp->right == NULL)
	{
		cout<<"3"<<endl;
		Node *temp2 = new Node;
		temp2->data = number;
		temp2->right = NULL;
		temp2->left = NULL;
		temp->right = temp2;
		countNode += 1;
		flag = 1;
		return;
	}

	if (height-localHeight == 1 && temp->left == NULL && temp->right == NULL)
	{
		cout<<"4"<<endl;
		Node *temp2 = new Node;
		temp2->data = number;
		temp2->right = NULL;
		temp2->left = NULL;
		temp->left = temp2;
		countNode += 1;
		flag = 1;
		return;
	}

	if (temp->left != NULL && flag == 0)
	{	
		cout<<"5"<<endl;
		localHeight += 1;
		insert(temp->left);
		localHeight -= 1;
	}

	if (temp->right != NULL && flag == 0)
	{
		cout<<"6"<<endl;
		localHeight += 1;
		insert(temp->right);
		localHeight -= 1;
	}
	if (temp == root)
	{
		flag = 0;
	}
	return;
}


int cbt::power(int num, int n)
{
	int result = 1;
	for (int i = 0; i < n; i++)
	{
		result = result * num;
	}
	return result;
}

int main()
{

	
	cbt obj;
	obj.number = 2;
	obj.insert(obj.root);
	obj.number = 3;
	obj.insert(obj.root);
	obj.number = 4;
	obj.insert(obj.root);
	obj.inOrder(obj.root);
	obj.flag = 0;
	cout<<endl;
	obj.number = 7;
	obj.insert(obj.root);
	obj.flag = 0;
	obj.number = 6;
	obj.insert(obj.root);
	obj.flag = 0;
	obj.number = 71;
	obj.insert(obj.root);
	obj.flag = 0;
	obj.number = 62;
	obj.insert(obj.root);
	obj.flag = 0;
	obj.number = 9;
	obj.insert(obj.root);
	obj.flag = 0;
	obj.number = 11;
	obj.insert(obj.root);
	obj.flag = 0;
	obj.number = 25;
	obj.insert(obj.root);
	obj.flag = 0;
	obj.number = 36;
	obj.insert(obj.root);
	obj.flag = 0;
	obj.number = 57;
	obj.insert(obj.root);
	obj.flag = 0;
	obj.inOrder(obj.root);
	cout<<endl;
	return 0;
}