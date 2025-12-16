#include <stdio.h>
#include <string.h>
#define TAM 100


typedef struct{
  int id;
  char nome[TAM];
  float valor;
}Item;

void modificarValor(Item *p, float novoValor){
  p->valor = novoValor;
}

int main(){
  Item carro;
  carro.id = 1;
  strcpy(carro.nome, "Maserati");
  carro.valor = 850000;
  float valorMod = 900000;
  printf("ID: %d\n", carro.id);
  printf("Carro: %s\n", carro.nome);
  printf("Valor inicial: %.2f\n\n", carro.valor);
  modificarValor(&carro, valorMod);
  printf("Valor Modificado: %.2f", carro.valor);
  return 0;
}


