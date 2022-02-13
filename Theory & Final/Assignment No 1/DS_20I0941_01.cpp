/*
Muhammad Ismail Ramzan :)
20I-0941
*/

#include <iostream>
using namespace std;

int *create_get_array(int size)
{
    // let's create a array on the heap
    int *ptr;
    // array creating of size in heap
    ptr = new int[size];
    // taking vlaues into array from user
    for (size_t i = 0; i < size; i++)
    {
        cout << "Please Enter the Element for Index " << i << ": ";
        cin >> *(ptr + i);
    }
    // let's return the Pointer
    return ptr;
}

int avg_calculate(int *ptr, int size)
{
    // now ptr points to the memory
    int sum = 0;
    // calculating the avarge
    for (size_t i = 0; i < size; i++)
    {
        sum = sum + *(ptr + i);
    }
    // divide sum by no.of size to get the element
    return (sum / size);
}
int main()
{
    // making a Pointer to Point to the array
    int *ptr;
    // size variable to store the size
    short size = 0;
    // ask user to enter the size of the array
    cout << "\n -- Please enter the size of the Array:";
    // doing some input validation
    while(true){
        cin >> size;
        if(size <= 0){
            cout << "\n--Invalid Input. Please enter Correct Size--\nEnter: ";
        }else
        break;
    }
    
    // calling the function to create a dynamic memory for me & take values from user & then return me the the Values
    ptr = create_get_array(size);
    // Now let's calculate the avarge of each element
    int avg = avg_calculate(ptr, size);
    cout << "\n ----Avarge is: " << avg << "----- \n";
    // once i got the avg, let's remove the Memory
    delete[] ptr;
    ptr = NULL;
}