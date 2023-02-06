/* Autor: Eduardo
 * Arquivo para conversao de Log MK para padrão do squid
 * Data: 18/04/13
  */
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

main(int argc, char *argv[]){
    int tamstring;
    int j;
    int i;
    int inicio=56;
    FILE *arquivo, *saida;
    char *linha;
    char stringtratada[300];
    size_t len= 300;
    char stringanterior[300] = "";
    if(argc <= 2)
      {
        printf("\nErro: Sintaxe Incorreta !!!\n Exemplo: mk2sarg /var/logdomk /var/log/squid/access.log\n By Eduardo Doria\n");
        exit(1);
      }


    if((arquivo = fopen(argv[1],"r")) == NULL)
      {
        printf("Erro ao abrir arquivo!!!\n\n");
        exit(1);
      };
	saida = fopen(argv[2],"w");
    while(!feof(arquivo)) 
      {
        getline(&linha,&len,arquivo);
        tamstring = strlen(linha);
	i=0;

	while (i<tamstring)
	{	
		stringtratada[i] = linha[i+inicio];
	        stringtratada[i+1] = '\0';
		i++;
	}
	//char *pos = strchr(stringtratada, '.');
	//char *pos2 = strchr(stringtratada, ' ');
	//printf ('%s',*pos);
	if (!feof(arquivo) && stringtratada[10] == '.' &&  stringtratada[14] == ' ')
		fprintf(saida,"%s",stringtratada);
	
      }
    fclose(arquivo);

    return(0);
}
