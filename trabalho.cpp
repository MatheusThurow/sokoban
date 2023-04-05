#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void ComandoProfesor()
{
	/// ALERTA: N O MODIFICAR O TRECHO DE C DIGO, A SEGUIR.
	// INICIO: COMANDOS PARA QUE O CURSOR N O FIQUE PISCANDO NA TELA
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
	// FIM: COMANDOS PARA QUE O CURSOR N O FIQUE PISCANDO NA TELA
	// IN CIO: COMANDOS PARA REPOSICIONAR O CURSOR NO IN CIO DA TELA
	short int CX = 0, CY = 0;
	COORD coord;
	coord.X = CX;
	coord.Y = CY;
	// FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO IN CIO DA TELA
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void movimento(char tecla, char matrizJogo[11][11], int &x, int &y)
{
	int modificadorX = 0, modificadorY = 0; //modifcadores de x e y da matriz

	if (_kbhit())//determinar se a tecla foi utilizada ou não
	{
		tecla = getch(); //funcionamento tecla
	}

	switch (tecla)
	{
	case 72:
	case 'w': // cima
		modificadorX = -1;  //linha x sobe
		modificadorY = 0;   //linha y permanece
		break;
	case 80:
	case 's': // baixo
		modificadorX = 1;   //linha x desce
		modificadorY = 0;   //permanece
		break;
	case 75:
	case 'a': // esquerda
		modificadorX = 0;   //permanece
		modificadorY = -1;  //vai para esquerda
		break;
	case 77:
	case 'd': // direita
		modificadorX = 0;   //permanece
		modificadorY = 1;   //direta
		break;
	}

	if (matrizJogo[x + modificadorX][y + modificadorY] != 1)
	{

		x += modificadorX;  //assumir o msm valor p/ ele andar horizontal
		y += modificadorY;  ////assumir o msm valor p/ ele andar vertical

		// Atualiza a posição das caixas, caso haja
        // 4 ponto de chegada da caixa 
        // 5 caixa

		switch (matrizJogo[x][y])
		{

		case 5:
			if (matrizJogo[x + modificadorX][y + modificadorY] == 0)
			{
				matrizJogo[x + modificadorX][y + modificadorY] = 5; 
				matrizJogo[x][y] = 0;
			}
			if (matrizJogo[x + modificadorX][y + modificadorY] == 4)   
			{
				matrizJogo[x + modificadorX][y + modificadorY] = 5;
				matrizJogo[x][y] = 0;
			}
			break;
		}
	}
    
}

void escolheMatriz(char matrizJogo[11][11], int escolhaMapa, int &x, int &y)
{

	char mapa1[11][11] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, // microban|| 10
						  1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, // y = 4                
						  1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, // x = 5
						  1, 5, 5, 5, 0, 0, 1, 0, 0, 0, 0,
						  1, 4, 4, 4, 0, 0, 1, 0, 0, 0, 0,
						  1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
						  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	char mapa2[11][11] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,  // microban |||
						  1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,  // y = 5
						  1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,  // x = 6
						  1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0,
						  1, 4, 5, 5, 0, 5, 0, 1, 0, 0, 0,
						  1, 0, 0, 4, 0, 4, 0, 1, 0, 0, 0,
						  1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0,
						  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
						  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	char mapa3[11][11] = {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, // sasquatch 1
						  0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, // x = 4
						  0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, // y = 4
						  1, 1, 0, 5, 0, 0, 0, 0, 0, 0, 1,
						  1, 0, 0, 0, 0, 5, 0, 1, 0, 0, 1,
						  1, 1, 1, 0, 5, 1, 1, 1, 0, 0, 1,
						  0, 0, 1, 0, 0, 1, 4, 4, 0, 0, 1,
						  1, 1, 1, 0, 1, 1, 4, 1, 0, 1, 1,
						  1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0,
						  1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0,
						  1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0};

	switch (escolhaMapa)
	{

	case 1: // escolher mapa e definir o ponto incial do personagem.
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				matrizJogo[i][j] = mapa1[i][j];
			}
		}

		x = 4;
		y = 5;      //mapa 1

		break;
	case 2:
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				matrizJogo[i][j] = mapa2[i][j];
			}
		}
		x = 5;
		y = 6;      //mapa 2
		break;
	case 3:
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				matrizJogo[i][j] = mapa3[i][j];
			}
		}
		x = 4;
		y = 4;      //mapa 3
		break;
	}
}

