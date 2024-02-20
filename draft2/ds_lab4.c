#include"arrayADT.h"
typedef struct
{
    int roll;
    char name[30],USN[30];
}stud;

void disp(stud *sp){
        printf("Name: %s\nRoll: %d\nUSN: %s\n",sp->name,sp->roll,sp->USN);
}
void dispAll(stack*sp){
        if(sp->count==0){
                printf("Stack is empty\n");
                return;
        }
        printf("Stack elements are\n");
        for(int i=0;i<sp->count;i++){
                disp(sp->starray[i]);
                printf("\n");
        }
}
int main()
{
    stack*ps;
    stud*pstd;
    int choice,type,num,size;
    printf("Enter the size of array\n");
    scanf("%d",&size);
    ps=createstack(size);
    while(1)
    {
        printf("Enter your choice\n1-pushstack\n2-popstack\n3-emptystack\n4-fullstack\n5-stacktop\n6-stackcount\n7-displaystack\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : 
                    
                     pstd=(stud*)malloc(sizeof(stud));
                     printf("Enter student name,rollno,USN\n");
                     scanf("%s%d%s",(pstd->name),&(pstd->roll),(pstd->USN));
                     if(pushstack(ps,pstd))
                     {
                     printf("Successfully inserted\n");
                     }
                     else
                     {
                     printf("push failed\n");
                     }
                     
                     
                    
                     break;
            case 2 : pstd=(stud*)popstack(ps);
                     if(ps)
                     printf("Successfully popped\n");
                     else
                     printf("Pop failed\n");
                     break;
            case 3: if(emptystack(ps))
                    
                    printf("Stack is empty\n");
                    else
                    printf("Stack is not empty\n");
                    break;
            case 4: if(fullstack(ps))
                    printf("Stack is full\n");
                    else
                    printf("Stack is not full\n");
                    break;
            case 5: pstd=(stud*)stacktop(ps);
                    if(pstd)
                    printf("Top element are %s,%d,%s\n",(pstd->name),(pstd->roll),(pstd->USN));
                    else 
                    printf("Stack is empty\n");
                    break;
            case 6: num=stackcount(ps);
                    printf("No. of elemenets = %d",num);
                    break;
            case 7: dispAll(ps);
                    break;
            case 8:if(destroystack(ps))
                   printf("Stack is destroyed\n");
                   else
                   printf("stack is not d\n");
                   break;
            default : return 0;
        }

    }
    
}
    