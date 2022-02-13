#include <iostream>
#include <queue>
#include <stack>
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
    Tree_Node *root;
    Tree()
    {
        root = NULL;
    }
    // making a binary tree.
    void insert(int new_Data)
    {
        // creating the node of the Data
        Tree_Node *newNode = new Tree_Node;
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
            queue<Tree_Node *> main_queue;
            main_queue.push(root);
            // Run until the queue is empty
            while (main_queue.size() > 0)
            {
                // get the front element. Pop it
                Tree_Node *data = main_queue.front();
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

    // A function to diplay in order
    void display_preorder(Tree_Node *ptr)
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
    int check_balance_node(Tree_Node *root)
    {
        if (root == NULL)
            return 1; // One because of Nodes
        /* Get the height of left and right sub trees */
        int lh = Height_node(root->left);
        int rh = Height_node(root->right);
        // find the gap between the nodes
        int gap = abs(lh - rh);
        // if gap is not between -1 and 1 then tree is not balance
        if (gap > 1 || gap < -1)
        {
            return false;
        }

        return check_balance_node(root->left) && check_balance_node(root->right);
    }
    bool check_balance(Tree *tree)
    {
        int x = check_balance_node(tree->root);
        return x;
    }
};

// a function that checks if trees are same or not
bool check_Same_trees(Tree_Node *tree1, Tree_Node *tree2)
{
    // if both are null
    if (tree1 == NULL && tree2 == NULL)
    {
        return 1;
    }
    // check the each node one by one for each tree if they are equal
    else if (tree1 != NULL && tree2 != NULL)
    {
        if (tree1->data == tree2->data && check_Same_trees(tree1->left, tree2->left) && check_Same_trees(tree1->right, tree2->right))
        {
            return 1;
        }
    }
    // if the above conditions fail then the tree is not subtree
    return 0;
}
// a Function to check if tree is subtree of other or not
bool check_subtree(Tree_Node *tree1, Tree_Node *tree2)
{
    // if tree 2 is empty then yes it is subtree
    if (tree2 == NULL)
    {
        return 1;
    }
    // if tree1 is empty and tree2 is not empty then it is not subtre
    if (tree2 != NULL && tree1 == NULL)
    {
        return 0;
    }
    // if tree2 is not empty and nor the tree one then check if tree are same
    if (check_Same_trees(tree1, tree2))
    {
        return 1;
    }

    // bool check the left subtree
    bool left_tree = (check_subtree(tree1->left, tree2));
    bool right_tree = (check_subtree(tree1->left, tree2));
    return (left_tree || right_tree);
}

// A function to check the sum and return the number of path
int count_path = 0;
// this function will start and start counting for the sum
void find_path_sum(Tree_Node *root,int target,int sum){
    // base case
    if(root == NULL){return;}
    // if u find some data then put it into the sum
    if(root->data != NULL)
    sum = sum+root->data;
    // if sum is equal to target then incease our global count
    if(sum == target){
        count_path++;
    }
    // check for the left node and right node and so on
    find_path_sum(root->left,target,sum);
    find_path_sum(root->right,target,sum);
}
int pathSum(Tree_Node *root, int target)  
{
   // we are going to use 2 Pointers. One for the root and the other for 
   // the traversal of the whole tree to get the target sum

   if(root == NULL){return -1;}

   // starting from the root go and check if u could find the path sum
   find_path_sum(root,target,0);

   // go to left element of the root and then right afterwards
   pathSum(root->left,target);
   pathSum(root->right,target);

   return count_path;
}   
int main()
{

    const int SIZE2 = 7;
    int arr2[SIZE2] = {13, -4, 5, NULL, NULL, 4, NULL};
    Tree tree2;
    for (size_t i = 0; i < SIZE2; i++)
    {
        // sending the array element one by one
        tree2.insert(arr2[i]);
    }
    cout << "[+] Tress Preorder View [+]";
    tree2.display_preorder(tree2.root);

    // checking the number of path
    cout << "Number of Path:" << pathSum(tree2.root, 9);

    return 0;
}