#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SEGMENTOS 7

#define BASE 	{0,0,0,0,0,0,0}
#define CERO	{1,1,1,0,1,1,1}
#define UNO 	{0,0,0,0,0,1,1}
#define DOS 	{1,0,1,1,1,0,1}
#define TRES	{0,0,1,1,1,1,1}
#define CUATRO	{0,1,0,1,0,1,1}
#define CINCO	{0,1,1,1,1,1,0}
#define SEIS	{1,1,1,1,1,1,0}
#define SIETE	{0,0,0,0,1,1,1}
#define OCHO	{1,1,1,1,1,1,1}
#define NUEVE	{0,1,1,1,1,1,1}

int entradaValida(int nArgumentos, char **argumentos){
	int valido = 1;
	if(!strcmp(*(argumentos+nArgumentos-1), "-1")){
		for (int i = 0; i < (nArgumentos-1); ++i)
		{
			if (strlen(*(argumentos+i)) > 1 || **(argumentos+i) < 48 || **(argumentos+i) > 58)
			{
				valido = 0;
			}
		}
	}
	return valido;
}

int** inizializarPanel(int digitos){
	int **panel = (int **) malloc(sizeof(*panel)*digitos);
	for (int i = 0; i < digitos; ++i)
	{
		int *fila = (int *) malloc(sizeof(**panel)*SEGMENTOS);
		for (int j = 0; j < SEGMENTOS; ++j)
		{
			*(fila+j) = 0;
		}
		*(panel+i) = fila;
		

	}
	
	return panel;
} 
int* transformarEntrada(int nArgumentos, char **argumentos){
	int *digitos = (int *) malloc(sizeof(int)*nArgumentos);
	for (int i = 0; i < nArgumentos; ++i)
	{
		*(digitos+i) = **(argumentos+i)-'0';
	}
	return digitos;
}
	





int main(int argc,char **argv){
	int solucion = 0;
	int **panel;
	int *entrada;
	if(entradaValida(argc-1, argv+1)){
		panel = inizializarPanel(argc-2);
		entrada = transformarEntrada(argc-2, argv+1);
		
	}

	

	
	
	return 0;
}
