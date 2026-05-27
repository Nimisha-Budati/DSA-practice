//Frequency of each element in array
#include<stdio.h>
#define N 50
int main(){
    int n;
    int arr[N],visited[N];
    printf("Enter size: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        if(visited[i]==1)
            continue;
        int count=1;
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
                visited[j]=1;
            }
        }
        printf("%d occurs %d times\n",arr[i],count);
    }
    return 0;
}