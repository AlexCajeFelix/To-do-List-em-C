// function.h
#ifndef FUNCTION_H   // Evita m�ltiplas inclus�es do cabe�alho
#define FUNCTION_H

// Declara��o de vari�veis globais
extern int i;
extern int Voltar;
extern int opcao;
extern int excluir;
extern int ContadorTarefas;
extern int AcessarFuncao;

// Defini��o da estrutura
typedef struct {
    int id;
    char Titulo[30];
    char Descricao[30];
} StructCard;

// Declara��o das fun��es
void RetornarpagAnterios();
void CriarTarefa();
void EditarTarefa();
void Excluir();
void VisualizarTodos();
void VisualizarporID();
void VisualizarporDescricao();
void Menu();

#endif // FUNCTION_H
