#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
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

int push(struct stack *ptr, int val)
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

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("The stack is underflow");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *s, int i)
{
    int arrayInd = s->top - i + 1;
    if (arrayInd < 0)
    {
        printf("Not a valid position for the stack.\n");
        return -1;
    }
    else
    {
        return s->arr[arrayInd];
    }
}

int stackTop(struct stack *s)
{
    return s->arr[s->top];
}

int stackBottom(struct stack *s)
{
    return s->arr[0];
}

int main()
{
    // struct stack s;
    // s.size=5;
    // s.top=-1;
    // s.arr=(int *)malloc(s.size*sizeof (int));
    int val;
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // printf("stack has been created successfully.");
    push(s, 11);
    push(s, 22);
    push(s, 33);
    push(s, 44);
    push(s, 55);

    // pop(s);

    // printf("%d", isFull(s));
    // printf("poped value is %d from stack", pop(s));

    for (int j = 1; j <= s->top + 1; j++)
    {
        printf("The value at position %d is %d.\n", j, peek(s, j));
    }
    printf("The top most value of this stack is %d\n", stackTop(s));
    printf("The bottom most value of this stack is %d\n", stackbottom(s));
    return 0;
}