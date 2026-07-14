//matrix addition
#include<stdio.h>
#define N 10
int main(){
    int a[N][N],b[N][N],sum[N][N],i,j,n;
    printf("Enter size: ");
    scanf("%d",&n);
    printf("Enter (%d x %d) elements of matrix 1:\n",n,n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter (%d x %d) elements of matrix 2:\n",n,n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            sum[i][j]=a[i][j]+b[i][j];
        }
    }
    printf("Matrices sum:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}