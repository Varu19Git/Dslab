//q_ ADT implementation
#include"queueadt.c"
void display_queue(queue*qp)
{
qnode* temp;
float* pele;
if(!qp->count)
printf("queue is empty\n");
else
{
temp=qp->front;
printf("queue elements are\n");
 while(temp)
 {
 pele=(float*)temp->dptr;
 printf("%f\n",*pele);
 temp=temp->next;
}
}
}
int main()
{
int choice;
float *pele;
queue* qp;
qp=create_queue();
while(1)
{
printf("\nenter choice\n1-enqueue\n2-dequeue\n3-count\n4-frontq\n5-rareq\n6-qempty\n7-fullq\n8-display\n9-destroy\n");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("enter element to be insert\n");
 pele=(float*)malloc(sizeof(int));
 scanf("%f",pele);
 if(en_queue(qp,pele))
 printf("%f is inserted\n",*pele);
 else
 printf("%f is not inserted\n",*pele);
 break;
 case 2:if(de_queue(qp,(void**)&pele))
 { pele=(float*)pele;
 printf("%f is deleted\n",*pele);
 }
 else
 printf("queue is empty\n");
 break;
 case 3:printf("number of elements are %d\n",qcount(qp));
 break;
 case 4:if(front_queue(qp))
 { pele=(float*)front_queue(qp);
 printf("front element is %f\n",*pele);
 }
 else
 { printf("queue is empty\n");}
 break;
 case 5:if(rare_queue(qp))
 { pele=(float*)rare_queue(qp);
 printf("rare element is %f\n",*pele);
 }
 else
 { printf("queue is empty\n");}
 break;

 case 6:if(qempty(qp))
 printf("queue is empty\n");
 else
 printf("queue is not empty\n");
 break;
 case 7:if(qfull(qp))
 printf("queue is full\n");
 else
 printf("queue is not full\n");
 break;
 case 8:display_queue(qp);
 break;
 case 9:if(!destroy_queue(qp))
 printf("queue is destroyed\n");
 else
 printf("queue not destroyed\n");
 
 default : return 0;
}
}
}