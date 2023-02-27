// PrimerAvance.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

struct Usuarios
{
	char NombreComUsu[50];
	char NombreUsuario[50];
	char Contrasena[50];
	int Tipo;
	char SucursalUsu[50];
	Usuarios* sigUsu;
};

struct Clientes
{
	char NombreComCli[50];
	int Telefono;
	char Correo[50];
	char SucursalCli[50];
	int Pts = 0;
	Clientes* sigCli;
};

struct Promociones
{
	char Promocion[50];
	int PtsRequeridos;
	int Descuento;
	int Estatus;
	Promociones* sigPro;
};

struct Sucursales
{
	char NombreSuc[50];
	char Direccion[50];
	Sucursales* sigSuc;
};

Usuarios* inicioUsu, * auxUsu = nullptr;
Clientes* inicioCli, * auxCli = nullptr;
Promociones* inicioPro, * auxPro = nullptr;
Sucursales* inicioSuc, * auxSuc = nullptr;

void RegistrarUsu(Usuarios* nuevoUsu);
void RegistrarCli(Clientes* nuevoCli);
void RegistrarPro(Promociones* nuevoPro);
void RegistrarSuc(Sucursales* nuevoSuc);

void MostrarListaUsu();
void MostrarListaCli();
void MostrarListaPro();
void MostrarListaSuc();

void EscribirBinarioUsu();
void EscribirBinarioCli();
void EscribirBinarioPro();
void EscribirBinarioSuc();

void LeerBinarioUsu();
void LeerBinarioCli();
void LeerBinarioPro();
void LeerBinarioSuc();

int main()
{
	LeerBinarioUsu();
	LeerBinarioCli();
	LeerBinarioPro();
	LeerBinarioSuc();

	Usuarios* nodoUsu = new Usuarios;
	Clientes* nodoCli = new Clientes;
	Promociones* nodoPro = new Promociones;
	Sucursales* nodoSuc = new Sucursales;

	int Opcion=0;
	int Opcion2=0;
	do
	{
		do
		{
			system("cls");
			cout << ":::::MENU:::::" << endl;
			cout << "1) Registrar." << endl;
			cout << "2) Mostrar." << endl;
			cout << "3) Salir." << endl;
			cin >> Opcion;
			if (Opcion < 1 || Opcion >3)
			{
				cout << "Opcion erronea, vuelva a ingresar" << endl;
				system("pause");
			}
		} while (Opcion < 1 || Opcion >3);

		if (Opcion == 1 or Opcion == 2)
		{
			do
			{
				system("cls");
				cout << ":::::ENTIDADES:::::" << endl;
				cout << "1) Usuarios." << endl;
				cout << "2) Clientes." << endl;
				cout << "3) Promociones." << endl;
				cout << "4) Sucursales." << endl;
				cin >> Opcion2;
				cin.ignore();
				system("cls");
				if (Opcion2 < 1 || Opcion2 >4)
				{
					cout << "Opcion erronea, vuelva a ingresar" << endl;
					system("pause");
				}
			} while (Opcion2 <1 || Opcion2 >4);

			if (Opcion == 1)
			{
				if (Opcion2 == 1)
				{
					cout << "Nombre completo del usuario: " << endl;
					cin.getline(nodoUsu->NombreComUsu, 50);
					cout << "Nombre de usuario: " << endl;
					cin.getline(nodoUsu->NombreUsuario, 50);
					cout << "Contrase" << char(164) << "a: ";
					cin.getline(nodoUsu->Contrasena, 50);
					cout << "Tipo: " << endl;
					cin >> nodoUsu->Tipo;
					cin.ignore();
					cout << "Sucursal de usuario: " << endl;
					cin.getline(nodoUsu->SucursalUsu, 50);

					nodoUsu->sigUsu = nullptr;

					RegistrarUsu(nodoUsu);
				}
				else if (Opcion2 == 2)
				{
					cout << "Nombre del cliente: " << endl;
					cin.getline(nodoCli->NombreComCli, 50);
					cout << "Telefono: " << endl;
					cin >> nodoCli->Telefono;
					cin.ignore();
					cout << "Correo: " << endl;
					cin.getline(nodoCli->Correo, 50);
					cout << "Sucursal de cliente: " << endl;
					cin.getline(nodoCli->SucursalCli, 50);
					cout << "Pts:" << endl;
					cin >> nodoCli->Pts;

					nodoCli->sigCli = nullptr;

					RegistrarCli(nodoCli);
				}
				else if (Opcion2 == 3)
				{
					cout << "Promocion: " << endl;
					cin.getline(nodoPro->Promocion, 50);
					cout << "Pts requeridos " << endl;
					cin >> nodoPro->PtsRequeridos;
					cout << "Descuento " << endl;
					cin >> nodoPro->Descuento;
					cout << "Estatus " << endl;
					cin >> nodoPro->Estatus;

					nodoPro->sigPro = nullptr;

					RegistrarPro(nodoPro);
				}
				else if (Opcion2 == 4)
				{
					cout << "Nombre de sucursal " << endl;
					cin.getline(nodoSuc->NombreSuc, 50);
					cout << "Direccion " << endl;
					cin.getline(nodoSuc->Direccion, 50);

					nodoSuc->sigSuc = nullptr;

					RegistrarSuc(nodoSuc);
				}
			}

			else if (Opcion == 2)
			{
				if (Opcion2 == 1)
				{
					MostrarListaUsu();
					cin.ignore();
				}
				else if (Opcion2 == 2)
				{
					MostrarListaCli();
					cin.ignore();
				}
				else if (Opcion2 == 3)
				{
					MostrarListaPro();
					cin.ignore();
				}
				else if (Opcion2 == 4)
				{
					MostrarListaSuc();
					cin.ignore();
				}
			}
		}

	} while (Opcion != 3);

	EscribirBinarioUsu();
	EscribirBinarioCli();
	EscribirBinarioPro();
	EscribirBinarioSuc();

	return 0;
}

