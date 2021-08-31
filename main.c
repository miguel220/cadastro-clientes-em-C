#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct pedido
{
	char namePed[200];
	char CPF[200];
	char qtdPed[200];
	char valorPed[200];
	int cod;
}logP[200];

struct cadastro
{
	char CPF[200];
	char telefone[200];
	char nome[200];
	char endereco[200];
	char data[200];
	int vazio, cod;
	struct pedido clientePed;
}logC[200];

//funções que seram usadas
int verifica_pos(void);
int verifica_cod(int cod);
int opt;
void cadastroP(int cod, int pos);
void list();
void cadastroPedido();
void consultaCod(void);
void excluirCliente(void);

int main(void) {
	
	int i,Opcao,OpcaoCliente,posicao, retorno;
	int codaux;
	
	do
	{
		printf("1 - Cadastrar novo cliente\n");
		printf("2 - Cliente\n");
		printf("3 - Alerear cliente\n");
		printf("4 - Excluir cliente\n");
		printf("5 - Cadastrar pedido\n");
		printf("6 - Alerar pedido\n");
		printf("7 - Excluir pedido\n");
		printf("8 - Sair\n");
		printf("Selecione uma opção por favor: ");
		scanf("%d", &Opcao);
		getchar();
		
		if(Opcao == 1)
		{
			printf("Você selecionou a opçao 1 - Cadastrar novo cliente\n");	
			posicao = verifica_pos();
			
			if(posicao != -1)
			{
				printf("\nEntre com um codigo de 1 a 200 para seu cadastro:\n");
				scanf("%d",&codaux);fflush(stdin);
				
				retorno = verifica_cod(codaux);
				
				if(retorno == 1)
				{
					cadastroP(codaux, posicao);
					
				}else{
					printf("\nCodigo já existente ou invalido pressione enter para voltar ao menu principal\n");
					getchar();
					
					system("cls");
					
					main();
				}
			}else{
				printf("\nNão é possivel realizar mais cadastros\n");
				
				break;
			}
		}else if(Opcao==2){
			system("cls");
			
			do
			{
				printf("Você selecionaou a opção 2 - Clientes\n\n");
				printf("1 - Pesquisar cliente por codigo\n");
				printf("2 - Listar todos os clientes\n");
				printf("3 - Voltar ao menu principal\n");
				printf("Selecione umaopçao por favor:");
				scanf("%d", &OpcaoCliente);
				getchar();
				
				if(OpcaoCliente == 1)
				{
					consultaCod();
				}
				else if(OpcaoCliente == 2)
				{
					list();
				}else if(OpcaoCliente == 3)
				{
					printf("Você selecionou voltar ao menu principal, pressione Enter para continuar");
					getchar();
					
					system("cls");
				}else
				printf("Opção Invalida\n\n");
			}while(OpcaoCliente =! 3 || OpcaoCliente > 3 || OpcaoCliente< 0 || OpcaoCliente==0);
		}else if(Opcao == 3)
		{
			printf("Você selecionou a opção 3 - Alterar cliente\n");
		}else if (Opcao == 4)
       	{

           printf("Voce selecionou a opcao 4 - Excluir Cliente\n");

           excluirCliente();
       	}else if (Opcao == 5)
       	{

           printf("Voce selecionou a opcao 5 - Cadastrar pedido\n");

           cadastroPedido();
           
       	}else if (Opcao == 6)
       	{
       	
           printf("Voce selecionou a opcao 6 - Alterar pedido\n");
           
       	}else if (Opcao == 7)
       	{

           printf("Voce selecionou a opcao 7 - Excluir pedido\n");
           
       	}else if (Opcao == 8)
       	{

           printf("Voce selecionou a opcao 8 - Sair\n");
           
           break;
       	}else
		   {
		   	printf("Opção invalida, favor pressionar Enter para voltar ao menu principal");
		   	
		   	getchar();
		   	
		   	system("cls");
		   }
	}while(Opcao != 8 || Opcao<8);
}
//Inicio do metodo de listagem

void list()
{
	int i, j;
	
	for(i=0;i<200;i++)
	{
		if(!logC[i].cod)
		{
			printf("\nCodigo: %d\nNome: %s\nCPF: %s\nEndereço: %s\nTelefone: %s\n\n",
			logC[i].cod, logC[i].nome, logC[i].CPF, logC[i].endereco, logC[i].telefone);
		}
	}
	printf("Pressione Enter para voltar ao menu principal");
	
	getchar();
	
	system("cls");
}
//Inicio do metodo de cadastro
void cadastroP(int cod, int pos)
{
	int i;
	do
	{
		pos= verifica_pos();
		logC[pos].cod= cod;
		
		printf("\nDigite seu nome: ");
		gets(logC[pos].nome);
		
		printf("\nDigite seu CPF: ");
		gets(logC[pos].CPF);
		
		printf("\nDigite seu Endereço: ");
		gets(logC[pos].endereco);
		
		printf("\nDigite seu Telefone: ");
		gets(logC[pos].telefone);
		
		logC[pos].vazio=1;
		
		printf("\n Tecle Enter para efetuar novo cadastro");
		scanf("%d",&opt);
		
		opt==1;
		
		getchar();
	}while(opt==1);
	
	system("cls");
	
	main();
}

