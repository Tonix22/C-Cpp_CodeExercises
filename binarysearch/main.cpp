#include <stdio.h>
#include <stdint.h>
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;
#define HASHSIZE 1000
typedef struct Base_Node
{
    /* data */
    struct Base_Node *next = NULL;
    uint32_t value;
    uint32_t size;
}Node;


uint8_t HastTable [HASHSIZE] ={255};
void insert (uint8_t key, uint8_t value)
{
    uint32_t i = 0;
    uint32_t first_OP =  (key+key)*key;
    for(i = 0;i<key-2;i++)
    {
        first_OP *= first_OP;
    }
    key = first_OP%HASHSIZE;
    HastTable[key] = value;
}
uint8_t get_Hash(uint8_t key)
{ 
    uint32_t i = 0;
    uint32_t first_OP =  (key+key)*key;
    for(i = 0;i<key-2;i++)
    {
        first_OP *= first_OP;
    }
    key = first_OP%HASHSIZE;
    return HastTable[key];
}
vector<int> searchRange(const vector<int> &A, int B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    std::vector<int> Return_vect;
    
    int starting_index= A.size()/2;
    int right_pib = A.size()-1;
    int left_pib  = 0;
    
    int init = -1;
    int end  = -1;
    int temp_izq = 0;
    int temp_der = 0;
    if(A.size() == 1 && B == A[0])
    {
        Return_vect.push_back(0);
        Return_vect.push_back(0);
        return Return_vect; 
    }
    
    while (left_pib != right_pib)
    {
        if(B>A[starting_index])
        {
            left_pib   = starting_index;
            starting_index = (left_pib+right_pib)/2 ;
        }
        else if(B<A[starting_index])
        {
            right_pib = starting_index;
            starting_index = (left_pib+right_pib)/2 ;
        }
        else
        {
            printf("starting_index: %d\r\n",starting_index);
            init = end = starting_index;
            temp_der = (end + right_pib)/2;
            temp_izq = (init + left_pib)/2;
            while(left_pib != init && init != (left_pib + 1))
            {
                if(B == A[temp_izq])
                {
                    init = temp_izq;
                    temp_izq = (init + left_pib)/2;
                }
                else
                {
                    left_pib = temp_izq;
                    temp_izq = (init + left_pib)/2;
                }
            }
            while(right_pib != end &&  right_pib!= (end + 1))
            {
                if(B == A[temp_der])
                {
                    end = temp_der;
                    temp_der = (end + right_pib)/2;
                }
                else
                {
                    right_pib = temp_der;
                    temp_der = (end + right_pib)/2;
                }
            }
            Return_vect.push_back(init);
            Return_vect.push_back(end);
            return Return_vect;
        }
         
        if( right_pib == left_pib+1){
            Return_vect.push_back(-1);
            Return_vect.push_back(-1);
            return Return_vect;
        }
        
    }
    return Return_vect;
}
int main(int argc, char** argv) 
{
           
    //std::vector<int> A = {1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};
    std::vector<int> A = { 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 7, 7, 8,8, 8, 8,9, 9, 10, 10, 10};
    //`int B = 1;
//`
    //`std::vector<int> ret = searchRange(A,B);
    //`for (int i : ret)
    //`{
    //`    std::cout<< i << " \r\n";
    //}
    //insert(5,70);
    //printf("my value in key %d is %d\r\n",5,get_Hash(5));
    //system("pause");
    for(int n: A) 
    {
        cout<<n<<" ";
    }
    cout<<"\r\n";
    for (auto it = A.rbegin(); it != A.rend(); it++) 
        cout << *it << " ";

    printf("\a");
    return 0;
}