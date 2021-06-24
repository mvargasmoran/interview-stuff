#include <stdio.h>      //bibliotecas principales
#include <windows.h>
#include <string.h>
#include <stdlib.h>
int main()
{
      int opcion1,edad[100],k=1;
      float altura[100],peso[100];
      char nombres[3][100];
      int cont=0;		
	  int resp,resp2;								// cuenta de ingresados
      int i=1,x,y;                                     // para recorrer los vectores
      int z,r;	
      char comparacion[100];
      int rutina[100][4];
      menu1:
       while (i==1) 
		{
         	printf("---------------------------------\n---                           ---\n---         GYM UNAP          ---\n---                           ---\n---------------------------------\n");  //Menu Principal
            printf("\n\n");
         	printf("\n\n");
         	printf("---------------------------------\n");
         	printf("--- [1] Menu Personas         ---\n");
         	printf("--- [2] Menu Rutinas          ---\n");
         	printf("--- [3] Menu Estadisticas     ---\n");
         	printf("--- [0] Salir                 ---\n");
         	printf("---     Ingrese su opcion     ---\n");
         	printf("---------------------------------\n\n\n");
         	scanf("%d",&k);                                 //guardamos la opcion para derivar a otro menu
         	printf("\n\n");
         	switch (k) {
         		case 1:
         			x=1;
         			
         			while (x==1){
         				printf("---------------------------------\n---------Menu Personas-----------\n---------------------------------\n--- [1] Ingresar Persona      ---\n--- [2] Mostrar Datos         ---\n");
         				printf("--- [0] Regresar              ---\n---     Ingrese su opcion     ---\n---------------------------------\n\n\n");
         				scanf("%d",&z);
         				printf("\n\n");
         				
         				
						   switch (z){
         					case 1:
         						resp=1;
         						while (resp==1)
								 {
         								  printf("--------------------------------\n");                                                                               
                                          printf("--- Ingrese el nombre:       ---\n");
                                          fflush(stdin);
                                          gets(nombres[i]);
                                          printf("--- Ahora ingrese la edad:   ---\n");
                                          scanf("%d",&edad[i]);
                                          printf("--- Ahora ingrese el peso:   ---\n");
                                          scanf("%f",&peso[i]);
                                          printf("--- Ahora ingrese la altura: ---\n");
                                          scanf("%f",&altura[i]);
                                          printf("--------------------------------\n");
                                          printf("\n");
                                          printf("Agregar a alguien mas? \n\n");
                                          printf("[1] Si\n");
                                          printf("[2] No\n");
                                          printf("\n\n");
                                          scanf("%d",&resp);
                                          i++;
                                          cont++;
                                          
                                 }
                                 
                                 break;
                                 
                            case 2:
                            	printf("  Nombre		Edad	Peso	Altura\n");
                            	printf("  ---------------------------------------------\n\n");
                            	for (i=1;i<=cont;i++)
								{
                            		printf("%d)  %s	%d	%.2f	%.2f\n",i,nombres[i],edad[i],peso[i],altura[i]);                        	
                            	}
                            	printf("\n\n");
                            	break;
                            case 0:
                                x=0;
                                goto menu1;
                            	break;
						}
                    
                    
                       
         				}
         		
         		case 2:
				   y=1;
				   while (y==1)
				   {
				   		printf("--------------------------------------------\n");
        				printf("--------------Menu Rutinas------------------\n");
                    	printf("--------------------------------------------\n");
						printf("--- [1] Ingresar Rutina de una persona   ---\n");
                    	printf("--- [2] Comparacion rutina secion        ---\n");
                    	printf("--- [3] Todos los datos de la secion     ---\n");
            			printf("--- [0] Regresar                         ---\n");
                    	printf("---        Ingrese su opcion             ---\n");
                    	printf("--------------------------------------------\n\n\n");
                    	scanf("%d",&r);	
						switch (r){
							resp2=1;
							
							case 1:
								printf("-----------Ingresar la rutina-----------\n");
								printf("Ingrese su nombre:");
								fflush(stdin);
								gets(comparacion);
								for (i=0;i<cont;i++)
								{
									if (strcmp(comparacion,nombres[i])==0)
									{
										printf("Ingrese kilometros:");
										scanf("%f",rutina[i][0]);
										printf("Ingrese abdominales:");
										scanf("%f",rutina[i][1]);
										printf("Ingrese flexiones de brazos:");
										scanf("%f",rutina[i][2]);
										printf("Ingrese sentadillas:");
										scanf("%f",rutina[i][3]);										
									}
								}
						}
				   }
				    
                    
				 		
         			}
         		break;	
         	}
         	
		}



