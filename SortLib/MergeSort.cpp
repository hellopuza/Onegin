/*------------------------------------------------------------------------------
    * File:        MergeSort.cpp                                               *
    * Description: Implementations of mergesort functions                      *
    * Created:     9 nov 2020                                                  *
    * Author:      Artem Puzankov                                              *
    * Email:       puzankov.ao@phystech.edu                                    *
    * GitHub:      https://github.com/hellopuza                                *
    * Copyright © 2021 Artem Puzankov. All rights reserved.                    *
    *///------------------------------------------------------------------------

#include "MergeSort.h"

//------------------------------------------------------------------------------

void MergeSort(void* values, size_t num, size_t size, int (*CompareFunc)(const void*, const void*))
{
    assert(values);
    assert(num);
    assert(size);
    assert(CompareFunc);

    MSort(values, 0, num - 1, size, CompareFunc);
}

//------------------------------------------------------------------------------

void MSort(void* values, int left, int right, size_t size, int (*CompareFunc)(const void*, const void*))
{
    assert(values);
    assert(size);
    assert(CompareFunc);

    if (left < right)
    {
        int middle = (right + left)/2;

        MSort(values, left,       middle, size, CompareFunc);
        MSort(values, middle + 1, right,  size, CompareFunc);

        Merge(values, left, right, middle, size, CompareFunc);
    }
}

//------------------------------------------------------------------------------

void Merge(void* values, int left, int right, int middle, size_t size, int (*CompareFunc)(const void*, const void*))
{
    assert(values);
    assert(size);
    assert(CompareFunc);

    size_t LeftLen  = middle - left + 1; // length of left array
    size_t RightLen = right - middle;    // length of right array

    void* LeftArray  = (void*)calloc(LeftLen  + 2, size);
    void* RightArray = (void*)calloc(RightLen + 2, size);

    LeftLen  *= size;
    RightLen *= size;
    left     *= size;
    right    *= size;
    middle    = size*(middle + 1);

    for (int i = 0; i < LeftLen; i += size)
    {
        memcpy((char*)LeftArray + i, (char*)values + (left + i), size);
    }

    for (int i = 0; i < RightLen; i += size)
    {
        memcpy((char*)RightArray + i, (char*)values + (middle + i), size);
    }


    int Li = 0;    // iteration of left array
    int Ri = 0;    // iteration of right array
    int Ai = left; // iteration of main array

    while ((Li < LeftLen) && (Ri < RightLen))
    {
        if (CompareFunc(((char*)LeftArray + Li), ((char*)RightArray + Ri)) < 0)
        {
            memcpy((char*)values + Ai, (char*)LeftArray + Li, size);
            Li += size;
        }
        else
        {
            memcpy((char*)values + Ai, (char*)RightArray + Ri, size);
            Ri += size;
        }
        Ai += size;
    }

    while (Li < LeftLen)
    {
        memcpy((char*)values + Ai, (char*)LeftArray + Li, size);
        Li += size;
        Ai += size;
    }

    while (Ri < RightLen)
    {
        memcpy((char*)values + Ai, (char*)RightArray + Ri, size);
        Ri += size;
        Ai += size;
    }

    free(LeftArray);
    free(RightArray);
}

//------------------------------------------------------------------------------
