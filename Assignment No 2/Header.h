/***
 *
 * Muhammad Ismail Ramzan
 * Roll No : 20I-0941
 * Section : T
 *
 * ****/

 // write documentation


 // Inclucding the Library Files
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Foward declearing the required Classes With Templates
template <class T>
class CCIDList;
class CBIDLIST;
template <class T>
class CBID_NODE;
template <class T>
class CCID_NODE;

// Using the templates, T will be mostly passed as the string
template <class T>
// Here is the CBID_NODE class. This class basically holds the Node data and two pointers. As CBID is going to be doubly linked list so it contains next, previous pointer. There is another member named as ptr_to_ccid_list. This points to the same cnic member but on the CCID list
class CBID_NODE
{
public:
    // These are the data members of this node
    T cnic;
    T name;
    T father_name;
    T gender;
    T address;
    T nationality;
    // 2 pointers to help in forming the doubly linked list
    CBID_NODE* next, * previous;
    // This is a pointer that helps us to point to the CCID list
    CCID_NODE<T>* ptr_to_ccid_list;
};

// This is the CCID List. it will be a circular doubly list
template <class T>
class CCIDList
{
public:
    // Declearing the CCID_NODEs for head and tail pointers
    CCID_NODE<string>* head;
    CCID_NODE<string>* tail;

    // Initialy head and tail will be pointing to the NULL
    CCIDList()
    {
        // make head & tail as null and head equal to tail
        head = NULL;
        tail = NULL;
        head = tail;
    }

    /********************************/
    ~CCIDList()
    {
        // this function just simply displays the cnic
        T* temp = head;
        if (head != NULL)
        {

            do
            {
                //  now it points toward next pointer
                T* next = temp->next;
                delete temp;
                temp = next;
                // run until the you again reaches the head
            } while (temp != head);
        }
        // in the end make head as null
        head = tail = NULL;
    }
    // A function that searches for the cnic in the list and return the final string
    string return_string_by_cnic_ccid(string cnic_find)
    {
        // make a temp variable
        T* temp = head;
        // check if the head is not NULL ( list is not empty)
        if (head != NULL)
        {
            // First of all check the tail if it is equal to the cnic
            if ((tail->cnic == cnic_find))
            {
                // if it is then Simply Get the Information of the User
                string final = "";
                cout << "\n Found you \n";
                // Get the name,father_name,crimes and everything & store them into a string variable named as final string the return that final string
                final = temp->ptr_to_cbid_list->name + " " + temp->ptr_to_cbid_list->father_name + " " + temp->ptr_to_cbid_list->gender + " " +
                    temp->ptr_to_cbid_list->address +
                    temp->ptr_to_cbid_list->nationality + " " + temp->crime_ccid.description + " " + temp->crime_ccid.punishment + temp->crime_ccid.fine;
                return final;
            }
            // If There is no cnic in the Tail Node then Search in the whole lists
            else
            {
                // Ierate through the end of the list
                while ((temp->next != head && temp->next != nullptr))
                {
                    // if you find the cnic then Go to this condition
                    if ((cnic_find) == (temp->cnic))
                    {
                        // Get the name,father_name,crimes and everything & store them into a string variable named as final string the return that final string
                        string final = "";
                        cout << "\n Found you \n";
                        final = temp->ptr_to_cbid_list->name + " " + temp->ptr_to_cbid_list->father_name + " " + temp->ptr_to_cbid_list->gender + " " +
                            temp->ptr_to_cbid_list->address +
                            temp->ptr_to_cbid_list->nationality + " " + temp->crime_ccid.description + " " + temp->crime_ccid.punishment + temp->crime_ccid.fine;
                        // return a single string in the end!
                        return final;
                    }
                    // keep increasing the temp until it reaches the head because it is a circular linked list
                    temp = temp->next;
                }
            }
        }
        // if is was unable to find the string due to some reason then return not found!
        return "Not Found! ";
    }

    // This is a helper function for the Inserting node according ot the ascending order
    void insert_node_at_index(T* node_Data, int index)
    {

        // First of all increase the index because we are passing index-1 into the function
        index++;

        {
            // placing the node at the position
            T* temp = head;
            for (int i = 1; i < index - 1; i++)
            {
                //	if (temp != NULL)
                {
                    // keep iterating until you reaches the specified position
                    temp = temp->next;
                }
            }
            // Now we have that position
            if (temp != NULL)
            {
                // if temp is not NULL then simply insert this node between the 2 nodes

                // setting their pointers
                node_Data->next = temp->next;
                node_Data->previous = temp;
                temp->next = node_Data;
                // checking if there is no next node ! if there is no then assign the cirrect pointer
                if (node_Data->next != NULL)
                    node_Data->next->previous = node_Data;
            }
        }
    }

