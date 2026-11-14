#include <stdio.h>
#include <iostream>

int main()
{
    int menu;
    int registro=0;
    float temperatura;

    
    while (menu!=4) {
    printf("1. Regitrar temperatura \n");
    printf("2. Evaluar temperatura \n");
    printf("3. Mostrar ultimo valor \n");
    printf("4. Salir \n");
    printf("Selecciona la informacion que deseas saber de la temperatura: ");
    scanf("%d", &menu);
    
    switch (menu){
        case 1: 
        printf("Ingresa la temperatura a grados C: ");
        scanf("%f", &temperatura);
        registro ++;
        break;
        case 2:
        if(registro==0){
            printf("Favor de registrar la temperatura\n\n");
            break;
           } else { 
                if(temperatura <18) {
            printf("La temperatura es baja \n\n");
            break;
            }  else if(temperatura <25) {
                printf("La temperatura es normal\n\n");
                break;
            } else{ 
                printf("La temperatura es alta\n\n");
                break;
            }   
        }
        case 3:
        if(registro!=0){
            printf("La ultima temperatura registrada es: %.1fC°\n\n", temperatura);
            break;
        } else {
            printf("Favor de registrar la temperatura\n\n");
            break;
        }
        break;
        case 4:
        printf("Programa finalizado\n\n");
        break;
        default:
        printf("Esa no es una opcion valida. \n\n")
        break;
    }
}
    return 0;
}