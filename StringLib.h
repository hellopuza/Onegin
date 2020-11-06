/*------------------------------------------------------------------------------
    * File:        StringLib.h
    * Description: String functions library
    * Created:     6 nov 2020
    * Copyright:   (C) 2020 MIPT
    * Author:      Artem Puzankov
    * Email:       puzankov.ao@phystech.edu
    */
//------------------------------------------------------------------------------

#ifndef STRINGLIB_H_INCLUDED
#define STRINGLIB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys\stat.h>

//#define NDEBUG
#include <assert.h>

#define OK       0
#define NOLINES  1
#define NOSYMB   2

//------------------------------------------------------------------------------

const char* output_name_1 = "text/SortedFromLeft.txt";
const char* output_name_2 = "text/SortedFromRight.txt";
const char* original_name = "text/original.txt";

const char* default_name = "text/Onegin.txt";

//------------------------------------------------------------------------------

typedef struct line
{
    char*  str = nullptr;
    size_t len = 0;
} line_t;

typedef struct text_info
{
   char*   Text        = nullptr;
   size_t  Size        = 0;
   size_t  LineNum     = 0;
   line_t* Lines       = nullptr;
} text_t;

//------------------------------------------------------------------------------
/*! @brief   Get name of file from command line
 *
 *  @param   argc is number of command line arguments
 *  @param   argv is arguments
 *
 *  @return  name of file
 */

char* GetFileName (int argc, char** argv);

//------------------------------------------------------------------------------
/*! @brief   Get pointer to file
 *
 *  @param   FileName is file name
 *
 *  @return  pointer to file
 */

FILE* GetFilePointer (char* FileName);

//------------------------------------------------------------------------------
/*! @brief   Fills the structure
 *
 *  @param   txtstruct is the structure to be filled
 *  @param   fp is pointer to file
 *
 *  @return  error code
 */

int fillinStruct (text_t* txtstruct, FILE* fp);

//------------------------------------------------------------------------------
/*! @brief   Get size of file
 *
 *  @param   fp is pointer to file
 *
 *  @return  size of file
 */

size_t CountSize (FILE* fp);

//------------------------------------------------------------------------------
/*! @brief   Get text of file
 *
 *  @param   fp is pointer to file
 *  @param   len is length of text
 *
 *  @return  pointer to text
 */

char* GetText (FILE* fp, size_t len);

//------------------------------------------------------------------------------
/*! @brief   Get number of lines in text
 *
 *  @param   text contains text
 *  @param   len is length of text
 *
 *  @return  number of lines in text
 */

size_t GetLineNum (char* text, size_t len);

//------------------------------------------------------------------------------
/*! @brief   Get pointers to start of lines and their lengths
 *
 *  @param   text contains text
 *  @param   num is number of strings
 *
 *  @return  array of lines
 */

struct line* GetLine (const char* text, size_t num);

//------------------------------------------------------------------------------
/*! @brief   Compare two lines from left alphabetically
 *
 *  @param   p1 is pointer to first line
 *  @param   p2 is pointer to second line
 *
 *  @return  positive integer if first line bigger then second
 *  @return  0 if first line the same as second
 *  @return  negative integer if first line smaller then second
 */

int CompareFromLeft (const void *p1, const void *p2);

//------------------------------------------------------------------------------
/*! @brief   Compare two lines from right alphabetically
 *
 *  @param   p1 is pointer to first line
 *  @param   p2 is pointer to second line
 *
 *  @return  positive integer if first line bigger then second
 *  @return  0 if first line the same as second
 *  @return  negative integer if first line smaller then second
 */

int CompareFromRight (const void *p1, const void *p2);

//------------------------------------------------------------------------------
/*! @brief   Copmare two strings by letters
 *
 *  @param   line1 is first line
 *  @param   line2 is second line
 *  @param   dir is direction of comparing (+1 - compare from left, -1 - compare from right)
 *
 *  @return  positive integer if first line bigger then second
 *  @return  0 if first line the same as second
 *  @return  negative integer if first line smaller then second
 */

int StrCompare (line_t line1, line_t line2, int dir);

//------------------------------------------------------------------------------
/*! @brief   Write lines to file
 *
 *  @param   lines is array of lines
 *  @param   num is number of lines
 *  @param   filename is name of file
 */

void Write (line_t* Lines, size_t num, const char* filename);

//------------------------------------------------------------------------------
/*! @brief   Print text to file
 *
 *  @param   text contains text
 *  @param   len is length of text
 *  @param   filename is name of file
 */

void Print (char* text, size_t len, const char* filename);

//------------------------------------------------------------------------------
/*! @brief   Check that char is letter
 *
 *  @param   c is char
 *
 *  @return  1 if c is letter
 *  @return  0 if c is not letter
 */

int isAlpha (const unsigned char c);

//------------------------------------------------------------------------------

#include "StringLib.cpp"

#endif // STRINGLIB_H_INCLUDED