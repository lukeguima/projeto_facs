void consulta_ficha(int aux_ficha_g){
	
	system("cls");
	printf(" - - - FICHA DO CLIENTE: %s / LOJA FACSNILDA - - - \n", ficha_cliente[aux_ficha_g].nome);
	printf("\n DADOS DO CLIENTE:");
	printf("\n\n Ficha cadastrada no código: %d", aux_ficha_g);
	printf("\n\n Nome do cliente: %s", ficha_cliente[aux_ficha_g].nome);
	printf("\n\n Idade do cliente: %d", ficha_cliente[aux_ficha_g].idade);
	printf("\n\n Endereço do cliente: %s", ficha_cliente[aux_ficha_g].endereco);
	printf("\n\n CPF do cliente: %d", ficha_cliente[aux_ficha_g].cpf);
	printf("\n\n__________________________________________________________________\n");
	printf("\n\n COMPRAS REALIZADAS:");
	
}
