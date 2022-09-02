#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int senha, senha2;
char email[100];
char nome[100], nome2[100];

int main(void) {
printf("------------SISPET---------------");
printf("\n");

  printf("Nome: ");
    scanf("%s", &nome[100]);
  printf("Email: ");
    scanf("%s", &email[100]);
  printf("Senha: ");
    scanf("%i", &senha);
  printf("Confirmar: ");

printf("\n");
printf("------------SISPET---------------");

  system("clear");

printf("\n \n Login: ");
  scanf("%s", &nome2[100]);
printf("\n Senha: ");
  scanf("%i", &senha2);

  return 0;
}
