#include <iostream>
using namespace std;
// size can be taken from the user
const int Size = 20;

class List
{
    int *arr;
    int end_index;
public:
    //  constructor to initize all the values
    List()
    {
        end_index = 0;
        // making
        arr = new int[Size];
        for (size_t i = 0; i < Size; i++)
        {
            arr[i] = 0;
        }
    }
    // insert an element at the end of the array
    void insert_at_end(int num)
    {
        arr[end_index] = num;
        end_index++;
    }
    // display the elements of the array
    void display()
    {
        cout << "\n----------------------------------\n";
        cout << "\nArray Elements\n";
        for (size_t i = 0; i < end_index; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n--------------------------------------\n";
    }
    //
    void insert_at_start(int num)
    {
        // first of all we have to right shift all the elements

        for (int i = end_index; i >= 0; i--)
        {

            arr[i + 1] = arr[i];
        }
        arr[0] = num;
        end_index++;
    }
    // function to insert at any position in the array
    void insert_at_position(int num, int position)
    {
        if (position > end_index && position <= -1)
        {
            cout << "\nInvalid Position\n";
        }
        else
        {
            for (int i = end_index; i >= position; i--)
            {
                arr[i + 1] = arr[i];
            }
            arr[position] = num;
            end_index++;
        }
    }
    // remove an element from the array
    void remove_element(int data)
    {
        int position = -1;
        // finding the position of the elemet to be removed
        for (int i = 0; i < end_index; i++)
        {
            if (arr[i] == data)
            {
                position = i;
                break;
            }
        }
        if (position != -1)
        {
            // removeing the element at the position
            for (int i = position; i < end_index; i++)
            {
                arr[i] = arr[i + 1];
            }
            end_index--;
        }
        else
        {
            cout << "\n Data did not found in the array \n";
        }
        
    }
    // check if the array is empty
    bool is_empty()
    {
        if (end_index == 0)
            return true;
        else
            return false;
    }
    // Replacing the element
    void replace_Element(int num, int data)
    {
        
         int position = -1;
        // finding the position of the elemet to be removed
        for (int i = 0; i < end_index; i++)
        {
            if (arr[i] == data)
            {
                position = i;
                break;
            }
        }
        if (position != -1)
        {
            // placing the element at the position
            arr[position] = num;
            
        }
        else
        {
            cout << "\n Data did not found in the array \n";
        }
    }
    // clear the list
    void clear_list()
    {
        for (size_t i = 0; i < Size; i++)
        {
            arr[i] = 0;
        }
        end_index = 0;
        cout << "";
    }
    // code to sort the elements of the array
    void sort()
    {
        for (size_t i = 0; i < end_index; i++)
        {
            for (size_t j = 0; j < end_index - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
     
    }
    // search for a particular value
    int search(int data)
    {
        int position = 0;
        bool flag = false;
        // finding the position of the elemet to be removed
        for (int i = 0; i < end_index; i++)
        {
            if (arr[i] == data)
            {
                position = i;
                flag = true;
                break;
            }
        }
        // returning the index
        if (flag)
        {
            return position;
        }
        else
        {
            return -1;
        }
    }
    // checking if elements are duplicating
    bool duplicate()
    {
        int flag = false;
        for (size_t i = 0; i < end_index; i++)
        {
            for (size_t j = 0; j < end_index; j++)
            {
                if (arr[i] == arr[j] && j != i)
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
            return true;
        else
            return false;
    }

    ~List(){
        delete[] arr;
        arr = NULL;
    }
};
int main()
{
    List obj;
    // inserting the elements into array at end
    cout << "\n Inserted Elements into the end of array \n";
    obj.insert_at_end(4);
    obj.insert_at_end(5);
    obj.insert_at_end(5);
    obj.insert_at_end(6);
    obj.insert_at_end(6);
    obj.insert_at_end(7);
    obj.display();
    cout << "\n Inserted Elements into the start of array \n";
    obj.insert_at_start(1);
    obj.insert_at_start(3);
    obj.display();
    cout << "\n Inserting elements into a position (3 num and at 2 positon) ";
    obj.insert_at_position(3, 2);
    obj.display();
    cout << "\n Removing Element from the Array ( 6 ) \n";
    obj.remove_element(6);
    obj.display();
    // 
    cout << "\n Checking For empty of Array \n";
    cout <<  obj.is_empty() << " ";
    cout << "\n Replacing the elements of the Array ( element 5 replace by 4 )\n";
    obj.replace_Element(4,5);
      obj.display();
    cout << "\n Sorting the Array \n";
    obj.sort();
    obj.display();
    cout << "\n Searching for Data in the Array & returning it's index \n";
    int index = obj.search(4);
    cout << "\nFound at Index: " << index << " ";
    obj.display();
    cout << "\n Check for duplicates in the Array \n";
    int ans = obj.duplicate();
    cout << "\n Is Duplicate Found:"<< ans;
    obj.display();
    cout << "\n Clearing the List \n";
    obj.clear_list();
    obj.display();
}