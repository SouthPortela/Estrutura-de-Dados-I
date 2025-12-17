#include <stdio.h>
#include <string.h>

#define MAX_SITES 3
#define MAX_URL 50

typedef struct{
  char urls[MAX_SITES][MAX_URL];
  int topo;
} PilhaHistorico;

void inicializar(PilhaHistorico *p){
  p->topo = -1;
}

void acessar(PilhaHistorico *p, char *site){
  if(p->topo == MAX_SITES - 1){
    printf("Historico cheio!\n");
    return;
  }
  p->topo++;

  strcpy(p->urls[p->topo], site);

  printf("Acessou: %s (Valor do topo: %d)\n", site, p->topo);
}

