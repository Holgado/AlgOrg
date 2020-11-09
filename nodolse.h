#ifndef NODOLSE_H_INCLUDED
#define NODOLSE_H_INCLUDED
#include<iostream>
#include<string>
using namespace std;
class NodoLSE{
public:
	string nome;
	NodoLSE* prox;
public:
	NodoLSE(string nome){
		this->nome = nome;
		this->prox = NULL;
	}

	string getNome(){
		return nome;
	}

	NodoLSE* getProx(){
		return prox;
	}

	void setProx(NodoLSE* p){
		prox = p;
	}
};

#endif // NODOLSE_H_INCLUDED