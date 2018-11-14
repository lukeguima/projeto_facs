struct compra{
	char data[10];
	float valor;
	float valor_parcelas;
	int parcelas;
	int cliente;
}compra[5];

struct banco_de_dados{
	int vendas_total;
}banco;

// validador = 101 = ficha cadastrada

struct ficha_cliente{
	char nome[50];
	int idade;
	char endereco[30];
	char cpf[15];
	int validador;
	int compras[10];
}ficha_cliente[50];
