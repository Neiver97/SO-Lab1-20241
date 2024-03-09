#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h> 

#define MAX_ARG 3
#define DEBUG 0
#define ERROR 1

void validarArchivosInvertidos(const char *nombreArch1,const char *nombreArch2){
    FILE *in = fopen(nombreArch1,"r");
    FILE *out = fopen(nombreArch2,"r");
    char *line = NULL;
    size_t len = 0;

    printf("Nombre Archivo 1: %s\n",nombreArch1 );

    if(getline(&line, &len, in)!=-1){
        printf("La información es: %s\n",line);
        printf("La cantidad de len es: %zu\n",len);
    }
    

}

int main(int argc, char *argv[]) {

    validarArchivosInvertidos(argv[1], argv[2]);


    return 0;
}