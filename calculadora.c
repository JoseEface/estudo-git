#include <stdio.h>

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

int main(void)
{
   int continuar=1;
   char operacao;
   float numeroA,numeroB;
   float (*fxoperacao)(const float *, const float *);

   while(continuar)
   {   
	printf("Lista de operações disponíveis: \n\n");
	printf("+ - realiza a soma de dois números\n");
	printf("- - realiza a subtração de dois números\n");
	printf("* - realiza a multiplicação de dois números\n");
	printf("/ - realiza a divisão de dois número\n");
	printf("s - sai do programa\n\n");
        printf("Digite a operação desejada: ");
        scanf("%c",&operacao);

        if(operacao != 's')
        {
	   switch(operacao)
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
              default:
		 printf("Operacao invalida\n\n");
		 setbuf(stdin,NULL);
                 continue;
           }

	   printf("Digite o primerio numero: ");
           scanf("%f",&numeroA);
           printf("Digite o segundo número: ");
           scanf("%f",&numeroB);

	   printf("Resultado: %f",fxoperacao(&numeroA,&numeroB));
	   printf("\n\n"); 
	   setbuf(stdin,NULL); /*Evitando salto de alguns scanfs....*/
        }
        else
           continuar=0;                
   }

}
