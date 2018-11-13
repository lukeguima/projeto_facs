void cadastro_ficha(int aux_ficha){
	int i;
	system("cls");
	printf(" - - - CADASTRO DE CLIENTE / FICHA SELECIONADA: %d - - - \n", aux_ficha);
	
	printf("\n Digite o nome do cliente: ");
	getchar();
	gets(ficha_cliente[aux_ficha].nome);
	
	printf("\n Digite a idade do cliente: ");
	scanf("%d",&ficha_cliente[aux_ficha].idade);

	printf("\n Digite o endereço do cliente: ");
	getchar();
	gets(ficha_cliente[aux_ficha].endereco);

	printf("\n Digite o CPF do cliente: ");
	scanf("%d",&ficha_cliente[aux_ficha].cpf);
	
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
