#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h> 

#define MAX_ARG 3
#define DEBUG 0
#define ERROR 1

bool archivoExiste(const char *nombreArchivo) {

    FILE *archivo = fopen(nombreArchivo, "r");

    if (archivo != NULL) {
        fclose(archivo);
        return true;
    } else {
        return false;
    }
}

void archivosNombreDiffArchivos(const char *nombreArch1,const char *nombreArch2){

    if ( strcmp(nombreArch1,nombreArch2)==0){
        fprintf(stderr,"reverse: input and output file must differ\n");
        exit(ERROR);
    }

}

void validarContenidoDiffArchivo(const char *nombreArch1,const char *nombreArch2){
    
    FILE *in = fopen(nombreArch1,"r");
    FILE *out = fopen(nombreArch2,"r");

    struct stat sb1, sb2;

    fstat(fileno(in), &sb1);
    fstat(fileno(out), &sb2);

    if (sb1.st_ino == sb2.st_ino){
        fprintf(stderr,"reverse: input and output file must differ\n");
        exit(ERROR);
    }

} 

void validarArchivosInvertidos(const char *nombreArch1,const char *nombreArch2){
    
    // Incompleto, falta seguir trabajando

    FILE *in = fopen(nombreArch1,"r");
    FILE *out = fopen(nombreArch2,"r");
    char *line = NULL;
    size_t len = 0;

    printf("Nombre Archivo 1: %s\n",nombreArch1 );

    /*if(getline(&line, &len, in)!=-1){
        printf("La información es: %s",line);
    }*/
    

}

void validarCantidadArgumentos(int argc, char *argv[]) {
    if (argc > MAX_ARG) {
        fprintf(stderr, "usage: reverse <input> <output>\n");
        exit(ERROR);
    }
}

void validarExistenciaArchivo(int argc, char *argv[]){

    const char *nombreArchivoEntrada = argv[1]; 
    
    if (!archivoExiste(nombreArchivoEntrada)) {
        fprintf(stderr, "reverse: cannot open file '/no/such/file.txt'\n");
        exit(ERROR);
    }
}

int main(int argc, char *argv[]) {

    validarCantidadArgumentos(argc, argv);
    validarExistenciaArchivo(argc, argv);
    archivosNombreDiffArchivos(argv[1], argv[2]);
    validarContenidoDiffArchivo(argv[1], argv[2]);
    validarArchivosInvertidos(argv[1], argv[2]);


    return 0;
}