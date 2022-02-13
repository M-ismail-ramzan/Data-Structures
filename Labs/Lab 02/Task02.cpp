#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void send_me_neighbours(char arr[][30], int size) {

	// now i will check for neighbours for each & will return the number
	for (size_t i = 1; i < 30; i++)
	{
		int nei = 0;
		for (size_t j = 1; j < 30; j++)
		{
			// so checking the each neighbour one by one
			if (arr[i][j] == '*') {
				
				if (arr[i + 1][j] == '*') {
					nei = nei + 1;
				}
				if (arr[i-1][j] == '*') {
					nei = nei + 1;
				}
				if (arr[i][j+1] == '*') {
					nei = nei + 1;
				}
				if (arr[i][j-1] == '*') {
					nei = nei + 1;
				}
				if (arr[i + 1][j+1] == '*') {
					nei = nei + 1;
				}
				if (arr[i - 1][j-1] == '*') {
					nei = nei + 1;
				}
				if (arr[i + 1][j-1] == '*') {
					nei = nei + 1;
				}
				if (arr[i - 1][j + 1] == '*') {
					nei = nei + 1;
				}
			}
			
		}

		// i have counted the Neigbours
			// now i just need to implement dead & alive conditions.
		if (nei == 0 || nei == 1) {
			// Underpopulation
		}
		else if(nei == 2 || nei == 3)
		{
			//  Neighbourhood 
		}
		else if (nei == 3) {
			// Overpopulation
		}
		else {
			// here ant dead cell will become alive
		}
	}
}
int main()
{
	
	char arr[30][30];

	
	for (size_t i = 1; i < 29; i++)
	{
		for (size_t j = 1; j < 29; j++)
		{
			// setting dead and alive cells
			if (rand() % 100 < 60) {
				arr[i][j] = '*';
				//arr[i][j] = ' ';
			}
			else
			{
				arr[i][j] = ' ';
				//cout << "  ";
			}
			//cout << endl;
		}
	}
	// printing the array to see what's going on
	for (size_t i = 1; i < 29; i++)
	{
		//cout << "|";
		for (size_t j = 1; j < 29; j++)
		{
			cout << arr[i][j] << "      ";
		}
		cout << "\n";
	}

	// now we have to check for each cell weather it's alive or not
	// Let's start from the First one


			// So My logic is that i will create a function that will send me the neighbours..
	while (true) {
		send_me_neighbours(arr,30);
	}
			

            /// Not printing right but almost got the idea..

			

			
}