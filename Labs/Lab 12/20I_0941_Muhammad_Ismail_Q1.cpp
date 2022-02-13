#include <iostream>
using namespace std;
// Node of the Tree
struct Node
{
    int data;
    Node *left;
    Node *right;
};
// making the tree calss
class bst
{
    

public:
Node *root;
    bst()
    {
        root = NULL;
    }
    // Insert into BST
    void insert(int mydata)
    {
        // Assigning data to the Node
        Node *newNode = new Node;
        newNode->data = mydata;
        newNode->right = newNode->left = NULL;
        // A pointer to traverse
        Node *temp = root;
        // if root is empty then insert in their
        if (root == NULL)
        {
            root = newNode;
            cout << "ok";
        }
        // if root has childs
        else
        {
            // repeat until u find a empty Node
            while (temp != NULL)
            {
                if (mydata < temp->data)
                {
                    // suppose element needs to be inserted into the left Subtree
                    if (temp->left == NULL)
                    {
                        // insert the element
                        temp->left = newNode;
                        cout << "\n Left Inserted " << mydata << "\n";
                        break;
                    }
                    // check it's child node
                    temp = temp->left;
                }
                else if (mydata > temp->data)
                {
                    // suppose element needs to be inserted into the right Subtree
                    if (temp->right == NULL)
                    {
                        // insert the node
                        temp->right = newNode;
                        cout << "\n RighT Inserted " << mydata<< "\n";
                        break;
                    }
                    // check it's child node
                    temp = temp->right;
                }
                else
                {
                    // if element is already present
                    cout << "\n Not possible";
                    break;
                }
            }
        }
        // Display Inorder
        cout << "\n Displaying Inorder \n";
        display_inorder(root);
        cout << "\n Displaying Pre Order \n";
        display_preorder(root);

        // Now, After inserting all the nodes , let's find the height
        
    }
    int Max_depth(int a, int x)
    {
        if (a > x)
        {
            return a;
        }
        else
            return x;
    }
    // A function which returns the Height of the tree..
    int Height(Node *root)
    {
        // Base Case
        if (root == NULL)
        {
            return -1; // as there are edges which we are counting.
        }
        // give me height of of left and right subtrees
        int left_height = Height(root->left);
        int right_height = Height(root->right);
        // after getting the height. compare which of them is longer then add 1 of the root
        return (Max_depth(left_height, right_height) + 1);
    }

    // A function to diplay in order
    void display_inorder(Node *ptr)
    {
        // left -- root-- right
        // Node* temp = root;
        if (ptr != NULL)
        {
            display_inorder(ptr->left);
            cout << "\n " << ptr->data << "\n";
            display_inorder(ptr->right);
        }
    }

    // A function to diplay in order
    void display_preorder(Node *ptr)
    {
        // root-- left-- right
        // Node* temp = root;
        if (ptr != NULL)
        {
            cout << "\n " << ptr->data << "\n";
            display_preorder(ptr->left);

            display_preorder(ptr->right);
        }
    }
};
int main()
{
    bst tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(2);
     tree.insert(6);
    int hei = tree.Height(tree.root);
    cout << "Height of the Tree is: " << hei << " \n ";
    return 0;
}