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


void listarColecao(Sllist *lista){ // consertar traço das funções e implementação delas
    anime *var = (anime*) sllGetfirstcur(lista);// consertar
    int ind = 0;
    int num = sllNumNodes(lista);
    if(lista != NULL && num > 0){
        while(var != NULL){
            printf("item %d: \n",ind + 1);
            printf("nome: %s ,preco: %d ,duracao: %.2f \n", var->nome, var->episodios, var->nota);
            var = (anime*)sllGetnext(lista); // consertar
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
        int numItens = sllNumNodes(lista);
        for(int i = 0; i <numItens; i++){
            sllRemovelast(lista);
        } 
        return true;
    }
    return false;
}

int main(){
    //criar cofo, inserir elementos, e para cada elemento inserido incrementar a variavel Atual para listar o cofo posteriormente
    
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
                    printf("destrua a colecao anterior antes de criar uma nova\n");
                    break;
                }
                lista = sllCreate();
                if(lista != NULL){
                    printf("Colecao criada com sucesso! \n");
                    break;
                }else{
                    printf("a coleção não foi criada, tente novamente... \n");
                    break;
                }
            }
            case 2:{
                anime *item = (anime *) malloc(sizeof(anime));
                if(lista != NULL && item != NULL){
                    printf("Nome: ");
                    scanf("%s", item->nome);
                    printf("episodios: ");
                    scanf("%d", &item->episodios);
                    printf("nota: ");
                    scanf("%f", &item->nota);
                    if(sllInsertAsLast(lista,item) == true){ 
                        printf("anime inserido com sucesso \n");
                        break;
                    }else{
                        printf("Erro ao inserir anime \n");
                        break;
                    }
                }
                printf("erro de parametro \n");
                break;
            }
            case 3:{
                anime *item = (anime *) malloc(sizeof(anime));
                if(lista != NULL && item != NULL){
                    printf("Nome: ");
                    scanf("%s", item->nome);
                    printf("episodios: ");
                    scanf("%d", &item->episodios);
                    printf("nota: ");
                    scanf("%f", &item->nota);
                    if(sllRemovespec(lista, item, cmp) != NULL){
                        printf("item removido com sucesso! \n");
                        break;
                    }else{
                       printf("nao foi possivel remover o item \n");
                       break; 
                    }
                }
                printf("erro de parametro \n");
                break;
            }
            case 4:{
                anime *item = (anime*) malloc(sizeof(anime));
                if(lista != NULL && item != NULL){
                    printf("Nome: ");
                    scanf("%s", item->nome);
                    printf("episodios: ");
                    scanf("%d", &item->episodios);
                    printf("nota: ");
                    scanf("%f", &item->nota);

                    anime *chave = (anime*) sllQueryspec(lista, item, cmp); 
                    if(chave != NULL){
                        printf("anime encontrado ! \n");
                        printf("Nome: %s, episodios: %d, nota: %.2f \n", chave->nome, chave->episodios, chave->nota);
                        break;
                    }else{
                        printf("O anime nao foi encontrado \n");
                        break;
                    }  
                }
                printf("erro de parametro \n");
                break;
            }
            case 5:{ // consertar a função de listar
                if(lista != NULL){
                    listarColecao(lista); // mata o código
                    break;
                }
                printf("erro de parametro \n");
                break;
            }
            case 6:{
                if(lista != NULL){
                    if(sllDestroy(lista) == true){
                        printf("Colecao destruida \n");
                        lista = NULL;
                        break;
                    }else{
                        printf("A colecao nao foi destruida \n");
                        break;
                    }
                }
                printf("erro de parametro \n");
                break;
            }
            case 7:{
                if(lista != NULL){
                    if(listaClean(lista) == true){ // quebra o código
                       printf("A colecao foi esvaziada \n");
                       break;
                    }else{
                      printf("A colecao nao foi esvaziada \n");
                      break;
                    }
                }
                printf("erro de parametro \n");
                break;
            }
            case 0:{
                printf("sistema encerrado com sucesso! \n");
                return 0;
            }
            default:{
                printf("opcao invalida \n");
                break;
            }
        }
    } flag = false;
}