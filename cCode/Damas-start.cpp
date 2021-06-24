#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
//#include <windows.h>
#include <unistd.h>

#define ROW 8
#define COL 8
#define PLAYER1 1
#define PLAYER2 2
#define BLACK 176 // puede ser 0 para que sea completamente negro
#define WHITE 219 // puede ser 177 o 178 o 219, para el blanco
int matrix[ROW][COL];

int salir(){
	return 0;
}

void checkColor(int i,int j){
	if( i%2 == 0 ) {
		if(j%2 != 0){
			matrix[i][j] = BLACK;
		}else{
			matrix[i][j] = WHITE;
		}
	} else {
		if( j%2 == 0){
			matrix[i][j] = BLACK;
		}else {
			matrix[i][j] = WHITE;
		}
	}
}

int getColor(int i,int j){
	if( i%2 == 0 ) {
		if(j%2 != 0){
			return BLACK;
		}else{
			return WHITE;
		}
	} else {
		if( j%2 == 0){
			return BLACK;
		}else {
			return WHITE;
		}
	}
}

void llenarTablero(){
	int i, j;

    for(i = 0; i < ROW; i++){
        for(j = 0; j < COL; j++){
			matrix[i][j] = getColor(i,j);
        }
        printf("\n");
    }
}

void imprimirTablero(){
	int i, j;

	printf("\t  %c Player%d %c   \n\n", PLAYER1, PLAYER1, PLAYER1);

    for(i = 0; i < ROW; i++){
    	printf("\t");
        for(j = 0; j < COL; j++){
            printf("%c%c", matrix[i][j], matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n\t  %c Player%d %c   \n", PLAYER2, PLAYER2, PLAYER2);
}

void imprimirInstrucciones(){
	printf("\n---------------------------------------\n");
	printf("#### INSTRUCCIONES MISTICAS ####");
	printf("\n");
	printf(" [1] %c \n [2] %c \n [3] (re)iniciar \n [0] salir \t", PLAYER1, PLAYER2);
	printf("\n");
	printf("#### INSTRUCCIONES MISTICAS ####");
	printf("\n---------------------------------------\n");
}

void iniciarTablero(){
	//Colocar las piezas de los jugadores donde corresponda
	int i,j;
	llenarTablero();

	//PLAYER1
	for(i = 0; i < 3; i++){ //solo hasta la fila 3
        for(j = 0; j < COL; j++){
        	if(getColor(i,j) == WHITE ){
        		matrix[i][j] = WHITE;
        	} else {
        		matrix[i][j] = PLAYER1;
        	}
        }
    }

	//PLAYER2
	for(i = 5; i < ROW; i++){ //empiezo en la fila 5
    	for(j = 0; j < COL; j++){
        	if(getColor(i,j) == WHITE ){
        		matrix[i][j] = WHITE;
        	} else {
        		matrix[i][j] = PLAYER2;
        	}
        }
    }
}

void moverJ1(){
//	//recojer movimiento del jugador 1 y colocar la pieza donde corresponda
//	printf("\n Ingrese X... );
//	scanf("%d", &posx);
//	printf("\n Ingrese Y... );
//	scanf("%d", &posy);
//	int coordinates[2];
//	coordinates[0] = posx;
//	coordinates[1] = posy;
//	return coordinates;
}

void moverJ2(){
	//recojer movimiento del jugador 1 y colocar la pieza donde corresponda

}

int esLegal(int prevposx, int prevposy, int posx, int posy){
	//revisar si el movimiento es hacia adelante
	//if(){
//	}
	//revisar si el movimiento es hacia un espacio valido (color negro)
	if(matrix[posx][posy] == BLACK){
		// OK
	}
	//revisar si el movimiento no esta obstruido por otra pieza
	if(matrix[posx][posy] != PLAYER1 || matrix[posx][posy] != PLAYER2){
	}
	//revisar si el movimiento no esta fuera del tablero
	if(posx < ROW && posx >= 0 && posy < ROW && posy >= 0){
	}
	return 0;
}
int main(int argc, char *argv[]){
    int i, j;
    int option; // opcion del menu
    int currentPlayer = 1; // marca cual es el jugador actual
    int posx, posy; // coordenadas en el tablero
    posx = 0; // inicializo en 0
    posy = 0;

    int auxposx, auxposy; // coordenadas en el tablero
    posx = 0; // inicializo en 0
    posy = 0;

    printf("Bienvenido...\n");
	llenarTablero();
	imprimirTablero();
	imprimirInstrucciones();

	scanf("%d", &option); //esperamos que usuario ingrese un valor para la opcion
	while(option != 0){
		if(option == 3){

			printf("(re)iniciando tablero...\n");
			iniciarTablero();

			//siempre terminar imprimiendo el tablero
			system("cls");
			printf("Redibujando...\n");
			usleep(1000);
			system("cls");
			imprimirTablero();
			imprimirInstrucciones();
			scanf("%d", &option);
		}
		if(option == 1){ // si ingresa uno muevo piezas para el jugador 1
			moverJ1();
			int piezaLegal = 0; // 0 significa falso
			//#### Mover piezas ####

			//recojo coordenadas de la pieza
			while(piezaLegal == 0){
				printf("\nIngrese coordenada X de la pieza que desea mover: ");
				scanf("%d", &auxposx);
				printf("\nIngrese coordenada Y de la pieza que desea mover: ");
				scanf("%d", &auxposy);
				//verificar que existe ficha en la posicion
				if(matrix[auxposx][auxposy] == 1){ // verifico si la coordenada corresponde a una pieza del jugador 1
					printf("\nPieza Legal");
					matrix[auxposx][auxposy] = 15;
					piezaLegal = 1;
				} else {
					printf("\nPieza iLegal...\nIntentelo de nuevo");
				}
				system("cls");
				printf("Redibujando...\n");
				usleep(1000);
				system("cls");
				imprimirTablero();
				imprimirInstrucciones();
			}
			//Ya teniendo coordenadas correctas de una pieza del jugador 1
			//puedo mover la ficha
			printf("\n¿Donde quiere mover la pieza?");
			int legal = 0;
			while(legal == 0){
				printf("\nIngrese coordenada X: ");
				scanf("%d", &posx);
				printf("\nIngrese coordenada Y: ");
				scanf("%d", &posy);
				//verificar que existe ficha en la posicion
				//if(matrix[posx][posy] == 1){
				if(esLegal(auxposy, auxposy, posx, posy) == 1){
					printf("\nMovimiento Legal");
					legal = 1;
				} else {
					legal = 0;
					printf("\nMovimiento iLegal...\nIntentelo de nuevo");
				}
			}
			//si todo es legal...
			//borro la pieza de su posicion inicial
			matrix[auxposx][auxposy] = getColor(auxposx, auxposy);

			//coloco la pieza en su nueva posicion
			matrix[posx][posy] = PLAYER1;

			//siempre terminar imprimiendo el tablero
			system("cls");
			printf("Redibujando...\n");
			usleep(1000);
			system("cls");
			imprimirTablero();
			imprimirInstrucciones();
			scanf("%d", &option);
			//////////////////////////////////////////
		}
		if(option == 2){ // si ingresa uno muevo piezas para el jugador 1
			moverJ2();
			//siempre terminar imprimiendo el tablero
			system("cls");
			printf("Redibujando...\n");
			usleep(1000);
			system("cls");
			imprimirTablero();
			imprimirInstrucciones();
			scanf("%d", &option);
		}
		if(option == 0){
			salir();
		}
	}

    return 0;
}



