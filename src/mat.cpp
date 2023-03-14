#include "mat.hpp"


/*void GenerateMatrix(Matrix *mat){
	
	for(int i=0; i<MAXROWS; i++)
        for(int j=0; j<MAXCOLS; j++)
            mat->m[i][j].val = rand()%999; 
}


void SetMatrixSignature(){
	FILE *f;

	if ((f = fopen("dataset/input.data", "w")) == NULL){
		printf("file could not be opened");
    	exit(-1);
    }

    fprintf(f,"%d %d", MAXROWS, MAXCOLS); 
    fprintf(f,"\n");
    fclose(f);

}

void SaveMatrix(Matrix *mat){
	
	FILE *f;

	if ((f = fopen("dataset/input.data", "a")) == NULL){
		printf("file could not be opened");
    	exit(-1);
    }

    GenerateMatrix(mat);

	for (int i=0;i<MAXROWS;i++){
        for (int j=0;j<MAXCOLS;j++)
             fprintf(f,"%d ", mat->m[i][j].val); 
        fprintf(f,"\n");
	}
	fprintf(f,"\n");
	fclose(f);
}*/

void LerMatriz(string matriz_atual[MAXROWS][MAXCOLS], int linhas, int colunas, fstream &arquivo)
{
	int j=0;
	
	if (arquivo.is_open()) 
	{
		string linha;
		string matriz_info;
		int c=0;

		getline(arquivo, linha);

		for (int i=0; i<linhas; i++)
		{
			getline(arquivo, linha);
			stringstream ss(linha);
			string substr;
			vector <string> substrings;
			
			while (getline(ss, substr, ' '))
			{
				substrings.push_back(substr);
				matriz_atual[i][c] = substr;
				c++;
			}
			c=0;
		}


		for (int i=0; i<linhas; i++) {
			for (int j=0; j<colunas; j++) {
				cout << matriz_atual[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		cout << "-----------MATRIZ PERCORRIDA------------" << endl << endl;
	}

    
}

void PercorrerMatriz(string matriz_atual[MAXROWS][MAXCOLS], int linhas, int colunas, fstream &arquivo, int *soma_total_matrizes)
{
	int i=0;
	int j=0;
	int proxima_linha=0;
	int proxima_coluna=0;
	int maior_valor=0;
	int soma_total = stoi(matriz_atual[0][0]);
	vector <int> vetor;
	int teste = 0;
	int contador = 0;

	matriz_atual[0][0].erase();
	matriz_atual[0][0] = "000";

	do {		
		if (j < MAXCOLS-1)
		//direita
			vetor.push_back(stoi(matriz_atual[i][j+1]));
		if ((j < MAXCOLS-1 && i < MAXROWS-1) || (j < MAXCOLS-1 && i < MAXROWS-1))
		//diagonal direita
			vetor.push_back(stoi(matriz_atual[i+1][j+1]));
		if (i < MAXROWS-1)
		//baixo
			vetor.push_back(stoi(matriz_atual[i+1][j]));
		if (i < MAXROWS-1 && j > 0)
		//diagonal esquerda
			vetor.push_back(stoi(matriz_atual[i+1][j-1]));
		if (j > 0)
		//esquerda
			vetor.push_back(stoi(matriz_atual[i][j-1]));

		
		sort(vetor.begin(), vetor.end(), [](int a, int b){return a > b; });
		
		if (i == MAXROWS-1) { //Última linha
			maior_valor = stoi(matriz_atual[i][j+1]);
			proxima_coluna = j+1;
			proxima_linha = i;
		}
		else { //Números no meio da matriz
			//Posição da direita
			if (stoi(matriz_atual[i][j+1]) == vetor[0]) {
				maior_valor = stoi(matriz_atual[i][j+1]);
				proxima_linha = i;
				proxima_coluna = j+1;
			}
			//Diagonal direita
			else if (stoi(matriz_atual[i+1][j+1]) == vetor[0]) {
				maior_valor = stoi(matriz_atual[i+1][j+1]);
				proxima_linha = i+1;
				proxima_coluna = j+1;
			}
			//Posição Abaixo
			else if (stoi(matriz_atual[i+1][j]) == vetor[0]) {
				maior_valor = stoi (matriz_atual[i+1][j]);
				proxima_linha = i+1;
				proxima_coluna = j;
			}
			//Diagonal Esquerda
			else if (stoi(matriz_atual[i+1][j-1]) == vetor[0]) {
				maior_valor = stoi(matriz_atual[i+1][j-1]);
				proxima_linha = i+1;
				proxima_coluna = j-1;
			}
			//Posição da Esquerda
			else if (stoi(matriz_atual[i][j-1]) == vetor[0]) {
				maior_valor = stoi(matriz_atual[i][j-1]);
				proxima_linha = i;
				proxima_coluna = j-1;
			}
		}
		i = proxima_linha;
		j = proxima_coluna;
		
		matriz_atual[i][j].erase();
		matriz_atual[i][j] = "000";
		soma_total += maior_valor;

		
		teste ++;
		vetor.clear();
		cout << "POSIÇÃO: [" << i << "]"<< " " << "[" << j << "]" << endl;
		cout << "MAIOR VALOR: [" << maior_valor << "]" << endl << endl;

	}while(i != MAXCOLS-1 || j != MAXROWS-1);
	
	for (int i=0; i<linhas; i++) {
			for (int j=0; j<colunas; j++) {
				cout << matriz_atual[i][j] << " ";
			}
			cout << endl;
		}
	cout << endl;
	cout << "Soma total do caminho: " << soma_total << endl;
	*soma_total_matrizes += soma_total;
	//cout << endl << "TESTE:" << *soma_total_matrizes << endl;
	soma_total = 0;
}