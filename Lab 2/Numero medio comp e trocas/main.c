/*
Alunos participantes;
João Vitor Gonçalves Oliveira - 11921bcc024
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10000

void geraValores(int vetor[], int tam) {
  int i;

  srand(time(NULL));

  for (i = 0; i < tam; i++) {
    int aleatorio = rand() % 500;
    vetor[i] = aleatorio;
  }
}

void troca(int vetor[], int p1, int p2) {
  int aux = vetor[p1];
  vetor[p1] = vetor[p2];
  vetor[p2] = aux;
}

void imprimeVetor(int vetor[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", vetor[i]);
  }
}

void BubbleSort(int vetor[], int n, int *comp, int *trocas) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - 1 - i; j++) {
      (*comp)++;
      if (vetor[j + 1] < vetor[j]) {
        troca(vetor, j, j + 1);
        (*trocas)++;
      }
    }
  }
}

void BubbleSort_otimizado(int vetor[], int n, int *comp, int *trocas) {
  int i, j, houveTroca;
  for (i = 0; i < n; i++) {
    houveTroca = 0;
    for (j = 0; j < n - 1 - i; j++) {
      (*comp)++;
      if (vetor[j + 1] < vetor[j]) {
        troca(vetor, j, j + 1);
        (*trocas)++;

        houveTroca = 1;
      }
    }

    if (houveTroca == 0)
      break;
  }
}


void InsertionSort(int vetor[], int n, int *comp, int *trocas) {
  int i, j, temp;

  for (i = 1; i < n; i++) {
    temp = vetor[i];
    for (j = i - 1; j >= 0 && vetor[j] > temp; j--) {
      (*comp)++;
      vetor[j + 1] = vetor[j];
      (*trocas)++;
    }
    vetor[j + 1] = temp;
    (*trocas)++;
  }
}

void SelectionSort(int vetor[], int n, int *comp, int *trocas) {
  int temp, menor, i, j;
  for (i = 0; i < n - 1; i++) {
    menor = i;
    for (j = i + 1; j < n; j++) {
      if (vetor[j] < vetor[menor]) {
        (*comp)++;
        menor = j;
      }
    }
    temp = vetor[i];
    vetor[i] = vetor[menor];
    vetor[menor] = temp;
    (*trocas)++;
  }
}

void ShellSort(int vetor[], int n, int *comp, int *trocas) {
  int i, j, h = 1, temp;
  do {
    h = h * 3 + 1;
  } while (h < n);

  do {
    h /= 3;
    for (i = h; i < n; i++) {
      temp = vetor[i];
      j = i;
      while (vetor[j - h] > temp) {
        (*comp)++;
        vetor[j] = vetor[j - h];
        (*trocas)++;
        j -= h;
        if (j < h)
          break;
      }
      vetor[j] = temp;

    }
  } while (h != 1);
}

void abcsort(int a[], int i, int j)
{
   int t, temp;

   if (a[j] < a[i]){
     temp = a[i];
     a[i] = a[j];
     a[j] = temp;
   }
   if (j - i > 1)
   {
       t = (j - i + 1) / 3;
       abcsort(a, i, j - t);
       abcsort(a, i + t, j);
       abcsort(a, i, j - t);
   }
}

void media10(int comp[], int troca[], int *mComp, int *mTroca){
  int temp = 0;
  for(int i = 0; i < 10; i++){
    temp = comp[i] + temp;
  }
  *mComp = temp/10;

  temp = 0;
  for(int i = 0; i < 10; i++){
    temp = troca[i] +temp;
  }
  *mTroca = temp/10;
}

int main(void) {
  int vetor[TAM];
  int comp[10], trocas[10];
  int mComp, mTroca;

  for(int i = 0; i < 10; i++){
    comp[i] = 0; trocas[i] = 0;
    geraValores(vetor, TAM);
    BubbleSort(vetor, TAM, &comp[i], &trocas[i]);
  }
  media10(comp, trocas, &mComp, &mTroca);
  printf("BubbleSort: Comparações: %d Trocas: %d\n", mComp, mTroca);

  for(int i = 0; i < 10; i++){
    comp[i] = 0; trocas[i] = 0;
    geraValores(vetor, TAM);
    BubbleSort_otimizado(vetor, TAM, &comp[i], &trocas[i]);
  }
  media10(comp, trocas, &mComp, &mTroca);
  printf("BubbleSort_otimizado: Comparações: %d Trocas: %d\n", mComp, mTroca);

  for(int i = 0; i < 10; i++){
    comp[i] = 0; trocas[i] = 0;
    geraValores(vetor, TAM);
    InsertionSort(vetor, TAM, &comp[i], &trocas[i]);
  }
  media10(comp, trocas, &mComp, &mTroca);
  printf("InsertionSort: Comparações: %d Trocas: %d\n", mComp, mTroca);

  for(int i = 0; i < 10; i++){
    comp[i] = 0; trocas[i] = 0;
    geraValores(vetor, TAM);
    SelectionSort(vetor, TAM, &comp[i], &trocas[i]);
  }
  media10(comp, trocas, &mComp, &mTroca);
  printf("SelectionSort: Comparações: %d Trocas: %d\n", mComp, mTroca);

  for(int i = 0; i < 10; i++){
    comp[i] = 0; trocas[i] = 0;
    geraValores(vetor, TAM);
    ShellSort(vetor, TAM, &comp[i], &trocas[i]);
  }
  media10(comp, trocas, &mComp, &mTroca);
  printf("ShellSort: Comparações: %d Trocas: %d\n", mComp, mTroca);


  return 0;
}