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

void escolheMatriz(char matrizJogo[11][11], int escolhaMapa, int &x, int &y)
{

	char mapa1[11][11] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, // microban|| 10
						  1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, /* posição inicial: x=4,y=5 */
						  1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0,
						  1, 5, 5, 5, 0, 0, 1, 0, 0, 0, 0,
						  1, 4, 4, 4, 0, 0, 1, 0, 0, 0, 0,
						  1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
						  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	char mapa2[11][11] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, // microban |||
						  1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
						  1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
						  1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0,
						  1, 4, 5, 5, 0, 5, 0, 1, 0, 0, 0,
						  1, 0, 0, 4, 0, 4, 0, 1, 0, 0, 0,
						  1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0,
						  1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
						  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	/* y =5
	   x =7 */

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
		y = 5;

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
		y = 7;
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
		y = 4;
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

					cout << char(176);
					break; // caixa
						   // default: cout<<"-"; //erro
				case 6:

					cout << char(178);
					break; // caixa no lugar certo
				}		   // fim switch
			}
		}
		cout << "\n";
	} // fim for mapa
}

void movimento(char tecla, char matrizJogo[11][11], int &x, int &y)
{
	int modificadorX = 0, modificadorY = 0; // modifcadores de x e y da matriz

	if (_kbhit()) // determinar se a tecla foi utilizada ou não
	{
		tecla = getch(); // funcionamento tecla
	}

	switch (tecla)
	{
	case 72:
	case 'w':			   // cima
		modificadorX = -1; // linha x sobe
		modificadorY = 0;  // linha y permanece
		break;
	case 80:
	case 's':			  // baixo
		modificadorX = 1; // linha x desce
		modificadorY = 0; // permanece
		break;
	case 75:
	case 'a':			   // esquerda
		modificadorX = 0;  // permanece
		modificadorY = -1; // vai para esquerda
		break;
	case 77:
	case 'd':			  // direita
		modificadorX = 0; // permanece
		modificadorY = 1; // direta
		break;
	}

    switch (matrizJogo[x + modificadorX][y + modificadorY])
    {
    case 0:
        if (modificadorX != 0)
            x += modificadorX;
        if (modificadorY != 0)
            y += modificadorY;
        break;

    case 5:
        switch (matrizJogo[x + modificadorX * 2][y + modificadorY * 2]) // acima da caixa
        {
        case 0:
            matrizJogo[x + modificadorX][y + modificadorY] = 0;
            matrizJogo[x + modificadorX * 2][y + modificadorY * 2] = 5;
            if (modificadorX != 0)
                x += modificadorX;
            if (modificadorY != 0)
                y += modificadorY;
            break;

        case 4:
            matrizJogo[x + modificadorX][y + modificadorY] = 0;
            matrizJogo[x + modificadorX * 2][y + modificadorY * 2] = 6;
            if (modificadorX != 0)
            x += modificadorX;
            if (modificadorY != 0)
                y += modificadorY;
            break;
        }
        break;

    case 4:
        if (modificadorX != 0)
            x += modificadorX;
        if (modificadorY != 0)
            y += modificadorY;
        break;

    case 6:
        switch (matrizJogo[x + modificadorX * 2][y + modificadorY * 2])
        {
        case 0:
            matrizJogo[x + modificadorX][y + modificadorY] = 4;
            matrizJogo[x + modificadorX * 2][y + modificadorY * 2] = 5;
            if (modificadorX != 0)
                x += modificadorX;
            if (modificadorY != 0)
                y += modificadorY;
            break;

        case 4:
            matrizJogo[x + modificadorX][y + modificadorY] = 4;
            matrizJogo[x + modificadorX * 2][y + modificadorY * 2] = 6;
            if (modificadorX != 0)
                x += modificadorX;
            if (modificadorY != 0)
                y += modificadorY;
            break;
        }
        break;
    }
}
void PausarLimpar()
{
	system("pause");
	system("cls");
}

void Dificuldade(char matrizJogo[11][11], int escolha, int &x, int &y)
{
	cout << " (1) THUrow" << endl;
	cout << " (2) Nicola" << endl;
	cout << " (3) APU" << endl;

	cout << "Escolha a Dificuldade do jogo: ";
	cin >> escolha;
	escolheMatriz(matrizJogo, escolha, x, y);
}

void jogar()
{
	int escolha = 0;
	char matrizJogo[11][11];
	int x, y;
	char tecla;

	Dificuldade(matrizJogo, escolha, x, y);

	escolheMatriz(matrizJogo, escolha, x, y);

	system("cls");
	while (true)
	{
		ComandoProfesor();

		imprimeMapaPersonagem(matrizJogo, x, y);
		movimento(tecla, matrizJogo, x, y);
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