    // This is the function that is called for arranging nodes in the ascending order uon entry
    T* insert_ascending_according_to_cnic(T& node_Data)
    {
        // some helper varaibles
        bool flag = false;
        int index = 0;
        // creating the Node
        T* new_node = new T;
        new_node->cnic = node_Data.cnic;
        // Now using the linked list inside the ccid make a node of the crime
        new_node->append(node_Data.crime_ccid);
        // This is also senting the data in the crime linked list
        new_node->crime_ccid.description = node_Data.crime_ccid.description;
        new_node->crime_ccid.fine = node_Data.crime_ccid.fine;
        new_node->crime_ccid.punishment = node_Data.crime_ccid.punishment;
        // setting the ptr to cbid pointer
        new_node->ptr_to_cbid_list = node_Data.ptr_to_cbid_list;
        // if there is no element in the list
        new_node->next = NULL;
        new_node->previous = NULL;
        // checking if empty
        if (head == NULL && head == tail)
        {
            // if list is empty create the first node and return it!
            head = new_node;
            tail = new_node;
            new_node->next = head;
            return new_node;

        } // if not empty then check for the first node
        else if (stoi(new_node->cnic) < stoi(head->cnic))
        {
            // insert the node at the first position

            tail->next = new_node;
            head->previous = new_node;
            new_node->next = head;
            new_node->previous = NULL;
            head = new_node;
            // after inserting the node return that node
            return new_node;
        }
        else
        {
            // if node need to be inserted at the correct position
            T* temp = head;
            // checking for the correct position
            do
            {
                // check & find the correct position of the node
                if (stoi(new_node->cnic) < stoi(temp->cnic))
                {
                    // once you find it correct posiition call the function to insert it at the positiion
                    flag = true;
                    insert_node_at_index(new_node, index);
                    // after inserting return the new node
                    return new_node;
                    break;
                } // then this is the position to insert
                index++;
                temp = temp->next;
            } while (temp != head);
            // suppose if the condition failed then we have to insert at the end
            if (!flag)
            {
                // this codes insert the code at the end
                tail->next = new_node;
                new_node->previous = tail;
                tail = new_node;
                new_node->next = head;
                // return the new node after the inseration
                return new_node;
            }
        }
    }
    // This function takes a ccnic and cbid node to find the matching cnic and sets the cbid->pointer to cciid and ccid->pointer to cbid into their correct address
    void return_Address_of_matching_cnic(string cnic_find, CBID_NODE<string>& obj)
    {
        CCID_NODE<string>* temp = head;
        bool found = false;
        if (head != NULL)
        {

            do
            {
                // if cnic is foind then
                if (cnic_find == temp->cnic)
                {
                    found = true;
                    //   cout << "\n Found the CNIC Node \n";

                      // cout << "\n-------------------\n";

                       //cout << temp->cnic << " \n";
                       // cout << temp->crime_ccid.description;
                       //temp->display_crimes_ccid();
                       // crime<string> wow = temp->crime_ccid;
                       // cout << wow.description;
                       // CCID_NODE<string> *temp2 = temp;

                       // set the Pointers
                    temp->ptr_to_cbid_list = &obj;
                    obj.ptr_to_ccid_list = temp;
                    //   cout << "\nName" << obj.name << "\n";

                     //  cout << "\n-------------------\n";
                    break;
                }
                temp = temp->next;
            } while (temp != head);
            // if cnci was not found then pointers will point to null
            if (!found)
            {
                obj.ptr_to_ccid_list = nullptr;
                // temp->ptr_to_cbid_list = nullptr;
            }
        }
    }

    // This is just a testing function to display & see the pointers using cnic
    void display_me_ccid()
    {
        // this function just simply displays the cnic
        T* temp = head;
        if (head != NULL)
        {

            do
            {
                cout << "\n-------------------\n";
                cout << temp->cnic << " -->";
                // cout << temp->crime_ccid.description;
                // temp->display_crimes_ccid();
                if (temp->ptr_to_cbid_list != NULL)
                    cout << temp->ptr_to_cbid_list->cnic;
                cout << "\n";

                // crime<string> wow = temp->crime_ccid;
                // cout << wow.description;

                temp = temp->next;
                // run until the you again reaches the head
            } while (temp != head);
        }
        // cout << head;
    }
};

// this is the node for the crimes
template <class T>
struct crime
{
    T description;
    T punishment;
    T fine;
    // a pointer to points toward the next in the linked list of the crime
    crime<T>* next;
};

// This is cbid node that contains the cnic and the crimes linked list
template <class T>
struct cbid
{
    T cnic;
    crime<T> crimes;
};

// this is the data structure that contains all the information of the person
template <class T>
struct Data
{
    T cnic;
    T name;
    T father_name;
    T gender;
    T address;
    T nationality;
    // an object of cbid!
    cbid<string> cbid_str;
    // next pointer for the criminal linked list
    Data<string>* next;
    // Node structure for data pipeline, implement data members as per requirement
};

