/* Orgs.cpp : Interface Servidor -> Gerenciamendo de informações e entrega de relatórios
              rltVendas -> 
              rltEstoque ->
              rltFornecedores -> 
              rltClientes ->
*/
#include <iostream>
#include "Caixa.h"
#include "Estoque.h"
#include "Header.h"



int main()
{
    header();
    int chosen;
    setlocale(LC_ALL, "portuguese");
    cout << "\nCHOOSE YOUR STATION:\n\n1 - SERVIDOR\n2 - CAIXA\n3 - ESTOQUE" << endl;
    cin >> chosen;
    switch (chosen)
    {
    case 1:
        printCaixa();
    default:
        break;
    }
    //cadastraCliente();
    
}

