#include <string>
#ifndef FILE1_H_INCLUDED
#define FILE1_H_INCLUDED
enum eCMD {CMD_EXIT = -1, CMD_NONE = 0, CMD_READ, CMD_SHOW, CMD_EDIT, CMD_ADD, CMD_DELETE, CMD_SORT, CMD_FIND, CMD_SAVE, CMD_AVG};
const int MAX_SIZE = 15;
struct book {
    char name[30];
    char title[30];
    int year;
    float cost;
    float rating;
};
#endif

