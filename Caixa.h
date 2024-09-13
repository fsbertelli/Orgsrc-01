#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <cstdlib> 
#include <vector>
#include <sstream>

using namespace std;

void printCaixa() {
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
    cout << " #####     #    ###  #     #    #    \n";
    cout << "#     #   # #    #   #   #    # #    \n";
    cout << "#        #   #   #    # #    #   #   \n";
    cout << "#       #     #  #     #    #     #  \n";
    cout << "#       #######  #    # #   #######  \n";
    cout << "#     # #     #  #   #   #  #     #  \n";
    cout << " #####  #     # ### #     # #     #  \n";

    auto now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);
    tm local_tm;
    localtime_s(&local_tm, &now_c);
    cout << "\nLast login: " << put_time(&local_tm, "%a %b %d %H:%M:%S %Y") << " from 127.0.0.1\n";
}

vector<string> carregarClientes(const string& arquivoTexto) {
	vector<string> clientes;
	ifstream lerArquivo(arquivoTexto);
	if (!lerArquivo) {
		cerr << "Erro ao abrir o arquivo " << arquivoTexto << " !" << endl;
		return clientes;
	}
	string linha;
	while (getline(lerArquivo, linha)) {
		clientes.push_back(linha);
	}
	lerArquivo.close();
	return clientes;
}

void salvarClientes(const vector<string>& clientes, const string& arquivoTexto) {
	ofstream salvarArquivo(arquivoTexto, ios::out);
	if (!salvarArquivo) {
		cerr << "Erro ao abrir o arquivo " << arquivoTexto << " !" << endl;
		return;
	}
	for (const auto& fornecedor : clientes) {
		salvarArquivo << fornecedor << endl;
	}
	salvarArquivo.close();

}

void cadastraClientes() {
	system("cls");
	string nomeArquivo = "dados/clientes.txt";
	vector<string> clientes = carregarClientes(nomeArquivo);
	string nomeCliente, cpfCliente;

	cin.ignore();
	cout << "\nInforme o nome do cliente: ";
	getline(cin, nomeCliente);
	cout << "Informe o CPF do cliente: ";
	getline(cin, cpfCliente);

	bool clienteExistente = false;

	for (auto& cliente : clientes) {
		istringstream iss(cliente);
		string nomeClienteExistente, cpfClienteExistente;
		if (getline(iss, nomeClienteExistente, ';') && getline(iss, cpfClienteExistente, ';')) {
			if (nomeClienteExistente == nomeCliente && cpfClienteExistente == cpfCliente) {
				cliente = nomeClienteExistente + ";" + cpfClienteExistente;
				clienteExistente = true;
				break;
			}
		}
	}
	if (!clienteExistente) {
		string novoCliente = nomeCliente + ";" + cpfCliente;
		clientes.push_back(novoCliente);
	}
	salvarClientes(clientes, nomeArquivo);

	if (clienteExistente) {
		cout << "\Cliente " << nomeCliente << " já existe na base de dados!" << endl;
	}
	else {
		cout << "\Cliente " << nomeCliente << " cadastrado com sucesso! Consulte em: " << nomeArquivo << endl;
	}
	Sleep(3000);
	system("cls");
}
