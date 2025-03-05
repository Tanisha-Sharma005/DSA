#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linkedlistTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("|%d|->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int isEmpty(struct node *top)
{
    return (top == NULL);
}

int isFull(struct node *top)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        free(p);
        return 0;
    }
}

struct node *push(struct node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack overflow\n");
        return top;
    }
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        struct node *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int main()
{
    struct node *top = NULL;

    top = push(top, 11);
    top = push(top, 22);
    top = push(top, 33);
    top = push(top, 44);

    int element = pop(&top);
    printf("Popped element is %d\n", element);

    linkedlistTraversal(top);

    return 0;
}