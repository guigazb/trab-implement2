#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sll.h"
#include "sll.c"
#define true 1
#define false 0

typedef struct {
    char nome[30];
    int episodios;
    float nota;
}anime;


void listarColecao(Sllist *lista){ 
    int ind = 0;
    int num = sllNumNodes(lista);
    anime *var = (anime*) sllGetfirstcur(lista);
    if(lista != NULL && num > 0){
        while(var != NULL){
            printf("item %d: \n",ind + 1);
            printf("nome: %s ,episodios: %d ,nota: %.2f \n", var->nome, var->episodios, var->nota);
            var = (anime*)sllGetnext(lista);
            ind++;
        }
    }else if(num <= 0){
            printf("sem itens para imprimir \n");
        }
}  

int cmp(void* a, void* b){
    anime *pa = (anime *) a;
    anime *pb = (anime*) b;
    if(pa != NULL && pb != NULL){
        if(strcmp(pa->nome,pb->nome) == 0 && pa->episodios == pb->episodios && pa->nota == pb->nota){
           return true;
        }
        return false;
    }
    return -1;
}

int listaClean(Sllist* lista){ 
    if(lista != NULL){
        anime* delete;
        while(delete != NULL){
            delete = (anime*) sllRemovelast(lista);
        } 
        return true;
    }
    return false;
}

int main(){
    //criar colecao, inserir elementos
    
    int flag = true;
    void listarColecao(Sllist *lista);
    int cmp(void* a, void* b);
    int listaClean(Sllist* lista);

    Sllist *lista = NULL;

    while(flag == true){
        
        printf("1 - Criar colecao \n");
        printf("2 - Inserir um elemento \n");
        printf("3 - Remover um elemento \n");
        printf("4 - Consultar um elemento \n");
        printf("5 - Listar os elementos \n");
        printf("6 - Destruir a colecao \n");
        printf("7 - Esvaziar a colecao \n");
        printf("0 - Sair \n");
        printf("deseja realizar qual operacao? \n ");
        
        int opcao;
        scanf("%d", &opcao);
        switch(opcao){
            case 1:{
                if(lista!= NULL){
                    printf("existe uma colecao criada \n");
                    printf("destrua a colecao anterior antes de criar uma nova \n");
                    printf("\n");
                    break;
                }
                lista = sllCreate();
                if(lista != NULL){
                    printf("Colecao criada com sucesso! \n");
                    printf("\n");
                    break;
                }else{
                    printf("a coleção não foi criada, tente novamente... \n");
                    printf("\n");
                    break;
                }
            }
            case 2:{
                anime *item = (anime *) malloc(sizeof(anime));
                if(lista != NULL && item != NULL){
                    printf("Nome: ");
                    scanf(" %[^\n]s", item->nome);
                    printf("episodios: ");
                    scanf("%d", &item->episodios);
                    printf("nota: ");
                    scanf("%f", &item->nota);
                    if(sllInsertAsLast(lista,item) == true){ 
                        printf("anime inserido com sucesso \n");
                        printf("\n");
                        break;
                    }else{
                        printf("Erro ao inserir anime \n");
                        printf("\n");
                        break;
                    }
                }
                printf("erro de parametro \n");
                printf("crie uma colecao antes... \n");
                printf("\n");
                break;
            }
            case 3:{
                anime *item = (anime *) malloc(sizeof(anime));
                if(lista != NULL && item != NULL){
                    printf("Nome: ");
                    scanf(" %[^\n]s", item->nome);
                    printf("episodios: ");
                    scanf("%d", &item->episodios);
                    printf("nota: ");
                    scanf("%f", &item->nota);
                    if(sllRemovespec(lista, item, cmp) != NULL){
                        printf("item removido com sucesso! \n");
                        printf("\n");
                        break;
                    }else{
                       printf("nao foi possivel remover o item \n");
                       printf("\n");
                       break; 
                    }
                }
                printf("erro de parametro \n");
                printf("crie uma colecao antes ou insira um item valido... \n");
                printf("\n");
                break;
            }
            case 4:{
                anime *item = (anime*) malloc(sizeof(anime));
                if(lista != NULL && item != NULL){
                    printf("Nome: ");
                    scanf(" %[^\n]s", item->nome);
                    printf("episodios: ");
                    scanf("%d", &item->episodios);
                    printf("nota: ");
                    scanf("%f", &item->nota);

                    anime *chave = (anime*) sllQueryspec(lista, item, cmp); 
                    if(chave != NULL){
                        printf("anime encontrado ! \n");
                        printf("Nome: %s, episodios: %d, nota: %.2f \n", chave->nome, chave->episodios, chave->nota);
                        printf("\n");
                        break;
                    }else{
                        printf("O anime nao foi encontrado \n");
                        printf("\n");
                        break;
                    }  
                }
                printf("erro de parametro \n");
                printf("crie uma colecao antes ou insira um item valido... \n");
                printf("\n");
                break;
            }
            case 5:{ 
                if(lista != NULL){
                    printf("aqui estao os itens da colecao: \n");
                    listarColecao(lista);
                    printf("\n");
                    break;
                }
                printf("erro de parametro \n");
                printf("crie uma colecao antes ... \n");
                printf("\n");
                break;
            }
            case 6:{
                if(lista != NULL){
                    if(sllDestroy(lista) == true){
                        printf("Colecao destruida \n");
                        printf("\n");
                        lista = NULL;
                        break;
                    }else{
                        printf("A colecao nao foi destruida \n");
                        printf("esvazie a colecao antes de destruir \n");
                        printf("\n");
                        break;
                    }
                }
                printf("erro de parametro \n");
                printf("crie uma colecao antes ... \n");
                printf("\n");
                break;
            }
            case 7:{
                if(lista != NULL){
                    if(listaClean(lista) == true){ 
                       printf("A colecao foi esvaziada \n");
                       printf("\n");
                       break;
                    }else{
                      printf("A colecao nao foi esvaziada \n");
                      printf("\n");
                      break;
                    }
                }
                printf("erro de parametro \n");
                printf("crie uma colecao antes ... \n");
                printf("\n");
                break;
            }
            case 0:{
                printf("sistema encerrado com sucesso! \n");
                printf("\n");
                return 0;
            }
            default:{
                printf("opcao invalida \n");
                printf("\n");
                break;
            }
        }
    } flag = false;
}
