#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

template <class T, class Node_tem>
class stack_list
{
public:
    Node_tem *head;

    stack_list()
    {
        head = NULL;
    }

    // Push into the stack
    void push(T info)
    {
        // if head is not null put element in the start

        if (head == NULL)
        {
            Node_tem *new_node = new Node_tem;
            new_node->data = info;
            new_node->next = NULL;
            head = new_node;
        }
        else
        {
            Node_tem *new_node = new Node_tem;
            new_node->data = info;
            new_node->next = head;
            head = new_node;
        }
    }

    T pop()
    {
        T value;
        if (head == NULL)
        {
            cout << "\nEmpty stack";
        }
        else
        {
            Node_tem *new_node = head;
            head = head->next;
            value = new_node->data;
            delete new_node;
        }
        return value;
    }
    // checking for empty
    bool is_stack_empty()
    {
        if (head == NULL)
            return false;
        else
            return true;
    }
    // now Checking for empty
    void clear()
    {
        while (is_stack_empty())
        {
            pop();
        }
    }
    // now getting the peak value
    void peak()
    {
        if (!is_stack_empty())
        {
            cout << "\nStack is empty;";
        }
        else
        {
            T value;
            Node_tem *curr = head;

            value = curr->data;
            cout << "\n Peak value is : " << value << "\n";
        }
    }
};

/*void recursive_function(stack_list<int,Node> &stacks){

    // Base Case
    if(!stacks.head->next){
        cout << stacks.pop();
        return;
    }else{
        // Recursion function
         // each time create a new stack and then get the
     //    stack_list<int,Node> temp;
      //   temp.push(stacks.pop());
         recursive_function(stacks);
         cout << stacks.pop() << " ";

    }

}*/

void recursive_function(stack_list<int, Node> &stacks)
{

    // Base Case
    if (stacks.is_stack_empty() == 0)
    {
        return;
    }
    else
    {
        // Recursion function
        // each time create a new stack and then get the
        int a = stacks.pop();
        
        recursive_function(stacks);
        cout << a;
    }
}
int main()
{

    stack_list<int, Node> a;
    cout << "\n Pushing the Following Values: \n";
    for (int i = 0; i < 10; i++)
    {
        a.push(i);
        cout << i << " ";
    }
    // now
    cout << "\nFollowing values are Poped \n";
    for (int i = 0; i < 5; i++)
    {
        int value = a.pop();
        cout << value << " ";
    }

    a.peak();

    cout << "\nChecking if empty \n";
    cout << a.is_stack_empty();

    cout << "\nClearing the Stack\n";
    a.clear();

    cout << "\nChecking if empty Again \n";
    cout << a.is_stack_empty();

    cout << "\n Starting of Task 2 \n";
    stack_list<char, Node> b;
    char arr[100] = "1.	1 + 2 * (3 / 4)\0";
    cout << "\n Do you want to enter your Own Expression ? \n1)yes\n2)No:";
    int flag = 0;
    cin >> flag;
    switch (flag)
    {
    case 1:
    {
        cout << "\n Give exPRESSION :";
        cin.ignore();
        cin >> arr;
    }
    break;
    case 2:
        cout << "\n checking test 2 in given \n";
        break;
    default:
        cout << "\n Invalid INput\n";
        cout << "\n checking test 2 in given \n";
        break;
    }
    // First of all Push all the elements Brackets
    bool test = true;

    for (int i = 0; arr[i] != '\0'; i++)
    {

        if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[')
        {
            b.push(arr[i]);
        }
    }
    // Now Iterate through the Char array and check if we could find matching

    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] == ')' || arr[i] == '}' || arr[i] == ']')
        {
            if (b.is_stack_empty() == 1)
            {

                char poped = b.pop();
                //  cout << poped << " nad " << arr[i] << "\n";
                /**/
                if (poped == '(' && arr[i] == ')')
                {
                    test = true;
                }
                else if (poped == '{' && arr[i] == '}')
                {
                    test = true;
                }
                else if (poped == '[' && arr[i] == ']')
                {
                    test = true;
                }
                else
                {
                    test = false;
                    break;
                }
            }
            else
            {
                test = false;
                break;
            }
            // cout << "\n Stack empty \n";
        }
    }

    if (test)
    {
        cout << "\n Test Successful \n";
    }
    else
    {
        cout << "\n Unsuccessful \n";
    }

    cout << "\n Final Stack \n";
    stack_list<int, Node> stacks;
    for (size_t i = 1; i <= 6; i++)
    {
        stacks.push(i);
        cout << i << " ";
    }

    recursive_function(stacks);
    return 0;
}