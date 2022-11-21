// CPUS.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <iterator>
#include <random>
#include <map>

using namespace std;
int N = 0;
std::vector<pair<int, int>> CPU1(N);
std::vector<pair<int, int>> CPU2(N);

int gen() {

    int a = rand() % 10 + 1;
    return a;
}

bool cmp(pair<int, int>& a,
    pair<int, int>& b) //функция сравнения пар
{
    return a.second > b.second;
}

//Функция сортировки map по значению
vector<pair<int,int>> sort(map<int, int>& M)
{

    // Создание вектора типа pair
    vector<pair<int, int> > A;

    // Копирование id - значение
    // в вектор значений pair
    for (auto& it : M) {
        A.push_back(it);
    }

    // Сортировка использованием функции сравнения
    sort(A.begin(), A.end(), cmp);

    // Вывод отсортированных зн.
    for (auto& it : A) {

        cout << it.first << ' '
            << it.second << endl;
    }
    return A;
}

int sort_by_cpus(vector<pair<int, int>> A) {
    int CPU1sum = 0;
    int CPU2sum = 0;
    auto c1 = CPU1.begin();
    auto c2 = CPU2.begin();
    
    for (int it = 0; it != A.size(); ++it)///вывод на экран
    {
        if (CPU1.size() == 0) {
            CPU1.push_back(A[it]);
            CPU1sum += A[it].second;

        }
        else if (CPU1sum>CPU2sum) {
            CPU2.push_back(A[it]);
            CPU2sum += A[it].second;

        }
        else if (CPU1sum == CPU2sum) {
            CPU1.push_back(A[it]);
            CPU1sum += A[it].second;
        }
        else if (CPU1sum < CPU2sum) {
            CPU1.push_back(A[it]);
            CPU1sum += A[it].second;
        }

    }

    cout << endl << CPU1sum <<endl;
    cout << CPU2sum << endl;
    return 0;
}



int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите количество процессов: ";
    cin >> N;

    map <int, int> MapProcs; // создаем map для хранения пар ключ - значение (id - длительность)
    srand(unsigned(std::time(nullptr)));
    for (auto i = 0; i < N; ++i) {
        MapProcs.insert({ i , gen() });
    };



    for (auto it = MapProcs.begin(); it != MapProcs.end(); ++it)///вывод на экран
    {
        cout << it->first << " : " << it->second << endl;
    }

    //map невозможно отсортировать по значениям, он сам сортирует себя только по ключу поэтому создаем вектор для хранения типов pair
    vector<pair<int, int>> Procs(N); //Создание вектора pair для хранения данных из map
    Procs = sort(MapProcs);

    cout << endl;
    for (auto it = Procs.begin(); it != Procs.end(); ++it)///вывод на экран
    {
        cout << "|" << it->first << "\t ";
    }
    cout << endl;
    for (auto it = Procs.begin(); it != Procs.end(); ++it)///вывод на экран
    {
        cout << "|" << it->second << "\t ";
    }
    sort_by_cpus(Procs);


}

// Copyright 2022, Eremin Artyom, All rights reserved
// For personal use only