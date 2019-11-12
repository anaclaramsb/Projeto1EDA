#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#include "Listas.h"

int main()
{
	tGuiche  UM, DOIS, TRES, PRIORIDADE; //O estabelecimento
	initGuiche(&UM);
	initGuiche(&DOIS);
	initGuiche(&TRES);
	initGuiche(&PRIORIDADE);

int cpf;
int tipo;
int prioridade;
char sair;
int senha;
	 //estabelecimento com 4 guiches(3 normais, 1 prioridade)
	while(sair != 'x'){
		printf("Digite seu cpf: ");
		scanf("%d", &cpf);
		printf("Digite seu nivel de complexidade (1- expresso, 2- normal, 3- complexo): ");
		scanf("%d", &tipo);
		while(tipo != 1 && tipo != 2 &&  tipo !=3){
			printf("Digite valores aceitaveis (1- expresso, 2- normal, 3- complexo): ");
			scanf("%d", &tipo);
		}
		printf("Digite 1 para prioridade ou 0 caso não: ");
		scanf("%d", &prioridade);
		while(prioridade != 0 && prioridade != 1){
			printf("Digite valores aceitaveis (1- prioridade, 0 - não prioridade):");
			scanf("%d", &prioridade);
		}
		senha = rand() % 1000;
		insereNoGuiche(&UM, &DOIS, &TRES, &PRIORIDADE,tipo, prioridade, cpf, senha);
		printf("Sua senha: %d \n", senha);
		

	

	printf("GUICHE UM, tempo de espera: %d\n", tempoGuiche(UM));
	imprimeGuiche(UM);
	printf("GUICHE DOIS, tempo de espera: %d\n", tempoGuiche(DOIS));
	imprimeGuiche(DOIS);
	printf("GUICHE TRES, tempo de espera: %d\n", tempoGuiche(TRES));
	imprimeGuiche(TRES);
	printf("GUICHE PRIORIDADE, tempo de espera: %d\n", tempoGuiche(PRIORIDADE));
	imprimeGuiche(PRIORIDADE);

	printf("Envie qualquer tecla para continuar a cadastrar novas senhas ou x para sair\n");
		scanf("%s", &sair);

	}
	botaoPanico(&DOIS, &UM, &TRES, &PRIORIDADE); //botão de panico, primeiro elemento o guiche em panico, demais entradas os outros guiches

	printf("GUICHE UM, tempo de espera: %d\n", tempoGuiche(UM));
	imprimeGuiche(UM);
	printf("GUICHE DOIS, tempo de espera: %d\n", tempoGuiche(DOIS));
	imprimeGuiche(DOIS);
	printf("GUICHE TRES, tempo de espera: %d\n", tempoGuiche(TRES));
	imprimeGuiche(TRES);
	printf("GUICHE PRIORIDADE, tempo de espera: %d\n", tempoGuiche(PRIORIDADE));
	imprimeGuiche(PRIORIDADE);
}
