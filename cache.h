#pragma once
#include <string>
#include <iostream>
#include <math.h>
#include <Windows.h>
#include <iomanip>
#include <bitset>
#include <chrono>

using namespace std;


typedef string tCache[4][2][6];

class cacheMem
{
public:

	/* CONSTRUTOR */
	cacheMem(int cacheOp[2], tCache matrizCache);
	/* INICIALIZA O DIRETO */
	void setCache(tCache matrizCache);
	/* INCIALIZA O ASSOCIATIVO */
	void setCacheAssoc(tCache matrizCache);
	/* PRINTA A MATRIZ */
	void getCache(tCache matrizCache);
	/* LE O CACHE E SE ENCONTRAR O VALOR RETORNA TRUE */
	bool readCache(string end, tCache matrizCache, int op[2]);
	/* FUNCAO STATICA UTILIZADA NA CLASSE DA MEMORIA PRINCIPAL, QUANDO A MEMORIA PRINCIPAL FAZ UMA BUSCA
	*  E ENCONTRA O VALOR, ELA CHAMA ESSA FUNCAO QUE REPASSA PRA CACHE
	*/
	static void newCache(string end, string tag, string set, string word, tCache matrizCache, int op[2]);
	
private:
	/* SELETOR */
	int cacheOp = 1;
};