void RegistrarUsu(Usuarios* nuevoUsu)
{
	if (inicioUsu == nullptr) { //Si 'inicio es igual a nullptr, o sea, apunta a nada, la lista esta vacia
		inicioUsu = new Usuarios;				//y el producto que vamos a registrar es el primero de la lista

		strcpy_s(inicioUsu->NombreComUsu, nuevoUsu->NombreComUsu);
		strcpy_s(inicioUsu->NombreUsuario, nuevoUsu->NombreUsuario);
		strcpy_s(inicioUsu->Contrasena, nuevoUsu->Contrasena);
		inicioUsu->Tipo = nuevoUsu->Tipo;
		strcpy_s(inicioUsu->SucursalUsu, nuevoUsu->SucursalUsu);
		inicioUsu->sigUsu = nullptr;
	}
	else {
		if (auxUsu == nullptr) {
			auxUsu = inicioUsu;
		}

		while (auxUsu->sigUsu != nullptr) //Si la respuesta a la pregunta es SI, entonces entra al while
		{
			auxUsu = auxUsu->sigUsu;
		}

		auxUsu->sigUsu = new Usuarios;

		auxUsu = auxUsu->sigUsu;

		strcpy_s(auxUsu->NombreComUsu, nuevoUsu->NombreComUsu);
		strcpy_s(auxUsu->NombreUsuario, nuevoUsu->NombreUsuario);
		strcpy_s(auxUsu->Contrasena, nuevoUsu->Contrasena);
		auxUsu->Tipo = nuevoUsu->Tipo;
		strcpy_s(auxUsu->SucursalUsu, nuevoUsu->SucursalUsu);
		auxUsu->sigUsu = nullptr;

	}
}
void MostrarListaUsu()
{
	system("cls");
	if (inicioUsu == nullptr) { //Si 'inicio es igual a nullptr, o sea, apunta a nada, la lista esta vacia

		cout << "\n";
		cout << "La lista esta vacia. Agregue productos";

	}
	else {			//si no, entonces tiene productos agregadas y nos movemos en la lista y mostramos los nombres
		auxUsu = inicioUsu;

		while (auxUsu != nullptr)
		{
			cout << "Nombre Completo de Usuario: " << auxUsu->NombreComUsu << endl;
			cout << "Nombre de Usuario: " << auxUsu->NombreUsuario << endl;
			cout << "Contrase" << char(164) << "a: " << auxUsu->Contrasena << endl;
			cout << "Tipo: " << auxUsu->Tipo << endl;
			cout << "Sucursal de Usuario: " << auxUsu->SucursalUsu << endl;
			cout << "--------------------------------" << endl;
			auxUsu = auxUsu->sigUsu;
		}
	}
}

