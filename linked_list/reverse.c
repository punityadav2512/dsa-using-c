#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *A;

void Reverse(){
    struct Node* q = A;
    struct Node* p = NULL;
    struct Node* r ;

    while(q != NULL){
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    A = p;
    return;

}

void Insert(int x, int pos)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (pos == 1)
    {
        temp->next = A;
        A = temp;
        return;
    }

    struct Node *temp1 = A;
    for (int i = 1; i < pos - 1; i++)
    {
        temp1 = temp1->next;
    }
    
    temp->next = temp1->next;
    temp1->next = temp;
}

void Print()
{
    struct Node *temp = A;
    printf("List is : ");
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{

    A = NULL;

    int n, x, pos;

    printf("Enter the size of linked list: \n");
    scanf("%d", &n);

    for ( int i =0; i<n; i++){
        printf("Enter the value : \n" );
        scanf("%d",&x);
        scanf("%d", &pos)  ;      
         Insert(x, pos);

        Print();

    }
    printf("After reversing ....\n");
    Reverse();
    Print();

    return 0;
}