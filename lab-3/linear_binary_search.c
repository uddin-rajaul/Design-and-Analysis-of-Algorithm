#include<stdio.h>

int linear_counter= 0;
int binary_counter= 0;

int linear_search(int A[], int n, int x){
    for (int i = 0; i < n; i++){
        linear_counter++;
        if (A[i] == x)
            return i;
    }
    return -1;
}

int binary_search(int A[],int n,int x){
    int low=0, high=n-1, mid;
    while(low <= high){
        binary_counter++;
        mid = (low + high)/2;
        if (A[mid] ==  x){
            return mid;
        }
        else if (x<A[mid]){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}
int main(){
    int A[50] , n, x;
    printf("Enter range for array: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("%d element: ", i+1);
        scanf("%d", &A[i]);
    }    
    printf("Enter element to find: ");
    scanf("%d", &x);
    int high = sizeof(A)/ sizeof(int);
    printf("\n--------------Linear search--------------n");
    int linear_result = linear_search(A, n, x);
    if(linear_result == -1){
        printf("\nElement not found\n");
        printf("Linear Search Time Complexity: %d", linear_counter);

    }
    else{
        printf("\nElement found at index %d\n", linear_result);
        printf("Linear Search Time Complexity: %d", linear_counter);
    }
    printf("\n--------------Binary search--------------\n");
    
    int binary_result = binary_search(A,n, x);
    if(binary_result != -1){
        printf("\nElement found at index %d\n", binary_result);
        printf("Binary Search Time Complexity: %d", binary_counter);
    }
    else{
        printf("\nElement not found\n");
        printf("Binary Search Time Complexity: %d", binary_counter);


    }
}