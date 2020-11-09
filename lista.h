#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

class Lista
{
private:
	NodoLSE* cabeca; // primeiro elemento
	NodoLSE* cauda; // último elemento

public:
	Lista(){
		cabeca = NULL;
		cauda = NULL;
	}

	Lista(string nome){
		cabeca = new NodoLSE(nome);
		cauda = cabeca;
	}
    NodoLSE* getCabeca(){
        return cabeca;
    }
    NodoLSE* getCauda(){
        return cauda;
    }
	virtual ~Lista() // destrutor
	{
		delete cabeca;
	}

	void mostrar() // mostra todos os elementos da lista
	{
		NodoLSE* c = cabeca;

		if(vazia())
			cout << "A lista NAO possui elementos!!\n\n";
		else
		{
			while(c){
				cout << c->getNome() << endl;
				c = c->getProx();
			}
		}
	}
    void remover_final()
	{
		if(!vazia())
		{
			if(cabeca->getProx() == NULL)
				cabeca = NULL;
			else if(cabeca->getProx()->getProx() == NULL)
				cabeca->setProx(NULL);
			else
			{
				NodoLSE* ant_ant = cabeca;
				NodoLSE* ant = cabeca->getProx();
				NodoLSE* corrente = cabeca->getProx()->getProx();

				while(corrente)
				{
					NodoLSE* aux = ant;
					ant = corrente;
					ant_ant = aux;
					corrente = corrente->getProx();
				}
				delete ant_ant->getProx();
				ant_ant->setProx(NULL);
				cauda = ant_ant;
			}
		}
	}


	int remover(string dado){
        NodoLSE *ptr, *antes;
        if(vazia()){
            return 0;
        }
        else{
            ptr = cabeca;
            antes = cabeca;
            while(ptr){
                if(ptr->nome == dado){
                   if(ptr == cabeca){
                        cabeca = cabeca->getProx();
                        delete ptr;
                        return 1;
                   }else{
                        antes->prox = ptr->prox;
                        delete ptr;
                        return 1;
                   }
                }
                   else{
                        antes = ptr;
                        ptr = ptr->prox;
                   }
                }
                  return 0;
            }
        }
    int tamanho(){
		if(vazia())
			return 0;

		NodoLSE* c = cabeca;
		int tam = 0;
		do{
			c = c->getProx();
			tam++;
		}while(c);

		return tam;
	}

	bool vazia(){
		return (cabeca == NULL);
	}
	void inserir_final(string e)
	{
		NodoLSE* no = new NodoLSE(e);
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

#endif // LISTA_H_INCLUDED