#include<iostream>
using namespace std;



struct Node
{
	int data;
	int leftHeight;
	int rightHeight;
	int balanceFactor;
	Node *left, *right;
};


class avl
{
	private:
		Node *temp;
	public:
		Node *root;
		int number;
		avl();
		~avl();
		void updateHeight(Node *temp);
		void updateBalanceFactor(Node *temp);
		void insertCaseOneLeft(Node *temp);
		void insertCaseTwoLeft(Node *temp);
		void insertCaseThreeLeft(Node *temp);
		void insertCaseFourLeft(Node *temp);
		void insertCaseOneRight(Node *temp);
		void insertCaseTwoRight(Node *temp);
		void insertCaseThreeRight(Node *temp);
		void insertCaseFourRight(Node *temp);
		void in_ord_info(Node *temp);
		void in_ord(Node *temp);
		void post_ord(Node *temp);
		void pre_ord(Node *temp);
		void insert(Node *temp);
		void delAll(Node *temp);
};


avl::avl()
{
	temp = root = NULL;
}

avl::~avl()
{
	delAll(root);
}

void avl::delAll(Node *temp)
{
	if (temp->left != NULL)
		delAll(temp->left);
	if (temp->right != NULL)
		delAll(temp->right);
	delete temp;
}


void avl:: in_ord(Node *temp)
{
	if (temp == NULL)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}
	if (temp->left != NULL)
	{
		in_ord(temp->left);
	}
	cout<<temp->data<<" ";
	if (temp->right != NULL)
	{
		in_ord(temp->right);
	}
}


void avl:: in_ord_info(Node *temp)
{
	if (temp == NULL)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}
	if (temp->left != NULL)
	{
		in_ord_info(temp->left);
	}
	cout<<"Info : "<<temp->data<<"  balanceFactor : "<<temp->balanceFactor<<" "<<"  leftHeight : "<<temp->leftHeight<<"  rightHeight : "<<temp->rightHeight<<endl;
	if (temp->right != NULL)
	{
		in_ord_info(temp->right);
	}
}


void avl:: post_ord(Node *temp)
{
	if (temp == NULL)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}
	if (temp->left != NULL)
	{
		in_ord(temp->left);
	}
	if (temp->right != NULL)
	{
		in_ord(temp->right);
	}
	cout<<temp->data<<" ";
}



void avl:: pre_ord(Node *temp)
{
	if (temp == NULL)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}
	
	cout<<temp->data<<" ";
	if (temp->left != NULL)
	{
		in_ord(temp->left);
	}
	if (temp->right != NULL)
	{
		in_ord(temp->right);
	}
	
}






void avl::updateBalanceFactor(Node *temp)
{
	temp->balanceFactor = temp->leftHeight - temp->rightHeight;
}


void avl::insertCaseOneLeft(Node *temp)
{
	// case -2 -1
	Node *temp2 = temp->left;
	temp->left = temp->left->right;
	temp2->right = temp->left->left;			
	temp->left = temp2;
}

void avl::insertCaseTwoLeft(Node *temp)
{
	// case 2 1
	Node *temp2 = temp->left;
	temp->left = temp2->left;
	temp2->left = temp->left->right;
	temp->left->right = temp2;
}


void avl::insertCaseThreeLeft(Node *temp)
{
	// case 2 -1
	Node *temp2 = temp->left->left;
	temp->left->left = temp2->right;
	temp2->right = temp->left->left->left;
	temp->left->left->left = temp2;
	insertCaseTwoLeft(temp);
}

void avl::insertCaseFourLeft(Node *temp)
{
	// case -2 1
	Node *temp2 = temp->left->right;
	temp->left->right = temp2->left;
	temp2->left = temp2->left->right->right;
	temp->left->right->right = temp2;
	insertCaseOneLeft(temp);	
}


void avl::insertCaseOneRight(Node *temp)
{
	// case -2 -1
	Node *temp2 = temp->right;
	temp->right = temp2->right;
	temp2->right = temp->right->left;
	temp2->right->left = temp2; 
}

void avl::insertCaseTwoRight(Node *temp)
{
	// case 2 1
	Node *temp2 = temp->right;
	temp->right = temp2->left;
	temp2->left = temp->right->right;
	temp->right->right = temp2;
}


void avl::insertCaseThreeRight(Node *temp)
{
	// case 2 -1

	Node *temp2 = temp->right->left;
	temp->right->left = temp2->right;
	temp2->right = temp->right->left->left;
	temp->right->left->left = temp2;
	insertCaseTwoRight(temp);
}


void avl:: insertCaseFourRight(Node *temp)
{
	// case -2 1
	Node *temp2 = temp->right->left;
	temp->right->left = temp2->right;
	temp2->right = temp->right->left->left;
	temp->right->left->left = temp2;
	insertCaseOneRight(temp);
}



