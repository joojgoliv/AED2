/*
Alunos participantes;
João Vitor Gonçalves Oliveira - 11921bcc024
Bruno Barbosa de Freitas - 12011bcc057
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

void imprimeVetor(int vetor[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", vetor[i]);
  }
}

void troca(int vetor[], int p1, int p2){
  int aux = vetor[p1];
  vetor[p1] = vetor[p2];
  vetor[p2] = aux;
}

void BubbleSort(int vetor[], int n) {
  int i, j;
  for(i = 0; i < n; i++){
    for(j = 0; j < n-1-i; j++){
      if(vetor[j+1] < vetor[j]){
        troca(vetor, j, j+1);
      }
    }
  }
}

void BubbleSort_otimizado(int vetor[], int n) {
  int i, j, houveTroca;
  for(i = 0; i < n; i++){
    houveTroca = 0;
    for(j = 0; j < n-1-i; j++){
      if(vetor[j+1] < vetor[j]){
        troca(vetor, j, j+1);

        houveTroca = 1;
      }
    }

    if(houveTroca == 0)
      break;
  }
}

void InsertionSort(int vetor[], int n) {
  int i, j, temp;

  for (i = 1 ; i < n; i++){
    temp = vetor[i];
    for(j = i-1; j >= 0 && vetor[j] > temp; j--){
      vetor[j+1] = vetor[j];
    }
    vetor[j+1] = temp;
  }
}

void SelectionSort(int vetor[], int n) {
  int temp, menor, i, j;
    for (i=0; i < n-1; i++){
      menor = i;
      for(j = i+1; j < n; j++){
        if(vetor[j]<vetor[menor]){
          menor = j;
        }
      }
      temp = vetor[i];
      vetor[i] = vetor[menor];
      vetor[menor] = temp;
    }
  }

void ShellSort(int vetor[], int n) {
  int i, j, h = 1, temp;
  do{
    h = h * 3 + 1;
  }while(h < n);

  do{
    h /= 3;
    for(i = h; i < n; i++){
      temp = vetor[i];
      j = i;
      while(vetor[j-h] > temp){
        vetor[j] = vetor[j-h];
        j -= h;
        if(j < h) break;
      }
      vetor[j] = temp;
    }
  } while(h != 1);
}

int main(void) {
  int vetor[TAM];

  clock_t inicio, fim;

  // BUBBLESORT
  geraValores(vetor, TAM);

  inicio = clock();
  BubbleSort(vetor, TAM);
  fim = clock();

  printf("\nTempo do BubbleSort: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

  // BUBBLESORT Otimizado
  geraValores(vetor, TAM);

  inicio = clock();
  BubbleSort_otimizado(vetor, TAM);
  fim = clock();
  //imprimeVetor(vetor, TAM);

  printf("\nTempo do BubbleSort_otimizado: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
  //imprimeVetor(vetor, TAM);

  // INSERTIONSORT
  geraValores(vetor, TAM);

  inicio = clock();
  InsertionSort(vetor, TAM);
  fim = clock();

  printf("\nTempo do InsertionSort: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
  //imprimeVetor(vetor, TAM);

  // SELECTIONSORT
  geraValores(vetor, TAM);

  inicio = clock();
  SelectionSort(vetor, TAM);
  fim = clock();

  printf("\nTempo do SelectionSort: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
  //imprimeVetor(vetor, TAM);

  // SHELLSORT
  geraValores(vetor, TAM);

  inicio = clock();
  ShellSort(vetor, TAM);
  fim = clock();

  printf("\nTempo do ShellSort: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
  //imprimeVetor(vetor, TAM);

  return 0;
}