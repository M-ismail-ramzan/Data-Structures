#include <iostream>
#include <stack>
using namespace std;
int main(){
    int x;
    cout << "\n Enter n: ";
    cin >> x;

    string y;
    // Enter string
    cout << "\n Enter string:";
    cin >> y;

    // checking if it is valid or not
    int i=0;
    bool is_valid = true;
     stack<string> sta;
    while (y[i]!=NULL)
    {
       
        // push the ( bracket in stack and pop the closing!!!
        if(y[i] == '('){
            sta.push("(");
        }
        if(y[i] == ')'){
            string test = sta.top();
            // check the test
            if(test != "("){
                is_valid = false;
                break;
            }
            sta.pop();
        }
    }
    if (!sta.empty()){
        is_valid = false;
    }
    
}