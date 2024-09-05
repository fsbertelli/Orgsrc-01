/* Orgs.cpp : Interface Servidor -> Gerenciamendo de informações e entrega de relatórios
              rltVendas -> 
              rltEstoque ->
              rltFornecedores -> 
              rltClientes ->
*/
#include <iostream>
#include "Estoque.h"


int main()
{
    int chosen;
    setlocale(LC_ALL, "portuguese");
    cout << "ORGS SSH SERVER/CLIENT - CHOOSE YOUR STATION:\n\n1 - SERVIDOR\n2 - CAIXA\n3 - ESTOQUE" << endl;
    cin >> chosen;
    switch (chosen)
    {
    case 1:
        cout << "SERVER";
    default:
        break;
    }
    //cadastraCliente();
    
}

