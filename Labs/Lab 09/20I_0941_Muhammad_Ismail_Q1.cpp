#include <iostream>

using namespace std;


void merge(int Array[], int strt, int mid, int end , int& count)
{
    
    //mid + 1 will be passed in the variable mid when the function is called
    int *result = new int[end-strt+1]; // allocate temporary array
    int array1_index = strt, array2_index = mid;
    int i=0; //index for result array
    while( array1_index < mid && array2_index <= end )
    {
        
        if(Array[array1_index]<=Array[array2_index])
        {
            result[i++] = Array[array1_index++]; //post increment
        }
        else
        {
            result[i++] = Array[array2_index++]; //post increment   
        }
        count++;
    }
            
    while( array2_index <= end ) // copy remaining elements from array 2
        result[i++] = Array[array2_index++];
    while( array1_index < mid ) // copy remaining elements from array 1
        result[i++] = Array[array1_index++];
   
    // copying elements from temporary array to "Array"
    for(i=0; i < end-strt+1; i++) //end-strt +1 = array size
        Array[strt+i] = result[i];   
    delete []result; // de-allocate memory 

}

void mergeSort(int arr[], int first, int last, int & count)
{
    if (first < last) //List size is greater than 1
    {
        
        int mid = (first + last) / 2;
        mergeSort(arr, first, mid , count);    //Split for first half
        mergeSort(arr, mid + 1, last, count); //Split for second half
        merge(arr, first, mid + 1, last, count);
    }
}


int main()
{
    const int SIZE = 5;
    int a[SIZE] = { 5,4,3,2,1};
    int count = 0;

    mergeSort(a ,0 ,SIZE, count );

    cout<<count<<endl;
    for(int i = 0; i<SIZE ; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
