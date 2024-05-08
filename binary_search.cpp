// binary search
#include <iostream>
#include <algorithm>

using namespace std;

class BinarySearch
{
    public:
        void sorting_array(int arr[], int arr_size);
        int binary_srch(int arr[], int item, int arr_size);
};

void BinarySearch::sorting_array(int arr[], int arr_size)
{
    unsigned int i, j, temp;

    // bubble sort
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

// index search
int BinarySearch::binary_srch(int arr[], int item, int arr_size)
{
    unsigned int low, high, middle;

    low = 0;
    high = arr_size - 1;

    while(low <= high){
        middle = low + (high - low) / 2;

        if(arr[middle] == item)
            return middle;
        else if(arr[middle] < item)
            low = middle + 1;
        else
            high = middle - 1;
    }
    return -1;
}

int main(void)
{
    BinarySearch bs;

    int arr[] = {7, 3, 0, 8, 1, 3, 2, 5, 0, 10};
    unsigned int arr_size, result, i, item = 8;

    arr_size = sizeof(arr)/sizeof(arr[0]);
    bs.sorting_array(arr, arr_size);
    result = bs.binary_srch(arr, item, arr_size);

    printf("Sorted Array: ");
    for(i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);

    printf("\n\n");

    if(result == -1)
        printf("%u Not Found.!", item);
    else
        printf("%u Found.! Index at %u", item, result);

    return 0;
}
