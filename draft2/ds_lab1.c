#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int rpart, ipart;
} complex;

typedef void* (*funptr)(void*, void*);

void* complex_sum(void*, void*);
void* int_sum(void*, void*);
void* float_sum(void*, void*);
void* sum_two_nos(void*, void*, funptr);
funptr getfun(int);

int main() {
    funptr fp;
    complex *pc1, *pc2, *pc3;
    int *pi1, *pi2, *pi3;
    float *pf1, *pf2, *pf3;
    int type;

    while (1) {
        printf("Enter your choice\n1-complex addition\n2-integer addition\n3-floating point addition\n4-Exit\n");
        scanf("%d", &type);

        if (type == 4) {
            printf("Exiting the program...\n");
            break;
        }

        fp = getfun(type);

        switch (type) {
            case 1:
                pc1 = (complex*)malloc(sizeof(complex));
                printf("Input first complex number\n");
                scanf("%d%d", &(pc1->rpart), &(pc1->ipart));
                pc2 = (complex*)malloc(sizeof(complex));
                printf("Input second complex number\n");
                scanf("%d%d", &(pc2->rpart), &(pc2->ipart));
                pc3 = (complex*)sum_two_nos(pc1, pc2, fp);
                printf("Real part=%d\t Imaginary part=%di\n", (pc3->rpart), (pc3->ipart));
                free(pc1);
                free(pc2);
                free(pc3);
                break;

            case 2:
                pi1 = (int*)malloc(sizeof(int));
                printf("Enter the first integer\n");
                scanf("%d", pi1);

                pi2 = (int*)malloc(sizeof(int));
                printf("Enter the second integer\n");
                scanf("%d", pi2);
                pi3 = (int*)sum_two_nos(pi1, pi2, fp);
                printf("Sum of two integers = %d\n", *pi3);
                free(pi1);
                free(pi2);
                free(pi3);
                break;

            case 3:
                pf1 = (float*)malloc(sizeof(float));
                printf("Enter the first float\n");
                scanf("%f", pf1);
                pf2 = (float*)malloc(sizeof(float));
                printf("Enter the second float\n");
                scanf("%f", pf2);
                pf3 = (float*)sum_two_nos(pf1, pf2, fp);
                printf("Sum of two floats = %f\n", *pf3);
                free(pf1);
                free(pf2);
                free(pf3);
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}

void* complex_sum(void* pc11, void* pc22) {
    complex* pc1 = (complex*)pc11;
    complex* pc2 = (complex*)pc22;
    complex* pc3 = (complex*)malloc(sizeof(complex));
    pc3->rpart = (pc1->rpart + pc2->rpart);
    pc3->ipart = (pc1->ipart + pc2->ipart);
    return pc3;
}

void* int_sum(void* pi11, void* pi22) {
    int* pi3;
    int* pi1 = (int*)pi11;
    int* pi2 = (int*)pi22;
    pi3 = (int*)malloc(sizeof(int));
    *pi3 = *pi1 + *pi2;
    return pi3;
}

void* float_sum(void* pf11, void* pf22) {
    float* pf1 = (float*)pf11;
    float* pf2 = (float*)pf22;
    float* pf3 = (float*)malloc(sizeof(float));
    *pf3 = (*pf1 + *pf2);
    return pf3;
}

void* sum_two_nos(void* d11, void* d22, funptr fp1) {
    return (fp1(d11, d22));
}

funptr getfun(int type) {
    switch (type) {
        case 1:
            return &complex_sum;
        case 2:
            return &int_sum;
        case 3:
            return &float_sum;
        default:
            printf("fp=NULL\n");
    }
    return NULL;

}



