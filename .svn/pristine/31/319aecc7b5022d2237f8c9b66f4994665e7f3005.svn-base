#define _GNU_SOURCE // necessário porque getline() é extensão GNU
#include <stdio.h>
#include <stdlib.h>
int main()
{
  FILE *f= fopen("teste.txt", "r");
  size_t len= 100; // valor arbitrário
  char *linha= malloc(len);

if (!f)
  {
    perror("teste.txt");
    exit(1);
  }
  while (getline(&linha, &len, f) > 0)
  {
    printf("%s", linha);
  }
  if (linha)
    free(linha);
  fclose(f);
  return 0;
}