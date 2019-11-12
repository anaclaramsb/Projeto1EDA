#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#include "Listas.h"


tCliente* alocaCliente(int valor, int prio, int cpf, int senha) { //aloca cliente

	tCliente* novo = (tCliente *)malloc(sizeof(tCliente));

	if (novo != NULL) {
		novo->tipo = valor;
		novo->prioridade=prio;
		novo->prox = NULL;
		novo->senha = senha;
		novo->cpf = cpf;
		}

	return novo;
}


void initGuiche(tGuiche* G){ //inicia Guiche
	G->numElem = 0;
	G->tempo = 0;
	G->tempocorrido = 0;
	G->sequencia = 0;
	G -> inicio = NULL;
}

void imprimeGuiche(tGuiche G){

	printf("========================\n");
	
	if (G.inicio == NULL)
		printf("LISTA VAZIA !!!\n");
	else
		while (G.inicio != NULL) {
			printf("cliente com cpf %d senha:%d  tipo:%d \n ", G.inicio->cpf, G.inicio->senha, G.inicio->tipo);
			G.inicio = G.inicio->prox;
		}
	printf("========================\n");
	printf("\n");
}

int tempoGuiche(tGuiche G){
	return G.tempo;
}

bool insereNoGuiche(tGuiche* um, tGuiche* dois, tGuiche* tres, tGuiche* pri, int tipo, int prioridade, int cpf, int senha){
tCliente* novo = alocaCliente(tipo, prioridade, cpf, senha);
tGuiche* guiche;

if (novo == NULL)
		return false;

if(prioridade == 1){ //pessoa com prioridade vai para fila de prioridade
	guiche = pri;
}
else{
	if(um->tempo < dois->tempo){
		if(um->tempo < tres->tempo){
			guiche = um;
		}
		else{
			guiche = tres;
		}
	}
	else{
		if(dois->tempo < tres->tempo){
			guiche = dois;
		}
		else{
			guiche = tres;
		}
	}
}


	tCliente* ultimo = guiche->inicio;

	if (ultimo == NULL)		// Lista Vazia
		guiche->inicio = novo;	

	else { 							// Lista nao Vazia

		while (ultimo->prox != NULL)
			ultimo = ultimo->prox;

		ultimo->prox = novo;
		}

	guiche->numElem++;
	guiche->tempo = guiche->tempo + tipo;
	guiche->tempocorrido = guiche->tempocorrido + tipo;

	if(guiche->numElem == X){ //limite de pessoas para descanso
		guiche->numElem = 0;
		guiche ->tempocorrido = 0;
		guiche->tempo = guiche->tempo + 5; //tempo de pausa
	}
	else if(guiche->tempocorrido >= Y){ //limite de tempo para descanso
		guiche->numElem = 0;
		guiche ->tempocorrido = 0;
		guiche->tempo = guiche->tempo + 5; //tempo de pausa
	}
	
	return true;

}


