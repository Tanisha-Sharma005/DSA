#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
int stackTop(struct stack *s)
{
    return s->arr[s->top];
}
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack is overflow.");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("The stack is underflow");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int precedence(char ch){
   if(ch=='*'|| ch=='/')
   return 3;
   else if(ch=='+'|| ch=='-')
   return 2;
   else
    return 0;
}

int isoperator(char ch){
    if(ch=='+'|| ch=='-'||ch=='*'||ch=='/')
    return 1;
    else
    return 0;
}

char *infixtopostfix(char *infix){
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->size=45;
    s->top=-1;
    s->arr=(char *)malloc(s->size *sizeof(char));
    char *postfix=(char *)malloc((strlen(infix)+1)*sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        if(!isoperator(infix[i])){
            postfix[i]=infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i]>precedence(stackTop(s)))){
                push(s,infix[i]);
                i++;
            }
            else{
                postfix[j]=pop(s);
                j++;
            }
        }
    }
    while(!isEmpty(s)){
        postfix[j]=pop(s);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}

int main()
{
    char *infix = "a-b+t/6";
    printf("Postfix is %s",infixtopostfix(infix));

    return 0;
}