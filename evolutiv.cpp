#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;
int aux=0;
vector <int> x;
vector <int> y;


void a_int (string s){
int j=0;
    istringstream iss(s);

    do
    {
        string sub;
        iss >> sub;
		//cout << sub << endl;
        if(j==0){
			x.push_back(atoi(sub.c_str()));
			cout << "x: " << atoi(sub.c_str())<< endl;
		}
		if(j==1){
			y.push_back(atoi(sub.c_str()));
			//cout <<x.size();			
			cout << "y: "<< atoi(sub.c_str())<< endl;
		}
	j++;    
	} while (iss);
	


}



void search_bigger(){



}







int main (){
  string line;
  ifstream myfile ("input.txt");
  if (myfile.is_open())
  {
  int i=-1;
    while ( getline (myfile,line) )
    {
		if(i==-1){
			aux=atoi(line.c_str());
		}else{
			a_int(line);
			//search_bigger();
    	}
		i++;
	}
	    myfile.close();
	
		cout <<x.size()<<"\n";
cout <<x[5]<<"\n";
	//for(int k=0;k<x.size();k++)
		//cout << x[k] << " " << y[k] << endl;


		
	}
  	else cout << "Unable to open file\n"; 

  return 0;
}


