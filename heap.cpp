#include "heap.h" 
#include <cstddef>
#include <new>


Heap::Heap(int MAX_ITEMS) {
  this->MAX_ITEMS = MAX_ITEMS;
  cadastro  = new Account*[MAX_ITEMS];
  for (int i = 0; i < MAX_ITEMS; i++) {
    cadastro[i] = NULL;
  }
  length    = 0;
}

Heap::Heap(int MAX_ITEMS, Account* input, int size)
{
  this->MAX_ITEMS = MAX_ITEMS;
  cadastro  = new Account*[MAX_ITEMS];
  this->length  = size;


  int i;
  for (i = 0; i < size; ++i)
    {
      // Construtor de cópia
      cadastro[i] = new Account(input[i]);
    }
  
  for (i = length/2-1; i >= 0; --i)
    {
      descida(i, length-1);
    }
}


Heap::~Heap()
{
  for (int i = 0; i < length; i++) {
    delete cadastro[i];
  }
  delete [ ] cadastro;
}


Account Heap::dequeue()
{
  if (length == 0)
    return NULL;
  else {
    Account item = *cadastro[0];
    cadastro[0]  = cadastro[length-1];
    length--;
    descida(0, length-1);
    return item;
  } 
}


void Heap::enqueue(Account newItem)
{
  if (length == MAX_ITEMS)
    return;
  else {
    length++;
    cadastro[length-1] = new Account(newItem); // Construtor de cópia
    subida(length-1, 0);
  } 
}

bool Heap::isFull() const
{
  return length == MAX_ITEMS;
}

bool Heap::isEmpty() const
{
  return length == 0;
}

void Heap::descida(int index, int bottom)
{

}

void Heap::subida(int index, int root)
{

}

void Heap::print() const {
  std::cout << "INI" << std::endl;
  for (int i = 0; i < length; i++) {
    Account* acc = cadastro[i];    
    if (acc != NULL) { 
	std::cout << i << ":" << acc->getAccountNumber() <<", "  <<acc->getBalance() << std::endl;
      }
  }
  std::cout << "FIM" << std::endl;
}
