// GromovaStudy.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <Windows.h>
#include "tasks_lib.h"
using namespace std;


void main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size = 0;
    task* planner = new task[size];

    planner = read_tasks(planner, size);
    uint8_t k = 0;
    do {
        system("cls");
        cout << "Выберите, что вы хотите сделать:\n1) Просмотреть все задачи.\n2) Добавить новую задачу.\n3) Удалить задачу.\n4) Редактировать задачу.\n5) Поиск по задачам.\n6) Завершить работу.\nВаш выбор: ";
        cin >> k;
        switch (k)
        {
        case '1':
            system("cls");
            show_all(planner, size);
            system("pause");
            break;
        case '2':
            system("cls");
            planner = add_task(planner, size);
            write_tasks(planner, size);
            system("pause");
            break;
        case '3':
            system("cls");
            planner = delete_task(planner, size);
            write_tasks(planner, size);
            system("pause");
            break;
        case '4':
            system("cls");
            change_task(planner, size);
            system("pause");
            break;
        case '5':
            system("cls");
            task_search(planner, size);
            system("pause");
            break;
        case '6':
            return;
            break;
        default:
            system("cls");
            cout << "Ошибка! Неверный номер пункта меню." << endl;
            system("pause");
            break;
        }
    } while (k != 7);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
