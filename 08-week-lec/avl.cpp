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
		int flag;
		int singleRotationFlag;
		avl();
		~avl();
		void delAll(Node *temp);

		void updateHeight(Node *temp);
		void updatingFlag(Node *temp);
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

		void simpleDelCaseOne(Node *temp);
		void simpleDelCaseTwoA(Node *temp);
		void simpleDelCaseTwoB(Node *temp);
		void simpleDelCaseThree(Node *temp);

		void delCaseThreeAdditionalLeft(Node *temp);
		void delCaseThreeAdditionalRight(Node *temp);
		
		void in_ord_info(Node *temp);
		void in_ord(Node *temp);
		void post_ord(Node *temp);
		void pre_ord(Node *temp);

		void insert(Node *temp);
		void del(Node *temp);
};


avl::avl()
{
	temp = root = NULL;
	flag = 0;
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
	temp->right->left = temp2; 
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
			// cout<<"case -2-1"<<endl;
			insertCaseOneLeft(temp);
			fullDownUpdation(temp->left);
			return;
		}

		if (temp->left->right->balanceFactor == 1)
		{
			// cout<<"case -21"<<endl;
			insertCaseFourLeft(temp);
			fullDownUpdation(temp->left);
			return;
		}
	}

	if (temp->left->balanceFactor == 2)
	{
		
		if (temp->left->left->balanceFactor == -1)
		{
			// cout<<"case 2-1"<<endl;
			insertCaseThreeLeft(temp);
			fullDownUpdation(temp->left);
			return;
		}

		if (temp->left->left->balanceFactor == 1)
		{	
			// cout<<"case 21"<<endl;
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


/////////////////////////////////////////////////////////////////////////////////////



void avl:: delCaseThreeAdditionalLeft(Node *temp)
{
	if (temp->right == NULL)
	{
		updateHeight(temp);
		return;
	}
	if (temp->right != NULL)
	{
		delCaseThreeAdditionalLeft(temp->right);
		updatingFlag(temp);
		if (flag == 1)
		{
			solvingBFR(temp);
		}
	}
}


void avl:: delCaseThreeAdditionalRight(Node *temp)
{
	if (temp->right == NULL)
	{
		updateHeight(temp);
		return;
	}
	if (temp->right != NULL)
	{
		delCaseThreeAdditionalRight(temp->left);
		updatingFlag(temp);
		if (flag == 1)
		{
			solvingBFL(temp);
		}
	}
}



void avl:: simpleDelCaseOne(Node *temp)
{
	if (temp->data == number && temp == root)
	{
		delete temp;
		root = temp = NULL;
		return;
	}
	if (number < temp->data)
	{
		delete temp->left;
		temp->left = NULL;
		return;
	}
	if (number > temp->data)
	{
		delete temp->right;
		temp->right = NULL;
		return;
	}
}





void avl:: simpleDelCaseTwoA(Node *temp)
{

	if (temp->data == number && temp == root)
	{
		root = temp->left;
		Node *temp2 = temp;
		delete temp2;
		temp = root;
		return;
	}
	if (number < temp->data)
	{
		Node *temp2 = temp->left;
		temp->left = temp->left->left;
		delete temp2;
		temp2 = NULL;
		return;	
	}
	if (number > temp->data)
	{
		Node *temp2 = temp->right;
		temp->right = temp->right->left;
		delete temp2;
		temp2 = NULL;
		return;	
	}
}


void avl:: simpleDelCaseTwoB(Node *temp)
{
	
	if (temp->data == number && temp == root)
	{
		root = temp->right;
		Node *temp2 = temp;
		delete temp2;
		temp = root;
		return;
	}
	if (number < temp->data)
	{
		Node *temp2 = temp->left;
		temp->left = temp->left->right;
		delete temp2;
		temp2 = NULL;
		return;
	}
	if (number > temp->data)
	{
		Node *temp2 = temp->right;
		temp->right = temp->right->right;
		delete temp2;
		temp2 = NULL;
		return;
	}
}





void avl::simpleDelCaseThree(Node *temp)
{
	if (temp->data == number && temp == root)
	{
		Node *temp2 = temp;
		if (temp->left->right != NULL)
		{
			Node *temp3 = temp;
			temp3 = temp3->left;
			temp2 = temp2->left->right;
			while(temp2->right != NULL)
			{
				temp3 = temp2;
				temp2 = temp2->right;
			}
			if (temp2->left == NULL)
			{
				temp->data = temp2->data;
				delete temp2;
				temp3->right = NULL;
				return;
			}
			if (temp2->left != NULL)
			{
				temp3->right = temp2->left;
				temp->data = temp2->data;
				delete temp2;
				return; 
			}
			
		}
		else
		{
			temp2 = temp->left;
			temp->left = temp2->left;
			temp->data = temp2->data;
			delete temp2;
			temp2 = NULL;
			return;
		}
	}

	if (number < temp->data)
	{
		Node *temp2 = temp;
		if (temp->left->left->right != NULL)
		{
			Node *temp3 = temp;
			temp3 = temp3->left->left;
			temp2 = temp2->left->left->right;
			while(temp2->right != NULL)
			{
				temp3 = temp2;
				temp2 = temp2->right;
			}
			if (temp2->left == NULL)
			{
				temp->left->data = temp2->data;
				delete temp2;
				temp3->right = NULL;
				delCaseThreeAdditionalLeft(temp->left->left);
				if (flag == 1)
				{
					solvingBFL(temp->left);
				}
				return;
			}
			if (temp2->left != NULL)
			{
				temp3->right = temp2->left;
				temp->left->data = temp2->data;
				delete temp2;
				temp2 = NULL;
				delCaseThreeAdditionalLeft(temp->left->left);
				if (flag == 1)
				{
					solvingBFL(temp->left);
				}
				return; 
			}
			
		}
		else
		{
			temp2 = temp->left;
			temp->left = temp2->left;
			temp->left->right = temp2->right;
			delete temp2;
			temp2 = NULL;
			updatingFlag(temp->left);
			fullDownUpdation(temp->left);
			if (flag == 1)
			{
				solvingBFL(temp);
			}
			return;
		}
	}

	if (number > temp->data)
	{
		Node *temp2 = temp;
		if (temp->right->right->left != NULL)
		{
			Node *temp3 = temp;
			temp3 = temp3->right->right;
			temp2 = temp2->right->right->left;
			while(temp2->left != NULL)
			{
				temp3 = temp2;
				temp2 = temp2->left;
			}
			if (temp2->right == NULL)
			{
				temp->right->data = temp2->data;
				delete temp2;
				temp3->left = NULL;
				delCaseThreeAdditionalRight(temp->right->right);
				if (flag == 1)
				{
					solvingBFR(temp->right);
				}
				return;
			}
			if (temp->right != NULL)
			{
				temp3->left = temp2->right;
				temp->right->data = temp2->data;
				delete temp2;
				temp3->left = NULL;
				delCaseThreeAdditionalRight(temp->right->right);
				if (flag == 1)
				{
					solvingBFR(temp->right);
				}
				return; 
			}
			
		}
		else
		{
			temp2 = temp->right;
			temp->right = temp2->right;
			temp->right->left = temp2->left;
			delete temp2;
			temp2 = NULL;
			updatingFlag(temp->right);
			fullDownUpdation(temp->right);
			if (flag == 1)
			{
				solvingBFR(temp->right);
			}
			return;
		}
	}
}



/////////////////////////////////////////////////////////////////////////////////////////////







/////////////////////////////////////////////////////////////////////////////////////////////
// updating flag 

void avl:: updatingFlag(Node *temp)
{
	if (temp->balanceFactor == 0)
	{
		fullDownUpdation(temp);
		return;
	}
	else
	{
		fullDownUpdation(temp);
		flag = 1;
		return;
	}	
}



//////////////////////////////////////////////////////////////////////////////////////////////



void avl::del(Node *temp)
{
	if (root == NULL)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}
	if (temp->data == number)
	{
		if (temp->left == NULL && temp->right == NULL)
		{
			simpleDelCaseOne(temp);	
		}
		if (temp->left != NULL && temp->right == NULL)
		{
			simpleDelCaseTwoA(temp);
		}
		if (temp->left == NULL && temp->right != NULL)
		{
			simpleDelCaseTwoB(temp);
		}
		if (temp->left != NULL && temp->right != NULL)
		{
			simpleDelCaseThree(temp);
		}

	}
	if (number < temp->data)
	{
		if (temp->left != NULL)
		{	
			if (temp->left->data == number)
			{
				if (temp->left->left == NULL && temp->left->right == NULL)
				{
					simpleDelCaseOne(temp);
					updatingFlag(temp);
					return;		
				}
				if (temp->left->left != NULL && temp->left->right == NULL)
				{
					simpleDelCaseTwoA(temp);
					updatingFlag(temp);
					return;	
				}
				if (temp->left->left == NULL && temp->left->right != NULL)
				{
					simpleDelCaseTwoB(temp);	
					updatingFlag(temp);
					return;
				}
				if (temp->left->left != NULL && temp->left->right != NULL)
				{
					simpleDelCaseThree(temp);
					if (flag == 1)
					{
						fullDownUpdation(temp);
						solvingBFL(temp);
					}
					return;
				}
			}
			del(temp->left);
			if (flag == 1)
			{
				solvingBFL(temp);
				if (temp == root)
				{
					fullDownUpdation(temp);
					solvingBFRoot(temp);
				}
			}
			return;
		}
	}
	if (number > temp->data)
	{
		if (temp->right != NULL)
		{	
			if (temp->right->data == number)
			{
				if (temp->right->left == NULL && temp->right->right == NULL)
				{
					simpleDelCaseOne(temp);
					updatingFlag(temp);
					return;		
				}
				if (temp->right->left != NULL && temp->right->right == NULL)
				{
					simpleDelCaseTwoA(temp);
					updatingFlag(temp);
					return;		
				}
				if (temp->right->left == NULL && temp->right->right != NULL)
				{
					simpleDelCaseTwoB(temp);
					updatingFlag(temp);
					return;		
				}
				if (temp->right->left != NULL && temp->right->right != NULL)
				{
					simpleDelCaseThree(temp);
					if (flag == 1)
					{
						fullDownUpdation(temp);
						solvingBFR(temp);
					}
					return;
				}

			}
			del(temp->right);
			if (flag == 1)
			{
				solvingBFR(temp);
				if (temp == root)
				{
					fullDownUpdation(temp);
					solvingBFRoot(temp);
				}
			}
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
	obj.in_ord_info(obj.root);
	obj.in_ord(obj.root);
	cout<<endl;
	obj.number = 95;
	obj.insert(obj.root);
	obj.number = 97;
	obj.insert(obj.root);
	obj.number = 15;
	obj.del(obj.root);
	// obj.insert(obj.root);
	obj.number = 3;
	obj.insert(obj.root);
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