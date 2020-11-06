/*------------------------------------------------------------------------------
    * File:        SortLib.h                                                   *
    * Description: Sort functions library                                      *
    * Created:     6 nov 2020                                                  *
    * Copyright:   (C) 2020 MIPT                                               *
    * Author:      Artem Puzankov                                              *
    * Email:       puzankov.ao@phystech.edu                                    *
    */
//------------------------------------------------------------------------------

#ifndef SORTLIB_H_INCLUDED
#define SORTLIB_H_INCLUDED

#include <stdlib.h>
#include <mem.h>

//#define NDEBUG
#include <assert.h>


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

#include "SortLib.cpp"

#endif // SORTLIB_H_INCLUDED
