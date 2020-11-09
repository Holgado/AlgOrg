#ifndef LISTAPARES_H_INCLUDED
#define LISTAPARES_H_INCLUDED
#include "nodopar.h"

class ListaPares
{
private:
	NodoPAR* cabeca;
	NodoPAR* cauda;

public:
	ListaPares(){
		cabeca = NULL;
		cauda = NULL;
	}

	ListaPares(string par1, string par2){
		cabeca = new NodoPAR(par1,par2);
		cauda = cabeca;
    }
    NodoPAR* getCabeca(){
        return cabeca;
    }

	virtual ~ListaPares() // destrutor
	{
		delete cabeca;
	}

	void mostrar() // mostra todos os elementos da lista
	{
		cout << "\nLISTA DE PARES INCOMPATIVEIS:\n";
		NodoPAR* no = cabeca;

		if(vazia())
			cout << "A lista NAO possui elementos!!\n\n";
		else
		{
			while(no){
				cout << no->getPar1() << " e " << no->getPar2() << endl;
				no = no->getProx();
			}
		}
	}

	bool vazia(){
		return (cabeca == NULL);
	}
	void inserir_final(string par, string par2)
	{
		NodoPAR* no = new NodoPAR(par, par2);
		if(vazia()){
			cabeca = no;
			cauda = no;
		}
		else{
			cauda->setProx(no);
			cauda = no;
		}
	}
};

#endif // LISTAPARES_H_INCLUDED