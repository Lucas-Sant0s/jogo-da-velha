#include <iostream>

using namespace std;

void tabuleiro(char casas2[9]) { // tabuleiro
	system("cls"); // Para não repetir toda vez que um valor é inserido
	printf("\t %c | %c | %c \n", casas2[0], casas2[1], casas2[2]);
	printf("\t----------- \n");
	printf("\t %c | %c | %c \n", casas2[3], casas2[4], casas2[5]);
	printf("\t----------- \n");
	printf("\t %c | %c | %c \n", casas2[6], casas2[7], casas2[8]);
}

int main() {
	
	char casas[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9'}; // Recebe cada casa do jogo
	char res; // Resposta do usuario se quer jogar novamente
	int cont_jogadas, jogada, vez = 0, i; // Jogadas e vez
	
	do{ // Start
			
		cont_jogadas = 1;
		for(i=0; i<=9; i++){ // Esse for limpa os numeros 
			casas[i] = ' ';
		} // monstra o tabuleiro e pede a jogada
		do{ // Aqui começa o jogo
		tabuleiro(casas);
		printf("Digite a casa para marcar! Exemplo: \n 1 2 3 \n 4 5 6 \n 7 8 9 \n \n \n");
		scanf("%i", &jogada);
			if(jogada < 1 || jogada > 9) { // Começa as condições das jogadas
			jogada = 0;
		} 	if (casas[jogada - 1] != ' '){
			jogada = 0;
				} else {
					if(vez%2 == 0){
						casas[jogada-1] = 'X';
					} else {
						casas[jogada-1] = 'O'; 
					}
				}
			cont_jogadas++;
			vez++;
			
			// Cada possibilidade de vitoria abaixo:
			
			if(casas[0] == 'X' && casas[1] == 'X' && casas[2] == 'X'){cont_jogadas = 11;}
			if(casas[3] == 'X' && casas[4] == 'X' && casas[5] == 'X'){cont_jogadas = 11;}
			if(casas[6] == 'X' && casas[7] == 'X' && casas[8] == 'X'){cont_jogadas = 11;}
			if(casas[0] == 'X' && casas[4] == 'X' && casas[8] == 'X'){cont_jogadas = 11;}
			if(casas[2] == 'X' && casas[4] == 'X' && casas[6] == 'X'){cont_jogadas = 11;}
			if(casas[0] == 'X' && casas[3] == 'X' && casas[6] == 'X'){cont_jogadas = 11;}
			if(casas[2] == 'X' && casas[5] == 'X' && casas[8] == 'X'){cont_jogadas = 11;}
			if(casas[3] == 'X' && casas[4] == 'X' && casas[5] == 'X'){cont_jogadas = 11;}
			
			if(casas[0] == 'O' && casas[1] == 'X' && casas[2] == 'X'){cont_jogadas = 12;}
			if(casas[3] == 'O' && casas[4] == 'X' && casas[5] == 'X'){cont_jogadas = 12;}
			if(casas[6] == 'O' && casas[7] == 'X' && casas[8] == 'X'){cont_jogadas = 12;}
			if(casas[0] == 'O' && casas[4] == 'X' && casas[8] == 'X'){cont_jogadas = 12;}
			if(casas[2] == 'O' && casas[4] == 'X' && casas[6] == 'X'){cont_jogadas = 12;}
			if(casas[0] == 'O' && casas[3] == 'X' && casas[6] == 'X'){cont_jogadas = 12;}
			if(casas[2] == 'O' && casas[5] == 'X' && casas[8] == 'X'){cont_jogadas = 12;}
			if(casas[3] == 'O' && casas[4] == 'O' && casas[5] == 'O'){cont_jogadas = 12;}
			
		} while(cont_jogadas <= 9);		
		
		tabuleiro(casas); 
		if(cont_jogadas == 10){
			printf("Jogo empatado!! \n");
		}
		if(cont_jogadas == 11){
			printf("O Jogador 'X' Ganhou!! \n");
		}
		if(cont_jogadas == 12){
			printf("O Jogador 'O' Ganhou!! \n");
		}
		cout << ("Deseja jogar novamente?[S-N] \n");
		cin >> ("%s", &res);
		  
	} while (res == 'S' || 's');
	return 0;	
}

