#include <iostream>
#include <string>
using namespace std;
template <class T1,class T2>
class Numbers {
private:
	T1 A; T2 B;
public:
	Numbers(T1 A1, T2 B1)
	{
		A = A1;
		B = B1;
	}
	T1 Asquare()
	{
		T1 result = A * A;
		return result;
	}
	T1 division()
	{
		if (B != 0)
			return A / B;
		else
			return 0;
	}
};
int main()
{
	Numbers <float,int>num(10.9, 3);
	cout << " A square : " << num.Asquare() << endl;
	cout << " A/B : " << num.division() << endl;
}
