#include <iostream>
#include <string>
using namespace std;

int return_me_max(int arr[],int size){
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

int return_me_min(int arr[],int size){
    int max = 99999;
    for (int i = 0; i < size; i++)
    {
        if(arr[i] < max)
            max = arr[i];
    }
    return max;
}

int return_me_correct_index(int x ,int min){
    int y = x - min;
    return y;
}
int main()
{
    const int FIRST_ARRAY_SIZE = 15;
    const int SECOND_ARRAY_SIZE = 4;
    int first[15] = {5, 8, 9, 3, 5, 7, 1, 3, 4, 9, 3, 5, 1, 8, 4};
    int second[4] = {3, 5, 7, 2};
    // making an array of size 25 for all the ascii's
 
    int maximum_index = return_me_max(first,FIRST_ARRAY_SIZE);
    cout << "Maximum Value  is : " << maximum_index << " \n";

    // find min here..
    int minimum_index = return_me_min(first,FIRST_ARRAY_SIZE);
    cout << "Minimum Value  is : " << minimum_index << " \n";

    int array_Size = maximum_index - minimum_index + 1;
    cout << "Size of the Array is: " << array_Size << "\n";
    int *arr = new int[array_Size];
    for (size_t i = 0; i < array_Size; i++)
    {
        arr[i] = 0;
    }
    
    // find max here..

    // int first_index = 0;
    for (int i = 0; i < FIRST_ARRAY_SIZE; i++)
    {   
        int correct_index = return_me_correct_index(first[i],minimum_index);
        // now we have the index.. let;s stroe them in the array
       // int x =first[i];
        arr[correct_index]++;
        //arr[correct_index]++;
    }

    for (size_t i = 0; i < array_Size; i++)
    {
        cout << arr[i] << " ";
    }
    
    // now checking for second array
    cout << "\n";
    int print_x_times = 0;
    for (int i = 0; i < 4; i++)
    {
        int print_x_times = 0;
        int correct_index = return_me_correct_index(second[i],minimum_index);
        int x = second[i];
        if (arr[correct_index] != 0)
        {
            print_x_times = arr[correct_index];
            arr[correct_index] = 0;
        }
       // cout << "Print tines"  << print_x_times << "\n";
        //  now print the numbers
        for (int i = 0; i < print_x_times; i++)
        {   
            // here i need to print the correct value..
            cout << x << " ";
            //cout << correct_index;
        }
    }

    // Am printing the second array --> Remaining Elements
    for (int i = 0; i < array_Size; i++)
    {
        int print_x_times = 0;
      //  int correct_index = return_me_correct_index(first[i],minimum_index);
      //int x = first[i];
        if (arr[i] != 0)
        {
            //if(array_Size-1 == )
            print_x_times = arr[i];
            //cout << "Print x : " << print_x_times << " \n";
            arr[i] = 0;
        }
       // cout << "Print tines"  << print_x_times << "\n";
        //  now print the numbers
        for (int j = 0; j < print_x_times; j++)
        {   
           // int correct_index = i + minimum_index;
            // here i need to print the correct value..
            cout << i + minimum_index << " ";
            //cout << correct_index;
        }
    }
}