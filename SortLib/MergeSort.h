/*------------------------------------------------------------------------------
    * File:        MergeSort.h                                                 *
    * Description: Mergesort functions                                         *
    * Created:     9 nov 2020                                                  *
    * Author:      Artem Puzankov                                              *
    * Email:       puzankov.ao@phystech.edu                                    *
    * GitHub:      https://github.com/hellopuza                                *
    * Copyright © 2021 Artem Puzankov. All rights reserved.                    *
    *///------------------------------------------------------------------------

#ifndef MERGESORT_H_INCLUDED
#define MERGESORT_H_INCLUDED

//#define NDEBUG

#include <assert.h>
#include <memory.h>
#include <stdlib.h>


//------------------------------------------------------------------------------
/*! @brief   Merge sort
 *
 *  @param   values is array of values
 *  @param   num is number of values
 *  @param   size is size of value
 *  @param   CompareFunc is comparison function
 */

void MergeSort (void* values, size_t num, size_t size, int (*CompareFunc)(const void*, const void*));

//------------------------------------------------------------------------------
/*! @brief   Merge sort with borders
 *
 * @param    values is array of values
 * @param    left is left border of array
 * @param    right is right border of array
 * @param    size is size of value
 * @param    CompareFunc is comparison function
 */

void MSort (void* values, int left, int right, size_t size, int (*CompareFunc)(const void*, const void*));

//------------------------------------------------------------------------------
/*! @brief   Merge two arrays
 *
 * @param    values is array of values
 * @param    left is left border of array
 * @param    right is right border of array
 * @param    middle is middle of array
 * @param    size is size of value
 * @param    CompareFunc is comparison function
 */

void Merge (void* values, int left, int right, int middle, size_t size, int (*CompareFunc)(const void*, const void*));

//------------------------------------------------------------------------------

#endif // MERGESORT_H_INCLUDED
