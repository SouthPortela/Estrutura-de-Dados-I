#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFFER 4096

int main(int argc, char *argv[]){
  if(argc < 3){
    printf("Erro ao mesclar, informe arquivofinal.txt e mais dois ou mais arquivos");
    return 1;
  }
  
  FILE *saida = fopen(argv[1], "w");
  if(argv[1] == NULL){
    printf("Nao foi possivel abrir o arquivo");
    return 1;
  }
  
  char buffer[BUFFER];
  size_t bytes_lidos;

  for(int i = 2; i < argc; i++){
    FILE *arquivo_atual = fopen(argv[i], "r");
    if(argv[i] ==NULL){
      printf("Erro, nao abriu a caralha do arquivo");
      return 1;
    }

    while((bytes_lidos = fread(buffer, 1, sizeof(buffer), arquivo_atual)) > 0){
      fwrite(buffer, 1, bytes_lidos, saida);
    }
    fclose(arquivo_atual);
  }
  fclose(saida);
  printf("todos os arquivos foram mesclados no arquivo %s", argv[1]);
  return 0;
}

