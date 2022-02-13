#include <iostream>
using namespace std;

class Node
{
public:
    char name;
    Node *next;
};

class List
{
public:
    //head node
    Node *head;

    // constructor
    List()
    {
        head = NULL;
    }
    // Append function
    void Append(char patient_name)
    {
        Node *curr;
        curr = head;
        if (curr == NULL)
        {
            curr = new Node;
            curr->name = patient_name;
            curr->next = NULL;
            head = curr;
        }
        else
        {
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = new Node;
            curr->next->name = patient_name;
            curr->next->next = NULL;
        }
    }
    // Now insert at middle
    void InsertNode(int index, char x)
    {
        // checking if index is invalid
        if (index < 0)
        {
            cout << "\n Invalid Index \n";
            return;
        }
        //
        int currIndex = 1;
        Node *currNode = head;
        while (currNode && index > currIndex)
        {
            currNode = currNode->next;
            currIndex++;
        }

        if (index > 0 && currNode == NULL)
        {
            cout << "\n Invalid Index \n";
        }

        Node *newNode = new Node;
        newNode->name = x;
        // checking if there is no idex in the start
        if (index == 0)
        {
            newNode->next = head;
            head = newNode;
        }

        else
        {
            newNode->next = currNode->next;
            currNode->next = newNode;
        }
    }
    // clearing the node
    void clear()
    {
        
         Node *currNode = head, *nextNode = NULL;
        while (currNode != NULL)
        {
            nextNode = currNode->next;

            // destroy the current node
            delete currNode;

            currNode = nextNode;
        }
        head = NULL;
    }
    // removing a node
    void DeleteNode(char x)
    {

        Node *prevNode = NULL;
        Node *currNode = head;

        // checking & finding that particular index
        while (currNode && currNode->name != x)
        {
            prevNode = currNode;
            currNode = currNode->next;
        }
        // finding the index that needs to be deleted
        if (currNode != NULL)
        {
            if (prevNode != NULL)
            {
                // deleteing the node
                prevNode->next = currNode->next;
                delete currNode;
            }
            else
            {
                head = currNode->next;
                delete currNode;
            }
        }
    }
    // replacing a node
    void replace(char old, char new_name)
    {
        Node *curr = head;
        // tesing until it finds the index
        while (curr != NULL)
        {
            if (curr->name == old)
            {
                curr->name = new_name;
            }
            curr = curr->next;
        }
    }

    // Checking if the list is empty
    bool isEmpty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }

    // split
    Node *split_appointments(int index)
    {

        int currIndex = 1;
        Node *currNode = head;
        while (currNode && index > currIndex)
        {
            currNode = currNode->next;
            currIndex++;
        }

        Node *new_node = currNode->next;
        currNode->next = NULL;
        return new_node;
    }
    // display the list
    void display_list()
    {
        cout << "\n********************************\n";
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->name << " ";
            current = current->next;
        }
         cout << "\n********************************\n";
    }

    ~List()
    {
        Node *currNode = head, *nextNode = NULL;
        while (currNode != NULL)
        {
            nextNode = currNode->next;

            // destroy the current node
            delete currNode;

            currNode = nextNode;
        }
    }
};

int main()
{
    List a;
    cout << "\nPatiend A,B and D walks \n";
    a.Append('A');
    a.Append('B');
    a.Append('D');
    a.display_list();
    cout << "\nPatient E walks in emergency \n";
    a.InsertNode(1, 'E');
     a.display_list();
    cout << "\nPatiend D went out\n";
    a.DeleteNode('D');
     a.display_list();
    cout << "\nReplace\n";
    a.replace('B', 'F');
     a.display_list();
    cout << "\n Displaying To Doctor \n";
    a.display_list();
    cout << "\nSpliting the Array";
    List b;
    b.head = a.split_appointments(1);
     a.display_list();
    b.display_list();
    cout << "\n Clearing the list ";
    a.clear();
    cout << "\n Checking if emptyt \n";
    bool ans = a.isEmpty();
    cout << ans;
}