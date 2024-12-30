#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#define MAX 100
#define _CRT_SECURE_NO_WARNINGS

int i = 0;
int Voltar = 0;
int opcao;
int excluir;
int ContadorTarefas = 0;
int AcessarFuncao;
int LocalizaId;
StructCard Tarefas[MAX];


void RetornarpagAnterios() {
    printf("Você deseja Voltar ou continuar nessa página: \n");
    printf("Digite 1 para voltar e 0 para continuar\n");
    scanf_s("%i", &Voltar);
    while (getchar() != '\n'); 
    if (Voltar == 1) {
        Menu();
    }
}


void CriarTarefa() {
    for (i = 0; i < 4; i++) {
        printf(" --------------------- Criar Lista de Afazeres ------------------------ \n");
        printf("Criar o Titulo: \n"); 
        fgets(Tarefas[ContadorTarefas].Titulo, sizeof(Tarefas[ContadorTarefas].Titulo), stdin);
        printf("Criar a descricao: \n");
        fgets(Tarefas[ContadorTarefas].Descricao, sizeof(Tarefas[ContadorTarefas].Descricao), stdin);
        Tarefas[ContadorTarefas].id = ContadorTarefas + 1;
        printf("Tarefa criada com sucesso! ID: %d\n", Tarefas[ContadorTarefas].id);
        ContadorTarefas++;
        RetornarpagAnterios();
    }
}


void EditarTarefa() {
    printf(" --------------------- Editando Cards ------------------------ \n");
    printf("Digite o ID do card que você gostaria de Editar \n");
    RetornarpagAnterios();
}


void Excluir() {
    int excluir;
    int encontrado = 0;
    printf(" --------------------- Apagando os Cards ------------------------ \n");
    printf("Digite o ID do card que você gostaria de apagar:\n");
    scanf_s("%d", &excluir);
   
    if (excluir > ContadorTarefas) {
        printf("Esse ID nao existe\n");
    }
    else {
    
        for (int i = excluir; i < ContadorTarefas - 1; i++) {
            strcpy_s(Tarefas[i].Titulo, sizeof(Tarefas[i].Titulo), Tarefas[i + 1].Titulo);
            strcpy_s(Tarefas[i].Descricao, sizeof(Tarefas[i].Descricao), Tarefas[i + 1].Descricao);
        }
       
        ContadorTarefas--;
    }

    RetornarpagAnterios();
}


void VisualizarTodos() {
    printf(" --------------------- Visualizar Todos os Cards ------------------------ \n");
    system("cls");
    if (ContadorTarefas == 0) {
        printf("Nenhuma tarefa encontrada.\n");
        return;
    }
    for (int i = 0; i < ContadorTarefas; i++) {
        printf("ID: %d\n", Tarefas[i].id);
        printf("Titulo: %s\n", Tarefas[i].Titulo);
        printf("Descricao: %s\n", Tarefas[i].Descricao);
        printf("-----------------------------------------\n");
    }
    RetornarpagAnterios();
}


void VisualizarporID() {
    
    printf(" --------------------- Apagando os Cards ------------------------ \n");
    printf("Digite o ID do card que você gostaria de Visualizar:\n");
    scanf_s("%d", &LocalizaId);

        if (LocalizaId < ContadorTarefas) {
                printf("ID: %d\n", Tarefas[LocalizaId].id);
                printf("Titulo: %s\n", Tarefas[LocalizaId].Titulo);
                printf("Descricao: %s\n", Tarefas[LocalizaId].Descricao);
                printf("-----------------------------------------\n");
            }
            else {
                printf("Nenhuma Card encontrado.\n");
            }
    
    RetornarpagAnterios();

}

void VisualizarporDescricao() {
    char VisualizarporDescricao[100];

    printf(" --------------------- Visualizando os Cards ------------------------ \n");
    printf("Digite a descricao do card que você gostaria de Visualizar:\n");
    fgets(VisualizarporDescricao, sizeof(VisualizarporDescricao), stdin);

    int encontrado = 0; 

    
    for (int i = 0; i < ContadorTarefas; i++) {
        
        if (strstr(Tarefas[i].Descricao, VisualizarporDescricao) != NULL) {
           
            printf("ID: %d\n", Tarefas[i].id);
            printf("Titulo: %s\n", Tarefas[i].Titulo);
            printf("Descricao: %s\n", Tarefas[i].Descricao);
            printf("-----------------------------------------\n");
            encontrado = 1; 
        }
    }

    
    if (!encontrado) {
        printf("Nenhuma tarefa encontrada com essa descricao.\n");
    }

}

void Menu() {
    system("cls");
    printf("Digite o que você gostaria de fazer: \n");
    printf("1 - Criar \n");
    printf("2 - Editar \n");
    printf("3 - Excluir \n");
    printf("4 - Visualizar Todos \n");
    printf("5 - Visualizar por ID \n");
    printf("6 - Visualizar por Descricao \n");
    scanf_s("%d", &AcessarFuncao);
    while (getchar() != '\n');  

    switch (AcessarFuncao) {
    case 1:
        system("cls");
        printf("Você escolheu Criar Tarefa.\n");
        CriarTarefa();
        break;
    case 2:
        system("cls");
        printf("Você escolheu Editar Tarefa.\n");
        EditarTarefa();
        break;
    case 3:
        system("cls");
        printf("Você escolheu Excluir.\n");
        Excluir();
        break;
    case 4:
        VisualizarTodos();
        break;
    case 5:
        system("cls");
        printf("Você escolheu Visualizar por ID.\n");
        VisualizarporID();
        break;
    case 6:
        system("cls");
        printf("Você escolheu Visualizar por Descrição.\n");
        VisualizarporDescricao();
        break;
    default:
        system("cls");
        printf("Opção inválida. Tente novamente.\n");
        break;
    }
}
