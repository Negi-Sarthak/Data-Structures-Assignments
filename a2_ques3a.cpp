#include <stdio.h>

int main() {
    int arr[100], n, i, sum=0, total;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter %d numbers from 1 to %d (one missing):\n", n-1, n);
    for(i=0;i<n-1;i++) {
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    total=n*(n+1)/2;
    printf("Missing number = %d\n", total-sum);
    return 0;
}