//	A linkedlist based queue to implement databases
//      Implement additional functions
template <class T>
class DataPipeline
{
    // this is the queue so making rear and head pointers
    Data<string>* rear;
    Data<string>* head;

public:
    DataPipeline()
    {
        // in the begnning both pointers will be null
        head = NULL;
        rear = NULL;
    }
    // this function simply returns the value at the first pointer
    T front()
    {
        return *head;
    }
    // this function simply returns the value at the rear poineter
    T back()
    {
        return *rear;
    }
    // this function is used to put the data inside the queue
    T enqueue(T& info)
    {
        // Function to insert inside the Quene
        T* new_node = new T;
        *new_node = info;
        new_node->next = NULL;
        // if there is no Data Member ( queue is empty)
        if (rear == NULL)
        {
            rear = new_node;
            head = new_node;
        }
        // if there is some data then add the data
        else
        {
            rear->next = new_node;
            rear = new_node;
        }
        // in the end retunr
        return T();
    }

    T dequeue()
    {
        // Dequeue always happens from the front and then front pointer  is moved toward the next Node
        T data_keeper;
        // checking if empty
        if (head == NULL)
        {
            cout << "\n Queue is Empty \n";
        }
        else
        {
            // making a pointer to keep track of queue and delete the element
            T* ptr;
            ptr = head;
            data_keeper = (*head);
            head = head->next;
            delete ptr;
        }
        // in the end return the deleted node data
        return data_keeper;
    }
    // this functions check if queue is empty or not
    bool is_empty()
    {
        // if front is null means it's empty
        if (front == NULL)
            return true;
        else
            return false;
    }
};
// This is the CCID_Node. that contains a crime linked list
template <class T>
class CCID_NODE
{
public:
    T cnic;
    // declearing the objects to help in forming linked list
    crime<string> crime_ccid;
    crime<string>* head;
    // Implement additional data members and functions as per requirement
    CCID_NODE* next, * previous;
    CBID_NODE<string>* ptr_to_cbid_list;

    // making function for the crime linked list
    CCID_NODE()
    {
        // at the start head will be null
        head = NULL;
    }
    // this functions append the data into the crime linked list
    void append(crime<string> information)
    {
        // 1. allocate node
        crime<string>* new_node = new crime<string>;
        // put the data inside the node
        new_node->description = information.description;
        new_node->punishment = information.punishment;
        new_node->fine = information.fine;
        // // this is going to be last node
        new_node->next = NULL;
        if (head == NULL)
        {
            head = new_node;
            return;
        }
        crime<string>* last = head;
        // 5. Else traverse till the last node
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = new_node;
        return;
    }
    // this function will return the string from the crimes linked list
    // this was made simply to see the database. this is not used anywhere
    string get_crime_list()
    {
        crime<string>* temp = head;
        while (temp != NULL)
        {
            return (temp->description + " " + temp->punishment + temp->fine);
            temp = temp->next;
        }
    }
    // this is alaso a helper function to visualize the data.
    void display_crimes_ccid()
    {
        crime<string>* temp = head;
        while (temp != NULL)
        {
            cout << " " << temp->description;
            cout << " " << temp->punishment;
            cout << " " << temp->fine;
            temp = temp->next;
        }
    }
    // Deleting the Crimes
    ~CCID_NODE() {

        // here we have to delete the linked list of the crimes!
        crime<string>* temp = head;
        while (temp != NULL)
        {
            crime<string>* next = temp->next;
            delete temp;
            temp = next;
        }
        head = NULL;

    }
};

// This is the CBID List
template <class T>
class CBIDList
{
public:
    // doubly list
    CBID_NODE<string>* head;
    CBID_NODE<string>* tail;

    // at the starting of the list
    CBIDList()
    {
        head = NULL;
        tail = NULL;
    }

    // Destructor
    ~CBIDList()
    {

        // Points to the head
        tail->next = nullptr;
        T* current = head;
        // run until you reaches the NUll
        do
        {
            // a pointer will point to the next node
            T* next = current->next;
            // now delete the currect node
            delete current;
            // move the currect to the next node
            current = next;
        } while (current != NULL);
        // in the end make head as null
        head = NULL;
    }

    /************Database Fcuntions*************/
    // This function update the father name when called by the datapipeline
    bool update_fname_by_cnic(string fnae, string cnic_find)
    {
        // make a temporray object and assign to the head
        T* temp = head;
        if (head != NULL)
        {
            // check the tail for the cnic
            if ((tail->cnic == cnic_find))
            {
                // if father name is found at the tail! that's cool just change it
                temp = tail;
                temp->father_name = fnae;
                return true;
            }
            else
            {
                // now start from the start and start searching for the giive cnic
                while (temp->next != head && temp->next != nullptr)
                {
                    // once you find the cnic change it's father name
                    if ((cnic_find) == (temp->cnic))
                    {
                        // charging the father name
                        temp->father_name = fnae;
                        return true; // end
                    }
                    // go to the next pointer
                    temp = temp->next;
                }
            }
        }
        // if not found then return false
        return false;
    }

