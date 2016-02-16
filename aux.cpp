#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int rdtsc()
{
    __asm__ __volatile__("rdtsc");
}

void aux(){

cout << rand()<< endl;
		cout << rand()<< endl;
		cout << rand()<< endl;
		cout << rand()<< endl;
		cout << rand()<< endl;
}
int main()
{
	int i = 0;
	//while(i++ < 10) {
srand(rdtsc());
        printf("%d\n", rand());
		cout << rand()<< endl;
		cout << rand()<< endl;
		cout << rand()<< endl;
		cout << rand()<< endl;
		cout << rand()<< endl;

		aux();


	//}
	return 0;
}





