#include <stdio.h>
#include <locale.h>
#define ESPACO ' '
#define DIM 3
void iniciar(char Matriz[][DIM]);
void tabuleiro(char Matriz[DIM][DIM]);
int verifGanhou(char Coordenada[DIM][DIM],char Simbolo);
int verifLinha(char linha[],char Simbolo);
int verifColuna(char Coordenada[DIM][DIM], int col,char Simbolo);
int verifDiagonal(char Coordenada[DIM][DIM], char Simbolo);
// inicia o Tabuleiro
void iniciar(char Matriz[][DIM])
{
	int i,j;
	for (i = 0; i < DIM; i++)
		for (j = 0; j < DIM; j++)
			Matriz[i][j] = ESPACO;
}
// mostra o aspecto do tabuleiro
void tabuleiro (char Matriz[DIM][DIM])
{
	int i,j;
	for (i = 0; i < DIM; i++)
	{
		for (j = 0; j < DIM; j++)
			printf ("%c %c",Matriz[i][j], j == DIM-1 ? ' ' : '|');
		if (i != DIM-1)
			printf("\n--------\n");
	}
}
/* Verifica se a linha esta preenchida com o char Simbolo (x ou o) */
int verifLinha(char Coordenada[],char Simbolo)
{
	return Coordenada[0] == Coordenada[1] && Coordenada[1] == Coordenada[2] && Coordenada[0] == Simbolo;
}
/* Verifica se a coluna col esta toda preenchida com o char Simbolo */
int verifColuna(char Coordenada[DIM][DIM], int col,char Simbolo)
{
	return Coordenada[0][col] == Coordenada[1][col] && Coordenada[1][col] == Coordenada[2][col] && Coordenada[0][col] == Simbolo;
}
/* Verifica se alguma das diagonais esta preenchida totalmente */
/* com o char Simbolo */
int verifDiagonal(char Coordenada[DIM][DIM],char Simbolo)
{
	return (Coordenada[0][0] == Coordenada[1][1] && Coordenada[2][2] == Coordenada[1][1] && Coordenada[0][0] == Simbolo) ||
	       (Coordenada[0][2] == Coordenada[1][1] && Coordenada[2][0] == Coordenada[1][1] && Coordenada[0][2] == Simbolo);
}
/* Verifica se o jogador do caractere Simbolo ganhou o jogo */
int verifGanhou(char Coordenada[DIM][DIM],char Simbolo)
{
	if (verifLinha (Coordenada[0],Simbolo) || verifLinha (Coordenada[1],Simbolo) || verifLinha (Coordenada[2],Simbolo))
		return 1;
	if (verifColuna (Coordenada,0,Simbolo) || verifColuna (Coordenada,1,Simbolo) || verifColuna (Coordenada,2,Simbolo))
		return 1;
	if (verifDiagonal (Coordenada,Simbolo))
		return 1;
	return 0; /* Nao ganhou o Jogo */
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
	char Velha[DIM][DIM];
	int PosX, PosY;
	char Simbolo = 'O'; /* Caractere a Jogar */
	int NumJogadas = 0;
	iniciar (Velha);
	
//Variaveis para finalizar o do-while
	int Ganhou = 0;
	int Empate = 0;
	
	do{
	    int True = 1; //Variavel para validar as posições escolhidas
        //Laço para validar as posições escolhidas pelo usuario
	    do{
	        tabuleiro (Velha);
	        printf ("\nIntroduza a Posição de Jogo Linha/Coluna: ");
		    scanf ("%d %d", &PosX, &PosY);
		    if (PosX > DIM || PosY > DIM || PosY < 1 || PosX < 1)
		    {
		    	printf ("\n\n**** Valores Inválidos ****\n\n");
		    	True = 0;
		    }
	    }while(!True);
	    
		PosX--;
		PosY--;
		
		if ( Velha[PosX][PosY] == ESPACO) /* Casa Livre */
		{
			Velha[PosX][PosY] = Simbolo = (Simbolo == 'O') ? 'X' : 'O';
			NumJogadas++;
			if (verifGanhou (Velha,Simbolo)) /* Basta verificar o jogador corrente */
			{
				printf("\n\n**** Ganhou o Jogador %c ****\n\n",Simbolo);
				Ganhou = 1;
			}
		}
		else
			printf ("Posição já ocupada!!!\nJogue Novamente!!!\n");
		if (NumJogadas == DIM*DIM)
		{
			printf ("\n\n**** EMPATE TÉCNICO ***\n\n");
			Empate = 1;
		}
	}while(!Ganhou && !Empate);
	tabuleiro (Velha);
}
