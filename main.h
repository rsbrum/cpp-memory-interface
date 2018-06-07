#include <string>
#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
#include <bitset>
#include "cache.h"
#include <chrono>



using namespace std;



class mainMem 
{
public:
	/* AUTO EXPLICATIVAS */
	mainMem();
	void getMain();
	void readMain(string end, tCache matrizCache, int op[2]);
	void setMain();
	
private:

	
	string getTag(string bits);
	string getSet(string bits);
	string getWord(string bits);

	string matrizMem[4][4][4];


};

