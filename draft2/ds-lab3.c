//assignment 3
//stack ADT integer implementation
#include"stackadt.c"
void display_stack(stack* ps)
{
node*temp;
int*pele;
temp=(node*)malloc(sizeof(node));
temp=ps->top;
printf("stack elements are\n");
while(temp)
{
pele=(int*)temp->data;
printf("%d\n",*pele);
temp=temp->next;
}
}
int main()
{
int choice,*pele;
stack* sp;
sp=create_stack();
while(1)
{
printf("\nEnter choice\n1-push\n2-pop\n3-top\n4-count\n5-empty\n6-fullstack\n7-display\n8-destroy\n");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("enter element to be pushed\n");
 pele=(int*)malloc(sizeof(int));
 scanf("%d",pele);
 if(push_stack(sp,pele))
 {
 printf("element %d is pushed successfully\n",*pele);
 }
 else
 {
 printf("element %d is not pushed successfully\n",*pele);
 }
 break;

 case 2:pele=(int*)pop_stack(sp);
 if(pele)
 printf("popped element is %d\n",*pele);
 else
 printf("stack is empty\n");
 break;

 case 3:pele=(int*)stack_top(sp);
 if(pele)
 printf("top element is %d\n",*pele);
 else
 printf("stack is empty\n");
 break;

 case 4:printf("number of elements in stack is %d\n",stack_count(sp));
 break;

 case 5:if(stack_empty(sp))
 printf("stack is empty\n");
 else
 printf("stack is not empty\n");
 break;

 case 6:if(stack_full(sp))
 printf("stack is full/n");
 else
 printf("stack is not full\n");
 break;

 case 7:display_stack(sp);
 break;

 case 8:if(destroy_stack(sp)==NULL)
 printf("stack is destroyed\n");
 
 default: return 0;
}
}
}