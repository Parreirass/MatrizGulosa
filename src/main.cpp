#include "mat.hpp"

int main() {
	int number_of_matrix = 5;
	Matrix m;
	int linhas = MAXROWS;
	int colunas = MAXCOLS;
	string matriz_atual[MAXROWS][MAXCOLS];
	FILE *f;
	int numero_matriz = 1;
	int soma_total_matrizes = 0;

	/*SetMatrixSignature();
	for(int i=0; i<number_of_matrix; i++)
		SaveMatrix(&m);*/
	
	fstream arquivo("dataset/input.data");

	for (int i=0; i< number_of_matrix; i++) {
		cout << endl << "NÚMERO MATRIZ:" << numero_matriz << endl << endl;
		LerMatriz(matriz_atual, linhas, colunas, arquivo);
		PercorrerMatriz(matriz_atual, linhas, colunas, arquivo, &soma_total_matrizes);
		cout << endl << "========================================" << endl << "========================================" << endl << endl;
		numero_matriz ++;
	}
	cout << endl << "SOMA TOTAL DAS MATRIZES: [" << soma_total_matrizes << "]" << endl; 
	
	return 0;
}