#include <stdio.h>

int main() {
    int arr[100], n, i, key, low, high, mid, flag = 0;
    printf("Enter size of array: ");
    scanf("%d",&n);
    printf("Enter elements (sorted):\n");
    for(i=0;i<n;i++) scanf("%d",&arr[i]);

    printf("Enter key to search: ");
    scanf("%d",&key);

    low=0; high=n-1;
    while(low<=high) {
        mid=(low+high)/2;
        if(arr[mid]==key) {
            printf("Found at position %d\n", mid);
            flag=1;
            break;
        }
        else if(arr[mid]<key) low=mid+1;
        else high=mid-1;
    }
    if(flag==0) printf("Not found\n");
    return 0;
}
