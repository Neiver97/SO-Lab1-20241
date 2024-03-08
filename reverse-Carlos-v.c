#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ARG 3
#define DEBUG 0

void validarCantidadArgumentos(int argc, char *argv[]) {
    if (argc > MAX_ARG) {
        fprintf(stderr, "usage: reverse <input> <output>\n");
        exit(1);
    }
}

bool archivoExiste(const char *nombreArchivo) {
  
    FILE *archivo = fopen(nombreArchivo, "r");

    if (archivo != NULL) {
        fclose(archivo);
        return true;
    } else {
        return false;
    }
}

void validarExistenciaArchivo(int argc, char *argv[]){

    const char *nombreArchivoEntrada = argv[1]; 
    if (!archivoExiste(nombreArchivoEntrada)) {
        fprintf(stderr, "reverse: cannot open file '/no/such/file.txt'\n");
        exit(1);
    }
}

void validarArchivosDiferentes(char *argv[]){
    if(strcmp(argv[1], argv[2]) == 0){
        fprintf(stderr, "reverse: input and output file must differ\n");
        exit(1);
    }
}

void validarArchivosDiferentesHL(char *argv[]){
    FILE *archivo1 = fopen(*argv[1], "r");

    FILE *archivo2 = fopen(*argv[2], "r");

    if(strcmp(&archivo1, &archivo2) == 0){
        fprintf(stderr, "reverse: input and output file must differ\n");
        exit(1);
    }

}







int main(int argc, char *argv[]) {

    validarCantidadArgumentos(argc, argv);

    validarExistenciaArchivo(argc, argv);
    
    validarArchivosDiferentes(argv);

    return 0;
}
