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
		void delAll(Node *temp);

		void updateHeight(Node *temp);
		void updateBalanceFactor(Node *temp);
		void fullDownUpdation(Node *temp);

		void solvingBFL(Node *temp);
		void solvingBFR(Node *temp);
		void solvingBFRoot(Node *temp);

		void insertCaseOneLeft(Node *temp);
		void insertCaseTwoLeft(Node *temp);
		void insertCaseThreeLeft(Node *temp);
		void insertCaseFourLeft(Node *temp);
		
		void insertCaseOneRight(Node *temp);
		void insertCaseTwoRight(Node *temp);
		void insertCaseThreeRight(Node *temp);
		void insertCaseFourRight(Node *temp);


		void insertCaseOneRoot(Node *temp);
		void insertCaseTwoRoot(Node *temp);
		void insertCaseThreeRoot(Node *temp);
		void insertCaseFourRoot(Node *temp);
		
		void in_ord_info(Node *temp);
		void in_ord(Node *temp);
		void post_ord(Node *temp);
		void pre_ord(Node *temp);

		void insert(Node *temp);
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



////////////////////////////////////////////////////////////////////////////
// traverse

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



void avl:: post_ord(Node *temp)
{
	if (temp == NULL)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}
	if (temp->left != NULL)
	{
		post_ord(temp->left);
	}
	if (temp->right != NULL)
	{
		post_ord(temp->right);
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
		pre_ord(temp->left);
	}
	if (temp->right != NULL)
	{
		pre_ord(temp->right);
	}
	
}
/////////////////////////////////////////////////////////






///////////////////////////////////////////////////////
// cases Left


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
/////////////////////////////////////////////////////////////////////////////






////////////////////////////////////////////////////////////////////////////
// case Right

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
///////////////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////////////
// case root

void avl::insertCaseOneRoot(Node *temp)
{
	// case -2 -1
	root = temp->right;
	temp->right = root->left;
	root->left = temp; 
}

void avl::insertCaseTwoRoot(Node *temp)
{
	// case 2 1
	root = temp->left;
	temp->left = root->right;
	root->right = temp;
}


void avl::insertCaseThreeRoot(Node *temp)
{
	// case 2 -1

	Node *temp2 = temp->left;
	temp->left = temp2->right;
	temp2->right = temp->left->left;
	temp->left->left = temp2;
	insertCaseTwoRoot(temp);
}


void avl:: insertCaseFourRoot(Node *temp)
{
	// case -2 1
	Node *temp2 = temp->right;
	temp->right = temp2->left;
	temp2->left = temp->right->right;
	temp->right->right = temp2;
	insertCaseOneRoot(temp);
}
//////////////////////////////////////////////////////////////////////////////////////////////










////////////////////////////////////////////////////////////////////////////////////////
// Solving balance factor
void avl::solvingBFL(Node *temp)
{
	if (temp->left->balanceFactor == -2)
	{
		
		if (temp->left->right->balanceFactor == -1)
		{
			cout<<"case -2-1"<<endl;
			insertCaseOneLeft(temp);
			fullDownUpdation(temp->left);
			return;
		}

		if (temp->left->right->balanceFactor == 1)
		{
			cout<<"case -21"<<endl;
			insertCaseFourLeft(temp);
			fullDownUpdation(temp->left);
			return;
		}
	}

	if (temp->left->balanceFactor == 2)
	{
		
		if (temp->left->left->balanceFactor == -1)
		{
			cout<<"case 2-1"<<endl;
			insertCaseThreeLeft(temp);
			fullDownUpdation(temp->left);
			return;
		}

		if (temp->left->left->balanceFactor == 1)
		{	
			cout<<"case 21"<<endl;
			insertCaseTwoLeft(temp);
			fullDownUpdation(temp->left);
			return;
		}
	}
}


void avl::solvingBFR(Node *temp)
{
	if (temp->right->balanceFactor == -2)
	{
		
		if (temp->right->right->balanceFactor == -1)
		{
			// cout<<"case -2-1"<<endl;
			insertCaseOneRight(temp);
			fullDownUpdation(temp->right);
			return;
		}

		if (temp->right->right->balanceFactor == 1)
		{
			// cout<<"case -21"<<endl;
			insertCaseFourRight(temp);
			fullDownUpdation(temp->right);
			return;
		}
	}

	if (temp->right->balanceFactor == 2)
	{
		if (temp->right->left->balanceFactor == -1)
		{
			// cout<<"case 2-1"<<endl;
			insertCaseThreeRight(temp);
			fullDownUpdation(temp->right);
			return;
		}

		if (temp->right->left->balanceFactor == 1)
		{
			// cout<<"case 21"<<endl;
			insertCaseTwoRight(temp);
			fullDownUpdation(temp->right);
			return;
		}
	}
}

void avl::solvingBFRoot(Node *temp)
{
	if (temp->balanceFactor == -2)
	{
		
		if (temp->right->balanceFactor == -1)
		{
			// cout<<"case -2-1"<<endl;
			insertCaseOneRoot(temp);
			fullDownUpdation(temp);
			return;
		}

		if (temp->right->balanceFactor == 1)
		{
			// cout<<"case -21"<<endl;
			insertCaseFourRoot(temp);
			fullDownUpdation(temp);
			return;
		}
	}

	if (temp->balanceFactor == 2)
	{
		
		if (temp->left->balanceFactor == -1)
		{
			// cout<<"case 2-1"<<endl;
			insertCaseThreeRoot(temp);
			fullDownUpdation(temp);
			return;
		}

		if (temp->left->balanceFactor == 1)
		{
			// cout<<"case 21"<<endl;
			insertCaseTwoRoot(temp);
			fullDownUpdation(temp);
			return;
		}
	}	
}
/////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////
// Balance factor calculation and height calculation

void avl:: fullDownUpdation(Node *temp)
{
	if (temp == NULL)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}
	if (temp->left != NULL)
	{
		fullDownUpdation(temp->left);
	}
	if (temp->right != NULL)
	{
		fullDownUpdation(temp->right);
	}
	updateHeight(temp);
	updateBalanceFactor(temp);
}


void avl::updateBalanceFactor(Node *temp)
{
	temp->balanceFactor = temp->leftHeight - temp->rightHeight;
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

////////////////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////////
// insertion code

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
			solvingBFL(temp);
			fullDownUpdation(temp->left);
			
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
			solvingBFR(temp);
			fullDownUpdation(temp->right);
			
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
	if (temp == root)
	{
		solvingBFRoot(temp);
		fullDownUpdation(temp);
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
	obj.number = 77;
	obj.insert(obj.root);
	obj.number = 14;
	obj.insert(obj.root);
	obj.number = 8;
	obj.insert(obj.root);
	obj.number = 14;
	obj.insert(obj.root);
	obj.in_ord_info(obj.root);
	obj.in_ord(obj.root);
	cout<<endl;
	obj.pre_ord(obj.root);
	cout<<endl;
	obj.post_ord(obj.root);
	cout<<endl;
	return 0;
}