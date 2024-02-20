#include <stdio.h>

// Function prototypes
int sum(int);
int fib(int);
int dec(int);
int fact(int);

int main() {
    int n, a, c, ch;

    while (1) {
        // Menu
        printf("\nEnter choice:\n1-Sum of n numbers\n2-Fibonacci\n3-Decimal to binary\n4-Factorial of n\n5-Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter n value: ");
                scanf("%d", &n);
                a = sum(n);
                printf("The sum of 1st %d numbers is %d\n", n, a);
                break;

            case 2:
                printf("Enter n value: ");
                scanf("%d", &n);
                printf("The first %d Fibonacci series is:\n", n);
                for (int i = 0; i < n; i++) {
                    printf("%d\t", fib(i));
                }
                printf("\n");
                break;

            case 3:
                printf("Enter n value: ");
                scanf("%d", &n);
                c = dec(n);
                printf("The binary of %d is %d\n", n, c);
                break;

            case 4:
                printf("Enter n value: ");
                scanf("%d", &n);
                printf("The factorial of %d is %d\n", n, fact(n));
                break;

            case 5:
                printf("Exiting program.\n");
                return 0;  // This will exit the entire program
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}

// Function to calculate sum of n numbers recursively
int sum(int n) {
    if (n == 0)
        return 0;
    else
        return (n + sum(n - 1));
}

// Function to calculate nth Fibonacci number recursively
int fib(int n) {
    if (n == 0 || n == 1)
        return n;
    else
        return (fib(n - 1) + fib(n - 2));
}

// Function to convert decimal to binary recursively
int dec(int n) {
    if (n == 0)
        return 0;
    else
        return (n % 2) + 10 * (dec(n / 2));
}

// Recursive function to find the factorial of n
int fact(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fact(n - 1);
}
 