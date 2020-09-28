#include <stdio.h>

#define ARRAYLEN sizeof(data) / sizeof(data[0])

int binsearch(int x, int v[], int n);

/* Perform a binary
 * search on a sorted array
 * the target element being
 * x. It sets the L element to
 * zero and R element to
 * n - 1. To get the middle element
 * set m to the floor of (L + R) / 2.
 * Then check if x is greater than,
 * less than or equal to m.
 * if x > m L is set to m + 1
 * else x < m R is set to m - 1
 * if x == m then the target value has been found.
 */
int main(void) {
    // Initialize a sorted array of integers
    int data[] = {2, 42, 70, 129, 141, 149, 151, 191, 200, 213}; 

    int target = 200; // initialize target value

    int foundval = 0;

    printf("Searching for %d in array...\n", target);

    foundval = binsearch(target, data, ARRAYLEN);

    if (foundval == -1)
        printf("Target value not found!\n");
    else
        printf("Target value found!\n"); 

    return 0;
}

/* Perform a binary search
 * for a target value
 * set L to 0 and R to n - 1.
 * get the middle element through
 * calculating (L + R) / 2
 * if the target element is
 * > m then set R to m + 1
 * if x < m set L to m - 1
 * if x == m then the target value
 * is found
 */
int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0; // Set L to 0
    high = n - 1; // Set R to n - 1
    mid = (low + high) / 2; // Set m to L + R / 2

    while ((low <= high) && (v[mid] != x)) {
        if (x < v[mid])
            high = mid - 1 ;
        else
            low = mid + 1;

        mid = (low + high) / 2;
    }

    return ((x == v[mid]) ? x : -1);
}
