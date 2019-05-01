#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "FuncoesCalculadora.h"

int main(void)
{
   int continuar=1;
   char operacao[20];
   float numeroA,numeroB;
   float (*fxoperacao)(const float *, const float *);

   ajuda();
   while(continuar)
   {   
        printf("Digite a operação desejada: ");
        fgets(operacao,3,stdin);  //Verificar possíveis problemas com buffer

        if(operacao[0] != 's')
        {
	   switch(operacao[0])   //Verificar uma forma eficiente de separar isso em uma função
           {
              case '+':    //A nova funcao poderia retornar ponteiros para funcao ?
		 fxoperacao=soma;
                 break;
              case '-':
		 fxoperacao=subtracao;
  		 break;
	      case '*':
		 fxoperacao=multiplicacao;
		 break;
	      case '/':
		 fxoperacao=divisao;
                 break;
	      case 'h':
		 ajuda();  //Se ponteiro para funcao como  retornar essa ?
		 continue;
              default:
		 printf("Operação inválida\n");
                 continue;
           }
	   

	   printf("Digite o primerio numero: ");
           fgets(operacao,19,stdin); numeroA=atof(operacao);
           printf("Digite o segundo número: ");
           fgets(operacao,19,stdin); numeroB=atof(operacao);

	   printf("Resultado: %f",fxoperacao(&numeroA,&numeroB));
	   printf("\n\n"); 
        }
        else
           continuar=0;                
   }

}
