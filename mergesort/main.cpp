
#include <vector>
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

typedef struct ListNode Node;

void Swap_Nodes(ListNode* A,ListNode* B)
{
    int temp;
    temp   = A->val;
    A->val = B->val;
    B->val = temp;
}

void Merge(ListNode* A)
{
    ListNode* T = NULL;
    ListNode* N = NULL;
    ListNode* helper = NULL;
    ListNode* before_N = NULL;
    int merges    = 1;
    bool get_size = true;
    int data_size = 0;//random data just need to be multiple of 2
    int log_n = 1;
    
    for(int j=0;j<log_n;j++)
    {
        merges *= 2;
        T = A;
        do
        {
            N = NULL;
            do
            {
                if(N == NULL)
                {
                    N =  T;
                    for(int i=0;i<merges/2;i++)
                    {
                        if(N->next!=NULL)
                        {
                            N = N->next;
                        }
                        if(i == (merges/2)-2)
                        {
                            before_N = N;
                        }
                        if(get_size)
                            data_size++;
                    }
                }
                if(T->val > N->val)
                {
                    Swap_Nodes(T,N);
                }
                if(T->next != N)
                {
                    helper = T->next;//save future Node remplaced
                    before_N ->next = N->next;//delete N 
                    T->next = N;//insert N
                    N->next = helper;//next node of N

                    T = T->next->next;
                    if(before_N ->next!=NULL)
                    {
                        N = before_N ->next;
                    }
                    else
                    {
                        N = before_N;
                    }
                    //delete and reinstert
                }
                else
                {
                    helper = NULL;
                }
                if(get_size)
                    data_size++;
            }while(helper!=NULL);
            if(N->next!=NULL)
            {
                T = N->next;
            }
        }while(N->next!=NULL);
        if(get_size)
        {
            int temp=data_size;
            data_size>>=1;
            while(data_size!=1)
            {
                data_size>>=1;
                log_n++;
            }
            get_size = false;
            data_size = temp;
        }
        
    }
    cout<<"size: "<<data_size<<endl;
}


#define ARR
int main(int argc, char const *argv[])
{
    //int arr[]={80 , 14 , 12 , 97};
    int arr[]={14,13,5,3,9,4,1,7,2,1};  
    #ifdef ARR
    int arr_size = sizeof(arr)/sizeof(int);
    Node Head(arr[0]);
    #else
    int arr_size = 10;
     Node Head(rand()%100);
    #endif 
    Node* Tail = (Node*) malloc(sizeof(Node));
    Node* List =  &Head;
    cout<<"data size: "<<arr_size<<endl;
    cout<<"input"<<endl;
    #ifdef ARRB
    printf(" %d ", List->val); 
    #endif
    for(int i=1;i<arr_size;i++)
    {
        #ifdef ARR
        Tail->val  = arr[i];
        #else
        Tail->val  = rand()%100;
        #endif
        List->next = Tail;
        List = Tail;
        Tail = (Node*) malloc(sizeof(Node));
        #ifdef ARR
        printf(" %d ", List->val);
        #endif
    }
        cout << endl;
        List->next = NULL;
    Merge(&Head);

    #ifdef ARR
        Tail = &Head;
        cout<<"sorted data"<<endl;
        for(int i=0;i<arr_size;i++)
        {
            printf(" %d ", Tail->val);
            Tail = Tail->next;
        }
    #endif
    return 0;
}
