#include <stdio.h>
#include <iostream>

using namespace std;

//RECURSIVIDADE 

int f1(int n){
    if(n==0){
        return 1;
    }else{
        return n * f1(n-1); // Fatorial.
    }
}

int f2(int n){
    if(n==0){
        return 1;
    }else if(n==1){
        return 1;
    }else{
        return f2(n-1) + (2 * f2(n-2)); // retorna (n - 1) que é o termo anterior + duas vez (n-2), ou seja duas vezes o número de dois passos atrás.
    }
}

void f3(int n){
    if(n==0){
        cout << "zero" << endl;
    }else{
        cout << n;
        cout << n;
        cout << endl;
        f3(n-1); // imprime duas vezes o n, diminui 1 e volta o processo.
    }
}

int somadosN(int n){
    int f = 0;
    if(n==0){
        cout << "invalido" << endl;
        return 0;
    }else if(n==1){
        return 0;
    }else{
    	if(n%2==0){
			f = n + somadosN(n-2);
		}else{
			f = n-1 + somadosN(n-2);
		}
        return f;
    }
}

int produto(int n, int x){
	if(x == 1){
		return n;
	}else{
		return n + produto(n, x-1); // soma n a quantidade de vezes de x;
	}
}

void menufuncoes(){
	int escolha;
	int x;
	int y;
	cout << "------------------------------- FUNCOES RECURSIVAS -------------------------------------" << endl;

	while (true){
		
    cout << "QUAL OPCAO DESEJA?" << endl;
	cout << "1-FUNCAO 1\n2-FUNCAO 2\n3-FUNCAO 3\n4-SOMA DE TODOS OS INTEIROS PARES\n5-CALCULAR O PRODUTO DE DOIS NUMEROS" << endl;
	cin >> escolha;
	
	switch(escolha){
	case 1:
		cout << "DIGITE UM NUMERO:" << endl;
		cin >> x;
		cout << f1(x) << endl;
		break;
	case 2:
		cout << "DIGITE UM NUMERO:" << endl;
		cin >> x;
		cout << f2(x) << endl;
		break;
	case 3:
		cout << "DIGITE UM NUMERO:" << endl;
		cin >> x;
		f3(x);
		break;
	case 4:
		cout << "DIGITE UM NUMERO:" << endl;
		cin >> x;
		cout << somadosN(x) << endl;
		break; 
	case 5:
		cout << "DIGITE OS NUMEROS:" << endl;
		cin >> x;
		cin >> y;
		cout << produto(x, y) << endl;
		break;
	default:
		cout << "OPCAO INVALIDA!" << endl;
	}
	}
}

int main (){
	menufuncoes();
	return 0;	
}