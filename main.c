//*********************************************************************************\\
//  UNIFACS - UNIVERSIDADE SALVADOR                                                \\
//                                                                                 \\
//  DESENVOLVIDO POR: LUCAS GUIMARÃES, AlEXANDRE JESUS, VANESSA BATISTA            \\
//                    141171081        144171067         019172024                 \\
//  																			   \\
// MATÉRIA: TÉCNICA DE PROGRAMAÇÃO  											   \\
//*********************************************************************************\\

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "registros.h"

main(){
	setlocale(LC_ALL,"portuguese");
	int entrada_menu;
	printf(" - - - CAIXA VIRTUAL / LOJA FACSNILDA - - - \n");
	printf(" \n1 - Clientes.");
	printf(" \n\n2 - Abrir Caixa.\n");
	scanf("%d",&entrada_menu);
	system("cls");
	menu(entrada_menu);
}

void menu(int entrada_menu_g){
	int i;
	if (entrada_menu_g==1){
		ficha();
	}
	else if(entrada_menu_g==2){
		caixa();
	}
	
	else{
		for(i=3;i>0;i--){
			system("cls");
			printf(" - - - Opção Inválida! - - -\n ");
			printf("\n O sistema vai te encaminhar para o menu inicial -> Em: %d SEGUNDOS! ", i);
			Sleep(1000);
		}
		system("cls");
		main();
	}
}
