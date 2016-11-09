
#include <iostream>
#include <cstring>

int* merge(int *arr1, int *arr2, int s1, int s2, int SizeResult=0)
{
    SizeResult = SizeResult == 0? s1 + s2: SizeResult;
    int *result_arr = new int[ SizeResult ];
    int n = 0;
    while (s1 && s2 && n < SizeResult)
    {
        if (*arr1 < *arr2)
        {
            result_arr[n] = *(arr1++);
            --s1;
        }
        else
        {
            result_arr[n] = *(arr2++);
            --s2;
        }
        ++n;
    }
    if (!s1)
        for (int i = 0; i < s2 && n < SizeResult; ++i)
            result_arr[n++] = *(arr2++);
    else
        for (int i = 0; i < s1 && n < SizeResult; ++i)
            result_arr[n++] = *(arr1++);
    return result_arr;
}

void merge_sort(int* Buffer, int Size)
{
    int n = 1, l, remain;
    int* arr;
    while (n < Size)
    {
        l = 0;
        while (l < Size)
        {
            if (l + n >= Size) break;
            remain = (l + n * 2 > Size) ? (Size - (l + n)) : n;
            arr = merge(Buffer + l, Buffer + l + n, n, remain);
            memcpy(Buffer+l,arr,sizeof(int)*(n+remain));
            delete[] arr;
            l += n * 2;
        }
        n *= 2;
    }
}

void sort_k_first(int* Result, int* Arr, int Portion, int Number)
{
    for( int i = 0; i < Portion; ++i)
        std::cin>>Result[i];
    merge_sort(Result, Portion);

    int j = Portion;
    int* temp;
    while ( j < Number )
    {
        int i;
        for( i = 0; i < Portion && j < Number; ++i, ++j)
            std::cin>>Arr[i];

        merge_sort(Arr, i);
        temp=merge(Result, Arr, Portion, i, Portion);
        memcpy(Result,temp,sizeof(int)*Portion);
        delete[] temp;
    }
}

int main()
{
    int Number = 0, Portion = 0;

    std::cin>> Number >> Portion;
    int* Result = new int [Portion];
    int* Arr = new int [Portion];
    sort_k_first(Result, Arr, Portion, Number);
    for ( int i = 0; i < Portion; ++i)
        std::cout<<Result[i]<<' ';
    delete[] Arr;
    delete[] Result;
    return 0;
}
