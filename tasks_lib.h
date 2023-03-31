#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <Windows.h>
using namespace std;

struct date {
    unsigned int year;
    unsigned int month;
    unsigned int day;
    unsigned int hour;
    unsigned int minute;
};

struct task {
    string name;
    string priority;
    string description;
    float rate;
    date completion;
};

task* read_tasks(task* pln, int& size) { //считывание задач из файла
    int i = 0; string tmp;
    ifstream in("tasks.txt");
    if (!in.is_open()) { //если файла не существовало, создаётся новый файл с 0 задач
        ofstream out;
        out.open("tasks.txt");
        out << '0' << endl;
        out.close();
        return pln;
    }
    else { //если файл существует, открываем
        getline(in, tmp);
        size = stoi(tmp);
        task* temp = new task[size];
        for (int i = 0; i < size; i++) {
            getline(in, temp[i].name);
            getline(in, temp[i].priority);
            getline(in, temp[i].description);
            in >> temp[i].completion.year >> temp[i].completion.month >> temp[i].completion.day >> temp[i].completion.hour >> temp[i].completion.minute;
            getline(in, tmp);
        }
        delete[] pln;
        return temp;
    }

}

void write_tasks(task* pln, int size) { //запись задач в файл
    ofstream out;
    out.open("tasks.txt");
    out << size << endl;
    for (int i = 0; i < size; i++) {
        out << pln[i].name << endl;
        out << pln[i].priority << endl;
        out << pln[i].description << endl;
        out << pln[i].completion.year << ' ' << pln[i].completion.month << ' ' << pln[i].completion.day << ' ' << pln[i].completion.hour << ' ' << pln[i].completion.minute << endl;
    }
    out.close();
}

task* add_task(task* pln, int& size) { //добавление задачи
    task* temp = new task[size + 1];
    for (int i = 0; i < size; i++) temp[i] = pln[i];
    cin.get(); //костыль, не удалять, иначе фигня
    cout << "Введите название задачи: ";
    getline(cin, temp[size].name);
    cout << "Введите приоритет: ";
    getline(cin, temp[size].priority);
    cout << "Введите описание: ";
    getline(cin, temp[size].description);
    cout << "Введите дату выполнения в формате \"дд мм гггг\": ";
    cin >> temp[size].completion.day >> temp[size].completion.month >> temp[size].completion.year;
    cout << "Введите время выполнения в формате \"чч мм\": ";
    cin >> temp[size].completion.hour >> temp[size].completion.minute;
    delete[] pln;
    size++;
    return temp;
}

task* delete_task(task* pln, int& size) { //удаление задачи
    if (size == 0) {
        cout << "Список задач уже пуст." << endl;
        return pln;
    }
    else {
        unsigned int num = 0;
        do {
            system("cls");
            cout << "Выберите номер задачи, которую хотите удалить:" << endl;
            for (int i = 0; i < size; i++) cout << i + 1 << ". " << pln[i].name << endl;
            cout << "Введите 0, чтобы отменить удаление задачи." << endl << "Выбор: ";
            cin >> num;
            if (num == 0) return pln;
            else if (num > size) {
                cout << "Неверный номер. Повторите ввод." << endl;
                system("pause");
            }
        } while (num > size);
        task* temp = new task[size - 1];
        for (int i = 0, j = 0; i < size - 1; i++) {
            if (i != num - 1) {
                temp[j] = pln[i];
                j++;
            }
        }
        delete[] pln;
        size--;
        return temp;
    }
}


void show_task(task* pln, int number) { //вывод одной задачи
    cout << "Название: " << pln[number].name << endl;
    cout << "Приоритет: " << pln[number].priority << endl;
    cout << "Описание: " << pln[number].description << endl;
    cout << "Время: " << pln[number].completion.hour << ':';
    (pln[number].completion.minute == 0) ? cout << "00" : cout << pln[number].completion.minute;
    cout << ' ' << pln[number].completion.day << '.' << pln[number].completion.month << '.' << pln[number].completion.year << endl;
}

void show_all(task* pln, int size) { // вывод всех задач
    if (size == 0) {
        cout << "Список задач пока пуст." << endl;
    }
    else {
        for (int i = 0; i < size; i++) {
            cout << "Задача номер " << i + 1 << ":\n";
            show_task(pln, i);
            cout << endl;
        }
    }
}

