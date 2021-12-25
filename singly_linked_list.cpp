#include <iostream>
#include <math.h>
#include <time.h>
#include "./routing_table.h"
using namespace std;

struct circular_linked_list_node
{
    // A routing_Table_in_each_machine
    Routing_table_linked_list route_table;
    int machine_id;
    // a pointer to point on the next Machine
    circular_linked_list_node* next;
};

class circular_linked_list
{
    // Pointers are made for the circular linked list.
    circular_linked_list_node* head = NULL;
    circular_linked_list_node* last = NULL;

public:
    void insert_when_empty(int new_machine_id)
    {
        // allocate memory for node
        circular_linked_list_node* temp = new circular_linked_list_node();

        // Adding the machine_id
        temp->machine_id = new_machine_id;
        // Now Fix the Pointer..
        last = temp;
        last->next = last;
        head = last;

    }

    // A function that Makes sure that the data is entered in ascending Order always
    void insert_ascending_order(int new_machine_id) {

        // if list is empty then add the node by calling insertInEmpty
        if (last == NULL)
        {
            insert_when_empty(new_machine_id);
            return;
        }
        // Now check if the first element is greater than the new id
        if (new_machine_id <= last->next->machine_id) {
            // then we need to insert at the start
            insert_at_start(new_machine_id);
            return;
        }
        // Now let's travsere and find the Correct Position of the Inseration
        circular_linked_list_node* temp, * temp2;
        // pOintes to the first element
        temp2 = last->next;
        temp = last;
        do
        {
            // travser until u find the machine_id
            if (new_machine_id <= temp2->machine_id)
            {
                insert_after(temp->machine_id, new_machine_id);
                // if inserted then return from this function
                return;
            }
            else
            {
                // move on
                temp2 = temp2->next;
                temp = temp->next;
            }
            // run until u find the last one (means first)
        } while (temp2 != last->next);

        // Now if none of the above satisfy it means we need to insert at the last
        insert_At_end(new_machine_id);
    }

    void insert_At_end(int new_machine_id)
    {
        // if list is empty then add the node by calling insertInEmpty
        if (last == NULL)
        {
            insert_when_empty(new_machine_id);
            return;
        }

        // else create a new node
        circular_linked_list_node* temp = new circular_linked_list_node();

        // Assign the machine_id to the new Node...
        temp->machine_id = new_machine_id;
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }

    void insert_after(int replaced_machine_id, int new_machine_id)
    {
        // return null if list is empty
        if (last == NULL)
        {
            insert_when_empty(new_machine_id);
            return;
        }

        circular_linked_list_node* temp, * temp2;
        // pOintes to the first element
        temp2 = last->next;
        do
        {
            // travser until u find the machine_id
            if (temp2->machine_id == replaced_machine_id)
            {
                // create the machine
                temp = new circular_linked_list_node;
                // set the Pointers
                temp->machine_id = new_machine_id;
                temp->next = temp2->next;
                temp2->next = temp;
                // if needs to be inserted at the last.
                if (temp2 == last)
                    last = temp;
                // if inserted then return from this function
                return;
            }
            else
            {
                // move on
                temp2 = temp2->next;
            }
            // run until u find the last one (means first)
        } while (temp2 != last->next);


        cout << "The node with machine_id " << replaced_machine_id << " is not present in the list." << endl;

    }

    // traverse the circular linked list
    void display_machine_nodes()
    {
        circular_linked_list_node* temp;

        // If list is empty, return.
        if (last == NULL)
        {
            cout << "Circular linked List is empty." << endl;
            return;
        }
        temp = last->next; // Point to the first Node in the list.

        // Traverse the list starting from first node until first node is visited again

        do
        {
            cout << temp->machine_id << " --> ";
            temp = temp->next;
        } while (temp != last->next);

        if (temp == last->next)
            cout << temp->machine_id;
        cout << "\n\n";
    }

