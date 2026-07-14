//row wise sum of a matrix
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
    for(i=0;i<rows;i++){
        int sum=0;
        printf("Row: ");
        for(j=0;j<cols;j++){
            printf("%d ",a[i][j]);
            sum+=a[i][j];
        }
        printf("    sum = %d\n",sum);
    }
    return 0;
}