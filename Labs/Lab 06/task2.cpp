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
};

class circular_list
{
public:
    Node *head;
    Node *tail;
    circular_list()
    {
        head = NULL;
        tail = head;
    }
    void append(Employee &employee)
    {
        Node *newNode = new Node;
        newNode->Emp = employee;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            newNode->next=tail;
            tail = head;
            
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
            tail = head;
        }
    }
    void display()
    {
        Node *curr = head;
        while (curr->next != tail)
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

        while (current->next != tail && id != current->Emp.id)
        {
            current = current->next;
        }
        if (current == tail)
        {
            cout << "\nNo data Found\n";
        }
        if (current == head)
        {
            head = current->next;
            delete current;
        }
        else
        {
            delete current;
        }
    }
};

int main(){
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
    circular_list obj;
    obj.append(emp1);
    obj.append(emp2);
    obj.append(emp3);
    obj.remove_by_id("huzaifa");
    obj.display();

    return 0;
}