#include <iostream>
#include <string>
using namespace std;

// Function to print all the elements of the array;
template <typename T1,typename T2>
void Print(T1 arr1[], T2 size_A) {


    for (T2 i = 0; i < size_A; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << "\n";
}
template <typename T1, typename T2>
void Union(T1 arr1[], T2 size_A, T1 arr2[], T2 size_B) {

    // Printing the element of first array
    for (size_t i = 0; i < size_A; i++)
    {
        cout << arr1[i] << " ";
    }
    // now Removing the same elements in the array2
    for (size_t i = 0; i < size_B; i++)
    {
        bool test = false;
        for (size_t j = 0; j < size_A; j++)
        {
            // if element of array1 is equal to any elemet of array2  then do not print it
            if (arr2[i] == arr1[j])
            {
                test = true;
                break;
            }
        }
        // if test is false ( we do not find element in array1 then print it)
        if (!test) {
            cout << arr2[i] << " ";
        }
    }

}
template <typename T1, typename T2>
void Intersection(T1 arr1[], T2 size_A, T1 arr2[], T2 size_B) {

    for (size_t i = 0; i < size_A; i++)
    {
        bool test = false;
        for (size_t j = 0; j < size_B; j++)
        {
            // each element of array1 will be scanned if it is present in array2
            if (arr1[i] == arr2[j])
            {
                test = true;
                break;
                // if it is present in array2. We need to Print it

            }
        }
        if (test) {
            cout << arr1[i] << " ";
        }
    }


}
template <typename T1, typename T2>
bool Disjoint(T1 arr1[], T2 size_A, T1 arr2[], T2 size_B) {
    for (size_t i = 0; i < size_A; i++)
    {
        for (size_t j = 0; j < size_B; j++)
        {
            // each element of array1 will be scanned if it is present in array2
            if (arr1[i] == arr2[j])
            {
                return 0;
                // if it is present in array2 then it means it is not disjoint

            }
        }
    }
    return 1;
}
template <typename T1, typename T2>
bool Find_elements(T1 arr1[], T2 size) {
    if (size == 0) {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    float A[] = { 10.43,4.3,5.61,6.90,11.57,12.11,3.8,2.4,9.5 };
    float B[] = { 11.01,12.34,16.5,3.8,8.1,2.4,9.11,12.11,6.75,10.43,20.2,2.1,4.3 };
    // Finding the Length of each Array
    int len_A = sizeof(A) / sizeof(A[0]);
    int len_B = sizeof(B) / sizeof(B[0]);
    cout << "\n Length of Array A is:" << len_A;
    cout << "\n Length of Array B is:" << len_B;
    // Calling the Print function
     // Print the Elemets of first Array
    cout << "\nElements of Array A is: ";
    Print<float,int>(A, len_A);
    // Print the Elemets of first Array
    cout << "Elements of Array B is: ";
    Print<float, int>(B, len_B);

    // Union
    cout << "\n Union of Set is : ";
    Union<float, int>(A, len_A, B, len_B);

    // Intersection
    cout << "\n Intersection of Set is : ";
    Intersection < float, int>(A, len_A, B, len_B);

    //Disjoint Check
    cout << "\n Checking for Disjoint set: \n";
    bool is_disjoint = Disjoint< float, int>(A, len_A, B, len_B);
    if (is_disjoint) {
        cout << "Sets are Disjoints";
    }
    else
    {
        cout << "Sets are not Disjoints";
    }

    // checking empty set
    bool is_Element_preent = Find_elements< float, int>(A, len_A);
    if (is_Element_preent) {
        cout << "\n Element Exist in set A";
    }
    else
    {
        cout << "\n Element does not exist in set A";
    }
}