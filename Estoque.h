#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <cstdlib> 
#include <vector>
#include <sstream>
#include <iomanip> // Para std::fixed e std::setprecision

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
ifstream -> método que carrega o arquivo produtos.txt, é realizada uma  verificação e caso haja um erro na abertura do arquivo, a condição retornará um vetor vazio.
getline -> lê linha a linha do arquivo e adicionada cada linha ao vetor produtos por meio do método push_back.
& -> garante que as alterações sejam realiadas em uma referência do objeto arquivoTexto, sem o & seria uma cópia do objeto. Ou seja, estou trabalhando com o endereço de memória da variável em vez de uma cópia dela tornando o algorítimo mais performático.
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
ofstream -> método que abre o arquivo produtos.txt para escrever novos dados. O atributo ios::out garanque que os novos dados sejam salvos no arquivo.
if -> faz a verificação se o arquivo foi aberto corretamente, caso haja algum problema, retornará vazio.
for -> corre o vetor produtos (para cada produto no vetor produtos) e o atributo auto permite que o compilador deduza o tipo da variável produto a partir do vetor produtos
& -> garante que as alterações sejam realiadas em uma referência do vetor, sem o & seria uma cópia do vetor.
Por fim o método .close() garante que o arquivo seja fechado corretamente
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
	string nomeArquivo = "produtos.txt";
	vector<string> produtos = carregarProdutos(nomeArquivo);
	string descProduto, codProduto;
	int qtyProduto;
	float precoProduto, pesoProduto;

	cout << "\nInforme o código do produto: " << endl;
	cin >> codProduto;
	cout << "Informe a descrição do produto: " << endl;
	cin >> descProduto;
	cout << "Informe a quantidade de produto: " << endl;
	while (true) {
		cin >> qtyProduto;
		if (cin.fail()) {
			cin.clear();
			cout << "\nEntrada inválida. A quantidade de produto deve ter do tipo inteiro: ";
			string temp;
			cin >> temp; 
		}
		else {
			break;  
		}
	}

	cout << "Informe o preço do produto: " << endl;
	while (true) {
		cin >> precoProduto;
		if (cin.fail()) {
			cin.clear();
			cout << "\nEntrada inválida. O preco do produto deve ter do tipo decimal: ";
			string temp;
			cin >> temp; 
		}
		else {
			break; 
		}
	}
	cout << "Informe o peso do produto: " << endl;
	while (true) {
		cin >> pesoProduto;
		if (cin.fail()) {
			cin.clear();
			cout << "\nEntrada inválida. O peso do produto deve ter do tipo decimal: ";
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
		string codExistente, descExistente, qtyExistenteStr, precoExistenteStr, pesoExistenteStr;
		if (getline(iss, codExistente, ';') &&
			getline(iss, descExistente, ';') &&
			getline(iss, qtyExistenteStr, ';') &&
			getline(iss, precoExistenteStr, ';') &&
			getline(iss, pesoExistenteStr, ';')) {

			if (descExistente == descProduto) {
				int quantidadeExistente = stoi(qtyExistenteStr);
				quantidadeExistente += qtyProduto;
				int pesoExistente = stoi(pesoExistenteStr);
				pesoExistente += pesoProduto;
				produto = codExistente + ";" + descExistente + ";" + to_string(qtyProduto) + ";" + to_string(precoProduto) + ";" + 
					to_string(pesoProduto);
				produtoExistente = true;
				break;
			}
		}
	}
	if (!produtoExistente) {
		string novoProduto = codProduto + ";" + descProduto + ";" + to_string(qtyProduto) + ';' + to_string(precoProduto) + ";" + 
			to_string(pesoProduto);
		produtos.push_back(novoProduto);
	}
	salvarProdutos(produtos, nomeArquivo);

	if (produtoExistente) {
		cout << "\nQuantidade atualizada para o produto " << descProduto << " existente.\n";
	}
	else {
		cout << "\nProduto " << descProduto << " cadastrado com sucesso!\n";
	}
	Sleep(3000);
	system("cls");
}




