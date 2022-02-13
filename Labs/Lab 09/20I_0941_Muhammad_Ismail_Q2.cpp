
#include <iostream>
#include <algorithm>
using namespace std;

int Make_partition(int arr[], int size)
{
    
    int pivot = 0;
    // j index to points the positive values
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        // if u see negative number.. swap them
        if (arr[i] < pivot)
        {
            
            swap(arr[i], arr[j]);
            j++;
        }
    }
    return j;
}

void Arrange_elements(int arr[], int size)
{

    int p = Make_partition(arr, size);

    // after rearranging the elements let's swap them :)
    for (int n = 0; (p < size && n < p); p++){
        swap(arr[n], arr[p]);
        n= n+2;
    }
        
}

int main()
{
    int array[] = {9, -3, 5, -2, -8, -6, 1, 3};
    int n = sizeof(array) / sizeof(array[0]);
    // arrange the array
    Arrange_elements(array, n);
    // show the output!
    for (int i = 0; i < n; i++)
    {
        cout << " " << array[i];
    }

    return 0;
}