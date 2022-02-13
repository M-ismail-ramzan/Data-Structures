#include <iostream>
#include <string>
using namespace std;

template <typename T>

T square(T A)
{
    T result = A * A;
    return result;
}
template <typename T1,typename T2>
T1 division(T1 A, T2 B)
{
    if (B != 0)
        return A / B;
    else
        return -1;
}
int main()
{
    float a = 10.9; int b = 3;
    // Here if we replace the datatype of varialbe a. it will return the same datatype
    cout << "\n Testing with float Data.\n";
    cout << " A square : " << square<float> (a) << endl;
    cout << "\nTesting with Int Data\n";
    a = 15;
    cout << " A square : " << square<int>(a) << endl;
    // Now if we change the datatype it will act accoordingly
    a=10.9;
    cout << "\nSquar Functions \n";
    // first argument as float and second as int
    cout << " A/B : " << division<float,int>(a, b) << endl;
    // first argument as float and second as int
    cout << " A square / B square : " << division <float,int>(square(a), square(b)) << endl;
}

for(int i=0;i<numSize;i++){
    char c;
    if(size[i] == false){
        cout << "Seat " << i + 1 << " is free";
    }
    cout << "Do you want to reserve this seat: ";
    cin >> c;
    if( c == 'y'){
        seat[i] = true;
        break;
    }else{
        cout << "\n Checking next seats ";
    }
}