// LISTA ENCADEADA
#include <iostream>

using namespace std;

typedef struct Reg{
	int info;
	Reg *prox;
}no;

typedef struct lista{
	no *inicio;
	no *fim;	
}listaa;

listaa *inicializar(listaa *minhalista){
	minhalista = new listaa;
	minhalista -> inicio = NULL;
	minhalista -> fim = NULL;
	
	return minhalista;
}

listaa *inseririnicio(listaa *minhalista, int x){
	no *meuno;
	meuno = new no;
	meuno -> info = x;
	
	if(minhalista -> inicio == NULL){
		meuno -> prox = NULL;
		minhalista -> inicio = meuno;
		minhalista -> fim = meuno;
	}else{
		meuno -> prox = minhalista -> inicio;
		minhalista -> inicio = meuno;
	}
	return minhalista;
}

listaa *inserirfinal(lista *minhalista, int x){
	no *meuno;
	meuno = new no;
	meuno -> info = x;
		
	if(minhalista -> inicio == NULL){
		minhalista -> fim = meuno;
		minhalista -> inicio = meuno;
		meuno -> prox = NULL;
	}else{ 
		minhalista -> fim -> prox  = meuno;
		minhalista -> fim = meuno;
		meuno -> prox = NULL;
	}
	return minhalista;
}

listaa *percorrer(no *inicial, int x){
	no *copia = inicial;
	
	if(inicial == NULL || inicial -> info == x){
		if(inicial == NULL){
		cout << "ELEMENTO NAO ENCONTRADO" << endl; // se minha lista estiver vazia.
		return 0;
	}else{
	 	cout << "ELEMENTO ENCONTRADO!" << endl; // se a informa��o do primeio n� for igual a x;
			}
		}else{
			return percorrer(inicial -> prox, x); // chama a fun��o e manda o pr�ximo.		 
	}
}

void imprimirlista(no *inicial){
	no *copia = inicial;
	if(inicial == NULL){ // Se meu in�cio for nulo, nada ser� mostrado na tela.
		
	}else{
		if(copia != NULL){
			cout << copia -> info << endl; // imprimo meu n� inicial e chamo a fun��o mandando o pr�ximo, vou imprimindo todas as vezes.
			imprimirlista(copia -> prox);
		}
	}
}

listaa *excluirinicio(lista *minhalista){
	
	if(minhalista -> inicio == NULL){
		cout << "LISTA VAZIA!" << endl; 
	}else{
         minhalista -> inicio = minhalista -> inicio -> prox; // meu in�cio receber� o pr�ximo.
		 cout << "ELEMENTO EXCLUIDO COM SUCESSO!" << endl;
		 }
		 return minhalista;
		}

listaa *excluirfinal(no *inicial, lista *minhalista){
	no *meuno;
	meuno = new no;
	meuno = inicial;
	
	if(minhalista -> inicio == NULL){
		cout << "LISTA VAZIA!" << endl;
	}else{
		while(meuno != NULL){
   			if(meuno -> prox != NULL && meuno-> prox -> prox == NULL){ // meu n� anda at� o pr�ximo do seu  pr�ximo ser nulo, ou seja, o final
				   minhalista -> fim = meuno; // fa�o minha lista receber meu pen�ltimo elemento.
				   meuno -> prox = NULL; // o pr�ximo do meu pen�ltimo agora � nulo, removendo meu antigo final.
			   cout << "ELEMENTO EXCLUIDO COM SUCESSO!" << endl;
			   }
			   meuno = meuno -> prox; // percorrer.
			   }
			   
	}
	return minhalista;
	}

void menuencadeadarec(){
	int escolha;
	int x;
	
	
	listaa *minhalista;
	minhalista = inicializar(minhalista);
	
	cout << "------------------------------- LISTA SIMPLESMENTE ENCADEADA COM RECURSIVIDADE -------------------------------------" << endl;

	while (true){
		
    cout << "QUAL OPCAO DESEJA?" << endl;
	cout << "1-INSERIR NO INICIO\n2-INSERIR NO FIM\n3-BUSCAR UM ELEMENTO\n4-MOSTRAR LISTA\n5-EXCLUIR UM ELEMENTO NO INICIO DA LISTA\n6-EXCLUIR UM ELEMENTO NO FIM DA LISTA" << endl;
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
		cout << "DIGITE O ELEMENTO QUE DESEJA PROCURAR:" << endl;
		cin >> x;
	 	percorrer(minhalista -> inicio, x);
		break;
	case 4:
		imprimirlista(minhalista -> inicio);
		break;
	case 5:
		excluirinicio(minhalista);
		break;
	case 6:
		excluirfinal(minhalista -> inicio, minhalista);
	default:
		cout << "OPCAO INVALIDA!" << endl;
	}
	}
}





int main (){
	
	menuencadeadarec();
	return 0;
	}
	