    // This function update the natuonality name when called by the datapipeline
    bool update_nationality_by_cnic(string nation, string cnic_find)
    {
        // making a temp object and assigning to the head
        T* temp = head;
        if (head != NULL)
        {
            // check the tail for the speecified cnci
            if ((tail->cnic == cnic_find))
            {
                // if found then change the nationality
                temp = tail;
                temp->nationality = nation;
                return true;
            }
            else
            {
                // if cnic is not at the tail then traverse the whole objects
                while (temp->next != head && temp->next != nullptr)
                {
                    // if you find the cnci
                    if ((cnic_find) == (temp->cnic))
                    {
                        // then change the nationlity
                        temp->nationality = nation;
                        return true;
                    }
                    // go to next pointer of the list
                    temp = temp->next;
                }
            }
        }
        // if cnic is not found return false
        return false;
    }

    // This function is used to add the crime by cnic

    // it is taking an extra argument which is list ( was not given in the )
    /**
     *  Why i passed ccid list in the below function?
     *  Well, i could have directly implemented this function in the datapipeline. I
     * would have direct access to ccid list. As i was using CBID functions for all the
     * implemetation of the Given list so i called cbid here too.
     *
     * Alternatively, i could have wrote this function's code in the Datapipeline function which
     * has direct access to CCIDList .
     *
     * In short, passing ccid here, does not effect to the given template because i had access
     * to ccidList in the datapipeline. This function is only called once from there.
     *
     * **/
    bool add_crime_by_cnic(string cnic_find, string des, string pun, string fin, CCIDList<CCID_NODE<string>>& obje)
    {
        // make a temporary object and set it to the head
        T* temp = head;
        if (head != NULL)
        {
            // checking the tail for the correct cnic
            if ((tail->cnic == cnic_find))
            {
                temp = tail;
                // making a crimial object
                CCID_NODE<string> new_node;
                // add data to the node
                new_node.crime_ccid.description = des;
                new_node.crime_ccid.fine = fin;
                new_node.crime_ccid.punishment = pun;
                new_node.cnic = cnic_find;
                // now i need to set the correct pointers
                new_node.ptr_to_cbid_list = temp;
                // inserrt the crime in the crime linked list and get the pointer to that node
                CCID_NODE<string>* ptr = obje.insert_ascending_according_to_cnic(new_node);
                // once i get the pointer now i can set the ccid list, Simple :)
                temp->ptr_to_ccid_list = ptr;

                return true;
            }
            else
            {
                // if tail does not contain particular cnic then check the whole list
                while (temp->next != head && temp->next != nullptr)
                {
                    // if cnic is found
                    if ((cnic_find) == (temp->cnic))
                    {
                        // create a node to add
                        CCID_NODE<string> new_node;
                        // add data to the node
                        new_node.crime_ccid.description = des;
                        new_node.crime_ccid.fine = fin;
                        new_node.crime_ccid.punishment = pun;
                        new_node.cnic = cnic_find;
                        new_node.ptr_to_cbid_list = temp;
                        // inserrt the crime in the crime linked list and get the pointer to that node
                        CCID_NODE<string>* ptr = obje.insert_ascending_according_to_cnic(new_node);
                        temp->ptr_to_ccid_list = ptr;
                        // if added successfully then return true
                        return true;
                    }
                    // go to the next element on the list
                    temp = temp->next;
                }
            }
        }
        // if not then return false
        return false;
    }
    // This function is used to update the crime by cnic
    bool update_crime_by_cnic(string cnic_find, string des, string pun, string fin)
    {
        // make a temp and set it to the head
        T* temp = head;
        if (head != NULL)
        {
            // check the tail for the cnci
            if ((tail->cnic == cnic_find))
            {
                // if found then check if the criminal has some crime
                temp = tail;
                if (temp->ptr_to_ccid_list != NULL)
                {
                    // if criminal has crimes then change them
                    temp->ptr_to_ccid_list->crime_ccid.fine = fin;
                    temp->ptr_to_ccid_list->crime_ccid.punishment = pun;
                    temp->ptr_to_ccid_list->crime_ccid.description = des;
                    // after changing return true
                    return true;
                }
                // if there is no data of the criminal then return falses
                return false;
            }
            else
            {
                // if it is not at the tail then check the entire list
                while (temp->next != head && temp->next != nullptr)
                {
                    // check for the cnci
                    if ((cnic_find) == (temp->cnic))
                    {
                        // if found then check if the person has criminal record
                        if (temp->ptr_to_ccid_list != NULL)
                        {
                            // if the person has criminal record then change its
                            temp->ptr_to_ccid_list->crime_ccid.fine = fin;
                            temp->ptr_to_ccid_list->crime_ccid.punishment = pun;
                            temp->ptr_to_ccid_list->crime_ccid.description = des;
                            // after changing return true
                            return true;
                        }
                        // if no record then return false
                        return false;
                    }
                    // go to the next element of the list
                    temp = temp->next;
                }
            }
        }
        // if no cnci is found then return falses
        return false;
    }

