#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>

void read_input(int* pa, int* pb);
int gcdRecursive(int a, int b) {
    int q;
    assert(b != 0);
    q = a % b;
    if (q == 0) return b;
    return gcdRecursive(b, q);
}

int gcdLoop(int a, int b) {
    assert(b != 0);
    int q = a % b;
    while (q != 0) {
        int k = q;
        q = b % q;
        b = k;
    }
    return b;
}

int main() {
    int a, b;
    read_input(&a, &b);
    assert(b != 0);
    int gcdResRecursive = gcdRecursive(a, b);
    int gcdResLoop = gcdLoop(a, b);
    printf("Recursive gcd is %d and loop gcd is %d\n", gcdResRecursive, gcdResLoop);
    return 0;
}

void read_input(int* pa, int* pb) {
    printf("Enter the numbers: ");
    int nitems = scanf("%d%d", pa, pb);
    if (nitems != 2 || *pb == 0) {
        printf("Error: Invalid Input\n");
        abort();
    }
    printf("Numbers are %d and %d\n", *pa, *pb);
}