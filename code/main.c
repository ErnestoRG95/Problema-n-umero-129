#include<stdio.h>
#include<string.h>

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



int main(int argc,char **argv){
	int solucion = 0;
	if(entradaValida(argc-1, argv+1)){
		for (int i = 1; i < argc-1; ++i)
		{

		}
		printf("%d\n", solucion);
	}

	

	
	
	return 0;
}
