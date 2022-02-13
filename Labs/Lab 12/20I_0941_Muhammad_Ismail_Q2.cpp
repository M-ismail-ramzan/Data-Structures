#include <iostream>
using namespace std;
// Node of the Tree
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// making the tree calss
class bst
{

public:
    Node* root;
    Node* parent;
    bst()
    {
        root = NULL;
    }
    // Insert into BST
    void insert(int mydata)
    {
        // Assigning data to the Node
        Node* newNode = new Node;
        newNode->data = mydata;
        newNode->right = newNode->left = NULL;
        // A pointer to traverse
        Node* temp = root;
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
                        cout << "\n RighT Inserted " << mydata << "\n";
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
    int Height(Node* root)
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
    void display_inorder(Node* ptr)
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
    void display_preorder(Node* ptr)
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

    void delete_it(int delete_data)
    {
        // Go and find the node that needs to be deleted
        Node* delete_me = find_delete_node(root,delete_data);
        // if there is nothing
        if (delete_me == NULL)
        {
            return;
        }

        // First thing first, delete if there is no child
        if (delete_me->left == NULL && delete_me->right == NULL)
        {

            // suppose it's root
            if (delete_me == root)
            {
                return;
            }
            // handling the pointers of the parents
            if (parent->right != NULL)
            {
                parent->right = NULL;
            }
            else if (parent->left != NULL)
            {
                parent->left = NULL;
            }

            return;
        }

        // Okay! so the node to be deleted must have one child

        if (delete_me->right == NULL)
        {
            // if the node to be deleted is the root node then just replace
            if (delete_me == root)
            {
                root = root->left;
                return;
            }
            // if ther is left child then
            if (parent->left == delete_me)
                parent->left = delete_me->left;
            else
                parent->right = delete_me->left;

            return;
        }

        if (delete_me->left == NULL)
        {
            // if the node to be deleted is the root node then just replace
            if (delete_me == root)
            {
                root = root->left;
                return;
            }
            // if ther is left child then
            if (parent->right == delete_me)
                parent->right = delete_me->left;
            else
                parent->left = delete_me->left;

            return;
        }

        // Now the only case i need to handle is if there is subtree


    }
    // Find the node to be deleted and find it's parents
    Node* find_delete_node(Node *haha,int data_delete)
    {
        // This function will find that particular node that needs to be deleted
        if (data_delete > haha->data)
        {
            // Go to the right node and travserse
            parent = haha;
            haha = find_delete_node(haha->right,data_delete);
            

        }
        else if (data_delete < haha->data)
        {
            // Go to the left node and travserse
            parent = haha;
            haha = find_delete_node(haha->left,data_delete);
           
        }
        return haha;
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
    cout << "\nlol";
    // making a node to be delete
    tree.delete_it(6);
    tree.delete_it(2);

    return 0;
}