#include "registros.h"
#include <stdio.h>

void ficha(){
	int aux_ficha, aux_consulta, i;
	printf(" - - - CONSULTAR CLIENTE / LOJA FACSNILDA - - - \n");
	printf("\n1 - Consultar ficha de cliente. \n");
	printf("\n2 - Cadastrar ficha de cliente.\n");
	printf("\n3 - Voltar.\n");
	scanf("%d",&aux_consulta);
	system("cls");
		
	switch(aux_consulta){
		case 1:
			printf(" - - - CONSULTAR FICHA DE CLIENTE / LOJA FACSNILDA - - - \n");
			printf("\n\n Código da ficha: ");
			scanf("%d",&aux_ficha);
			system("cls");
			entrada_ficha_consulta(aux_ficha);
		break;
		case 2:
			printf(" - - - CADASTRAR FICHA DE CLIENTE / LOJA FACSNILDA - - - \n");
			printf("\n Código da ficha: ");
			scanf("%d",&aux_ficha);
			system("cls");
			entrada_ficha_cadastro(aux_ficha);
		break;
		case 3:
			system("cls");
			main();
		break;
		default:
			system("cls");
			printf(" - - - Opção Inválida! - - -\n ");
			printf("\n O sistema vai te encaminhar para o menu inicial -> Em %d SEGUNDOS! ", i);
			Sleep(1000);
			system("cls");
			main();
		break;
	}
}

void entrada_ficha_consulta(int entrada_g){
	int aux, i;
	
	if(ficha_cliente[entrada_g].validador==101){
		consulta_ficha(entrada_g);
	}

	else{
		printf(" - - - CONSULTA FICHA DE CLIENTE / LOJA FACSNILDA - - - \n");
		printf("\n\n O código: %d não possui uma ficha cadastrada!", entrada_g);
		printf("\n\n * Para cadastrar uma ficha no código: %d, DIGITE 1!", entrada_g);
		printf("\n\n * Para voltar na consulta de clientes, DIGITE 2!");
		printf("\n\n * Para voltar ao menu principal, DIGITE 3!\n");
		printf("\n\n__________________________________________________________________\n");
		scanf("%d",&aux);
		
		switch(aux){
			case 1:
				system("cls");
				cadastro_ficha(entrada_g);
			break;
			
			case 2:
				system("cls");
				ficha();
			break;
			
			case 3:
				system("cls");
				main();
			
			default:
				for(i=3;i>0;i--){
					system("cls");
					printf(" - - - Opção Inválida! - - -\n ");
					printf("\n O sistema vai te encaminhar para o menu inicial -> Em %d SEGUNDOS! ", i);
					Sleep(1000);
				}	
				system("cls");
				main();
			break;
  		  }
	}
}

void entrada_ficha_cadastro(int entrada_g){
	
	int aux;
	if(ficha_cliente[entrada_g].validador!=101){
		cadastro_ficha(entrada_g);
	}
	else{
		printf(" - - - CADASTRAR FICHA DE CLIENTE / LOJA FACSNILDA - - - \n");
		printf("\n\n O código: %d já possui uma ficha cadastrada!", entrada_g);
		printf("\n\n Nome do cliente: %s", ficha_cliente[entrada_g].nome);
		printf("\n\n CPF do cliente: %d", ficha_cliente[entrada_g].cpf);
		printf("\n\n * Para visualizar todos os dados do cliente, DIGITE 1!");
		printf("\n\n * Para voltar a consulta de clientes, DIGITE 2!");
		printf("\n\n * Para voltar ao menu principal, DIGITE 3!\n");
		printf("\n\n__________________________________________________________________\n");
		scanf("%d",&aux);
		if(aux==1){
			consulta_ficha(entrada_g);
		}
		else if(aux==2){
			system("cls");
			ficha();
		}
		else{
			system("cls");
			main();
		}
	}
}

void consulta_ficha(int aux_ficha_g){
	int aux, i=0, x;
	
	system("cls");
	printf(" - - - FICHA DO CLIENTE: %s / LOJA FACSNILDA - - - \n", ficha_cliente[aux_ficha_g].nome);
	printf("\n\n = DADOS DO CLIENTE =  \n");
	printf("\n\n Código da ficha: %d", aux_ficha_g);
	printf("\n\n Nome do cliente: %s", ficha_cliente[aux_ficha_g].nome);
	printf("\n\n Idade do cliente: %d", ficha_cliente[aux_ficha_g].idade);
	printf("\n\n Endereço do cliente: %s", ficha_cliente[aux_ficha_g].endereco);
	printf("\n\n CPF do cliente: %s", ficha_cliente[aux_ficha_g].cpf);
	printf("\n\n__________________________________________________________________\n");
	printf("\n\n = COMPRAS REALIZADAS =  \n");
	while(i<=banco.vendas_total){
		if(compra[i].cliente==aux_ficha_g){
			printf("\n\n Código da compra: %d", i);
			printf("\n\n Data da compra: %s", compra[i].data);
			printf("\n\n Total da compra: %0.2f", compra[i].valor);
			printf("\n\n Quantidade de parcelas da compra: %d", compra[i].parcelas);
			printf("\n\n\n = VALOR DAS PARCELAS = \n");
			for(x=1;x<=compra[i].parcelas;x++){
				printf("\n\n - Parcela %d: %0.2f", x, compra[i].valor_parcelas);
			}
			printf("\n\n ");
			printf("\n- - - - - - - - - - - - - - \n");
		}
		i++;
	}
	printf("\n\n__________________________________________________________________\n");
	printf("\n\n = AÇOES =  \n");
	printf("\n\n * Para alterar a ficha do cliente, DIGITE 1!");
	printf("\n\n * Para voltar a consulta de clientes, DIGITE 2!");
	printf("\n\n * Para voltar ao menu principal, DIGITE 3!\n");
	scanf("%d",&aux);
		if(aux==1){
			system("cls");
			alterar_ficha(aux_ficha_g);
		}
		else if(aux==2){
			system("cls");
			ficha();
		}
		else{
			system("cls");
			main();
		}
	
}

