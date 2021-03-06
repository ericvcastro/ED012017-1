#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	char nome[100];
	char email [100];
	char telefone [20];
	struct Node *prox;
};
typedef struct Node node;

int tam;

void inicia(node *LISTA);
int menu(void);
void opcao(node *LISTA, int op);
node *criaNo();
void insereInicio (node *LISTA);
void exibe (node *LISTA);
void libera (node *LISTA);
void insere (node *LISTA);
void altera (node *LISTA);
void procura(node *LISTA);

int main(void)
{
	node *LISTA = (node *) malloc(sizeof(node));
	if(!LISTA){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
	inicia(LISTA);
	int opt;

	do{
		opt=menu();
		opcao(LISTA,opt);
	}while(opt);

	free(LISTA);
	return 0;
	}
}

void inicia(node *LISTA)
{
	LISTA->prox = NULL;
	tam=0;
}

int menu(void)
{
	int opt;
	printf("\nEscolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Zerar agenda\n");
	printf("2. Exibir agenda\n");
	printf("3. Adicionar contato\n");
	printf("4. Alterar contato\n");
    printf("5. Procura contato\n");
	printf("Opcao: ");
	scanf("%d", &opt);

	return opt;
}

void opcao(node *LISTA, int op)
{
	node *tmp;
	switch(op){
		case 0:
			libera(LISTA);
			break;

		case 1:
			libera(LISTA);
			inicia(LISTA);
			break;

		case 2:
			exibe(LISTA);
			break;

		case 3:
			insereInicio(LISTA);
			break;

		case 4:
		    altera(LISTA);
			break;

		case 5:
		    procura(LISTA);
			break;
		default:
			printf("Comando invalido\n\n");
	}
}

int vazia(node *LISTA)
{
	if(LISTA->prox == NULL)
		return 1;
	else
		return 0;
}

node *aloca()
{
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
	    setbuf(stdin, NULL);
		printf("\nNovo contato: \n Nome: ");
		scanf("%[^\n]s", &novo->nome);
		setbuf(stdin, NULL);
		printf("Email: ");
		scanf("%[^\n]s", &novo->email);
		setbuf(stdin, NULL);
		printf("Telefone: ");
		scanf("%[^\n]s", &novo->telefone);
		setbuf(stdin, NULL);
		printf("\nCADASTRO REALIZADO COM SUCESSO!\n");
		system("pause");
		system("cls");
		return novo;
	}
}

void insereInicio(node *LISTA)
{
	node *novo=aloca();
	node *oldHead = LISTA->prox;

	LISTA->prox = novo;
	novo->prox = oldHead;

	tam++;
}
void ordenar(node *LISTA) {
    if(LISTA == NULL || LISTA->prox == NULL)
    return; //se for nulo(vazio), ou apenas 1 elemento
    char s[100]; //precisa de espacao suficiente para armazenar o nome
node *t;
node *aux;

    while(aux != NULL) {
      t = aux->prox;
      while(t != NULL) {
        if(strcmp(aux->nome, t->nome) > 0) { //se vir depois
            strcpy(s, aux->nome);
            strcpy(aux->nome, t->nome);
            strcpy(t->nome, s);
        }
        t = t->prox;
      }
      aux = aux->prox;
    }
}
void exibe(node *LISTA)
{
system("cls");
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}
	node *tmp;
	tmp = LISTA->prox;
	printf("Lista de contatos: \n");
	while( tmp != NULL){
		printf("NOME: %s\n", tmp->nome);
		printf("EMAIL: %s\n", tmp->email);
		printf("TELEFONE: %s\n\n", tmp->telefone);
		tmp = tmp->prox;
	}
	system("pause");
	system("cls");
	printf("\n");
}

void libera(node *LISTA)
{
	if(!vazia(LISTA)){
		node *proxNode,
			  *atual;

		atual = LISTA->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
	printf("\n LISTA TELEFONICA ZERADA COM SUCESSO!\n");
	system("pause");
	system("cls");
}
void altera(node *LISTA)
{
system("cls");
char nome[100];
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}
	setbuf(stdin, NULL);
    printf("Qual nome do contato deseja alterar:");
    scanf("%[^\n]s",&nome);
    setbuf(stdin, NULL);
    while (LISTA!= NULL && strcmp(nome,LISTA->nome)!= 0){
    LISTA = LISTA->prox;
        if(strcmp(nome,LISTA->nome)== 0){
        printf("O contato a ser alterado e: %s\n",LISTA->nome);
        printf("Novo email: ");
        scanf("%[^\n]s",LISTA->email);
        setbuf(stdin, NULL);
        printf("Novo telefone: ");
        scanf("%[^\n]s",LISTA->telefone);
        setbuf(stdin, NULL);
        printf("\n\nContato alterado com sucesso!\n");
        }
            else
            printf("\nContato nao encontrado!\n\n");
            return ;
    }
}
void procura(node *LISTA)
{
system("cls");
char nome[100];
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}
setbuf(stdin, NULL);
printf("Qual o nome do contato deseja procurar: ");
scanf("%[^\n]s",&nome);
 setbuf(stdin, NULL);
    while (LISTA!= NULL && strcmp(nome,LISTA->nome)!= 0){
    LISTA = LISTA->prox;
        if(strcmp(nome,LISTA->nome)== 0){
        printf("\n\nCONTATO ENCONTRADO!\nNome: %s\n",LISTA->nome);
        printf("Email: %s\n",LISTA->email);
        printf("Telefone: %s\n",LISTA->telefone);
      }else printf("\nContato nao encontrado!\n\n");
      return ;
      }
}
