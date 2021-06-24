#include <stdio.h>
#include <stdlib.h>
long fibonacci( long n )
{
   if ( n == 0 || n == 1 ) {
      return n;
   } 
   else { 
      return fibonacci( n - 1 ) + fibonacci( n - 2 );
   }
}
main()
{
   long n;
   long resultado; 
   long numero;  
   printf( "Introduzca un entero: " );
   scanf( "%ld", &n);
   resultado = fibonacci( n );
   printf( "Fibonacci( %ld ) = %ld\n", n, resultado );
   system("pause");
   system("cls");
   main();
}
