//symmetric matrix check
#include<stdio.h>
#define N 10
int main(){
    int rows,cols,a[N][N],i,j,transpose[N][N];
    printf("Enter noof rows: ");
    scanf("%d",&rows);
    printf("Enter noof cols: ");
    scanf("%d",&cols);
    if(rows!=cols){
        printf("Not a symmetric matrix\n");
        return 0;
    }
    printf("Enter (%d x %d) elements of matrix 1:\n",rows,cols);
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            transpose[j][i]=a[i][j];
        }
    }
    for(i=0;i<cols;i++){
        for(j=0;j<rows;j++){
            if(a[i][j]!=transpose[i][j]){
                printf("Not a symmetric matrix\n");
                return 0;
            }
        }
    }
    printf("symmetric matrix\n");
    return 0;
}