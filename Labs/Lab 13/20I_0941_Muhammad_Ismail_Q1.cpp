//--------------------------//



#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    // Each Node will have it's Height and It's Balance factor!!!
    int height;
    int balance_factor;
};

class Avl
{
    Node *root;

public:
    // Constructor
    Avl()
    {
        root = NULL;
    }

    // First of all we need to Update the Height and the Balance of each node when they are inserted into the Avl tree
    void update_height_and_balance_factor(Node *Inserted_Node)
    {

        // This function is going up after the inseration

        // this is basically visting the returning path of the tree
        int left_node_height = -1;
        int right_node_height = -1;
        // if there is left node then ask for it's left height
        if (Inserted_Node->left != NULL)
        {
            left_node_height = Inserted_Node->left->height;
        }

        // if there is Right node then ask for it's left height
        if (Inserted_Node->right != NULL)
        {
            right_node_height = Inserted_Node->right->height;
        }

        //  NOW after getting the Heights.. i want to calculate the height and the balance factor of this node and above..

        Inserted_Node->balance_factor = left_node_height - right_node_height;
        if (left_node_height > right_node_height)
        {
            Inserted_Node->height = left_node_height + 1;
        }
        else
        {
            Inserted_Node->height = right_node_height + 1;
        }
    }
    // Performing the right Rotation

    Node *perform_right_rotation(Node *new_node)
    {
        Node *temp = new_node->left;
        Node *temp2 = temp->right;

        temp->right = new_node;
        new_node->left = temp2;

        update_height_and_balance_factor(temp);
        update_height_and_balance_factor(temp2);

        return temp;
    }

    // Performing the left Rotation

    Node *perform_left_rotation(Node *new_node)
    {
        Node *temp = new_node->right;
        Node *temp2 = temp->left;

        temp->left = new_node;
        new_node->right = temp2;

        update_height_and_balance_factor(temp);
        update_height_and_balance_factor(temp2);

        return temp;
    }
    // Apply the Rotations...

    Node *Update_and_apply_rotations(Node *new_node)
    {
        // update the height and the balance factor of the tree..
        update_height_and_balance_factor(new_node);

        if (new_node->balance_factor == 2)
        { // it means ll or lr

            if (new_node->balance_factor == 1)
            {
                // it means if this is ll then do the right totation..
                Node *new_Root = perform_right_rotation(new_node);
                return new_Root;
            }
            else
            {
                new_node->left = perform_left_rotation(new_node->left);
                Node *new_Root = perform_right_rotation(new_node);
                return new_Root;
            }
        }
        else
        { // ir means rr, rl

            // if it is rr then do the right rotation
            if (new_node->balance_factor == -1)
            { // rr
                Node *new_Root = perform_left_rotation(new_node);
                return new_Root;
            }
            else
            { // rl
                new_node->right = perform_right_rotation(new_node->right);
                Node *new_Root = perform_left_rotation(new_node);
                return new_Root;
            }
        }
    }

    // This is the function to insert into the function
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            // create a node and insert
            Node *new_Node = new Node;
            new_Node->data = data;
            return new_Node;
        }

        if (data > root->data)
        {
            root->right = insert(root->right, data);
        }
        else
        {
            root->left = insert(root->right, data);
        }

        Update_and_apply_rotations(root);
        return root;
    }

    // display
    void display(Node *node)
    {
        if (node == NULL)
        {
            return;
        }

        if (node->left != NULL)
        {
            cout << " " << node->left->data << " ::: ";
        }
        cout << " <-- " << node->data << "  --> ";
        if (node->right != NULL)
        {
            cout << " " << node->right->data << " ::: ";
        }

        // Pre order
        display(node->left);
        display(node->right);
    }
};

int main()
{
    // Insert an node into the tree
    int arr[7] = {10,20,30,40,50,60,70};
    Node *rooty=NULL;
    Avl treee;
    for (int i = 0; i < 6; i++)
    {
        /* code */
        rooty = treee.insert(rooty,arr[i]);
    }
    

}