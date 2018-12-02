#include<iostream>
using namespace std;



struct Node
{
	int data;
	int lCh;
	int rCh;
	Node *left, *right;
};


class tbt
{
	private:
		Node *temp;
	public:
		Node *root;
		Node *dummy;
		int number;
		int flag;
		tbt();
		~tbt();
		

		void fastInOrder(Node *temp);
		Node* nextInOrder(Node *temp);
		

		void insert(Node *temp);
		void delAll(Node *temp);
};


tbt::tbt()
{
	flag = 0;
}

tbt::~tbt()
{
	delAll(root);
}

void tbt::delAll(Node *temp)
{
	if (temp->lCh != 0)
		delAll(temp->left);
	if (temp->rCh != 0)
		delAll(temp->right);
	if (temp == root)
	{
		root->rCh == 0;
		root->lCh == 0;
		root->left = dummy;
		root->right = dummy;
	}
	else
		delete temp;
}


void tbt:: fastInOrder(Node *temp)
{

	while((temp=nextInOrder(temp)) != dummy)
	{
		cout<<temp->data<<" ";
	}
	cout<<endl;
}


Node* tbt:: nextInOrder(Node *temp)
{
	if (temp->rCh == 0)
	{
		return temp->right;
	}
	else
	{
		temp= temp->right;
		while(temp->lCh == 1)
			temp = temp->left;
		return temp;
	}
}






void tbt::insert(Node *temp)
{
	
	if (flag == 0)
	{
		dummy = new Node;
		temp = new Node;
		temp->data = number;
		temp->right = dummy;
		temp->left = dummy;
		root = temp;
		root->lCh = 0;
		root->rCh = 0;
		flag = 1;
		dummy->left = root;
		dummy->right = dummy;
		dummy->lCh = 1;
		dummy->rCh = 1;

		return;
	}
	if (temp->data == number)
	{
		cout<<"given number already in  tree"<<endl;
		return;
	}
	if (temp->data > number)
	{
		if (temp->lCh != 0)
		{
			insert(temp->left);
		}
		else
		{
			Node *temp2 = new Node;
			temp2->data = number;
			temp->lCh = 1;
			if (temp == root)
			{
				temp2->right = temp;
				temp2->left = dummy;
				temp2->rCh = 0;
				temp2->lCh = 0;
				temp->left = temp2;
			}
			else
			{
				temp2->left = temp->left;
				temp2->right = temp;
				temp2->rCh = 0;
				temp2->lCh = 0;
				temp->left = temp2; 
			}
			return;
		}
	}
	if (temp->data < number)
	{
		if (temp->rCh != 0)
		{
			insert(temp->right);
		}
		else
		{
			Node *temp2 = new Node;
			temp2->data = number;
			temp->rCh = 1;
			if (temp == root)
			{
				temp2->right = dummy;
				temp2->left = temp;
				temp2->rCh = 0;
				temp2->lCh = 0;
				temp->right = temp2;
			}
			else
			{
				temp2->left = temp;
				temp2->right = temp->right;
				temp2->rCh = 0;
				temp2->lCh = 0;
				temp->right = temp2;
			}
			return;
		}
	}

}






void bst:: delCaseOne(Node *temp)
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
	}
	if (number > temp->data)
	{
		delete temp->right;
		temp->right = NULL;
		return;
	}
}




void bst:: delCaseTwoA(Node *temp)
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


void bst:: delCaseTwoB(Node *temp)
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



void bst::delCaseThree(Node *temp)
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
				return;
			}
			if (temp2->left != NULL)
			{
				temp3->right = temp2->left;
				temp->left->data = temp2->data;
				delete temp2;
				temp2 = NULL;
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
				return;
			}
			if (temp->right != NULL)
			{
				temp3->left = temp2->right;
				temp->right->data = temp2->data;
				delete temp2;
				temp3->left = NULL;
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
			return;
		}
	}
}






void bst::del(Node *temp)
{
	if (root == NULL)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}
	if (temp->data == number && temp == root)
	{
		if (temp->left == NULL && temp->right == NULL)
		{
			delCaseOne(temp);
			return;
		}

		if (temp->left != NULL && temp->right == NULL)
		{
			delCaseTwoA(temp);
			return;
		}
		if (temp->left == NULL && temp->right != NULL)
		{
			delCaseTwoB(temp);
			return;
		}
		if (temp->left != NULL && temp->right != NULL)
		{
			delCaseThree(temp);
			return;
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
					delCaseOne(temp);
					return;
				}

				if (temp->left->left != NULL && temp->left->right == NULL)
				{
					delCaseTwoA(temp);
					return;
				}
				if (temp->left->left == NULL && temp->left->right != NULL)
				{
					delCaseTwoB(temp);
					return;
				}
				if (temp->left->left != NULL && temp->left->right != NULL)
				{
					delCaseThree(temp);
					return;
				}

			}
			del(temp->left);
			return;
		}
	}
	if (number > temp->data)
	{
		if (temp->right != NULL)
		{	
			if (temp->right->data == number)
			{
				if (temp->right->right == NULL && temp->right->left == NULL)
				{
					cout<<"Good"<<endl;
					delCaseOne(temp);
					return;
				}

				if (temp->right->left != NULL && temp->right->right == NULL)
				{
					delCaseTwoA(temp);
					return;
				}
				if (temp->right->left == NULL && temp->right->right != NULL)
				{
					delCaseTwoB(temp);
					return;
				}
				if (temp->right->left != NULL && temp->right->right != NULL)
				{
					delCaseThree(temp);
					return;
				}

			}
			del(temp->right);
			return;
		}
	}
}






int main()
{

	tbt obj;
	obj.number = 70;
	obj.insert(obj.root);
	obj.number = 150;
	obj.insert(obj.root);
	obj.number = 22;
	obj.insert(obj.root);
	obj.number = 10;
	obj.insert(obj.root);
	obj.number = 30;
	obj.insert(obj.root);
	obj.number = 12;
	obj.insert(obj.root);
	obj.number = 40;
	obj.insert(obj.root);
	obj.number = 7;
	obj.insert(obj.root);
	// obj.number = 3;
	// obj.insert(obj.root);
	// obj.number = 8;
	// obj.insert(obj.root);
	obj.fastInOrder(obj.dummy);
	// obj.number = 14;
	// obj.insert(obj.root);
	// obj.pre_ord(obj.root);
	// cout<<endl;
	// obj.in_ord(obj.root);
	// cout<<endl;
	// obj.post_ord(obj.root);
	// cout<<endl;
	// obj.number = 40;
	// obj.del(obj.root);
	// cout<<endl;
	// obj.in_ord(obj.root);
	// cout<<endl;
	// obj.number = 70;
	// obj.del(obj.root);
	// obj.in_ord(obj.root);
	// cout<<endl;
	// obj.number = 20;
	// obj.insert(obj.root);
	// obj.in_ord(obj.root);
	// cout<<endl;
	return 0;
}