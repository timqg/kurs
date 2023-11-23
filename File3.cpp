#include "File3.h"
#include "File2.h"
#include "File1.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstring>
using namespace std;
eCMD show_menu(){
    while(true)
    {
        puts("Выберите действие:");
        puts("1 - Добавить запись");
        puts("2 - Удалить запись");
        puts("3 - Изменить запись");
        puts("4 - Сортировка");
        puts("5 - Поиск");
        puts("6 - Найти среднее значение");
        puts("7 - Выход");
        unsigned opt;
        fflush(stdin);
        scanf("%u", &opt);
        switch(opt) {
            case 1: return CMD_ADD;
            case 2: return CMD_DELETE;
            case 3: return CMD_EDIT;
            case 4: return CMD_SORT;
            case 5: return CMD_FIND;
            case 6: return CMD_AVG;
            case 7: return CMD_EXIT;
            default: puts("Вы ввели неправильную команду");
            system("pause");
        }
    }
}
char* format(char* str, int n){
    char *res = new char[n+1];
    int r, r1, i;
    r = n - strlen(str);
    r1 = r/2;
    for (i=0; i<r1; i++) res[i]=' ';
    for (i=r1; i<(r1+strlen(str)); i++) res[i] = str[i-r1];
    for (i=r1+strlen(str); i < n; i++) res[i] = ' ';
    res[n]='\0';
    return res;
}
void avg(book *arr, unsigned count){
    int s;
    cout << "Найти среднее значение столбца:\n1-год выпуска\n2-цена\n3-рейтинг" << endl;
    cin >> s;
    if(s==1){
        int sum = 0;
        for(int i=0; i<count; i++) sum = sum + arr[i].year;
        cout << "Среднее значение:" << sum/count << endl;
    }
    else if (s==2){
        float sum = 0;
        for(int i=0; i<count; i++) sum = sum + arr[i].cost;
        cout << "Среднее значение:" << sum/count << endl;
    }
    else if (s==3){
        float sum = 0;
        for(int i=0; i<count; i++) sum = sum + arr[i].rating;
        cout << "Среднее значение:" << sum/count << endl;
    }
    else cout << "Вы ввели неправильную команду" << endl;
    system("pause");
}
void Find_str(book *arr, unsigned count){
    int s;
    char str[40];
    char *t;
    cout << "Осуществить поиск\n1-по автору\n2-по названию"<< endl;
    cin >> s;
    if(s==1 || s==2){
        cout << "Введите строку для поиска:" << endl;
        fflush(stdin);
        cin >> str;
        int f = 0;
        if(s==1){
            for(int i=0; i < count; i++){
                if(arr[i].name == str){
                    if (f==0){
                        cout <<"+------------------------------+------------------------------+---------------+-------+--------+" << endl;
                        cout << "|" << format("Автор", 30) << "|" << format("Название", 30) << "|" << format("Год выпуска", 15) << "|" << format("Цена", 8) << "|" <<  format("Рейтинг", 8) << "|" << endl;
                        cout <<"+------------------------------+------------------------------+---------------+-------+--------+" << endl;
                    }
                    f++;
                    cout << "|" << format(arr[i].name, 30) << "|" << format(arr[i].title, 30) << "|" << format(itoa(arr[i].year, t, 10), 15) << "|  " << setw(4) << arr[i].cost << "  |  " << setw(4) << arr[i].rating << "  |" << endl;
                    cout <<"+------------------------------+-------------------------------+---------------+-------+--------+" << endl;
                }
            }
            if (f==0) cout << "Таких записей нет" << endl;
        }
        else if(s==2){
            for(int i=0; i < count; i++){
                if(arr[i].title == str){
                    if (f==0){
                        cout <<"+------------------------------+------------------------------+---------------+--------+--------+" << endl;
                        cout << "|" << format("Автор", 30) << "|" << format("Название", 30) << "|" << format("Год выпуска", 15) << "|" << format("Цена", 8) << "|" <<  format("Рейтинг", 8) << "|" << endl;
                        cout <<"+------------------------------+------------------------------+---------------+--------+--------+" << endl;
                    }
                    f++;
                    cout << "|" << format(arr[i].name, 30) << "|" << format(arr[i].title, 30) << "|" << format(itoa(arr[i].year, t, 10), 15) << "|  " << setw(4) << arr[i].cost << "  |  " << setw(4) <<  arr[i].rating << "  |" << endl;
                    cout <<"+------------------------------+-------------------------------+---------------+--------+--------+" << endl;
                }
            }
            if (f==0) cout << "Таких записей нет" << endl;
        }
    }
    else cout << "Вы ввели неправильную команду" << endl;
    system("pause");
}

