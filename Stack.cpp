#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct Stack
{
    int top;
    int capacity;
    int *arry;
};
struct Stack *Creat(int cap)
{
    struct Stack *n;
    n = (struct Stack *)malloc(sizeof(struct Stack));
    n->capacity = cap;
    n->top = -1;
    n->arry = (int *)malloc(sizeof(int)*n->capacity);
    return n;
};
int isFull(struct Stack *s)
{
    if(s->top==s->capacity-1)
        return 1;
    else
        return 0;
}
int isEmpty(struct Stack *s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}
void push(struct Stack *s,int item)
{
    if(!isFull(s)){
        s->top++;
        s->arry[s->top]=item;
    }
}
int pop(struct Stack *s)
{
    int item;
    if(!isEmpty(s))
    {
       item = s->arry[s->top];
       s->top--;
       return(item);
    }
    return -1;
}
int main()
{
    struct Stack *Stack;
    Stack = Creat(5);
    int ch,item;
    while(1)
    {
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.exit");
        printf("\nEnter your choice ");
        scanf("%d",&ch);
        switch(ch){
    case 1:
        printf("Enter a Number : ");
        scanf("%d",&item);
        push(Stack,item);
        break;
    case 2:
        item = pop(Stack);
        if(item==-1)
            printf("stack is empty");
        else
            printf("\n Poped Value is %d",item);
        break;
    case 3:
        exit(0);


        }
    }
    return 0;
}


