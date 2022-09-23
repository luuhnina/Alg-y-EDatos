#include <iostream>
#include <fstream>

using namespace std;
const int dimprod {5};

int mostrarmayor(float vec[][5], int dim)
{
	const int dimen {5};
	int mayor;
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dimen; j++)
			if (vec[i][j] > vec[mayor][j])
				mayor = i;
	return mayor;
}

void mostrardatos(float m[][5], string vec[], int& dim, int dimen)
{
	for (int i = 0; i < dimen; i++)
		cout << vec[i] << ": " << m[dim][i] << endl;
}

int entregas(string vec[],int m[][5])
{
	const int dimen {8};
	cout << vec[dimen] << endl;
	int cantidad;
	for (int i = 0; i < dimen; ++i)
		cantidad = m[i][dimen]++;
	return cantidad;
}

int main()
{
	const int dimclien {8};
	float distancia[dimclien][dimprod] {};
	float pesoxclient[dimclien][dimprod] {};
	float mayora[dimclien][dimprod];
	string nomcliente[dimclien];
	string tipoprod[dimprod];

    ifstream archivo;
	archivo.open("Datos.txt");
	if (!archivo) {
		cout << "No se puedo abrir el archivo de datos" << endl;
		return 1;
	}
	int cliente, prod;
	float peso, dist;
	//SE CORRE UN LOOP Y SE CALCULAN DATOS
	while (archivo >> cliente >> prod >> peso >> dist) { //identifico las columnas
		distancia[cliente][prod] += dist; //suma
		pesoxclient[cliente][prod] += peso; //suma
		mayora[cliente][prod]++;
	}
	archivo.close();

	archivo.open("Nombres.txt");
	if (!archivo) {
		cout << "No se puedo abrir el archivo de datos" << endl;
		return 1;
	}
	for (int i = 0; i < dimclien && archivo >> nomcliente[i]; ++i);
	for (int i = 0; i < dimprod && archivo >> tipoprod[i]; ++i);
	archivo.close();
	
	//Punto 1
	int max;
	cout << "Listado por cliente de los tipos de porductos que superen los 13000 Kg" << endl;
	for (int i = 0; i < dimclien; ++i)
		for (int j = 0; j < dimprod && pesoxclient[i][j] > 13000; ++j)
			cout << nomcliente[i] << ": " << tipoprod[j] << endl;
			max = mostrarmayor(mayora, dimprod);	

	//Punto 2
	cout << "Listado de Km recorrido por tipo de producto" << endl;
	mostrardatos(distancia, tipoprod, max, dimprod);

	//Punto 3
	cout << "Producto con más recorrido y número de entregas" << endl;
	entregas(mostrardatos[8], distancia);
}	