void change_task(task* pln, int size) { //редактирование задачи
    unsigned int num = 0;
    do {
        system("cls");
        cout << "Выберите номер задачи, которую хотите изменить:" << endl;
        for (int i = 0; i < size; i++) cout << i + 1 << ". " << pln[i].name << endl;
        cout << "Введите 0, чтобы отменить редактирование задачи." << endl << "Выбор: ";
        cin >> num;
        if (num == 0) return;
        else if (num > size) {
            cout << "Неверный номер. Повторите ввод." << endl;
            system("pause");
        }
    } while (num > size);
    unsigned short k = 0;
    do {
        system("cls");
        cout << "Выбранная задача выглядит так:" << endl;
        show_task(pln, num - 1);
        cout << endl << "Выберите, что вы ходите редактировать:\n1) Название\n2) Приоритет\n3) Описание\n4) Дату и время выполнения\n0) Отменить редактирование\nВведите ваш выбор: ";
        cin >> k;
        if (k == 0) return;
        else if (k > 4) {
            cout << "Неверный номер. Повторите ввод." << endl;
            system("pause");
        }
    } while (k > 4);
    switch (k)
    {
    case 1:
        cin.get(); //костыль, не удалять, иначе фигня
        cout << "Введите новое название задачи: ";
        getline(cin, pln[num - 1].name);
        break;
    case 2:
        cin.get();
        cout << "Введите новый приоритет: ";
        getline(cin, pln[num - 1].priority);
        break;
    case 3:
        cin.get();
        cout << "Введите новое описание: ";
        getline(cin, pln[num - 1].description);
        break;
    case 4:
        cout << "Введите новую дату выполнения в формате \"дд мм гггг\": ";
        cin >> pln[num - 1].completion.day >> pln[num - 1].completion.month >> pln[num - 1].completion.year;
        cout << "Введите новое время выполнения в формате \"чч мм\": ";
        cin >> pln[num - 1].completion.hour >> pln[num - 1].completion.minute;
        break;
    }
}

void name_search(task* pln, int size) {
    string search;
    cin.get(); //костыль, не удалять, иначе фигня
    cout << "Введите название задачи, которую хотите найти: ";
    getline(cin, search);
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (!pln[i].name.find(search)) {
            count++;
            show_task(pln, i);
            cout << endl;
        }
    }
    if (count == 0) cout << "Задачи с таким названием не найдено." << endl;
}

void priority_search(task* pln, int size) {
    string search;
    cin.get(); //костыль, не удалять, иначе фигня
    cout << "Введите приоритет задач для поиска: ";
    getline(cin, search);
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (!pln[i].priority.find(search)) {
            count++;
            show_task(pln, i);
            cout << endl;
        }
    }
    if (count == 0) cout << "Задач с таким приоритетом не найдено." << endl;
}

void description_search(task* pln, int size) {
    string search;
    cin.get(); //костыль, не удалять, иначе фигня
    cout << "Введите описание задачи, которую хотите найти: ";
    getline(cin, search);
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (!pln[i].description.find(search)) {
            count++;
            show_task(pln, i);
            cout << endl;
        }
    }
    if (count == 0) cout << "Задач с таким описанием не найдено." << endl;
}

void date_search(task* pln, int size) {
    date search_date;
    cin.get(); //костыль, не удалять, иначе фигня
    cout << "Введите дату выполнения задачи, которую хотите найти, в формате \"дд мм гггг\": ";
    cin >> search_date.day >> search_date.month >> search_date.year;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (pln[i].completion.day == search_date.day && pln[i].completion.month == search_date.month && pln[i].completion.year == search_date.year) {
            count++;
            show_task(pln, i);
            cout << endl;
        }
    }
    if (count == 0) cout << "Задач с таким описанием не найдено." << endl;
}

void task_search(task* pln, int size) {
    unsigned short k = 0;
    do {
        system("cls");
        cout << "Выберите, как вы хотите осуществить поиск:\n1) По названию\n2) По приоритету\n3) По описанию\n4) По дате выполнения\n0) Отменить поиск\nВведите ваш выбор: ";
        cin >> k;
        if (k == 0) return;
        else if (k > 4) {
            cout << "Неверный номер. Повторите ввод." << endl;
            system("pause");
        }
    } while (k > 4);
    system("cls");
    switch (k)
    {
    case 1:
        name_search(pln, size);
        break;
    case 2:
        priority_search(pln, size);
        break;
    case 3:
        description_search(pln, size);
        break;
    case 4:
        date_search(pln, size);
        break;
    }
}