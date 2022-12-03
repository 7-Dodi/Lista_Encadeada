//==========================================
//== ESTRUTURA DE DADOS: LISTA ENCADEADA; ==
//== AUTOR: DOUGLAS;                      ==
//==========================================

//Liberando as bibliotecas para a constru��o da Lista
#include <stdio.h> 
#include <stdlib.h>

//Criando a estrutura de valores da lista
typedef struct nodo{ 
	int num;
	struct nodo *proximo;
}Nodo;

//Criando o ponteiro pra a estrutura de valores
typedef struct{
	Nodo *inicio;
}Lista;

//Iniciando o ponteiro
Lista *criarlista(){
	Lista *lista= (Lista*) malloc (sizeof (Lista));
	lista->inicio= NULL;
	return lista;
}

//Fun��o para adicionar um elemento no inicio
void push(Lista *lista, int num){ //Recebendo a lista e o valor de parametro
	Nodo *novo= (Nodo*) malloc (sizeof(Nodo)); //Criando uma estrutura de valores
	novo->num= num; //Adicionando o valor a estrutura criada
	novo->proximo= lista->inicio;
	lista->inicio= novo;
}

//Fun��o para adicionar um elemento no fim da lista
void pushFim (Lista *lista, int num){
	Nodo *aux, *novo = (Nodo*) malloc (sizeof(Nodo)); //Criando duas estruturas uma auxilia e outra para receber os parametros
	novo->num= num;
	novo->proximo= NULL;
	
	if(lista->inicio == NULL){ //Caso este seja o primeiro elemento a ser inserido na lista
		lista->inicio= novo;
	}
	else{ //Caso n�o seja o primeiro elemento
		aux= lista->inicio; 
		while(aux->proximo != NULL){ //Segue at� encontrar o ultimo elemento da estrutura
			aux= aux->proximo;
		}
		aux->proximo= novo; //Faz com que o ultimo elemento aponte para o novo dado adicionado
	} 
}

//Fun��o para remover um elemento
void remover (Lista *lista, int valor){
	Nodo *aux = lista->inicio; //Para localizar os dados da estrutura
	Nodo *NoRemover= NULL; //Para servi de c�pia para dado que ser� removido
	
	if(lista->inicio == NULL){ //Caso a lista esteja vazia
		printf("\n\nAVISO!! Nada a remover a lista est� vazia");
	}
	else{ //Caso a lista n�o esteja vazia
		if(lista->inicio->num == valor){ //Caso o elemento procurado seja o primeiro
			NoRemover= lista->inicio; //Faz-se a copia do elemento que ser� removido
			lista->inicio= NoRemover->proximo; //Se liga com o proximo elemento ou com a o vazio
		}
		else{ //Caso n�o seja o primeiro elemento
			while(aux->proximo != NULL && aux->proximo->num != valor){ //Procurar o elemento desejado ou ir at� o fim da lista
				aux= aux->proximo;
			}
			if(aux->proximo->num == valor){ //Caso o motivo da fim do while seja o encontro do valor
				NoRemover= aux->proximo; //Faz-se a copia
				aux->proximo= NoRemover->proximo; //Liga-se ao proximo elemento
			}
			else if (aux->proximo == NULL){ //Caso o valor n�o seja encontrado
				printf("\n\nAVISO!! Valor n�o encontrado");			
			}
			free(NoRemover); //Fun��o para remover o arquivo copiado
		}
	}
}

//Fun��o para imprimir a lista
void imprimir(Lista *lista){
	Nodo *aux= lista->inicio; //Estrutura auxiliar
	if(lista->inicio == NULL){ //Caso a lista esteja vazia
		printf("\n\nAVISO!! A lista esta vazia"); 
	}
	else{ //Imprimindo os dados da lista
		printf("\n\nImprimindo o valores informados:");
		while(aux != NULL){
		printf("%d ", aux->num);
		aux= aux->proximo;
	}
	}
}

//Fun��o para saber se a lista est� vazia ou n�o
int vazia(Lista *lista){
	if(lista->inicio == NULL){ //Caso esteja vazia
		return 0;
	}
	else{ //Caso n�o esteja vazia
		return 1;
	}
}

void main(){
	Lista *lista= criarlista(); //Iniciando a lista
	int opcao, num; //Variaveis para controlar os valores na interface
	do{//Menu
		printf("\n================ MENU ==============\n");
		printf("====================================\n");
		printf("1- Adicionar no inicio;\n2-Para adicionar no fim;\n3-Para remover um valor;\n4-Para imprimir\n0-Para encerrar\n");
		printf("====================================\n");
		scanf("%d", & opcao);
		switch(opcao){
			case 1 : 
				printf("\nInforme um valor:");
				scanf("%d", & num);
				push(lista, num);
				break;
			
			case 2 :
				printf("\nInforme um valor:");
				scanf("%d", & num);
				pushFim(lista, num);
				break;
			
			case 3 :
				if(vazia(lista) == 0){
					printf("\n\nA lista esta vazia");
				}
				else{
					printf("\nInforme um valor que deseja remover:");
					scanf("%d", & num);
					remover(lista, num);
				}
				break;
				
			case 4 :
				imprimir(lista);
				break;
				
			default: 
				if(opcao != 0){
					printf("\n\nAVISO!!! Opcao nao existente");	
				}
		}
	}while(opcao!=0);
	printf("Encerrando... digite qualquer tecla....");
	getch();
}

