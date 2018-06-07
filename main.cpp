#include "main.h"
#include "cache.h"
using namespace std;

int matrizTamanho = 4;

mainMem::mainMem(){}

void mainMem::setMain() {

	int count = 0;
	string bits;	
	string sTag;
	string sSet; 
	string sWord;
	int rands;

	for (int x = 0; x < matrizTamanho; x++)
	{ 
		for (int y = 0; y < matrizTamanho; y++)
		{	
			rands = rand() % 10000;
			bitset<12> bVal(rands);
			bits = bVal.to_string();

			sSet = this->getSet(bits);
			sTag = this->getTag(bits);
			sWord = this->getWord(bits);

			this->matrizMem[x][y][0] = "0x" + to_string(count);
			this->matrizMem[x][y][1] = sTag;
			this->matrizMem[x][y][2] = sSet;
			this->matrizMem[x][y][3] = sWord;

			count++; 
		}
		
	}

}

void mainMem::getMain() {

	

	cout << "********** MAIN ***********\n" << endl;
	cout << "BLOCK -  END - TAG     - SET  - WORD" << endl;

	for (int x = 0; x < matrizTamanho; x++)
	{ 
		for (int y = 0; y < matrizTamanho; y++)
		{
			cout <<  x << "     | " << setw(3) <<  this->matrizMem[x][y][0] <<  " - " << this->matrizMem[x][y][1] <<  "  - " << this->matrizMem[x][y][2] << "   - " << this->matrizMem[x][y][3] << endl;
		}
		cout << "******************************************" << endl;
	}

}

void mainMem::readMain(string end, tCache matrizCache, int op[2]) {
	
	auto start = chrono::high_resolution_clock().now();

	for (int x = 0; x < matrizTamanho; x++)
		for (int y = 0; y < matrizTamanho; y++)
		{ 
			if (this->matrizMem[x][y][0] == end)
			{
				auto stop = chrono::high_resolution_clock().now();

				chrono::duration<float, milli> result = stop - start;

				cout << "Tempo: " << result.count() << " ms" << endl;
				cout << "Endereco: " << end << "    Valor: " << this->matrizMem[x][y][1] << endl;

				cacheMem::newCache(this->matrizMem[x][y][0], this->matrizMem[x][y][1], this->matrizMem[x][y][2], this->matrizMem[x][y][3], matrizCache, op);
				Sleep(2000);
				break;
			}
		}

}


string mainMem::getSet(string bits) {

	string set; 

	for (int x = bits.size() - 4; x < bits.size() -2; x++) {
		set.push_back(bits[x]);
	}

	
	return set;
}

string mainMem::getTag(string bits) {

	string tag;

	for (int x = 0; x < bits.size() -6; x++) {
		tag.push_back(bits[x]);
	}

	return tag;
}

string mainMem::getWord(string bits) {

	string word;

	for (int x = bits.size() - 2; x < bits.size(); x++) {
		word.push_back(bits[x]);
	}

	return word;
}
