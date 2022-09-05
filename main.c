#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>
#include <locale.h>

#define BUFFER 64

char login[15] , senha[15] , cad_login[15] , cad_senha[15];
int ret_login , ret_senha,escolha;

int main(void){
  printf("----------------------------\n");
  printf("    BEM-VINDO AO SISPET\n");
  printf("----------------------------\n");

  printf("1-Cadastrar\n");
  printf("2-Login\n");
  printf("Qual sua escolha? ");
  scanf("%i",&escolha);

  system("cls");

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

    system("cls");
    return login1() ;
  }
  int login1(void){
    printf("--------------------------\n");
    printf("      LOGIN E SENHA\n");
    printf("--------------------------\n");

    printf("Login: ");
    scanf("%s",&login);
    printf("Senha: ");
    scanf("%s",&senha);

    ret_login = strcmp(login,cad_login);
    ret_senha = strcmp(senha,cad_senha);
    if (ret_login==0 && ret_senha==0){
      printf("Login realizado com sucesso!");
      }else{
      printf("Login Invalido!\n");
      system("cls");
      return login1();
      }
     system("cls");
     return main1();
    }

/* Estrutura da lista declarada para armazenar nossos dados. */
typedef struct lista {
        char *nome;
        int idade;
        struct lista *proximo;
} Dados;

/* Prototipo das funcoes de manuseio dos dados. */
Dados *inicia_dados(char *nome, int idade);
Dados *insere_dados(Dados *dados, char *nome, int idade);
void exibe_dados(Dados *dados);
void busca_dados(Dados *dados, char *chave);
Dados *deleta_dados(Dados *dados);
int checa_vazio(Dados *dados);

/* Prototipo das funcoes do menu.*/
void insere(void);
void exibe(void);
void busca(void);
void deleta(void);

/* Inicializa a estrutura de dados principal. */
Dados *principal = NULL;

/* Cria a nova lista apontando o proximo no para NULL. */
Dados *inicia_dados(char *nome, int idade) {

        Dados *novo;

        novo = (Dados *)malloc(sizeof(Dados));
        novo->nome = (char *)malloc(strlen(nome)+1);
        strncpy(novo->nome, nome, strlen(nome)+1);
        novo->idade = idade;
        novo->proximo = NULL;

        return novo;
}

/* Como a lista nao esta mais vazia, apontamos o proximo no para lista anterior. */
Dados *insere_dados(Dados *dados, char *nome, int idade) {

        Dados *novo;

        novo = (Dados *)malloc(sizeof(Dados));
        novo->nome = (char *)malloc(strlen(nome)+1);
        strncpy(novo->nome, nome, strlen(nome)+1);
        novo->idade = idade;
        novo->proximo = dados;

        return novo;
}

/* Percorre todos os campos da lista e imprime ate o ponteiro proximo chegar em NULL. */
void exibe_dados(Dados *dados) {

        fprintf(stdout, "Cadastro De Pets:\n\n");

        fprintf(stdout, "------------------------\n");

        for (; dados != NULL; dados = dados->proximo) {
                fprintf(stdout, "Nome Do Pet: %s\n", dados->nome);
                fprintf(stdout, "Idade Do Pet: %d\n", dados->idade);
                fprintf(stdout, "------------------------\n ");
        }
        printf("Pressione uma tecla para continuar.");
        getch();
}

/* Percorre cada ponta comparando o nome com a chave. */
void busca_dados(Dados *dados, char *chave) {

        int achou = 0;

        fprintf(stdout, "Cadastro:\n\n");
        for (; dados != NULL; dados = dados->proximo) {
                if (strcmp(chave, dados->nome) == 0) {

                        fprintf(stdout, "------------------------\n");
                        fprintf(stdout, "Nome do Pet: %s\n", dados->nome);
                        fprintf(stdout, "Idade do Pet: %d\n", dados->idade);
                        fprintf(stdout, "------------------------\n");
                        achou++;
                }
        }

        if (achou == 0)
                fprintf(stdout, "Nenhum resultado encontrado.\nPressione uma tecla para continuar.\n");
        else
                fprintf(stdout, "Foram encontrados %d registros. \nPressione uma tecla para continuar.\n", achou);

        sleep(1);
        getch();
}

/* Deleta o ultimo registro inserido. */
Dados *deleta_dados(Dados *dados) {

        Dados *novo;

        novo = dados->proximo;

        free(dados->nome);
        free(dados);

        fprintf(stdout, "O ultimo registro inserido foi deletado com sucesso.\\n");
        sleep(1);

        return novo;
}

