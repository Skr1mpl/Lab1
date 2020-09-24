#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

void setColor(int, int);
int chooseFillArr();


int main()
{
	setlocale(0, "rus");
	cout << "Введите размер матрицы n = ";
	int n = 0;
	cin >> n;
    int** mas = new int* [n];
    for (int i = 0; i < n; i++)
        mas[i] = new int[n];
    system("cls");
    int choose = chooseFillArr();
    if (choose == 0) {
        system("cls");
        cout << "Введите левый диапозон рандома: ";
        int l = 0, r = 0;
        cin >> l;
        cout << "Введите правый диапозон рандома: ";
        cin >> r;
        srand(time(NULL));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mas[i][j] = rand() % (r - l + 1) + l;
    }
    else {
        cout << "Введите элементы массива: " << endl;
        for (int i = 0; i < n; i++) {
            cout << i + 1 << " - строка из " << n << " символов: ";
            for (int j = 0; j < n; j++)
                cin >> mas[i][j];
        }
    }
    cout << "Первоначальный массив: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mas[i][j] << " ";
        cout << endl;
    }
    system("pause");
    int k = 0;
    for (int i = 0; i < n; i++)
        for(int j = 0; j < n - 1; j++)
            if (mas[j][j] > mas[j + 1][j + 1]) {
                k = mas[j][j];
                mas[j][j] = mas[j + 1][j + 1];
                mas[j + 1][j + 1] = k;
            }
    system("cls");
    cout << "Массив с отсортированной по возрастанию главной диогонали: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mas[i][j] << " ";
        cout << endl;
    }
}

int chooseFillArr() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите как заполнить матрицу: " << endl;
        choose_menu = (choose_menu + 2) % 2;

        if (choose_menu == 0) { setColor(2, 0); cout << " -> Через рандом" << endl; setColor(15, 0); }
        else { cout << " Через рандом" << endl; }

        if (choose_menu == 1) { setColor(2, 0); cout << " -> С клавиатуры" << endl; setColor(15, 0); }
        else { cout << " С клавиатуры" << endl; }

        keyboard_button = _getch();
        if (keyboard_button == 224) {
            keyboard_button = _getch();
            if (keyboard_button == 72) choose_menu--;
            if (keyboard_button == 80) choose_menu++;
        }
        if (keyboard_button == 13) { system("cls"); return choose_menu; }
        system("cls");
    }
}

void setColor(int text, int background) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
