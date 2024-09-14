#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <cstdlib> 
#include <vector>
#include <sstream>

using namespace std;


void printEstoque() {
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
	cout << "#######  #####  ####### #######  #####  #     # ####### " << endl;
	cout << "#       #     #    #    #     # #     # #     # #       " << endl;
	cout << "#       #          #    #     # #     # #     # #       " << endl;
	cout << "#####    #####     #    #     # #     # #     # #####   " << endl;
	cout << "#             #    #    #     # #   # # #     # #       " << endl;
	cout << "#       #     #    #    #     # #    #  #     # #       " << endl;
	cout << "#######  #####     #    #######  #### #  #####  ####### " << endl;

	auto now = chrono::system_clock::now();
	time_t now_c = chrono::system_clock::to_time_t(now);
	tm local_tm;
	localtime_s(&local_tm, &now_c);
	cout << "\nLast login: " << put_time(&local_tm, "%a %b %d %H:%M:%S %Y") << " from 127.0.0.1\n";
}

/*
----vector<string>----
ifstream -> m�todo que carrega o arquivo produtos.txt, � realizada uma  verifica��o e caso haja um erro na abertura do arquivo, a condi��o retornar� um vetor vazio.
getline -> l� linha a linha do arquivo e adicionada cada linha ao vetor produtos por meio do m�todo push_back.
& -> garante que as altera��es sejam realiadas em uma refer�ncia do objeto arquivoTexto, sem o & seria uma c�pia do objeto. Ou seja, estou trabalhando com o endere�o de mem�ria da vari�vel em vez de uma c�pia dela tornando o algor�timo mais perform�tico.
Por fim retorna o vetor de produtos cadastrados no arquivo produtos.txt
*/
vector<string> carregarProdutos(const string& arquivoTexto) {
	vector<string> produtos;
	ifstream lerArquivo(arquivoTexto);
	if (!lerArquivo) {
		cerr << "Erro ao abrir o arquivo " << arquivoTexto << " !" << endl;
		return produtos;
	}
	string linha;
	while (getline(lerArquivo, linha)) {
		produtos.push_back(linha);
	}
	lerArquivo.close();
	return produtos;
}
/*
----salvarProdutos----
ofstream -> m�todo que abre o arquivo produtos.txt para escrever novos dados. O atributo ios::out garanque que os novos dados sejam salvos no arquivo.
if -> faz a verifica��o se o arquivo foi aberto corretamente, caso haja algum problema, retornar� vazio.
for -> corre o vetor produtos (para cada produto no vetor produtos) e o atributo auto permite que o compilador deduza o tipo da vari�vel produto a partir do vetor produtos
& -> garante que as altera��es sejam realiadas em uma refer�ncia do vetor, sem o & seria uma c�pia do vetor.
Por fim o m�todo .close() garante que o arquivo seja fechado corretamente
*/
void salvarProdutos(const vector<string>& produtos, const string& arquivoTexto) {
	ofstream salvarArquivo(arquivoTexto, ios::out);
	if (!salvarArquivo) {
		cerr << "Erro ao abrir o arquivo " << arquivoTexto << " !" << endl;
		return;
	}
	for (const auto& produto : produtos) {
		salvarArquivo << produto << endl;
	}
	salvarArquivo.close();

}

