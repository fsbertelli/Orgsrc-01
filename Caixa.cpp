#include <iostream>
#include <fstream>

using namespace std;

void efetuarVenda() {
    ofstream outFile("vendas.txt", ios::app);
    string codCliente, nomeCliente, codProduto, descProduto;
    int qtyProduto, total = 0;
    cout << "efetuarVenda\n";
    cout << "Informe o código do produto: ";
    cin >> codProduto;
    cout << "Informe a quantidade do produto: ";
    cin >> qtyProduto;
    total = qtyProduto * 1;
    if (!outFile) {
        cerr << "Falha ao registrar venda.";
    }
    outFile << codCliente << "," << nomeCliente << "," << codProduto << "," << descProduto << "," << qtyProduto << "," << total << endl;
    outFile.close();
    cout << "Venda registrada com sucesso no arquivo vendas.txt" << endl;
    //TODO Listar produto e buscar o preço qty * price
}