    // tHIS FUnction delete the criminal record of the person
    bool delete_crime_by_cnic(string cnic_find, string des, string pun, string fin)
    {
        // make a temp and set it to the head
        T* temp = head;
        if (head != NULL)
        {
            // check the tail for the crime record
            if ((tail->cnic == cnic_find))
            {
                // if criminal record is found
                temp = tail;
                if (temp->ptr_to_ccid_list != NULL)
                {
                    // then make a temp pointer that points to that record
                    CCID_NODE<string>* ptr = temp->ptr_to_ccid_list;
                    // make the pointers correct
                    ptr->previous->next = ptr->next;
                    ptr->next->previous = ptr->previous;
                    // then delete that pointer
                    delete ptr;
                    temp->ptr_to_ccid_list = NULL;
                    // if deleted successfuly return true
                    return true;
                }
                // if no cnic found then return false
                return false;
            }
            else
            {
                //
                while (temp->next != head && temp->next != nullptr)
                {
                    // check for the cnic
                    if ((cnic_find) == (temp->cnic))
                    {
                        // check if criminal record is found
                        if (temp->ptr_to_ccid_list != NULL)
                        {
                            // then make a temp pointer that points to that record

                            CCID_NODE<string>* ptr = temp->ptr_to_ccid_list;
                            // make the pointers correct
                            ptr->previous->next = ptr->next;
                            ptr->next->previous = ptr->previous;
                            // now delete that node
                            delete ptr;
                            // make sure there is no record now
                            temp->ptr_to_ccid_list = NULL;
                            // return true if everything goes well
                            return true;
                        }
                        // return false
                        return false;
                    }
                    // go to next object
                    temp = temp->next;
                }
            }
        }
        // if no cnci found then retun false
        return false;
    }

    // This is the function that updates the address by using cnic
    bool update_address_by_cnic(string addr, string cnic_find)
    {
        // make a temp and set it to the head
        T* temp = head;
        if (head != NULL)
        {
            // check if tail contains that element (node)
            if ((tail->cnic == cnic_find))
            {
                // if yes then change  the address.
                temp = tail;
                temp->address = addr;
                // successfully changed return true
                return true;
            }
            else
            {
                // traverse the whole list
                while (temp->next != head && temp->next != nullptr)
                {
                    // if cnci is found then
                    if ((cnic_find) == (temp->cnic))
                    {
                        // change the address and return true
                        temp->address = addr;
                        return true;
                    }
                    // go to the next node
                    temp = temp->next;
                }
            }
        }
        // if no cnic found then return false
        return false;
    }
    // This is the function that updates the address by using cnic
    bool update_name_by_cnic(string fnae, string cnic_find)
    {
        // make a temp and set it to the head
        T* temp = head;
        if (head != NULL)
        {
            // check the tail for the cnic
            if ((tail->cnic == cnic_find))
            {
                // change the name
                temp = tail;
                temp->name = fnae;
                return true;
            }
            else
            {
                // traverse the whole list for the element
                while (temp->next != head && temp->next != nullptr)
                {
                    // if cnic is found then
                    if ((cnic_find) == (temp->cnic))
                    {
                        // change the name and return true
                        temp->name = fnae;
                        return true;
                    }
                    // go to the next node
                    temp = temp->next;
                }
            }
        }
        // if not then return false
        return false;
        ;
    }
    // A function that searches for the cnic in the list and return the final string
    string return_string_by_cnic(string cnic_find)
    {
        // make a temp and set it to the head
        T* temp = head;
        if (head != NULL)
        {
            // check the tail for the cnic
            if ((tail->cnic == cnic_find))
            {
                // if found the make 2 empty strings
                temp = tail;
                string final = "";
                string n = "";
                // checking if cnic has crimes or not
                if (temp->ptr_to_ccid_list != NULL)
                {
                    // if there are crimes then put them in the final string
                    n = temp->ptr_to_ccid_list->crime_ccid.description + temp->ptr_to_ccid_list->crime_ccid.punishment + temp->ptr_to_ccid_list->crime_ccid.fine;
                }

                // temp->ptr_to_ccid_list->display_crimes_ccid();
                cout << "\n";
                // make a final string to pass test cases
                final = temp->name + " " + temp->father_name + " " + temp->gender + " " + temp->address + temp->nationality;
                // append to the final string
                final = final + " " + n;
                // return the final string
                return final;
            }
            else
            {
                // traverse the whole list
                while (temp->next != head && temp->next != nullptr)
                {
                    // look for the cnic
                    if ((cnic_find) == (temp->cnic))
                    {
                        // make a final string to return
                        string final = "";
                        /* cout << "\n Found you \n";
                         // cout << temp->ptr_to_ccid_list->crime_ccid.fine;
                         cout << temp->name << "\n";
                         cout << temp->father_name << "\n";
                         cout << temp->gender << "\n";
                         cout << temp->address << "\n";
                         cout << temp->nationality << "\n";*/
                         // this string will help in holding the crimes
                        string n = "";
                        // checking if cnic has crimes or not
                        if (temp->ptr_to_ccid_list != nullptr)
                        {
                            // if he has crimes then make a string of the crimes
                            n = temp->ptr_to_ccid_list->crime_ccid.description + " " + temp->ptr_to_ccid_list->crime_ccid.punishment + temp->ptr_to_ccid_list->crime_ccid.fine;
                        }

                        // temp->ptr_to_ccid_list->display_crimes_ccid();
                        cout << "\n";
                        // now make a final string
                        final = temp->name + " " + temp->father_name + " " + temp->gender + " " + temp->address + temp->nationality;
                        // add the crimes and other data to one string and return
                        final = final + " " + n;
                        return final;
                    }
                    // check the next node for the cnic
                    temp = temp->next;
                }
            }
        }
        // if no cnic found return not found
        return "Not Found! ";
    }

