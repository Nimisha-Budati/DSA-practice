#include<stdio.h>
#define N 10
void sum(int arr[][N],int rows,int cols){
    int (*p)[N]=arr;
    int total=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            total+=*(*(p+i)+j);
        }
    }
    printf("Sum= %d\n",total);
}
void maximum(int arr[][N],int rows,int cols){
    if(rows==0||cols==0){
        printf("Matrix is empty\n");
        return;
    }
    int (*p)[N]=arr;
    int max=*(*(p+0)+0);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(*(*(p+i)+j)>max){
                max=*(*(p+i)+j);
            }
        }
    }
    printf("Maximum element= %d\n",max);
}
int main(){
    int arr[N][N],rows,cols;
    printf("Enter rows and cols: ");
    scanf("%d%d",&rows,&cols);
    if(rows>N||cols>N||rows<0||cols<0){
        printf("Invalid size\n");
        return 0;
    }
    printf("Enter elements:\n");
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            scanf("%d",&arr[i][j]);
    sum(arr,rows,cols);
    maximum(arr,rows,cols);
    return 0;
}