using namespace std;

struct circular_linked_list_node;


struct Routing_table_node
{
    // a pointer for the Machine..
    circular_linked_list_node *ptr;
    // routing index and Number for the storage of the Index & Numbers
    
    int routing_index;
    int routing_number;
    // These are the Next and Previous Pointers for doubly Linked List..
    Routing_table_node *routing_next;
    Routing_table_node *routing_previous;
};

class Routing_table_linked_list
{
    // A pointer that points towards towards the head pf the List..
    Routing_table_node *head;

public:
    // Default constructor of the Doubly Linked List..
    Routing_table_linked_list()
    {
        head = NULL;
    }

    // Insert the Node at the Start of the Routing table linked list..
    void insert_At_start(int routing_idx, int routing_no)
    {
        // First of all make a new Node..
        Routing_table_node *new_node = new Routing_table_node();
        // Put the data into the New Node..
        new_node->routing_index = routing_idx;
        new_node->routing_number = routing_no;
        // Now new Node next will point to the Node..
        new_node->routing_next = (head);
        new_node->routing_previous = NULL;
        // if head_node is not null then make the head previous point to new Node..
        if ((head) != NULL)
            head->routing_previous = new_node;
        // move the head to point to the new node
        (head) = new_node;
    }

    void insert_the_node_at_correct_index(int routing_idx, int routing_no, int insert_after_this_index)
    {
        if (head != NULL)
        {
            // Create the Node..
            Routing_table_node *new_node = new Routing_table_node();

            // Put the data into the Node..
            new_node->routing_index = routing_idx;
            new_node->routing_number = routing_no;
            // Travse the Linked List to Find the Correct Index..
            Routing_table_node *temp = head;
            while (temp != NULL)
            {
                // Find the Index to be Placed After..
                if (temp->routing_index == insert_after_this_index)
                {
                    break;
                }
                temp = temp->routing_next;
            }
            // After the Above Iteration. Temp stores the Previous Node..

            // Make next of new node points toward the Previous Node
            new_node->routing_next = temp->routing_next;
            // next of Previous node as the New Node..
            temp->routing_next = new_node;
            // make the previous of new node points to the Previous Node..
            new_node->routing_previous = temp;
            // change the previous of the next node if it exist
            if (new_node->routing_next != NULL)
                new_node->routing_next->routing_previous = new_node;
        }
    }
    // a Function to Insert at the End of the Doubly Linked list..
    void insert_the_node_at_the_end(int routing_idx, int routing_no, circular_linked_list_node *pointer)
    {

        Routing_table_node *new_node = new Routing_table_node();

        // Put the data
        new_node->routing_index = routing_idx;
        new_node->routing_number = routing_no;
        new_node->ptr = pointer;
        // make the last as Null..
        new_node->routing_next = NULL;
        // check if it;s empyrt
        if (head == NULL)
        {
            new_node->routing_previous = NULL;
            head = new_node;
            return;
        }
        // travser until the last node is found..
        Routing_table_node *temp = head;
        while (temp->routing_next != NULL)
            temp = temp->routing_next;
        // change next of last node..
        temp->routing_next = new_node;
        // setting previous of new Node.
        new_node->routing_previous = temp;
    }

    // A function that makes in an index and delete that index..
    void delete_the_given_index_node(int index)
    {
        if (head == NULL)
            return;
        // First we have to check if it's head node
        if (head->routing_index == index)
        {
            Routing_table_node *temp = head;
            head = head->routing_next;
            head->routing_previous = NULL;
            delete temp;
            return;
        }
        Routing_table_node *temp = head;
        while (temp->routing_index != index)
        {
            temp = temp->routing_next;
        }
        // Now we have the node to be deleted at the temp

        // Fix next pointer
        if (temp->routing_next != NULL)
            temp->routing_next->routing_previous = temp->routing_previous;

        // fix previous Pointer.
        if (temp->routing_previous != NULL)
            temp->routing_previous->routing_next = temp->routing_next;

        delete temp;
    }
    // Find an index and change it's correcsponding Value..
    void change_value_at_index(int idx,int new_number)
    {
        // Find that Particular Node
        Routing_table_node *temp = head;
        while (temp->routing_index != idx)
        {
            temp = temp->routing_next;
        }
        temp->routing_number = new_number;
    }
    // this is simply a Function to display the Double Linked List of the Routing Tab
    void display_routing_table()
    {
        Routing_table_node *temp;
        temp = head;
        while (temp != NULL)
        {
            cout << " \nRouting Index: " << temp->routing_index << " :: "
                 << "Routing Value: "
                 << "::" << temp->routing_number;
            temp = temp->routing_next;
        }
    }
};
/*
int main()
{
    Routing_table_linked_list list;
    list.insert_At_start(1, 2);
    list.insert_At_start(2, 2);
    list.insert_At_start(3, 2);
    list.insert_At_start(4, 2);
    list.insert_At_start(5, 2);
    list.insert_the_node_at_correct_index(7, 2, 2);
    list.insert_the_node_at_the_end(9, 5);
    list.insert_At_start(4, 2);
    list.delete_the_given_index_node(4);
    list.delete_the_given_index_node(2);
    list.change_value_at_index(7,7);
    list.display_routing_table();

    return 0;
}*/
