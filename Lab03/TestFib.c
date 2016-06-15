#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fibalgoz.h"

#define SIZE1 45
#define SIZE 10000


int main(){


clock_t end ,start;
int i=0;
unsigned long long array1[SIZE1];
unsigned long long array2[SIZE];
unsigned long long array3[SIZE];
unsigned long long array4[SIZE];
unsigned long long array5[SIZE];
unsigned long long array6[SIZE];

float secnd[6]={0};
	
		printf("Please Wait few Seconds.Numbers are calculating...:)\n\n");
		
		start = clock();

		for (i=1;i<SIZE1;i++){
			array1[i]=fib1(i);
		}
		end = clock();

		secnd[0]=(float)(end - start) / CLOCKS_PER_SEC;
		
		start = clock();

		
		for (i=1;i<SIZE;i++){
			array2[i]=fib2(i);
		}

		end = clock();
		secnd[1]=(float)(end - start) / CLOCKS_PER_SEC;

		start = clock();

		
		for (i=1;i<SIZE;i++){
			array3[i]=fib3(i);
		}


		end = clock();
		
		secnd[2]=(float)(end - start) / CLOCKS_PER_SEC;


		start = clock();

		
		for (i=1;i<SIZE;i++){
			array4[i]=fib4(i);
		}

		end = clock();
		secnd[3]=(float)(end - start) / CLOCKS_PER_SEC;


		start = clock();

		
		for (i=1;i<SIZE;i++){
			array5[i]=fib5(i);
		}

		end = clock();
		secnd[4]=(float)(end - start) / CLOCKS_PER_SEC;

		start = clock();

		
		for (i=1;i<SIZE;i++){
			array6[i]=fib6(i);
		}

		end = clock();
		secnd[5]=(float)(end - start) / CLOCKS_PER_SEC;

		
		/*
			for (i=1;i<45;i++)
			printf("F(%2d) = %10u \t\t \n",i,array1[i]) ;

			for (i=1;i<45;i++)
			printf("F(%2d) = %10u \t\t \n",i,array2[i]) ;

			for (i=1;i<45;i++)
			printf("F(%2d) = %10u \t\t \n",i,array3[i]) ;

			for (i=1;i<45;i++)
			printf("F(%2d) = %10u \t\t \n",i,array4[i]) ;

			for (i=1;i<45;i++)
			printf("F(%2d) = %10u \t\t \n",i,array6[i]) ;
		

		*/

		for (i=1;i<45;i++)
			printf("F(%2d) = %10u \t\t \n",i,array5[i]) ;
		

		printf("\nTime taken for First 45  Fibonacci numbers\n\n");
		printf("Using algorithm 1.Recursive					 = %f sec\n\n",secnd[0]);

		printf("Time taken for First 10000  Fibonacci numbers\n\n");
		printf("Using algorithm 1.Recursive(SHOULD BE)				= INFINITE sec\n");

		printf("Using algorithm 2.Dynamic Programming 				= %f sec\n",secnd[1]);
		
		printf("Using algorithm 3.Space optimized Dynamic Programming		= %f sec\n",secnd[2]);
		
		printf("Using algorithm 4.Recursive Powering 				= %f sec\n",secnd[3]);
		
		printf("Using algorithm 5.Time optimized (log n) Recursive Powering 	= %f sec\n",secnd[4]);
		
		printf("Using algorithm 6.Intelligent Recursive Fibonacci Solution 	= %f sec\n",secnd[5]);
		
			
		


    	return 0;

    }


