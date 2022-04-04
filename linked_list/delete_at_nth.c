#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *A;

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

void Delete(int pos1, int n){
    struct Node* temp = A;
    if(pos1>n){
        printf("can't delete\n");
        return;
    }
    if(pos1 == 1){
        A = temp->next;
        free(temp);
        return;
    }

    for(int i = 1; i<=pos1-1; i++){
        temp = temp->next;
    }
    struct Node* temp1 = A;
    for(int i = 1; i<pos1-1; i++){
        temp1 = temp1->next;
    }

    temp1->next = temp->next; 
    free(temp);
}


int main()
{

    A = NULL;

    int n, x, pos, pos1;
   

    printf("Enter the size of linked list: \n");
    scanf("%d", &n);

    for ( int i =0; i<n; i++){
        printf("Enter the value : \n" );
        scanf("%d",&x);
        scanf("%d", &pos)  ;      
         Insert(x, pos);

        Print();

    }

     printf("Enter the position : \n");
    scanf("%d", &pos1);
    
    Delete(pos1, n);
     Print();
    

    return 0;
}