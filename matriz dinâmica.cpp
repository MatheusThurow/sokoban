/* TENTATIVA EM CHAR

#include <iostream>
#include <fstream>
using namespace std;

//utilizando matriz dinamica 
int main(){
    // Abre o arquivo para leitura
    ifstream arquivo(R"(C:\Users\mathe\mapas\1.txt)");

    // Verifica se o arquivo foi aberto corretamente
    if (!arquivo)
    {
        cout << "Erro ao abrir o arquivo." << std::endl;
        return 1;
    }

    // Lê o número de matrizes do arquivo
    int numMatrizes;
    arquivo >> numMatrizes; //aqui ele vai ler um valor inteiro do arquivo e armazená-lo na variável numMatrizes.Ou seja a matriz é inteira e n feita em char !

    // Aloca memória para armazenar informações das matrizes
    char ***matrizes = new char**[numMatrizes];
    char *linhasMatrizes = new char[numMatrizes];
    char *colunasMatrizes = new char[numMatrizes];


    // Loop para ler cada matriz do arquivo
    for (int i = 0; i < numMatrizes; i++)
    {
        char linhas, colunas;
        arquivo >> linhas >> colunas;

        // Armazena as dimensões da matriz
        linhasMatrizes[i] = linhas;
        colunasMatrizes[i] = colunas;

        // Aloca memória para a matriz
        matrizes[i] = new char *[linhas];
        for (int j = 0; j < linhas; j++)
        {
            matrizes[i][j] = new char[colunas];
            for (int k = 0; k < colunas; k++)
            {
                // Lê os elementos da matriz do arquivo
                arquivo >> matrizes[i][j][k];
            }
        }
    }

    // Fecha o arquivo após a leitura
    arquivo.close();

    // Exemplo de uso: escolher e imprimir uma matriz
    int indiceMatriz;
    cout << "Digite o índice da matriz que deseja imprimir (0 a " << numMatrizes - 1 << "): ";
    cin >> indiceMatriz;

    // Verifica se o índice é válido
    if (indiceMatriz >= 0 && indiceMatriz < numMatrizes)
    {
        cout << "Matriz selecionada:" << endl;
        for (int i = 0; i < linhasMatrizes[indiceMatriz]; i++)
        {
            for (int j = 0; j < colunasMatrizes[indiceMatriz]; j++)
            {
                // Imprime os elementos da matriz selecionada
                cout << matrizes[indiceMatriz][i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Índice de matriz inválido." << std::endl;
    }

    // Liberando a memória alocada
    for (int i = 0; i < numMatrizes; i++)
    {
        for (int j = 0; j < linhasMatrizes[i]; j++)
        {
            delete[] matrizes[i][j];
        }
        delete[] matrizes[i];
    }
    delete[] matrizes;
    delete[] linhasMatrizes;
    delete[] colunasMatrizes;

    return 0;
}


*/

#include <iostream>
#include <fstream>
using namespace std;

//utilizando matriz dinamica 
int main(){
    // Abre o arquivo para leitura
    ifstream arquivo(R"(C:\Users\mathe\mapas\1.txt)");

    // Verifica se o arquivo foi aberto corretamente
    if (!arquivo)
    {
        cout << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    // Lê o número de matrizes do arquivo
    int numMatrizes;
    arquivo >> numMatrizes; //aqui ele vai ler um valor inteiro do arquivo e armazená-lo na variável numMatrizes.Ou seja a matriz é inteira e n feita em char !

    // Aloca memória para armazenar informações das matrizes
    int ***matrizes = new int**[numMatrizes];
    int *linhasMatrizes = new int[numMatrizes];
    int *colunasMatrizes = new int[numMatrizes];


    // Loop para ler cada matriz do arquivo
    for (int i = 0; i < numMatrizes; i++)
    {
        int linhas, colunas;
        arquivo >> linhas >> colunas;

        // Armazena as dimensões da matriz
        linhasMatrizes[i] = linhas;
        colunasMatrizes[i] = colunas;

        // Aloca memória para a matriz
        matrizes[i] = new int *[linhas];
        for (int j = 0; j < linhas; j++)
        {
            matrizes[i][j] = new int[colunas];
            for (int k = 0; k < colunas; k++)
            {
                // Lê os elementos da matriz do arquivo
                arquivo >> matrizes[i][j][k];
            }
        }
    }

    // Fecha o arquivo após a leitura
    arquivo.close();

    // Exemplo de uso: escolher e imprimir uma matriz
    int indiceMatriz;
    cout << "Digite o índice da matriz que deseja imprimir (0 a " << numMatrizes - 1 << "): ";
    cin >> indiceMatriz;

    // Verifica se o índice é válido
    if (indiceMatriz >= 0 && indiceMatriz < numMatrizes)
    {
        cout << "Matriz selecionada:" << endl;
        for (int i = 0; i < linhasMatrizes[indiceMatriz]; i++)
        {
            for (int j = 0; j < colunasMatrizes[indiceMatriz]; j++)
            {
                // Imprime os elementos da matriz selecionada
                cout << matrizes[indiceMatriz][i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Índice de matriz inválido." << endl;
    }

    // Liberando a memória alocada
    for (int i = 0; i < numMatrizes; i++)
    {
        for (int j = 0; j < linhasMatrizes[i]; j++)
        {
            delete[] matrizes[i][j];
        }
        delete[] matrizes[i];
    }
    delete[] matrizes;
    delete[] linhasMatrizes;
    delete[] colunasMatrizes;

    return 0;
}
