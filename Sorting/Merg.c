#include <stdio.h>

void merge(int arr[], int start, int mid, int end);
void mergeSort(int arr[], int start, int end);

int main()
{
  int n, i, j, temp;

  printf("Enter number of elements:");
  scanf("%d", &n);

  printf("Enter %d integers:", n);
  int arr[n];
  for (i=0;i<n;i++) scanf("%d", &arr[i]);

   mergeSort(arr, 0, n - 1);  

  printf("Sorted list in ascending order:\n");

  for (i=0;i<n;i++) printf("%d ", arr[i]);
  printf("\n");
  
  return 0;
}

void merge(int arr[], int start, int mid, int end)    
{    
    int i, j, k;  
    int n1 = mid - start + 1;    
    int n2 = end - mid;    
      
    int LeftArray[n1], RightArray[n2]; //temporary arrays  
      
    /* copy data to temp arrays */  
    for ( i = 0; i < n1; i++)    
    LeftArray[i] = arr[start + i];    
    for ( j = 0; j < n2; j++)    
    RightArray[j] = arr[mid + 1 + j];    
      
    i = 0; /* initial index of first sub-array */  
    j = 0; /* initial index of second sub-array */   
    k = start;  /* initial index of merged sub-array */  
      
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            arr[k] = LeftArray[i];    
            i++;    
        }    
        else    
        {    
            arr[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    
    {    
        arr[k] = LeftArray[i];    
        i++;    
        k++;    
    }    
      
    while (j<n2)    
    {    
        arr[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}    
  
void mergeSort(int arr[], int start, int end)  
{  
    if (start < end)   
    {  
        int mid = (start + end) / 2;  
        mergeSort(arr, start, mid);  
        mergeSort(arr, mid + 1, end);  
        merge(arr, start, mid, end);  
    }  
}  