// labr_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <locale>
#include <windows.h>
using namespace std;

// Структура Student, що представляє студента
struct Student {
    string name;
    int group;
    int propysk;
};

int main() {
    setlocale(LC_CTYPE, "ukr");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    const int k = 10; 
    Student students[k];

    // Введення даних про студентів
    for (int i = 0; i < k; i++) {
        cout << "Введiть данi для студента " << i + 1 << ":" << endl;
        cout << "ПIБ: ";
        cin.ignore();  
        getline(cin, students[i].name);  
        cout << "Номер групи: ";
        cin >> students[i].group;
        cout << "Кiлькiсть пропускiв: ";
        cin >> students[i].propysk;
    }

    // Впорядкування записів у масиві за зменшенням номера групи
    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (students[i].group < students[j].group) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    cout << "____________________________________________________________________________";
    cout << "\n";
    cout << "\n";
    // Виведення ПІБ і номерів груп для студентів, кількість пропусків яких більша за 20
    cout << "Студенти з кiлькiстю пропускiв бiльше за 20:" << endl;
    cout << "____________________________________________________________________________";
    cout << "\n";
    bool found = false;
    for (int i = 0; i < k; i++) {
        if (students[i].propysk > 20) {
            cout << "ПIБ: " << students[i].name << ", Номер групи: " << students[i].group << endl;
            cout << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "Немає студентiв з кiлькiстю пропускiв бiльше 20." << endl;
    }

    return 0;
}
