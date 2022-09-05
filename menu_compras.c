#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main(void) {
  setlocale(LC_ALL, "Portuguese");
  int i = 0, escolha;
  float valorracao=0, valorTotal=0,racao=0;
  int pagamento=0, coleiras=0, totalcoleiras=0, shampoo=0, totalshampoo=0;

  printf(" Código \t");
  printf(" Produto \t \t");
  printf(" Preço \t\t\t" );
  printf(" Descrição \t\t\ \n" );
  printf(" 1 \t\t Ração \t\t\t R$10.9 por KG \t\t A melhor comida para seu pet \n");
  printf(" 2 \t\t Coleira\t\t R$40 reais \t\t Revestida de titanium, para pet de grande porte. \n");
  printf(" 3 \t\t Shampoo\t\t R$30 reais \t\t Com cheiro de castanhas do pará e quinoa. \n");

  while(i == 0){
    printf("Informe o código do produto que deseja comprar: \n");
    scanf("%i",&escolha);

    switch(escolha)
    {
      case 1:
      printf("Quantos quilos de ração deseja comprar :\n");
      scanf("%f",&racao);
      valorracao= (racao * 10.9);
      break;
      case 2:
      printf("Quantas coleiras deseja comprar :\n");
      scanf("%i",&coleiras);
        totalcoleiras=coleiras*40;
      break;
      case 3:
      printf("Quantos shamppos deseja comprar :\n");
      scanf("%i",&shampoo);
        totalshampoo=shampoo*40;
      break;

      default :
      printf ("Valor invalido!\n");
    }
    printf("Para finalizar compra digite 1 , caso deseje continuar a compra digite 0: \n");
    scanf("%i",&i);
  }
  valorTotal = valorracao + totalcoleiras+ totalshampoo;

  printf("Sua compra vai custar R$ %.2f \n",valorTotal);
  printf("Qual será a forma de pagamento?\n");
  printf("1- PIX\n");
  printf("2- Cartão de crédito\n");
  printf("3- Cartão de débito\n");
  printf("4- Mercado Pago\n");
  printf("5- Dinheiro\n");
  scanf("%i",&pagamento);
  switch(pagamento)
  default:
    printf("Pagamento Realizado com sucesso!\n");

  return 0;
}
