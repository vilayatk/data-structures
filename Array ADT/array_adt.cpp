#include <iostream>
#include "../helper_functions.cpp"
struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        std::cout << arr.A[i] << " | ";
    }
    std::cout << std::endl;
}

void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
    else
        std::cout << "Error! Array capacity reached";
}

void Delete(struct Array *arr, int index)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = 0;
        for (int i = index; i < arr->length; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
}

void ReverseArray(struct Array *arr)
{
    struct Array arr_2 = *arr;
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = arr_2.A[arr->length - i - 1];
    }
}

void ReverseArraySwap(struct Array *arr)
{
    int i = 0, j = arr->length - 1;

    while (i < j)
    {
        SwapPosition(&arr->A[i], &arr->A[j]);
        i++;
        j--;
    }
}

void Insert(struct Array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int main()
{
    struct Array arr = {{2, 3, 4, 5}, 10, 4};
    Append(&arr, 10);
    Insert(&arr, 0, -2);
    Display(arr);
    ReverseArraySwap(&arr);
    Display(arr);
    return 0;
}