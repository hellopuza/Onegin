/*------------------------------------------------------------------------------
    * File:        TreeSort.h                                                  *
    * Description: Treesort functions                                          *
    * Created:     9 nov 2020                                                  *
    * Author:      Artem Puzankov                                              *
    * Email:       puzankov.ao@phystech.edu                                    *
    * GitHub:      https://github.com/hellopuza                                *
    * Copyright © 2021 Artem Puzankov. All rights reserved.                    *
    *///------------------------------------------------------------------------

#ifndef TREESORT_H_INCLUDED
#define TREESORT_H_INCLUDED

//#define NDEBUG

#include <assert.h>
#include <memory.h>
#include <stdlib.h>



struct node
{
    void*  data         = nullptr;
    struct node* left   = nullptr;
    struct node* right  = nullptr;
};

//------------------------------------------------------------------------------
/*! @brief   Tree sort
 *
 *  @param   values is array of values
 *  @param   num is number of values
 *  @param   size is size of value
 *  @param   CompareFunc is comparison function
 */

void TreeSort (void* values, size_t num, size_t size, int (*CompareFunc)(const void*, const void*));

//------------------------------------------------------------------------------
/*! @brief   Insert pointer to value to binary tree of struct
 *
 *  @param   pproot is pointer to pointer to struct
 *  @param   pvalue is pointer to value
 *  @param   CompareFunc is comparison function
 */

void insert (struct node** pproot, void* pvalue, size_t size, int (*CompareFunc)(const void*, const void*));

//------------------------------------------------------------------------------
/*! @brief   Rewrite contents of tree into array
 *
 *  @param   proot is pointer to struct
 *  @param   values is array of values
 *  @param   size is size of value
 *
 *  @return  pointer to value
 */

void* rewrite (struct node* proot, void* values, size_t size);

//------------------------------------------------------------------------------

#endif // TREESORT_H_INCLUDED
