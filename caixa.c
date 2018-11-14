#include "registros.h"
#include <stdio.h>

void caixa(){
	int aux, i;
	printf(" - - - CAIXA ABERTO - - - \n");
	printf(" \n1 - Nova venda.");
	printf(" \n\n2 - Total de vendas.\n");
	printf(" \n3 - Voltar.");
	scanf("%d",&aux);
	
	switch(aux){
		case 1:
			nova_venda();
		break;
	
		case 2:
			consulta_vendas();
		break;
	
		case 3:
			system("cls");
			main();
		break;
	
		default:
			for(i=3;i>0;i--){
				system("cls");
				printf(" - - - Opção Inválida! - - -\n ");
				printf("\n O sistema vai te encaminhar para o menu inicial -> Em: %d SEGUNDOS! ", i);
				Sleep(1000);
			}
			system("cls");
			main();
		break;
	}


}

void nova_venda(){
	int aux_venda, aux_op, op, i;
	float venda_bruta;

	system("cls");
	printf(" - - - CAIXA ABERTO - - - \n");
	printf("\n\n Para realizar uma nova venda, digite o código do cliente: ");
	scanf("%d",&op);
	
	if(ficha_cliente[op].validador==101){
		system("cls");
		banco.vendas_total++;
		aux_venda=banco.vendas_total;
		printf(" - - - NOVA VENDA / FICHA SELECIONADA: %d - - - \n", op);
		printf("\n Digite a data: ");
		fflush(stdin);
		gets(compra[aux_venda].data);

		printf("\n Digite o valor do produto: ");
		scanf("%f",&venda_bruta);
	
		printf("\n Informe a quantidade de parcelas que deseja dividir: ");
		scanf("%d",&compra[aux_venda].parcelas);	
		
		compra[aux_venda].valor=venda_bruta;
		compra[aux_venda].valor_parcelas=venda_bruta/compra[aux_venda].parcelas;
		compra[aux_venda].cliente=op;
	
		for(i=3;i>0;i--){
		system("cls");
		printf(" - - - VENDA REALIZADA COM SUCESSO! - - -");
		printf("\n\n O sistema vai te encaminhar para o caixa -> Em: %d SEGUNDOS! ", i);
		Sleep(1000);
		}
		system("cls");
		caixa();
	}
	else{
		system("cls");
		printf(" - - - NOVA VENDA / FICHA SELECIONADA: %d - - - \n", op);
		printf("\n\n O código: %d não possui uma ficha cadastrada!", op);
		printf("\n\n * Para cadastrar uma ficha no código: %d, DIGITE 1!", op);
		printf("\n\n * Para voltar ao caixa, DIGITE 2!");
		printf("\n\n * Para voltar ao menu principal, DIGITE 3!\n");
		printf("\n\n__________________________________________________________________\n");
		scanf("%d",&aux_op);
		
		switch(aux_op){
			case 1:
				system("cls");
				cadastro_ficha(op);
			break;
			
			case 2:
				system("cls");
				caixa();
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
  		  }
	}
}

void consulta_vendas(){
	int i=1, aux=0, op, x;
	float total_money;
	
	system("cls");
	printf(" - - - TOTAL DE VENDAS / LOJA FACSNILDA - - - \n");
	while(i<=banco.vendas_total){
		aux++;
		printf("\n\n Código da compra: %d  - Código do cliente: %d - Nome: %s. ", i, compra[i].cliente, ficha_cliente[compra[i].cliente].nome);
		total_money=compra[i].valor+total_money;
		i++;
	}
	printf("\n\n\n - TOTAL DE VENDAS REALIZADAS: %d", aux);
	printf("\n\n - VALOR LIQUIDO DAS VENDAS REALIZADAS: %0.2f", total_money);
	printf("\n\n__________________________________________________________________\n");
	printf("\n\n = AÇOES =  \n");
	printf("\n\n * Para voltar ao caixa, DIGITE 1!");
	printf("\n\n * Para voltar ao menu principal, DIGITE 2!");
	scanf("%d",&op);
		if(op==1){
			system("cls");
			caixa();
		}
		else if(op==2){
			system("cls");
			main();
		}
		else{
			for(x=3;x>0;x--){
				system("cls");
				printf(" - - - Opção Inválida! - - -\n ");
				printf("\n O sistema vai te encaminhar para o menu inicial -> Em %d SEGUNDOS! ", i);
				Sleep(1000);
			}	
			system("cls");
			main();
		}
}



