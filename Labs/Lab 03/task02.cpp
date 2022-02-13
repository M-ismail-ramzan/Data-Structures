#include <iostream>
using namespace std;


void reverse (int arr[], int size)
{
    // starting & ending index
	int start = 0;
	int end = size-1;

    // loop to run from start to end
	while(start<=end)
	{
		int swap = arr[start];
		arr[start] = arr[end];
		arr[end] = swap;
        // reducing & increasing index
		end--;
		start++;

	}
}

int main()
{

	const int SIZE = 7;
	int arr[SIZE] = {1,4,7,4,5,25,9};
    // Printing the array
	cout<<"Array is : "<<endl;
    for(int i=0 ; i<SIZE ;i++)
	{
		cout<<arr[i]<<" ";
	}
    // Function to reverse the array
	reverse(arr, SIZE);

    // Prining the Final array
	cout<<"\nReversed: "<<endl;
	for(int i=0 ; i<SIZE ;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}





