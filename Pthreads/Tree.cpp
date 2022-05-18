#include <stdio.h>
#include <fstream>
#include <iostream>

#include "Tree.h"

using namespace std;

// ���������� ����
tnode* addNode(unsigned long long v, tnode* tree)
{
	if (tree == NULL)
	{
		tree = new tnode;		// ������ ��� ����
		tree->value = v;		// �������� ��������
		tree->sum = 0;			// ����� �������� �������� �����
		tree->left = NULL;		// ����� �������
		tree->right = NULL;		// ������ �������
	}
	else if (v < tree->value)	// ������� ���������� ������ �������
		tree->left = addNode(v, tree->left);
	else if (v > tree->value)	// ������� ���������� ������� �������
		tree->right = addNode(v, tree->right);
	return(tree);
}