#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void bubble_sort(int *A,int n);           //Declaración de funciones
void selection_sort (int *B,int n);
void insertion_sort(int *C, int n);

int main(int argc)
{
	int n = 2000;						//Numero de valores 
	int A[n];							//Definicion de arreglo
	int B[n];
	int C[n];							
	clock_t t_start, t_finish;			//variables para medir tiempo
	double t_interval;					//Variable para obtener resultados de tiempo precisos
	int i;


	for (i=0;i<n;i++)					//Escanea valores del documento seleccionado 
	{
		scanf("%d", &A[i]);
		B[i]=A[i];						//Asigna valores a todas las matrices
		C[i]=A[i];
	}


	t_start=clock();					//Llama a funcion Clock
	bubble_sort(A,n);					//Llama a funcion Bubble Sort 
	t_finish=clock();					
	t_interval = (double)(t_finish - t_start)/CLOCKS_PER_SEC;			//Ecuacion para obtener resultado de tiempo mas preciso
	printf("\n\nTiempo de bubble sort: %.8f seconds.", t_interval);


	t_start=clock();					//Llama a funcion Clock
	selection_sort (B,n);				//Llama a funcion Selection Sort
	t_finish=clock();
	t_interval = (double)(t_finish - t_start)/CLOCKS_PER_SEC;			//Ecuacion para obtener resultado de tiempo mas preciso
	printf("\n\nTiempo de selection sort: %.8f seconds.", t_interval);


	t_start=clock();					//Llama a funcion Clock
	insertion_sort(C, n);				//Llama a funcion Insertion Sort
	t_finish=clock();
	t_interval = (double)(t_finish - t_start)/CLOCKS_PER_SEC;			//Ecuacion para obtener resultado de tiempo mas preciso
	printf("\n\nTiempo de insertion sort: %.8f seconds.", t_interval);
}



void bubble_sort(int *A,int n)				//Funcion Bubble Sort 
{
	
	int eliminar=0, i=0, aux=0;				

	while(n != eliminar)
	{
      for(i=0; i <((n-1)-eliminar); i++)
		{
          if(A[i]>A[i+1])
		  {
             aux=A[i];
             A[i]=A[i+1];
             A[i+1]=aux;
          }
      	}
       eliminar++;
	}
	for(i=0;i<n;i++)
		printf("\nA[%d]=%d",i,A[i]);
}

void selection_sort (int *B,int n)				//Funcion Selection Sort 
{
	int aux=0, i=0, j=0, aux2=0;
	
	for(i=0; i<n; i++)
	{
    	aux2=i;
    	for(j=i+1; j<n; j++)
		{
        	if(B[j]<B[aux2])
			{	
            	aux2=j;
        	}	
        aux=B[i];
        B[i]=B[aux2];
        B[aux2]=aux;
    	}	
	}
	for(i=0;i<n;i++)
		printf("\nB[%d]=%d",i,B[i]);
}

void insertion_sort(int *C, int n)					//Funcion Insertion Sort 
{ 
	
	for (int i = 1; i < n;i++){
		int key = C[i];
		int j = i-1;
		
		while (j>=0 && C[j]>key){
			C[j+1]= C[j];
			j = j-1;
		}
		C[j+1]= key;
	}
	for(int i=0;i<n;i++)
		printf("\nC[%d]=%d",i,C[i]);
}


