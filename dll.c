#include<stdio.h>
#include<stdlib.h>
void createnode();
void display();
void insertatbeg();
void insertatEnd();
void insertatPos();
int count=0;
struct node{
    int data;
    struct node *next;
    struct node *prev; 
} *head=NULL,*tail=NULL;
int main(){
    createnode();
    display();
    insertatbeg();
    insertatEnd();
    insertatPos();
    display();
    printf("The total node in this program is: %d\n",count);
    printf("Thank You!");
}
void createnode(){
   struct node *temp,*newnode;
   int choice =1;
   while(choice){
   newnode=(struct node*)malloc(sizeof(struct node));
   if(newnode==NULL){
    printf("Memory allocation failed.\n");
    exit(1);
   }
   printf("Enter data:");
   scanf("%d",&newnode->data);
   newnode->prev=NULL;
   newnode->next=NULL;
   if(head==NULL){
    head=temp=newnode;
   }
   else{
    temp->next=newnode;
    newnode->prev=tail;
    temp=newnode;
   }
   count++;
   printf("Do you want to continue:");
   scanf("%d",&choice);
   printf("\n");
}
}
void display(){
    struct node *temp=head;
    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    printf("Doubly Linked List: ");
    while(temp!=NULL){
        printf("|%d|->",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void insertatbeg(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter the data u want to store in first pos:");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=head;
        if (head != NULL) {
        head->prev = newnode;
    } else {
        tail = newnode;  // If the list was empty
    }
   head=newnode;
   count++;
}
void insertatEnd(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter the data u want to store at the end pos:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=tail;
    if(tail!=NULL){
    tail->next=newnode;
    }
    else{
    head=newnode;
}
    tail=newnode;
    count++;
}
void insertatPos(){
    int pos,i=1;
    printf("Enter position:");
    scanf("%d",&pos);
    if(pos>count+1||pos<1){
        printf("Invalid potision:\n");
        return;
    }
     if (pos==1){
        insertatbeg();
    }
    else if(pos==count+1){
        insertatEnd();
    }
    else{
        struct node *newnode,*temp=head;
        newnode=(struct node*)malloc(sizeof(struct node));
                if (newnode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        printf("Enter the data u want to store in given pos:");
        scanf("%d",&newnode->data);
        for (i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }

        newnode->next = temp->next;
        newnode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newnode;
        }
        temp->next = newnode;

        count++;
    }
}
    

