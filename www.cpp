#include<iostream>
using namespace std;

struct AVL_node			// AVL_Node created to traverse in AVL tree
{
	int height;			// To calculate the height factor for balancing AVL
	int id;				// Id of the corresponding value
	int value;			// The value which user entered with respect to that Id
	int line_no;		// Line no. at which this value is placed in file

	AVL_node* left_child;
	AVL_node* right_child;


	AVL_node()				// Default Constructor
	{
		id = 0;
		value = 0;
		left_child = NULL;
		right_child = NULL;

	}


};

typedef AVL_node* Position;				// to calculate the Position of any node

class AVL				// AVL Class to implement all the basics to Store ID's and Corresponding Values
{
	AVL_node* root;				// Root created
public:
	AVL()				// Default Constructor
	{
		root = NULL;
		root->left_child = NULL;
		root->right_child = NULL;

	}

	
	int Height(AVL_node* t)				// Function to calculate height of any node for balancing factor
	{
		int h = 0;
		if (t != NULL) 
		{
			int l_height = Height(t->left_child);
			int r_height = Height(t->right_child);
			int max_height = max(l_height, r_height);
			h = max_height + 1;
		}
		return h;
	}			


	int max(int inp1, int inp2)				// Function of Calculating Maximum node in the tree
	{
		return (inp1 >= inp2) ? inp1 : inp2;
	}

	

	AVL_node* SingleRotateWithLeft(AVL_node* parent)				// Function of Left Rotation
	{
		AVL_node* t;
		t = parent->left_child;
		parent->left_child = t->right_child;
		t->right_child = parent;
		cout << "Left-Left Rotation";
		return t;
	}


	AVL_node* SingleRotateWithRight(AVL_node* parent)			// Function of Right Rotation
	{
		AVL_node* t;
		t = parent->right_child;
		parent->right_child = t->left_child;
		t->left_child = parent;
		cout << "Right-Right Rotation";
		return t;
	}


	




	AVL_node* left_right(AVL_node* parent)					// Function of left Right Rotation
	{
		AVL_node* t;
		t = parent->left_child;
		parent->left_child = SingleRotateWithRight(t);
		cout << "Left-Right Rotation";
		return SingleRotateWithLeft(parent);
	}

	AVL_node* right_left(AVL_node* parent)					// Function of Right Left Rotation
	{
		AVL_node* t;
		t = parent->right_child;
		parent->right_child = SingleRotateWithLeft(t);
		cout << "Right-Left Rotation";
		return SingleRotateWithRight(parent);
	}

	AVL_node* insert(AVL_node* r, int v)					// Function of Inserting new node
	{
		if (r == NULL)
		{
			r = new AVL_node;
			r->value = v;
			r->left_child = NULL;
			r->right_child = NULL;
			return r;
		}
		else if (v < r->value)
		{
			r->left_child = insert(r->left_child, v);
			r = balance_calculate(r);
		}
		else if (v >= r->value)
		{
			r->right_child = insert(r->right_child, v);
			r = balance_calculate(r);
		}
		return r;
	}


	AVL_node* balance_calculate(AVL_node* t)
	{
		int bal_factor = difference(t);
		if (bal_factor > 1) 
		{
			if (difference(t->left_child) > 0)
				t = SingleRotateWithLeft(t);
			else
				t = left_right(t);
		}
		else if (bal_factor < -1)
		{
			if (difference(t->right_child) > 0)
				t = right_left(t);
			else
				t = SingleRotateWithRight(t);
		}
		return t;
	}

	int difference(AVL_node* t)
	{
		int l_height = Height(t->left_child);
		int r_height = Height(t->right_child);
		int b_factor = l_height - r_height;
		return b_factor;
	}


	void show(AVL_node* p, int l) 
	{
		int i;
		if (p != NULL)
		{
			show(p->right_child, l + 1);
			cout << " ";
			if (p == root)
			{
				cout << "Root : ";
			}
			for (i = 0; i < l && p != root; i++)
			{
				cout << " ";
			}
				
			cout << p->value;
			show(p->left_child, l + 1);
		}
	}

	void inorder(AVL_node* t)
	{
		if (t == NULL)
		{
			return;
		}
			
		inorder(t->left_child);
		cout << t->value << " ";
		inorder(t->right_child);
	}
	void preorder(AVL_node* t)
	{
		if (t == NULL)
		{
			return;
		}
			
		cout << t->value << " ";
		preorder(t->left_child);
		preorder(t->right_child);
	}
	void postorder(AVL_node* t) 
	{
		if (t == NULL)
		{
			return;
		}
			
		postorder(t->left_child);
		postorder(t->right_child);
		cout << t->value << " ";
	}


};



int main()
{

	AVL_node* root;
	AVL obj1;

	int c, i;
	while (1) {
		cout << "1.Insert Element into the tree" << endl;
		cout << "2.show Balanced AVL Tree" << endl;
		cout << "3.InOrder traversal" << endl;
		cout << "4.PreOrder traversal" << endl;
		cout << "5.PostOrder traversal" << endl;
		cout << "6.Exit" << endl;
		cout << "Enter your Choice: ";
		cin >> c;
		switch (c) {
		case 1:
			cout << "Enter value to be inserted: ";
			cin >> i;
			root = obj1.insert(root, i);
			break;
		case 2:
			if (root == NULL) {
				cout << "Tree is Empty" << endl;
				continue;
			}
			cout << "Balanced AVL Tree:" << endl;
			obj1.show(root, 1);
			cout << endl;
			break;
		case 3:
			cout << "Inorder Traversal:" << endl;
			obj1.inorder(root);
			cout << endl;
			break;
		case 4:
			cout << "Preorder Traversal:" << endl;
			obj1.preorder(root);
			cout << endl;
			break;
		case 5:
			cout << "Postorder Traversal:" << endl;
			obj1.postorder(root);
			cout << endl;
			break;
		case 6:
			exit(1);
			break;
		default:
			cout << "Wrong Choice" << endl;
		}
	}
	return 0;
}