    // inserting at index after scanning for cnic ( helper function to insert at the idex)
    void insert_node_at_index(T* node_Data, int index)
    {

        // icrease the index by 1
        index++;
        {
            // make a temp and set to head
            T* temp = head;

            for (int i = 1; i < index - 1; i++)
            {
                // go to that particular node
                if (temp != NULL)
                {
                    temp = temp->next;
                }
            }
            // Now we have that position
            if (temp != NULL)
            {
                // now let's insert at that position
                // make sure to correct pointers of previous and next node
                node_Data->next = temp->next;
                node_Data->previous = temp;
                temp->next = node_Data;
                // check if it's next node is not null if not then correct it's pointer
                if (node_Data->next != NULL)
                    node_Data->next->previous = node_Data;
            }
        }
    }
    // start inserting accoirdgin to cnic
    T* insert_ascending_according_to_cnic(T& node_Data)
    {
        bool flag = false;
        int index = 0;
        // creating the Node
        T* new_node = new T;
        // Putting all the data into the Node
        new_node->cnic = node_Data.cnic;
        new_node->name = node_Data.name;
        new_node->father_name = node_Data.father_name;
        new_node->gender = node_Data.gender;
        new_node->address = node_Data.address;
        new_node->nationality = node_Data.nationality;
        new_node->ptr_to_ccid_list = node_Data.ptr_to_ccid_list;
        // if there is no element in the list
        new_node->next = NULL;
        new_node->previous = NULL;
        // checking if empty
        if (head == NULL)
        {
            // insert node at first
            head = new_node;
            tail = new_node;
            return new_node;
        } // if not empty then check for the first node
        else if (stoi(new_node->cnic) < stoi(head->cnic))
        {
            // then it will be the first node
            // setting the pointers
            new_node->next = head;
            tail = head->next;
            head->previous = new_node;
            head = new_node;
            return new_node;
        }
        else
        {
            // now if we need to check the correct position for the node
            T* temp = head;
            // checking for the correct position
            while (temp->next != NULL)
            {
                // check if previous node cnic matches
                if (stoi(new_node->cnic) < stoi(temp->cnic))
                {
                    flag = true;
                    // if we found the correct position then call the function to do it's job
                    insert_node_at_index(new_node, index);
                    return new_node;
                    break;
                } // then this is the position to insert
                index++;
                // go to next node
                temp = temp->next;
            }
            // suppose if the condition failed then we have to insert at the end
            if (!flag)
            {
                // simply inserting at the end of the list
                tail->next = new_node;
                new_node->previous = tail;
                tail = new_node;
                return new_node;
            }
        }
    }
    // this is just a helper function to visualize the data
    void display_me()
    {
        // traverse the whole list and show me the correct data
        T* temp = head;
        if (head != NULL)
        {
            while (temp != NULL)
            {
                // show the cnic
                cout << temp->cnic << "-->";
                // show to what pointer cnic it is pointing to
                if (temp->ptr_to_ccid_list != NULL)
                    cout << temp->ptr_to_ccid_list->cnic;
                cout << "\n";
                temp = temp->next;
            }
        }
        // cout << head;
    }
};

