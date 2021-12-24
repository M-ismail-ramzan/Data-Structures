#include <iostream>
#include "practice.h"
#include <math.h>
using namespace std;

struct circular_linked_list_node
{
    // A routing_Table_in_each_machine
    // Routing_table_linked_list route_table;
    int data;
    // a pointer to point on the next Machine
    circular_linked_list_node *next;
};

class circular_linked_list
{
    // Pointers are made for the circular linked list.
    circular_linked_list_node *head = NULL;
    circular_linked_list_node *last = NULL;

public:
    void *insert_when_empty(int new_data)
    {
        // allocate memory for node
        circular_linked_list_node *temp = new circular_linked_list_node();

        // Adding the data
        temp->data = new_data;
        // Now Fix the Pointer..
        last = temp;
        last->next = last;
        
    }

    void insert_At_end(int new_Data)
    {
        // if list is empty then add the node by calling insertInEmpty
        if (last == NULL)
        {
            insert_when_empty(new_Data);
            return;
        }

        // else create a new node
        circular_linked_list_node *temp = new circular_linked_list_node();

        // Assign the data to the new Node...
        temp->data = new_Data;
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }

    void insert_after(int replaced_data, int new_data)
    {
        // return null if list is empty
        if (last == NULL)
        {
            insert_when_empty(new_data);
            return;
        }

        circular_linked_list_node *temp, *p;
        // pOintes to the first element
        p = last->next;
        do
        {
            // travser until u find the data
            if (p->data == replaced_data)
            {
                temp = new circular_linked_list_node;
                temp->data = new_data;
                temp->next = p->next;
                p->next = temp;

                if (p == last)
                    last = temp;
            }
            else
            {
                p = p->next;
            }

        } while (p != last->next);

        if (p == last->next)
        {
         cout << "The node with data " << replaced_data << " is not present in the list." << endl;
        }
    }

    // traverse the circular linked list
    void traverseList()
    {
        struct circular_linked_list_node *p;

        // If list is empty, return.
        if (last == NULL)
        {
            cout << "Circular linked List is empty." << endl;
            return;
        }
        p = last->next; // Point to the first Node in the list.

        // Traverse the list starting from first node until first node is visited again

        do
        {
            cout << p->data << "==>";
            p = p->next;
        } while (p != last->next);
        if (p == last->next)
            cout << p->data;
        cout << "\n\n";
    }

    void display_cricular_linked_list()
    {
        circular_linked_list_node *temp = head;
        while (temp != last)
        {
            cout << "\n Data is: " << temp->data << " ";
            temp = temp->next;
        }
    }

    void insert_at_start(int new_Data)
    {
        // return null if list is empty
        if (last == NULL)
        {
            insert_when_empty(new_Data);
            return;
        }

        // else create a new node
        struct circular_linked_list_node *temp = new circular_linked_list_node;

        // set new data to node
        temp->data = new_Data;
        temp->next = last->next;
        last->next = temp;
    }
};

int main()
{
    // Ask User the Number of Bits he wants to Store...
    int number_of_machine = 0;
    cout << "\n Please Specify the Number of Bits u want to Store:";
    cin >> number_of_machine;

    int max_range_of_machine = pow(2, (number_of_machine));
    cout << "\n Number of Machines Possible: " << max_range_of_machine << "\n";
    // Now i need to ask User the Number the Machine...
    number_of_machine = 9999;
    while (true)
    {
        if (number_of_machine <= max_range_of_machine)
        {
            break;
        }
        else
        {
            cout << "\n Please specify the Number of Machines that You want to make: ";
            cin >> number_of_machine;
            if (number_of_machine > max_range_of_machine)
            {
                cout << "\n You Cannot Create So Much Machines... \n";
                cout << "Machine Range     [  1  to " << max_range_of_machine << " ]";
            }
        }
    }


    // Now Ask weather User want to assign Them Id's Themselves or Not!!
    cout << "\n-----------------------------------------------\n";
    cout << "\n Number of Machones: " << max_range_of_machine << "\n";
    cout << "\n Id's From Range 0 to " << max_range_of_machine - 1 << "\n";
    cout << "\n-----------------------------------------------\n";
    cout << "\n Do you want to Assign Id ";
    cout << "\n1) Manually ";
    cout << "\n2) Automatically ";
    cout << "\nEnter: ";
    int choice =0 ;
    cin >> choice;
    circular_linked_list Machines;
    switch (choice)
    {
    case 1:
        cout << "\n User wants to assign the id's Manually\n";
        // Now Here we Runs the Loop And take Id's From User and create a linked List.
        // EACH NODE ( Machine ) will have a id variable to store it's Id.
        for (int i = 0; i < number_of_machine; i++)
        {
            int machine_id=0;
            // Get the machine id and Create a node with that Particular Id
            cout << "\n Please Enter the Id of the Machine \n Enter:  ";
            cin >> machine_id;
            Machines.insert_At_end(machine_id);
            cout << " Machine with " << machine_id << " is Generated Successfully\n";
        }
        

        break;
    case 2:
        cout << "\n User wants to assign the id's Automatically";
        break;
    default:
        cout << "\n Invalid Input.\n";
        break;
    }
    
    // Now i have to create a Linked List of Nodes Equal to Number of Machine which is in the number_of_machine variable
    circular_linked_list obj;
    
    //obj.insert_At_end(5);
    //obj.insert_At_end(6);
    //obj.insert_at_start(7);
    //obj.insert_at_start(9);
    //obj.insert_after(5, 99);
    Machines.traverseList();

    return 0;
}
