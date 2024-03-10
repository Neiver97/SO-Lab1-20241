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
//    validarCantidadArgumentos(argc, argv);
  //  validarExistenciaArchivo(argc, argv);
    //validarArchivosDiferentes(argv);

    FILE *archivo1, *archivo2;
    char *linea1 = NULL, *linea2 = NULL;
    size_t longitud1 = 0, longitud2 = 0;
    ssize_t bytes_leidos1, bytes_leidos2;
    int contador1 = 0, contador2 = 0;


//------------- RECORDAR QUE SON 3 FORMAS DE EJECUCION, ESTA ES ASUMIENDO QUE SE INGRESAN LOS DOS .TXT----------
    archivo1 = fopen(argv[1], "r");
    // Me aseguro que el archivo esté limpio
    archivo2 = fopen(argv[2], "w+");
    // Cierro y abro en modo agregación
    fclose(archivo2);
    archivo2 = fopen(argv[2], "a+");

    if (archivo1 == NULL) {
        printf(stderr, "Error al abrir el archivo");
        return 1;
    }
    // Leer línea por línea de ambos archivos
    //while (((bytes_leidos1 = getline(&linea1, &longitud1, archivo1)) != -1) && ((bytes_leidos2 = getline(&linea2, &longitud2, archivo2)) != -1)) {
      //  contador1++; // Incrementar contador del archivo 1
        //contador2++; // Incrementar contador del archivo 2
    //}

     // Mover el puntero de archivo al final del archivo
    long posicion, posicion_inicial;
    fseek(archivo1, 0, SEEK_END);
    posicion = ftell(archivo1);

    // Bucle para recorrer el archivo línea por línea
    //posicion >= 0
    //------------- TO DO EN VEZ DE i, PONER CANTIDAD DE LINEAS CALCULADAS--------
    bool bandera = true;
    do
     {
        char c;
        // Retroceder la posición del puntero en el archivo
        fseek(archivo1, --posicion, SEEK_SET);
        c = fgetc(archivo1);

        if (c == '\n' || posicion == 0) { // Si encontramos un salto de línea
            if(posicion == 0){
                rewind(archivo1);
            }
            getline(&linea1, &longitud1, archivo1); // Leemos la línea utilizando getline
            // Impresión en en archivo out.txt
            if(bandera){
                fprintf(archivo2, "%s\n", linea1);
                printf("Línea leída: %s\n", linea1);
                bandera = false;
            }else
                fprintf(archivo2, "%s", linea1);
                printf("Línea leída: %s", linea1);
            }
     } while (posicion != 0);
     //Borra ultimo salto de línea escrito
    fseek(archivo2, -1, SEEK_CUR);
    ftruncate(fileno(archivo2), ftell(archivo2));
    fseek(archivo2, -1, SEEK_CUR);
    ftruncate(fileno(archivo2), ftell(archivo2));

// Mostrar el número de líneas contadas en cada archivo
   // printf("El archivo1 tiene %d lineas.\n", contador1);
    //printf("El archivo2 tiene %d lineas.\n", contador2);

    // Liberar la memoria asignada a las líneas
    free(linea1);
    free(linea2);

    // Cerrar los archivos
    fclose(archivo1);
    fclose(archivo2);


    return 0;
}
