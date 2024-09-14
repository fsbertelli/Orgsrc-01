/* Orgs.cpp : Interface Servidor -> Gerenciamendo de informações e entrega de relatórios
			  rltVendas ->
			  rltEstoque ->
			  rltFornecedores ->
			  rltClientes ->
*/
#include <iostream>
#include "Header.h"
#include "Caixa.h"
#include "Estoque.h"
#include "Servidor.h"  

int main()
{
	system("cls");
	setlocale(LC_ALL, "portuguese");
	char chosen = 0;
	do {
		system("cls");
		header();
		cout << "\nCHOOSE YOUR STATION:\n\n1 - SERVIDOR\n2 - CAIXA\n3 - ESTOQUE\n0 - FECHAR APLICACAO\n" << endl;
		cin >> chosen;
		char option = 0;
		switch (chosen)
		{
		case '1':
			printServidor();
			do {
				cout << "\n\n\nSELECIONE A OPCAO DESEJADA:\n\n1 - GERAR RELATORIO DE ESTOQUE\n2 - GERAR RELATORIO DE VENDAS\n3 - GERAR LISTA DE FORNECEDORES\n4 - GERAR LISTA DE CLIENTES\n0 - VOLTAR AO MENU PRINCIPAL\n" << endl;
				cin >> option;
				switch (option)
				{
				case '1':
					reportProdutos();
					break;
				case '2':
					cout << "\nGerar relatorio de vendas";
					break;
				case '3':
					reportForncedores();
					break;
				case '4':
					reportClientes();
					break;
				case '0':
					system("cls");
					break;
					main();
				default:
					cout << "\nOPCAO INVALIDA! TENTE NOVAMENTE!\n";
					Sleep(500);
					system("cls");
					printServidor();
					break;
				}

			} while (option != '0');
		break;
		case '2':
			printCaixa();
			do {
				cout << "\n\n\nSELECIONE A OPCAO DESEJADA:\n\n1 - EFETUAR VENDA\n2 - CADASTRAR CLIENTE\n0 - VOLTAR AO MENU PRINCIPAL\n" << endl;
				cin >> option;
				switch (option)
				{
				case '1':
					cout << "\nEfetuar Venda";
					break;
				case '2':
					cadastraClientes();
					break;
				case '0':
					system("cls");
					break;
					main();

				default:
					cout << "\nOPCAO INVALIDA! TENTE NOVAMENTE!\n";
					Sleep(500);
					system("cls");
					printCaixa();
					break;
				}
			} while (option != '0');
		break;
		case '3':
			printEstoque();
			do {
				cout << "\n\n\nSELECIONE A OPCAO DESEJADA:\n\n1 - CADASTRAR PRODUTO\n2 - CADASTRAR FORNECEDOR\n0 - VOLTAR AO MENU PRINCIPAL\n" << endl;
				cin >> option;
				switch (option)
				{
				case '1':
					cadastraProduto();
					break;
				case '2':
					cadastraFornecedor();
					break;
				case '0':
					system("cls");
					break;
					main();
				default:
					cout << "\nOPCAO INVALIDA! TENTE NOVAMENTE!\n";
					Sleep(500);
					system("cls");
					printEstoque();
					break;
				}
			} while (option != '0');
		break;
		case '0':
			cout << "\nAPLICACAO ENCERRADA PELO USUARIO!\n";
			break;
		default:
			cout << "\nOPCAO INVALIDA! TENTE NOVAMENTE!\n";
			Sleep(500);
			break;
		}
	} while (chosen != '0');
}
//cadastraCliente();



