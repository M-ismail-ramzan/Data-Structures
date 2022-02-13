#include <iostream>
#include <string>
using namespace std;

int return_Ascii(char first)
{
    int idx = first - 97;
    return idx;
}
int main()
{
    // input data
    string first = "reoh";
    string second = "hero";
    // making an array of size 25 for all the ascii's
    int arr[26] = {0};
    // strore the length of each string
    int length_of_first = first.length();
    int length_of_second = second.length();
    // A loop for correcting the ascii of the array
    int first_index = 0;
    for (int i = 0; i < length_of_first; i++)
    {
        // get the index of all the strings..
        if (first[i] != NULL)
        {
            first_index = return_Ascii(first[i]);
        }
        // now we have the index.. let;s stroe them in the array
        arr[first_index]++;
    }

    for (size_t i = 0; i < 26; i++)
    {
        cout << arr[i] << " ";
    }
    
    int second_index = 0;
    // now checking for second array
    for (int i = 0; i < length_of_second; i++)
    {
        // get the index of all the strings..
        if (second[i] != NULL)
        {
            second_index = return_Ascii(second[i]);
        }
        // now we have the index.. let;s stroe them in the array
        arr[second_index]--;
    }

    cout << "\n";
        for (size_t i = 0; i < 26; i++)
    {
        cout << arr[i] << " ";
    }
    // now checking for anagram
    bool is_analogy = true;
    for (int i = 0; i < 26; i++)
    {
        if(arr[i] != 0){
            is_analogy = false;
            break;
        }
    }
    cout << "\n";
    cout << "The Given string is : " << is_analogy;

}