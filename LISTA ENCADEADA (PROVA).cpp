#include <iostream>

using namespace std;

typedef struct Reg
{
	int info;
	Reg *prox;
} no;

typedef struct lista
{
	no *inicio;
	no *fim;
	int tam;
} listaa;


	// ------------------------------ LISTA SIMPLESMENTE ENCADEADA ------------------------------
	listaa *inicializar(listaa * minhalista)
	{
		minhalista = new listaa;
		minhalista->inicio = NULL;
		minhalista->fim = NULL;
		minhalista->tam = 0;

		return minhalista;
	}

	listaa *inseririnicio(listaa * minhalista, int x)
	{
		no *meuno;
		meuno = new no;
		meuno->info = x;

		if (minhalista->inicio == NULL)
		{
			meuno->prox = NULL;
			minhalista->inicio = meuno;
			minhalista->fim = meuno;
		}
		else
		{
			meuno->prox = minhalista->inicio;
			minhalista->inicio = meuno;
		}
		minhalista->tam++;
		return minhalista;
	}

	listaa *inserirfinal(lista * minhalista, int x)
	{
		no *meuno;
		meuno = new no;
		meuno->info = x;

		if (minhalista->inicio == NULL)
		{
			minhalista->fim = meuno;
			minhalista->inicio = meuno;
			meuno->prox = NULL;
		}
		else
		{
			minhalista->fim->prox = meuno;
			minhalista->fim = meuno;
			meuno->prox = NULL;
		}
		minhalista->tam++;
		return minhalista;
	}

	void percorrer(no * inicial, int x)
	{
		no *copia = inicial;

		if (inicial == NULL)
		{
			cout << "LISTA VAZIA!" << endl;
		}
		else
		{
			while (copia != NULL)
			{
				if (copia->info == x)
				{
					cout << "ELEMENTO ENCONTRADO!" << endl;
					cout << copia -> info << endl;
					return;
				}
				copia = copia->prox;
			}
			cout << "ELEMENTO NAO ENCONTRADO NA LISTA!" << endl;
		}
	}

	void imprimirlista(no * inicial)
	{
		no *copia = inicial;

		if (inicial == NULL)
		{
			cout << "A LISTA ESTA VAZIA!" << endl;
		}
		else
		{
			while (copia != NULL)
			{
				cout << copia->info << endl;
				copia = copia->prox;
			}
		}
	}

	void tamanho(lista * minhalista)
	{
		cout << "O TAMANHO DA LISTA E:" << endl;
		cout << minhalista->tam << endl;
	}

	void menulistaencadeada()
	{
		int escolha;
		int x;

		listaa *minhalista;
		minhalista = inicializar(minhalista);

		cout << "------------------------------- LISTA SIMPLESMENTE ENCADEADA-------------------------------------" << endl;

		while (true)
		{

			cout << "QUAL OPCAO DESEJA?" << endl;
			cout << "1-INSERIR NO INICIO\n2-INSERIR NO FIM\n3-BUSCAR UM ELEMENTO\n4-MOSTRAR LISTA\n5-MOSTRAR TAMANHO DA LISTA" << endl;
			cin >> escolha;

			switch (escolha)
			{
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
				percorrer(minhalista->inicio, x);
				break;
			case 4:
				imprimirlista(minhalista->inicio);
				break;
			case 5:
				tamanho(minhalista);
				break;
			default:
				cout << "OPCAO INVALIDA!" << endl;
			}
		}
	}

int main(){
	menulistaencadeada();
}