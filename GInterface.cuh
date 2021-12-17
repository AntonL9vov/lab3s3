#pragma once
#ifndef G_INTERFACE_H
#define G_INTERFACE_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#include "graph.h"
#include "tests.h"

using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::string;
using std::cin;


Graph *printmenu12() {
    while (true) {
        fout.open(PATH_FILE);

        cout << "		(1.1)Задать граф." << endl;
        cout << "	||Напишите количество вершин графа: ";
        int length = readInt(1, INT_MAX);
        fout << length << ' ';

        cout << "	||Граф ориентированный? " << endl;
        cout << "	||1 - Нет;" << endl;
        cout << "	||2 - Да." << endl;
        cout << "	||Введите число: ";
        int choice = readInt(1, 2);
        fout << choice - 1 << ' ';

        cout << "	||Граф взвешенный? " << endl;
        cout << "	||1 - нет;" << endl;
        cout << "	||2 - да." << endl;
        cout << "	||Введите ваш ответ: ";
        int weight = readInt(1, 2);
        fout << weight - 1 << endl;

        cout << "	Пожалуйста, введите рёбра графа согласно правилам." << endl;
        cout << "	> вершины нумеруются с 1;" << endl;
        cout << "	> если граф НЕ ориентированный, то повторять рёбра НЕ НУЖНО." << endl << endl;

        while (true) {
            cout << "	||Введите начальную вершину: ";
            choice = readInt(1, length);
            fout << choice - 1 << ' ';

            cout << "	||Введите конечную вершину: ";
            choice = readInt(1, length);
            fout << choice - 1;

            if (weight == 2) {
                cout << "	||Введите вес ребра: ";
                int choice = readInt(1, INT_MAX);
                fout << ' ' << choice;
            }
            fout << endl;
            cout << "	Для завершения ввода ребёр введите -1: ";
            int a;
            cin>>a;
            cout << "	__________" << endl << endl;
            if (a==-1)
                break;
        }
        fout.close();
        return makeGraph(PATH_FILE);
    }
}

Graph *printmenu11() {
    while (true) {
        cout << "		(1.1)Задать граф автоматически." << endl;
        cout << "	||1 - НЕ оринетированный, НЕ взвешенный;" << endl;
        cout << "	||2 - НЕ оринетированный, взвешенный;" << endl;
        cout << "	||3 - оринетированный, НЕ взвешенный;" << endl;
        cout << "	||4 - оринетированный, взвешенный;" << endl;
        cout << "	||" << endl;
        cout << "	||5 - выйти в меню (1)Создать граф." << endl;
        cout << "	||Введите номер выбранного вами действия: ";
        int choice = readInt(1, 5);
        switch (choice) {
            case 1:
                return makeGraph(PATH_FILE1);
                break;
            case 2:
                return makeGraph(PATH_FILE2);
                break;
            case 3:
                return makeGraph(PATH_FILE3);
                break;
            case 4:
                return makeGraph(PATH_FILE4);
                break;
            case 5:
                return nullptr;
                break;
        }
    }
}

Graph *printmenu1() {
    while (true) {
        cout << "		(1)Создать граф." << endl;
        cout << "	|1 - задать автоматически;" << endl;
        cout << "	|2 - задать самостоятельно;" << endl;
        cout << "	|" << endl;
        cout << "	|3 - выйти в Главное меню." << endl;
        cout << "	|Введите номер выбранного вами действия: ";
        int choice = readInt(1, 3);
        switch (choice) {
            case 1:
                return printmenu11();
                break;
            case 2:
                return printmenu12();
                break;
            case 3:
                return nullptr;
                break;
        }
    }
}

void printmenu32(Graph *graph) {
    while (true) {
        cout << "		(3.2)Поиск наикратчайших путей." << endl;
        cout << "	||1 - без учёта веса;" << endl;
        cout << "	||2 - с учётом веса (для НЕ взвешенных вес каждого ребра равен 1);" << endl;
        cout << "	||3 - оба варианта;" << endl;
        cout << "	||" << endl;
        cout << "	||4 - выйти в меню (3)Операци над графом." << endl;
        cout << "	||Введите номер выбранного вами действия: ";
        int choice = readInt(1, 4);
        switch (choice) {
            case 1:
                t_graph_shortestPathBFS(graph);
                break;
            case 2:
                t_grapPathAndLengthWithWeight(graph);
                break;
            case 3:
                t_graph_paths(graph);
                break;
            case 4:
                return;
                break;
        }
    }
}

void printmenu3(Graph *graph) {
    while (true) {
        cout << "		(3)Операции над графом." << endl;
        cout << "	|1 - раскрасить граф;" << endl;
        cout << "	|2 - найти наикратчайшие пути;" << endl;
        cout << "	|" << endl;
        cout << "	|3 - выйти в Главное меню." << endl;
        cout << "	|Введите номер выбранного вами действия: ";
        int choice = readInt(1, 3);
        switch (choice) {
            case 1:
                //return printmenu31(Graph * graph);
                t_graph_painting(graph);
                break;
            case 2:
                printmenu32(graph);
                break;
            case 3:
                return;
        }
    }
}

void printmenu0() {
    Graph *graph = nullptr;
    while (true) {
        cout << "	Главное меню." << endl;
        cout << "1 - создать граф;" << endl;
        cout << "2 - показать информацию о созданном графе;" << endl;
        cout << "3 - операции над графом;" << endl;
        cout << endl;
        cout << "4 - выход." << endl;
        cout << "5 - TESTS" << endl;
        cout << "Введите номер выбранного вами действия: ";
        int choice = readInt(1, 5);
        switch (choice) {
            case 1:
                graph = printmenu1();
                cout << endl;
                break;
            case 2:
                if (graph == nullptr) {
                    cout << "Граф не был создан." << endl;
                    break;
                } else {
                    print(graph);
                    break;
                }
            case 3:
                if (graph == nullptr) {
                    cout << "Граф не был создан." << endl;
                    break;
                } else {
                    printmenu3(graph);
                    break;
                }
            case 4:
                return;
                break;
            case 5:
                tests();
                break;
        }
    }
}

void program() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printmenu0();
    return;
}


#endif // !G_INTERFACE_H