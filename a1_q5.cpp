#include <stdio.h>

int main() {
    int a[10][10], rows, cols, i, j;

    printf("Enter rows and cols: ");
    scanf("%d%d",&rows,&cols);

    printf("Enter matrix:\n");
    for(i=0;i<rows;i++)
        for(j=0;j<cols;j++)
            scanf("%d",&a[i][j]);

    for(i=0;i<rows;i++) {
        int rowSum=0;
        for(j=0;j<cols;j++)
            rowSum += a[i][j];
        printf("Sum of row %d = %d\n", i, rowSum);
    }

    for(j=0;j<cols;j++) {
        int colSum=0;
        for(i=0;i<rows;i++)
            colSum += a[i][j];
        printf("Sum of column %d = %d\n", j, colSum);
    }
    return 0;
}
