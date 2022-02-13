/*
Muhammad Ismail Ramzan :)
20I-0941
*/
const int ROW = 30;
const int COL = 30;
#include <iostream>
#include <time.h>
using namespace std;
int live_neighbours(char arr[ROW][COL], int i, int j)
{
    int len = 0;
    // checking for each dimention..
    if (arr[i - 1][j] == '*')
    {
        len++;
    }
    if (arr[i - 1][j + 1] == '*')
    {
        len++;
    }
    if (arr[i - 1][j + 1] == '*')
    {
        len++;
    }
    if (arr[i][j + 1] == '*')
    {
        len++;
    }
    if (arr[i + 1][j + 1] == '*')
    {
        len++;
    }
    if (arr[i + 1][j] == '*')
    {
        len++;
    }
    if (arr[i + 1][j - 1] == '*')
    {
        len++;
    }
    if (arr[i][j - 1] == '*')
    {
        len++;
    }
    if (arr[i - 1][j - 1] == '*')
    {
        len++;
    }
    return len;
}
int main()
{
    srand(time(NULL));
  
    char arr[ROW][COL];
         // making a new array to test for the cases
          char arr2[ROW][COL];
    // Loop through the each index
    for (size_t i = 0; i < ROW; i++)
    {
        for (size_t j = 0; j < COL; j++)
        {
            // randomly assinging active & dead cells
            if (rand() % 30 >= 15)
                arr[i][j] = '*';
            else
                arr[i][j] = ' ';
            cout << arr[i][j] << " ";
            arr2[i][j] = arr[i][j];
        }
        cout << "\n";
    }

    while (true)
    {
         cout << "\n Type Anything & Press Enter to see the Next Generation! ";
        // Now i need to loop through the each cell & checking it's neibouring cells
        string answer;
        cin >> answer;
        
        // copying the new array to the previous array
        for (size_t i = 0; i < ROW; i++)
        {
            for (size_t j = 0; j < COL; j++)
            {
                arr2[i][j] = arr[i][j];
            }
            
        }
        
        //testing for the Rules
        for (size_t i = 0; i < ROW - 1; i++)
        {
            for (size_t j = 0; j < COL - 1; j++)
            {
               cout << arr[i][j] << " ";
                 
                 
                // checking for each cell ignoring those which are at the corners
                if (arr[i][j] == '*')
                {
                    // A function will return the live neigbours
                    int len = live_neighbours(arr2, i, j);
                   
                    // checking for length
                    
                    if (len == 0 || len == 1)
                    {
                        arr[i][j] = ' ';
                    }
                    else if (len == 2 || len == 3)
                    {
                        arr[i][j] = '*';
                    }
                    else
                    {
                        arr[i][j] = ' ';
                    }
                }
                // cehcking for dead cells
                else
                {
                    int len = live_neighbours(arr2, i, j);
                    if (len == 3)
                    {
                        arr[i][j] = '*';
                    }
                }

               
            }
            cout << "\n";
           
        }
    }
}