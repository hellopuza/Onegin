/*------------------------------------------------------------------------------
    * File:        main.cpp                                                    *
    * Description: Program for sorting strings of text file                    *
    * Created:     6 nov 2020                                                  *
    * Author:      Artem Puzankov                                              *
    * Email:       puzankov.ao@phystech.edu                                    *
    * GitHub:      https://github.com/hellopuza                                *
    * Copyright © 2021 Artem Puzankov. All rights reserved.                    *
    *///------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>

#include "StringLib/StringLib.h"
#include "SortLib/SortLib.h"

const char* output_name_1 = "SortedFromLeft.txt";
const char* output_name_2 = "SortedFromRight.txt";
const char* original_name = "original.txt";

//------------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");

    printf("\n ** -- **       Program sort strings of text file      ** -- **"
           "\n ** -- ** Sorting from left   and   Sorting from right ** -- **\n");


    char* input_file_name = GetFileName(argc, argv);
    Text input_text(input_file_name);

    MergeSort(input_text.lines_, input_text.num_, sizeof(Line), CompareFromLeft);
    Write    (input_text.lines_, input_text.num_, output_name_1);

    MergeSort(input_text.lines_, input_text.num_, sizeof(Line), CompareFromRight);
    Write    (input_text.lines_, input_text.num_, output_name_2);

    printf("\n Sort finished. Check files \"%s\" and  \"%s\"\n", output_name_1, output_name_2);

    Print(input_text.text_, input_text.size_, original_name);

    printf("\n Original text is available in file \"%s\"\n", original_name);


    return 0;
}
