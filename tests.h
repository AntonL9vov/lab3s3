#pragma once
#ifndef TESTS_H
#define TESTS_H
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#include "List.h"
#include "queue.h"
#include "graph.h"
//#include "g_interface.h"
#include "DynamicArray.h"
#include "stack.h"
#include "pair.h"

using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::string;
using std::cin;

const string PATH_FILE = "C:\\Users\\AntonLvov\\CLionProjects\\lab3s3\\file.txt";
const string PATH_FILE1 = "C:\\Users\\AntonLvov\\CLionProjects\\lab3s3\\file.txt";
const string PATH_FILE2 = "C:\\Users\\AntonLvov\\CLionProjects\\lab3s3\\file.txt";
const string PATH_FILE3 = "C:\\Users\\AntonLvov\\CLionProjects\\lab3s3\\file.txt";
const string PATH_FILE4 = "C:\\Users\\AntonLvov\\CLionProjects\\lab3s3\\file.txt";

ifstream fin; //������
ofstream fout; //����

int readInt(int from = INT_MIN, int to = INT_MAX) {
    while (true) {
        try {
            std::string line;
            std::getline(std::cin, line);
            if (line.empty()) throw std::exception();

            int read = std::stoi(line);
            if (read < from || read > to) throw std::exception();

            std::cout << endl;
            return read;
        }
        catch (...) {
            std::cout << "���������� ������� ����� �� " << std::to_string(from) << " �� " << std::to_string(to) << ": ";
        }
    }
}

