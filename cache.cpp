#include "cache.h"


cacheMem::cacheMem(int cacheOp[2], tCache matrizCache)
{
	switch (cacheOp[0])
	{
	case 0:
		this->setCache(matrizCache);
		break;
	case 1:
		this->setCacheAssoc(matrizCache);
		this->cacheOp = 2;
		break;
	}
}

void cacheMem::setCache(tCache matrizCache){
	
	string sSet;

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 1; y++)
		{	
			bitset<2> bSet(x); 
			sSet = bSet.to_string();

			matrizCache[x][y][0] = sSet;
			matrizCache[x][y][1] = "0";
			matrizCache[x][y][2] = "";
			matrizCache[x][y][3] = "";
			matrizCache[x][y][4] = "";
		}
	}

}

void cacheMem::setCacheAssoc(tCache matrizCache) {

	string sSet;

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 2; y++)
		{
			bitset<2> bSet(x);
			sSet = bSet.to_string();

			matrizCache[x][y][0] = sSet;
			matrizCache[x][y][1] = "0";
			matrizCache[x][y][2] = "";
			matrizCache[x][y][3] = "";
			matrizCache[x][y][4] = "";
			matrizCache[x][y][5] = "0";
		}
	}

}

void cacheMem::getCache(tCache matrizCache) {


	cout << "\n\n********* CACHE *********" << endl;
	cout << "SET  -  FLAG  -  TAG      -    WORD   -   END" << endl;

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < this->cacheOp; y++)
		{
			cout << matrizCache[x][y][0] << "      " << matrizCache[x][y][1] << "        " << matrizCache[x][y][2] << setw(8) << "      " << matrizCache[x][y][3] <<  "         "<<matrizCache[x][y][4] << endl;
		}
	}

}

bool cacheMem::readCache(string end, tCache matrizCache, int op[2]) {

	int v;

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < this->cacheOp; y++)
		{
			if (matrizCache[x][y][1] != "0")
			{
				if (matrizCache[x][y][4] == end)
				{
					
					switch (op[1])
					{

					case 1:
						
						v = stoi(matrizCache[x][y][5]);
						v++;
						matrizCache[x][y][5] = to_string(v);
						break;

					case 2:
						
						v = stoi(matrizCache[x][y][5]);
						v++;
						matrizCache[x][y][5] = to_string(v);
						break;

					}

					
					cout << "\nCACHE HIT!" << endl;
					Sleep(2000);
					return true;

				}
			}
		}
	}

	return false;

}


void cacheMem::newCache(string end, string tag, string set, string word, tCache matrizCache, int op[2]) {

	/*
	* DIRETO OU ASSOC 
	*/
	switch (op[0])
	{
	case 0:

		for (int x = 0; x < 4; x++) {	
			for (int y = 0; y < 1; y++) {
				if (matrizCache[x][y][1] == "0" && matrizCache[x][y][0] == set) {
				
					matrizCache[x][y][1] = "1";
					matrizCache[x][y][2] = tag;
					matrizCache[x][y][3] = word;
					matrizCache[x][y][4] = end;
					return;
				}
				else if (matrizCache[x][y][1] == "1" && matrizCache[x][y][0] == set)
				{

					cout << "\nValor " << matrizCache[x][y][4] << " sera apagado!" << endl;
					Sleep(2000);
					matrizCache[x][y][1] = "1";
					matrizCache[x][y][2] = tag;
					matrizCache[x][y][3] = word;
					matrizCache[x][y][4] = end;
					return;
				}
			
			}
		}
		break;

	case 1:

		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 2; y++) {


				/*
				*	ESCOLHA DE POLITICA DE SUBSTITUICAO
				*/

				switch (op[1]) {
				
					int v1;
					int v2;

				//rand
				case 0:
					if (matrizCache[x][y][1] == "0" && matrizCache[x][y][0] == set) {

						matrizCache[x][y][1] = "1";
						matrizCache[x][y][2] = tag;
						matrizCache[x][y][3] = word;
						matrizCache[x][y][4] = end;
						return;
					}
					else if (matrizCache[x][y][1] == "1" && matrizCache[x][y -1 ][1] == "1" && matrizCache[x][y][0] == set)
					{
						int n = rand() % 2;
						cout << "\nValor " << matrizCache[x][y -n][4] << " sera apagado!" << endl;
						Sleep(2000);
						matrizCache[x][y -n][1] = "1";
						matrizCache[x][y -n][2] = tag;
						matrizCache[x][y -n][3] = word;
						matrizCache[x][y -n][4] = end;
						return;
					}
					break;

				//LFU
				case 1:
					if (matrizCache[x][y][1] == "0" && matrizCache[x][y][0] == set) {

						matrizCache[x][y][1] = "1";
						matrizCache[x][y][2] = tag;
						matrizCache[x][y][3] = word;
						matrizCache[x][y][4] = end;
						return;
					}
					else if (matrizCache[x][y][1] == "1" && matrizCache[x][y - 1][1] == "1" && matrizCache[x][y][0] == set)
					{

						v1 = stoi(matrizCache[x][y - 1][5]);
						v2 = stoi(matrizCache[x][y ][5]);

						if (v1 > v2) 
						{
							cout << "\nValor " << matrizCache[x][y][4] << " foi usado apenas " << matrizCache[x][y][5] << " contra " << matrizCache[x][y -1][5] << "do outro endereco e sera apagado!" << endl;
							Sleep(2000);
							matrizCache[x][y][1] = "1";
							matrizCache[x][y][2] = tag;
							matrizCache[x][y][3] = word;
							matrizCache[x][y][4] = end;
							matrizCache[x][y][5] = "0";
							return;
						}
						else
						{
							cout << "\nValor " << matrizCache[x][y][4] << " foi usado apenas " << matrizCache[x][y -1][5] <<" contra " << matrizCache[x][y][5] << " do outro endereco e sera apagado!" << endl;
							Sleep(2000);
							matrizCache[x][y -1][1] = "1";
							matrizCache[x][y -1][2] = tag;
							matrizCache[x][y -1][3] = word;
							matrizCache[x][y -1][4] = end;
							matrizCache[x][y -1][5] = "0";
							return;
						}



					}
					break;

				//LFA
				case 2:
					
					if (matrizCache[x][y][1] == "0" && matrizCache[x][y][0] == set) {

						matrizCache[x][y][1] = "1";
						matrizCache[x][y][2] = tag;
						matrizCache[x][y][3] = word;
						matrizCache[x][y][4] = end;
						return;
					}
					else if (matrizCache[x][y][1] == "1" && matrizCache[x][y - 1][1] == "1" && matrizCache[x][y][0] == set)
					{

						v1 = stoi(matrizCache[x][y - 1][5]);
						v2 = stoi(matrizCache[x][y][5]);

						if (v1 > v2)
						{	
							Sleep(2000);
							matrizCache[x][y][1] = "1";
							matrizCache[x][y][2] = tag;
							matrizCache[x][y][3] = word;
							matrizCache[x][y][4] = end;
							matrizCache[x][y][5] = "0";
							return;
						}
						else
						{
							Sleep(2000);
							matrizCache[x][y - 1][1] = "1";
							matrizCache[x][y - 1][2] = tag;
							matrizCache[x][y - 1][3] = word;
							matrizCache[x][y - 1][4] = end;
							matrizCache[x][y - 1][5] = "0";
							return;
						}



					}
					break;
					
				}
			}
		}
		break;

	}

}

