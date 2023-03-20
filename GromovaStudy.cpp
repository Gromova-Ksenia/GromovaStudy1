// GromovaStudy.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include "my_lib.h"
using namespace std;
struct movie {
    char name[50];
    char director[20];
    char genre[20];
    float rate;
    int price;
};

 /*void real_libruary(FILE* lib) {
    int size = 5;
    movie* temp = new movie[size];
    int i = 0;
    while (!feof(lib)) {
        fscanf_s(lib, "%s", &temp[i].name, sizeof(temp[i].name));
        fscanf_s(lib, "%s", &temp[i].director, sizeof(temp[i].director));
        fscanf_s(lib, "%s", &temp[i].genre, sizeof(temp[i].genre));
        fscanf_s(lib, "%f", &temp[i].rate, sizeof(temp[i].rate));
        fscanf_s(lib, "%u", &temp[i].price, sizeof(temp[i].price));
        i++;
    }
}*/

void fill_movies(movie* ms) {
    ms[0] = { "Начало", "Нолан", "Триллер", 9.8, 800 };
    ms[1] = { "Довод", "Нолан", "Триллер", 9.5, 700 };
    ms[2] = { "Первому игроку приготовиться", "Спилберг", "Боевик", 7.5, 650 };
    ms[3] = { "Призрак Оперы", "Шумахер", "Мюзикл", 7.8, 500 };
    ms[4] = { "Боги хеви-метал", "Соллетт", "Комедия", 7.1, 500 };
}

movie* add_movie(movie* ms, int& size) {
    movie* temp = new movie[size + 1];
    for (int i = 0; i < size; i++) temp[i] = ms[i];
    cout << "Введите название фильма: ";
    cin.getline(temp[size].name, 50);
    cout << "Введите режиссёра: ";
    cin >> temp[size].director;
    cout << "Введите жанр: ";
    cin >> temp[size].genre;
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
        if (strstr(ms[i].name, search)) {
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
        if (strstr(ms[i].director, search)) {
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
        if (strstr(ms[i].genre, search)) {
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
        if (strstr(ms[i].genre, search)) {
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
    int size = 5;
    movie* movieshop = new movie[size];
    //FILE* libruary;

    //libruary = fopen("P:/Студенты/РПО211/Gromova/lib.txt", "w+");
    fill_movies(movieshop);
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
