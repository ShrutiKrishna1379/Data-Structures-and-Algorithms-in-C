#include <stdio.h>

int main()
{
    int n, i, j, temp;
    
    printf("Enter number of elements:");
    scanf("%d", &n);
    
    printf("Enter %d integers:", n);
    int arr[n];
    for (i=0;i<n;i++) scanf("%d", &arr[i]);
    
    for (i = 1; i < n; i++) {  
       temp = arr[i];  
       j = i - 1;  

       while(j>=0 && temp <= arr[j])  
       {    
           arr[j+1] = arr[j];     
           j = j-1;    
       }    
       arr[j+1] = temp;    
    }  
    
    printf("Sorted list in ascending order:\n");
    
    for (i=0;i<n;i++) printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}        