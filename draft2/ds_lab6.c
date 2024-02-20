//q_array ADT implementation
#include"qarrayadt.c"
void qdisplay(queue*qp)
{
int i;
if(qp)
{
if(qp->count>0)
{
i=qp->front;
printf("queue elements are\n");
while(i!=qp->rare)
{
printf("%s\n",((char*)qp->qarray[i]));
i=i+1;
if(i==qp->maxsize)
i=0;
}
printf("%s\n",(char*)qp->qarray[i]);
}
else
{
printf("queue is empty\n");
}
 }
}
int main()
{
queue* qp;
int size,choice;
char *pele;
printf("enter number of elements\n");
scanf("%d",&size);
qp=create_queue(size);
while(1)
{
printf("\nenter choice\n1-enqueue\n2-dequeue\n3-qcount\n4-qfront\n5-qrare\n6-qfull\n7-qempty\n8-qdisplay\n9-qdestroy\n");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("enter element to be pushed\n");
 pele=(char*)calloc(10,sizeof(char));
 scanf("%s",pele);
 if(en_queue(qp,pele))
 printf("%s is inserted successfully\n",pele);
 else
 printf("%s is not inserted \n",pele);
 break;
 case 2:pele=(char*)de_queue(qp);
 if(pele)
 printf("popped element is %s\n",pele);
 else
 printf("queue is empty\n");
 break;
 case 3:printf("number of elements in queue are %d\n",qcount(qp));
 break;
 case 4:if(qfront(qp))
 { pele=(char*)qfront(qp);
 printf("front element is %s\n",pele);
 }
 else
 { printf("queue is empty\n");
}
 break;
 case 5:if(qrare(qp))
 { pele=(char*)qrare(qp);
 printf("rare element is %s\n",pele);
 }
 else
 { printf("queue is empty\n");
}
 break;
 case 6:if(qfull(qp))
 printf("queue is full\n");
 else
 printf("queue is not full\n");
 break;
 case 7:if(qempty(qp))
 printf("queue is empty\n");
 else
 printf("queue is not empty\n");
 break;
 case 8:qdisplay(qp);
 break;
 case 9:qdestroy(qp);
 
 default: return 0;
 break;
}
}
}