#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraAleatorio(int vetor[], int tamanho) {
    srand(time(NULL)); 
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 10000; // Gera um número aleatório entre 0 e 9999
    }
}

void geraCrescente(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i + 1;
    }
}

void geraDecrescente(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - i;
    }
}

void geraRepticoes(int vetor[], int tamanho) {
    srand(time(NULL)); 
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 50; // Gera um número aleatório entre 0 e 49
    }
}

void troca(int vetor[], int i, int j){
  int aux = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = aux;
}

int particao(int vetor[], int esq, int dir){
  int i, pivo;
  pivo = esq;
  for(i = esq + 1; i <= dir; i++){
    if(vetor[i] < vetor[esq]){
      pivo = pivo +1;
      troca(vetor, pivo, i);
    }
  }
  troca(vetor, esq, pivo);
  
  return pivo;
}
// QS NORMAL
void quicksort(int vetor[], int esq, int dir){
  int i;
  if(esq >= dir) return;
  i = particao(vetor, esq, dir);
  quicksort(vetor, esq, i-1);
  quicksort(vetor, i+1, dir);
}

// PIVO ALEATORIO
int pivo_aleatorio(int esq, int dir){
double r;
  r = (double) rand()/RAND_MAX;
  
  return (int)(esq + r*(dir-esq));
}
// QUICKSORT ALEATORIO
void quicksort_aleatorizado(int vetor[], int esq, int dir){
  int i;
  if(dir <= esq) return;
  troca(vetor, pivo_aleatorio(esq, dir), esq);
  i = particao(vetor, esq, dir);
  quicksort_aleatorizado(vetor, esq, i-1);
  quicksort_aleatorizado(vetor, i+1, dir);
}

// PIVO med3
void quicksort_mediana_tres(int vetor[], int esq, int dir){
  int i;
  if(dir <= esq) return;
  troca(vetor, (esq +dir)/2, esq+1);
  if(vetor[esq] > vetor[esq+1]) troca(vetor, esq, esq+1);
  if(vetor[esq] > vetor[dir]) troca(vetor, esq, dir);
  if(vetor[esq+1] > vetor[dir]) troca(vetor, esq+1, dir);
  i = particao(vetor, esq+1, dir);
  quicksort_mediana_tres(vetor, esq, i-1);
  quicksort_mediana_tres(vetor, i+1, dir);
}

// PIVO part3
void quicksort_tres_partes(int a[], int l, int r){
  int k, i = l-1, j = r, p = l-1, q = r;
  int v = a[r];
  if(r <= l) return;
  for(;;){
    while(a[++i] < v);
    while(v < a[--j])
      if(j == l) break;
    if(i >= j) break;
    troca(a, i, j);
    if(a[i] == v) {p++; troca(a, p, i);}
    if(v == a[j]) {q--; troca(a, j, q);}
  }
  troca(a, i, r);
  j = i-1;
  i = i+1;
  for(k = l; k <= p; k++, j--) troca(a, k, j);
  for(k = r-1; k >= q; k--, i++) troca(a, i, k);
  quicksort_tres_partes(a, l, j);
  quicksort_tres_partes(a, i, r);
}


