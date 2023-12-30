#include <stdio.h>

int main()
{
    int n, i, j, min;

    printf("Enter number of elements:");
    scanf("%d", &n);

    printf("Enter %d integers:", n);
    int arr[n];
    for (i=0;i<n;i++) scanf("%d", &arr[i]);
        
    for (i = 0; i < n-1; i++)      
    {  
        min= i;   
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min])  
            min = j;  
 
        int temp = arr[min];  
        arr[min] = arr[i];  
        arr[i] = temp;  
    }  

  printf("Sorted list in ascending order:\n");

  for (i=0;i<n;i++) printf("%d ", arr[i]);
  printf("\n");
  
  return 0;
}