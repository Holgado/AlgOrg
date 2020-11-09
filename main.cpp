#include "nodolse.h"
#include "lista.h"
#include "listapares.h"
#include<stdio.h>

#include <typeinfo>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

string menu(){ //Funcao para imprimir um menu para ver o programa executando no melhor caso e no pior caso
    int op=0;
    string type;
    do {
    cout << "Digite uma opcao de lista de aluno: \n\n"
            "1 - Lista de estudantes pequena.\n"
            "2 - Lista de estudantes media.\n"
            "3 - Lista de estudante grande.\n"
            "Opcao: ";

    cin >> op;

    switch(op){
    case 1:
        type = "lista_pequena.txt";
        return type;
    case 2:
        type = "lista_media.txt";
        return type;
    case 3:
        type = "lista_grande.txt";
        return type;
    default:
        cerr << "Opcao invalida: "<< endl;
        break;
    }
    }while(op);
    return "erro";
}

void selecionados(int tam, Lista L, ListaPares Lp, int n){
    //ALGORITMO PARA SABER QUEM VAI MORAR NA CASA !!!
    Lista ListaSelecionados;
   	int vet[n];  //Vetor com o numero de pessoas que nao podem ficar juntas
   	int j;
    for(j = 0;j < n;j++){
        	vet[j] = 0;
    }
   	int i = 0;
    string aux, selc;
    string temp[100];
    NodoLSE* no;
    NodoPAR* nop;
    no = L.getCabeca();
    nop = Lp.getCabeca();
    j = 0;
    int axu = 0;
    while(no){
        aux = no->getNome();
        while(nop){
            if(nop->getPar1() == aux){
               axu = axu + 1;
               vet[j] = axu;
            }
            else if(nop->getPar2() == aux){
                axu = axu +1;
                vet[j]= axu;
            }
            nop = nop->getProx();
        }
        nop = Lp.getCabeca();
        axu = 0;
        j++;
        no= no->getProx();
    }
    no = L.getCabeca();
    nop = Lp.getCabeca();

    while(no){
        selc = no->getNome();
         if(vet[i] <= tam){
            while(nop){
                if(nop->getPar1() == selc){
                    temp[j] = nop->getPar2();
                }
                else if(nop->getPar2() == selc){
                    temp[j] = nop->getPar1();
                }
                j++;
                nop=nop->getProx();
            }

            for (int x = 0;x < 100;x++){
                if(selc == temp[x])
                    L.remover(selc);
            }
        }
        else{
            L.remover(no->getNome());
        }
        i++;
        no = no->getProx();
    }
    while(L.tamanho() > tam){ //remove candidatos selecionados mas nao ha vagas na casa
        L.remover_final();
    }
    L.mostrar(); //Mostra lista de selecionados
}

int menu2(){
    int x;
    cout << "Digite o numero de dormitorios da casa: ";
    cin >> x;
    return x;
}

int main(){
    int tam = 0;
    string op, cabecalho, nome;
    ifstream arq;
    op = menu();

    Lista L;
    ListaPares Lp;

    if(op == "erro"){
        cerr << "Type invalid" << endl;
        return 0;
    }
    tam = menu2();
    arq.open(op,ios::in);
    if(!arq.is_open()){
        cout << "Falha na abertura do arquivo " << op << ". Terminando " << endl;
        return 0;
    }
    int n;
    string n_convive1, n_convive2;
    getline(arq, cabecalho);
    arq >> nome >> n_convive1 >> n_convive2;
    while (!arq.eof()){
        L.inserir_final(nome);              //cria a lista de estudantes
        Lp.inserir_final(nome, n_convive1); //cria lista de pares
        Lp.inserir_final(nome, n_convive2);
        arq >> nome >> n_convive1 >> n_convive2;
    }
    arq.close();
    cout << "LISTA DE ESTUDANTES..." << endl;
    L.mostrar();
    Lp.mostrar();
    n = L.tamanho(); // Quantidade de etudantes da casa

    cout << "\nLISTA DE SELECIONADOS PARA A CASA..." << endl;

    selecionados(tam,L,Lp,n);

}

