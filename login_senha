#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

char login[15] , senha[15] , cad_login[15] , cad_senha[15];
int ret_login , ret_senha,escolha;
int main(void){
  printf("----------------------------\n");
  printf("    BEM-VINDO AO SISPET\n");
  printf("----------------------------\n");

  printf("1-Cadastrar\n");
  printf("2-Login\n");
  printf("Qual sua escolha?");
  scanf("%i",&escolha);

  switch(escolha){
  case 1:
    return cadastro();
  case 2: 
    return login1();
    }
}
int cadastro(void)
{
    setlocale(LC_ALL, "Portuguese");
    printf("--------------------------\n");
    printf("  CADASTRO LOGIN E SENHA\n");
    printf("--------------------------\n");

    printf("Login no máximo 10 caracteres:\n");
    scanf("%s",&cad_login);
    printf("Senha no máximo 10 caracteres:\n");
    scanf("%s",&cad_senha);
    printf("Cadastro realizado com sucesso\n");

    system("clear");
    return login1() ;
  }
  int login1(void){
    printf("--------------------------\n");
    printf("      LOGIN E SENHA\n");
    printf("--------------------------\n");

    printf("Login:\n");
    scanf("%s",&login);
    printf("Senha:\n");
    scanf("%s",&senha);

    ret_login = strcmp(login,cad_login);
    ret_senha = strcmp(senha,cad_senha);
    if (ret_login==0 && ret_senha==0){
      printf("Login realizado com sucesso!");
      }else{
      printf("Login Invalido!\n");
      system("clear");
      return login1();
      }
     system("clear");
    }
