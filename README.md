# MatrizGulosa
AEDS | CEFET-MG
</div>

<div style="display: inline-block;">
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> 
<img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Made%20for-VSCode-1f425f.svg"/> 
</a> 
</div>

<p> </p>
<p> </p>

<p align="justify">
	O trabalho Matriz Gulosa consiste em percorrer uma matriz de tamanho N x N, a partir da posição [0]x[0], passando apenas pelo maior valor adjacente, com o objetivo de chegar até a posição [N-1]x[N-1]. Dessa forma, o algorítmo orienta à apenas "andar" em 5 direções, leste, sudeste, sul, sudoeste e oeste, seguindo essa ordem de prioridade respectivamente.
</p>

<p align="justify">
	Para percorrer a matriz, existe a restrição de não "subi-la", pois o objetivo é chegar ao ponto extremo inferior direito, dessa forma, não faria sentido acessar uma posição cuja linha seja menor que a atual. 
</p>

<p align="center">
<img src="images/matriz_gulosa_editada.png"/> 
</p>

<p align="justify">
A partir da Fig. 1 é possível observar o funcionamento prático da matriz gulosa e sua ordem de prioridade. Partindo da posição [0]x[0], a próxima porição acessada foi a [0]x[1], que guardava o número 32. O algorítimo priorizou essa posição, pois, ao ordenar um vetor com o valor armazenado nas posições adjacentes à posição atual, o número 32 foi o maior. Observe também que, caso a posição atual tenha como coluna [0] ou [N-1], não será necessária a análise das posições à esquerda ou à direita, respectivamente, por não existirem na matriz.
</p>

<p align="justify">
Caso o algorítimo leve até a ultima linha, ele propõe que exista apenas a direção leste como possibilidade. Como pode-se observar na Fig. 1, ao chegar na posição [3]x[1], o maior número adjacente seria o 74, porém como ele atingiu a ultima linha, ele seguiu a direita até encontrar a posição final.
</p>

<p align="justify">
Caso existam dois números iguais nas posições adjacentes à atual, o algorítimo segue a ordem de prioridade de sentido citada acima. Ao encontrar a posição que armazena esse maior número, ele avança para tal posição, ignorando o mesmo número em outra posição menos prioritária.
</p>

<p align="justify">
Durante o caminho, é também tratado no algorítimo o tamanho do caminho percorrido, representado pela soma dos números que guardavam as posições. No caso da Fig. 1, o caminho total foi 621. 
</p>

<p align="justify">
No fim do programa, ao tratar de todas as matrizes presentes no arquivo input.data, ele, por fim, faz o somatório total do caminho de todas as matrizes e exibe ao usuário.
</p>

# Compilação e Execução

A estrutura árvore disponibilizada possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

<a style="color:black" href="mailto:felipeparreiras86@gmail.com?subject=[GitHub]%20Source%20Dynamic%20Lists">
✉️ <i>felipeparreiras86@gmail.com</i>
</a>