/* a pena checa se a lista e NULL ou nao. */
int checa_vazio(Dados *dados) {

        if (dados == NULL) {
                fprintf(stdout, "Lista vazia!\\n");
                sleep(1);
                return 1;
        } else
                return 0;
}

/* Obtem os dados necessarios para chamar as funcoes de manuseio de dados. */
void insere(void) {

        char *nome;
        int idade;

        nome = (char *)malloc(BUFFER);

        fprintf(stdout, "\n\nDigite o Nome Do Pet: \n----> ");
        scanf("%s", nome);
        fprintf(stdout, "\n");

        fprintf(stdout, "Digite a Idade Do Pet: \n----> ");
        scanf("%d", &idade);
        fprintf(stdout, "\n");

        if (principal == NULL)
                principal = inicia_dados(nome, idade);
        else
                principal = insere_dados(principal, nome, idade);
}

void exibe(void) {

        if (!checa_vazio(principal))
                exibe_dados(principal);

}

void busca(void) {

        char *chave;

        if (!checa_vazio(principal)) {

                chave = (char *)malloc(BUFFER);

                fprintf(stdout, "Digite o nome do pet que deseja buscar: \\n--> ");
                scanf("%s", chave);

                busca_dados(principal, chave);
                getch();
        }
}

void deleta(void) {

        if (!checa_vazio(principal))
                principal = deleta_dados(principal);
}

int main1(void) {

        char escolha;

        do {
                system("cls");
                fprintf(stdout, "\n MENU DE OPCOES\n\n");
                fprintf(stdout, "1 - Cadastro de Pet\n");
                fprintf(stdout, "2 - Exibir Dados do Pet Cadastrado\n");
                fprintf(stdout, "3 - Buscar Pets Cadastrados\n");
                fprintf(stdout, "4 - Excluir Pet\n");
                fprintf(stdout, "5 - Acessar PetShop\n");
                fprintf(stdout, "6 - Finalizar Sessao\n\n");

                scanf("%c", &escolha);

                switch(escolha) {
                        case '1':
                                insere();
                                break;

                        case '2':
                                exibe();
                                break;

                        case '3':
                                busca();
                                break;

                        case '4':
                                deleta();
                                break;

                        case '5':
                                return compras();
                                break;

                        case '6':
                                exit(0);
                                break;

                        default:
                                fprintf(stderr,"Aguarde Um Momento...\\n");
                                sleep(1);
                                break;
                }

                //getchar(); /* E para impedir sujeira na entrada da escolha. Nao lembro de nada melhor tambem.   */
        }

        while (escolha > 0); /* Loop Principal. */

        return 0;
}

int compras(void) {
  setlocale(LC_ALL, "Portuguese");
  int i = 0, escolha, escolha2;
  float valorracao=0, valorTotal=0,racao=0;
  int pagamento=0, coleiras=0, totalcoleiras=0, shampoo=0, totalshampoo=0;
  printf("\n\n");
  printf("------------------------------");
  printf("\n BEM VINDO AO NOSSO PETSHOP: \n");
  printf("------------------------------");
  printf("\n\n O que Deseja Adquirir? \n");
  printf("------------------------------ \n");

  printf(" Código \t");
  printf(" Produto \t \t");
  printf(" Preço \t\t\t" );
  printf(" Descrição \t\t\ \n" );
  printf(" 1 \t\t Ração \t\t\t R$10.9 por KG \t\t A melhor comida para seu pet \n");
  printf(" 2 \t\t Coleira\t\t R$40 reais \t\t Revestida de titanium, para pet de grande porte. \n");
  printf(" 3 \t\t Shampoo\t\t R$30 reais \t\t Com cheiro de castanhas do pará e quinoa. \n");
  printf(" 4 \t\t Banho\t\t R$35 reais \t\t Banho com Hidrataçao. \n");
  printf(" 5 \t\t Tosa\t\t R$45 reais \t\t Tosa simples. \n");
  printf(" 6 \t\t Banho e Tosa\t\t R$80 reais \t\t Tosa simples e Banho com Hidrataçao. \n");

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
      case 4:
        printf("Deseja comprar o serviço de Banho? \n");
        break;
      case 5:
        printf("Deseja comprar o serviço de Tosa? \n");
        break;
      case 6:
        printf("Deseja comprar o serviço de Banho e Tosa? \n");
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

  return main1();
}
