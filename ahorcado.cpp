#include "Owntools.h"

//DECLARACION DE FUNCIONES
void uploadWord(char word[],char player, int &letras);
void start();
void game(int &puntaje, char jugador, int num, char palabra[]);
bool verificar(char letra, int n, char aux[], char palabra[], int &aciertos);
void rellenar(char aux[], int num);
void vaciar(char palabra[]);
void cuerpo(int numParte);
bool agrLetra(char listLetras[], char letra, int intentos, int &cantIntegradas);
void mostrarLetras(char letras[], int cantIntegradas);
void mostrarPalabra(char palabra[]);

//Variables Globales
int cantLetrasP[1], puntaje[1];

main(){
	system("mode 120, 35");
	bool Opcion=true;
	char Jugar;
	while(Opcion==true){
		start();
		printf("\n\n\tQuieres volver a jugar?(S/N): ");
		scanf("%s", &Jugar);
		Jugar=toupper(Jugar);
			if(Jugar=='N'){
				Opcion=false;
				printf("\nSaliendo del juego......\n");
				printf("\nAdios....\n");
			}else{
				Opcion=true;
				system("cls");
			}
	}
}

//	pantalla de inicio

void start(){
	char word1[20], word2[20];
	
	vaciar(word1);
	vaciar(word2);
	TituloAH();
	uploadWord(word2, 'B', cantLetrasP[1]);
	game(puntaje[0], 'A' , cantLetrasP[1], word2);
	TituloAH();
	uploadWord(word1, 'A', cantLetrasP[0]);
	game(puntaje[1], 'B' , cantLetrasP[0], word1);
	TituloAH();
	textcolor(YELLOW);
		if(puntaje[0]>puntaje[1]){
			printf("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\t\t\t\t\tEl ganador es el JUGADOR A.\n\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
		}
			if(puntaje[0]<puntaje[1]){
				printf("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\t\t\t\t\tEl ganador es el JUGADOR B.\n\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
			}
				if(puntaje[0]==puntaje[1]){
					printf("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\t\t\t\t\t\tFUE EMPATE.\t\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
				}
	textcolor(WHITE);
}

//	limpia la variable

void vaciar(char palabra[]){
	for(int i=0; i<23; i++){
		palabra[i]=' ';
	}
}

//	Carga de palabra

void uploadWord(char word[],char player, int &letras){
	letras=0;
	vaciar(word);
	printf("\tIngresa la palabra el jugador %c para el oponente, letra por letra (despues de cada letra presione ENTER).\n\t(Ingresar '0' para terminar de agregar letras) \n", player);
	printf("\t%c%c%c Palabras recomendadas: \n\n", 205, 205,185);
	textcolor(YELLOW);
	textbackground(RED);
	printf("\t\t\t1. Compilador\t2. Entorno\t3. Computadora\t4. Estructura\t\n\t\t\t5. Seleccion\t6. Repeticion\t7. Directiva\t8. Algoritmo\t\n\t\t\t9. Program\t10.Ejecucion\t11.Int\t\t12.Float\t\n\t\t\t13.Char\t\t14.Double\t15.Long\t\t16.If\t\t\n\t\t\t17.Else\t\t18.For\t\t19.While\t20.Return\t\n\t\t\t21.Break\t22.Switch\t23.Case\t\t24.Main\t\t\n\t\t\t25.Include\t26.Define\t27.Struct\t28.Cin\t\t\n");
	textcolor(WHITE);
	textbackground(BLACK);
		for(int i=0; i<20 ; i++){
			printf("\n\t%d� = ", i+1);
			scanf("%s", &word[i]);
				if(isalpha(word[i])){
					letras++;
				}
				else{
						if(isalnum(word[i])){
							i=20;
							word[i]=' ';
						}
						else{
							printf("\n\tSi desea terminar el valor debe ser '0'.");
						}
				}
		}
	strupr(word);
	system("cls");
}

//	CUERPO DEL JUEGO

void game(int &puntaje, char jugador, int num, char palabra[]){
	char letraInput;
	int contJugadas=1, contCuerpo=0, i=0;
	bool valorResp;
	bool partida=true;
	int aciertos=0;
	char aux[num];
	int cantLetras=0;
	char letras[contJugadas];

	rellenar(aux, num);
	while( i<11 and aciertos!=num){
		TituloAH();
		printf("\n\t\t\t----> INICIO <----");
		printf("\n\t\t\tTURNO DEL JUGADOR %c\n", jugador);
		strupr(aux);
		printf("\n\n\t��������������JUGADA #%d��������������\t\n", contJugadas);
		cout<<"\n\tLetras ya ingresadas: ";textcolor(YELLOW);
		mostrarLetras(letras, cantLetras);
		textcolor(WHITE);
		cout<<"\n\tPalabra que debe adivinar:" << aux <<endl;
		cout<<"\tEstado del mu�eco: ";
		cuerpo(contCuerpo);
		printf("\n\tIngrese una letra: ");
		textbackground(BLUE);
		scanf("%s", &letraInput);
		textbackground(BLACK);
		if(isalpha(letraInput)){
			if(agrLetra(letras, letraInput, contJugadas, cantLetras)==true){
				valorResp = verificar(letraInput, num, aux, palabra, aciertos);
				if(valorResp==false){
					contCuerpo++;
					i++;
				}
			}
			else{
				printf("\n\tLa letra ya fue ingresada. Vuelva a intentar.");
				system("pause");
			}
			cout<<"\n\t";
			crearLineas('=', 40);
		}
		else{
			printf("\n\tEl valor ingresado no es una letra. Vuelva a ingresar.");
			cout<<"\n\t";
			crearLineas('=', 40);
			system("pause");
		}
		contJugadas++;
		system("cls");
	}
		if(i==11){
			puntaje=0;
			textcolor(LIGHTRED);
			printf("\n\n\n\n\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\t\t\t\tPerdiste, tienes 0 puntos. La palabra era: ");
				for(int l=0; l<num; l++){
				cout<<palabra[l];
				}
			printf("\n\n\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n\n\n");
			textcolor(WHITE);
		}
		else{
			puntaje=50-(2*contCuerpo);
			textcolor(LIGHTGREEN);
			printf("\n\n\n\n\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\t\t\t\t\t\tObtuviste %d puntos.\n\n\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n\n\n", puntaje);
			textcolor(WHITE);
		}
	system("pause");
	system("cls");
}

//	verifica que la letra ingresada se encuentra
bool verificar(char letra, int n, char aux[], char palabra[], int &c){
	letra=toupper(letra);
	bool valor=false;
		for(int i=0; i<n; i++){
			if(letra==palabra[i]){
				aux[i]=letra;
				valor=true;
				c++;
			}
		}
	return valor;
}

//	rellena de guiones la variable
void rellenar(char aux[], int num){
	vaciar(aux);
		for(int i=0; i<num ; i++){
			aux[i]= '-';
		}
}

//  VISUALIZADOR DE PARTES DEL CUERPO EN FORMA VERBAL
void cuerpo(int numParte){
	string partesCuerpo[12];
	partesCuerpo[0]="No hay partes plasmadas ";
	partesCuerpo[1]=" Cabeza ";
	partesCuerpo[2]="- Tronco ";
	partesCuerpo[3]="- Brazo izquierdo ";
	partesCuerpo[4]="- Brazo derecho ";
	partesCuerpo[5]="- Pierna izquierda ";
	partesCuerpo[6]="- Pierna derecha ";
	partesCuerpo[7]="- Mano izquierda ";
	partesCuerpo[8]="- Mano derecha ";
	partesCuerpo[9]="- Pie izquierdo ";
	partesCuerpo[10]="- Pie derecho. ";

		if(numParte==0){
			cout<<partesCuerpo[0];
		}
		else{
			if(numParte==10){
				textcolor(LIGHTRED);
				Beep(250, 100);
				Beep(400, 100);
			}
				for(int i=1; i<numParte+1; i++){
					if(i==4){
						cout<<"\n\t";
					}
						if(i==7){
							cout<<"\n\t";
						}
					cout<<partesCuerpo[i];
				}
		}
	grafPersona(numParte);
	textcolor(WHITE);
}


// 	VERIFICACION DE LETRA INGRESADA
bool agrLetra(char listLetras[], char letra, int intentos, int &cantIntegradas){
	bool valor=true;
	letra=toupper(letra);

		for(int i=0; i<cantIntegradas ; i++){
			if(letra==listLetras[i]){
				valor=false;
			}
		}
			if(valor==false){
				return false;
			}
			else{
				cantIntegradas++;
				listLetras[intentos-1]=letra;
				return true;
			}
}

// VISULIZADOR DE LETRAS YA INGRESADAS

void mostrarLetras(char letras[], int cantIntegradas){
	for(int i=0; i<cantIntegradas; i++){
		cout<<letras[i];
		cout<<"-";
	}
}
