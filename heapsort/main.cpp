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

void First_Heap(ListNode* A)
{
    ListNode* Root = A; //just an alias
    ListNode* Sub_Root;

    ListNode* Left_Leaf;
    ListNode* Right_Leaf;
    
    ListNode* iterator;
    ListNode* Last_node = NULL;

    bool swaps = false;
    ListNode* last_sorted_node = NULL;
    ListNode* Fully_sorted     = NULL;
    ListNode* Reducing_Node    = NULL;
    ListNode* Before_Left      = NULL;
    ListNode* MAX_ITEM         = NULL;
    int i=0;
    if(A->next != NULL)
    {
        do
        {
            do
            {
                Sub_Root  = Root;
                iterator  = Sub_Root;
                swaps     = false;
                Fully_sorted = last_sorted_node;
                do 
                {
                    Before_Left = iterator;
                    Left_Leaf   = iterator->next;
                    iterator    = Left_Leaf->next;
                    Right_Leaf  = Left_Leaf->next;

                    if(Left_Leaf->val > Sub_Root->val)
                    {
                        Swap_Nodes(Left_Leaf,Sub_Root);
                        swaps = true;
                        last_sorted_node = Sub_Root;
                    }
                    if(Right_Leaf!=NULL)
                    {
                        if(Right_Leaf->val > Sub_Root->val && Right_Leaf!=MAX_ITEM)
                        {
                            Swap_Nodes(Right_Leaf,Sub_Root);
                            swaps = true;
                            last_sorted_node = Sub_Root;
                        }
                    }

                    Sub_Root = Sub_Root->next;
                    i++;
                } while(Sub_Root!=Fully_sorted && Left_Leaf->next!=MAX_ITEM && Right_Leaf->next!=MAX_ITEM);

                if(Last_node == NULL)
                {
                    Last_node     = (Right_Leaf == MAX_ITEM)? Left_Leaf:Right_Leaf;
                    Reducing_Node = (Last_node == Right_Leaf)?Left_Leaf:Before_Left;
                }

            }while(swaps);

            Swap_Nodes(Root,Last_node);
            last_sorted_node = Reducing_Node;
            MAX_ITEM  = Last_node;
            Last_node = NULL;
        
        }while(MAX_ITEM!=Root->next);
    }
    cout<<"iterations: "<<i<<endl;
}
//#define ARR
int main(int argc, char const *argv[])
{
    //int arr[]={9,13,17,14,10,18,12,15,8,16,11};
    //int arr[]={41, 40, 48, 11, 88, 34, 97, 12, 98, 38, 13, 18,\
    //101, 59, 77, 41, 63, 70, 22, 3, 56, 25, 10, 46, 17,\
    //84,87, 33, 60, 29, 27, 54, 71, 100, 93, 50, 65, 61, 39, 21, 32, 16};
    int arr[]={80 , 14 , 12 , 97}; 
    ////int arr[]={92};
    #ifdef ARR
    int arr_size = sizeof(arr)/sizeof(int);
    Node Head(arr[0]);
    #else
    int arr_size = 1000;
     Node Head(rand()%10000);
    #endif 
    Node* Tail = (Node*) malloc(sizeof(Node));
    Node* List =  &Head;
    #ifdef ARR
    printf(" %d ", List->val); 
    #endif
    for(int i=1;i<arr_size;i++)
    {
        #ifdef ARR
        Tail->val  = arr[i];
        #else
        Tail->val  = rand()%10000;
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
        First_Heap (&Head);
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