int main(void) {
  int vetor5k[5000], vetor50k[50000];
  clock_t inicio, fim;

  // ----------------------------------QUICK SORT NORMAL 5k------------------------------------
  geraAleatorio(vetor5k, 5000);
  inicio = clock();
  quicksort(vetor5k, 0, 4999);
  fim = clock();
  printf("\nQS valores aleatórios 5k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

  geraCrescente(vetor5k, 5000);
  inicio = clock();
  quicksort(vetor5k, 0, 4999);
  fim = clock();
  printf("\nQS valores crescentes 5k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

  geraDecrescente(vetor5k, 5000);
  inicio = clock();
  quicksort(vetor5k, 0, 4999);
  fim = clock();
  printf("\nQS valores decrescentes 5k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

  geraRepticoes(vetor5k, 5000);
  inicio = clock();
  quicksort(vetor5k, 0, 4999);
  fim = clock();
  printf("\nQS valores repetidos 5k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

  //---------------------------QUICK SORT ALEATORIO 5k-----------------------------------------------
  geraAleatorio(vetor5k, 5000);
  inicio = clock();
  quicksort_aleatorizado(vetor5k, 0, 4999);
  fim = clock();
  printf("\nQS Aleatorio valores aleatórios 5k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

  geraCrescente(vetor5k, 5000);
  inicio = clock();
  quicksort_aleatorizado(vetor5k, 0, 4999);
  fim = clock();
  printf("\nQS Aleatorio valores crescentes 5k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

  geraDecrescente(vetor5k, 5000);
  inicio = clock();
  quicksort_aleatorizado(vetor5k, 0, 4999);
  fim = clock();
  printf("\nQS Aleatorio valores decrescentes 5k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

  geraRepticoes(vetor5k, 5000);
  inicio = clock();
  quicksort_aleatorizado(vetor5k, 0, 4999);
  fim = clock();
  printf("\nQS Aleatorio valores repetidos 5k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

  //---------------------------------QUICK SORT MEDIANA DE TRES 5k-----------------------------------
  geraAleatorio(vetor5k, 5000);
  inicio = clock();
  quicksort_mediana_tres(vetor5k, 0, 4999);
  fim = clock();
  printf("\nQS Mediana3 valores aleatórios 5k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

  geraCrescente(vetor5k, 5000);
  inicio = clock();
  quicksort_mediana_tres(vetor5k, 0, 4999);
  fim = clock();
  printf("\nQS Mediana3  valores crescentes 5k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

  geraDecrescente(vetor5k, 5000);
  inicio = clock();
  quicksort_mediana_tres(vetor5k, 0, 4999);
  fim = clock();
  printf("\nQS Mediana3  valores decrescentes 5k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

  geraRepticoes(vetor5k, 5000);
  inicio = clock();
  quicksort_mediana_tres(vetor5k, 0, 4999);
  fim = clock();
  printf("\nQS Mediana3  valores repetidos 5k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

  //---------------------------------QUICK SORT 3 vias 5k-----------------------------------
  geraAleatorio(vetor5k, 5000);
  inicio = clock();
  quicksort_tres_partes(vetor5k, 0, 4999);
  fim = clock();
  printf("\nQS 3 partes valores aleatórios 5k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

  geraCrescente(vetor5k, 5000);
  inicio = clock();
  quicksort_tres_partes(vetor5k, 0, 4999);
  fim = clock();
  printf("\nQS 3 partes valores crescentes 5k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

  geraDecrescente(vetor5k, 5000);
  inicio = clock();
  quicksort_tres_partes(vetor5k, 0, 4999);
  fim = clock();
  printf("\nQS 3 partes valores decrescentes 5k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

  geraRepticoes(vetor5k, 5000);
  inicio = clock();
  quicksort_tres_partes(vetor5k, 0, 4999);
  fim = clock();
  printf("\nQS 3 partes valores repetidos 5k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

   // ----------------------------------QUICK SORT NORMAL 50k------------------------------------
   geraAleatorio(vetor50k, 50000);
   inicio = clock();
   quicksort(vetor50k, 0, 49999);
   fim = clock();
   printf("\nQS valores aleatórios 50k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

   geraCrescente(vetor50k, 50000);
   inicio = clock();
   quicksort(vetor50k, 0, 49999);
   fim = clock();
   printf("\nQS valores crescentes 50k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

   geraDecrescente(vetor50k, 50000);
   inicio = clock();
   quicksort(vetor50k, 0, 49999);
   fim = clock();
   printf("\nQS valores decrescentes 50k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

   geraRepticoes(vetor50k, 50000);
   inicio = clock();
   quicksort(vetor50k, 0, 49999);
   fim = clock();
   printf("\nQS valores repetidos 50k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

   //---------------------------QUICK SORT ALEATORIO 50k-----------------------------------------------
   geraAleatorio(vetor50k, 50000);
   inicio = clock();
   quicksort_aleatorizado(vetor50k, 0, 49999);
   fim = clock();
   printf("\nQS Aleatorio valores aleatórios 50k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

   geraCrescente(vetor50k, 50000);
   inicio = clock();
   quicksort_aleatorizado(vetor50k, 0, 49999);
   fim = clock();
   printf("\nQS Aleatorio valores crescentes 50k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

   geraDecrescente(vetor50k, 50000);
   inicio = clock();
   quicksort_aleatorizado(vetor50k, 0, 49999);
   fim = clock();
   printf("\nQS Aleatorio valores decrescentes 50k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

   geraRepticoes(vetor50k, 50000);
   inicio = clock();
   quicksort_aleatorizado(vetor50k, 0, 49999);
   fim = clock();
   printf("\nQS Aleatorio valores repetidos 50k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

   //---------------------------------QUICK SORT MEDIANA DE TRES 50k-----------------------------------
   geraAleatorio(vetor50k, 50000);
   inicio = clock();
   quicksort_mediana_tres(vetor50k, 0, 49999);
   fim = clock();
   printf("\nQS Mediana3 valores aleatórios 50k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

   geraCrescente(vetor50k, 50000);
   inicio = clock();
   quicksort_mediana_tres(vetor50k, 0, 49999);
   fim = clock();
   printf("\nQS Mediana3  valores crescentes 50k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

   geraDecrescente(vetor50k, 50000);
   inicio = clock();
   quicksort_mediana_tres(vetor50k, 0, 49999);
   fim = clock();
   printf("\nQS Mediana3  valores decrescentes 50k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

   geraRepticoes(vetor50k, 50000);
   inicio = clock();
   quicksort_mediana_tres(vetor50k, 0, 49999);
   fim = clock();
   printf("\nQS Mediana3  valores repetidos 50k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

   //---------------------------------QUICK SORT 3 vias 50k-----------------------------------
   geraAleatorio(vetor50k, 50000);
   inicio = clock();
   quicksort_tres_partes(vetor50k, 0, 49999);
   fim = clock();
   printf("\nQS 3 partes valores aleatórios 50k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

   geraCrescente(vetor50k, 50000);
   inicio = clock();
   quicksort_tres_partes(vetor50k, 0, 49999);
   fim = clock();
   printf("\nQS 3 partes valores crescentes 50k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

   geraDecrescente(vetor50k, 50000);
   inicio = clock();
   quicksort_tres_partes(vetor50k, 0, 49999);
   fim = clock();
   printf("\nQS 3 partes valores decrescentes 50k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);

   geraRepticoes(vetor50k, 50000);
   inicio = clock();
   quicksort_tres_partes(vetor50k, 0, 49999);
   fim = clock();
   printf("\nQS 3 partes valores repetidos 50k: %f\n", (double)(fim - inicio)/CLOCKS_PER_SEC);
  
  return 0;
}
//Implementar os algoritmos: Quicksort básico, Quicksort aleatorizado, Quicksort com mediana de três, Quicksort com partição em três vias
//Criar quatro vetores (Sequência aleatória, Sequência ordenada, Sequência invertida, Sequência com muitas repetições) de números inteiros com tamanhos 5.000 e 50.000.
//Medir os tempos de execução para cada algoritmo e tipo/tamanho de vetor.