void RegistrarCli(Clientes* nuevoCli)
{
	if (inicioCli == nullptr) { //Si 'inicio es igual a nullptr, o sea, apunta a nada, la lista esta vacia
		inicioCli = new Clientes;				//y el producto que vamos a registrar es el primero de la lista

		strcpy_s(inicioCli->NombreComCli, nuevoCli->NombreComCli);
		inicioCli->Telefono = nuevoCli->Telefono;
		strcpy_s(inicioCli->Correo, nuevoCli->Correo);
		strcpy_s(inicioCli->SucursalCli, nuevoCli->SucursalCli);
		inicioCli->Pts = nuevoCli->Pts;
		inicioCli->sigCli = nullptr;
	}
	else {
		if (auxCli == nullptr) {
			auxCli = inicioCli;
		}

		while (auxCli->sigCli != nullptr) //Si la respuesta a la pregunta es SI, entonces entra al while
		{
			auxCli = auxCli->sigCli;
		}

		auxCli->sigCli = new Clientes;

		auxCli = auxCli->sigCli;

		strcpy_s(auxCli->NombreComCli, nuevoCli->NombreComCli);
		auxCli->Telefono = nuevoCli->Telefono;
		strcpy_s(auxCli->Correo, nuevoCli->Correo);
		strcpy_s(auxCli->SucursalCli, nuevoCli->SucursalCli);
		auxCli->Pts = nuevoCli->Pts;
		auxCli->sigCli = nullptr;
	}
}
void MostrarListaCli()
{
	system("cls");
	if (inicioCli == nullptr) { //Si 'inicio es igual a nullptr, o sea, apunta a nada, la lista esta vacia

		cout << "\n";
		cout << "La lista esta vacia. Agregue productos";

	}
	else {			//si no, entonces tiene productos agregadas y nos movemos en la lista y mostramos los nombres
		auxCli = inicioCli;

		while (auxCli != nullptr)
		{
			cout << "Nombre Completo de Cliente: " << auxCli->NombreComCli << endl;
			cout << "Telefono: " << auxCli->Telefono << endl;
			cout << "Correo: " << auxCli->Correo << endl;
			cout << "Sucursal de Cliente: " << auxCli->SucursalCli << endl;
			cout << "Pts: " << auxCli->Pts << endl;
			cout << "--------------------------------" << endl;
			auxCli = auxCli->sigCli;
		}
	}
}

void RegistrarPro(Promociones* nuevoPro)
{
	if (inicioPro == nullptr) { //Si 'inicio es igual a nullptr, o sea, apunta a nada, la lista esta vacia
		inicioPro = new Promociones;				//y el producto que vamos a registrar es el primero de la lista

		strcpy_s(inicioPro->Promocion, nuevoPro->Promocion);
		inicioPro->PtsRequeridos = nuevoPro->PtsRequeridos;
		inicioPro->Descuento = nuevoPro->Descuento;
		inicioPro->Estatus = nuevoPro->Estatus;
		inicioPro->sigPro = nullptr;
	}
	else {
		if (auxPro == nullptr) {
			auxPro = inicioPro;
		}

		while (auxPro->sigPro != nullptr) //Si la respuesta a la pregunta es SI, entonces entra al while
		{
			auxPro = auxPro->sigPro;
		}

		auxPro->sigPro = new Promociones;

		auxPro = auxPro->sigPro;

		strcpy_s(auxPro->Promocion, nuevoPro->Promocion);
		auxPro->PtsRequeridos = nuevoPro->PtsRequeridos;
		auxPro->Descuento = nuevoPro->Descuento;
		auxPro->Estatus = nuevoPro->Estatus;
		auxPro->sigPro = nullptr;

	}
}
void MostrarListaPro()
{
	system("cls");
	if (inicioPro == nullptr) { //Si 'inicio es igual a nullptr, o sea, apunta a nada, la lista esta vacia

		cout << "\n";
		cout << "La lista esta vacia. Agregue productos";

	}
	else {			//si no, entonces tiene productos agregadas y nos movemos en la lista y mostramos los nombres
		auxPro = inicioPro;

		while (auxPro != nullptr)
		{
			cout << "Promocion: " << auxPro->Promocion << endl;
			cout << "Pts Requeridos: " << auxPro->PtsRequeridos << endl;
			cout << "Descuento: " << auxPro->Descuento << "%" << endl;
			cout << "Estatus: " << auxPro->Estatus << endl;
			cout << "--------------------------------" << endl;
			auxPro = auxPro->sigPro;
		}
	}
}

