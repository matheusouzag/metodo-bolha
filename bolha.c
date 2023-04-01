#include "bolha.h"
#include <stdio.h>
#include <stdlib.h>

struct tReturn {
  int *vet;
  int tam;
  int erro;
};
// declara o tipo de dados tReturn

tReturn *alocatReturn() {
  tReturn *x = (tReturn *)malloc(sizeof(tReturn));

  return x;
}
// Essa função aloca memória para uma variável do tipo tReturn

int *getVet(tReturn *rep) { return rep->vet; }
// Essa função retorna o vetor contido na estrutura tReturn;

int getTam(tReturn *rep) { return rep->tam; }
// Essa função retorna o tamanho vetor contido na estrutura tReturn;

int getErro(tReturn *rep) { return rep->erro; }
// Essa função retorna o valor da variável error contido na estrutura tReturn;

void trataErro(int erro) {
  switch (erro) {
  case 1:

    printf("Erro ao abrir o arquivo\n");
    break;
  case 2:

    printf("Erro ao ler do arquivo\n");
    break;
  case 3:

    printf("Erro ao alocar memória\n");
    break;
  }
}
// Essa função trata os erros relativos à função leArquivo
// erro 1 : abertura do arquivo -- printf("Erro ao abrir o arquivo\n");
// erro 2: leitura do arquivo -- printf("Erro ao ler do arquivo\n");
// erro 3 : alocação de memória -- printf("Erro ao alocar memória\n");

tReturn *leArquivo(char nomeArquivo[]) {

  int i = 0, err = 0;
  FILE *arq;
  tReturn *rep = alocatReturn();

  arq = fopen(nomeArquivo, "rt");

  // Tratando erro 1
  if (arq == NULL) {
    rep->erro = 1;
    return rep;
  }

  fscanf(arq, "%d", &rep->tam);

  rep->vet = (int *)malloc(sizeof(int) * rep->tam);

  // Tratando erro 2
  if (rep->tam == 0) {
    rep->erro = 2;
    return rep;
  }

  // Tratando erro 3
  if (rep->vet == NULL) {
    rep->erro =3;
  }

  while (!feof(arq)) {
    err = fscanf(arq, "%d", &rep->vet[i]);

    if (err == 0){
      rep->erro = 2;
      return rep;
    }
    i++;
  }

  return rep;
}
// Essa função lê um arquivo com números inteiros (um número por linha) e
// preenche um vetor A primeira linha do arquivo contém o tamanho do vetor A
// função retorna o tipo TReturn formado por um ponteiro para inteiros, um
// inteiro que guarda o tamanho do vetor e um inteiro que codifica erros

int bolha(int *vet, int tam) {
  int aux, i, j, cont = 0;

  for (i = 0; i < tam; i++) {
    for (j = 1; j < tam; j++) {
      if (vet[j] < vet[j - 1]) {
        aux = vet[j - 1];
        vet[j - 1] = vet[j];
        vet[j] = aux;
      }
      cont++;
    }
  }

  return cont;
}
// Essa função ordena o vetor usando o método bolha e retorna a quantidade de
// comparações realizadas

int bolhaInteligente(int *vet, int tam) {

  int aux, i, j, cont = 0, troca = 1;

  for (i=0;i < tam-1 && troca == 1;i++) {
    troca = 0; // quando não há trocas, troca continuará 0
    for (j=0;j < tam-i-1;j++) {
      if (vet[j] > vet[j+1]) {
        aux = vet[j];
        vet[j] = vet[j+1];
        vet[j+1] = aux;
        troca = 1; // troca realizada
      }
      cont++;
    }
  }

  return cont;
}
// Essa função ordena o vetor usando o método bolha inteligente e retorna a
// quantidade de comparações realizadas

void imprimeVet(int *vet, int tam) {
  int i = 0;

  for (i = 0; i < tam; i++) {
    printf("%d\n", vet[i]);
  }
}
// Essa função imprime os dados de um vetor (um número por linha) -