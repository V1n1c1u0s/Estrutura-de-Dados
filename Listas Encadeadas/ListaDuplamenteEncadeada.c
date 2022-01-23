#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct aluno{
    char nome[128];
    float nota;
    struct aluno* ant;
    struct aluno* prox;
}ALUNO;

ALUNO* cadastrarAlunoInicio(ALUNO* lista, char nome[], float nota);
ALUNO* cadastrarAlunoFinal(ALUNO* lista, char nome[], float nota);
ALUNO* removerAlunoInicio(ALUNO* lista);
ALUNO* removerAlunoFinal(ALUNO* lista);
ALUNO* removerAlunoEspecifico(ALUNO* lista, char nome[]);
void mostrarAlunos(ALUNO* lista);
void opcoes();

int main(void){
    system("chcp 1252"); // system("chcp 1252>nul"), system("chcp 65001"), system("chcp 65001>nul");;;
    //setlocale(LC_ALL, "Portuguese");
    int opcao = 1;
    char nome[128];
    float nota;
    ALUNO* lista = NULL;
    while(opcao){
        system("cls");
        opcoes();
        printf("\nDigite sua opção: ");
        scanf("%d",&opcao);
        switch(opcao){
            case 1:
                printf("\nDigite o nome do aluno: ");
                scanf(" %[^\n]",nome);
                fflush(stdin);
                printf("Digite a nota do aluno: ");
                scanf("%f",&nota);
                fflush(stdin);
                lista = cadastrarAlunoInicio(lista, nome, nota);
                break;
            case 2:
                printf("\nDigite o nome do aluno: ");
                scanf(" %[^\n]",nome);
                fflush(stdin);
                printf("Digite a nota do aluno: ");
                scanf("%f",&nota);
                fflush(stdin);
                lista = cadastrarAlunoFinal(lista, nome, nota);
                break;
            case 3:
                lista = removerAlunoInicio(lista);
                break;
            case 4:
                lista = removerAlunoFinal(lista);
                break;
            case 5:
                printf("\nDigite o nome do Aluno que sera excluido: ");
                scanf(" %[^\n]",nome);
                fflush(stdin);
                lista = removerAlunoEspecifico(lista, nome);
                break;
            case 6:
                mostrarAlunos(lista);
                break;
            case 0:
                break;
            default:
                break;
        }
    }
    return 0;
}

void opcoes(){
    printf("\n[1] Cadastrar aluno no início");
    printf("\n[2] Cadastrar aluno no final");
    printf("\n[3] Remover aluno no início");
    printf("\n[4] Remover aluno no final");
    printf("\n[5] Remover Aluno Específico");
    printf("\n[6] Mostrar Alunos");
    printf("\n[0] Finalizar programa\n");
    return;
}

void mostrarAlunos(ALUNO* lista){
    system("cls");
    ALUNO* ptr = lista;
    ALUNO* tmp = NULL;
    if(ptr == NULL) return;
    printf("\nIndo\n");
    for(ptr = lista; ptr != NULL ; ptr = ptr->prox){
        printf("\nNome: %s\nNota: %.2f\n",ptr->nome,ptr->nota);
        tmp = ptr;
    }
    printf("\nVoltando\n");
    while(tmp != NULL){
        printf("\nNome: %s\nNota: %.2f\n",tmp->nome,tmp->nota);
        tmp = tmp->ant;
    }
    getch();
}

ALUNO* cadastrarAlunoInicio(ALUNO* lista, char nome[], float nota){
    ALUNO* ptr = (ALUNO*)malloc(sizeof(ALUNO));
    strcpy(ptr->nome,nome);
    ptr->nota = nota;
    ptr->ant = NULL;
    if(lista != NULL) lista->ant = ptr;
    ptr->prox = lista;
    return ptr;
}

ALUNO* cadastrarAlunoFinal(ALUNO* lista, char nome[], float nota){
    ALUNO* tmp = lista;
    ALUNO* ptr = (ALUNO*)malloc(sizeof(ALUNO));
    strcpy(ptr->nome,nome);
    ptr->nota = nota;
    ptr->ant = NULL;
    ptr->prox = NULL;
    if(tmp == NULL) return ptr;
    while (tmp->prox != NULL){
        tmp = tmp->prox;
    }
    ptr->ant = tmp;
    tmp->prox = ptr;
    return lista;
}

ALUNO* removerAlunoInicio(ALUNO* lista){
    ALUNO* ptr = lista;
    if(ptr == NULL) return ptr;
    ALUNO* tmp = ptr->prox;
    tmp->ant = NULL;
    free(ptr);
    return tmp;
}

ALUNO* removerAlunoFinal(ALUNO* lista){
    ALUNO* ptr = lista;
    ALUNO* tmp = NULL;
    if(ptr == NULL || ptr->prox == NULL) return NULL;
    while(ptr->prox != NULL){
        tmp = ptr;
        ptr = ptr->prox;
    }
    tmp->ant = tmp->ant;
    tmp->prox = NULL;
    free(ptr);
    return lista;
}

ALUNO* removerAlunoEspecifico(ALUNO* lista, char nome[]){
    ALUNO* ptr = lista;
    ALUNO* tmp = NULL;
    while(ptr != NULL && strcmp(ptr->nome,nome) != 0){
        tmp = ptr;
        ptr = ptr->prox;
    }
    if(ptr == NULL) return ptr;
    if(tmp == NULL)
        lista = ptr->prox;
    else
        tmp->prox = ptr->prox;
    free(ptr);
    return lista;
    //cuidar do ptr->ant
}
