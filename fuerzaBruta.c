#include <iostream>
//#include <stdio>
#include <stdlib.h>
#include <time.h>

int calcularTamano(FILE *archivo, int *tamano){
	char buff;
	archivo = fopen("mochila.dat", "r");
	while( (buff = getc(archivo))!=EOF ){ //calcular dimenciones
		if((buff == '\n')||(buff == '\r')){
			tamano[0]++;
		}
	}
	return 0;
}
int leerGrafo(int **matriz, FILE *archivo){
	char buff;
	int x = -1, indice = 0;
	archivo = fopen("mochila.dat", "r");
	while( (buff = getc(archivo))!=EOF ){//inserto valores
		if( (buff != '\n')&&(buff != '\r') ){
			if(x == -1){
				indice = atoi(&buff);
				x++;
			}else{
				x = atoi(&buff);
				matriz[indice][x] = 1;
			}
		}else{
			x = -1;
		}
	}
	return 0;
}
int llenarMatriz(int **Matriz, int ancho){
	int i, j;
	for(i = 0; i < ancho; i++){
		for(j = 0; j < ancho; j++){
			if(Matriz[i][j] != 1){
				Matriz[i][j] = 0;
			}
		}
	}	
}




int void main()
{
int w[10],v[10],n,w1,i,W,k[10][10],j;
//clrscr();
clock_t s=clock()/CLK_TCK;
clock_t start_time;
    clock_t final_time;
    double total_time;
    start_time = clock();
 
//cout<<"enter the number of items";
//cin>>n;
//cout<<"enter the total weight";
//cin>>W;
//cout<<"enter the weight";
//for(i=1;i<=n;i++)
//cin>>w[i];
//cout<<"enter the value";
FILE *archivo;
	int *tamano = (int *)malloc(sizeof(int)), **matriz, i;
	tamano[0] = 1;
	calcularTamano(archivo, tamano);
	matriz = (int **)malloc(tamano[0]*sizeof(int*));
	for(i=0; i < tamano[0];i++){
		matriz[i] = (int*)malloc(tamano[0]*sizeof(int));
	}
	leerArchivo(matriz, archivo);
	llenarMatriz(matriz, tamano[0]);




for(i=1;i<=n;i++)
cin>>v[i];
for(w1=1;w1<=W;w1++)
k[i][0]=0;
for(i=1;i<=n;i++)
{
for(w1=0;w1<=W;w1++)
{
if(w[i] <= W)
{
if((v[i] + k[i-1][w1-w[i]]) > (k[i-1][w1]))
k[i][w1]=v[i]+k[i-1][w1-w[i]];
else
k[i][w1]=k[i-1][w1];
}
else
k[i][w1]=k[i-1][w1];
}
}
i=n;
int val=0;
while((i>0) && (W>0))
{
if(k[i][W] != k[i-1][W])
{
cout<<"\nitem number in knapsack is "<< i;
val=val+v[i];
W=W-w[i];
i=i-1;
}
else
i=i- 1;
}
cout<<"\noptimal value is " <<val;
final_time = clock();
    total_time = ((double)(final_time - start_time)) / CLOCKS_PER_SEC;
 
    printf("Tiempo de ejecución : %lf segundos \n", total_time);
 
//cout<<"\nRunning time in Seconds "<< (double(clock() / CLK_TCK) - s);
//getch();
return 0;

