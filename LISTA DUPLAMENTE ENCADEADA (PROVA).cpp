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

lista *percorrer(No *inicial, int x){
	No *copia = inicial;
	
	if(inicial == NULL || inicial -> info == x){
		if(inicial == NULL){
		cout << "ELEMENTO NAO ENCONTRADO, DIGITE NOVAMENTE:" << endl;
		return 0;
	}else{
	 	cout << "ELEMENTO ENCONTRADO!" << endl;
			}
		}else{
			return percorrer(inicial -> prox, x);		
	}
}

lista *inseririnicio(lista *minhalista, int x){
	No *meuno;
	meuno = new No;
	meuno -> info =x;
	meuno -> ant = NULL;
	meuno -> prox = NULL;
	if(percorrer(minhalista -> inicio, x) == 0){
	if(minhalista -> inicio == NULL){
		minhalista -> inicio = meuno;
		minhalista -> final = meuno;
	}else{
		meuno -> prox = minhalista -> inicio;
		minhalista -> inicio -> ant = meuno;
		minhalista -> inicio = meuno;
	}
	minhalista -> tamanho++;
	}
	return minhalista;
}

lista *inserirfinal(lista *minhalista, int x){
	No *meuno;
	meuno = new No;
	meuno -> info =x;
	meuno -> ant = NULL;
	meuno -> prox = NULL;
	
	
	if(minhalista -> inicio == NULL){
		minhalista -> inicio = meuno;
		minhalista -> final = meuno;
	}else{
		meuno -> ant = minhalista -> final;
		minhalista -> final -> prox = meuno;
		minhalista -> final = meuno;
	}
	minhalista -> tamanho++;
	return minhalista;
}

lista *inserirqualquer(lista *minhalista , int x, No *inicial, int y){
	No *meuno = new No;
	meuno -> info = y;
	No *copia = minhalista -> inicio;
	
	
	if(copia == NULL){
		cout << "LISTA VAZIA!" << endl;
	}else{
		while(copia != NULL){
			if(copia -> info == x){
				copia -> ant -> prox = meuno;
				meuno -> prox = copia ;
			}
			copia = copia -> prox;
		}
	}
	minhalista -> tamanho++;
	return minhalista;
}

void *imprimir(No *inicial){
	if(inicial == NULL){
		cout << "LISTA VAZIA!" << endl;
	}else{
		while(inicial != NULL){
			cout << inicial -> info << endl;
			inicial = inicial -> prox;
		}
	}
}

void tamanho(lista *minhalista){
	cout << "O TAMANHO DA LISTA E:" << endl;
	cout << minhalista -> tamanho << endl;
}

lista *excluirqualquer(lista *minhalista , int x, No *inicial){
	No *copia = inicial;
	
	if(percorrer(inicial, x) != 0){	
	if(copia == NULL){
		cout << "LISTA VAZIA!" << endl;
	}else{
		while(copia != NULL){
			if(copia -> info == x){
				copia -> ant -> prox = copia -> prox;
				copia -> prox -> ant = copia -> ant ;
			}
			copia = copia -> prox;
		}
	}
	minhalista -> tamanho--;
	}
	return minhalista;
}



void menudupla(){
	int escolha;
	int x;
	
	lista *minhalista;
	minhalista = new lista;
	inicializarlista(minhalista);
	
	cout << "------------------------------- LISTA DUPLAMENTE ENCADEADA-------------------------------------" << endl;

	while (true){
		
    cout << "QUAL OPCAO DESEJA?" << endl;
	cout << "1-INSERIR NO INICIO\n2-INSERIR NO FIM\n3-INSERIR EM QUALQUER POSICAO\n4-BUSCAR UM ELEMENTO\n5-MOSTRAR LISTA\n6-MOSTRAR TAMANHO DA LISTA\n7-EXCLUIR EM QUALQUER POSICAO" << endl;
	cin >> escolha;
	
	switch(escolha){
	case 1:
		cout << "DIGITE O ELEMENTO QUE DESEJA INSERIR:" << endl;
		cin >> x;
		inseririnicio(minhalista, x);
		break;
	case 2:
		cout << "DIGITE O ELEMENTO QUE DESEJA INSERIR:" << endl;
		cin >> x;
		inserirfinal(minhalista, x);
		break;
	case 3:
		cout << "DIGITE O ELEMENTO QUE DESEJA INSERIR:" << endl;
		int y;
		cin >> y;
		cout << "DESEJA INSERIR ANTES DE QUAL ELEMENTO?:" << endl;
		cin >> x;
		inserirqualquer(minhalista, x, minhalista -> inicio, y);
		break;
	case 4:
		cout << "DIGITE O ELEMENTO QUE DESEJA PROCURAR:" << endl;
		cin >> x;
	 	percorrer(minhalista -> inicio, x);
		break;
	case 5:
		imprimir(minhalista -> inicio);
		break;
	case 6:
		tamanho(minhalista);
		break;
	case 7:
		cout << "QUAL ELEMENTO DESEJA EXCLUIR?" << endl;
		cin >> x;
		excluirqualquer(minhalista, x, minhalista -> inicio);
		break;
	default:
		cout << "OPCAO INVALIDA!" << endl;
	}
	}
	
}
int main(){
	
	menudupla();
	return 0;
	
}
	