#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "FuncoesCalculadora.h"

/**Função principal**/

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
	   switch(operacao[0])
           {
              case '+':
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
		 ajuda(); 
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
