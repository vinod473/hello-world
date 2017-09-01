#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int top1,top2;
    int *array;
    int capacity;
};
struct stack* CreateStack(int capacity)
{
  struct stack *s=(struct stack*)malloc(sizeof(struct stack));
  if(!s)
    {
        return NULL;
    }
  s->top1=-1;
  s->top2=capacity;
  s->capacity=capacity;
  s->array=(int*)malloc(capacity*sizeof(int));
  if(!s->array)
    {
        return NULL;
    }
return s;
}
int IsEmptyStack(struct stack *s)
{
    return (s->top1==-1&&s->top2==s->capacity);
}
int peak1(struct stack *s)
{
    return s->array[s->top1];
}
int peak2(struct stack *s)
{
    return s->array[s->top2];
}
void push1(struct stack *s,int data)
{
    if(s->top1<s->top2-1)
    {
        s->array[++s->top1]=data;
    }
    else
    {
        printf("Stack Overflow");
        exit(1);
    }
}
void push2(struct stack *s,int data)
{
    if(s->top1<s->top2-1)
        s->array[--s->top2]=data;
    else
    {
        printf("stack overflow");
        exit(1);
    }
}
int main()
{
    struct stack *s=CreateStack(10);
    if(!s)
        return -1;
    push1(s,5);
    push2(s,10);
    push2(s,15);
    push1(s,11);
    push2(s,7);
    printf("%d ",peak1(s));
    push2(s,40);
    printf(" %d",peak2(s));
return 0;
}
