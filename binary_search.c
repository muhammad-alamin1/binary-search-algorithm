// binary search algorithm
// required -> Array must be sorted
#include <stdio.h>

void sorting_arr(int arr[], int arr_size);
int binary_search(int arr[], int arr_size, int item);

int main(void)
{
    int arr[] = {7, 3, 0, 8, 1, 3, 2, 5, 0, 10};
    int arr_size, result, item = 3;

    arr_size = sizeof(arr) / sizeof(arr[0]);
    sorting_arr(arr, arr_size);

    for(int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);

    printf("\n\n");

    // search index
    result = binary_search(arr, arr_size, item);
    if(result < 0)
        printf("Item Not Found.!");
    else
        printf("Item Found. Index at %d\n", result);

    return 0;
}

// bubble sort
void sorting_arr(int arr[], int arr_size)
{
    unsigned int i, j, temp;

    for(i = 0; i < arr_size; i++){
        for(j = i+1; j < arr_size; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// binary search;
int binary_search(int arr[], int arr_size, int item)
{
    int middle, left, right;

    left = 0;
    right = arr_size - 1;

    while(left <= right){
        middle = left + (right - left) / 2;
        if(arr[middle] == item)
            return middle;
        else if(arr[middle] < item)
            left = middle + 1;
        else
            right = middle - 1;
    }

    return -1;
}
