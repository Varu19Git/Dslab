#include<stdio.h>
#include<string.h>
#include "stackadt.c"
int priority(char c){
    if(c=='+'||c=='-')
    return 1;
if(c=='*'||c=='/')
return 2;
return 0;
}
int isoperator(char c){
    switch(c){
        case '+':
        case '-':
        case '/':
        case '*':return 1;
        default :return 0;
    }
}
int main(){
    stack *sp;
    sp=create_stack();
    char *dptr,pf[30]={'\0'},infix[30],temp[2];
    temp[1]='\0';
    printf("Enter infix expn");
    scanf("%s",infix);
    for(int i=0;infix[i]!='\0';i++){
        if(infix[i]=='(')
        {
            dptr=(char*)malloc(sizeof(char));
            *dptr=infix[i];
            push_stack(sp,dptr);
        }
        else if(infix[i]==')')
        {
            dptr=(char*)pop_stack(sp);
            while(*dptr!='(')
            {
                temp[0]=*dptr;
                strcat(pf,temp);
                dptr=(char*)pop_stack(sp);
            }

        }
        else if(isoperator(infix[i])){
            dptr=stack_top(sp);
            while((!stack_empty(sp))&&(priority(*dptr)>=priority(infix[i]))){
                dptr=(char*)pop_stack(sp);
                temp[0]=*dptr;
                strcat(pf,temp);
                dptr=(char*)stack_top(sp);
            }
            
            dptr=(char*)malloc(sizeof(char));
            *dptr=infix[i];
            push_stack(sp,dptr);
        }
        else {
            temp[0]=infix[i];
            strcat(pf,temp);
        }
    }
    while(!stack_empty(sp)){
        dptr = (char*)pop_stack(sp);
        temp[0] = *dptr;
        strcat(pf, temp);
    }
    printf("postfix is %s",pf);

}