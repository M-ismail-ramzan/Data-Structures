#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{

   //creating the file...
        ofstream test;
        string name = to_string(7) + "-data.txt";
        test.open(name);
        if (!test)
        {
            cout << "\n Unavle to open file \n";
        }

         int number_of_lines = 0;
        string line;
         name = to_string(7) + "-data.txt";
        cout << " Nmae is " << name << " ";
        ifstream myfile;
        myfile.open(name,ios::out);
        if (!myfile)
        {
            cout << "\n Unable to Open file \n";
        }
        else
        {
            while (getline(myfile, line))
                ++number_of_lines;
            number_of_lines = number_of_lines + 3;
        }

        cout << "No of lines is:  " << number_of_lines << " ";
        ofstream file;
        file.open(name);
        if (!file)
        {
            cout << "\n Unavle to open file \n";
        }
        else
        {
            file << "something" << endl;
                cout << "ahta";
                // for the line
        }
    return 0;
}