void RegistrarSuc(Sucursales* nuevoSuc)
{
	if (inicioSuc == nullptr) { //Si 'inicio es igual a nullptr, o sea, apunta a nada, la lista esta vacia
		inicioSuc = new Sucursales;				//y el producto que vamos a registrar es el primero de la lista

		strcpy_s(inicioSuc->NombreSuc, nuevoSuc->NombreSuc);
		strcpy_s(inicioSuc->Direccion, nuevoSuc->Direccion);
		inicioSuc->sigSuc = nullptr;
	}
	else {
		if (auxSuc == nullptr) {
			auxSuc = inicioSuc;
		}

		while (auxSuc->sigSuc != nullptr) //Si la respuesta a la pregunta es SI, entonces entra al while
		{
			auxSuc = auxSuc->sigSuc;
		}

		auxSuc->sigSuc = new Sucursales;

		auxSuc = auxSuc->sigSuc;

		strcpy_s(auxSuc->NombreSuc, nuevoSuc->NombreSuc);
		strcpy_s(auxSuc->Direccion, nuevoSuc->Direccion);
		auxSuc->sigSuc = nullptr;
	}
}
void MostrarListaSuc()
{
	system("cls");
	if (inicioSuc == nullptr) { //Si 'inicio es igual a nullptr, o sea, apunta a nada, la lista esta vacia

		cout << "\n";
		cout << "La lista esta vacia. Agregue productos";

	}
	else {			//si no, entonces tiene productos agregadas y nos movemos en la lista y mostramos los nombres
		auxSuc = inicioSuc;

		while (auxSuc != nullptr)
		{
			cout << "Nombre de Sucursal: " << auxSuc->NombreSuc << endl;
			cout << "Direccion: " << auxSuc->Direccion << endl;
			cout << "--------------------------------" << endl;
			auxSuc = auxSuc->sigSuc;
		}
	}
}

void EscribirBinarioUsu()
{
	auxUsu = inicioUsu;

	ofstream escrUsu;
	escrUsu.open("Usuarios.bin", ios::out | ios::binary | ios::trunc);

	if (escrUsu.is_open()) {
		while (auxUsu != nullptr)
		{
			escrUsu.write((char*)auxUsu, sizeof(Usuarios));
			auxUsu = auxUsu->sigUsu;
		}

		escrUsu.close();
	}
	else
	{
		cout << "No se pudo abrir el archivo.";
		system("PAUSE");
	}
}
void LeerBinarioUsu()
{
	ifstream leerUsu;
	leerUsu.open("Usuarios.bin", ios::in | ios::binary);


	if (leerUsu.is_open()) {

		Usuarios* usuLeido = new Usuarios;

		while (!leerUsu.read((char*)usuLeido, sizeof(Usuarios)).eof()) {

			if (inicioUsu == nullptr) {
				inicioUsu = usuLeido;
				inicioUsu->sigUsu = nullptr;
				auxUsu = inicioUsu;
			}
			else {
				auxUsu->sigUsu = usuLeido;
				auxUsu = auxUsu->sigUsu;
				auxUsu->sigUsu = nullptr;
				//fin = aux;
			}

			usuLeido = new Usuarios;
		}
		leerUsu.close();
		delete usuLeido;
	}
	else {
		cout << "No es posible abrir el archivo.";
		system("PAUSE");
	}
}

