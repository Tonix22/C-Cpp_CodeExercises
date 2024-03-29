#include <vector>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int str_math(int A_int,int B_int, string OP)
{
    int res = 0;
    if(OP.c_str()[0]=='+')
    {
        res = A_int + B_int; 
    }
    else if(OP.c_str()[0]=='-')
    {
        res = A_int - B_int; 
    }
    else if(OP.c_str()[0]=='*')
    {
        res = A_int * B_int; 
    }
    else if(OP.c_str()[0]=='/')
    {
        res = A_int / B_int; 
    }

    return res;
}
int evalRPN(vector<string> &A)
{
     stack<int> tempdata;
     int save_top;
     int from_str_to_int;
     int result;
     for(int i=0;i<A.size();i++)
     {
            if 
            (
                (
                A[i].c_str()[0] == '+' ||
                A[i].c_str()[0] == '-' ||
                A[i].c_str()[0] == '*' ||
                A[i].c_str()[0] == '/' 
                ) &&  A[i].size() == 1
            )
            {
                save_top = tempdata.top();
                tempdata.pop();
                result = str_math(tempdata.top(),save_top,A[i]);
                tempdata.pop();
                tempdata.push(result);
            }
            else
            {
                from_str_to_int = strtol (A[i].c_str(),NULL,10);
                tempdata.push(from_str_to_int);
            }
     }
     return result;
}
int main(int argc, char const *argv[])
{
    //vector<string> A{"2", "2", "/"};
    vector<string> A{"-2", "-1", "2", "+", "-1", "-", "-", "2", "-2", "1", "-", "+", "-", "-2", "-2", "-", "-1", "2", "-2", "-", "-2", "-1", "+", "1", "1", "-", "-1", "+", "1", "*", "*", "2", "+", "*", "-", "-2", "1", "-2", "*", "+", "-2", "*", "1", "*", "-", "*", "*" };
    evalRPN(A);
    return 0;
}