void imprimeMapaPersonagem(char matrizJogo[11][11], int x, int y)
{
	/// Imprime o jogo: mapa e personagem.
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (i == x && j == y)
			{

				cout << char(2); // personagem
			}
			else
			{
				switch (matrizJogo[i][j])
				{
				case 0:

					cout << " ";
					break; // caminho
				case 1:

					cout << char(219);
					break; // parede
				case 4:

					cout << char(248);
					break; // ponto p/ a caixa ficar
				case 5:

					cout << char(64);
					break; // caixa
						   // default: cout<<"-"; //erro
				}		   // fim switch
			}
		}
		cout << "\n";
	} // fim for mapa
}


void PausarLimpar() //não necessita de comentarios k k k k k 
{
	system("pause");
	system("cls");
}

void Dificuldade(char matrizJogo[11][11], int escolha, int &x,int &y)
{
	cout << " (1) THUrow" << endl;
	cout << " (2) Nicola" << endl;
	cout << " (3) Kaio" << endl;

	cout << "Escolha a Dificuldade do jogo: ";
	cin >> escolha;
	escolheMatriz(matrizJogo, escolha, x, y);   //utliza a função para ser emplementada junto com a dificul
}

void jogar()
{
	int escolha = 0;
	char matrizJogo[11][11];
	int x, y;
	char tecla;

	Dificuldade(matrizJogo, escolha, x, y);     //escolha da dificuldade, puxando a funça

	escolheMatriz(matrizJogo, escolha, x, y);   //escolha dos mapas

	system("cls");
	while (true)
	{
		ComandoProfesor();//n é pra modificar

		imprimeMapaPersonagem(matrizJogo, x, y);//puxa matriz personagem
		movimento(tecla, matrizJogo, x, y);//puxando a funçao da movimentaçao
	}
}

void Sobre()
{

	cout << endl;

	cout << "OQUE E O SOKOBAN?" << endl;
	cout << " E um tipo de jogo de transporte e movimentação de cubos ou engradados em um armazem. " << endl;
	cout << " O objetivo e pegar e estocar o engradado em determinada posicoes." << endl;
	cout << " O Sokoban originalfoi criado em 1981 por Hiroyuki Imabayashi, e publicado em 1982 por Thinking Rabbit," << endl;
	cout << " uma empresa de software localizada em Takarazuka." << endl;

	cout << endl;
	cout << endl;

	cout << "REGRAS:" << endl;
	cout << "O caramujo empurra caixas em torno de um labirinto e tenta coloca-los em locais designados. " << endl;
	cout << "Pressione a tecla de direção das casas adjacentes para empurrá-los. " << endl;
	cout << "Pressione 4 para revogar," << endl;
	cout << "pressione A para mover para cima," << endl;
	cout << "pressione V para mover para baixo," << endl;
	cout << "pressione <-- para mover para a esquerda, " << endl;
	cout << "pressione --> para mover para a direita, " << endl;

	cout << endl;

	cout << " EM D E S E N V O L V I M E N T O " << endl;

	cout << endl;
	cout << endl;

	cout << "EQUIPE DE DESENVOLVIMENTO:" << endl;

	cout << endl;

	cout << "Matheus Thurow" << endl;
	cout << "Rodrigo Nicola" << endl;
	cout << "kaio Saldanha" << endl;
	cout << "Professor: ---" << endl;
}

int main()
{

	int EscolhaMenu;
	int EscolheDificul;
	char matrizJogo[11][11];

	do
	{
		system("cls");
		ComandoProfesor();
		cout << " 1 - JOGAR" << endl;
		cout << " 2 - SOBRE" << endl;
		cout << " 3 - SAIR" << endl;
		cout << endl;
		cout << "ESCOLHA UMA DAS OPCOES ACIMA" << endl;
		cout << endl;
		cin >> EscolhaMenu;

		system("cls");

		switch (EscolhaMenu)
		{
		case 1:

			jogar();

			PausarLimpar();

			break;

		case 2:

			Sobre();

			cout << endl;

			PausarLimpar();

			break;

		case 3:

			cout << " saindo do jogo...." << endl;

			PausarLimpar();

			break;

		default:

			cout << "opcao invalida" << endl;

			PausarLimpar();

			break;
		}
	} while (EscolhaMenu != 4);

	return 0;
}