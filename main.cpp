/*------------------------------------------------------------------------------
    * File:        main.cpp                                                    *
    * Description: Program sort strings of text file                           *
    * Created:     6 nov 2020                                                  *
    * Copyright:   (C) 2020 MIPT                                               *
    * Author:      Artem Puzankov                                              *
    * Email:       puzankov.ao@phystech.edu                                    *
    */
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>

#include "String/StringLib.h"
#include "Sort/SortLib.h"

const char* output_name_1 = "text/SortedFromLeft.txt";
const char* output_name_2 = "text/SortedFromRight.txt";
const char* original_name = "text/original.txt";

//------------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"Russian");

    printf("\n ** -- **       Program sort strings of text file      ** -- **"
           "\n ** -- ** Sorting from left   and   Sorting from right ** -- **\n");


    char* InputFileName = GetFileName(argc, argv);
    FILE* InputFILE = GetFilePointer(InputFileName);

    text_t InputText;

    int err = fillinStruct(&InputText, InputFILE);
    switch (err)
    {
        case OK:      /* WOW! Program works correctly! eeeeeeeeeeeeeeeeee */ break;

        case NOSYMB:  printf("\n File is empty!");                           return 0;

        case NOLINES: printf("\n There are no lines with letters in text!"); return 0;

        default:      assert(0);
    }

    fclose(InputFILE);


    MergeSort(InputText.Lines, InputText.LineNum, sizeof(struct line), CompareFromLeft);
    Write    (InputText.Lines, InputText.LineNum, output_name_1);

    MergeSort(InputText.Lines, InputText.LineNum, sizeof(struct line), CompareFromRight);
    Write    (InputText.Lines, InputText.LineNum, output_name_2);

    printf("\n Sort finished. Check files \"%s\" and  \"%s\"\n", output_name_1, output_name_2);


    Print(InputText.Text, InputText.Size, original_name);

    printf("\n Original text is available in file \"%s\"\n", original_name);


    return 0;
}
