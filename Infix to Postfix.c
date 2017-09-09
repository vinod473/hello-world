#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stack
{
    int top;
    unsigned capacity;
    int *array;
};
struct stack* createStack(unsigned capacity)
{
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    if(!s)
        return NULL;
    s->top=-1;
    s->capacity=capacity;
    s->array=(int*)malloc(s->capacity*sizeof(int));
    if(!s->array)
        return NULL;
    return s;
};
int IsEmptyStack(struct stack *s)
{
    return s->top==-1;
}
char peak(struct stack *s)
{
    return s->array[s->top];
}
char pop(struct stack *s)
{
    if(IsEmptyStack(s))
        return '$';
    return s->array[s->top--];
}
void push(struct stack *s,char op)
{
    s->array[++s->top]=op;
}
int isOperand(char ch)
{
    return (ch>='a'&&ch<='z'||ch>='A'&&ch<='Z');
}
int prec(char ch)
{
    switch(ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
return -1;
}
InfixToPostfix(char *exp)
{
    int i,k;
    struct stack *s=createStack(strlen(exp));
    if(!s)
      return -1;
    for(i=0,k=-1;exp[i];i++)
    {
        if(isOperand(exp[i]))
            exp[++k]=exp[i];
        else if(exp[i]=='(')
            push(s,exp[i]);
        else if(exp[i]==')')
        {
            while(!IsEmptyStack(s)&&peak(s)!='(')
                   exp[++k]=pop(s);
            if(IsEmptyStack(s))
               {
                 printf("Invalid Exp\n");
                  return ;
               }
            else pop(s);
        }
        else
        {
            while(prec(exp[i])<=prec(peak(s))&&!IsEmptyStack(s))
                exp[++k]=pop(s);
            push(s,exp[i]);
        }
    }
  while(!IsEmptyStack(s))
    exp[++k]=pop(s);
exp[++k]='\0';
if(IsEmptyStack(s))
 printf("%s YES\n",exp);
else printf("Invalid exp1\n");
}
int main()
{
    char exp[]="a+b*((c^d-e)^(f+g*h)-i";
    InfixToPostfix(exp);
    return 0;
}
