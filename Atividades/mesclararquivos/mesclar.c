#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFFER 4096

int main(int argc, char *argv[]){
  if(argc < 4){
    printf("Erro ao mesclar, informe arquivofinal.txt e mais dois ou mais arquivos");
    return 1;
  }
  
  FILE *saida = fopen(argv[1], "w");
  if(argv[1] == NULL){
    printf("Nao foi possivel abrir o arquivo");
    return 1;
  }

  char buffer[BUFFER];
  
  for(int i=2; i < argc;i++){
    FILE *atual = fopen(argv[i], "r");
    if(!atual) continue;

    int linha = 0;
    while(fgets(buffer, BUFFER, atual)){
      linha++;
      if(linha <= 2){
        continue;
      }

      if(strncmp(buffer, "EF", 2) == 0){
        continue;
      }
      fputs(buffer, saida);
    }
    fclose(atual);

  }
  fclose(saida);
  printf("todos os arquivos foram mesclados no arquivo %s", argv[1]);
  return 0;
}

