#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SEGMENTOS 7

int APAGADO[SEGMENTOS]	=	{0,0,0,0,0,0,0};
int CERO[SEGMENTOS]		=	{1,1,1,0,1,1,1};
int UNO[SEGMENTOS]		=	{0,0,0,0,0,1,1};
int DOS[SEGMENTOS]		=	{1,0,1,1,1,0,1};
int TRES[SEGMENTOS]		=	{0,0,1,1,1,1,1};
int CUATRO[SEGMENTOS]	=	{0,1,0,1,0,1,1};
int CINCO[SEGMENTOS]	=	{0,1,1,1,1,1,0};
int SEIS[SEGMENTOS]		=	{1,1,1,1,1,1,0};
int SIETE[SEGMENTOS]	=	{0,0,0,0,1,1,1};
int OCHO[SEGMENTOS]		=	{1,1,1,1,1,1,1};
int NUEVE[SEGMENTOS]	=	{0,1,1,1,1,1,1};

int entradaValida(int argEntrada, char **argumentos){
	int valido = 1;
	int i;
	if(!strcmp(*(argumentos+argEntrada-1), "-1")){
		for (i = 0; i < (argEntrada-1); ++i)
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
	int i, j;
	for (i = 0; i < digitos; ++i)
	{
		int *fila = (int *) malloc(sizeof(**panel)*SEGMENTOS);
		for (j = 0; j < SEGMENTOS; ++j)
		{
			*(fila+j) = 0;
		}
		*(panel+i) = fila;
		

	}
	
	return panel;
} 
int* transformarEntrada(int nArgumentos, char **argumentos){
	int *digitos = (int *) malloc(sizeof(int)*nArgumentos);
	int i;
	for (i = 0; i < nArgumentos; ++i)
	{
		*(digitos+i) = **(argumentos+i)-'0';
	}
	return digitos;
}
int* getSegmento(int digito){
	switch(digito){
		case 0:
			return CERO;
		case 1:
			return UNO;
		case 2:
			return DOS;
		case 3:
			return TRES;
		case 4:
			return CUATRO;
		case 5:
			return CINCO;
		case 6:
			return SEIS;
		case 7:
			return SIETE;
		case 8:
			return OCHO;
		case 9:
			return NUEVE;
	}
	return NULL;
}
void matriscopy (int **destmat, int **srcmat, int rowcount, int columncount) 
{
  int i, j;
  for (i=0; i<rowcount; i=i+1) /* rad-nr */
    for (j=0; j<columncount; j=j+1) /* kolumn-nr */
      destmat[i][j] = srcmat[i][j];
}
int countDiferences(int **panel, int **nuevoPanel, int nArgumentos){
	int resultado = 0;
	int i, j;
	for (i= 0; i < nArgumentos; ++i)
	{
		for (j = 0; j < SEGMENTOS; ++j)
		{
			if (panel[i][j] != nuevoPanel[i][j])
			{
				resultado++;
			}
		}		
	}
	return resultado;
}	





int main(int argc,char **argv){
	int solucion = 0;
	int nArgumentos, i, j; 
	int **panel;
	int **nuevoPanel;
	int *entrada;
	if(entradaValida(argc-1, argv+1)){
		nArgumentos = argc-2;
		panel = inizializarPanel(nArgumentos);
		nuevoPanel = inizializarPanel(nArgumentos);
		entrada = transformarEntrada(nArgumentos, argv+1);
		
		//entrada de los digitos
		for (i = 0; i < nArgumentos; ++i) 
		{
			for (j = 0; j < nArgumentos-1; ++j)
			{
				*(nuevoPanel+j) = *(panel+j+1);
			}
			*(nuevoPanel+nArgumentos-1) = getSegmento(*(entrada+i));
			
			solucion += countDiferences(panel, nuevoPanel, nArgumentos);

			matriscopy(panel, nuevoPanel, nArgumentos, SEGMENTOS);
		}



		//salida de los digitos
		for (i = 0; i < nArgumentos; ++i) 
		{
			for (j = 0; j < nArgumentos-1; ++j)
			{
				*(nuevoPanel+j) = *(panel+j+1);
			}
			*(nuevoPanel+nArgumentos-1) = APAGADO;
			solucion += countDiferences(panel, nuevoPanel, nArgumentos);

			matriscopy(panel, nuevoPanel, nArgumentos, SEGMENTOS);
		}
	}	
	printf("%d\n", solucion);
	return 0;
}