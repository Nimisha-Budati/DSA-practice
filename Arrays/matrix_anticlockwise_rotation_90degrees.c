//rotate matrix by 90 degrees anti-clock wise
#include<stdio.h>
#define N 10
int main(){
    int a[N][N],i,j,rows,cols,rotate[N][N];
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
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            rotate[cols-1-j][i]=a[i][j];
        }
    }
    printf("Rotated matrix:\n");
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            printf("%d ",rotate[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
original matrix: 
1 2 3 
4 5 6
7 8 9
roatated matrix should be:
3 6 9
2 5 8
1 4 7

so,
1->rotate[2][0]
2->rotate[1][0]
3->rotate[0][0]
4->rotate[2][1]
5->rotate[1][1]
6->rotate[0][1]
7->rotate[2][2]
8->rotate[1][2]
9->rotate[0][2]

soo here row=cols-j-1
and column=i
*/