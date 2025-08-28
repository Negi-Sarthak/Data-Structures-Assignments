#include <stdio.h>

int arr[100], n = 0;   // Global array and size

void create() {
    int i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void display() {
    int i;
    if(n == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Array elements: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insert() {
    int pos, val, i;
    printf("Enter position (0-%d): ", n);
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &val);

    for(i = n; i > pos; i--)
        arr[i] = arr[i-1];

    arr[pos] = val;
    n++;
}

void delete() {
    int pos, i;
    if(n == 0) {
        printf("Array empty!\n");
        return;
    }
    printf("Enter position (0-%d): ", n-1);
    scanf("%d", &pos);

    for(i = pos; i < n-1; i++)
        arr[i] = arr[i+1];

    n--;
}

void linearSearch() {
    int val, i, found = 0;
    printf("Enter value to search: ");
    scanf("%d", &val);

    for(i = 0; i < n; i++) {
        if(arr[i] == val) {
            printf("Found at position %d\n", i);
            found = 1;
            break;
        }
    }
    if(!found)
        printf("Not found\n");
}

int main() {
    int choice;
    while(1) {
        printf("\n---MENU---\n");
        printf("1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: delete(); break;
            case 5: linearSearch(); break;
            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
