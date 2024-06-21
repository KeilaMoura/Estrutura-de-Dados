#include <iostream>

using namespace std;

typedef struct Reg{
	int info;
	Reg *ant;
	Reg *prox;
}No;


typedef struct Tipolista{
	No * final;
	No * inicio;
	int tamanho;
}lista;

lista *inicializarlista(lista *minhalista){
	minhalista -> inicio = NULL;
	minhalista -> final = NULL;
	minhalista -> tamanho = 0;
}

lista *inseririnicio(lista *minhalista, int x, No *inicial){
	No *meuno;
	meuno = new No;
	meuno -> info =x;
	meuno -> ant = NULL;
	meuno -> prox = NULL;
	
	if(minhalista -> inicio == NULL){
		minhalista -> inicio = meuno;
		minhalista -> final = meuno;
	}else{
		meuno -> prox = minhalista -> inicio;
		minhalista -> inicio -> ant = meuno;  
		minhalista -> inicio = meuno;
		minhalista -> final -> prox = minhalista -> inicio;	
		minhalista -> inicio -> ant = minhalista -> final;
	}
	minhalista -> tamanho++;
	return minhalista;
}

lista *excluirinicio(lista *minhalista){
	
	if(minhalista -> inicio == NULL){
		cout << "LISTA VAZIA!" << endl;
	}if(minhalista -> inicio == minhalista -> final){
		minhalista -> inicio = NULL;
		minhalista -> final = NULL;
	}else{
		minhalista -> inicio = minhalista -> inicio -> prox;
		minhalista -> final -> prox = minhalista -> inicio;
		minhalista -> inicio -> ant = minhalista -> final;
	}
	minhalista -> tamanho--;
	
	return minhalista;
}

void *imprimir(No *inicial, lista *minhalista){
	inicial = minhalista -> inicio;
	if(inicial == NULL){
		cout << "LISTA VAZIA!" << endl;
	}else{
		while(inicial != NULL){
			cout << inicial -> info << endl;
			inicial = inicial -> prox;
			if(inicial == minhalista -> inicio){
				break;
			}
		}
		
	}
}

void menucircular(){
	int escolha;
	int x;
	
	lista *minhalista;
	minhalista = new lista;
	inicializarlista(minhalista);
	
	cout << "------------------------------- LISTA CIRCULAR -------------------------------------" << endl;

	while (true){
		
    cout << "QUAL OPCAO DESEJA?" << endl;
	cout << "1-INSERIR NO INICIO\n2-EXCLUIR NO INICIO\n3-MOSTRAR LISTA" << endl;
	cin >> escolha;
	
	switch(escolha){
	case 1:
		cout << "DIGITE O ELEMENTO QUE DESEJA INSERIR:" << endl;
		cin >> x;
		inseririnicio(minhalista, x, minhalista -> inicio);
		break;
	case 2:
		excluirinicio(minhalista);
		break;
	case 3:
		imprimir(minhalista -> inicio, minhalista);
		break;
	default:
		cout << "OPCAO INVALIDA!" << endl;
	}
	}
	
}

int main (){
	menucircular(); 
}