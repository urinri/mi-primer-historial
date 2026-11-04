/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int cantidadpilotos, pilotorapido, pilotomenor=0, promediomenor=0;
    int destacado=0, amejorar=0, competitivo=0, opcion=0, sesion=0, totalvueltas=0;
    float vuelta1[100], vuelta2[100], vuelta3[100];
    float promedio[100], tiempototal[100];
    float segundos, sumapromedios=0, promediogeneral=0, sumatiempos=0, vueltarapida=0;
    
    while(opcion!=3){
    printf("1. Registrar una sesión de entrenamiento\n");
    printf("2. Consultar el resumen de la última sesión\n");
    printf("3. Salir\n");
    printf("Selecciona la opción que deseas seleccionar: ");
    scanf("%d", &opcion);
    
    switch(opcion){
    case 1: 
    printf("Ingresa la cantidad de pilotos:");
    scanf("%d", &cantidadpilotos);
    if(cantidadpilotos<1 || cantidadpilotos>100){
        printf("No es una cantidad valida de pilotos.");
        } else {
        for(int i=1; i<=cantidadpilotos; i++){
        printf("Ingresa el tiempo de la vuelta 1 en S para el piloto P0%d:", i);
        scanf("%f", &vuelta1[i]);
        printf("Ingresa el tiempo de la vuelta 2 en S para el piloto P0%d:", i);
        scanf("%f", &vuelta2[i]);
        printf("Ingresa el tiempo de la vuelta 3 en S para el piloto P0%d:", i);
        scanf("%f", &vuelta3[i]);
        sumatiempos=vuelta1[i]+vuelta2[i]+vuelta3[i];
        totalvueltas+=3;
        tiempototal[i] = vuelta1[i] + vuelta2[i] + vuelta3[i];
        printf("Su tiempo total es %.2f \n", tiempototal[i]);
        promedio[i]=tiempototal[i]/3;
        printf("El promedio por cada vuelta es de: %.2f \n", promedio[i]);
        sumapromedios+=promedio[i];
        if(promedio[i]<=60){
        printf("El resultado del piloto P0%d es: Destacado\n", i);
        destacado++;
        } else if(promedio[i]>=60 && promedio[i]<=75){
            printf("El resultado del piloto es P0%d: Competitivo\n", i);
            competitivo++;
        } else{
            printf("El resultado del pilo P0%d o es: En mejora\n", i);
            amejorar++;
        }
        if(i==1 || vuelta1[i]<vuelta2[i] && vuelta1[i]<vuelta3[i]) {
            printf("La vuelta más rápida del piloto P%d fue la 1ra, con %.1fs\n", i, vuelta1[i]);
            pilotorapido=i;
            vueltarapida=vuelta1[i];
        } else if (i==1 || vuelta2[i]<vuelta1[i] && vuelta2[i]<vuelta3[i]){
            printf("La vuelta mas rapida del piloto P%d fue la 2da, con %.1fs\n", i, vuelta2[i]);
            pilotorapido=i;
            vueltarapida=vuelta2[i];
        } else{
            printf("La vuelta mas rapida del piloto P%d fue la 3ra, con %.1fs\n", i, vuelta3[i]);
            pilotorapido=i;
            vueltarapida=vuelta3[i];
        }
        if(i==1 || promedio[i]<promedio[pilotomenor]){
        pilotomenor=i; }
    } 
        }
        sesion=1;
        printf("Sesion registrada.\n");
        break;
        case 2:
        if (sesion!=0){
        printf("Resumen de la ultima información:\n");
        printf("Cantidad de pilotos participantes: %d\n", cantidadpilotos);
        promediogeneral=sumatiempos/totalvueltas;
        printf("Promedio general de los tiempos por vuelta: %.2f\n", promediogeneral);
        promediomenor = promedio[pilotomenor];
        printf("Número del piloto con menor tiempo promedio: %d y su resultado: %d \n", pilotomenor, promediomenor);
        printf("Vuelta más rápida de toda la sesión en s: %.2f \n", vueltarapida);
        printf("Número del piloto que la realizó: P0%d \n", pilotorapido);
        printf("Cantidad de pilotos destacados: %d \n", destacado);
        printf("Cantidad de pilotos competitivos: %d \n", competitivo);
        printf("Cantidad de pilotos en mejora: %d \n", amejorar);
        } else {
            printf("No se ha registrado aun el tiempo.\n");
        }
        break;
        case 3:
        printf("Programa finalizado.");
        break;
        default:
        printf("Esa no es una opción valida\n");
        break;
    }
}
    return 0;
}