    void insert_at_start(int new_machine_id)
    {
        // return null if list is empty
        if (last == NULL)
        {
            insert_when_empty(new_machine_id);
            return;
        }

        // else create a new node
        struct circular_linked_list_node* temp = new circular_linked_list_node;

        // set new machine_id to node
        temp->machine_id = new_machine_id;
        temp->next = last->next;
        last->next = temp;
    }
    // This function Traverse Each Node in the Machine and Fill the Routing table.
    void fill_routing_table(int no_of_machines, int max_range_of_machine) {
        // First of all .. Each machine will have the max number of machine as index's of the Routing table..


        // We need to Traverse the Each Node...
        circular_linked_list_node* temp, * temp2;
        // pOintes to the first element
        temp2 = last->next;
        // This loop will run for all the machines..
        do
        {

            // For each machine i want you to run 
            for (int i = 1; i <= no_of_machines; i++)
            {
                // Here i need to Apply the Algo of Routing Table..

                // The index will always be increasing from 1 to no_of_machine
                //  The value needs to be calculated from the Formaula.
                int number_from_formula = ((temp2->machine_id) + pow(2, i - 1));
                // check if number exceeds the limit then again take it's mode
                if(number_from_formula > (max_range_of_machine)){
                    number_from_formula = number_from_formula % max_range_of_machine;
                }

                // Now i need to see which machine is responsible for handling the above Number that number will be stored in the Routing Index..
                temp = last->next;
                // We need to treat root as special...because of it's range..

                int last_machine_id = last->machine_id;
                int max_range = no_of_machines - 1;
                bool root_Test = false;
                // Now the number's between max range and last machine id' are handled by the root node.

                for (int i = last_machine_id; i <= max_range; i++)
                {
                    // now check if root handles that number
                    if (i == number_from_formula) {
                        // Now temp will be responsible for this number.
                        root_Test = true;
                        temp = last->next;
                        break;

                    }
                }


                do {
                    // if root is handling that number
                    if (root_Test) {
                        break;
                    }
                    // If number is less than the machine then. then that machine stores that number
                    if (number_from_formula <= temp->machine_id) {
                        break;
                    }
                    temp = temp->next;
                } while (temp != last->next);
                // now temp know's who is responsible for storing that number..
                int store_machine_id = temp->machine_id;
                temp2->route_table.insert_the_node_at_the_end(i, store_machine_id);
            }

            // Now we can print the doubly of the Previous Machine
            cout << "\n Routing Table for the Machine " << temp2->machine_id << " is Following \n";
            temp2->route_table.display_routing_table();
            // Move to the NExt Node
            temp2 = temp2->next;
        } while (temp2 != last->next);



    }
};

int main()
{
    // for changing time ( actually for random numbers)
    srand(time(0));
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
    cout << "\n Number of Machones: " << number_of_machine << "\n";
    cout << "\n Id's From Range 0 to " << max_range_of_machine - 1 << "\n";
    cout << "\n-----------------------------------------------\n";
    cout << "\n Do you want to Assign Id ";
    cout << "\n1) Manually ";
    cout << "\n2) Automatically ";
    cout << "\nEnter: ";
    int choice = 0;
    cin >> choice;
    circular_linked_list Machines;
    switch (choice)
    {
    case 1:
    {
        cout << "\n User wants to assign the id's Manually\n";
        // Now Here we Runs the Loop And take Id's From User and create a linked List.
        // EACH NODE ( Machine ) will have a id variable to store it's Id.
        int previous_id = 0;
        int machine_id = 0;

        for (int i = 0; i < number_of_machine; i++)
        {
            // 2 Checks's

            //  No Repeated Id should be allowed to User
            //  Must be In range..
            //  Must be in ascending Order

            // Get the machine id and Create a node with that Particular Id
            cout << "\n Please Enter the Id of the Machine \n Enter:  ";
            cin >> machine_id;

            // A check for the User that he never Enters the Id's In Decending Order
            if (previous_id >= machine_id)
            {
                cout << "\n You have Not Entered In ascending. SO Arranging Machings....\n ";
            }
            previous_id = machine_id;
            Machines.insert_ascending_order(machine_id);
            cout << " Machine with " << machine_id << " is Generated Successfully\n";
        }
    }
    break;

    case 2:
        for (int i = 0; i < number_of_machine; i++)
        {
            // 2 Checks's
            int random = rand() % (max_range_of_machine - 1);
            //  No Repeated Id should be allowed to User
            //  Must be In range..
            //  Must be in ascending Order
            Machines.insert_ascending_order(random);
            cout << " Machine with ID " << random << " is Generated Successfully\n";
        }
        break;
    default:
        cout << "\n Invalid Input.\n";
        break;
    }
    // Until this Point all the Machines has been made and the id's has been assigned to them.
    // Now it's time for us to fill the Routing Table for each of the machine

    Machines.fill_routing_table(number_of_machine,max_range_of_machine);


    // Display me the Final Linked List....
    cout << "\n";
    Machines.display_machine_nodes();

    return 0;
}
