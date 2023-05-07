#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>


using namespace std;

//sobrecarga de função
void menu();
void imprimeMapaPersonagem(char matrizJogo[11][11], int x, int y);
void movimento(char tecla, char matrizJogo[11][11], int &x, int &y);
void escolheMatriz(char matrizJogo[11][11], int escolhaMapa, int &x, int &y);
void Dificuldade(char matrizJogo[11][11], int escolha, int &x, int &y);
void jogar();
void PausarLimpar();
void telabloqueio();
void carregarMapa(char m[11][11], int &x, int &y);
void salvarMapa(char m[11][11], int &x, int &y);



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

void salvarMapa(char m[11][11], int &x, int &y)
{
    ofstream mapasSalvos("mapas.txt");

    if (mapasSalvos.is_open())
    {

        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                if (i == x && j == y)
                {
                    mapasSalvos << '9'; // personagem
                }
                else
                {
                    switch (m[i][j])
                    {
                    case 0:
                        mapasSalvos << "0"; // caminho
                        break;
                    case 1:
                        mapasSalvos << '1'; // parede
                        break;
                    case 3:
                        mapasSalvos << '3'; // caixa
                        break;
                    case 4:
                        mapasSalvos << '4'; // posicao final
                        break;
                    case 5:
                        mapasSalvos << '5'; // caixa na posicao final
                        break;
                    } // fim switch
                }
            }
            mapasSalvos << endl;
        }
    }
}

void carregarMapa(char m[11][11], int &x, int &y)
{
    ifstream carregamento("mapas.txt"); //mesmo mapa do trabalho 

    if (carregamento.is_open())
    {

        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                char c;
                carregamento.get(c);

                switch (c)
                {
                case 9:
                    m[i][j] = char(24);
                    x = i;
                    y = j;
                    break;
                case 1:
                    m[i][j] = char(219);
                    break;
                case 3:
                    m[i][j] = char(176);
                    break;
                case 4:
                    m[i][j] = char(169);
                    break;
                case 5:
                    m[i][j] = char(178);
                    break;
                case 0:
                    m[i][j] = ' ';
                    break;
                }
            }
            carregamento.ignore('\n');
        }
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
                case 2:

                    cout << char(176);
                    break; // caixa em posição livre(movimentando)
                           // default: cout<<"-"; //erro
                case 3:

                    cout << char(248);
                    break; // posição final

                case 4:

                    cout << char(178);
                    break; // caixa em posição final
                }          // fim switch
            }
        }
        cout << "\n";
    } // fim for mapa
}

bool verificarVitoria(char matrizJogo[11][11]) {
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            if (matrizJogo[i][j] == 2) {
                return false; // Ainda não venceu
            }
        }
    }
    return true; // venceu - todas as caixas estão no lugar
}


void movimento(char tecla, char matrizJogo[11][11], int &x, int &y)
{
    int modificadorX = 0, modificadorY = 0; // modifcadores de x e y da matriz
    bool ganhar = false; // nova tentativa k k k k k


    if (_kbhit()) // determinar se a tecla foi utilizada ou não
    {
        tecla = getch(); // funcionamento tecla
    }

//switch reperente a movimentação normal (das teclas):

    switch (tecla)
    {
    case 8:
        salvarMapa(matrizJogo, x, y);   //tentativa do botão salvar
        break;

    case 72:
    case 'w':              // cima
        modificadorX = -1; // linha x sobe
        modificadorY = 0;  // linha y permanece
        break;
    case 80:
    case 's':             // baixo
        modificadorX = 1; // linha x desce
        modificadorY = 0; // permanece
        break;
    case 75:
    case 'a':              // esquerda
        modificadorX = 0;  // permanece
        modificadorY = -1; // vai para esquerda
        break;
    case 77:
    case 'd':             // direita
        modificadorX = 0; // permanece
        modificadorY = 1; // direta
        break;
    case 32:
        return menu();
    }
    
//switch referente a empurrar a caixa:

    switch (matrizJogo[x + modificadorX][y + modificadorY])
    {
    case 0:
        if (modificadorX != 0)
            x += modificadorX;
        if (modificadorY != 0)
            y += modificadorY;
        break;

    case 2:
        switch (matrizJogo[x + modificadorX * 2][y + modificadorY * 2]) // acima da caixa
        {
        case 0:
            matrizJogo[x + modificadorX][y + modificadorY] = 0;
            matrizJogo[x + modificadorX * 2][y + modificadorY * 2] = 2;
            if (modificadorX != 0)
                x += modificadorX;
            if (modificadorY != 0)
                y += modificadorY;
            break;

        case 3:
            matrizJogo[x + modificadorX][y + modificadorY] = 0;
            matrizJogo[x + modificadorX * 2][y + modificadorY * 2] = 4;
            if (modificadorX != 0)
                x += modificadorX;
            if (modificadorY != 0)
                y += modificadorY;
            break;
        }
        break;

    case 3:
        if (modificadorX != 0)
            x += modificadorX;
        if (modificadorY != 0)
            y += modificadorY;
        break;

    case 4:
        switch (matrizJogo[x + modificadorX * 2][y + modificadorY * 2])
        {
        case 0:
            matrizJogo[x + modificadorX][y + modificadorY] = 4;
            matrizJogo[x + modificadorX * 2][y + modificadorY * 2] = 2;
            if (modificadorX != 0)
                x += modificadorX;
            if (modificadorY != 0)
                y += modificadorY;
            break;

        case 3:
            matrizJogo[x + modificadorX][y + modificadorY] = 3;             
            matrizJogo[x + modificadorX * 2][y + modificadorY * 2] = 4;
            if (modificadorX != 0)
                x += modificadorX;
            if (modificadorY != 0)
                y += modificadorY;
            break;  
                verificarVitoria(matrizJogo);

        }
        break;
    }
    ganhar = verificarVitoria(matrizJogo); // atribua o resultado à variável ganhar

    if (ganhar == true) {
        cout << "Você venceu!" << endl;

        PausarLimpar();
        return menu();
        // Faça algo para encerrar o jogo ou oferecer opções para o jogador
    }
    /*verificarVitoria(matrizJogo,ganhar);*/
}

