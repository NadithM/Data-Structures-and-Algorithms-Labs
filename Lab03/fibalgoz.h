#include <stdio.h>
#include <stdlib.h>

unsigned long long M5[2][2] = {{1,0},{0,1}};
	unsigned long long M[2][2] = {{1,1},{1,0}};



unsigned long long fib2(int n)
    {
    int i=0;
    unsigned long long f[n+1];
   
    f[1] = 1;
    f[2] = 1;
   
    for (i = 3; i <= n; i++)
        f[i] = f[i-1] + f[i-2];
    return f[n];
    }


unsigned long long fib1(int n)
    {
  
    if (n <= 2) return 1;
    else return fib1(n-1) + fib1(n-2);
    }



unsigned long long fib3(int n)
    {
    unsigned long long a = 1, b = 1;
    int i;
    for (i = 3; i <= n; i++) {
        unsigned long long c = a + b;
        a = b;
        b = c;
    }           
    return b;
    }

    unsigned long long fib4(int n)
    {
    unsigned long long M[2][2] = {{1,0},{0,1}};
    unsigned long long a,b,c,d;
    int i;
    for (i = 1; i < n; i++){
       a  = M[0][0]*1 +  M[0][1]*1;
       b  = M[0][0]*1;
       c = M[1][0]*1 +  M[1][1]*1;
       d  = M[1][1]*1 ;
       M[0][0]=a;
       M[0][1]=b;
       M[1][0]=c;
       M[1][1]=d;
      }
    
    return M[0][0];
    }


void matMul(unsigned long long a[2][2],unsigned long long b[2][2],unsigned long long c[2][2]){
    
    unsigned long long temp[2][2];
    int i,j,k;
    int sum;
    
    for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
        
                sum = 0;
                for (k = 0; k < 2; k++) {
                sum = sum + a[i][k] * b[k][j];                
                }
                
            temp[i][j] = sum;               
            }
        }
     for(i = 0; i < 2; i++){
            for(j=0;j<2; j++){
                c[i][j] = temp[i][j]; 
            }         
        } 
        
}  
void matpow(int n){
    if (n > 1) {
        matpow(n/2);
        matMul(M5,M5,M5);
    }
    if (n%2 == 1)
        matMul(M5,M,M5);
}
unsigned long long fib5(int n){

	
    matpow(n-1);
    unsigned long long t=M5[0][0];

     	M5[0][0]= 1;
        M5[0][1]= 0;
        M5[1][0]= 0;
        M5[1][1]= 1;
        M[0][0] =1;
        M[0][1] =1;
        M[1][0] =1;
        M[1][1] =0;

    return t;
}



  

unsigned long long fib6_2(int n, unsigned long long p0, unsigned long long p1)
{
  return n == 1 ? p1 : fib6_2(n - 1, p1, p0 + p1);
}

unsigned long long fib6(int n)
{
  return n == 0 ? 0 : fib6_2(n, 0, 1);
}


   

