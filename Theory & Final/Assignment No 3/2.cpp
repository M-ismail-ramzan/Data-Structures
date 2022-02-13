#include <iostream>
#include <queue>
using namespace std;

// A tree Node for the Trees
struct Tree_Node
{
    int data;
    Tree_Node *left;
    Tree_Node *right;
};
// A Linked list Node for the linked lists
struct List_Node
{
    int data;
    List_Node *next;
};

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

    // A function to diplay in order
    void display_inorder(Tree_Node *ptr)
    {
        // left -- root-- right
        // Node* temp = root;
        if (ptr != NULL)
        {
            display_inorder(ptr->left);
            cout << "\n " << ptr->data << " ";
            display_inorder(ptr->right);
        }
    }
};
// a simple list class
class List
{
public:
    List_Node *head;
    List()
    {
        head = NULL;
    }
    // A function to display the content of the list
    void display()
    {
        List_Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

// A function to create the linked list at each depth
int create_linked_depth(Tree *tree)
{
    // I have to travser the tree level wise.
    int depth = 0;
    queue<Tree_Node *> center_queue;
    center_queue.push(tree->root);
    // while the queue is not empty.
    int j = 0;
    while (center_queue.size() > 0)
    {
        // run until the queue is full
        int count = center_queue.size();
        List *ptr = new List;
        depth++;
        List_Node *previous_ptr = NULL;
        // A list has been created and this loop runs for each breath
        for (int i = 0; i < count; i++)
        {

            Tree_Node *newNode = center_queue.front();
            // making a linked List
            List_Node *myNode = new List_Node;
            if (newNode != NULL)
            {
                // put the data into the node
                myNode->data = newNode->data;
                myNode->next = NULL;
            }
            // now fix the pointers
            if (previous_ptr != NULL)
                previous_ptr->next = myNode;
            // add the first element of node as head
            if (i == 0)
                ptr->head = myNode;
            // cout << newNode->data << "   ";
            center_queue.pop();
            // making previous pointer pointing to previous node
            previous_ptr = myNode;
            // if there is left child then push it
            if (newNode->left)
            {
                center_queue.push(newNode->left);
            }
            // if there is right child then Push it
            if (newNode->right)
            {
                center_queue.push(newNode->right);
            }
        }

        // looking at each linked list
        cout << "Linkded List No " << j << " : ";
        // a function is called to displa the linked list
        ptr->display();
        cout << "\n";
        j++;
    }
    return depth;
}
int main()
{
    // cout << 050;
    const int SIZE = 9;
    int arr[SIZE] = {1, 3, 4, 6, 7, 8, 10, 13, 14};
    Tree tree;
    for (size_t i = 0; i < SIZE; i++)
    {
        // sending the array element one by one
        tree.insert(arr[i]);
    }
    cout << "[+] Tress Inorder View [+]";
    tree.display_inorder(tree.root);
    cout << "\n------------------------\n";
    int depth = create_linked_depth(&tree);
    cout << "Depth is: " << depth;
}