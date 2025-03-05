#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
int isEmpty(struct stack *ptr)
{
    return ptr->top == -1;
}

int isFull(struct stack *ptr)
{
    return ptr->top == ptr->size - 1;
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack is overflow.\n");
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
        printf("The stack is underflow.\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int match(char a, char b)
{
    if (a == '(' && b == ')')
        return 1;
    if (a == '{' && b == '}')
        return 1;
    if (a == '[' && b == ']')
        return 1;
    return 0;
}

int parenthesisMatch(char *exp)
{
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(s, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(s))
            {
                free(s->arr);
                free(s);
                return 0;
            }
            char popped_ch = pop(s);
            if (!match(popped_ch,exp[i]))
            {
                free(s->arr);
                free(s);
                return 0;
            }
        }
    }
       int result=isEmpty(s);
       free(s->arr);
       free(s);
       return result;
}
int main()
{
    char exp[20];
    printf("Enter your expression");     //---->This willnot give output
     scanf("%s",exp);
    if (parenthesisMatch(exp))
    {
        printf("The parenthesis is balanced.\n");
    }
    else
    {
        printf("The parenthesis is not balanced.");
    }
    return 0;
}