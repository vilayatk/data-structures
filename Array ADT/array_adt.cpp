#include <iostream>

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

void Delete(struct Array* arr, int index)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = 0;
        for (int i = index; i < arr->length; i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
    }
}

void Insert(struct Array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

// int main()
// {
//     struct Array arr = {{2, 3, 4, 5}, 10, 4};
//     Append(&arr, 10);
//     Insert(&arr, 0, -2);
//     Display(arr);
//     Delete(&arr, 3);
//     Display(arr);
//     return 0;
// }