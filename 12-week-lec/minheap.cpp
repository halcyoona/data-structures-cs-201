#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *left,*right;
};



class heap
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
		heap();
		~heap();
		void delAll(Node *temp);
		void inOrder(Node *temp);
		void insert(Node *temp);
		int power(int height, int n);
};


heap::heap()
{
	root=temp=NULL;
	height = 0;
	localHeight = 0;
	countNode = 0;
	flag = 0;
	number=0;
}

heap::~heap()
{
	delAll(root);
}

void heap::delAll(Node *temp)
{
	if (temp->left!=NULL)
		delAll(temp->left);
	if (temp->right!=NULL)
		delAll(temp->right);
	delete temp;
}

void heap::inOrder(Node *temp)
{
	if (temp->left != NULL)
		inOrder(temp->left);
	cout<<temp->data<<" ";
	if (temp->right != NULL)
		inOrder(temp->right);
	return;
}





void heap::insert(Node *temp)
{
	if(temp == root)
	{
		flag = 0;
	}

	if (root == NULL)
	{
		// cout<<"1"<<endl;
		temp=new Node;
		temp->data = number;
		temp->left=NULL;
		temp->right=NULL;
		root=temp;
		height = 0;
		countNode += 1;
		return;
	}

	if (temp->data > number)
	{
		int num = number;
		number= temp->data;
		temp->data = num;
	}

	if (((power(2,height+1))-1) == countNode) 
	{
		// cout<<"2"<<endl;
		while(temp->left != NULL)
		{
			if (temp->data > number)
			{
				int num = number;
				number = temp->data;
				temp->data = num;
			}
			temp = temp->left;
		}
		Node *temp2 = new Node;
		temp2->data = number;
		temp2->left = NULL;
		temp2->right = NULL;
		temp->left = temp2;
		countNode += 1;
		height += 1;
		flag = 1;
		if (temp->data > temp->left->data)
		{
			temp->left->data = temp->data;
			temp->data = number;
		}
		return;
	}

	if (height-localHeight == 1 && temp->left != NULL && temp->right == NULL)
	{
		// cout<<"3"<<endl;
		Node *temp2 = new Node;
		temp2->data = number;
		temp2->right = NULL;
		temp2->left = NULL;
		temp->right = temp2;
		countNode += 1;
		flag = 1;
		if (temp->data > temp->right->data)
		{
			temp->right->data = temp->data;
			temp->data = number;
		}
		return;
	}

	if (height-localHeight == 1 && temp->left == NULL && temp->right == NULL)
	{
		// cout<<"4"<<endl;
		Node *temp2 = new Node;
		temp2->data = number;
		temp2->right = NULL;
		temp2->left = NULL;
		temp->left = temp2;
		countNode += 1;
		flag = 1;
		if (temp->data > temp->left->data)
		{
			temp->left->data = temp->data;
			temp->data = number;
		}
		return;
	}

	if (temp->left != NULL && flag == 0)
	{	
		// cout<<"5"<<endl;
		localHeight += 1;
		insert(temp->left);
		localHeight -= 1;
	}

	if (temp->right != NULL && flag == 0)
	{
		// cout<<"6"<<endl;
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





int heap::power(int num, int n)
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

	
	heap obj;
	obj.number = 50;
	obj.insert(obj.root);
	obj.number = 30;
	obj.insert(obj.root);
	obj.number = 42;
	obj.insert(obj.root);
	// obj.inOrder(obj.root);
	// cout<<endl;
	obj.number = 10;
	obj.insert(obj.root);
	obj.number = 67;
	obj.insert(obj.root);
	obj.number = 71;
	obj.insert(obj.root);
	obj.number = 6;
	obj.insert(obj.root);
	obj.number = 9;
	obj.insert(obj.root);
	// obj.number = 11;
	// obj.insert(obj.root);
	// obj.number = 25;
	// obj.insert(obj.root);
	// obj.number = 36;
	// obj.insert(obj.root);
	// obj.number = 57;
	// obj.insert(obj.root);
	obj.inOrder(obj.root);
	cout<<endl;
	return 0;
}