#include <iostream>
//#include "../../Project1/Header.h"

using namespace std;
template <class mystring, class myint>
struct Node
{
    mystring name;
    myint key;
    Node* left_child;
    Node* right_child;
    Node() {
        left_child = right_child = NULL;
    }
    Node(mystring name, myint key) {
       // this->name = name;
        //this->value = value;
        //left = right = NULL;
        
        Node<string, int>* new_Node = new Node<string, int>;
        new_Node->name = name;
        new_Node->key = key;
        // pass the data to the node who called it!
        this->name = new_Node->name;
        this->key = new_Node->key;
    }

};
template <class mystring, class myint>
struct Tree {
    Node<mystring, myint>* root;
public:
    Tree() {
        root = NULL;
    }

    // inserting into the Tree
    void insert(Node<mystring, myint> newnode) {
        // the Pointer which will be used to transverse the whole tree.
        Node<mystring, myint>* nodePtr = NULL;

        // copying the data from newnode to the 
        Node<mystring, myint>* newNode = new Node<mystring, myint>
        ;
        newNode->name = newnode.name;
        newNode->key = newnode.key;
        // Create a new node

      
        // If tree is empty.
        if (!root) { root = newNode; }
        // check if the tree is not empty
        else {
            // making it the 
            nodePtr = root;

            while (nodePtr != NULL) {
                // if node need to be inserted at the left subtree..
                if (newNode->key < nodePtr->key) {
                    // go to the next until u reach the root
                    if (nodePtr->left_child)
                    {
                        nodePtr = nodePtr->left_child;
                    }
                    else {
                        nodePtr->left_child = newNode;
                        break;
                    }
                }

                else if (newNode->key > nodePtr->key) { // Right subtree

                    if (nodePtr->right_child)
                    {
                        nodePtr = nodePtr->right_child;
                    }
                    else {
                        nodePtr->right_child = newNode;
                        break;
                    }
                }
                else {
                    cout << "Insertion Not possible\n";
                    break;
                }
            }

        }

    }

    bool retrieve(int findit) {
        Node<string,int>* nodePtr = root;
        // iterate until u reaches the leaf
        while (nodePtr != NULL) {
            // checking the root
            if (nodePtr->key == findit)
                return true; 
            // check the left subtree
            else if (findit < nodePtr->key)
                nodePtr = nodePtr->left_child;
            else // if not then go to right subtree
                nodePtr = nodePtr->right_child;
        }
        // if none of the condition satisfy then false
        return false; 

    }

    void displayInOrder(Node <string, int>* nodePtr) {
        // left->root>right
       
        // if there exist the tree.
        if (nodePtr) {
            displayInOrder(nodePtr->left_child);
            cout << " Value: " << nodePtr->key << " Name: " << nodePtr->name << " ";
            displayInOrder(nodePtr->right_child);
        }
    }
    
    void displayInOrder() {
        Node<string, int>* nodePtr = root;
        displayInOrder(nodePtr);
    }



    void displayPreOrder(Node <string,int>* nodePtr) {
        // root -> left -> right
       
        // if there exist the tree.
        if (nodePtr) {
            cout << " Value: " << nodePtr->key << " Name: " << nodePtr->name << " ";
            displayPreOrder(nodePtr->left_child);
            displayPreOrder(nodePtr->right_child);
        }
    }

    void displayPreOrder(){
        Node<string, int>* nodePtr = root;
        displayPreOrder(nodePtr);
    }


    void displayPostOrder() {
        Node<string, int>* nodePtr = root;
        displayPostOrder(nodePtr);
    }

    void displayPostOrder(Node <string, int>* nodePtr) {
            // left -? right -> root
        
        // if there exist the tree.
        if (nodePtr) {

            displayPostOrder(nodePtr->left_child);
            displayPostOrder(nodePtr->right_child);
            cout << " Value: " << nodePtr->key << " Name: " << nodePtr->name << " ";
        }
    }


};