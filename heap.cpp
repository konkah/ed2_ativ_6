#include "heap.h" 
#include <cstddef>
#include <new>
#include <tgmath.h>

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
    if (index > bottom)
        return;

    int child1 = index * 2 + 1;
    int child2 = index * 2 + 2;

    int childToSwap;

    // Para descer um elemento, a verificação / troca
    // precisa ser feita com o filho de maior prioridade
    if (cadastro[child1]->getPriority() < cadastro[child2]->getPriority())
    {
        childToSwap = child2;
    }
    else
    {
        childToSwap = child1;
    }

    // Se o filho tem uma prioridade maior que o elemento,
    // isso viola a regra da HEAP, onde quem tem
    // mais prioridade precisa ficar no topo,
    // e eles têm que ser trocados
    if (cadastro[childToSwap]->getPriority() > cadastro[index]->getPriority())
    {
        Account* aux = cadastro[childToSwap];
        cadastro[childToSwap] = cadastro[index];
        cadastro[index] = aux;

        // Depois que descemos o elemento, precisamos
        // verificar se o pai dele precisa ser descido também
        // então seguimos recursivamente
        descida(childToSwap, bottom);
    }

}

void Heap::subida(int index, int root)
{
    int parent = (index - 1) / 2;

    if (parent < root)
        return;

    // Se o pai tem uma prioridade menor que o elemento,
    // isso viola a regra da HEAP, onde quem tem
    // mais prioridade precisa ficar no topo,
    // e eles têm que ser trocados
    if (cadastro[parent]->getPriority() < cadastro[index]->getPriority())
    {
        Account* aux = cadastro[parent];
        cadastro[parent] = cadastro[index];
        cadastro[index] = aux;

        // Depois que subimos o elemento, precisamos
        // verificar se o pai dele precisa ser subido também
        // então seguimos recursivamente
        subida(parent, root);
    }
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

void Heap::printTree() const {
    std::cout << std::endl;
    std::cout << std::endl;

	if (length == 0)
	{
        std::cout << "<Vazia>";
	}

	int lastOfLine = 2;
    int levels = log2(length);

	for (int i = 0; i < length; i++) {
        Account* acc = cadastro[i];

    	if (acc != NULL) {

    		int level = log2(i+1);
    		int spaces = pow(2, levels - level) - 1;

    		for(int l = 0; l < spaces; l++)
    		{
    			if (l < spaces/2)
    			{
                    std::cout << "              ";
    			}
    			else if (l > spaces / 2)
                {
                    std::cout << "--------------";
                }
                else
    			{
                    std::cout << "_______-------";
    			}
            }

            if (i < 10)
            {
                std::cout << "0";
            }

            std::cout << i << ":";

        	if (acc->getAccountNumber() < 10000)
        	{
                std::cout << "0";
        	}

            std::cout << acc->getAccountNumber() << ", " << acc->getBalance();

            if (acc->getBalance() < 1000)
            {
                std::cout << " ";

                if (acc->getBalance() < 100)
	            {
	                std::cout << " ";

	                if (acc->getBalance() < 10)
	                {
	                    std::cout << " ";
	                }
	            }
            }

            for (int l = 0; l < spaces; l++)
            {
                if (l < spaces / 2)
                {
                    std::cout << "--------------";
                }
                else if (l > spaces / 2)
                {
                    std::cout << "              ";
                }
                else
                {
                    std::cout << "-------_______";
                }
            }

        	if ((i + 1) == (lastOfLine - 1))
        	{
                std::cout << std::endl;
        		lastOfLine = lastOfLine * 2;
        	}
        	else
        	{
                std::cout << "              ";
            }
        }
    }

	if ((length + 1) == (lastOfLine - 1))
	{
        std::cout << std::endl;
	}

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}
