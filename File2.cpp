#include "File1.h"
#include <cstring>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <locale>
using namespace std;
void Read_data(book *arr, unsigned &count){
    char filename[20];
    char str[100];
    cout << "Введите название файла:" << endl;
    cin >> filename;
    ifstream fin(filename);
    if(!fin.is_open()) cout << "Ошибка открытия файла!" << endl;
    else {
        while(!fin.eof()) {
            if (count >= MAX_SIZE){
                book *new_arr = new book [count+1];
                for(int i=0; i < count; i++) new_arr[i] = arr[i];
                delete[] arr;
                arr = new_arr;
            }
            char **s =  new char* [5];
            fin.getline(str, 100);
            int i = 0;
            char *token = strtok(str, ";");
            while (token != nullptr) {
                s[i] = new char [strlen(token)];
                strcpy(s[i], token);
                token = strtok(nullptr, ";");
                i++;
            }
            strcpy(arr[count].name, s[0]);
            strcpy(arr[count].title, s[1]);
            arr[count].year = atoi(s[2]);
            arr[count].cost = atof(s[3]);
            arr[count].rating = atof(s[4]);
            count++;
            for (i = 0; i < 5; i++){
                delete[] s[i];
                s[i] = NULL;
            }
            delete[] s;
            s = NULL;
        }
        cout << "Данные считаны успешно\n" << endl;
    }
    fin.close();
    system("pause");
}
void Save_data(book *arr, unsigned count){
    char filename[20];
    cout << "Введите название файла:" << endl;
    cin >> filename;
    ofstream fout;
    fout.open(filename);
    if (!fout.is_open()) cout << "Ошибка открытия файла!" << endl;
    else{
        for(int i=0; i < count; i++){
            fout << arr[i].name << ';' << arr[i].title << ';' << arr[i].year << ';' << arr[i].cost << ';' << arr[i].rating << ';'<< '\n';
        }
        cout << "Данные успешно записаны" << endl;
    }
    fout.close();
    system("pause");
}


