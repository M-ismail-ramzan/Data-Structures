#include <iostream>
using namespace std;

bool Linear_search(int arr[3][4], int row,int col, int element_finding)
{
 

    //Rin the loop as the size of the loop 
    for (int i = 0; i < row; i++)
    {
        // run the loop as size of the column
        for (int j = 0; j < col; j++)
            //if the element is found
            if (arr[i][j] == element_finding)
            {
                cout << "Element Found\n";
                cout << "Position: [" << i << "][" << j << "]";
                return true;
            }
    }

    cout << "Element not found";
    return 0;
}

int main() {

    int arr[3][4] = {{12, 43, 66, 78},{ 34, 21, 72, 81 }, { 7, 13, 2, 59 }};
    Linear_search(arr,3,4,2);
  

}