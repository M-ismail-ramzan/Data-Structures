#include <iostream>
using namespace std;
bool binSearchOnMatrix(int matrix[][4], int Row, int Col, int key);
int main()
{
    const short Row = 4;
    const short Col = 4;
    int arr[Row][Col] = { {10, 20, 30, 40},{15, 25, 35, 45},{27, 29, 37, 48},{32, 33, 39, 50} };
    int target=29; //search key
    binSearchOnMatrix(arr,4,4,target);
}

bool binSearchOnMatrix(int matrix[][4],int Row, int Col, int key)
{
    // as array is sorted column wise :)
    int col_Size = Col;
    int row_Size = Row;
    // let's start finding from the last elemetn
  
    for (size_t j = col_Size ; j > 0; j--)
    {
        for(size_t i = 0; i< row_Size; i++)
        {
            // check the last Column of each row.. if it's greater than target! then we don't need to search for that Colomn
            
            if (matrix[i][j] > key)
            {
                // ignore that col
                break;
            }
            // now see for the object
            else if(matrix[i][j] == key){
                cout << "Element found at Index:";
                cout <<"[" << i  <<"]" << "[" << j << "]" << "\n";
                return true;
            }
        }

    }
    cout << "Element not Found!";
    return false;
}
