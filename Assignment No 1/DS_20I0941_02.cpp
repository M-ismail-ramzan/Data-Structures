/*
Muhammad Ismail Ramzan :)
20I-0941
*/

#include <iostream>
using namespace std;

// creating a dynamic array
int **create_dynamic_matrix(int row, int col)
{
    int **ptr = NULL;

    ptr = new int *[row];

    // now for each row i want to create an array of size col
    for (size_t i = 0; i < row; i++)
    {
        ptr[i] = new int[col];
    }
        // Taking the input from the User
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << "Please Enter the Value of Index at Row " << i << " & Column " << j << " :";
           // cin >> ptr[i][j];
            cin >> (*(*(ptr+i)+j));
        }
        cout << "\n";
    }
    return ptr;
}
// display row wise matrix
void display_row_matrix(int **ptr, int row, int col)
{
    cout << "\n------Row Wise Matrix is-----\n";
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << (*(*(ptr+i)+j))<< " ";
        }
    }

}
// display colum wise matrix
void display_col_matrix(int **ptr, int row, int col)
{

    cout << "\n------Col Wise Matrix is-----\n";

    for (size_t i = 0; i < col; i++)
    {
        for (size_t j = 0; j < row; j++)
        {
            cout << (*(*(ptr+j)+i)) << " ";
        }
        //cout << "\n";
    }
    
}
// multiply the matrices
void mulMat(int **ptr1,int row,int col, int **ptr2,int row2,int col2) {
    // Answer of any multiplication is
    // number of row of first and col of second so
     int **ptr = new int *[row];
    // now for each row i want to create an array of size col
    for (size_t i = 0; i < row; i++)
    {
        ptr[i] = new int[col2];
    }
    // checking the indexs of ptr pointer 2*3 & 3*2   --> 2*2
     for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
           (*(*(ptr+i)+j)) = j;
           // cout << ptr[i][j] << " ";
        }
        cout << " \n ";
    }
    

    cout << "\nMultiplication:\n";
   for (size_t i = 0; i < row; i++)
   {
       for (size_t j = 0; j < col2; j++)
       {
           int sum=0;
           for (size_t k = 0; k < col; k++)
           {
               sum = sum + ((*(*(ptr1+i)+k)) * (*(*(ptr2+k)+j)));
           }
           (*(*(ptr+i)+j)) = sum;
          cout <<(*(*(ptr+i)+j)) << " ";
       }
       cout << "\n";
   }
   
}

//dispaying the matrix
void display_matrix(int **ptr_arr,int row, int col){
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout <<(*(*(ptr_arr+i)+j))<< " ";
        }
        cout << "\n";
    }
    
    
}
void input_validation(int &n){
    while(true){
        cin >> n;
        if(n <= 0){
            cout << "\nInvalid Input.Please Enter Correct Input\nEnter: ";
        }else
        break;
    }
}
int main()
{

    // creating a pointer to hold the dynamic 2d array
    int **ptr;
    int **ptr2_arr;
    int **ptr3_arr;
    // varaibles
    int row = 0;
    int col = 0;
    // Let's get ROw and Col from the User for Matrix
    cout << "\nPlease Enter the Row Size : ";
    input_validation(row);
    cout << "\nPlease Enter the Col Size : ";
    input_validation(col);
    // calling the function to create the 2d Array in the Heap & return the Pointer
    ptr = create_dynamic_matrix(row, col);

    // Now displaying the Matrix to the User
    display_row_matrix(ptr, row, col);
    // Displaying col matrix
    display_col_matrix(ptr, row, col);

    cout << "\n --Multiplication--\n";
    // taking data for first matrix
    cout << "\n Enter Number of Rows for First Matrix: ";
    input_validation(row);
    cout << "\n Enter Number of Colums for First Matrix: ";
    input_validation(col);
    ptr2_arr = create_dynamic_matrix(row, col);
    // taking data for second matrix
    int rows = 0;
    int cols = 0;
    while (true)
    {
        cout << "\n Enter Number of Rows for Second Matrix: ";
        input_validation(rows);
        cout << "\n Enter Number of Colums for Second Matrix: ";
        input_validation(cols);
        // checking if user enters the correct matrix
        if (col == rows)
            break;
        else
        {
            cout << "\n\n---For multiplication Number of Cols of first matrix must be equal to rows of second matrix---\n";
        }
    }
    ptr3_arr = create_dynamic_matrix(rows, cols);
    // display matrix
    cout << "\nFirst Matrix\n";
    display_matrix(ptr2_arr,row,col);
    cout << "\nSecond Matrix\n";
    display_matrix(ptr3_arr,rows,cols);
    // multiplying 2 matrix
 mulMat(ptr2_arr,row,col,ptr3_arr,rows,cols);
 
     //Free each sub-array
    for(int i = 0; i < row; ++i) {
        delete[] ptr[i]; 
        delete[] ptr2_arr[i]; 
        delete[] ptr3_arr[i];   
    }
    //Free the array of pointers
    delete[] ptr;
    
}