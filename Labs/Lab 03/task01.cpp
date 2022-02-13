#include <iostream>
#include <cmath>

using namespace std;

int main()
{
int d=0;
// calculate to 1000
int n = 1000;
for(int a=0;a<n;a++)
{
	for(int b=0;b<n;b++)
	{
		for(int c=0;c<n;c++)
		{			
			d = pow((pow(a,3) + pow(b,3) - pow(c,3)) , 1/3 );
			if( (pow(a,3) + pow(b,3) == pow(c,3) + pow(d,3)) )
			{
                cout << " A: " << a << " B: " << b << " C: " << c << " D: " << d << "\n";
			}
		}
	}

}
return 0;

}
