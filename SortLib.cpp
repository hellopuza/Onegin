/*------------------------------------------------------------------------------
    * File:        SortLib.cpp                                                 *
    * Description: Implementations of sort functions                           *
    * Created:     6 nov 2020                                                  *
    * Copyright:   (C) 2020 MIPT                                               *
    * Author:      Artem Puzankov                                              *
    * Email:       puzankov.ao@phystech.edu                                    *
    */
//------------------------------------------------------------------------------

#include "SortLib.h"

//------------------------------------------------------------------------------

void TreeSort(void* values, size_t num, size_t size, int (*CompareFunc)(const void*, const void*))
{
    assert(values);
    assert(num);
    assert(size);
    assert(CompareFunc);

    struct node* proot = nullptr;

    for (int i = 0; i < num; ++i)
    {
        insert(&proot, (char*)values + size*i, size, CompareFunc);
    }

    rewrite(proot, values, size);
}

//------------------------------------------------------------------------------

void insert(struct node** pproot, void* pvalue, size_t size, int (*CompareFunc)(const void*, const void*))
{
    assert(pproot);
    assert(pvalue);
    assert(size);
    assert(CompareFunc);

    if (not *pproot)
    {
        *pproot = (struct node*)calloc(1, sizeof(struct node));

        (*pproot)->data = (void*)calloc(1, 1);
        memmove((*pproot)->data, pvalue, size);

        (*pproot)->left  = nullptr;
        (*pproot)->right = nullptr;
    }
    else if (CompareFunc(pvalue, (*pproot)->data) < 0)
        insert(&(*pproot)->left,  pvalue, size, CompareFunc);
    else
        insert(&(*pproot)->right, pvalue, size, CompareFunc);
}

//------------------------------------------------------------------------------

void* rewrite(struct node* proot, void* values, size_t size)
{
    assert(values);
    assert(size);

    if (proot != NULL)
    {
        values = rewrite(proot->left, values, size);

        memmove(values, proot->data, size);

        values = rewrite(proot->right, (char*)values + size, size);

        free(proot);
    }

    return values;
}

//------------------------------------------------------------------------------
