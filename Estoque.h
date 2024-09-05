#include <iostream>
#include <locale.h>
#include <fstream>
#include <string> 

using namespace std;

void cadastraFornecedor() {
    ofstream outFile("fornecedores.txt", ios::app);
    string nomeFornecedor, codFornecedor, cnpjFornecedor;
    cout << "------------------------\n";
    cout << "|Cadastro de Fornecedor|\n";
    cout << "------------------------\n";
    cout << "Informe o código do Fornecedor: ";
    cin >> codFornecedor;
    cout << "Informe o nome do Fornecedor: ";
    cin >> nomeFornecedor;
    cout << "Informe o CNPJ do Fornecedor: ";
    cin >> cnpjFornecedor;
    if (!outFile) {
        cerr << "Falha ao cadastrar fornecedor." << endl;
    }
    outFile << codFornecedor << "," << nomeFornecedor << "," << cnpjFornecedor << endl;
    outFile.close();
    cout << "\nO fornecedor registrado com sucesso no arquivo fornecedores.txt" << endl;
}
void cadastraCliente() {
    ofstream outFile("clientes.txt", ios::app);
    string nomeCliente, codCliente, cpfCliente;
    cout << "Cadastro de Cliente\n";
    cout << "Informe o código do Cliente (Histograma Face Recognition): ";
    cin >> codCliente;
    cout << "Informe o nome do  Cliente: ";
    cin >> nomeCliente;
    cout << "Informe o CPF do cliente: ";
    cin >> cpfCliente;
    if (!outFile) {
        cerr << "Falha ao cadastrar cliente." << endl;
    }
    outFile << codCliente << "," << nomeCliente << "," << cpfCliente << endl;
    outFile.close();
    cout << "\nO cliente registrado com sucesso no arquivo clientes.txt" << endl;
}
void cadastraProduto() {
    ofstream outFile("produtos.txt", ios::app);
    cout << "cadastraProduto\n";
    int qtyProduto, precoProduto;
    string descProduto, codProduto;
    cout << "Informe o código do produto: ";
    cin >> codProduto;
    cout << "Informe a descrição do produto: ";
    cin >> descProduto;
    cout << "Informe a quantidade de produto: ";
    cin >> qtyProduto;
    cout << "Informe o preço do produto: ";
    cin >> precoProduto;
    if (!outFile) {
        cerr << "Falha ao cadastrar produto." << endl;
    }
    outFile << codProduto << "," << descProduto << "," << qtyProduto << "," << precoProduto << endl;
    outFile.close();
    cout << "\nO produto registrado com sucesso no arquivo produtos.txt" << endl;
}

void menu() {
    while (true) {
        int option;
        cout << "\nBem vindo ao sistema Hortis!\n\n";
        cout << "Informe via teclado a opcao desejada.\n\n";
        cout << "1 - Cadastro de Fornecedor.\n2 - Cadastro de Cliente.\n3 - Cadastro de Produto\n0 - Sair da aplicacao.\n";
        cin >> option;
        if (!option) {
            exit(0);
        }
        else {
            switch (option) {
            case 1:
                cadastraFornecedor();
                break;
            case 2:
                cadastraCliente();
                break;
            case 3:
                cadastraProduto();
                break;
            }
        }
    }
}
#pragma once
