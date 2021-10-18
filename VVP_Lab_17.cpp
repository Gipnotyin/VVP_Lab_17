#include <iostream>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    vector <int> SrAr;
    vector <int> NeoCh;
    vector <int> MinI;
    vector <int> LocMx;
    vector <int> OdiSh;
    bool end = true;
    int number, n, k, l, d, sum, flug, min, max, c;
    while (end == true) {
        cout << "Выберите задание для проверки.\n" <<
            "Для выхода из программы ввидите любую цифру, не входящих в диапозон от 1 до 5:\n";
        cin >> number;
        if (number >= 1 and number <= 5) {
            switch (number)
            {
            case 1:
                system("cls");
                cout << "Вы просматриваете " << number << " задание\n" <<
                    "1. Дан массив размера N и целые числа K и L (1 <= K <= L < N).\nНайти среднее арифметическое элементов массива с номерами от K до L включительно.\n\n";
                cout << "Введите размер массива N: ";
                cin >> n;
                SrAr.reserve(n);
                cout << "Введите целое число K: ";
                cin >> k;
                cout << "Введите целое число L: ";
                cin >> l;
                if (1 <= k and k <= l and l < n) {
                    cout << "Введите значения в массив: ";
                    for (int i = 0; i < n; i++) {
                        cin >> d;
                        SrAr.push_back(d);
                    }
                    sum = 0;
                    for (int i = k; i <= l; i++) {
                        sum += SrAr[i];
                    }
                    sum /= (l - k) + 1;
                    cout << "Среднее арифметическое числе в массиве от K до L равно: " << sum << endl;
                    SrAr.clear();
                    SrAr.shrink_to_fit();
                }
                else {
                    system("cls");
                    cout << "Ошибка ввода, не выполняется условие 1 <= K <= L < N!!!\n";
                }
                break;
            case 2:
                system("cls");
                cout << "Вы просматриваете " << number << " задание.\n"<<
                    "2. Дан целочисленный массив размера N, не содержащий одинаковых чисел.\nПроверить, образуют ли его элементы арифметическую прогрессию.\nЕсли образуют, то вывести разность прогрессии, если нет — вывести 0.\n\n";
                cout << "Введите размер массива (N): ";
                flug = 1;
                cin >> n;
                if (n == 1) {
                    cout << "Любой имассив из одного элемента не может составить арифметическую прогрессию, вывожу 0\n";
                }
                else if (n > 1) {
                    cout << "Заполните массив: ";
                    for (int i = 0; i < n; i++) {
                        cin >> d;
                        NeoCh.push_back(d);
                    }
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < i - 1; j++) {
                            if (NeoCh[i] == NeoCh[j]) {
                                cout << "Ошибка заполнения массива!!!\n";
                                flug = 0;
                            }
                        }
                        if (flug == 0)
                            break;
                    }
                    if (flug != 0) {
                        sum = NeoCh[1] - NeoCh[0];
                        for (int i = 1; i < n; i++) {
                            if (NeoCh[i] - NeoCh[i - 1] != sum) {
                                flug = 0;
                                if (flug == 0) {
                                    break;
                                }
                            }
                        }
                        if (flug == 1) {
                            cout << "Арифметическая разность равна: " << sum << endl;
                        }
                        else {
                            cout << "0\n";
                        }
                    }
                }
                else {
                    cout << "Ошибка ввода размерности массива!\n";
                }
                NeoCh.clear();
                NeoCh.shrink_to_fit();
                break;
            case 3:
                system("cls");
                cout << "Вы просматриваете " << number << " задание\n" <<
                    "3. Дан массив A размера N.\nНайти минимальный элемент из его элементов с четными номерами: A2, A4, A6, и тд...\n\n";
                cout << "Введите размер массива (N): ";
                cin >> n;
                if (n > 0) {
                    MinI.reserve(n);
                    for (int i = 0; i < n; i++) {
                        cin >> d;
                        MinI.push_back(d);
                    }
                    min = MinI[0];
                    for (int i = 0; i < n; i++) {
                        if ((i % 2 == 0) and (i > 0)) {
                            if (min > MinI[i]) {
                                min = MinI[i];
                            }
                        }
                    }
                    cout << "Минимальное число на чётном месте равно: " << min << endl;
                }
                else {
                    system("cls");
                    cout << "Размер массива должен быть > 0";
                }
                MinI.clear();
                MinI.shrink_to_fit();
                break;
            case 4:
                system("cls");
                cout << "Вы просматриваете " << number << " задание\n" << 
                    "4. Дан массив размера N.\nНайти номер его последнего локального максимума (локальный максимум — это элемент, который больше любого из своих соседей).\n\n";
                cout << "Введите размер массива (N): ";
                cin >> n;
                if (n > 2) {
                    LocMx.reserve(n);
                    for (int i = 0; i < n; i++) {
                        cin >> d;
                        LocMx.push_back(d);
                    }
                    max = 0;
                    for (int i = 1; i < n - 1; i++) {
                        if (LocMx[i] > LocMx[i - 1] and LocMx[i] > LocMx[i + 1]) {
                            max = i;
                        }
                        else if (LocMx[n - 1] > LocMx[n - 2]) {
                            max = n - 1;
                        } 
                    }
                    if (max == 0 and LocMx[0]<=LocMx[1]) {
                        cout << "Скалярного максимума нет!\n";
                    }
                    else {
                        cout << "Номер локального максимума: " << max << endl;
                    }
                }
                else if (n >= 1 and n <= 2) {
                    LocMx.reserve(n);
                    for (int i = 0; i < n; i++) {
                        cin >> d;
                        LocMx.push_back(d);
                    }
                    if (LocMx[0]>LocMx[1]) {
                        max = 0;
                        cout << "Номер скалярного максимума равен: " << max << endl;
                    }
                    else if (LocMx[0] < LocMx[1]) {
                        max = 1;
                        cout << "Номер скалярного максимума равен: " << max << endl;
                    }
                    else {
                        cout << "Локального максимума нет!\n";
                    }
                }
                else {
                    system("cls");
                    cout << "Ошбка ввода!!!\n";
                }
                LocMx.clear();
                LocMx.shrink_to_fit();
                break;
            case 5:
                system("cls");
                cout << "Вы просматриваете " << number << " задание\n" <<
                    "5. Дан целочисленный массив размера N, содержащий ровно два одинаковых элемента.\nНайти номера одинаковых элементов и вывести эти номера в порядке возрастания.\n\n";
                cout << "Введите размер массива (N): ";
                cin >> n;
                if (n > 0) {
                    OdiSh.reserve(n);
                    cout << "Заполните массив так, чтобы было ровно два одинаковых элемента!\n";
                    for (int i = 0; i < n; i++) {
                        cin >> d;
                        OdiSh.push_back(d);
                    }
                    c = 0;
                    for (int i = 0; i < n - 1; i++) {
                        if (OdiSh[i] == OdiSh[i+1]) {
                            c += 1;
                            k = i;
                            l = i + 1;
                        }
                        if (c > 1) {
                            break;
                        }
                    }
                    if (c == 1) {
                        system("cls");
                        cout << "Номера двух одинаковых соседей: " << k << " и " << l << endl;
                    }
                    else {
                        system("cls");
                        cout << "Вы ошиблись с вводом данных!\n";
                    }
                }
                else {
                    system("cls");
                    cout << "Ошибка ввода размера массива!\n";
                }
                OdiSh.clear();
                OdiSh.shrink_to_fit();
                break;
            }
        } else { 
            system("cls");
            cout << "Спасибо за проверку лаб!!!\n";
            end = false;
        }
    }
}
