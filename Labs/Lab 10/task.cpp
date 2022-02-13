#include <iostream>
#include <queue>
using namespace std;


struct Node {
	int data;
	Node* left;
	Node* right;
};
class BTree {
	Node* root;
public:
	// making the constructor
	BTree() {
		root = NULL;
	}
	void insert(int mydata)
	{
		// if root is equal to the NULL
		if (root == NULL) {
			Node* my_node = new Node;
			my_node->data = mydata;
			my_node->left = NULL;
			my_node->right = NULL;
			root = my_node;
		}
		else {
			// make a new Queue
			queue<Node*> myqueue;
			myqueue.push(root);
		
			while (true) {
				Node* n = myqueue.front();
				myqueue.pop();
				if (n->left != NULL) {
					// if left is Not null then push to the Queue
					myqueue.push(n->left);
				}
				else {
					// now add the data to the node
					n->left = new Node;
					n->left->data = mydata;
					n->left->left = NULL;
					n->left->right = NULL;
					
					break;

				}

				if (n->right != NULL) {
					// if right is Not null then push to the Queue
					myqueue.push(n->right);
				}
				else {
					// now add the data to the node
					n->right = new Node;
					n->right->data = mydata;
					n->right->left = NULL;
					n->right->right = NULL;
					
					break;

				}

			}



		}
	}



	bool replace(int OldDataItem, int NewDataItem) {
		// Now am going to replace the olddataitem
		if (root != NULL) {
			// CHECK THE ROOT
			if (root->data == OldDataItem) {
				root->data = NewDataItem;
				return true;
			}
			else {
				// make a new Queue
				queue<Node*> myqueue;
				myqueue.push(root);

				while (true) {
					Node* n = myqueue.front();
					myqueue.pop();


					if (n->left != NULL) {
						// if left is Not null then push to the Queue
						if (n->left->data == OldDataItem) {
							n->left->data = NewDataItem;
							return true;
						}

						myqueue.push(n->left);

					}
					else {

						return false;
					}

					if (n->right != NULL) {
						// if right is Not null then push to the Queue
						if (n->right->data == OldDataItem) {
							n->right->data = NewDataItem;
						}
						myqueue.push(n->right);
						return true;
					}
					else {
						return false;
					}
				}

			}
		}
		else {
			return false;
		}
	}

	void display() {
		// Now am going to replace the olddataitem
		if (root != NULL) {
			// CHECK THE ROOT
		
			{
				cout << root->data << "\n";
				// make a new Queue
				queue<Node*> myqueue;
				myqueue.push(root);

				while (true) {
					Node* n = myqueue.front();
					myqueue.pop();


					if (n->left != NULL) {
						// if left is Not null then push to the Queue
						cout << n->left->data << " \n";
						myqueue.push(n->left);

					}
					else {
						break;
					}


					if (n->right != NULL) {
						// if right is Not null then push to the Queue
						cout << n->right->data << " \n";
						myqueue.push(n->right);

					}
					else {
						break;
					}
				}

			}
		}
	}

};

int main() {
	int arr[7] = { 1,2,3,4,5,6,7 };
	const int Size = 7;
	BTree my_tree;
	for (int i = 0; i < Size; i++)
	{
		my_tree.insert(arr[i]);
	}
	my_tree.display();
	return 0;
}