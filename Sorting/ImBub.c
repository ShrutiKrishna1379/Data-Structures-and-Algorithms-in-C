#include <stdio.h>

int main()
{
  int n, i, j, temp,flag;

  printf("Enter number of elements:");
  scanf("%d", &n);

  printf("Enter %d integers:", n);
  int arr[n];
  for (i=0;i<n;i++) scanf("%d", &arr[i]);

  for (i=0;i<n-1;i++){
    flag=0;
    for (j=0;j<n-i-1;j++){
      if(arr[j]>arr[j+1]){
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
        flag=1;
      }
    }
    if(flag==0) break;
  }

  printf("Sorted list in ascending order:\n");

  for (i=0;i<n;i++) printf("%d ", arr[i]);
  printf("\n");

  return 0;
}