// THIS IS THE DATABASE!!!
template <class T>
class Database
{
    CBIDList<CBID_NODE<string>> CBID;        // CBID Database
    CCIDList<CCID_NODE<string>> CCID;        // CCID Database
    DataPipeline<Data<string>> dataPipeline; // Queue

public:
    // constructor passing the file names to it
    Database(const T& filename, const T& filename1)
    {
        // making a temporary obect to keep the data for pipeline
        Data<string> info;
        // making files object
        ifstream file1;
        ifstream file2;

        // Open Both the files!

        // filename --> cbid
        // filename1 --> ccid
        file1.open(filename);
        file2.open(filename1);
        // check if there are errors in the opening of the files
        if (!file1)
        {
            cout << "\n Unable to Open the File of CBID \n";
        }
        else if (!file2)
        {
            cout << "\n Unable to Open the File of CCID \n";
        }
        else
        {
            // some variables for storing data
            string line;
            string line2;
            // will count the number of objects in the queue
            int count = 1;

            // open the file1 and start reading line by line
            while (getline(file1, line))
            {
                if (count)
                {
                    // helper variabes to break the lines
                    string delimiter = " ";
                    string s = line;
                    size_t position = 0;
                    string token;

                    // Looping to get each value from the file
                    int i = 1;
                    // Get the position until u find the space ""
                    while ((position = s.find(delimiter)) != std::string::npos)
                    {
                        // Now get that string!
                        token = s.substr(0, position);
                        // Assign values to particular datatype!

                        /*
                        cases are actually representing the word column in the
                        file and assign values accordingly. "i" is the variable
                        to help in it
                        */
                        switch (i)
                        {
                        case 1:
                            // if it is cnic then put it into info object
                            info.cnic = token;
                            break;
                        case 2:
                            // if it is name then put it into info object
                            info.name = token;
                            break;
                        case 3:
                            // if it is father name then put it into info object
                            info.father_name = token;
                            break;
                        case 4:
                            // if it is gender then put it into info object
                            info.gender = token;
                            break;
                        case 5:
                        case 6:
                        case 7:
                            // if it is address then put it into info object
                            info.address = info.address + token + " ";
                            break;

                        default:
                            break;
                        }
                        // After Assignming , Remove that string!
                        s.erase(0, position + delimiter.length());
                        i++;
                    }
                    // in the end the last word will be assigned which is nationality
                    info.nationality = s;
                    /*   cout << "\n\n";
                       cout << info.cnic << "\n";
                       cout << info.name << "\n";
                       cout << info.father_name << "\n";
                       cout << info.gender << "\n";
                       cout << info.address << "\n";
                       cout << info.nationality << "\n";
                       //	int line_count = 0;*/

                       // now close the file2
                    file2.close();
                    // open the filename1 ( ccid )
                    file2.open(filename1);
                    bool tracking = false;
                    while (getline(file2, line2))
                    {
                        // cout << "lines : " << line2 << "\n";
                        //  Looping to get each value from the file
                        // these are helper varaibles to read the file
                        int i = 1;
                        s = line2;
                        position = 0;
                        token = "";
                        delimiter = " ";
                        // Get the position until u find the space ""
                        while ((position = s.find(delimiter)) != std::string::npos)
                        {
                            token = s.substr(0, position);
                            // Assign values to particular datatype!
                            // only assign if you find the data of that particular

                            // check if cnic in the file mataches with the cnic of the datapipeline object. if yes then put data
                            if (line2.substr(0, line2.find(" ")) == info.cnic)
                            {
                                tracking = true;
                                // this is simply reading the each colum. i varaible represents the column number
                                switch (i)
                                {
                                case 1:
                                    // if it is cnic then put it into info->cbid_str object
                                    info.cbid_str.cnic = token;
                                    break;
                                case 2:
                                    // if it is description then put it into info->cbid_str object
                                    info.cbid_str.crimes.description = token;
                                    break;
                                case 3:
                                case 4:
                                case 5:
                                case 6:
                                    // if it is punishment then put it into info->cbid_str object and make sure to combine the string
                                    if (token != "-")
                                        info.cbid_str.crimes.punishment = info.cbid_str.crimes.punishment + token + " ";
                                    break;

                                default:
                                    break;
                                }
                                // After Assignming , Remove that string!
                                s.erase(0, position + delimiter.length());

                                info.cbid_str.crimes.fine = s;
                                i++;
                                //	break;
                            }
                            else
                            {
                                // if cnic does not match then simply we don't need to iterate authing!
                                break;
                            }

                            //
                        }
                    }
                    // if cnic in the cbid = cnic in the cbic
                    if (tracking)
                    {
                        /*
                        // cout << "\n\n\n ******HAHAHA****** \n\n\n\n";
                        cout << "\n\n I AM HERE!!!!";
                        cout << info.cbid_str.cnic << "\n";
                        cout << info.cbid_str.crimes.description << "\n";
                        cout << info.cbid_str.crimes.fine << "\n";
                        cout << info.cbid_str.crimes.punishment << "\n";
                        cout << "\n THE NED\n";
                        // Putting data for CCID*/

                        // make a ccid node
                        CCID_NODE<string> obj_node_ccid;

                        // Once data is in the node put it in the queue
                        obj_node_ccid.cnic = info.cbid_str.cnic;
                        obj_node_ccid.crime_ccid.fine = info.cbid_str.crimes.fine;
                        obj_node_ccid.crime_ccid.description = info.cbid_str.crimes.description;
                        obj_node_ccid.crime_ccid.punishment = info.cbid_str.crimes.punishment;

                        string n = info.cbid_str.cnic;
                        // before sending the data to the ccid list make sure cnic is corect
                        if (n.length() == 4)
                        {
                            // Remember!!!!
                            // Now insert the data into the ccid list
                            CCID.insert_ascending_according_to_cnic(obj_node_ccid);
                            // make this string empty so it won't keep appeding
                            info.cbid_str.crimes.punishment = "";
                            // once we are done now close the file
                            file2.close();
                        }
                    }

                    // break;
                }
                // Put the information into the Quene
                dataPipeline.enqueue(info);
                info.address = "";
                // info = obj.rear();

                // cout << "\n-----------\n";
                count++;
            }
            count--;
            // we have count of the data that is in the queue now let's dequeue that and put the data into the CBID Node
            while (count != 0)
            {
                // cout << count << "\n";
                count = count - 1;
                // Now let's move the data to the CBID
                CBID_NODE<string> obj_node;
                // take data from the queue
                info = dataPipeline.dequeue();
                // Put the data into the object
                // cout << "\n testing \n";
                obj_node.cnic = info.cnic;
                obj_node.father_name = info.father_name;
                obj_node.name = info.name;
                obj_node.gender = info.gender;
                obj_node.address = info.address;
                obj_node.nationality = info.nationality;
                // let's scan the ccid list!
                // Inserting into CBID AND Get the pointer of the node so we can set the ccid->pointer to cbid node matching cnic correctly
                CBID_NODE<string>* final_node = CBID.insert_ascending_according_to_cnic(obj_node);

                // this function simply sets the Pointers to cbid in ccid and Pointer to ccid in cbid with matching cnic
                CCID.return_Address_of_matching_cnic(info.cnic, *final_node);
            }
        }
        // Once we have data in all the CBID AND CCID List now close the files
        file2.close();
        file1.close();
        /*
        cout << "\n Final Test Of Nodes \n";

        CBID.display_me();
        CCID.display_me_ccid();
        */
    }

