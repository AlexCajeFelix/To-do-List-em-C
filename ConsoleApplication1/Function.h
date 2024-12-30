// function.h
#ifndef FUNCTION_H   // Evita múltiplas inclusões do cabeçalho
#define FUNCTION_H

// Declaração de variáveis globais
extern int i;
extern int Voltar;
extern int opcao;
extern int excluir;
extern int ContadorTarefas;
extern int AcessarFuncao;

// Definição da estrutura
typedef struct {
    int id;
    char Titulo[30];
    char Descricao[30];
} StructCard;

// Declaração das funções
void RetornarpagAnterios();
void CriarTarefa();
void EditarTarefa();
void Excluir();
void VisualizarTodos();
void VisualizarporID();
void VisualizarporDescricao();
void Menu();

#endif // FUNCTION_H
