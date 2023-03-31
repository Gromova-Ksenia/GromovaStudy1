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

task* read_tasks(task* pln, int& size) { //���������� ����� �� �����
    int i = 0; string tmp;
    ifstream in("tasks.txt");
    if (!in.is_open()) { //���� ����� �� ������������, �������� ����� ���� � 0 �����
        ofstream out;
        out.open("tasks.txt");
        out << '0' << endl;
        out.close();
        return pln;
    }
    else { //���� ���� ����������, ���������
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

void write_tasks(task* pln, int size) { //������ ����� � ����
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

task* add_task(task* pln, int& size) { //���������� ������
    task* temp = new task[size + 1];
    for (int i = 0; i < size; i++) temp[i] = pln[i];
    cin.get(); //�������, �� �������, ����� �����
    cout << "������� �������� ������: ";
    getline(cin, temp[size].name);
    cout << "������� ���������: ";
    getline(cin, temp[size].priority);
    cout << "������� ��������: ";
    getline(cin, temp[size].description);
    cout << "������� ���� ���������� � ������� \"�� �� ����\": ";
    cin >> temp[size].completion.day >> temp[size].completion.month >> temp[size].completion.year;
    cout << "������� ����� ���������� � ������� \"�� ��\": ";
    cin >> temp[size].completion.hour >> temp[size].completion.minute;
    delete[] pln;
    size++;
    return temp;
}

task* delete_task(task* pln, int& size) { //�������� ������
    if (size == 0) {
        cout << "������ ����� ��� ����." << endl;
        return pln;
    }
    else {
        unsigned int num = 0;
        do {
            system("cls");
            cout << "�������� ����� ������, ������� ������ �������:" << endl;
            for (int i = 0; i < size; i++) cout << i + 1 << ". " << pln[i].name << endl;
            cout << "������� 0, ����� �������� �������� ������." << endl << "�����: ";
            cin >> num;
            if (num == 0) return pln;
            else if (num > size) {
                cout << "�������� �����. ��������� ����." << endl;
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


void show_task(task* pln, int number) { //����� ����� ������
    cout << "��������: " << pln[number].name << endl;
    cout << "���������: " << pln[number].priority << endl;
    cout << "��������: " << pln[number].description << endl;
    cout << "�����: " << pln[number].completion.hour << ':';
    (pln[number].completion.minute == 0) ? cout << "00" : cout << pln[number].completion.minute;
    cout << ' ' << pln[number].completion.day << '.' << pln[number].completion.month << '.' << pln[number].completion.year << endl;
}

void show_all(task* pln, int size) { // ����� ���� �����
    if (size == 0) {
        cout << "������ ����� ���� ����." << endl;
    }
    else {
        for (int i = 0; i < size; i++) {
            cout << "������ ����� " << i + 1 << ":\n";
            show_task(pln, i);
            cout << endl;
        }
    }
}

void change_task(task* pln, int size) { //�������������� ������
    unsigned int num = 0;
    do {
        system("cls");
        cout << "�������� ����� ������, ������� ������ ��������:" << endl;
        for (int i = 0; i < size; i++) cout << i + 1 << ". " << pln[i].name << endl;
        cout << "������� 0, ����� �������� �������������� ������." << endl << "�����: ";
        cin >> num;
        if (num == 0) return;
        else if (num > size) {
            cout << "�������� �����. ��������� ����." << endl;
            system("pause");
        }
    } while (num > size);
    unsigned short k = 0;
    do {
        system("cls");
        cout << "��������� ������ �������� ���:" << endl;
        show_task(pln, num - 1);
        cout << endl << "��������, ��� �� ������ �������������:\n1) ��������\n2) ���������\n3) ��������\n4) ���� � ����� ����������\n0) �������� ��������������\n������� ��� �����: ";
        cin >> k;
        if (k == 0) return;
        else if (k > 4) {
            cout << "�������� �����. ��������� ����." << endl;
            system("pause");
        }
    } while (k > 4);
    switch (k)
    {
    case 1:
        cin.get(); //�������, �� �������, ����� �����
        cout << "������� ����� �������� ������: ";
        getline(cin, pln[num - 1].name);
        break;
    case 2:
        cin.get();
        cout << "������� ����� ���������: ";
        getline(cin, pln[num - 1].priority);
        break;
    case 3:
        cin.get();
        cout << "������� ����� ��������: ";
        getline(cin, pln[num - 1].description);
        break;
    case 4:
        cout << "������� ����� ���� ���������� � ������� \"�� �� ����\": ";
        cin >> pln[num - 1].completion.day >> pln[num - 1].completion.month >> pln[num - 1].completion.year;
        cout << "������� ����� ����� ���������� � ������� \"�� ��\": ";
        cin >> pln[num - 1].completion.hour >> pln[num - 1].completion.minute;
        break;
    }
}

void name_search(task* pln, int size) {
    string search;
    cin.get(); //�������, �� �������, ����� �����
    cout << "������� �������� ������, ������� ������ �����: ";
    getline(cin, search);
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (!pln[i].name.find(search)) {
            count++;
            show_task(pln, i);
            cout << endl;
        }
    }
    if (count == 0) cout << "������ � ����� ��������� �� �������." << endl;
}

void priority_search(task* pln, int size) {
    string search;
    cin.get(); //�������, �� �������, ����� �����
    cout << "������� ��������� ����� ��� ������: ";
    getline(cin, search);
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (!pln[i].priority.find(search)) {
            count++;
            show_task(pln, i);
            cout << endl;
        }
    }
    if (count == 0) cout << "����� � ����� ����������� �� �������." << endl;
}

void description_search(task* pln, int size) {
    string search;
    cin.get(); //�������, �� �������, ����� �����
    cout << "������� �������� ������, ������� ������ �����: ";
    getline(cin, search);
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (!pln[i].description.find(search)) {
            count++;
            show_task(pln, i);
            cout << endl;
        }
    }
    if (count == 0) cout << "����� � ����� ��������� �� �������." << endl;
}

void date_search(task* pln, int size) {
    date search_date;
    cin.get(); //�������, �� �������, ����� �����
    cout << "������� ���� ���������� ������, ������� ������ �����, � ������� \"�� �� ����\": ";
    cin >> search_date.day >> search_date.month >> search_date.year;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (pln[i].completion.day == search_date.day && pln[i].completion.month == search_date.month && pln[i].completion.year == search_date.year) {
            count++;
            show_task(pln, i);
            cout << endl;
        }
    }
    if (count == 0) cout << "����� � ����� ��������� �� �������." << endl;
}

void task_search(task* pln, int size) {
    unsigned short k = 0;
    do {
        system("cls");
        cout << "��������, ��� �� ������ ����������� �����:\n1) �� ��������\n2) �� ����������\n3) �� ��������\n4) �� ���� ����������\n0) �������� �����\n������� ��� �����: ";
        cin >> k;
        if (k == 0) return;
        else if (k > 4) {
            cout << "�������� �����. ��������� ����." << endl;
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