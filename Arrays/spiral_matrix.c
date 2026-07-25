//spiral matrix
#include<stdio.h>
#define N 10
int main(){
    int a[N][N],i,j,top,bottom,right,left,rows,cols;
    printf("Enter noof rows: ");
    scanf("%d",&rows);
    printf("Enter noof cols: ");
    scanf("%d",&cols);
    printf("Enter (%d x %d) elements: ",rows,cols);
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            scanf("%d",&a[i][j]);
        }
    }
    top=0,bottom=rows-1,left=0,right=cols-1;
    while(top<=bottom && left<=right){
        for(i=left;i<=right;i++){
            printf("%d ",a[top][i]);
        }
        top++;
        for(i=top;i<=bottom;i++){
            printf("%d ",a[i][right]);
        }
        right--;
        if(top<=
            bottom){
            for(i=right; i>=left; i--){
                printf("%d ", a[bottom][i]);
            }
            bottom--;
        }
        if(left <= right){
            for(i=bottom; i>=top; i--){
                printf("%d ", a[i][left]);
            }
            left++;
        }
    }
    printf("\n");
    return 0;
}