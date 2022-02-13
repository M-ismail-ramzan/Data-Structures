/*
Muhammad Ismail Ramzan :)
20I-0941
*/

#include <iostream>
#include <string>
using namespace std;
// function for input validation
void input_validation(int &n){
    while(true){
        cin >> n;
        if(n <= 0){
            cout << "\nInvalid Input ( no -ve numbers for now ).Please Enter Correct Input\nEnter: ";
        }else
        break;
    }
}
// Function to Print a pARTICULAR aRRAY
void print_single_employee(int max_index,  int hours[],  int complained_resolved[], string csrID[], string csrName[], float payrate[], float wages[])
{
    cout << "\n----------------------------\n";
    cout << "\nID: : " << csrID[max_index];
    cout << "\nName: " << csrName[max_index];
    cout << "\nHours Worked: " << hours[max_index];
    cout << "\nComplained Solved: " << complained_resolved[max_index];
    cout << "\nPayrate : " << payrate[max_index];
    cout << "\nWages : " << wages[max_index];
    cout << "\n----------------------------\n";
}
// Function to Calculate the Maximum & return the final index
template <typename T>
int max_index_finder(T arr[], int size)
{
    // Variables to find the maximum hours
    int max_index = 0;
    int max_hours = 0;
    // Loop to find max index & hours
    for (size_t i = 0; i < size; i++)
    {
        // if max_hours are less. it will loop through each element of array
        if (max_hours < arr[i])
        {
            max_hours = arr[i];
            // save the max index
            max_index = i;
        }
    }
    return max_index;
}
int main()
{
    short const SIZE = 7;
    short payrate_constant = 25;
    // making the Array'es
    // Alternatively i can make a class but i don't think it's needed lol..
    string csrID[SIZE];
    string csrName[SIZE];
    int hours[SIZE];
     int complained_resolved[SIZE];
     float payrate[SIZE];
     float wages[SIZE];
    // Asking User to enter the data
    int total_complained_resolved = 0;
    for (size_t i = 0; i < SIZE; i++)
    {
        //Let's get te data in each Array!
        csrID[i] = "CSR_0" + to_string(i + 1);
        cout << "\nPlease Enter the Name of " << csrID[i] << " Emplyee:";
        cin >> csrName[i];
        cout << "Please Enter the Hours of " << csrID[i] << " Emplyee:";
        input_validation(hours[i]);
        cout << "Please Enter the Number of Complained Resolved of " << csrID[i] << " Emplyee:";
        input_validation(complained_resolved[i]);
        // calculating total number of Complained
        total_complained_resolved = total_complained_resolved + complained_resolved[i];
        cout << "\n---------------------------------------------\n";
    }
    cout << endl;
    // Displaying the Final Data
    for (size_t i = 0; i < SIZE; i++)
    {
        // calculating the payrate
        payrate[i] = payrate_constant + (payrate_constant * (float(complained_resolved[i] / float(total_complained_resolved))));
        // calculating the wages
        wages[i] = payrate[i] * hours[i];
        // Displaying the Final Result
        cout << "\n----------------------------\n";
        cout << "ID: " << csrID[i] << "\n";
        cout << "Name: " << csrName[i] << "\n";
        cout << "Hours : " << hours[i] << "\n";
        cout << "Complained Resolved: " << complained_resolved[i] << "\n";
        cout << "Payrate: " << payrate[i] << "\n";
        cout << "wages: " << wages[i] << "\n";
    }
    // Now showing the Top Client!
      short answer = 0;
    do
    {
      
        cout << "\n Visit the TOP Employee on Basis of ( no charater or string allowed to enter) \n";
        cout << "1) Hours Worked\n";
        cout << "2) Complained Resolved\n";
        cout << "3) Payrate\n";
        cout << "4) Exit\nEnter:";
        cin >> answer;
        switch (answer)
        {
        case 1:
        {
            // calling functions to do it's job! :)
            int max_index = max_index_finder< int>(hours, SIZE);
            print_single_employee(max_index, hours, complained_resolved, csrID, csrName, payrate, wages);

            break;
        }
        case 2:
        {
            // calling functions to do it's job! :)
            int max_index = max_index_finder< int>(complained_resolved, SIZE);
            print_single_employee(max_index, hours, complained_resolved, csrID, csrName, payrate, wages);

            break;
        }
        case 3:
        {
            // calling functions to do it's job! :)
            int max_index = max_index_finder<float>(payrate, SIZE);
            print_single_employee(max_index, hours, complained_resolved, csrID, csrName, payrate, wages);

            break;
        }
        case 4:{
            cout << "\n Exiting..";
            break;
        }
        default:
        {
            cout << "\n Invalid Input";
            break;
        }
        }
    } while (!(answer == 4));
}