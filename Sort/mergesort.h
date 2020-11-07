/*------------------------------------------------------------------------------
    * File:        mergesort.h                                                  *
    * Description: Mergesort functions                                          *
    * Created:     9 nov 2020                                                  *
    * Copyright:   (C) 2020 MIPT                                               *
    * Author:      Artem Puzankov                                              *
    * Email:       puzankov.ao@phystech.edu                                    *
    */
//------------------------------------------------------------------------------

#ifndef MERGESORT_H_INCLUDED
#define MERGESORT_H_INCLUDED

#include <stdlib.h>
#include <mem.h>

//#define NDEBUG
#include <assert.h>

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

#include "mergesort.cpp"

#endif // MERGESORT_H_INCLUDED
