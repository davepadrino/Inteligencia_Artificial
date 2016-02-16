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
vector <int> x2;
vector <int> y2;
vector <int> x3;
vector <int> y3;
vector <bool> e1;
vector <bool> e2;
vector <bool> e3;
vector <int> fire;
vector <int> water;
vector <int> earth;
vector <int> duel1;
vector <int> duel2;
vector <bool> duel_couple;
int rndm=0;
void to_int (string s, vector <int> x, vector <int> y){
int j=0;
    istringstream iss(s);

    do
    {
        string sub;
        iss >> sub;
		//cout << sub << endl;
        if(j==0){
			x.push_back(atoi(sub.c_str()));
			//cout << "x: " << atoi(sub.c_str())<< endl;
		}
		if(j==1){
			y.push_back(atoi(sub.c_str()));
			//cout <<x.size();			
			//cout << "y: "<< atoi(sub.c_str())<< endl;
		}
	j++;    
	} while (iss);
	


}


int x_cont = 0;
int y_cont = 0;

int rdtsc()
{
    __asm__ __volatile__("rdtsc");
}

void generate_duel(){

	for(int i=aux; i>0; i--)
		duel_couple.push_back(false);
	int k=0;
	rndm=rand()%aux;
	while (k!=aux/2-1){
		
		rndm=rand()%aux;
		while(duel_couple[rndm])
			rndm=rand()%aux;
		duel_couple[rndm]=true;
		duel1.push_back(rndm);
		cout<< "pareja "<< k << " ->"<< rndm << endl;
		rndm=rand()%aux;
		while(duel_couple[rndm])
			rndm=rand()%aux;
		duel_couple[rndm]=true;
		duel2.push_back(rndm);
		cout<< "pareja "<< k << " ->"<< rndm << endl;
		k++;
		//cout << "aux: " << aux << "    k: " << k <<endl;
	}
//cout << "fgfgg" << endl;
	for(int j=0; duel1.size()!=aux/2; j++){
		cout << "duel 1 j: " << j << duel_couple[j]<<endl; 
		if(!duel_couple[j]){
			cout << "ingrese al if" << endl;
			duel1.push_back(j);
			duel_couple[j]=true;
		}

	}
	for(int j=0; duel2.size()!=aux/2; j++){
		cout << "duel 2 j: " << j << duel_couple[j] << endl;
		if(!duel_couple[j]){
			duel2.push_back(j);
			duel_couple[j]=true;
		}

	}
}

void search_bigger(vector <int> x, vector <int> y){
	for (int i = 0; i < x.size(); i++){
		if (x[i] > x_cont){
			x_cont = x[i];
		}
	}
	for (int j = 0; j < y.size(); j++){
		if (y[j] > y_cont){
			y_cont = y[j];
		}
	}
}




 

void generate_teams(){
	for(int i=aux; i>0; i--){
		e1.push_back(false);
		e2.push_back(false);
		e3.push_back(false);
	}
	int k=0;
	//while (k!=aux/2-1){
	while (k<aux){
		
		rndm=rand()%aux;
		while(e1[rndm])
			rndm=rand()%aux;
		e1[rndm]=true;
		fire.push_back(rndm);
		rndm=rand()%aux;
		while(e2[rndm])
			rndm=rand()%aux;
		e2[rndm]=true;
		water.push_back(rndm);
		rndm=rand()%aux;
		while(e3[rndm])
			rndm=rand()%aux;
		e3[rndm]=true;
		earth.push_back(rndm);
		k++;
	}//se generaron los diferentes equipos

	for(int j=0; j<aux; j++){
		if(!e1[j])
			fire.push_back(j);
		if(!e2[j])
			water.push_back(j);
		if(!e3[j])
			earth.push_back(j);
	}


}


int main (){
  string line;
  ifstream myfile ("input.txt");
  ifstream myfile2 ("input2.txt");
  ifstream myfile3 ("input3.txt");
  srand(rdtsc());
  //first file

  if (myfile.is_open())
  {
  int i=-1;
    while ( getline (myfile,line) )
    {
		if(i==-1){
			aux=atoi(line.c_str()); //number of lines
		}else{
			to_int(line, x,y);
			//search_bigger(x, y);
			//cout << "mayor de x: " << x_cont << "\n";
			//cout << "mayor de y: " << y_cont << "\n";

    	}
		i++;
	}
	    myfile.close();
	
	//for(int k=0;k<x.size();k++)
		//cout << x[k] << " " << y[k] << endl;


		
	}
  	else cout << "Unable to open file\n"; 

  	// Second file
  	if (myfile2.is_open())
  {
  int i=-1;
    while ( getline (myfile2,line) )
    {
		if(i==-1){
			aux=atoi(line.c_str());
		}else{
			to_int(line, x2, y2);
			//search_bigger(x, y);
			//cout << "mayor de x: " << x_cont << "\n";
			//cout << "mayor de y: " << y_cont << "\n";

    	}
		i++;
	}
	    myfile2.close();
	
	//for(int k=0;k<x.size();k++)
		//cout << x[k] << " " << y[k] << endl;


		
	}
  	else cout << "Unable to open file\n"; 


  	// Third file
  	if (myfile3.is_open())
  {
  int i=-1;
    while ( getline (myfile3,line) )
    {
		if(i==-1){
			aux=atoi(line.c_str());
		}else{
			to_int(line, x3, y3);
			//search_bigger(x, y);
			//cout << "mayor de x: " << x_cont << "\n";
			//cout << "mayor de y: " << y_cont << "\n";

    	}
		i++;
	}
	    myfile3.close();
	
	//for(int k=0;k<x.size();k++)
		//cout << x[k] << " " << y[k] << endl;


		
	}
  	else cout << "Unable to open file\n";











  generate_teams();
  generate_duel();
  for(int i=0; i<aux/2; i++)
  	cout << i << " " << duel1[i] << " vs " << duel2 [i]<< endl;

  return 0;
}


