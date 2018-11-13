#include "registros.h"
#include <stdio.h>

void caixa(){
	int aux, i;
	printf(" - - - CAIXA ABERTO - - - \n");
	printf(" \n1 - Nova venda.");
	printf(" \n\n2 - Consultar todas as vendas.\n");
	printf(" \n3 - Voltar.");
	scanf("%d",&aux);
	
	switch(aux){
		case 1:
			nova_venda();
		break;
	
		case 2:
			
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




