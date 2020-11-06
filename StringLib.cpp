/*------------------------------------------------------------------------------
    * File:        StringLib.cpp                                               *
    * Description: Implementations of string functions                         *
    * Created:     6 nov 2020                                                  *
    * Copyright:   (C) 2020 MIPT                                               *
    * Author:      Artem Puzankov                                              *
    * Email:       puzankov.ao@phystech.edu                                    *
    */
//------------------------------------------------------------------------------

#include "StringLib.h"

//------------------------------------------------------------------------------

char* GetFileName(int argc, char *argv[])
{
    assert(argc);
    assert(argv);

    if (argc > 1)
    {
        return argv[1];
    }

    return (char*)"";
}

//------------------------------------------------------------------------------

FILE* GetFilePointer(char* filename)
{
    assert(filename);

    FILE* fp = nullptr;
    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("\n ERROR. Input file \"%s\" is not found\n", filename);
        printf(" \"%s\" will be opened instead\n", default_name);

        fp = fopen(default_name, "r");
    }

    return fp;
}

//------------------------------------------------------------------------------

int fillinStruct(text_t* txtstruct, FILE* fp)
{
    assert(txtstruct);
    assert(fp);

    int err = OK;


    txtstruct->Size = CountSize(fp);
    if (txtstruct->Size == 0)
        err = NOSYMB;

    txtstruct->Text = GetText(fp, txtstruct->Size);
    assert(txtstruct->Text);

    txtstruct->LineNum = GetLineNum(txtstruct->Text, txtstruct->Size);
    if (txtstruct->LineNum == 0)
        err = NOLINES;

    txtstruct->Lines = GetLine(txtstruct->Text, txtstruct->LineNum);
    assert(txtstruct->Lines);


    switch (err)
    {
        case OK:      /* WOW! Program works correctly! eeeeeeeeeeeeeeeeee */ break;

        case NOSYMB:  printf("\n File is empty!");                           return 0;

        case NOLINES: printf("\n There are no lines with letters in text!"); return 0;

        default:      assert(0);
    }

    return err;
}

//------------------------------------------------------------------------------

size_t CountSize(FILE* fp)
{
    assert(fp);

    struct stat prop;
    fstat(_fileno(fp), &prop);

    return prop.st_size;
}

//------------------------------------------------------------------------------

char* GetText(FILE* fp, size_t len)
{
    assert(fp);
    assert(len);

    char* text = (char*)calloc(len + 2, 1);
    fread(text, 1, len, fp);

    return text;
}

//------------------------------------------------------------------------------

size_t GetLineNum(char* text, size_t len)
{
    assert(text);
    assert(len);

    char* start = text;

    size_t num = 0;

    while (1)
    {
        while (not isAlpha(*text++) && (text - start < len));
        if (isAlpha(*--text))
            ++num;
        else
            break;

        text = strchr(text, '\n') + 1;

        if ((int)text == 1) break;

        *(text - 1) = '\0';
    }

    return num;
}

//------------------------------------------------------------------------------

struct line* GetLine(const char* text, size_t num)
{
    assert(text);
    assert(num);

    struct line* Lines = (struct line*)calloc(num + 2, sizeof(line));
    struct line* temp  = Lines;

    while (num-- > 0)
    {
        while (not isAlpha(*text++));
        --text;

        temp->str = (char*)text;
        temp->len = strlen(text);
        temp++;

        text = strchr(text, '\0') + 1;
    }

    return Lines;
}

//------------------------------------------------------------------------------

int CompareFromLeft(const void* p1, const void* p2)
{
    assert(p1);
    assert(p2);
    assert(p1 != p2);

    return StrCompare(*(line_t*)p1, *(line_t*)p2, 1);
}

//------------------------------------------------------------------------------

int CompareFromRight(const void* p1, const void* p2)
{
    assert(p1);
    assert(p2);
    assert(p1 != p2);

    return StrCompare(*(line_t*)p1, *(line_t*)p2, -1);
}

//------------------------------------------------------------------------------

int StrCompare(line_t line1, line_t line2, int dir)
{
    assert((dir == 1) || (dir == -1));


    int i1 = 0;
    int i2 = 0;

    if (dir == -1)
    {
        i1 = line1.len - 1;
        i2 = line2.len - 1;
    }

    while ((line1.str[i1] != '\0') && (line2.str[i2] != '\0'))
    {
        if (not(isAlpha(line1.str[i1])))
        {
            i1 += dir;
            continue;
        }

        if (not(isAlpha(line2.str[i2])))
        {
            i2 += dir;
            continue;
        }

        if ((unsigned char)line1.str[i1] == (unsigned char)line2.str[i2])
        {
            i1 += dir;
            i2 += dir;
            continue;
        }

        else return ((unsigned char)line1.str[i1] - (unsigned char)line2.str[i2]);
    }

    if (dir == 1)
        return ((unsigned char)line1.str[i1] - (unsigned char)line2.str[i2]);
    else
        return ((unsigned char)line1.str[i2] - (unsigned char)line2.str[i1]);
}

//------------------------------------------------------------------------------

int isAlpha(const unsigned char c)
{
    return (   ((unsigned char)'a' <= c) && (c <= (unsigned char)'z')
            || ((unsigned char)'A' <= c) && (c <= (unsigned char)'Z')
            || ((unsigned char)'à' <= c) && (c <= (unsigned char)'ÿ')
            || ((unsigned char)'À' <= c) && (c <= (unsigned char)'ß'));
}

//------------------------------------------------------------------------------

void Write(line_t* Lines, size_t num, const char* filename)
{
    assert(Lines);
    assert(num);
    assert(filename);

    FILE* fp = fopen(filename, "w");

    for(int i = 0; i < num; ++i)
        fprintf(fp, "%s\n", Lines[i].str);

    fclose(fp);
}

//------------------------------------------------------------------------------

void Print(char* text, size_t len, const char* filename)
{
    assert(text);
    assert(len);
    assert(filename);

    FILE* fp = fopen(filename, "w");

    for (int i = 0; i < len; ++i)
        fputc(text[i], fp);

    fclose(fp);
}

//------------------------------------------------------------------------------
