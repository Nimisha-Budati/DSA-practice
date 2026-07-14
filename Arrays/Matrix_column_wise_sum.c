//column wise sum of a matrix
#include<stdio.h>
#define N 10
int main(){
    int rows,cols,a[N][N],i,j;
    printf("Enter noof rows: ");
    scanf("%d",&rows);
    printf("Enter noof cols: ");
    scanf("%d",&cols);
    printf("Enter (%d x %d) elements of matrix 1:\n",rows,cols);
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<cols;i++){
        int sum=0;
        printf("Col: ");
        for(j=0;j<rows;j++){
            printf("%d ",a[j][i]);
            sum+=a[j][i];
        }
        printf("    sum = %d\n",sum);
    }
    return 0;
}