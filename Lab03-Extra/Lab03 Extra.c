/*
Alunos participantes;
João Vitor Gonçalves Oliveira - 11921bcc024
Bruno Barbosa de Freitas - 12011bcc057
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM10k 1000
#define TAM50k 50000
#define TAM100k 100000

void geraValoresAleatorios(int vetor[], int tam) {
  int i;

  srand(time(NULL));

  for (i = 0; i < tam; i++) {
    int aleatorio = rand() % 500;
    vetor[i] = aleatorio;
  }
}

void geraValoresAscendentes(int vetor[], int tam) {
  int i;

  for (i = 0; i < tam; i++) {
    vetor[i] = i;
  }
}

void geraValoresDescendentes(int vetor[], int tam) {
  int i, j = tam;

  for (i = 0; i < tam; i++, j--) {
    vetor[i] = j;
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

void max_heapify(int arr[], int n, int i) {
    while (1) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            i = largest;
        } else {
            break;
        }
    }
}

void build_max_heap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(arr, n, i);
}

void heap_sort(int arr[], int n) {
    build_max_heap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        max_heapify(arr, i, 0);
    }
}

int Menu(){
  int op;
  printf("\nEscolha o tamanho de vetor:\n");
  printf("[1] Vetor de 10.000 elementos\n");
  printf("[2] Vetor de 50.000 elementos\n");
  printf("[3] Vetor de 100.000 elementos\n");
  printf("[0] Sair\n");
  scanf( "%d", &op);

  return op;
}

int MenuV(){
  int op;
  printf("\nEscolha o tipo de vetor:\n");
  printf("\n[1] Vetor aleatório");
  printf("\n[2] Vetor com valores decrescentes");
  printf("\n[3] Vator com valores crescentes\n");
  scanf( "%d", &op);

  return op;
}

int main(void) {
  int vetor10k[TAM10k];
  int vetor50k[TAM50k];
  int vetor100k[TAM100k];
  int opTamanho, opValores;

  clock_t inicio, fim;
  double tempoVetAl, tempoVetAsc, tempoVetDes;

  /*
  a)três tipos de entrada de dados: aleatória, em ordem ascendente e em ordem descendente
  b)para cada tipo de entrada de dados, use pelo menos três tamanhos de entrada iniciando com vetor de tamanho 10.000.
  */
  do{
    opTamanho = Menu();
    if(opTamanho == 0) break;
    opValores = MenuV();

    if(opTamanho == 1 && opValores == 1){
      geraValoresAleatorios(vetor10k, TAM10k);
      inicio = clock();
      ShellSort(vetor10k, TAM10k);
      fim = clock();
      printf("\n\nVETOR 10.000 ELEMENTOS ALEATÓRIOS");
      printf("\nTempo do ShellSort: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

      geraValoresAleatorios(vetor10k, TAM10k);
      inicio = clock();
      heap_sort(vetor10k, TAM10k);
      fim = clock();
      printf("\nTempo do Heap_Sort: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
    }
    else if(opTamanho == 1 && opValores == 2){
      geraValoresDescendentes(vetor10k, TAM10k);
      inicio = clock();
      ShellSort(vetor10k, TAM10k);
      fim = clock();
      printf("\n\nVETOR 10.000 ELEMENTOS DECRESCENTES");
      printf("\nTempo do ShellSort: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

      geraValoresDescendentes(vetor10k, TAM10k);
      inicio = clock();
      heap_sort(vetor10k, TAM10k);
      fim = clock();
      printf("\nTempo do Heap_Sort: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
    }
    else if(opTamanho == 1 && opValores == 3){
      geraValoresAscendentes(vetor10k, TAM10k);
      inicio = clock();
      ShellSort(vetor10k, TAM10k);
      fim = clock();
      printf("\n\nVETOR 10.000 ELEMENTOS CRESCENTES");
      printf("\nTempo do ShellSort: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

      geraValoresAscendentes(vetor10k, TAM10k);
      inicio = clock();
      heap_sort(vetor10k, TAM10k);
      fim = clock();
      printf("\nTempo do Heap_Sort: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
    }
    else if(opTamanho == 2 && opValores == 1){
      geraValoresAleatorios(vetor50k, TAM50k);
      inicio = clock();
      ShellSort(vetor50k, TAM50k);
      fim = clock();
      printf("\n\nVETOR 50.000 ELEMENTOS ALEATÓRIOS");
      printf("\nTempo do ShellSort: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

      geraValoresAleatorios(vetor50k, TAM50k);
      inicio = clock();
      heap_sort(vetor50k, TAM50k);
      fim = clock();
      printf("\nTempo do Heap_Sort: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
    }
    else if(opTamanho == 2 && opValores == 2){
      geraValoresDescendentes(vetor50k, TAM50k);
      inicio = clock();
      ShellSort(vetor50k, TAM50k);
      fim = clock();
      printf("\n\nVETOR 50.000 ELEMENTOS DECRESCENTES");
      printf("\nTempo do ShellSort: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

      geraValoresDescendentes(vetor50k, TAM50k);
      inicio = clock();
      heap_sort(vetor50k, TAM50k);
      fim = clock();
      printf("\nTempo do Heap_Sort: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
    }
    else if(opTamanho == 2 && opValores == 3){
        geraValoresAscendentes(vetor50k, TAM50k);
        inicio = clock();
        ShellSort(vetor50k, TAM50k);
        fim = clock();
        printf("\n\nVETOR 50.000 ELEMENTOS CRESCENTES");
        printf("\nTempo do ShellSort: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

        geraValoresAscendentes(vetor50k, TAM50k);
        inicio = clock();
        heap_sort(vetor50k, TAM50k);
        fim = clock();
        printf("\nTempo do Heap_Sort: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
    }
    else if(opTamanho == 3 && opValores == 1){
      geraValoresAleatorios(vetor100k, TAM100k);
      inicio = clock();
      ShellSort(vetor100k, TAM100k);
      fim = clock();
      printf("\n\nVETOR 100.000 ELEMENTOS ALEATÓRIOS");
      printf("\nTempo do ShellSort: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

      geraValoresAleatorios(vetor100k, TAM100k);
      inicio = clock();
      heap_sort(vetor100k, TAM100k);
      fim = clock();
      printf("\nTempo do Heap_Sort: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
    }
    else if(opTamanho == 3 && opValores == 2){
      geraValoresDescendentes(vetor100k, TAM100k);
      inicio = clock();
      ShellSort(vetor100k, TAM100k);
      fim = clock();
      printf("\n\nVETOR 100.000 ELEMENTOS DECRESCENTES");
      printf("\nTempo do ShellSort: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

      geraValoresDescendentes(vetor100k, TAM100k);
      inicio = clock();
      heap_sort(vetor100k, TAM100k);
      fim = clock();
      printf("\nTempo do Heap_Sort: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
    }
      else if(opTamanho == 3 && opValores == 3){
        geraValoresAscendentes(vetor100k, TAM100k);
        inicio = clock();
        ShellSort(vetor100k, TAM100k);
        fim = clock();
        printf("\n\nVETOR 100.000 ELEMENTOS CRESCENTES");
        printf("\nTempo do ShellSort: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

        geraValoresAscendentes(vetor100k, TAM100k);
        inicio = clock();
        heap_sort(vetor100k, TAM100k);
        fim = clock();
        printf("\nTempo do Heap_Sort: %f\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
    }
    else{
      printf("\n\nSelecione valores válidos.\n\n");
    }

  }while (opTamanho!=0);

  printf("\n\nFim do programa.");

  return 0;
}