#include <iostream>
using namespace std;

class Employee
{
public:
    string id;
    string nic;
    int sal;
    int bonus;
};

class Node
{
public:
    Employee Emp;
    Node *next;
    Node *prev;
};

class Doubly_list
{
public:
    Node *head;
    Node *tail;

    Doubly_list()
    {
        head = NULL;
        tail = NULL;
    }

    void append(Employee &employee)
    {
        Node *newNode = new Node;
        newNode->Emp = employee;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            newNode->prev = NULL;
        }
        else
        {
            //
            Node *curr;
            curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->prev = curr;
            tail = newNode;
        }
    }
    void display()
    {
        Node *curr = head;
        while (curr != NULL)
        {
            cout << "I am running";
            cout << "\n--------------------------------\n";
            cout << curr->Emp.id << endl;
            cout << curr->Emp.nic << endl;
            cout << curr->Emp.sal << endl;
            cout << curr->Emp.bonus << endl;
            cout << "\n--------------------------------\n";
            curr = curr->next;
        }
    }

    void remove_by_id(const string id)
    {
        Node *current = head;

        while (current != NULL && id != current->Emp.id)
        {
            current = current->next;
        }
        if (current == NULL)
        {
            cout << "\nNo data Found\n";
        }
        if (current == head)
        {
            head = current->next;
            current->next->prev = head;
            delete current;
        }
        else if (current == tail)
        {
            tail = current->prev;
            current->prev->next = current->next;
            current->next = NULL;
            delete current;
        }
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
    }
    void voidUpdateSalary(int salary, string id)
    {
        Node *current;
        current = head;

        while (current && id != current->Emp.id)
        {
            current = current->next;
        }

        if (current == NULL)
        {
            cout << "\n[-] Record Not FOund! \n";
        }
        else
        {
            current->Emp.sal = salary;
        }
    }
    void voidUpdateBonus(int bonus, string id)
    {
        Node *current;
        current = head;

        while (current && id != current->Emp.id)
        {
            current = current->next;
        }

        if (current == NULL)
        {
            cout << "\n[-] Record Not FOund! \n";
        }
        else
        {
            current->Emp.bonus = bonus;
        }
    }
    void clear()
    {
        // doing for is clear
        Node *currNode = head, *nextNode = NULL;
        while (currNode != NULL)
        {
            nextNode = currNode->next;
            // destroy the current node
            delete currNode;
            currNode = nextNode;
        }
        head = NULL;
        tail = NULL;
    }
    void sort()
    {

        Node *curr = head;
        int size = 0;
        while (curr != NULL)
        {
            size++;
            curr = curr->next;
        }
        cout << "Size is: " << size;
        curr=head;
        // selection sort
      /*  for (int i = *head; i < *tail; curr=curr->next)
        {
            int min_index = i;
            // starting from i+1 index
            for (int j = i + 1; j <= size; j++)
            {
                if ( < arr[min_index])
                {
                    min_index = j;
                }
            }

            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
        */
    }
    bool is_empty()
    {
        if (head == NULL && tail == NULL)
            return true;
        else
            return false;
    }
};

int main()
{
    Employee emp1;
    emp1.id = "huzaifa";
    emp1.nic = "123";
    emp1.sal = 500;
    emp1.bonus = 12567;
    Employee emp2;
    emp2.id = "usman";
    emp2.nic = "456";
    emp2.sal = 600;
    emp2.bonus = 12367;
    Employee emp3;
    emp3.id = "ismail";
    emp3.nic = "789";
    emp3.sal = 800;
    emp3.bonus = 12347;
    Doubly_list obj;
    obj.append(emp1);
    obj.append(emp2);
    obj.append(emp3);
    obj.remove_by_id("huzaifa");
    obj.voidUpdateBonus(600, "huzaifa");
    obj.voidUpdateBonus(600, "usman");
    obj.clear();
    bool ans = obj.is_empty();
    cout << "\nEmpty is " << ans << endl;
    obj.append(emp1);
    obj.append(emp2);
    obj.append(emp3);

    obj.display();
    obj.sort();
}