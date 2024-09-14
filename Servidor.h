#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

void printServidor() {
	system("cls");
	cout << "Welcome to Ubuntu 18.04.6 LTS (GNU/Linux 4.9.140-tegra aarch64)\n\n";
	cout << " * Documentation:  https://help.ubuntu.com\n";
	cout << " * Management:     https://landscape.canonical.com\n";
	cout << " * Support:        https://ubuntu.com/advantage\n";
	cout << "This system has been minimized by removing packages and content that are\n";
	cout << "not required on a system that users do not log into.\n\n";
	cout << "To restore this content, you can run the 'unminimize' command.\n\n";
	cout << "432 updates can be applied immediately.\n";
	cout << "248 of these updates are standard security updates.\n";
	cout << "To see these additional updates run: apt list --upgradable\n\n";
	cout << "#####  ####### ######  #     # ### ######  ####### ######  " << endl;
	cout << "#     # #       #     # #     #  #  #     # #     # #     # " << endl;
	cout << "#       #       #     # #     #  #  #     # #     # #     # " << endl;
	cout << " #####  #####   ######  #     #  #  #     # #     # ######  " << endl;
	cout << "      # #       #   #    #   #   #  #     # #     # #   #   " << endl;
	cout << "#     # #       #    #    # #    #  #     # #     # #    #  " << endl;
	cout << " #####  ####### #     #    #    ### ######  ####### #     # " << endl;
	auto now = chrono::system_clock::now();
	time_t now_c = chrono::system_clock::to_time_t(now);
	tm local_tm;
	localtime_s(&local_tm, &now_c);
	cout << "\nLast login: " << put_time(&local_tm, "%a %b %d %H:%M:%S %Y") << " from 127.0.0.1\n";
}
//@TODO
void reportProdutos() {
	string nomeArquivo = "dados/produtos.txt";
	vector<string> produtos = carregarProdutos(nomeArquivo);
	for (auto& produto : produtos) {
		istringstream iss(produto);
		string descExistente, qtyExistenteStr, precoExistenteStr, pesoExistenteStr;
		if (getline(iss, descExistente, ';') &&
			getline(iss, qtyExistenteStr, ';') &&
			getline(iss, precoExistenteStr, ';') &&
			getline(iss, pesoExistenteStr, ';')) {
			system("cls");
			cout << descExistente << " " << qtyExistenteStr << " " << precoExistenteStr << " " << pesoExistenteStr;
		}
	}
	cout << "\n\n";
	system("pause");
	system("cls");
}
//@TODO
//void reportVendas() {}

void reportForncedores() {
	string nomeArquivo = "dados/fornecedores.txt";
	vector<string> fornecedores = carregarClientes(nomeArquivo);
	string nomeFornecedor, cnpjFornecedor;
	for (auto& fornecedor : fornecedores) {
		istringstream iss(fornecedor);
		string nomeFornecedorExistente, cnpjFornecedorExistente;
		if (getline(iss, nomeFornecedorExistente, ';') && getline(iss, cnpjFornecedorExistente, ';')) {
			system("cls");
			cout << nomeFornecedorExistente << " " << cnpjFornecedorExistente << endl;
			break;
		}
	}
	cout << "\n";
	system("pause");
	system("cls");
}
void reportClientes() {
	string nomeArquivo = "dados/clientes.txt";
	vector<string> clientes = carregarClientes(nomeArquivo);
	string nomeCliente, cpfCliente;
	for (auto& cliente : clientes) {
		istringstream iss(cliente);
		string nomeClienteExistente, cpfClienteExistente;
		if (getline(iss, nomeClienteExistente, ';') && getline(iss, cpfClienteExistente, ';')) {
			system("cls");
			cout << nomeClienteExistente << " " << cpfClienteExistente << endl;
			break;
		}
	}
	cout << "\n";
	system("pause");
	system("cls");
}
