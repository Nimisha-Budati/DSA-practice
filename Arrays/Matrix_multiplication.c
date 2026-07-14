//matrix Multiplication
#include<stdio.h>
#define N 10
int main(){
    int a[N][N],b[N][N],mul[N][N],i,j,n1,n2,m1,m2,k;
    printf("Enter noof rows of matrix 1: ");
    scanf("%d",&n1);
    printf("Enter noof cols of matrix 1: ");
    scanf("%d",&n2);
    printf("Enter (%d x %d) elements of matrix 1:\n",n1,n2);
    for(i=0;i<n1;i++){
        for(j=0;j<n2;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter noof rows of matrix 2: ");
    scanf("%d",&m1);
    printf("Enter noof cols of matrix 2: ");
    scanf("%d",&m2);
    printf("Enter (%d x %d) elements of matrix 2:\n",m1,m2);
    for(i=0;i<m1;i++){
        for(j=0;j<m2;j++){
            scanf("%d",&b[i][j]);
        }
    }
    if(n2!=m1){
        printf("Multiplication not possible\n");
        return 0;
    }
    for(i=0;i<n1;i++){
        for(j=0;j<m2;j++){
            mul[i][j]=0;
            for(k=0;k<n2;k++){
                mul[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    printf("Matrices Multiplication:\n");
    for(i=0;i<n1;i++){
        for(j=0;j<m2;j++){
            printf("%d ",mul[i][j]);
        }
        printf("\n");
    }
    return 0;
}