#include <stdio.h>
#include <ctime>
#include <fstream>
#include <omp.h>
#include <math.h>
#include <clocale>

#include "Tree.h"
#include "TreeUtils.h"

using namespace std;

double startTime, endTime;

int log2(int n) {
    return int(log(n) / log(2));
}

void defaultSum() {
    cout << "------============[DEFAULT]============------" << endl;
    tnode* tree = importTreeFromFile();

    startTime = omp_get_wtime();
    unsigned long long sum = getSumOfAllChilds(tree);
    endTime = omp_get_wtime();

    cout << "Время выполнения:\t" << endTime - startTime << endl;
    cout << "Сумма дочерних узлов:\t" << sum << endl << endl;
}

void pthreadSum() {
    cout << "------============[PTHREAD]============------" << endl;
    tnode* tree = importTreeFromFile();

    int threads = omp_get_num_procs();
    unsigned long long elementCount = getCountOfFile();
    cout << "Количество потоков:\t" << threads << "\nКоличество элментов:\t" << elementCount << endl;

    pthreadArg arg;
    arg.tree = tree;
    arg.threadCount = threads;

    startTime = omp_get_wtime();
    getSumOfAllChilds_Pthread((void*)&arg);
    endTime = omp_get_wtime();

    cout << "Время выполнения:\t" << endTime - startTime << endl;
    cout << "Сумма дочерних узлов:\t" << arg.tree->sum << endl << endl;
}

void openMpSum() {
    cout << "------============[OPENMP]============------" << endl;
    tnode* tree = importTreeFromFile();

    int threads = omp_get_num_procs();
    unsigned long long elementCount = getCountOfFile();
    cout << "Количество потоков:\t" << threads << "\nКоличество элементов:\t" << elementCount << endl;

    omp_set_nested(1);
    omp_set_max_active_levels((log2(20)));

    startTime = omp_get_wtime();
    unsigned long long sum = getSumOfAllChilds_OpenMP(tree);
    endTime = omp_get_wtime();

    cout << "Время выполнения:\t" << endTime - startTime << endl;
    cout << "Сумма дочерних узлов:\t" << sum << endl << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    tnode* tree = makeRandomTree();
    exportTreeToFile(tree);

    defaultSum();
    pthreadSum();
    openMpSum();

    system("pause");
}
