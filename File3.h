#include "File1.h"
#ifndef FILE3_H_INCLUDED
#define FILE3_H_INCLUDED
void Find_str(book *arr, unsigned count);
void Sort_arr(book *arr, unsigned count);
void Edit_str(book *arr, unsigned count);
void Add_str(book *arr, unsigned &count);
void Delete_str(book *arr, unsigned &count);
void Show_data(book *arr, unsigned &count);
char* format(char* str, int n);
#endif

