#include <iostream>
using namespace std;

int return_Ascii(char first)
{
    int idx = first - 97;
    return idx;
}

char return_charater(int index)
{
    char idx = index + 97;
    return idx;
}
int main()
{

    int set_A[4] = {'a', 'b', 'c', 'd'};
    int set_B[4] = {'d', 'e', 'a', 'b'};

    // making an array of size 26 for all the ascii's
    bool arr[26] = {0};
    // strore the length of each string
    int length_of_first = 4;
    int length_of_second = 4;
    cout << "\nUnion of the Sets is \n";
    for (int i = 0; i < length_of_first; i++)
    {
        // get the ascii of the charater
        int correct_index = return_Ascii(set_A[i]);
        arr[correct_index] = true;
        correct_index = return_Ascii(set_B[i]);
        arr[correct_index] = true;
    }

    // Printing the Union of the Sets.
    for (int i = 0; i < 26; i++)
    {
        // get the ascii of the charater
        if (arr[i] == true)
        {
            cout << return_charater(i) << " ";
        }
        // making false for intersection..
        arr[i] = false;
    }

    // For the Intersetion
    cout << "\nIntersection of the Sets is \n";
    // ptting setA elemetn in the array
    for (int i = 0; i < length_of_first; i++)
    {
        // get the ascii of the charater
        int correct_index = return_Ascii(set_B[i]);
        arr[correct_index] = true;
    }
    // Let's go and find the intersection!!!
    for (int i = 0; i < length_of_second; i++)
    {
        // get the common elemetns
        int correct_index = return_Ascii(set_A[i]);
        if(arr[correct_index] == true){
            cout << return_charater(correct_index) << " ";
        }
    }
    
}