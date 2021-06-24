#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char rut[500];
int serie=2,i,total=0,x,n;
int chartoint(char x)
{
     int digito;
     switch(x)
     {
              case '0':digito=0;break;
              case '1':digito=1;break;
              case '2':digito=2;break;
              case '3':digito=3;break;
              case '4':digito=4;break;
              case '5':digito=5;break;
              case '6':digito=6;break;
              case '7':digito=7;break;
              case '8':digito=8;break;
              case '9':digito=9;break;
     }return digito;
}
void digver()
{
     for(i=n-1;i>=0;i--)
     {
           x=rut[i];
           if(serie>7)
                 serie=2;
           total+=chartoint(rut[i])*(serie);
           printf("\n%d",total);
           serie++;
     }
     total=total%11;
     total=11-total;
}
main()
{
      system("color f0");
      system("title rut verificador");
      serie=2;
      i=0;
      total=0;
      x=0;
      n=0;
      puts("BIENVENIDO");
      puts("ingrese su RUT: ");
      printf("\n");
      gets(rut);
      n=strlen(rut);
      printf("%d",n);
      //scanf("",&);
      digver();
      if(total==10)
            printf("su digito verificador es: K");
      else
            printf("su digito verificador es: %d\n",total);
      printf("\n\n\n\n");
      system("pause");
      system("cls");
      main();
}
