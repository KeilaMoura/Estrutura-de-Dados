//PILHA

#include <iostream>

using namespace std;

typedef struct Reg{
	int info;
	Reg *prox;
}No;


typedef struct TipoPilha{
	No * topo;
	int tamanho;
}Pilha;

Pilha *inicializarpilha(Pilha *minhapilha){
	minhapilha = new Pilha;
	minhapilha -> topo = NULL;
	minhapilha -> tamanho = 0;
}

Pilha *inserirelemento(Pilha *minhapilha, int x){
	No *meuno;
	meuno = new No;
	meuno -> info = x;
	
	if(minhapilha -> topo == NULL){
		minhapilha -> topo = meuno;
		meuno -> prox = NULL; 
		minhapilha -> tamanho++;
	}else{
		meuno -> prox = minhapilha -> topo;
		minhapilha -> topo = meuno;
		minhapilha -> tamanho++;
	}
	return minhapilha;
}

Pilha *excluirelemento(Pilha *minhapilha){
	minhapilha -> topo = minhapilha -> topo -> prox;
	minhapilha -> tamanho--;
	cout << "ELEMENTO EXCLUIDO COM SUCESSO!" << endl;
	return minhapilha;
}

void imprimir(No *inicial){
	No *copia = inicial;
	if(inicial == NULL){
		cout << "PILHA VAZIA!" << endl;
	}else{
		while(copia != NULL ){
			cout << copia -> info << endl;
			copia = copia -> prox;
		}
	}
}

void verificar(No *inicial, int x){
	No *copia = inicial;
	if(inicial == NULL){
		cout << "PILHA VAZIA!" << endl;
	}else{
		while(copia != NULL ){
			if(copia -> info == x){
			cout << "ELEMENTO ENCONTRADO NA PILHA!" << endl;
			return;
		}
		copia = copia -> prox;
	}
	cout << "ELEMENTO NAO ENCONTRADO NA PILHA!" << endl;
}
}

void menupilha(){
	int escolha;
	int x;
	
	Pilha *minhapilha;
	minhapilha = inicializarpilha(minhapilha);

	cout << "------------------------------- PILHA -------------------------------------" << endl;
	while (true){
		
    cout << "QUAL OPCAO DESEJA?" << endl;
	cout << "1-INSERIR UM ELEMENTO\n2-EXCLUIR UM ELEMENTO\n3-MOSTRAR PILHA\n4-VERIFICAR SE O ELEMENTO ESTA NA PILHA" << endl;
	cin >> escolha;
	
	switch(escolha){
	case 1:
		cout << "DIGITE O ELEMENTO QUE DESEJA INSERIR:" << endl;
		cin >> x;
		inserirelemento(minhapilha, x);
		break;
	case 2:
		excluirelemento(minhapilha);
		break;
	case 3:
		imprimir(minhapilha -> topo);
		break;
	case 4:
		cout << "QUAL ELEMENTO DESEJA BUSCAR NA PILHA?" << endl;
		cin >> x;
		verificar(minhapilha -> topo, x);
		break;
	default:
		cout << "OPCAO INVALIDA!" << endl;
	}
	}
	
}

int main(){
	
	menupilha();
	
	return 0;
}