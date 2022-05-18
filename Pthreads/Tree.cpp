#include <stdio.h>
#include <fstream>
#include <iostream>

#include "Tree.h"

using namespace std;

// ƒобавление узла
tnode* addNode(unsigned long long v, tnode* tree)
{
	if (tree == NULL)
	{
		tree = new tnode;		// пам€ть под узел
		tree->value = v;		// числовое значение
		tree->sum = 0;			// сумма значений дочерних узлов
		tree->left = NULL;		// левый потомок
		tree->right = NULL;		// правый потомок
	}
	else if (v < tree->value)	// условие добавлени€ левого потомка
		tree->left = addNode(v, tree->left);
	else if (v > tree->value)	// условие добавлени€ правого потомка
		tree->right = addNode(v, tree->right);
	return(tree);
}