void cadastraProduto() {
	system("cls");
	string nomeArquivo = "dados/produtos.txt";
	vector<string> produtos = carregarProdutos(nomeArquivo);
	string descProduto;
	int qtyProduto;
	float precoProduto, pesoProduto;

	cin.ignore();
	cout << "Informe o nome do produto: ";
	getline(cin, descProduto);
	cout << "Informe a quantidade de produto: ";
	while (true) {
		cin >> qtyProduto;
		if (cin.fail()) {
			cin.clear();
			cout << "\nEntrada inv�lida. A quantidade de produto deve ter do tipo inteiro: ";
			string temp;
			cin >> temp; 
		}
		else {
			break;  
		}
	}
	cout << "Informe o pre�o do produto: ";
	while (true) {
		cin >> precoProduto;
		if (cin.fail()) {
			cin.clear();
			cout << "\nEntrada inv�lida. O preco do produto deve ter do tipo decimal: ";
			string temp;
			cin >> temp; 
		}
		else {
			break; 
		}
	}
	cout << "Informe o peso do produto: ";
	while (true) {
		cin >> pesoProduto;
		if (cin.fail()) {
			cin.clear();
			cout << "\nEntrada inv�lida. O peso do produto deve ter do tipo decimal: ";
			string temp;
			cin >> temp; 
		}
		else {
			break;  
		}
	}

	bool produtoExistente = false;

	for (auto& produto : produtos) {
		istringstream iss(produto);
		string descExistente, qtyExistenteStr, precoExistenteStr, pesoExistenteStr;
		if (getline(iss, descExistente, ';') &&
			getline(iss, qtyExistenteStr, ';') &&
			getline(iss, precoExistenteStr, ';') &&
			getline(iss, pesoExistenteStr, ';')) {

			if (descExistente == descProduto) {
				int quantidadeExistente = stoi(qtyExistenteStr);
				quantidadeExistente += qtyProduto;
				int pesoExistente = stoi(pesoExistenteStr);
				pesoExistente += pesoProduto;
				produto = descExistente + ";" + to_string(qtyProduto) + ";" + to_string(precoProduto) + ";" + 
					to_string(pesoProduto);
				produtoExistente = true;
				break;
			}
		}
	}
	if (!produtoExistente) {
		string novoProduto = descProduto + ";" + to_string(qtyProduto) + ';' + to_string(precoProduto) + ";" + 
			to_string(pesoProduto);
		produtos.push_back(novoProduto);
	}
	salvarProdutos(produtos, nomeArquivo);

	if (produtoExistente) {
		cout << "\nQuantidade atualizada para o produto " << descProduto << " existente.\n";
	}
	else {
		cout << "\nProduto " << descProduto << " cadastrado com sucesso! Consulte em: " << nomeArquivo << "\n";
	}
	cout << "\n\n";
	system("pause");
	system("cls");
}

vector<string> carregarFornecedores(const string& arquivoTexto) {
	vector<string> fornecedores;
	ifstream lerArquivo(arquivoTexto);
	if (!lerArquivo) {
		cerr << "Erro ao abrir o arquivo " << arquivoTexto << " !" << endl;
		return fornecedores;
	}
	string linha;
	while (getline(lerArquivo, linha)) {
		fornecedores.push_back(linha);
	}
	lerArquivo.close();
	return fornecedores;
}

void salvarFornecedores(const vector<string>& fornecedores, const string& arquivoTexto) {
	ofstream salvarArquivo(arquivoTexto, ios::out);
	if (!salvarArquivo) {
		cerr << "Erro ao abrir o arquivo " << arquivoTexto << " !" << endl;
		return;
	}
	for (const auto& fornecedor : fornecedores) {
		salvarArquivo << fornecedor << endl;
	}
	salvarArquivo.close();

}

void cadastraFornecedor() {
	system("cls");
	string nomeArquivo = "dados/fornecedores.txt";
	vector<string> fornecedores = carregarFornecedores(nomeArquivo);
	string nomeFornecedor, cnpjFornecedor;
	
	cin.ignore();
	cout << "\nInforme o nome do fornecedor: ";
	getline(cin, nomeFornecedor);
	cout << "Informe o CNPJ do fornecedor: ";
	getline(cin, cnpjFornecedor);
	
	bool fornecedorExistente = false;

	for (auto& fornecedor : fornecedores) {
		istringstream iss(fornecedor);
		string nomeFornecedorExistente, cnpjFornecedorExistente;
		if (getline(iss, nomeFornecedorExistente, ';') && getline(iss, cnpjFornecedorExistente, ';')) {
			if (nomeFornecedorExistente == nomeFornecedor && cnpjFornecedorExistente == cnpjFornecedor) {
				fornecedor = nomeFornecedorExistente + ";" + cnpjFornecedorExistente;
				fornecedorExistente = true;
				break;
			}
		}
	}
	if (!fornecedorExistente) {
		string novoFornecedor = nomeFornecedor + ";" + cnpjFornecedor;
		fornecedores.push_back(novoFornecedor);
	}
	salvarFornecedores(fornecedores, nomeArquivo);

	if (fornecedorExistente) {
		cout << "\nFornecedor " << nomeFornecedor << " j� existe na base de dados!" << endl;
	}
	else {
		cout << "\nFornecedor " << nomeFornecedor << " cadastrado com sucesso! Consulte em: " << nomeArquivo << endl;
	}
	cout << "\n\n";
	system("pause");
	system("cls");
}