void Sort_arr(book *arr, unsigned count){
    int s1, s2;
    int i, j;
    book tmp;
    cout << "Сортировка\n1-по возрастанию\n2-по убыванию" << endl;
    cin >> s1;
    if (s1==1 || s1==2){
        cout << "Сортировка по\n1-автору\n2-названию\n3-году выпуска\n4-цене\n5-рейтингу" << endl;
        cin >> s2;
        if (s2==1){
            for(i=1; i <count; i++){
                for(j=0;j<count-i; j++){
                    if(s1 == 1 && strcmp(arr[j].name, arr[j+1].name) > 0){
                        tmp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = tmp;
                    }
                    else if(s1 == 2 && strcmp(arr[j].name, arr[j+1].name) < 0){
                        tmp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = tmp;
                    }
                }
            }
        }
        else if (s2==2){
            for(i=1; i <count; i++){
                for(j=0;j<count-i; j++){
                    if(s1 == 1 && strcmp(arr[j].title, arr[j+1].title) > 0){
                        tmp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = tmp;
                    }
                    else if(s1 == 2 && strcmp(arr[j].title, arr[j+1].title) < 0){
                        tmp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = tmp;
                    }
                }
            }
        }
        else if (s2==3){
            for(i=1; i <count; i++){
                for(j=0;j<count-i; j++){
                    if(s1 == 1 && (arr[j].year > arr[j+1].year)){
                        tmp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = tmp;
                    }
                    else if(s1 == 2 && (arr[j].year < arr[j+1].year)){
                        tmp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = tmp;
                    }
                }
            }
        }
        else if (s2==4){
            for(i=1; i <count; i++){
                for(j=0;j<count-i; j++){
                    if(s1 == 1 && (arr[j].cost > arr[j+1].cost)){
                        tmp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = tmp;
                    }
                    else if(s1 == 2 && (arr[j].cost < arr[j+1].cost)){
                        tmp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = tmp;
                    }
                }
            }

        }
        else if (s2==5){
            for(i=1; i <count; i++){
                for(j=0;j<count-i; j++){
                    if(s1 == 1 && (arr[j].rating > arr[j+1].rating)){
                        tmp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = tmp;
                    }
                    else if(s1 == 2 && (arr[j].rating < arr[j+1].rating)){
                        tmp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = tmp;
                    }
                }
            }
        }
        else cout << "Вы ввели неправильную команду" << endl;
    }
    else cout << "Вы ввели неправильную команду" << endl;
}
void Edit_str(book *arr, unsigned count){
    int n, k=1;
    char *t;
    cout << "Введите номер записи, которую хотите изменить(0-выход):" << endl;
    cin >> n;
    if(n==0) k = 0;
    else if (n<1 || n>count) cout << "Такой записи нет" << endl;
    while(k == 1){
        system("cls");
        cout <<"+------------------------------+------------------------------+---------------+--------+--------+" << endl;
        cout << "|" << format("Автор", 30) << "|" << format("Название", 30) << "|" << format("Год выпуска", 15) << "|" << format("Цена", 8) << "|" <<  format("Рейтинг", 8) << "|" << endl;
        cout <<"+------------------------------+------------------------------+---------------+--------+--------+" << endl;
        for (int i = 0; i < count; i++) {
            cout << "|" << format(arr[i].name, 30) << "|" << format(arr[i].title, 30) << "|" << format(itoa(arr[i].year, t, 10), 15) << "|  " << setw(4) << arr[i].cost << "  |  " << setw(4) <<  arr[i].rating << "  |" << endl;
            cout <<"+------------------------------+-------------------------------+---------------+--------+--------+" << endl;
        }
        cout << "Что вы хотите изменить:\n1-Автор\n2-Название\n3-Год выпуска\n4-Цена\n5-Рейтинг\n6-Выход" << endl;
        int s;
        cin >> s;
        cout << "Введите новые данные:"<< endl;
        fflush(stdin);
        if(s==1) cin >> arr[n-1].name;
        else if(s==2) cin >> arr[n-1].title;
        else if(s==3) cin >> arr[n-1].year;
        else if(s==4) cin >> arr[n-1].cost;
        else if(s==5) cin >> arr[n-1].rating;
        else if(s==6) k = 0;
        else cout << "Вы ввели неправильную команду" << endl;
    }

}
void Add_str(book *arr, unsigned &count){
    fflush(stdin);
    if (count >= MAX_SIZE) {
        book *new_arr = new book [count+1];
        for(int i=0; i < count; i++) new_arr[i] = arr[i];
        delete[] arr;
        arr = new_arr;
    }
    cout << "Введите автора книги:" << endl;
    cin >> arr[count].name;
    cout << "Введите название книги:" << endl;
    cin >> arr[count].title;
    cout << "Введите год выпуска книги:" << endl;
    cin >> arr[count].year;
    cout << "Введите цену:" << endl;
    cin >> arr[count].cost;
    cout << "Введите рейтинг книги:" << endl;
    cin >> arr[count].rating;
    count++;
}
void Delete_str(book *arr, unsigned &count){
    int n;
    int k = 1;
    while (k==1){
        cout << "Введите номер записи, которую хотите удалить: ";
        cin >> n;
        if (n >= 1 && n <= count) {
            k = 0;
            n--;
            for (int i = n; i < count; i++) arr[i] = arr[i+1];
            count--;
        }
        else cout << "\nТакой записи нет!" << endl;
    }


}
void Show_data(book *arr, unsigned &count){
    eCMD cmd = CMD_NONE;
    int k = 1;
    char *t;
    while(k==1) {
        system("cls");
        cout <<"+------------------------------+------------------------------+---------------+--------+--------+" << endl;
        cout << "|" << format("Автор", 30) << "|" << format("Название", 30) << "|" << format("Год выпуска", 15) << "|" << format("Цена", 8) << "|" <<  format("Рейтинг", 8) << "|" << endl;
        cout <<"+------------------------------+------------------------------+---------------+--------+--------+" << endl;
        for (int i = 0; i < count; i++) {
            cout << "|" << format(arr[i].name, 30) << "|" << format(arr[i].title, 30) << "|" << format(itoa(arr[i].year, t, 10), 15) << "|  " << setw(4) << arr[i].cost << "  |  " << setw(4) << arr[i].rating << "  |" << endl;
            cout <<"+------------------------------+------------------------------+---------------+--------+--------+" << endl;
        }
        cmd = show_menu();
        if (cmd == CMD_SORT) Sort_arr(arr, count);
        else if (cmd == CMD_FIND) Find_str(arr, count);
        else if (cmd == CMD_EDIT) Edit_str(arr, count);
        else if (cmd == CMD_DELETE) Delete_str(arr, count);
        else if (cmd == CMD_ADD) Add_str(arr, count);
        else if (cmd == CMD_AVG) avg(arr, count);
        else if (cmd == CMD_EXIT) k = 0;
    }
}