void escolheMatriz(char matrizJogo[11][11], int escolhaMapa, int &x, int &y)
{
    char mapa1[11][11] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, // microban|| 10
                          1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, /* posição inicial: x=4,y=5 */
                          1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0,
                          1, 2, 2, 2, 0, 0, 1, 0, 0, 0, 0,
                          1, 3, 3, 3, 0, 0, 1, 0, 0, 0, 0,
                          1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    char mapa2[11][11] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, // microban |||
                          1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, /* posição inicial: x=5,y=7 */
                          1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
                          1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0,
                          1, 3, 2, 2, 0, 2, 0, 1, 0, 0, 0,
                          1, 0, 0, 3, 0, 3, 0, 1, 0, 0, 0,
                          1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0,
                          1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    char mapa3[11][11] = {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, // sasquatch 1
                          0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, /* posição inicial: x=4,y=4 */
                          0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1,
                          1, 1, 0, 2, 0, 0, 0, 0, 0, 0, 1,
                          1, 0, 0, 0, 0, 2, 0, 1, 0, 0, 1,
                          1, 1, 1, 0, 2, 1, 1, 1, 0, 0, 1,
                          0, 0, 1, 0, 0, 1, 3, 3, 0, 0, 1,
                          1, 1, 1, 0, 1, 1, 3, 1, 0, 1, 1,
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

void Dificuldade(char matrizJogo[11][11], int escolha, int &x, int &y)
{
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    cout << "x                                                 x" << endl;
    cout << "x                   (1) THUrow                    x" << endl;
    cout << "x                   (2) Nicola                    x" << endl;
    cout << "x                   (3) APU                       x" << endl;
    cout << "x                                                 x" << endl;
    cout << "x         Escolha a Dificuldade do jogo           x" << endl;
    cout << "x                                                 x" << endl;
    cout << "x                                                 x" << endl;
    cout << "x     aperte 9 para voltar ao menu anterior       x" << endl;
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    cin >> escolha;
    escolheMatriz(matrizJogo, escolha, x, y);
    if(escolha == 9){                     // esta zero po motivos de n da pra por a barra de espaço
        return menu();
    }
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

void PausarLimpar()
{
    system("pause");
    system("cls");
}

void menu()//loop --> so sai quando for = 3
{

    int EscolhaMenu;
    int EscolheDificul;
    char matrizJogo[11][11];
    int tecla1; //n ta sendo utilizado
    int teclaa;
    int x,y;
    
    do
    {
        system("cls");
        system ("pause");
        ComandoProfesor();
        cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
        cout << "x                                                 x" << endl;
        cout << "x                       MENU:                     x" << endl;
        cout << "x                                                 x" << endl;
        cout << "x                     1~JOGAR~                    x" << endl;
        cout << "x                                                 x" << endl;
        cout << "x                     2~SOBRE~                    x" << endl;
        cout << "x                                                 x" << endl;
        cout << "x                     3~SAIR~                     x" << endl;
        cout << "x                                                 x" << endl;
        cout << "x                 4~CARREGAR MAPA                 x" << endl;
        cout << "x                                                 x" << endl;
        cout << "x       aperte 9 para voltar ao menu inicial      x" << endl;
        cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;

            cin >> teclaa;
        system("cls");

        if (_kbhit()) // determinar se a tecla foi utilizada ou não             n foi deu para por a barra de espaço para voltar por motivos desconhecidos
    {
        teclaa = getch(); // funcionamento tecla
    }
        switch (teclaa)
        {
        case 1:

            jogar();

            PausarLimpar();

            break;

        case 2:

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
        PausarLimpar();

            break;

        case 3:

            cout << " saindo do jogo...." << endl;

            PausarLimpar();

            break;
        
        case 4:
        
        carregarMapa(matrizJogo, x, y);

        break;

        case 9:     //ta 9 pq n consigo por a abrra de espaço

            return telabloqueio();  

            break;

        default:

            cout << "opcao invalida" << endl;

            PausarLimpar();

            break;
        }
    } while (teclaa != 3);{
        if(teclaa == 32){      //n funfa
        return telabloqueio();
    }
    }
}

void telabloqueio(){

    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    cout << "x                                                 x" << endl;
    cout << "x                                                 x" << endl;
    cout << "x                                                 x" << endl;
    cout << "x                                                 x" << endl;
    cout << "x                 S O K O B A N                   x" << endl;
    cout << "x                                                 x" << endl;
    cout << "x                                                 x" << endl;
    cout << "x                                                 x" << endl;
    cout << "x                                                 x" << endl;
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
        system("pause");
        menu();
}

int main()
{
    telabloqueio();
    return 0;
}
