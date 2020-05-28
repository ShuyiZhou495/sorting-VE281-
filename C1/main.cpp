#include <iostream>
#include <string>
#include <ctime>
#include <clock>
using namespace std;


// Swap function
void
swap(int* array, int index1, int index2)
{
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

// Bubble sort (0)
void
bubble(int* array, int arraySize)
{
    // Swapping.
    for (int i = arraySize - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (array[j] > array[j+1])
            {
                swap(array, j+1, j);
            }
        }
    }
}

// Insertion sort (1)
void
insertion(int* array, int arraySize)
{
    for (int i = 1; i < arraySize; i ++)
    {
        int temp = array[i];
        // shift sorted elements greater than t right, and then insert temp in gap.
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (array[j] > temp) array[j+1] = array[j];
            else break;
        }
        array[j+1] = temp;
    }
}

// Selection sort (2)
void selection(int* array, int arraySize)
{
    for (int i = 0; i < arraySize - 1 ; i ++)
    {
        int min_value = array[i];
        int min_index = i;
        int temp = array[i];
        for (int j = i + 1; j <= arraySize - 1; j++){
            if (array[j] < min_value)
            {
                min_value = array[j];
                min_index = j;
            }
        }
        array[i] = min_value;
        array[min_index] = temp;
    }
}

// Merge sort (3)
void
merge (int* array, int left, int mid, int right)
{
    int mergeArray[right - left + 1];
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i < mid + 1 && j <= right) {
        if(array[i] <= array[j]) mergeArray[k++] = array[i++];
        else mergeArray[k++] = array[j++];
    }
    if (j > right)
    {
        while(i<mid+1) mergeArray[k++] = array[i++];
    } else
    {
        while(j<=right) mergeArray[k++] =array[j++];
    }
    for(int n = left; n<=right; n++) array[n] = mergeArray[n-left];
}

void
mergesort(int* array, int left, int right)
{
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergesort(array, left, mid);
    mergesort(array, mid+1, right);
    merge(array, left, mid, right);
}


// Quick sort using extra array (4)
int
partition_extra_array (int* array, int left, int right)
{
    srand(time(NULL));
    int temp = rand() % (right - left + 1);
    int array_temp[right - left + 1];
    int pivot = array[temp + left];
    swap(array, left, temp + left);
    int i_left = 0, i_right = right - left;
    for (int i = left + 1; i <= right; i++)
    {
        if (array[i] < pivot) array_temp[i_left ++] = array[i];
        else array_temp[i_right--] = array[i];
    }
    array_temp[i_left] = pivot;
    for (int i = 0; i<=right - left; i++) array[left + i] = array_temp[i];
    return i_left + left;
}

void
quicksort_extra_array (int* array, int left, int right)
{
    int pivotat;
    if (left >= right) return;
    pivotat = partition_extra_array (array, left, right);
    quicksort_extra_array(array, left, pivotat-1);
    quicksort_extra_array(array, pivotat+1, right);

}

// Quick sort with in-place partitioning (5)
int
partition_in_place(int* array, int left, int right) {
    srand(time(NULL));
    int temp = rand() % (right - left + 1);
    int pivot = array[temp + left];
    swap(array, left, temp+left);
    int i = left + 1, j = right;
    while (true)
    {
        while(array[i] < pivot && i <= right) i++;
        while(array[j] >= pivot && j >= left) j--;
        if(i<j)
        {
            // Swap
            swap(array, i, j);
        } else break;
    }
    if(j<left) j = left;
    // Swap the first with A[j]
    swap(array, left, j);

    return j;
}


void
quicksort_in_place (int* array, int left, int right)
{
    int pivotat;
    if (left >= right) return;
    pivotat = partition_in_place (array, left, right);
    quicksort_in_place(array, left, pivotat-1);
    quicksort_in_place(array, pivotat+1, right);
}

int
main()
{
    int whichSort;
    int arraySize;

    // Read file.
    cin>>whichSort;
    cin>>arraySize;
    // Define Array.
    int* array = new int[arraySize];
    for(int i = 0; i < arraySize ; i++) cin>>array[i];
    // Sort
    switch (whichSort) {
        case 0:
            bubble(array, arraySize);
            break;
        case 1:
            insertion(array, arraySize);
            break;
        case 2:
            selection(array, arraySize);
            break;
        case 3:
            mergesort(array, 0, arraySize-1);
            break;
        case 4:
            quicksort_extra_array(array, 0, arraySize - 1);
            break;
        default:quicksort_in_place(array, 0, arraySize - 1);

    }
    // Save to output.
    for (int i = 0; i < arraySize; i++) cout<<array[i]<<endl;
    // Release memory.
    delete [] array;
    return 0;
}



