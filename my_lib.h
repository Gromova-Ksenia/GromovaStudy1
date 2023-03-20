#pragma once
#include <iostream>
using namespace std;
int const l_size = 10, c_size = 7, d_size = 5;

void num_print(int a, int size = 3) {
    int count = 0, b;
    (a == 0) ? b = 1 : b = a;
    if (b < 0) {
        count++;
        b *= -1;
    }
    while (b > 0) {
        b /= 10;
        count++;
    }
    if (count == size) {
        cout << a << ' ';
    }
    else {
        for (int i = 0; i < (size - count); i++) {
            cout << ' ';
        }
        cout << a << ' ';
    }
}

template <typename T>
void fill(T a[][c_size][d_size], int l_size, int c_size, int d_size) {
    for (int i = 0; i < l_size; i++) {
        for (int j = 0; j < c_size; j++) {
            for (int t = 0; t < d_size; t++) {
                a[i][j][t] = rand() % 51;
                //num_print(a[i][j], 2);
            }
            
        }
        //cout << endl;
    }
}

template <typename T>
void fill(T a[][c_size], int l_size, int c_size) {
    for (int i = 0; i < l_size; i++) {
        for (int j = 0; j < c_size; j++) {
            a[i][j] = rand() % 51;
            //num_print(a[i][j], 2);
        }
       // cout << endl;
    }
}

template <typename T>
void fill(T a[], int size) {
    for (int i = 0; i < size; i++) {
            a[i] = rand() % 51;
            num_print(a[i], 2);
    }
}

void arr_transp(int a[c_size][c_size]) {
    int temp;
    for (int i = 0; i < c_size - 1; i++) {
        for (int j = i+1; j < c_size; j++) {
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
}

template <typename T>
void quick_sort(T a[], long N) {
        long i = 0, j = N;
    T temp, p;
    p = a[N / 2];
    do {
        while (a[i] < p) i++;
        while (a[j] > p) j--;
        if (i <= j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) quick_sort(a, j);
    if (N > i) quick_sort(a + i, N - i);
}

template <typename T>
void arr_print(T a[], int size) {
    for (int i = 0; i < size; i++) {
        num_print(a[i], 2);
    }
    cout << endl;
}

void arr_print(int* a, int size) {
    for (int i = 0; i < size; i++) {
        num_print(*(a + i), 3);
    }
    cout << endl;
}

template <typename T>
void arr_print(T a[][10], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 10; j++) {
            num_print(a[i][j], 2);
        }
        cout << endl;
    }
}

template <typename T>
void arr_print(T** arr, int arr_size, int line_size) {
    for (int i = 0; i < arr_size; i++) {
        arr_print(arr[i], line_size);
    }
}

template <typename T>
void sort_arrays_merge(T* a, int size_a, T* b, int size_b, T* c) {
    int tempa = 0, tempb = 0;
    for (int i = 0; i < size_a + size_b;) {
        if (tempa < size_a && tempb < size_b) {
            if (*(a + tempa) == *(b + tempb)) {
                *(c + i) = *(a + tempa);
                *(c + i + 1) = *(b + tempb);
                i += 2;
                tempa++;
                tempb++;
            }
            else if (*(a + tempa) < *(b + tempb)) {
                *(c + i) = *(a + tempa);
                i++;
                tempa++;
            }
            else {
                *(c + i) = *(b + tempb);
                i++;
                tempb++;
            }
        }
        else if (tempa == size_a) {
            *(c + i) = *(b + tempb);
            tempb++;
            i++;
        }
        else {
            *(c + i) = *(a + tempa);
            tempa++;
            i++;
        }
    }
}

int& init_array(int size) {
    int* ptr = new int[size];
    for (int i = 0; i < size; i++) {
        ptr[i] = rand() % 50;
        num_print(ptr[i], 3);
    }
    cout << endl;
    return ptr[0];
}

template <typename T>
void init_array(T** arr, int arr_size, int line_size) {
    for (int i = 0; i < arr_size; i++) {
        arr[i] = &init_array(line_size);
    }
}

void column_print(int* a, int size) {
    for (int i = 0; i < size; i++) {
        num_print(*(a + i), 3);
        cout << endl;
    }
}

