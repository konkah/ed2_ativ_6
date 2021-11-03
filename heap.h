#ifndef HEAP_H
#define HEAP_H


#include <iostream>
#include <string>
#include "account.h"

/*
  Esta classe cria uma fila de prioridade, que é uma estrutura
  logicamente vista como uma árvore, mas que internamente
  implementamos como um array. Os elementos armazenados nesta fila de
  prioridade são objetos da classe account.
 */
class Heap
{ 
 public:
  /* 
    Este primeiro construtor recebe o numero máximo de elementos que a
    heap poderá receber e inicializa uma heap vazia.
  */
  Heap(int MAX_ITEMS = 10); 

  /*
    Este segundo construtor também recebe o número máximo de elementos
    que a Heap pode receber. Entretanto, ao invés de inicializar
    vazia, a Heap recebe também um número inicial de elementos.
    
    O primeiro parâmetro é o número máximo de elementos, o segundo
    parâmetro é um array de Account e o terceiro parâmetro é o número
    de elementos preenchido no array de Account.

    Você deve implementar este método de forma eficiente, sua nota
    depende disso, comece pelo último elemento não folha e itere até a
    raiz.
   */

  Heap(int MAX_ITEMS, Account* ARRAY_ACCOUNT, int NUM_IN_ARRAY_ACCOUNT);

  /*
    Este é um destrutor, você deverá usá-lo para apagar todos os
    elementos da Heap antes de apagar a própria Heap.
   */
  ~Heap();

  /*
    Alguns métodos auxiliares. Os nomes dos métodos são
    auto-explicativos.
   */
  bool isEmpty() const;
  bool isFull()  const;
  void print()   const;

  /*
    Alguns métodos para empilhar e desempilhar elementos da heap.
   */
  void enqueue(Account newItem);
  Account dequeue();

  
 private:
  /* Número máximo de elementos que podem ser alocados na nossa
     Heap.  */
  int MAX_ITEMS;
  /* Armazena o quanto do nosso array interno está realmente
   preenchido.  */
  int length;
  /* Array onde os elementos que estão na Heap serão colocados. */ 
  Account** cadastro; 

  /*
    Operações de subida e descida vistas em sala de aula. O parâmetro
    index é o índice do elemento que será movido. Em descida, este
    elemento não pode passar do índice de bottom e em subida este
    elemento não pode passar do índice de root.
   */
  void descida(int index, int bottom);
  void subida(int root,   int index);  
};

#endif
