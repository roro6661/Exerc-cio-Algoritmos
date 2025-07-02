#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 5
#define MAX_NOME 100

// Função para calcular a média de 3 notas
float calcular_media(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3.0;
}

int main() {
    char nomes[MAX_ALUNOS][MAX_NOME];
    float notas[MAX_ALUNOS][3];
    float medias[MAX_ALUNOS];
    char situacao[MAX_ALUNOS][10];
    int i, j;
    int indice_maior_media = 0;

    // Entrada de dados
    for (i = 0; i < MAX_ALUNOS; i++) {
        printf("Digite o nome do aluno %d (sem espaços): ", i + 1);
        scanf("%s", nomes[i]);  // <-- sem espaços!

        for (j = 0; j < 3; j++) {
            printf("Digite a nota %d de %s: ", j + 1, nomes[i]);
            scanf("%f", &notas[i][j]);
        }

        // Calcula média
        medias[i] = calcular_media(notas[i][0], notas[i][1], notas[i][2]);

        // Define situação
        if (medias[i] >= 7.0) {
            strcpy(situacao[i], "Aprovado");
        } else {
            strcpy(situacao[i], "Reprovado");
        }

        // Verifica maior média
        if (medias[i] > medias[indice_maior_media]) {
            indice_maior_media = i;
        }
    }

    // Exibe tabela
    printf("\n%-20s %-6s %-6s %-6s %-6s %-10s\n", "Nome", "Nota1", "Nota2", "Nota3", "Média", "Situação");
    printf("------------------------------------------------------------------\n");
    for (i = 0; i < MAX_ALUNOS; i++) {
        printf("%-20s %-6.1f %-6.1f %-6.1f %-6.2f %-10s\n",
               nomes[i], notas[i][0], notas[i][1], notas[i][2], medias[i], situacao[i]);
    }

    // Mostra o campeão
    printf("\nAluno com a maior média: %s (%.2f)\n", nomes[indice_maior_media], medias[indice_maior_media]);

    return 0;
}
