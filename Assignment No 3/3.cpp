#include <iostream>
#include <queue>
using namespace std;
// Node of the Tree
struct Tree_Node
{
    int data;
    Tree_Node *left;
    Tree_Node *right;
};
// making the tree calss
class Tree
{

public:
     Tree_Node* root;
    Tree()
    {
        root = NULL;
    }
     // making a binary tree.
    void insert(int new_Data)
    {
        // creating the node of the Data
        Tree_Node* newNode = new Tree_Node;
        newNode->data = new_Data;
        newNode->right = newNode->left = NULL;
        // checking if there is no node
        if (root == NULL)
        {
            // if the Root is null then make it the root node
            root = newNode;
        }
        else
        {
            // If root is taken then insert it into the empty space by trasversing level by level
            queue<Tree_Node*> main_queue;
            main_queue.push(root);
            // Run until the queue is empty
            while (main_queue.size() > 0)
            {
                // get the front element. Pop it
                Tree_Node* data = main_queue.front();
                main_queue.pop();
                // if there is any Null left node in the tree
                if (data->left == NULL)
                {
                    data->left = newNode;
                    break;
                }
                // if there is any Null right node in the tree
                else if (data->right == NULL)
                {
                    data->right = newNode;
                    break;
                }
                else
                {
                    // if there is any  no left node AND right Node wich is null in the tree then add them to the queue
                    main_queue.push(data->left);
                    main_queue.push(data->right);
                }
            }
        }
    }
    // a simple function that returns the highest number
    int Max_depth(int a, int x)
    {
        if (a > x)
        {
            return a;
        }
        else
            return x;
    }
    int Height_node(Tree_Node *root)
    {
        // Base Case
        if (root == NULL)
        {
            return 0; // as there are nodes which we are counting.
        }
        // give me height of of left and right subtrees
        int left_height = Height_node(root->left);
        int right_height = Height_node(root->right);
        // after getting the height. compare which of them is longer then add 1 of the root
        return (Max_depth(left_height, right_height) + 1);
    }
    // A function which returns the Height of the tree..
    
    

    // A function to diplay in order
    void display_inorder(Tree_Node *ptr)
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

    int check_balance_node(Tree_Node *root)
    {
        if(root == NULL)
        return 1; // One because of Nodes
        /* Get the height of left and right sub trees */
        int lh = Height_node(root->left);
        int rh = Height_node(root->right);
        // find the gap between the nodes
        int gap = abs(lh-rh);
        // if gap is not between -1 and 1 then tree is not balance
        if(gap > 1 || gap < -1){return false;}
        // go check the left tree and the right treee. if they are balance then the whole tree is balanced
        bool left_subtree_balance = check_balance_node(root->left);
        bool right_subtree_balance = check_balance_node(root->right);

        // if both are balance then the tree is balnce

        return  (left_subtree_balance && right_subtree_balance);
    }
    bool check_balance(Tree *tree)
    {
       int x = check_balance_node(tree->root);
       return x;
    }
};

int main()
{
      const int SIZE = 15;
    int arr[SIZE] = { 1, 3, 4, 6, 7, 8,9,9,9,9,9,9,9,9,9 };
    Tree tree;
    for (size_t i = 0; i < SIZE; i++)
    {
        // sending the array element one by one
        tree.insert(arr[i]);
    }
    cout << "[+] Tress Inorder View [+]";
    tree.display_inorder(tree.root);
    cout << "\n Checking Weather the Tree is balanced or Not \n";
    cout << tree.check_balance(&tree);
    return 0;
}