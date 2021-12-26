#include <iostream>
#include <math.h>
#include <time.h>
#include <fstream>
#include "./routing_table.h"
#include "./avl_Tree.h"

using namespace std;

struct circular_linked_list_node
{
    // avl tree fro storing the data...
    AVL avl_tree;
    AVL_node *avl_root = NULL;
    // A routing_Table_in_each_machine
    Routing_table_linked_list route_table;
    int machine_id;
    // a pointer to point on the next Machine
    circular_linked_list_node *next;
};

class circular_linked_list
{
    // Pointers are made for the circular linked list.
    circular_linked_list_node *head = NULL;
    circular_linked_list_node *last = NULL;

public:
    void insert_when_empty(int new_machine_id)
    {
        // allocate memory for node
        circular_linked_list_node *temp = new circular_linked_list_node();

        // Adding the machine_id
        temp->machine_id = new_machine_id;
        // Now Fix the Pointer..
        last = temp;
        last->next = last;
        head = last;
    }

    // A function that Makes sure that the data is entered in ascending Order always
    void insert_ascending_order(int new_machine_id)
    {

        // if list is empty then add the node by calling insertInEmpty
        if (last == NULL)
        {
            insert_when_empty(new_machine_id);
            return;
        }
        // Now check if the first element is greater than the new id
        if (new_machine_id <= last->next->machine_id)
        {
            // then we need to insert at the start
            insert_at_start(new_machine_id);
            return;
        }
        // Now let's travsere and find the Correct Position of the Inseration
        circular_linked_list_node *temp, *temp2;
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
        circular_linked_list_node *temp = new circular_linked_list_node();

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

        circular_linked_list_node *temp, *temp2;
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
        circular_linked_list_node *temp;

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
        struct circular_linked_list_node *temp = new circular_linked_list_node;

        // set new machine_id to node
        temp->machine_id = new_machine_id;
        temp->next = last->next;
        last->next = temp;
    }

