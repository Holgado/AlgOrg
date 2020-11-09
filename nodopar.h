#ifndef NODOPAR_H_INCLUDED
#define NODOPAR_H_INCLUDED

class NodoPAR{
private:
	string par1;
	string par2;
	NodoPAR* prox;
public:
	NodoPAR(string par1, string par2){
		this->par1 = par1;
		this->par2 = par2;
		this->prox = NULL;
	}
   /* void setPar1(string p1){
        this->par1 = p1;
    }
	void setPar1(string p2){
        this->par2 = p2;
    }*/

	string getPar1(){
		return par1;
	}
    string getPar2(){
        return par2;
    }
	NodoPAR* getProx(){
		return prox;
	}

	void setProx(NodoPAR* p){
		prox = p;
	}
};

#endif // NODOPAR_H_INCLUDED