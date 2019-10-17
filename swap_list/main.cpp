
#include <iostream>
#include <stdio.h>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* swapPairs(ListNode* A) 
{
    ListNode* Head = NULL;
    ListNode* Bef_Bef = NULL;
    ListNode* Before;
    ListNode* After = A; 
    ListNode* Middle;
    do
    {
        if(After!=NULL)
        {
            Before = After;
            Middle = Before->next;
            if(Middle!=NULL)
            {
                After = Middle->next;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
        Middle->next = Before;
        Before->next = After;
        if(Bef_Bef!=NULL)
        {
            Bef_Bef->next = Middle;
        }
        if(Head == NULL)
        {
            Head = Middle;
        }
        Bef_Bef = Before;
    }while(true);
    Head = (Head == NULL)?A:Head;
    return Head;
}

int main(int argc, char const *argv[])
{
    /* code */
    int arr[]={1,2,3,4,5};
    ListNode* Head =(ListNode*) malloc( sizeof(ListNode));
    Head->val = arr[0];
    ListNode* iterator;
    ListNode* Tail;
    Tail = Head;
    for(int n=1;n<sizeof(arr)/sizeof(int);n++)
    {
        iterator = (ListNode*) malloc( sizeof(ListNode));
        iterator->val = arr[n];
        Tail->next = iterator;
        Tail = iterator;
    }  
    Tail->next = NULL;
    Head = swapPairs(Head);
    return 0;
}
