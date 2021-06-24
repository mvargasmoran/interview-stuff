#include <stdio.h>
#include <stdlib.h>
main()
{
      int num1,num2,mcd=1,div=2;
      printf("ingrese los numeros\n");
      scanf("%d",&num1);
      scanf("%d",&num2);
       do
       {
           if(((num1%div)==0) && ((num2%div)==0))
           {
               num1=num1/div;
               num2=num2/div;
               mcd*=div;
           }       
           else 
               div++;
       }while(num1>div);
       printf("el mcd es: %d\n",mcd);
       system("pause");
       system("font arial");
}
