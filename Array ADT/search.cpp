#include <iostream>
#include "array_adt.cpp"

void SwapPosition(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array *arr, int x, int method = -1)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == x)
        {
            int index = i;
            if (method == 0 && index > 0)
            {
                // Transposition
                SwapPosition(&arr->A[i], &arr->A[i - 1]);
                index = i - 1;
            }
            else if (method == 1)
            {
                // Move to front
                SwapPosition(&arr->A[i], &arr->A[0]);
                index = 0;
            }
            return index;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int x)
{   // Had O(log n) complexity -> Ex. n = 16 =? 16/2//2/2/2 can be done. i.e. 2^4 = 16.
    // we take ceil
    int high = arr.length;
    int low = 0;

    while (high >= low)
    {
        int mid = (high + low) / 2;
        if (arr.A[mid] == x)
            return mid;
        else if (arr.A[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int RecursiveBinarySearch(struct Array arr, int x, int high, int low)
{
    if (high >= low)
    {
        int mid = (high + low) / 2;
        if (arr.A[mid] == x)
            return mid;
        else if (arr.A[mid] > x)
        {
            return RecursiveBinarySearch(arr, x, mid - 1, low);
        }
        else
        {
            return RecursiveBinarySearch(arr, x, high, mid + 1);
        }
    }
    return -1;
}

int main()
{
    Array arr = {{2, 3, 4, 5, 6, 7}, 10, 6};
    int index = -1;

    std::cout << RecursiveBinarySearch(arr, 2, 6, 0);
}

// if key element is found
// Transposition = move it ahead by 1 every time it is searched O(n-1) next time
// Move to front = move it at the start O(1) next time