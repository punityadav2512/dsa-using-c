#include<stdio.h>
#include<stdlib.h>

    struct Node {
        int data;
        struct Node* next;
    };
    struct Node* A ;

    void Insert(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if(A==NULL){

    A = temp;
    }
    else{

    struct Node* temp1 = A;
    while(temp1->next != NULL){
        temp1 = temp1->next;
    }
    temp1->next =temp;
    }
    }

    void Print(){
        struct Node* temp = A;
        printf("List is : ");
        while(temp != NULL){
            printf("%d", temp->data);
            temp = temp->next;
        }

        printf("\n");
    }

int main(){

    A = NULL;

    int n, x;
    printf("Enter the size of linked list: \n");
    scanf("%d", &n);

    for ( int i =0; i<n; i++){
        printf("Enter the value : \n" );
        scanf("%d",&x);
         Insert(x);
        Print();

    }

   



    return 0;
}