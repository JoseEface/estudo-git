#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**Operações da calculadora**/

/* Comentario */

/*Comentario inutil*/

float soma(const float *a, const float *b)
{
  return *a+*b;
}

float subtracao(const float *a, const float *b)
{
  return *a-*b;
}

float multiplicacao(const float *a, const float *b)
{
  return (*a)*(*b);
}

float divisao(const float *a, const float *b)
{
  if(*b == 0)
  {
    printf("\nVocẽ não pode realizar divisão por zero\n=> ");
    return 0;
  }
  
  return (*a)/(*b);
}

void ajuda(void)
{
   printf("Lista de operações disponíveis: \n\n");
   printf("+ - realiza a soma de dois números\n");
   printf("- - realiza a subtração de dois números\n");
   printf("* - realiza a multiplicação de dois números\n");
   printf("/ - realiza a divisão de dois número\n");
   printf("h - mostra esse menu de ajuda\n");
   printf("s - sai do programa\n\n");   
}

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
        fgets(operacao,3,stdin);

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
