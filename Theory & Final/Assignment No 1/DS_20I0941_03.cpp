
/*
Muhammad Ismail Ramzan :)
20I-0941
*/

#include <iostream>
using namespace std;

void input_validation(int &n){
    while(true){
        cin >> n;
        if(n <= 0){
            cout << "\nInvalid Input ( no -ve numbers for now ).Please Enter Correct Input\nEnter: ";
        }else
        break;
    }
}

// taking the input from the user
void input_sort(int *ptr, int size)
{
    cout << "\nPlease Enter the Elements of Array: \n";
    for (size_t i = 0; i < size; i++)
    {
        cout << "Please Enter Value at index " << i << " of array: ";
        
        // checking that user always enter in ascending order
        while(true){
             // allow
             input_validation(ptr[i]);
            if(i != 0 && ptr[i] <= ptr[i-1]){
                cout << "\n Please Write in Ascending Order\nEnter Again: ";
            }else{
                break;
            }
           
        }
    }
}

int *sort_two_array(int *arr_1, int first_size, int *size_ptr)
{
    // inputting 2nd array
    int size = 0;
    cout << "\nPlease Enter the Size of the Array:";
    input_validation(size);
    //inputing the array
    int *arr_2 = new int[size];
    input_sort(arr_2, size);
    int index = 0;
    for (size_t i = 0; i < first_size; i++)
    {
        if (arr_1[i] > arr_2[index])
        {
            int temp = arr_2[index];
            arr_2[index] = arr_1[i];
            arr_1[i] = temp;
            // now sort the second array
            int value = arr_2[index];
            for (size_t j = 0; j < size; j++)
            {
                // it will make sure that the second array is sorted so we don't need to do much work
                if (value > arr_2[j])
                {
                    int temp = arr_2[j];
                    arr_2[j] = arr_2[index];
                    arr_2[index] = temp;
                    index = index + 1;
                }
            }
        }
        index = 0;
    }

    // display
    for (size_t i = 0; i < first_size; i++)
    {
        cout << arr_1[i] << "  ";
    }
    // display
    cout << "\n";
    for (size_t i = 0; i < size; i++)
    {
        cout << arr_2[i] << "  ";
    }
    // making final array
    int *finalize_arr = new int[first_size + size];
    index = 0;
    for (size_t i = 0; i < first_size; i++)
    {
        finalize_arr[i] = arr_1[i];
        index++;
    }
    for (size_t i = index, j = 0; i < index + size; i++, j++)
    {
        finalize_arr[i] = arr_2[j];
    }
    *(size_ptr) = first_size + size;
    return finalize_arr;
}
void remove_duplicates(int *ptr, int *size_ptr)
{
    
    int size = *size_ptr;
    /*
    cout << "Size: " << *size_ptr << "   ";
    // checking for duplicates
    for (size_t i = 0; i < (size); i++)
    {
        cout << "\n";
        for (size_t j = 1; j < (size); j++)
        {
            cout << "I : " << i << " while J is: " << j << " ";
            if (ptr[i] == ptr[j])
            {
                int temp = ptr[size-1];
                ptr[size-1] = ptr[i];
                ptr[i] = temp;
                size--;
            }
        }
    }
*/
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size;)
        {
            if (ptr[i] == ptr[j])
            {
                for (int k = j; k < size - 1; ++k)
                    ptr[k] = ptr[k + 1];
                --size;
            }
            else
                ++j;
        }
    cout << "\n";
    /* cout << "\nFinal2";
    for (size_t i = 0; i < size; i++)
    {
        cout << ptr[i] << " ";
    }*/
    int start=0;
    int end=size-1;
    while (start < end)
    {
        int temp = ptr[start];
        ptr[start] = ptr[end];
        ptr[end] = temp;
        start++;
        end--;
    }
    // showing the final array!
     cout << "\nFinal Array: ";
     cout << "\n----------------------\n";
        for (size_t i = 0; i < size; i++)
    {
        cout << ptr[i] << " ";
    }
    cout << "\n----------------------\n";
   /* cout << "\nFinal";
    for (size_t i = 0; i < *size_ptr; i++)
    {
        cout << ptr[i] << " ";
    }*/
}

int main()
{
    int no_of_arr = 0;
    cout << "\nPlease Enter the Number of Arrays You want to sort: ";
    input_validation(no_of_arr);
    no_of_arr = no_of_arr - 1;
    int *ptr = NULL;
    // for each array i want the input & sort it!
    int first_size = 0;
    cout << "\nPlease Enter the Size of the Array:";
    input_validation(first_size);
    //inputing the array
    ptr = new int[first_size];
    input_sort(ptr, first_size);
    int *final = NULL;
    int *size_ptr = new int;
    for (size_t i = 0; i < no_of_arr; i++)
    {
        // Now i will do some sorting mechanism
        if (i == 0)
        {
            final = sort_two_array(ptr, first_size, size_ptr);
        }
        else
        {
            first_size = *size_ptr;
            final = sort_two_array(final, first_size, size_ptr);
        }
    }
    cout << "\n";
/*
    for (size_t i = 0; i < *size_ptr; i++)
    {
        cout << final[i] << " ";
    }
    */
  //  cout << "Error";
    // Now we will Remove the Duplicates
    remove_duplicates(final, size_ptr);
    delete[] ptr;
    delete[] final;
};