    /*
    NOTE: CNIC WAS INT AND STRING SO I JUST TOOK THE INT AND CONVERTED IT TO THE STRING
    */

    // impleting the functions
    string CBID_Search_by_CNIC(int cnic)
    {
        // convert cnic to string
        string cnic_find = to_string(cnic);
        // now call the function that will return the string after finding the cnic!

        // I have pointer in cbid that points to same element in the ccid that has same cnic. So, i don't need to use ccid.

        // Alternative this code can be directly written here that is in the function and can also by written in CCID list

        string n = CBID.return_string_by_cnic(cnic_find);
        return n;
    }

    string CCID_Search_by_CNIC(int cnic)
    {
        // convert cnic to string
        string cnic_find = to_string(cnic);
        // now call the function that will return the string after finding the cnic in the CCID list

        // I have pointer in ccid that points to same element in the cbid that has same cnic. So, i don't need to use cbid.

        // Alternative this code can be directly written here that is in the function and can also by written in CBID list because both are linked

        string n = CCID.return_string_by_cnic_ccid(cnic_find);
        return n;
    }

    bool updateCBIDName(T Name, int cnic)
    {
        // convert cnic to string
        string cnic_find = to_string(cnic);
        // now calling the function that updates the name and return true or false dependingly
        return CBID.update_name_by_cnic(Name, cnic_find);
    }

    bool updateCBIDFName(T Father_Name, int cnic)
    {
        // cnic to string
        string cnic_find = to_string(cnic);
        // now calling the function that updates the father name and return true or false dependingly
        return CBID.update_fname_by_cnic(Father_Name, cnic_find);
    }

    bool updateCBIDAddress(T Address, int cnic)
    {
        string cnic_find = to_string(cnic);
        // now calling the function that updates the address and return true or false dependingly
        return CBID.update_address_by_cnic(Address, cnic_find);
    }

    bool updateCBIDNationality(T Nationality, int cnic)
    {
        string cnic_find = to_string(cnic);
        // now calling the function that updates the address and return true or false dependingly
        return CBID.update_nationality_by_cnic(Nationality, cnic_find);
    }

    bool addCrime(int cnic, T charges, T punishment, T fine)
    {
        // cnic to string
        string cnic_find = to_string(cnic);
        // now calling the function that add the crimes by cnic

        // I also passed the CCID in the function!. It should not effect the given
        // template because CCID is directly accessibly here and it is being
        // passed as the reference. In short, argument will be same as given
        // in the code templates if i write the function here instead of calling the
        // another function.
        return CBID.add_crime_by_cnic(cnic_find, charges, punishment, fine, CCID);
    }

    bool deleteCrime(int cnic, T charges, T punishment, T fine)
    {
        // convert cnic to string
        string cnic_find = to_string(cnic);
        // Call the function that deletes the particulat cnic
        return CBID.delete_crime_by_cnic(cnic_find, charges, punishment, fine);
        /*update and return true when crime found else return false*/
    }

    bool updateCrime(int cnic, T charges, T punishment, T fine)
    {
        string cnic_find = to_string(cnic);
        // call the function that update the crimes!
        return CBID.update_crime_by_cnic(cnic_find, charges, punishment, fine);
    }
};

