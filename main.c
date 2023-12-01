#include <stdio.h>
#include <string.h>

void inverterString(char *str, int tamanho) {
    static int i = 0; //index que percorre a string - static pra manter o valor
    char temp; //armazena o caractere que o index percorreu para troca-lo no final da função
    if (i < tamanho / 2) { //divide por dois pq o char tem 2 bytes
        temp = str[i]; //pega o caractere que está na posição indicada pelo index
        str[i] = str[tamanho - i - 1]; //troca o caractere atual por o caractere na posição inversa (se o i estiver em 0, tamanho - 0 - 1)( o 1 para remover o caractere nulo)
        str[tamanho - i - 1] = temp;//troca o caractere da ultima posição pelo que foi armazenado na temp no inicio da chamada
        i++; //aumenta o index
        inverterString(str, tamanho); //chama a função de novo
    }
}

int tamanhoString(char *str) {
    if (*str == '\0') {
        return 0;
    } else {
        return 1 + tamanhoString(str + 1);
    }
}

int main() {
    FILE *teste;
    char string[150]; //buffer = recebe a quantidade de caracteres do arquivo + 1
    int tamanho;

    teste = fopen("teste.txt", "r"); //abre o arquivo no modo leitura

    if (teste == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fgets(string, sizeof(string), teste); //buffer, tamanho do buffer, nome do arquivo
    fclose(teste);

    tamanho = tamanhoString(string);

    teste = fopen("teste.txt", "a"); //abre o arquivo para adiconar linhas(a de append)

    if (teste == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fprintf(teste, "\nTamanho da string: %d\n", tamanho);

    inverterString(string, tamanho);

    fprintf(teste, "String invertida: %s\n", string);

    fclose(teste);

    printf("Concluido\n");

    return 0;
}