void avl:: updateHeight(Node *temp)
{
	if (temp == NULL)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}
	if (temp->left != NULL)
	{
		if (temp->left->leftHeight > temp->left->rightHeight)
		{
			temp->leftHeight = 1;
			temp->leftHeight += temp->left->leftHeight;
		}
		else
		{
			temp->leftHeight = 1;
			temp->leftHeight += temp->left->rightHeight;	
		}
		
	}
	if (temp->right != NULL)
	{
		if (temp->right->leftHeight > temp->right->rightHeight)
		{
			temp->rightHeight = 1;
			temp->rightHeight += temp->right->leftHeight;
		}
		else
		{
			temp->rightHeight = 1;
			temp->rightHeight += temp->right->rightHeight;	
		}
	}
	if (temp->left == NULL)
	{
		temp->leftHeight = 0;
	}
	if (temp->right == NULL)
	{
		temp->rightHeight = 0;
	}
}



void avl::insert(Node *temp)
{
	
	if (root == NULL)
	{
		temp = new Node;
		temp->data = number;
		temp->right = NULL;
		temp->left = NULL;
		root = temp;
		updateHeight(temp);
		updateBalanceFactor(temp);
		return;
	}
	if (temp->data == number)
	{
		cout<<"given number already in  tree"<<endl;
		return;
	}

	if (temp->data > number)
	{
		if (temp->left != NULL)
		{
			insert(temp->left);
			updateHeight(temp);
			updateBalanceFactor(temp);
			if (temp->left->balanceFactor == -2)
			{
				
				if (temp->left->right->balanceFactor == -1)
				{
					cout<<"case -2-1"<<endl;
					insertCaseOneLeft(temp);
					updateHeight(temp->left);
					updateBalanceFactor(temp->left);
					return;
				}

				if (temp->left->right->balanceFactor == 1)
				{
					cout<<"case -21"<<endl;
					insertCaseFourLeft(temp);
					updateHeight(temp->left);
					updateBalanceFactor(temp->left);
					return;
				}
			}

			if (temp->left->balanceFactor == 2)
			{
				
				if (temp->left->left->balanceFactor == -1)
				{
					cout<<"case 2-1"<<endl;
					insertCaseThreeLeft(temp);
					updateHeight(temp->left);
					updateBalanceFactor(temp->left);
					return;
				}

				if (temp->left->left->balanceFactor == 1)
				{	
					cout<<"case 21"<<endl;
					insertCaseTwoLeft(temp);
					updateHeight(temp->left);
					updateBalanceFactor(temp->left);
					return;
				}
			}
			return;
			
		}
		else
		{
			Node *temp2 = new Node;
			temp2->data = number;
			temp2->right = NULL;
			temp2->left = NULL;
			temp->left = temp2;
			updateHeight(temp2);
			updateBalanceFactor(temp2);
			updateHeight(temp);
			updateBalanceFactor(temp);
			return;
		}
	}
	if (temp->data < number)
	{
		if (temp->right != NULL)
		{
			insert(temp->right);
			updateHeight(temp);
			updateBalanceFactor(temp);
			if (temp->right->balanceFactor == -2)
			{
				cout<<"case 12"<<endl;
				if (temp->right->right->balanceFactor == -1)
				{
					insertCaseOneRight(temp);

					return;
				}

				if (temp->right->right->balanceFactor == 1)
				{
					insertCaseFourRight(temp);
					return;
				}
			}

			if (temp->right->balanceFactor == 2)
			{
				cout<<"case 21"<<endl;
				if (temp->right->left->balanceFactor == -1)
				{
					insertCaseThreeRight(temp);
					return;
				}

				if (temp->right->left->balanceFactor == 1)
				{
					insertCaseTwoRight(temp);
					return;
				}
			}
			return;
		}
		else
		{
			Node *temp2 = new Node;
			temp2->data = number;
			temp2->right = NULL;
			temp2->left = NULL;
			temp->right = temp2;
			updateHeight(temp2);
			updateBalanceFactor(temp2);
			updateHeight(temp);
			updateBalanceFactor(temp);
			return;
		}
	}

}











int main()
{
	avl obj;
	obj.number = 70;
	obj.insert(obj.root);
	obj.number = 15;
	obj.insert(obj.root);
	obj.number = 82;
	obj.insert(obj.root);
	obj.number = 9;
	obj.insert(obj.root);
	obj.number = 45;
	obj.insert(obj.root);
	obj.number = 7;
	obj.insert(obj.root);
	obj.number = 3;
	obj.insert(obj.root);
	// obj.number = 77;
	// obj.insert(obj.root);
	// obj.number = 14;
	// obj.insert(obj.root);
	// obj.number = 8;
	// obj.insert(obj.root);
	// obj.number = 14;
	// obj.insert(obj.root);
	obj.in_ord_info(obj.root);
	obj.in_ord(obj.root);
	cout<<endl;
	obj.pre_ord(obj.root);
	cout<<endl;
	obj.post_ord(obj.root);
	cout<<endl;
	return 0;
}