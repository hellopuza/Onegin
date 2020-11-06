/*------------------------------------------------------------------------------
    * File:        Onegin.cpp                                                  *
    * Description: Program sort strings of text file                           *
    * Created:     6 nov 2020                                                  *
    * Copyright:   (C) 2020 MIPT                                               *
    * Author:      Artem Puzankov                                              *
    * Email:       puzankov.ao@phystech.edu                                    *
    */
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include "StringLib.h"
#include "SortLib.h"

//------------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"Russian");

    printf("\n ** -- **       Program sort strings of text file      ** -- **"
           "\n ** -- ** Sorting from left   and   Sorting from right ** -- **\n");


    char* InputFileName = GetFileName(argc, argv);
    FILE* InputFILE = GetFilePointer(InputFileName);

    text_t InputText;

    fillinStruct(&InputText, InputFILE);

    fclose(InputFILE);


    TreeSort(InputText.Lines, InputText.LineNum, sizeof(struct line), CompareFromLeft);
    Write   (InputText.Lines, InputText.LineNum, output_name_1);

    TreeSort(InputText.Lines, InputText.LineNum, sizeof(struct line), CompareFromRight);
    Write   (InputText.Lines, InputText.LineNum, output_name_2);

    printf("\n Sort finished. Check files \"%s\" and  \"%s\"\n", output_name_1, output_name_2);


    Print(InputText.Text, InputText.Size, original_name);

    printf("\n Original text available in file \"%s\"\n", original_name);


    return 0;
}
