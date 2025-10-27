#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Sala
typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

// Função para criar uma nova sala (aloca memória dinamicamente)
Sala* criarSala(const char* nome) {
    Sala* novaSala = (Sala*)malloc(sizeof(Sala));
    if (novaSala == NULL) {
        perror("Erro ao alocar memória para a sala");
        exit(EXIT_FAILURE);
    }
    strncpy(novaSala->nome, nome, 49);
    novaSala->nome[49] = 0; // Garante terminação nula
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;
    return novaSala;
}

// Função para explorar as salas (exemplo de percurso em pré-ordem)
void explorarSalas(Sala* sala) {
    if (sala != NULL) {
        printf("Explorando: %s\\n", sala->nome);
        explorarSalas(sala->esquerda);
        explorarSalas(sala->direita);
    }
}

// Função para liberar toda a memória alocada recursivamente
void liberarSalas(Sala* sala) {
    if (sala != NULL) {
        liberarSalas(sala->esquerda);
        liberarSalas(sala->direita);
        free(sala);
    }
}

int main() {
    // Construção estática da árvore
    Sala* hallEntrada = criarSala("Hall de Entrada");
    hallEntrada->esquerda = criarSala("Sala de Estar");
    hallEntrada->direita = criarSala("Cozinha");

    hallEntrada->esquerda->esquerda = criarSala("Quarto Principal");
    hallEntrada->esquerda->direita = criarSala("Banheiro Social");
    hallEntrada->direita->esquerda = criarSala("Área de Serviço");
    hallEntrada->direita->direita = criarSala("Jardim de Inverno");

    // Inicia a exploração
    explorarSalas(hallEntrada);

    // Liberação de memória usando a função recursiva
    liberarSalas(hallEntrada);

    return 0;
}
