//matrix diagonal sum
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
    if(rows!=cols){
        printf("Not a square matrix. Primary and secondary diagonals are not defined.\n");
        return 0;
    }
    int primary_sum=0,secondary_sum=0;
    for(i=0;i<rows;i++){
        primary_sum+=a[i][i];
        secondary_sum+=a[i][rows-i-1];
    }
    printf("primary Diagonal sum: %d\n",primary_sum);
    printf("secondary Diagonal sum: %d\n",secondary_sum);
    return 0;
}