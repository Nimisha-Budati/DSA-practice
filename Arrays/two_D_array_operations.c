#include<stdio.h>
#define N 10
int arr[N][N],rows,cols,i,j;
void display(){
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
}
void insert_row(int pos){
    if(rows==N){
        printf("Row limit reached\n");
        return;
    }
    if(pos<1||pos>rows+1){
        printf("Invalid position\n");
        return;
    }
    for(i=rows-1;i>=pos-1;i--){
        for(j=0;j<cols;j++)
            arr[i+1][j]=arr[i][j];
    }
    printf("Enter elements of new row:\n");
    for(j=0;j<cols;j++)
        scanf("%d",&arr[pos-1][j]);
    rows++;
}
void delete_row(int pos){
    if(rows==0){
        printf("Matrix empty\n");
        return;
    }
    if(pos<1||pos>rows){
        printf("Invalid position\n");
        return;
    }
    for(i=pos-1;i<rows-1;i++){
        for(j=0;j<cols;j++)
            arr[i][j]=arr[i+1][j];
    }
    rows--;
}
void insert_col(int pos){
    if(cols==N){
        printf("Column limit reached\n");
        return;
    }
    if(pos<1||pos>cols+1){
        printf("Invalid position\n");
        return;
    }
    for(j=cols-1;j>=pos-1;j--){
        for(i=0;i<rows;i++)
            arr[i][j+1]=arr[i][j];
    }
    printf("Enter elements of new column:\n");
    for(i=0;i<rows;i++)
        scanf("%d",&arr[i][pos-1]);
    cols++;
}
void delete_col(int pos){
    if(cols==0){
        printf("Matrix empty\n");
        return;
    }
    if(pos<1||pos>cols){
        printf("Invalid position\n");
        return;
    }
    for(j=pos-1;j<cols-1;j++){
        for(i=0;i<rows;i++)
            arr[i][j]=arr[i][j+1];
    }
    cols--;
}
int main(){
    int ch,pos;
    printf("Enter rows and cols: ");
    scanf("%d%d",&rows,&cols);
    if(rows>N||cols>N||rows<0||cols<0){
        printf("Invalid size\n");
        return 0;
    }
    printf("Enter elements:\n");
    for(i=0;i<rows;i++)
        for(j=0;j<cols;j++)
            scanf("%d",&arr[i][j]);
    do{
        printf("\n1.Display\n2.Insert Row\n3.Delete Row\n4.Insert Column\n5.Delete Column\n0.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: display(); break;
            case 2: printf("Enter position: ");
                    scanf("%d",&pos);
                    insert_row(pos);
                    break;
            case 3: printf("Enter position: ");
                    scanf("%d",&pos);
                    delete_row(pos);
                    break;
            case 4: printf("Enter position: ");
                    scanf("%d",&pos);
                    insert_col(pos);
                    break;
            case 5: printf("Enter position: ");
                    scanf("%d",&pos);
                    delete_col(pos);
                    break;
            default: printf("Invalid choice\n");
        }
    }while(ch!=0);
    return 0;
}