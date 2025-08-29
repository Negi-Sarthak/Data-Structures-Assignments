#include <stdio.h>

int main() {
    int a[10][10], transpose[10][10];
    int rows, cols, i, j;

    printf("Enter rows and cols: ");
    scanf("%d%d",&rows,&cols);

    printf("Enter matrix:\n");
    for(i=0;i<rows;i++)
        for(j=0;j<cols;j++)
            scanf("%d",&a[i][j]);

    for(i=0;i<rows;i++)
        for(j=0;j<cols;j++)
            transpose[j][i] = a[i][j];

    printf("Transpose matrix:\n");
    for(i=0;i<cols;i++) {
        for(j=0;j<rows;j++)
            printf("%d ", transpose[i][j]);
        printf("\n");
    }
    return 0;
}
