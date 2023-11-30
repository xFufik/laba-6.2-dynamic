﻿#include <iostream>
#include <locale>

using namespace std;

/*
*Лабораторная работа 6. Задание 2. Индивидуальный вариант 24. Статический массив.
*Обнулить элементы матрицы, лежащие одновременно ниже главной диагонали (включая эту диагональ) и выше побочной диагонали (также включая эту диагональ). Условный оператор не использовать.
*return 0 - все ок. return 1 - ошибка.
*/

int main() {
    setlocale(LC_ALL, "ru");

    int M;

    cout << "Введите порядок М квадратной матрицы: ";
    cin >> M;

    if (M <= 0) {
        cerr << "Порядок матрицы должен быть натуральным числом";
        return 1;
    }

    int** matrix = new int* [M];
    for (int i = 0; i < M; i++) {
        matrix[i] = new int[M];
    }

    cout << "Введите элементы матрицы: " << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }
    matrix[0][0] = 0; //Зануляем первый элемент главной диагонали
    for (int i = 1; i < M; i++) { //Зануляем элементы главной диагонали и элемент слева от главной диагонали начиная СО ВТОРОЙ СТРОКИ
        matrix[i][i] = 0;
        matrix[i][i - 1] = 0;
    }

    matrix[M - 1][0] = 0; //Зануляем последний элемент побочной диагонали
    for (int i = 0; i < M - 1; i++) { //Зануляем элементы побочной диагонали и элемент слева от нее на всех строках КРОМЕ ПОСЛЕДНЕЙ
        int j = M - 1 - i;
        matrix[i][j] = 0;
        matrix[i][j - 1] = 0;
    }

    //Таким образом мы получаем геометрически верную последовательность удаления элементов

    cout << "Результат:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < M; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}