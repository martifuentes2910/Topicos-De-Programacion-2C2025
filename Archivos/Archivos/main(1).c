#include "Archivos.h"
/*Ejercicio 5.7
Se dispone de dos archivos binarios: <empleados> y <estudiantes>.
Cada registro del primer archivo contiene los campos:
<dni>, <apellido>, <nombre> y <sueldo>
en tanto que los del segundo:
<dni>, <apellido>, <nombre> y <promedio>.
Ambos archivos están ordenados alfabéticamente por <apellido> / <nombre> / <dni>.
Ambos archivos deben ser leídos sólo una vez, y no deben ser almacenados en arrays. El sueldo es
double y el promedio es float.
Escriba un programa que, leyendo ambos archivos, actualice el sueldo de aquellos empleados que
tengan un registro de estudiante con un promedio superior a 7, en un 7,28%.*/

/**Ejercicio 5.13
Se tiene un archivo de texto con los campos “legajo, dni, promedio, edad, genero”, todos los campos
son numéricos y no hay blancos entre ellos. La primera línea indica el orden de los campos en el
archivo de texto y este puede cambiar entre distintos archivos, todas las combinaciones son posibles.
Ej:
Desarrolle una función que genere un archivo binario de registros de la estructura tAlumno que se
muestra al pie a partir de cualquier orden de campos en los archivos de texto. Utilice todas las
técnicas aprendidas hasta la fecha para evitar poner una condición para cada orden de campos
posible, recuerde que la cantidad de combinaciones es el factorial de la cantidad de campos,
volviendo inconveniente esta estrategia
28
Tenga presente que debe usar punteros a función para la resolución del ejercicio.
**/
int main()
{
    char femps[] = "Empleados.dat";
    char ftxtLV[] = "DatosLV.txt";
    char ftxtLF[] = "DatosLF.txt";
    // char fests[] = "Estudiantes.dat";
//    tEmpleado emps[]= {{10,"Juan Perez", 100},
//        {30, "Maria Benitez", 200},
//        {35, "Emilio Garcia", 100},
//        {37, "Florencia Massa", 300},
//        {50, "Flavio Gomez", 200},
//        {70, "Julieta Beltran", 200},
//        {80, "Mariana Gauna", 150},
//        {100, "Lorena Babuin", 150}
//    };
    //  int ce=8;
    crearArchivoEmp(femps);
    ///leerYmostrarArchivo(femps);
    ///crearArchivoDeTextoLV(femps,ftxtLV);
    /// crearArchivoDeTextoLF(femps,ftxtLF);
    FILE *pf;
    tEmpleado d;
    char linea[61];
    int nroRegistrosArchivo;
//    leerYmostrarArchivo(femps);
//    if(!abrirArchivo(&pf,femps,"r+b",1))
//        exit(1);
    if(!abrirArchivo(&pf,ftxtLV,"rt",1))
        exit(1);
    //printf("%d\n",(int)sizeof(tEmpleado));
    fgets(linea,sizeof(tEmpleado),pf);
    trozarCamposLongitudVariable(&d,linea);
    printf("%ld %s %c  %d/%d/%d %.2f\n", d.dni,
           d.apyn,
           d.categoria,
           d.fecIngreso.dia,
           d.fecIngreso.mes,
           d.fecIngreso.anio,
           d.sueldo);
//    actualizarPorcentajeSueldo(pf, 1.25,&nroRegistrosArchivo);    ///NRO DE REG INDICA LA CANTIDAD DE REG Q FUERON ACTUALIZADOS, NADA MAS
//    printf("Cant reg act: %d\n",nroRegistrosArchivo);
//    leerYmostrarArchivo(femps);

//    if(!crearArchivo(femps,emps,sizeof(tEmpleado),sizeof(emps)))
//    {
//        puts("no se pudo crear");
//    }

//    if(!recorrerArch(femps,sizeof(tEmpleado),mostrarEmpleado))
//    {
//        puts("No se pudo recorrer");
//    }
    return 0;
}
