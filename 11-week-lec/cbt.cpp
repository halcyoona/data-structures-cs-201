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
		
		int localHeight;
		int countNode;
		Node *searchTemp;
		Node *delTemp;
	public:
		int height;
		Node *root;
		int number;
		int flag;
		cbt();
		~cbt();
		void delAll(Node *temp);
		void inOrder(Node *temp);
		void insert(Node *temp);
		int power(int height, int n);
		void del(Node *temp);
		void search(Node *temp);
		void lowerBubble(Node *temp);
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

cbt::~cbt()
{
	// delAll(root);

}

void cbt::delAll(Node *temp)
{
	if (temp == NULL)
	{
		return;
	}
	if (temp->left!=NULL)
		delAll(temp->left);
	if (temp->right!=NULL)
		delAll(temp->right);
	delete temp;
}

void cbt::inOrder(Node *temp)
{
	if (temp==NULL)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}
	if (temp->left != NULL)
		inOrder(temp->left);
	cout<<temp->data<<" ";
	if (temp->right != NULL)
		inOrder(temp->right);
	return;
}





void cbt::insert(Node *temp)
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

	if (((power(2,height+1))-1) == countNode) 
	{
		// cout<<"2"<<endl;
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
		// cout<<"3"<<endl;
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
		// cout<<"4"<<endl;
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







int cbt::power(int num, int n)
{
	int result = 1;
	for (int i = 0; i < n; i++)
	{
		result = result * num;
	}
	return result;
}



void cbt::del(Node *temp)
{
	if (temp == root)
	{
		flag = 0;
		delTemp = NULL;
	}

	if (root == NULL)
	{
		// cout<<"1"<<endl;
		cout<<"tree is empty"<<endl;
		return;
	}
	if (temp->data == number && temp->left == NULL && temp->right == NULL && temp->data==root->data)
	{
		
		delete temp;
		root = temp = NULL;
		countNode -= 1;
		return;
	}
	if (temp->data == number && temp->left != NULL  && root == temp && temp->left->left == NULL)
	{
		// cout<<"1"<<endl;
		Node *temp2 = root;
		root = root->left;
		root->right= temp2->right;
		delete temp2;
		return;
	}
	

	if ((power(2,height)) == countNode) 
	{
		// cout<<"2"<<endl;
		while(temp->left->left != NULL)
			temp = temp->left;
		search(root);
		searchTemp->data = temp->left->data;
		delete temp->left;
		temp->left = NULL;
		height -= 1;
		countNode -=1;
		flag = 1;
		return;
	}

	if (((power(2,height+1))-1) == countNode)	
	{
		// cout<<"3"<<endl;
		while(temp->right->right != NULL)
			temp = temp->right;
		search(root);
		// cout<<"search: "<<searchTemp->data<<endl;
		searchTemp->data = temp->right->data;
		// cout<<"search: "<<searchTemp->data<<endl;
		delete temp->right;
		temp->right = NULL;
		countNode -=1;
		flag = 1;
		return;
	}

	if (height-localHeight == 1)
	{
		// cout<<"4"<<endl;
		if (temp->left != NULL && temp->right != NULL)
		{
			delTemp = temp;
		}
		if (temp->left != NULL && temp->right == NULL)
		{
			search(root);
			searchTemp->data = temp->left->data;
			delete temp->left;
			temp->left = NULL;
			countNode -=1;
			flag = 1;
			return;

		}
	}

	if (temp->left != NULL && flag == 0)
	{	
		// cout<<"5"<<endl;
		localHeight += 1;
		del(temp->left);
		localHeight -= 1;
	}

	if (temp->right != NULL && flag == 0)
	{
		// cout<<"6"<<endl;
		localHeight += 1;
		del(temp->right);
		localHeight -= 1;
	}
	if (temp == root)
	{
		if (delTemp != NULL)
		{
			searchTemp->data = delTemp->right->data;
			delete delTemp->right;
			delTemp->right = NULL;
		}
	}
	
	return;
}


void cbt::search(Node *temp)
{
	if (temp->data == number)
	{
		lowerBubble(temp);
		return;
	}
	if (temp->left != NULL)
		search(temp->left);
	if (temp->right != NULL)
		search(temp->right);
}

void cbt:: lowerBubble(Node *temp)
{
	if (temp->left == NULL)
	{
		searchTemp = temp;
		return;
	}
	if (temp->left != NULL)
	{
		temp->data = temp->left->data;
		lowerBubble(temp->left);
	}
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
	// obj.inOrder(obj.root);
	// cout<<endl;
	obj.number = 7;
	obj.insert(obj.root);
	obj.number = 6;
	obj.insert(obj.root);
	obj.number = 71;
	obj.insert(obj.root);
	// obj.number = 62;
	// obj.insert(obj.root);
	// obj.number = 9;
	// obj.insert(obj.root);
	obj.number = 11;
	obj.insert(obj.root);
	// obj.number = 25;
	// obj.insert(obj.root);
	// obj.number = 36;
	// obj.insert(obj.root);
	// obj.number = 57;
	// obj.insert(obj.root);
	obj.inOrder(obj.root);
	cout<<endl;
	// cout<<obj.height<<endl;
	obj.number = 4;
	obj.del(obj.root);
	// obj.insert(obj.root=NULL);
	// obj.number = 4;
	// obj.insert(obj.root);
	obj.inOrder(obj.root);
	cout<<endl;
	obj.number = 2;
	obj.del(obj.root);
	obj.number = 77;
	obj.insert(obj.root);
	obj.inOrder(obj.root);
	cout<<endl;
	return 0;
}