    circular_linked_list_node *get_the_machine_to_be_deleted(int test_machine_id)
    {
        if (last != NULL)
        {
            circular_linked_list_node *temp;
            temp = last->next;
            do
            {

                if (test_machine_id == temp->machine_id)
                {
                    return temp;
                }
                temp = temp->next;
            } while (temp != last->next);
        }
        return NULL;
    }
    // This function check's weather the machine id is already their or not !!
    bool check_if_machine_present(int test_machine_id)
    {
        if (last != NULL)
        {
            circular_linked_list_node *temp;
            temp = last->next;
            do
            {

                if (test_machine_id == temp->machine_id)
                {
                    return true;
                }
                temp = temp->next;
            } while (temp != last->next);
        }
        return false;
    }
    // Return me head machine id
    int get_head_machine_id(){
        if(last->next != NULL)
        return last->next->machine_id;
        else 
        return NULL;
    }
    // This function looks into the doubly of each Node and check's where we need to store the data
    circular_linked_list_node *find_storage_machine(int data_id, int start_machine_id, int bit_size)
    {
        // Now we need to identify which machine we need to visit.
        // steps::::::::::::::::
        // 1) -->  Go and find the start Machine id from the Linked list..[x]
        // 2) Once Found!! Now Print it's Routing table to see  -- [x]
        //  Make a function that traverse the doubly linked list... and we pass him the index and it return's the address of that index so we can move to that machine...
        //

        circular_linked_list_node *temp;
        temp = last->next;
        do
        {
            if (start_machine_id == temp->machine_id)
            {
                // store the machine id in temp from where we need to start searching
                break;
            }
            temp = temp->next;
        } while (temp != last->next);

        // now we have the machine from where we need to start Searching..

        // Let's take a look at It's Routing table..
        cout << "\n We will start searching from machine no:  " << temp->machine_id << "\n";
        cout << "\n Routing table of this Machine is \n";
        temp->route_table.display_routing_table();

        // Now let's start Traversubg and Have Some FUN !!
        start_machine_id = temp->machine_id;

        while (true)
        {
            // call the Function from this machine and check it's routing index
            circular_linked_list_node *temp2 = temp->route_table.finding_next_machine(start_machine_id, data_id, bit_size, temp);
            if (temp2 != temp)
                cout << "\n Travelled to Machine --> " << temp2->machine_id;
            else
            {
                cout << "\nFOUND!!!!";
                break;
            }
            // First of all let's check is the Pointer right orr not ?
            start_machine_id = temp2->machine_id;
            temp = temp2;
        }

        cout << "\nThis Machine is active: --> " << temp->machine_id << "\n";
        return temp;
    }
    // This function takes in machine id and display the avl tree of the machine
    void display_me_avl_machine(int machine_id)
    {
        circular_linked_list_node *temp;
        temp = last->next;
        do
        {
            if (machine_id == temp->machine_id)
            {
                // store the machine id in temp from where we need to start searching
                break;
            }
            temp = temp->next;
        } while (temp != last->next);
        // Let's take a look at It's Routing table..
        cout << "\n AVL Tree of this Machine is \n";
        temp->avl_tree.show(temp->avl_root, 1);
    }
    // This functions takes in the machine id and display the Routing table
    void display_me_routing_table_of_temp_id(int machine_id)
    {

        circular_linked_list_node *temp;
        temp = last->next;
        do
        {
            if (machine_id == temp->machine_id)
            {
                // store the machine id in temp from where we need to start searching
                break;
            }
            temp = temp->next;
        } while (temp != last->next);
        // Let's take a look at It's Routing table..
        cout << "\n Routing table of this Machine is \n";
        temp->route_table.display_routing_table();
    }
    // This function returns the Number of Machine into the system
    int return_number_of_machine_currently()
    {
        int count = 0;
        circular_linked_list_node *temp;
        temp = last->next;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != last->next);
        return count;
    }
    // this function delete the Previous Routing Table of all the nodes..
    void delete_routes(int bit_size)
    {

        circular_linked_list_node *temp;
        temp = last->next;
        do
        {
            for (int i = 1; i <= bit_size; i++)
            {
                temp->route_table.delete_the_given_index_node(i);
            }
            temp = temp->next;
        } while (temp != last->next);
    }
    // a function that takes in the node to be deleted and delete it
    void del(circular_linked_list_node *node_to_be_deleted)
    {
        circular_linked_list_node *temp2;
        circular_linked_list_node *prev;
        temp2 = last->next;
        do
        {
            if (temp2->machine_id == node_to_be_deleted->machine_id)
            {
                break;
            }
            prev = temp2;
            temp2 = temp2->next;
        } while (temp2 != last->next);

        circular_linked_list_node *temp;
        temp = prev->next;
        prev->next = temp->next;
        delete temp;
    }
    // Assign the deleted Node values to other machines..
    void assign_avl_values_of_machine_to_other(circular_linked_list_node *temp, int bit_size)
    {

        // Now we need to delete the Node...

        fstream newfile;
        string name = to_string(temp->machine_id) + "-data.txt";
        newfile.open(name, ios::in); // open a file to perform read operation using file object
        if (newfile.is_open())
        { // checking whether the file is open
            string line;
            int count = 0;
            int data_id = 0;
            string data = "";
            while (getline(newfile, line)) // Read data from the file..
            {

                if (count == 0)
                {
                    data_id = stoi(line);
                }
                // Each avl entry has 3 values... id,value,line no;
                if (count == 2)
                {
                    data = line;
                    circular_linked_list_node *tempy = NULL;
                    tempy = this->find_storage_machine((data_id), last->next->machine_id, bit_size);
                    if (tempy != NULL)
                        tempy->avl_root = tempy->avl_tree.insert(tempy->avl_root, data_id, data);
                    // creating the file
                    this->create_temp_file(tempy->machine_id);
                    tempy->avl_tree.show_in_file(tempy->avl_root, tempy->machine_id);
                    tempy->avl_tree.show(tempy->avl_root, 1);
                    count = 0;
                }

                count++;

                cout << line << "\n"; // print the data of the string
            }
            newfile.close(); // close the file object.
        }
    }

    // This function will fix the avl trees for all the machines..
    void fix_the_avl_trees(int bit_size)
    {
        circular_linked_list_node *temp;
        temp = last->next;
        do
        {

            temp->avl_tree.deleteTree(temp->avl_root);

            //             2  -->  Go and get the data from file
            fstream newfile;
            string name = to_string(temp->machine_id) + "-data.txt";
            newfile.open(name, ios::in); // open a file to perform read operation using file object
            if (newfile.is_open())
            { // checking whether the file is open
                string line;
                int count = 0;
                int data_id = 0;
                string data = "";
                while (getline(newfile, line)) // Read data from the file..
                {

                    if (count == 0)
                    {
                        data_id = stoi(line);
                    }
                    // Each avl entry has 3 values... id,value,line no;
                    if (count == 2)
                    {
                        data = line;
                        circular_linked_list_node *tempy = NULL;
                        tempy = this->find_storage_machine((data_id), last->next->machine_id, bit_size);
                        if (tempy != NULL)
                            tempy->avl_root = tempy->avl_tree.insert(tempy->avl_root, data_id, data);
                        // creating the file
                        this->create_temp_file(tempy->machine_id);
                        tempy->avl_tree.show_in_file(tempy->avl_root, tempy->machine_id);
                        tempy->avl_tree.show(tempy->avl_root, 1);
                        count = 0;
                    }

                    count++;

                    cout << line << "\n"; // print the data of the string
                }
                newfile.close(); // close the file object.

                // Traversing the Machine..
            }
            //       3   --> Now insert that data into the machines..
            temp = temp->next;
        } while (temp != last->next);
    }
    // create the temp file
    void create_temp_file(int mac_id)
    {
        // creating the file...
        ofstream test;
        string name = to_string(mac_id) + "-data.txt";
        test.open(name, ios::out);
        if (!test)
        {
            cout << "\n Unavle to open file \n";
        }
        test.close();
    }
    // This function Traverse Each Node in the Machine and Fill the Routing table.
    void fill_routing_table(int no_of_machines, int max_range_of_machine, int bit_Size)
    {
        // First of all .. Each machine will have the max number of machine as index's of the Routing table..

        // We need to Traverse the Each Node...
        circular_linked_list_node *temp, *temp2;
        // pOintes to the first element
        temp2 = last->next;
        // This loop will run for all the machines..
        do
        {

            // For each machine i want you to run
            for (int i = 1; i <= bit_Size; i++)
            {
                // Here i need to Apply the Algo of Routing Table..

                // The index will always be increasing from 1 to no_of_machine
                //  The value needs to be calculated from the Formaula.
                int number_from_formula = ((temp2->machine_id) + pow(2, i - 1));
                // check if number exceeds the limit then again take it's mode
                if (number_from_formula > (max_range_of_machine))
                {
                    number_from_formula = number_from_formula % (max_range_of_machine + 1);
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
                    if (i == number_from_formula)
                    {
                        // Now temp will be responsible for this number.
                        root_Test = true;
                        temp = last->next;
                        break;
                    }
                }

                do
                {
                    // if root is handling that number
                    if (root_Test)
                    {
                        break;
                    }
                    // If number is less than the machine then. then that machine stores that number
                    if (number_from_formula <= temp->machine_id)
                    {
                        break;
                    }
                    temp = temp->next;
                } while (temp != last->next);
                // now temp know's who is responsible for storing that number..
                int store_machine_id = temp->machine_id;
                temp2->route_table.insert_the_node_at_the_end(i, store_machine_id, temp);
                // We need to set the Pointer as well..
                // temp2->route_table.set_the_pointer();
            }

            // Now we can print the doubly of the Previous Machine
            cout << "\n Routing Table for the Machine " << temp2->machine_id << " is Following \n";
            temp2->route_table.display_routing_table();
            // Move to the NExt Node
            temp2 = temp2->next;
        } while (temp2 != last->next);
    }
};
// this function takes in a key and return the data id out of it
int hash_function(int key, int max_range)
{
    key = key % max_range;
    return key;
}
int main()
{
    // for changing time ( actually for random numbers)
    srand(time(0));
    // Ask User the Number of Bits he wants to Store...
    int bit_size = 0;
    cout << "\n\n Please Specify the Number of Bits u want to Store:";
    cin >> bit_size;

    int max_range_of_machine = pow(2, (bit_size));
    cout << "\n Number of Machines Possible: " << max_range_of_machine << "\n";
    // Now i need to ask User the Number the Machine...
    int number_of_machine = 9999;
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

            while (true)
            {
                // cheaking weather the id is repeated or not!!!
                bool is_machine_already_present = Machines.check_if_machine_present(machine_id);
                // if machine is already present..
                if (is_machine_already_present)
                {
                    cout << "\n Machine id is already in the list.. \n Enter Again:";
                    cin >> machine_id;
                }
                else if (machine_id <= -1 || machine_id >= (max_range_of_machine - 1))
                {
                    cout << "\n You have Entered Id which is not In Range..\nEnter Again: ";
                    cin >> machine_id;
                }
                else
                {
                    break;
                }
            }

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
            //  Must be In range..
            // must not be repeating..
            while (true)
            {
                // cheaking weather the id is repeated or not!!!
                bool is_machine_already_present = Machines.check_if_machine_present(random);
                // if machine is already present..
                if (is_machine_already_present)
                {
                    random = rand() % (max_range_of_machine - 1);
                }
                else
                {
                    break;
                }
            }
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

    Machines.fill_routing_table(number_of_machine, (max_range_of_machine - 1), bit_size);

    // Display me the Final Linked List....
    cout << "\n Following are the Machines Made \n";
    Machines.display_machine_nodes();

    // Until this Point. All the machines has been made and the Routing tables are inserted as well.
    // Now we will ask the user Key,value Pair and will store them in the Avl tree and will identify that
    // which machine is responsible for storing the data..
    do
    {
        cout << "\n Please specify the Operation that You want to Perform \n";
        cout << "1) Add A Machine into the System [o]";
        cout << "\n2) Remove A Machine from the System [o]";
        cout << "\n3) Insert a Key,Value Pair into Machine [o]";
        cout << "\n4) Search for Key Into the AVL Tree (Machines) [o]";
        cout << "\n5) Delete the Key from the Machine [x] ";
        cout << "\n6) Print Routing Table of any machine Id [o] ";
        cout << "\n7) Print the Avl  tree of the Machine [o]";
        cout << "\n8) See machines id;s ";
        cout << "\n9) Exit\nEnter:";
        choice = 0;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "\n Add Machine \n";
            cout << "--- Checking Range --- ";
            cout << "\n Number of Machines Possible: " << max_range_of_machine << "\n";
            cout << "\n Id's From Range 0 to " << max_range_of_machine - 1 << "\n";
            int count = Machines.return_number_of_machine_currently();
            cout << "\n Number of machines Now into the system : " << count << "\n";
            int test = max_range_of_machine - count;
            if (test > 0)
            {
                cout << "\n There is space into the System. You can create New Machine";

                cout << "\n Id's From Range 0 to " << max_range_of_machine - 1 << "\n";
                cout << "\n Please Enter the Id of the New Machine: ";
                int mac_id = 0;
                cin >> mac_id;
                // we have to check user do not enter repeated or Already exist id..
                while (true)
                {
                    // cheaking weather the id is repeated or not!!!
                    bool is_machine_already_present = Machines.check_if_machine_present(mac_id);
                    // if machine is already present..
                    if (is_machine_already_present)
                    {
                        cout << "\n Machine id is already in the list.. \n Enter Again:";
                        cin >> mac_id;
                    }
                    else if (mac_id <= -1 || mac_id >= (max_range_of_machine - 1))
                    {
                        cout << "\n You have Entered Id which is not In Range..\nEnter Again: ";
                        cin >> mac_id;
                    }
                    else
                    {
                        break;
                    }
                }

                // Now we have tested all the things.. let's create the machine
                Machines.insert_ascending_order(mac_id);
                cout << " Machine with " << mac_id << " is Generated Successfully\n";
                number_of_machine++;
                // Display me the Final Linked List....
                cout << "\n Following are the Machines Made \n";
                Machines.display_machine_nodes();
                // First of all i need to delete the Previous One..
                Machines.delete_routes(bit_size);
                cout << "\n Updating Routing Tables \n";
                Machines.fill_routing_table(number_of_machine, (max_range_of_machine - 1), bit_size);
                // Now the Routing table has been Updated...
                // Here, we need to adjust the avl keys as well...
                /*
                1 -->  Go to Each Machine
                2 -->  Traverse the Tree. For each Node call the insert Function
                3 -->  Insert Function will find the new Positions and will save the
                       data..
                */

                cout << "\n Fixing the AVL trees of the Machines \n";
                Machines.fix_the_avl_trees(bit_size);
            }
            else
            {
                cout << "\n No space Avaliable for New Machine";
            }
        }
        break;

        case 2:
        {
            cout << "\n Remove Machine \n";
            cout << "\n Number of Machines Possible: " << max_range_of_machine << "\n";
            cout << "\n Id's From Range 0 to " << max_range_of_machine - 1 << "\n";
            int count = Machines.return_number_of_machine_currently();
            cout << "\n Number of machines Now into the system : " << count << "\n";
            if (count <= 1)
            {
                cout << "\nThere is only One Machine in the system.We cannot delete it";
            }
            else
            {
                cout << "\n Please Enter the Id of the Machine You want to delete: ";
                int mac_id = 0;
                cin >> mac_id;
                // Check if machine exist
                bool is_exist = Machines.check_if_machine_present(mac_id);
                //
                if (is_exist)
                {
                    // Find the node of the machine..
                    circular_linked_list_node *tmp;
                    AVL obj;
                    tmp = Machines.get_the_machine_to_be_deleted(mac_id);
                    // First save the avl tree in some temp of this machine
                    // Now we need to open file
                    tmp->avl_tree.deleteTree(tmp->avl_root);
                    Machines.del(tmp);
                    // First of all i need to delete the Previous One..
                    Machines.delete_routes(bit_size);
                    cout << "\n Updating Routing Tables \n";
                    Machines.fill_routing_table(number_of_machine, (max_range_of_machine - 1), bit_size);
                    Machines.assign_avl_values_of_machine_to_other(tmp, bit_size);
                    // Now obj has the tree... We need to get the data and insert it into the machine
                    // we have the data into file as well.. Let's read from there.
                }
                else
                {
                    cout << "\n This machine does not exist in the system \n";
                }
            }
        }
        break;

        case 3:
        {
            cout << "\n Insert the Value into the System \n";
            int data_id = 0;
            int start_machine_id = 0;
            cout << "\n Please Enter the key(Must be integer): ";
            cin >> data_id;
            // Now we will calculte the Hash of the key
            data_id = hash_function(data_id, max_range_of_machine);
            cout << "\n Data Id After Hashing: " << data_id << "\n";
            cout << "\n Please Enter the Value: ";
            string data = "welcome to my prgrams!!";
            cin.ignore();
            getline(cin, data);
            cout << "\n Start Search From Which Machine Number :";
            cin >> start_machine_id;

            // Now i need to use Routing Table to identify to which machine i need to look at!!!
            circular_linked_list_node *temp = NULL;
            temp = Machines.find_storage_machine(data_id, start_machine_id, bit_size);
            // Now we can store that data into the temp Node..

            temp->avl_root = temp->avl_tree.insert(temp->avl_root, data_id, data);
            // creating the file
            Machines.create_temp_file(temp->machine_id);
            temp->avl_tree.show_in_file(temp->avl_root, temp->machine_id);
            temp->avl_tree.show(temp->avl_root, 1);
        }
        break;

        case 4:
        {
            cout << "\n Search the Value from the System\n";
            // Now i need to Travel through the Routing table and find where the key is stored on the system..
            cout << "\n Please Enter the Key to Seach for \n";
            int data_id=0;
            cin >> data_id;
            data_id = hash_function(data_id,max_range_of_machine);
             circular_linked_list_node *temp = NULL;
            temp = Machines.find_storage_machine(data_id,Machines.get_head_machine_id(),bit_size);
            // Now we will Traverse the Avl tree of them Temp..
            temp->avl_tree.find_a_key(temp->avl_root,data_id);
        }
        break;
        case 6:
        {
            int temp_id = 0;
            cout << "Please Enter the Id of the Machine for: ";
            cin >> temp_id;
            // this Function display's the Routing table of any machine..
            Machines.display_me_routing_table_of_temp_id(temp_id);
            // Now we will traverse the machines to find out it's lcocation

            break;
        }
        case 7:
        {
            int temp_id = 0;
            cout << "Please Enter the Id of the Machine for ";
            cin >> temp_id;

            Machines.display_me_avl_machine(temp_id);
            break;
        }
        case 8:
        {
            Machines.display_machine_nodes();
        }
        break;
        case 9:
        {
            cout << "\n Thanks for using our system \n";
            break;
        }
        default:
            cout << "\n Invalid Input \n";
            break;
        }
    } while (!(choice == 9));

    return 0;
}
