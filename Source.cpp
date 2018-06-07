#include <iostream>
#include <string>
#include <Windows.h>
#include "cache.h"
#include "main.h"
#include <chrono>

using namespace std;

void menu();
void iniciar(int cacheOp[2]);

/* SETA AS OPCOES DO CACHE */
int mapCache[2] = { 0,0 };

mainMem o_main;
tCache matrizCache;

int main() {

	menu();

	system("pause");
}

void menu() {

	system("cls");

	wstring wsMenu;
	wstring wsCache;

	int op; 

	wsMenu += L"\tMENU\n\n";
	wsMenu += L"1 - Iniciar\n";
	wsMenu += L"2 - Escolher mapeamento\n";
	wsMenu += L"3 - Escohler liberacao\n";

	wcout << wsMenu;
	cin >> op;

	switch (op)
	{
	case 1: 
		iniciar(mapCache);
		break; 
		
	case 2:

		system("cls");

		wsCache += L"1 - Direto\n";
		wsCache += L"2 - Associativo\n";
		wsCache += L"3 - Retornar\n";
		
		wcout << wsCache; 
		cin >> op;

		switch (op)
		{
		case 1:
			mapCache[0] = 0;
			menu();
			break;

		case 2:
			mapCache[0] = 1;
			menu();
			break;

		case 3:
			menu();
			break;

		}
		
	case 3:
		system("cls");
		wsCache = ' ';
		wsCache += L"1 - Randomico\n";
		wsCache += L" 2 - LFU\n";
		wsCache += L" 3 - LRU\n";

		wcout << wsCache;
		cin >> op;
		
		switch (op)
		{
		case 1:
			mapCache[1] = 0;
			menu();
			break;

		case 2:
			mapCache[1] = 1;
			menu();
			break;

		case 3:
			mapCache[1] = 2;
			menu();
			break;

		}
			
	}

 }

void iniciar(int cacheOp[2]) {
	
	cacheMem o_cache(cacheOp, matrizCache);

	o_main.setMain();
	
	system("cls");

	string sEndereco;

	while (1)
	{
		system("cls");
		o_main.getMain();
		o_cache.getCache(matrizCache);

		cout << "Endereco (0x...): ";
		cin >> sEndereco;

		if (!o_cache.readCache(sEndereco, matrizCache, cacheOp))
			o_main.readMain(sEndereco, matrizCache, cacheOp);
		 
	}
	
}