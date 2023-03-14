#ifndef MAT_H 
#define MAT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXCOLS 8
#define MAXROWS 8

typedef struct Item{
	int val;
}Item;

typedef struct Matrix{
	Item m[MAXROWS][MAXCOLS];
}Matrix;

//void GenerateMatrix(Matrix *mat);
//void SetMatrixSignature();
//void SaveMatrix(Matrix *mat);

void LerMatriz(string matriz_atual[MAXROWS][MAXCOLS], int linhas, int colunas, fstream &arquivo);
void PercorrerMatriz(string matriz_atual[MAXROWS][MAXCOLS], int linhas, int colunas, fstream &arquivo, int *soma_total_matrizes);

#endif