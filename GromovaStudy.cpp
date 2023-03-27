// GromovaStudy.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <Windows.h>
using namespace std;
struct movie {
    string name;
    string director;
    string genre;
    float rate;
    int price;
};


movie* read_libruary(movie* ms, int& size) {
    int i = 0; string tmp;
    ifstream in("lib.txt");
    getline(in, tmp);
    size = stoi(tmp);
    movie* temp = new movie[size];
    while (!in.eof()) {
        getline(in, temp[i].name);
        getline(in, temp[i].director);
        getline(in, temp[i].genre);
        getline(in, tmp);
        temp[i].rate = stof(tmp);
        getline(in, tmp);
        temp[i].price = stoi(tmp);
        i++;
    }
    delete[] ms;
    return temp;
}

void write_libruary(movie* ms, int size) {
    ofstream out;
    out.open("lib.txt");
    out << size;
    for (int i = 0; i < size; i++) {
        out << ms[0].name << endl;
        out << ms[0].director << endl;
        out << ms[0].genre << endl;
        out << ms[0].rate << endl;
        out << ms[0].price << endl;
    }
    out.close();
}

movie* add_movie(movie* ms, int& size) {
    movie* temp = new movie[size + 1];
    for (int i = 0; i < size; i++) temp[i] = ms[i];
    cout << "Введите название фильма: ";
    getline(cin, temp[size].name);
    cout << "Введите режиссёра: ";
    getline(cin, temp[size].director);
    cout << "Введите жанр: ";
    getline(cin, temp[size].genre);
    cout << "Введите рейтинг: ";
    float temp_rate;
    cin >> temp_rate;
    temp[size].rate = temp_rate;
    cout << "Введите цену: ";
    int temp_price;
    cin >> temp_price;
    temp[size].price = temp_price;
    delete[] ms;
    size++;
    return temp;
}

void show_movie(movie* ms, int number) {
    cout << "Название: " << ms[number].name << endl;
    cout << "Режиссёр: " << ms[number].director << endl;
    cout << "Жанр: " << ms[number].genre << endl;
    cout << "Рейтинг: " << ms[number].rate << endl;
    cout << "Стоимость: " << ms[number].price << endl;
}

void show_all(movie* ms, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Фильм номер " << i + 1 << ":\n";
        show_movie(ms, i);
        cout << endl;
    }
}

void name_search(movie* ms, int size) {
    char search[50];
    cout << "Введите название фильма, который хотите найти: ";
    cin.getline(search, 50);
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (ms[i].name.find(search)) {
            count++;
            show_movie(ms, i);
            cout << endl;
        }
    }
    if (count == 0) cout << "Фильма с таким названием не найдено." << endl;
}

void director_search(movie* ms, int size) {
    char search[20];
    cout << "Введите режиссёра фильма, который хотите найти: ";
    cin >> search;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (ms[i].director.find(search)) {
            count++;
            show_movie(ms, i);
            cout << endl;
        }
    }
    if (count == 0) cout << "Фильмов этого режиссёра не найдено." << endl;
}

void genre_search(movie* ms, int size) {
    char search[20];
    cout << "Введите жанр фильма, который хотите найти: ";
    cin >> search;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (ms[i].genre.find(search)) {
            count++;
            show_movie(ms, i);
            cout << endl;
        }
    }
    if (count == 0) cout << "Фильмов с таким жанром не найдено." << endl;
}

void best_in_genre(movie* ms, int size) {
    char search[20];
    cout << "Введите жанр фильма, по которому будет поиск: ";
    cin >> search;
    float rate = 0;
    float number = 0;
    for (int i = 0; i < size; i++) {
        if (ms[i].genre.find(search)) {
            if ((ms[i].rate) > rate) {
                rate = ms[i].rate;
                cout << "rate=" << rate;
                number = i + 1;
        }
        }
    }
    if (number == 0) {
        cout << "Фильмов с таким жанром не найдено." << endl;
    }
    else {
        cout << "Самый популярный фильм в жанре \"" << search << "\":" << endl;
        show_movie(ms, number - 1);
        cout << endl;
    }
}


void main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size = 1;
    movie* movieshop = new movie[size];

    movieshop = read_libruary(movieshop, size);
    uint8_t k = 0;
    do {
        system("cls");
        cout << "Выберите, что вы хотите сделать:\n1) Просмотреть всю библиотеку фильмов.\n2) Добавить новый фильм в библиотеку.\n3) Найти фильм по названию.\n4) Найти фильм по режиссёру.\n5) Найти фильм по жанру.\n6) Найти самый популярный фильм в жанре.\n7) Завершить работу.\nВаш выбор: ";
        cin >> k;
        switch (k)
        {
        case '1':
            system("cls");
            show_all(movieshop, size);
            system("pause");
            break;
        case '2':
            movieshop = add_movie(movieshop, size);
            system("pause");
            break;
        case '3':
            name_search(movieshop, size);
            system("pause");
            break;
        case '4':
            director_search(movieshop, size);
            system("pause");
            break;
        case '5':
            genre_search(movieshop, size);
            system("pause");
            break;
        case '6':
            best_in_genre(movieshop, size);
            system("pause");
            break;
        case '7':
            return;
            break;
        default:
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
