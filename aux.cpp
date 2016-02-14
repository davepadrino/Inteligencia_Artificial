// min_element/max_element example
#include <iostream>     // std::cout
#include <algorithm>    // std::min_element, std::max_element
#include <vector>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>
bool myfn(int i, int j) { return i<j; }

struct myclass {
  bool operator() (int i,int j) { return i<j; }
} myobj;


int main () {
	int myints[] = {3,7,2,5,6,4,9,10};
	std::cout << "The largest element is "  << *std::max_element(myints,myints+7) << '\n';

  return 0;
}