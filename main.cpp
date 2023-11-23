#include "File1.h"
#include "File2.h"
#include "File3.h"
#include <windows.h>
using namespace std;
book arr[MAX_SIZE];
unsigned count = 0;
using namespace std;
eCMD menu(){
    while(true)
    {
        system("cls");
        puts("Выберите действие:");
        puts("1 - Открыть csv файл");
        puts("2 - Просмотр данных");
        puts("3 - Записать данные в файл");
        puts("4 - Выход из программы");
        unsigned opt;
        fflush(stdin);
        scanf("%u", &opt);
        switch(opt) {
            case 1: return CMD_READ;
            case 2: return CMD_SHOW;
            case 3: return CMD_SAVE;
            case 4: return CMD_EXIT;
            default: puts("Вы ввели неправильную команду");
            system("pause");
        }
    }
}
int main(){
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    eCMD cmd = CMD_NONE;
    int k=1;
    while(k==1){
        system("cls");
        cmd = menu();
        if (cmd == CMD_READ) Read_data(arr, count);
        else if (cmd == CMD_SHOW) Show_data(arr, count);
        else if (cmd == CMD_SAVE) Save_data(arr, count);
        else if (cmd == CMD_EXIT) k = 0;
    }
    puts("Работа закончена!");
    system("pause");
    return 0;
}
