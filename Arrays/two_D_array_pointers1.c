#include<stdio.h>
#define N 10
void multiply(int a[][N],int b[][N],int res[][N],int r1,int c1,int r2,int c2){
    if(c1!=r2){
        printf("Multiplication not possible: c1 must equal r2\n");
        return;
    }
    int (*p)[N]=a;
    int (*q)[N]=b;
    int (*r)[N]=res;
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            *(*(r+i)+j)=0;
            for(int k=0;k<c1;k++){
                *(*(r+i)+j)+=(*(*(p+i)+k))*(*(*(q+k)+j));
            }
        }
    }
    printf("Result matrix:\n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            printf("%d ",*(*(r+i)+j));
        }
        printf("\n");
    }
}
int main(){
    int a[N][N],b[N][N],res[N][N];
    int r1,c1,r2,c2;
    printf("Enter rows and cols of matrix A: ");
    scanf("%d%d",&r1,&c1);
    printf("Enter rows and cols of matrix B: ");
    scanf("%d%d",&r2,&c2);
    if(r1>N||c1>N||r2>N||c2>N||r1<0||c1<0||r2<0||c2<0){
        printf("Invalid size\n");
        return 0;
    }
    printf("Enter elements of matrix A:\n");
    for(int i=0;i<r1;i++)
        for(int j=0;j<c1;j++)
            scanf("%d",&a[i][j]);
    printf("Enter elements of matrix B:\n");
    for(int i=0;i<r2;i++)
        for(int j=0;j<c2;j++)
            scanf("%d",&b[i][j]);
    multiply(a,b,res,r1,c1,r2,c2);
    return 0;
}