LinkedList<int>* ll_create_by_length(int length) {
    LinkedList<int>* list = nullptr;
    try {
        list = new LinkedList<int>(length);
        cout << "	�������!" << endl;
        cout  << endl;
        return list;
    }
    catch (const std::exception& e) {
        cout << e.what() << endl <<  endl;
        return nullptr;
    }
}
LinkedList<int>* ll_create_by_array(int* arr, int length) {
    LinkedList<int>* list = nullptr;
    try {
        list = new LinkedList<int>(arr,length);
        cout << "	�������!" << endl;
        cout <<  endl;
        return list;
    }
    catch (const std::exception& e) {
        cout << e.what() << endl << endl;
        return nullptr;
    }
}
void print(LinkedList<int>* list) {
    cout << "	�����: " << list->getLength() << endl;
    cout << "	������:" << endl;
    for (int i = 0; i < list->getLength(); i++) {
        cout << list->get(i) << " ";
    }
    cout << endl << "__________" << endl;
}
void t_llist() {
    cout << "����� LINKED LIST (��� INT)" << endl;

    cout << "	�����������" << endl;
    LinkedList<int>* list = nullptr;
    cout << "	����� = -5." << endl;
    list = ll_create_by_length(-5);
    cout << "	����� = 0." << endl;
    list = ll_create_by_length(0);
    cout << "	����� = 10." << endl;
    list = ll_create_by_length(10);

    int arr[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
    cout << endl;
    cout << "	������: [ 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 ]." << endl;
    cout << "	����� = -1." << endl;
    list = ll_create_by_array(arr,-1);
    //print(list);
    cout << "	����� = 10." << endl;
    list = ll_create_by_array(arr, 10);
    print(list);
    cout << "	����� = 20." << endl;
    list = ll_create_by_array(arr, 20);
    print(list);

    cout << "	���������� �����������." << endl;
    LinkedList<int>* list2 = new LinkedList<int>(*list);
    if (list2 == list) cout << "	�������!" << endl;


}

Queue<int>* queue_create_by_array(int* arr, int length) {
    Queue<int>* queue = nullptr;
    try {
        queue = new Queue<int>(arr, length);
        cout << "	�������!" << endl;
        cout << endl;
        return queue;
    }
    catch (const std::exception& e) {
        cout << e.what() << endl << endl;
        return nullptr;
    }
}
void print(Queue<int>* queue) {
    cout << "	�����: " << queue->getLength() << endl;
    Queue<int>* tmp = new Queue<int>(*queue);
    cout << "	�������:" << endl;
    int length = tmp->getLength();
    for (int i = 0; i < length; i++) {
        cout << tmp->dequeue() << " ";
    }
    cout << endl << "__________" << endl;
}
void t_queue() {
    cout << "����� Queue (��� INT)" << endl;

    cout << "	�����������" << endl;

    Queue<int>* queue = new Queue<int>();
    for (int i = 0; i < 15; i++)
        queue->enqueue(i);
    print(queue);


    int arr[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
    cout << endl;
    cout << "	������: [ 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 ]." << endl;
    cout << "	����� = -1." << endl;
    queue = queue_create_by_array(arr, -1);
    cout << "	����� = 10." << endl;
    queue = queue_create_by_array(arr, 10);
    print(queue);
    cout << "	����� = 20." << endl;
    queue = queue_create_by_array(arr, 20);
    print(queue);

    cout << "	���������� �����������." << endl;
    Queue<int>* queue2 = new Queue<int>(*queue);
    print(queue);
}

Stack<int>* stack_create_by_array(int* arr, int length) {
    Stack<int>* stack = nullptr;
    try {
        stack = new Stack<int>(arr, length);
        cout << "	�������!" << endl;
        cout << endl;
        return stack;
    }
    catch (const std::exception& e) {
        cout << e.what() << endl << endl;
        return nullptr;
    }
}
void print(Stack<int>* stack) {
    cout << "	�����: " << stack->getLength() << endl;
    Stack<int>* tmp = new Stack<int>(*stack);
    cout << "	����:" << endl;
    int length = tmp->getLength();
    for (int i = 0; i < length; i++) {
        cout << tmp->pop() << " ";
    }
    cout << endl << "__________" << endl;
}
void t_stack() {
    cout << "����� Stack (��� INT)" << endl;

    cout << "	�����������" << endl;

    Stack<int>* stack = new Stack<int>();
    for (int i = 0; i < 15; i++)
        stack->push(i);
    print(stack);


    int arr[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
    cout << endl;
    cout << "	������: [ 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 ]." << endl;
    cout << "	����� = -1." << endl;
    stack = stack_create_by_array(arr, -1);
    //print(list);
    cout << "	����� = 10." << endl;
    stack = stack_create_by_array(arr, 10);
    print(stack);
    cout << "	����� = 20." << endl;
    stack = stack_create_by_array(arr, 20);
    print(stack);

}

void print(DynamicArray<int>* da) {
    for (int i = 0; i < da->getLength(); i++)
        cout << da->get(i) << " ";
    //cout << endl;
}

void printInfo(Graph* graph) {
    cout << "���� " << endl;
    if (graph->getDirect())
        cout << "���������������, ";
    else cout << "�� ���������������, ";
    if (graph->getWeigth())
        cout << "����������, �� ";
    else cout << "�� ����������, �� ";
    cout << graph->getLength() << " ��������." << endl;
}
Graph* makeGraph(string path) {


    int i, j;
    int w = 1;

    fin.open(path);
    if (fin.is_open())
    {
        bool weigth, direct;
        fin >> i >> j >> w;
        if (j == 1)
            direct = true;
        else direct = false;

        if (w == 1)
            weigth = true;
        else weigth = false;

        Graph* graph = new Graph(weigth, direct);
        for (j = 0; j < i; j++) {
            graph->addVertex();
        }
        printInfo(graph);
        cout << "и���: ";
        while (true)
        {
            fin >> i >> j;
            if (fin.fail()) break;
            if (weigth)
                fin >> w;
            std::cout << "	(" << i << ", " << j << ")";
            if (weigth)
                std::cout << " = " << w;
            std::cout << std::endl;
            graph->addEdge(i, j, w);
        }
        fin.close();
        return graph;
    }
    else {
        std::cout << "���-�� �� ���"<< std::endl;
        return nullptr;
    }
}
void print(Graph* graph) {
    printInfo(graph);
    if (graph->getWeigth()) {
        for (int i = 0; i < graph->getLength(); i++) {
            cout << "�������: " << i << endl;
            for (int j = 0; j < graph->get(i)->getEdgesCount(); j++) {
                cout << "	(" << i << ", " << graph->get(i)->getEdge(j).getVertex() << ")";
                cout << " = " << graph->get(i)->getEdge(j).getData();
                cout << endl;
            }
        }
    }
    else {
        for (int i = 0; i < graph->getLength(); i++) {
            cout << i << "( ";
            for (int j = 0; j < graph->get(i)->getEdgesCount(); j++) {
                cout << graph->get(i)->getEdge(j).getVertex() << " ";
            }
            cout << ")" << endl;
        }
    }
    cout << endl;
}
void t_graph_isNeighbor(Graph* graph) {
    print(graph);
    for (int i = 0; i < graph->getLength(); i++) {
        cout << "������ ������� " << i << ": ";
        for (int j = 0; j < graph->getLength(); j++) {
            if (i != j)
                if (graph->get(i)->isNeighbor(j))
                    cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void t_graph_BFS(Graph* graph) {
    cout << "����� � ������" << endl;
    for (int i = 0; i < graph->getLength(); i++) {
        cout << "	������� " << i << ": ";
        DynamicArray<int>* res = graph->BFS(i);
        print(res);
        cout << endl;
    }
    cout << endl;
}
void t_graph_shortestPathBFS(Graph* graph) {
    cout << "���������� ����" << endl;
    for (int i = 0; i < graph->getLength(); i++) {
        cout << "�� ������� " << i << " �� " << endl;
        for (int j = 0; j < graph->getLength(); j++) {
            if (i != j) {
                cout << "	" << j << ": ";
                DynamicArray<int>* res = graph->shortestPathBFS(i, j);
                if (res == nullptr) cout << " ��� ����." << endl;
                else { print(res); cout << endl; }
            }
        }
    }
    cout << endl;
}
void t_grapPathAndLengthWithWeight(Graph* graph) {
    cout << "���������� ���� � ������ �����" << endl;
    for (int i = 0; i < graph->getLength(); i++) {
        cout << "�� ������� " << i << " �� " << endl;
        for (int j = 0; j < graph->getLength(); j++)
            if (i != j) {
                cout << "	" << j << ": ";
                try
                {
                    Pair< DynamicArray<int>*, int> res = graph->pathAndLengthWithWeight(i, j);
                    cout << "(" << res.second << ") ";
                    print(res.first);
                    cout << endl;

                }
                catch (const std::exception& e)
                {
                    cout << /*e.what()*/ "��� ����."<< endl;
                }

            }
    }
}
void t_graph_paths(Graph* graph) {
    cout << "���������� ���� (��� ����� �����)	(� ������ �����)" << endl;
    for (int i = 0; i < graph->getLength(); i++) {
        cout << "�� ������� " << i << " �� " << endl;
        for (int j = 0; j < graph->getLength(); j++)
            if (i != j) {
                cout << "	" << j << ": ";
                DynamicArray<int>* res_arr = graph->shortestPathBFS(i, j);
                if (res_arr == nullptr) cout << " ��� ����.";
                else print(res_arr);
                cout << "           	";
                try
                {
                    Pair< DynamicArray<int>*, int> res = graph->pathAndLengthWithWeight(i, j);
                    cout << "(" << res.second << ") ";
                    print(res.first);
                }
                catch (const std::exception& e)
                {
                    cout << " ��� ����.";
                }
                cout << endl;
            }
    }
}
void t_graph_painting(Graph* graph) {
    cout << "��������� �����" << endl;
    DynamicArray<Pair<int, int>>* res = graph->painting();
    for (int i = 0; i < res->getLength(); i++)
    {
        cout << "(" << res->get(i).first << ", " << res->get(i).second << ") ";
    }
    cout << endl << endl;
}
void t_graph_all(Graph* graph) {
    t_graph_isNeighbor(graph);
    t_graph_BFS(graph);
    t_graph_shortestPathBFS(graph);
    t_grapPathAndLengthWithWeight(graph);
    t_graph_paths(graph);
    t_graph_painting(graph);
}
void t_graph() {

    Graph* graph = makeGraph(PATH_FILE1);
    t_graph_all(graph);

    graph = makeGraph(PATH_FILE2);
    t_graph_all(graph);

    graph = makeGraph(PATH_FILE3);
    t_graph_all(graph);

    graph = makeGraph(PATH_FILE4);
    t_graph_all(graph);

}
void t_file_output() {
    fout.open(PATH_FILE);
    fout << "������ � ������� � �++";
    fout.close();
}

void tests() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (true)
    {
        while (true)
        {
            std::cout << std::endl;
            std::cout << "	(0)�����" << std::endl;
            std::cout << "1 - ��� �����;" << std::endl;
            std::cout << "2 - ������;" << std::endl;
            std::cout << "3 - �������;" << std::endl;
            std::cout << "4 - ����;" << std::endl;
            std::cout << "5 - ����;" << std::endl;
            std::cout << std::endl;
            std::cout << "6 - �����." << std::endl;
            std::cout << "�����: ";
            int choice = readInt(1, 6);
            switch (choice)
            {
                case 1:
                    t_llist();
                    t_queue();
                    t_stack();
                    t_graph();
                    std::cout << std::endl;
                    break;
                case 2:
                    t_llist();
                    std::cout << std::endl;
                    break;
                case 3:
                    t_queue();
                    std::cout << std::endl;
                    break;
                case 4:
                    t_stack();
                    std::cout << std::endl;
                    break;
                case 5:
                    t_graph();
                    std::cout << std::endl;
                    break;
                case 6:
                    return;
                    break;

            }
        }

    }
}

#endif // !TESTS_H