void cadastro_ficha(int aux_ficha){
	int i;
	system("cls");
	printf(" - - - CADASTRO DE CLIENTE / FICHA SELECIONADA: %d - - - \n", aux_ficha);
	
	printf("\n Digite o nome do cliente: ");
	fflush(stdin);
	gets(ficha_cliente[aux_ficha].nome);
	
	printf("\n Digite a idade do cliente: ");
	scanf("%d",&ficha_cliente[aux_ficha].idade);

	printf("\n Digite o endereço do cliente: ");
	fflush(stdin);
	gets(ficha_cliente[aux_ficha].endereco);

	printf("\n Digite o CPF do cliente: ");
	fflush(stdin);
	gets(ficha_cliente[aux_ficha].cpf);
	
	ficha_cliente[aux_ficha].validador=101;

	for(i=5;i>0;i--){
		system("cls");
		printf(" - - - CADASTRO REALIZADO COM SUCESSO! - - -");
		printf("\n\n O sistema vai te encaminhar para o menu inicial -> Em: %d SEGUNDOS! ", i);
		Sleep(1000);
	}
	system("cls");
	main();
}

void alterar_ficha(int aux_ficha){
	int op, i, aux;
	
	printf(" - - - ALTERAÇÃO FICHA DO CLIENTE: %s / LOJA FACSNILDA - - - \n", ficha_cliente[aux_ficha].nome);
	printf("\n\n * SELECIONE O NÚMERO DO CAMPO PARA A ALTERAÇÃO:   \n");
	printf("\n\n 1 - Nome do cliente: %s", ficha_cliente[aux_ficha].nome);
	printf("\n\n 2 - Idade do cliente: %d", ficha_cliente[aux_ficha].idade);
	printf("\n\n 3 - Endereço do cliente: %s", ficha_cliente[aux_ficha].endereco);
	printf("\n\n 4 - CPF do cliente: %d\n", ficha_cliente[aux_ficha].cpf);
	scanf("%d",&op);
	printf("\n\n__________________________________________________________________\n");
	
	switch(op){
		case 1:
			printf("\n\n ALTERAR O NOME DO CLIENTE:");
			printf("\n\n ATUAL: %s", ficha_cliente[aux_ficha].nome);
			printf("\n\n NOVO: ");
			fflush(stdin);
			gets(ficha_cliente[aux_ficha].nome);
		break;
		
		case 2:
			printf("\n\n ALTERAR A IDADE DO CLIENTE:");
			printf("\n\n ATUAL: %d", ficha_cliente[aux_ficha].idade);
			printf("\n\n NOVO: ");
			scanf("%d",&ficha_cliente[aux_ficha].idade);
		break;
		
		case 3:
			printf("\n\n ALTERAR O ENDEREÇO:");
			printf("\n\n ATUAL: %s", ficha_cliente[aux_ficha].endereco);
			printf("\n\n NOVO: ");
			fflush(stdin);
			gets(ficha_cliente[aux_ficha].endereco);
		break;
		
		case 4:
			printf("\n\n ALTERAR O CPF:");
			printf("\n\n ATUAL: %d", ficha_cliente[aux_ficha].cpf);
			printf("\n\n NOVO: ");
			scanf("%d",&ficha_cliente[aux_ficha].cpf);
	}
		printf("\n\n PARA ATUALIZAR A FICHA, DIGITE 1!");
		printf("\n\n PARA VOLTAR AO MENU PRINCIPAL, DIGITE 2!");
		scanf("%d",&aux);
		
		if(aux==1){
			for(i=3;i>0;i--){
			system("cls");
			printf("\n ATUALIZANDO A FICHA!  -> Em %d SEGUNDOS! ", i);
			Sleep(1000);
			}
			consulta_ficha(aux_ficha);
		}	
		else if(aux==2){
			main();
		}
		else{
			for(i=3;i>0;i--){
					system("cls");
					printf(" - - - Opção Inválida! - - -\n ");
					printf("\n O sistema vai te encaminhar para o menu inicial -> Em %d SEGUNDOS! ", i);
					Sleep(1000);
				}	
				system("cls");
				main();
		}
}

