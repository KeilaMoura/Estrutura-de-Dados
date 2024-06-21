#include <iostream>

using namespace std;

typedef struct Reg{
	int info;
	Reg *prox;
}No;


typedef struct TipoFila{
	No * final;
	No * inicio;
	int tamanho;
}Fila;

Fila inicializar(Fila *minhafila){
	minhafila -> inicio = NULL;
	minhafila -> final = NULL;
	minhafila -> tamanho = 0;
}

Fila *inserirelementos(Fila *minhafila, int x){
	No *meuno;
	meuno = new No;
	meuno -> info = x;
	meuno -> prox = NULL;
	
	if(minhafila -> inicio == NULL){
		minhafila -> inicio = meuno;
		minhafila -> final = meuno;
	}else{
		minhafila -> final -> prox = meuno;
		minhafila -> final = meuno;
		meuno -> prox == NULL;
	}
	minhafila -> tamanho ++;
	return minhafila;
}

Fila *excluirelementos(Fila *minhafila){
	if(minhafila -> inicio == NULL){
		cout << "FILA VAZIA!" << endl;
	}else{
		minhafila -> inicio = minhafila -> inicio -> prox;
		minhafila -> tamanho --;
	}
	cout << "ELEMENTO EXCLUIDO COM SUCESSO!" << endl;
	return minhafila;
}

void imprimir(No *inicial){
	No *copia = inicial;
	if(inicial == NULL){
		cout << "LISTA VAZIA!" << endl;
	}else{
		while(copia != NULL){
			cout << copia -> info << endl;
			copia = copia -> prox;
		}
	}	
}

void verificar(No *inicial, int x){
	No *copia = inicial;
	if(inicial == NULL){
		cout << "LISTA VAZIA!" << endl;
	}else{
		while(copia != NULL){
			if(copia -> info == x){
				cout << "ELEMENTO ENCONTRADO NA FILA!" << endl;
				return;
			}
			copia = copia -> prox;
		}
		cout << "ELEMENTO NAO ENCONTRADO NA FILA!" << endl;
	}
}

void menufila(){
	int escolha;
	int x;
	
	Fila *minhafila;
	minhafila = new Fila;
	inicializar(minhafila);
	
	cout << "------------------------------- FILA -------------------------------------" << endl;

	while (true){
		
    cout << "QUAL OPCAO DESEJA?" << endl;
	cout << "1-INSERIR UM ELEMENTO\n2-EXCLUIR UM ELEMENTO\n3-MOSTRAR FILA\n4-VERIFICAR SE O ELEMENTO ESTA NA FILA" << endl;
	cin >> escolha;
	
	switch(escolha){
	case 1:
		cout << "DIGITE O ELEMENTO QUE DESEJA INSERIR:" << endl;
		cin >> x;
		inserirelementos(minhafila, x);
		break;
	case 2:
		excluirelementos(minhafila);
		break;
	case 3:
		imprimir(minhafila -> inicio);
		break;
	case 4:
		cout << "QUAL ELEMENTO DESEJA BUSCAR NA PILHA?" << endl;
		cin >> x;
		verificar(minhafila -> inicio, x);
		break;
	default:
		cout << "OPCAO INVALIDA!" << endl;
	}
	}
}

int main (){
	
	menufila();
	
	return 0;
	}

