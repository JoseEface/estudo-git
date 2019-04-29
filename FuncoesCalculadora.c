#include "FuncoesCalculadora.h"

float soma(const float *a, const float *b)
{
   return *a + *b;
}

float subtracao(const float *a, const float *b)
{
   return *a - *b;
}

float multiplicacao(const float *a, const float *b)
{
   return (*a)*(*b);
}

float divisao(const float *a, const float *b)
{
   if(*b == 0)
   {
      printf("\nVocê não pode realizar divisão por zero");
      return 0;
   }
   
   return (*a)/(*b);
}

void ajuda(void)
{
   printf("Lista de operações disponíveis: \n\n");
   printf("+ - realiza a soma de dois números\n");
   printf("- -  realiza a subtração de dois números\n");
   printf("* - realiza a multiplicação de dois números\n");
   printf("/ - realiza a divisão de dois números\n");
   printf("h - mostra esse menu de ajuda\n");
   printf("s - sai do programa \n\n");
}




