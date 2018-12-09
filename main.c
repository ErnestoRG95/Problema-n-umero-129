#include<stdio.h>
#include<string.h>

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
	entradaValida(argc-1, argv+1);

	

	
	
	return 0;
}
