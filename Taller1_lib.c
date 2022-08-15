/**************************************************
#   Fecha: 2-Agosto 2022
#   Autor: Diego Bermúdez
#   Materia: Parallel & Distributin Computation
#   Tema:Taller 1
#   Topic: Implementación de las funciones
#*************************************************/

/*Here I made an import of c defined libraries */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*Here I created a funtion in order to present my program 
* In this part I made a menu to present the solutions for all the 10 job points*/
void presentacion()
{
	printf("**********  Bienvenido al programa solucion del taller #1  ***********\n");
	printf("Seleccione la opcion que decea ejecutar\n");
	printf("1.Multiplicacion de dos números enteros\n");
	printf("2.Conversor de dias en años,semanas,dias\n");
	printf("3.Calcular la distancia entre dos puntos 'cordenadas'\n");
	printf("4.Mostrar los 10 primero numeros naturales\n");
	printf("5.Mostrar patron de triangulo rectangulo 'max 14 lineas'\n");
	printf("6.Mostrar matriz de '1' de tamaño deseado 'max 8'\n");
	printf("7.Mostrar dos matrices aleatorias de tamaño deseado 'max 8'\n"); 
		printf("	7.1.Su suma\n");
		printf("	7.2.Su resta\n");
		printf("	7.3.Su producto\n");
	printf("0.Para terminar la ejecucion\n");
	int seleccion;
	scanf("%d",&seleccion);
	menu(seleccion);
	if(seleccion!=0)
	presentacion();
	
}
/*This funtion take the order of the user to solve an specific 1-10 problem (1-7/3)
**And show the answer. This funtion call the specific method for each point to be solved*/
void menu(int seleccion)
{
	switch (seleccion)
	{
	case 1:
		printf("Ingrese los dos numeros a multiplicar\n");
		int a1,b1;
		scanf("%d",&a1);
		scanf("%d",&b1);
		int multiplicacion=multiplicacionEnteros(a1,b1);
		printf("El producto de los numeros es:\n%d",multiplicacion,"\n");
		printf("\n");
		break;
	case 2:
		printf("Ingrese la cantidad de dias a convertir:\n");
		int dias;
		scanf("%d",&dias);
		conversorDias(dias);
		break;
	case 3:
		printf("Ingrese las cordenadas de los puntos en el siguiente orden:\n");
		double x1,y1,x2,y2;
		scanf("%lf",&x1);
		scanf("%lf",&y1);
		scanf("%lf",&x2);
		scanf("%lf",&y2);
		distancia(x1,y1,x2,y2);

		break;
	case 4:
		printf("Los primeros 10 numero naturales son:\n");
		for(int i=1;i<11;i++)
		printf("%d ",i);
		break;
	case 5:
		triangulo();
		break;
	case 6:
		printf("Ingrese el tamaño de la matriz");
		int n;
		scanf("%d",&n);
		matrizD1(n);
		break;
	case 7:
		printf("Ingrese el tamaño de las matrices:\n");
		int z,seleccion2,SIZE;
		scanf("%d",&z);
		SIZE=z*z;
		int a[SIZE],b[SIZE],c[SIZE];
		printf("Se muestran las matrices\n");
		inicializacionMM(z,a,b,c);
		impresionMatriz(a,z);
		impresionMatriz(b,z);
		printf("Que decea realizar con las matrices:\n");
		printf("1.Suma\n");
		printf("2.Resta\n");
		printf("3.Multiplicación\n");
		printf("Cualquier otro número:solo impresión de las matrices a-b \n");
		scanf("%d",&seleccion2);
		switch (seleccion2)
		{
		case 1:
			sumaMM(z,a,b,c);
			break;
		case 2:
			restaMM(z,a,b,c);
			break;
		case 3:
			multiplicacionMM(z,a,b,c);
			break;
		default:
			break;
		}
	}

	printf("\n\n\n");
}
/*This one just return the product of the given numbers (2)*/
int multiplicacionEnteros(int a,int b)
{
	return a*b;
}
/*This method show how many years weeks and days would be in a given numer of days*/
void conversorDias(int dias)
{
	printf("La conversion de %d dias en años,semanas y dias es:\n");
	int anios=0,semanas=0,diasF=0;
	if(dias>=365)
	anios=dias/365;
	dias-=anios*365;
	printf("Años:%d \n",anios);
	if(dias>=30)
	semanas=dias/7;
	dias-=semanas*7;
	printf("Semanas:%d \n",semanas);
	diasF=dias;
	dias-=diasF;	
	printf("Dias:%d \n",diasF);
}
/*This funtion calculate the distance between two coordinates*/
void distancia(double x1,double y1,double x2,double y2)
{

	double x=x2-x1,y=y2-y1,t=0;
	x=pow(x,2),y=pow(y,2),t=x+y;
	double distancia=pow(t,0.5);
	printf("La distancia entre los dos puntos es:%lf",distancia);
}
/*This method show a rectangular triangle made by "*" with a given "sieze" */
void triangulo()
{
	printf("Ingrese la cantidad de lineas que desea visualisar:\n");
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		printf("*");
		printf("\n");
	}
}
/*This funtion define a matrix of nxn size "given" with only "1" and show it*/
void matrizD1(int N)
{
	int SIZE=N*N;
	int a[SIZE];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			a[i+j*N]=1;
		}
	}
	impresionMatriz(a,N);
}
/*This method initialize two matrix nxn with random numbers and one with 0 */
void inicializacionMM(int N,int a[],int b[],int c[])
{
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			a[i+j*N]=rand() % 10;
			b[i+j*N]=rand() % 10;
			c[i+j*N]=0;
		}
	}
	
}
/*This method print a matrix*/
void impresionMatriz(int a [],int N)
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("%d ",a[i+j*N]);
		}
		printf("\n");
	}
	printf("\n");
}
/*This funtion make the product between two matrix*/
void multiplicacionMM(int N,int a[],int b[],int c[])
{
	int suma=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			suma=0;
			for(int k=0;k<N;k++)
			{
				suma+=a[j+k*N]*b[k+i*N];
			}
			c[j+i*N]=suma;
		}
	}
	printf("El resultado de multiplicar estas dos matrices es:\n");
	impresionMatriz(c,N);
	
}
/*This funtion make the sum between two matrix*/
void sumaMM(int N,int a[],int b[],int c[])
{
	for(int i=0;i<N*N;i++)
	c[i]=a[i]+b[i];
	printf("El resultado de sumar estas dos matrices es:\n");
	impresionMatriz(c,N);
}
/*This funtion make a subtraction between two matrix*/
void restaMM(int N,int a[],int b[],int c[])
{
	for(int i=0;i<N*N;i++)
	c[i]=a[i]-b[i];
	printf("El resultado de restar estas dos matrices(a-b) es:\n");
	impresionMatriz(c,N);
}

