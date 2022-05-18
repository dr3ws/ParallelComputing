#pragma once

#include "Tree.h"

// ���������
#define MAX_VALUE 0xFFFFFFFF        // 4 294 967 295 (������������ �������� ��� ���������)
//#define GENERATE_COUNT 100          // ���������� ��������� ���������� �����
extern const char* EXTERNAL_FILE;   // ������ ���� ��� �������� � ������� ������

#define SUCCESS 0
#define ERROR_CREATE_THREAD -1
#define ERROR_JOIN_THREAD   -2

struct pthreadArg {
    struct tnode* tree;
    int threadCount;
};

// ��������� �������
tnode* makeRandomTree();
void exportTreeToFile(tnode* tree);
tnode* importTreeFromFile();
unsigned long long getCountOfFile();
unsigned long long getSumOfAllChilds(tnode* tree);
unsigned long long getSumOfAllChilds_OpenMP(tnode* tree);
void* getSumOfAllChilds_Pthread(void* args);