// inicio verifica posição
int verifica_pos(void)
{
	int cont= 0;
	
	while(cont<=200)
	{
		if(logC[cont].vazio==0)
			return(cont);
			
		cont++;
	}
	
	return(-1);
}

//inicio verifica codigo
int verifica_cod(int cod)
{
	int cont = 0;
	
	while(cont<=200)
	{
		if(logC[cont].cod==cod)
			return(0);
			
		cont++;
	}
	
	return(1);
}

//inicio cadastro de pedidos
void cadastroPedido()
{
	system("cls");
	
	int i;
	
	int Option;
	
	int OpcaoPedido;
	
	char nomeCad[200];
	
	printf("\nDigite seu nome como esta no cadastro: ");
	
	gets(nomeCad);
	
	for(i=0;i<200;i++){
		
		if(strcmp(logC[i].nome, nomeCad)==0){
			
			do{
				printf("\nEscolha o seu pedido:");
				
				printf("\n1-Sanduba esperto");
				
				printf("\n2- Ceasar Salad");
				
				printf("\n3 - Raviolli\n");
				
				if(OpcaoPedido==1){
					
					strcpy(logC[i].clientePed.namePed, "Sanduba esperto");
					
					printf("\nVocê escolheu %s, seu pedido foi adicionado ao seu cadastro.", logC[i].clientePed.namePed);
					
					printf("\nPressione 1 para continuar pedindo ou 2 para voltar ao meu principal:");
					
					scanf("%d", &Option);
					
					i++;
				}else if(OpcaoPedido==2){
					
					strcpy(logC[i].clientePed.namePed, "Ceasar Salad");
					
					printf("\nVocê escolheu %s, seu pedido foi adicionado ao seu cadastro.", logC[i].clientePed.namePed);
					
					printf("\nPressione 1 para continuar pedindo ou 2 para coltar ao menu principal");
					
					scanf("%d", &Option);
					
					i++;
				}else if(OpcaoPedido==3){
					
					strcpy(logC[i].clientePed.namePed, "Raviolli");
					
					printf("\nVocê escolheu %s, seu pedido foi adicionado ao seu cadastro.", logC[i].clientePed.namePed);
					
					printf("\nPressione 1 para continuar pedindo ou 2 para coltar ao menu principal");
					
					scanf("%d", &Option);
					
					i++;
				}
			}while(Option==1);
			
			system("cls");
		}
	}
}

//Consultar 1 cadastro qualquer via codigo dado pelo usuario.

void consultaCod(void){
	
	int cont = 0, cod;
	
	printf("\nEntre com o codigo\n");
	
	scanf("%d",&cod);
	
	fflush(stdin);
	
	system("cls");
	
	
	while(cont<=200)
	{
		if(logC[cont].cod==cod)
		{
			if(logC[cont].vazio==1){
				
				printf("\nCodigo: %d \nNome: %s \nCPF: %s \nEndereço: %s \nTelefone: %s \n\n",
				logC[cont].cod, logC[cont].nome, logC[cont].CPF, logC[cont].endereco, logC[cont].telefone);
				
				system("pause");
				
				system("cls");
				
				break;
			}
		}
		cont++;
		
		if(cont>200){
			printf("\nCodigo não encontrado, pressione enter para voltar ao menu principal\n");
			
			getchar();
			
			system("cls");
		}
	}
}

//Inicio do metodo para excluir cliente.
void excluirCliente(void){
	
	int cod, cont=0;
	
	char resp;
	
	printf("\nEntr com o codigo do registro que deseja exlcluir: \n");
	
	scanf("%d",&cod);
	
	while(cont <= 200){
		
		if(logC[cont].cod == cod){
			
			if(logC[cont].vazio == 1){
				
				printf("\nCodigo: %d \nNome: %s \nCPF: %s \nEndereço: %s \nTelefone: %s \n\n",
				logC[cont].cod, logC[cont].nome, logC[cont].CPF, logC[cont].endereco, logC[cont].telefone);
				
				getchar();
				
				printf("\nDeseja realmente excluir? s/n:");
				
				scanf("%s",&resp);
				
				if((resp == 's' || (resp == 'S'))){
					
					logC[cont].vazio = 0;
					
					logC[cont].cod = 0;
					
					printf("\nExclusão feita com sucesso\n");
					
					break;
				}else{
					
					if((resp == 'n' || (resp == 'N'))){
						
						printf("Exclusão cancelada!\n");
						
						break;
					}
					
				}
			}
		}
		
		cont++;
		
		if(cont>200)
			printf("\nCodigo não encontrado\n");
	}
	
	system("pause");
	
	system("cls");
}










