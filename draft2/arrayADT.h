#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct
{
     int count,max,top;
     void**starray;
}stack;
stack*createstack(int size)
{
    stack*sp;
    sp=(stack*)malloc(sizeof(stack));
    if(sp)
    {
        sp->count=0;
        sp->max=size;
        sp->top=-1;
        sp->starray=(void**)calloc(size,sizeof(void*));
        if(!sp->starray)
        {
            free(sp);
            return NULL;
        }
    }
    return sp;
}
int pushstack(stack*sp,void*dptr)
{
    if(sp->count==sp->max)
    return 0;
    else
    {
        (sp->count)++;
        (sp->top)++;
        sp->starray[sp->top]=dptr;
        return 1;
    }
}
void*popstack(stack*sp)
{
    void*dptr;
    if(sp->top==-1)
    return NULL;
    else
    {
        dptr=sp->starray[sp->top];
        (sp->count)--;
        (sp->top)--;
        return dptr;
    }
}
void*stacktop(stack*sp)
{
    void*dout;
    if(sp->count==0)
    return NULL;
    else
    {
        return(sp->starray[sp->top]);
    }
}
int emptystack(stack*sp)
{
    if(sp->count==0)
    return 1;
    else
    return 0;
}
int fullstack(stack*sp)
{
    if(sp->count==sp->max)
    return 1;
    else
    return 0;
}
int stackcount(stack*sp)
{
    return(sp->count);
}
stack*destroystack(stack*sp)
{
    int i=0;
    if(sp)
    {
        while(i<(sp->count))
        {
            free(sp->starray[i]);
            i--;
        }
        free(sp->starray);
        free(sp);
    }
    return NULL;
}