void EscribirBinarioCli()
{
	auxCli = inicioCli;

	ofstream escrCli;
	escrCli.open("Clientes.bin", ios::out | ios::binary | ios::trunc);

	if (escrCli.is_open()) {
		while (auxCli != nullptr)
		{
			escrCli.write((char*)auxCli, sizeof(Clientes));
			auxCli = auxCli->sigCli;
		}

		escrCli.close();
	}
	else
	{
		cout << "No se pudo abrir el archivo.";
		system("PAUSE");
	}
}
void LeerBinarioCli()
{
	ifstream leerCli;
	leerCli.open("Clientes.bin", ios::in | ios::binary);


	if (leerCli.is_open()) {

		Clientes* cliLeido = new Clientes;

		while (!leerCli.read((char*)cliLeido, sizeof(Clientes)).eof()) {

			if (inicioCli == nullptr) {
				inicioCli = cliLeido;
				inicioCli->sigCli = nullptr;
				auxCli = inicioCli;
			}
			else {
				auxCli->sigCli = cliLeido;
				auxCli = auxCli->sigCli;
				auxCli->sigCli = nullptr;
				//fin = aux;
			}

			cliLeido = new Clientes;
		}
		leerCli.close();
		delete cliLeido;
	}
	else {
		cout << "No es posible abrir el archivo.";
		system("PAUSE");
	}
}

void EscribirBinarioPro()
{
	auxPro = inicioPro;

	ofstream escrPro;
	escrPro.open("Promociones.bin", ios::out | ios::binary | ios::trunc);

	if (escrPro.is_open()) {
		while (auxPro != nullptr)
		{
			escrPro.write((char*)auxPro, sizeof(Promociones));
			auxPro = auxPro->sigPro;
		}

		escrPro.close();
	}
	else
	{
		cout << "No se pudo abrir el archivo.";
		system("PAUSE");
	}
}
void LeerBinarioPro()
{
	ifstream leerPro;
	leerPro.open("Promociones.bin", ios::in | ios::binary);


	if (leerPro.is_open()) {

		Promociones* proLeido = new Promociones;

		while (!leerPro.read((char*)proLeido, sizeof(Promociones)).eof()) {

			if (inicioPro == nullptr) {
				inicioPro = proLeido;
				inicioPro->sigPro = nullptr;
				auxPro = inicioPro;
			}
			else {
				auxPro->sigPro = proLeido;
				auxPro = auxPro->sigPro;
				auxPro->sigPro = nullptr;
				//fin = aux;
			}

			proLeido = new Promociones;
		}
		leerPro.close();
		delete proLeido;
	}
	else {
		cout << "No es posible abrir el archivo.";
		system("PAUSE");
	}
}

void EscribirBinarioSuc()
{
	auxSuc = inicioSuc;

	ofstream escrSuc;
	escrSuc.open("Sucursales.bin", ios::out | ios::binary | ios::trunc);

	if (escrSuc.is_open()) {
		while (auxSuc != nullptr)
		{
			escrSuc.write((char*)auxSuc, sizeof(Sucursales));
			auxSuc = auxSuc->sigSuc;
		}

		escrSuc.close();
	}
	else
	{
		cout << "No se pudo abrir el archivo.";
		system("PAUSE");
	}
}
void LeerBinarioSuc()
{
	ifstream leerSuc;
	leerSuc.open("Sucursales.bin", ios::in | ios::binary);


	if (leerSuc.is_open()) {

		Sucursales* sucLeido = new Sucursales;

		while (!leerSuc.read((char*)sucLeido, sizeof(Sucursales)).eof()) {

			if (inicioSuc == nullptr) {
				inicioSuc = sucLeido;
				inicioSuc->sigSuc = nullptr;
				auxSuc = inicioSuc;
			}
			else {
				auxSuc->sigSuc = sucLeido;
				auxSuc = auxSuc->sigSuc;
				auxSuc->sigSuc = nullptr;
				//fin = aux;
			}

			sucLeido = new Sucursales;
		}
		leerSuc.close();
		delete sucLeido;
	}
	else {
		cout << "No es posible abrir el archivo.";
		system("PAUSE");
	}
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
