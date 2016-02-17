#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;
int aux=0, aux1=0, aux2, aux3=0;

vector <int> x;
vector <int> y;
vector <int> x2;
vector <int> y2;
vector <int> x3;
vector <int> y3;
vector <bool> e1;//aux1 se maracaran con true los indices de los maestros de fuego seleccionados
vector <bool> e2;//aux2 se maracaran con true los indices de los maestros de agua seleccionados
vector <bool> e3;//aux3 se maracaran con true los indices de los maestros de tierra seleccionados
vector <int> fire; //aux cada indice representa un individuo
vector <int> water;//aux cada indice representa un individuo
vector <int> earth;//aux cada indice representa un individuo
vector <int> duel1;//aux/2 cada indice representa una batalla
vector <int> duel2;//aux/2 cada indice representa una batalla
vector <bool> duel_couple;//aux se marcara con true el individuo que ya tiene contrrincante
vector <int> ganadores; //aux/2 
struct equipo{
	int id;
	int efectividad;
	int stamina;
	int zona;

};
equipo arena2[3]; 
equipo arena1[3];
int rndm=0;

int rdtsc()
{
    __asm__ __volatile__("rdtsc");
}


void torneo(int id_batalla){
//fuego
arena1[0].efectividad= x[fire[duel1[id_batalla]]];
arena1[0].stamina= y[fire[duel1[id_batalla]]];
arena1[0].id= fire[duel1[id_batalla]];
arena1[0].zona=1;
arena2[0].efectividad= x[fire[duel2[id_batalla]]];
arena2[0].stamina= y[fire[duel2[id_batalla]]];
arena2[0].id= fire[duel2[id_batalla]];
arena2[0].zona=1;

//agua
arena1[1].efectividad= x2[water[duel1[id_batalla]]];
arena1[1].stamina= y2[water[duel1[id_batalla]]];
arena1[1].id= water[duel1[id_batalla]];
arena1[1].zona=1;
arena2[1].efectividad= x2[water[duel2[id_batalla]]];
arena2[1].stamina= y2[water[duel2[id_batalla]]];
arena2[1].id= water[duel2[id_batalla]];
arena2[1].zona=1;

//tierra
arena1[2].efectividad= x3[earth[duel1[id_batalla]]];
arena1[2].stamina= y3[earth[duel1[id_batalla]]];
arena1[2].id= earth[duel1[id_batalla]];
arena1[2].zona=1;
arena2[2].efectividad= x3[earth[duel2[id_batalla]]];
arena2[2].stamina= y3[earth[duel2[id_batalla]]];
arena2[2].id= earth[duel2[id_batalla]];
arena2[2].zona=1;

srand(rdtsc());
while(((arena1[0].zona<4 && arena2[0].zona<4) || (arena1[1].zona<4 && arena2[1].zona<4) || (arena1[3].zona<4 && arena2[3].zona<4)) && (arena1[0].stamina>0 || arena1[1].stamina>0 || arena1[2].stamina>0 || arena2[0].stamina>0 || arena2[1].stamina>0 ||arena2[2].stamina>0)){

	for(int i=0; i<=2;i++){
		if(arena1[i].zona<=3 && arena2[i].zona<=3){
			if(arena1[i].stamina>=arena1[i].efectividad*(abs(arena1[i].zona-arena2[i].zona)+1)){
				if(arena2[i].stamina>=arena2[i].efectividad*(abs(arena1[i].zona-arena2[i].zona)+1)){//los dos pueden atacar
					rndm=rand()%2;
					if(rndm==0){//ataca el de la arena1
						cout<< i <<" ataca arena 1 "<< endl;
						arena1[i].stamina-= arena1[i].efectividad*(abs(arena1[i].zona-arena2[i].zona)+1);
						arena2[i].zona++;
						if(i==0)
							arena2[i].stamina= y[arena2[i].id];
						else
							if(i==1)
								arena2[i].stamina=y2[arena2[i].id];
							else
								arena2[i].stamina=y3[arena2[i].id];
					}else{//ataca el de la arena2
						cout<< i <<" ataca arena 2 "<< endl;
						arena2[i].stamina-= arena2[i].efectividad*(abs(arena1[i].zona-arena2[i].zona)+1);
						arena1[i].zona++;
						if(i==0)
							arena1[i].stamina= y[arena1[i].id];
						else
							if(i==1)
								arena1[i].stamina=y2[arena1[i].id];
							else
								arena1[i].stamina=y3[arena1[i].id];



					}

				}else{//solo puede atacar arena1
					cout<< i <<" ataca arena 1 "<< endl;
					arena1[i].stamina-= arena1[i].efectividad*(abs(arena1[i].zona-arena2[i].zona)+1);
						arena2[i].zona++;
						if(i==0)
							arena2[i].stamina= y[arena2[i].id];
						else
							if(i==1)
								arena2[i].stamina=y2[arena2[i].id];
							else
								arena2[i].stamina=y3[arena2[i].id];

				}
			}else{//arena1 no puede atacar
				if(arena2[i].stamina>=arena2[i].efectividad*(abs(arena1[i].zona-arena2[i].zona)+1)){//solo puede atacar arena 2
					cout<< i <<" ataca arena 2 "<< endl;
					arena2[i].stamina-= arena2[i].efectividad*(abs(arena1[i].zona-arena2[i].zona)+1);
					arena1[i].zona++;
					if(i==0)
						arena1[i].stamina= y[arena1[i].id];
					else
						if(i==1)
							arena1[i].stamina=y2[arena1[i].id];
						else
							arena1[i].stamina=y3[arena1[i].id];

				}else{//ninguno de los dos puede atacar
					cout<< i <<" Ninguno puede atacar"<< endl;
					arena2[i].stamina=0;
					arena1[i].stamina=0;


				}


			}
		}//fin if

	}//fin for
}//fin while



cout << arena1[0].id << " " << arena1[0].efectividad << " " << arena1[0].stamina << endl;
cout << arena1[1].id << " " << arena1[1].efectividad << " " << arena1[1].stamina << endl;
cout << arena1[2].id << " " << arena1[2].efectividad << " " << arena1[2].stamina << endl;
cout << arena2[0].id << " " << arena2[0].efectividad << " " << arena2[0].stamina << endl;
cout << arena2[1].id << " " << arena2[1].efectividad << " " << arena2[1].stamina << endl;
cout << arena2[2].id << " " << arena2[2].efectividad << " " << arena2[2].stamina << endl;
//cout << duel1[id_batalla] << endl;
//cout << water[duel1[id_batalla]] << endl;
//cout << x[water[duel1[id_batalla]]] << endl;







}//fin torneo


void to_int1 (string s){
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

void to_int2 (string s){
int j=0;
    istringstream iss(s);

    do
    {
        string sub;
        iss >> sub;
		//cout << sub << endl;
        if(j==0){
			x2.push_back(atoi(sub.c_str()));
			//cout << "x: " << atoi(sub.c_str())<< endl;
		}
		if(j==1){
			y2.push_back(atoi(sub.c_str()));
			//cout <<x.size();			
			//cout << "y: "<< atoi(sub.c_str())<< endl;
		}
	j++;    
	} while (iss);
}

void to_int3 (string s){
int j=0;
    istringstream iss(s);

    do
    {
        string sub;
        iss >> sub;
		//cout << sub << endl;
        if(j==0){
			x3.push_back(atoi(sub.c_str()));
			//cout << "x: " << atoi(sub.c_str())<< endl;
		}
		if(j==1){
			y3.push_back(atoi(sub.c_str()));
			//cout <<x.size();			
			//cout << "y: "<< atoi(sub.c_str())<< endl;
		}
	j++;    
	} while (iss);
}


int x_cont = 0;
int y_cont = 0;



void generate_duel(){

	for(int i=aux; i>0; i--)
		duel_couple.push_back(false);
	int k=0;
	rndm=rand()%aux;
	while ((k!=aux/2-1 && aux%2==0) || (k!=aux/2 && aux%2!=0)){
		
		rndm=rand()%aux;
		while(duel_couple[rndm]){
			
			cout<< k <<"candidato random: " << rndm << endl;
			rndm=rand()%aux;
		}
		duel_couple[rndm]=true;
			cout<< k <<"random elegido: " << rndm << endl;
		duel1.push_back(rndm);
		//cout<< "pareja "<< k << " ->"<< rndm << endl;
		rndm=rand()%aux;
		while(duel_couple[rndm]){
			
			cout<< k <<"candidato random: " << rndm << endl;
			rndm=rand()%aux;
		}
		duel_couple[rndm]=true;
		cout<< k <<"random elegido: " << rndm << endl;
		duel2.push_back(rndm);
		//cout<< "pareja "<< k << " ->"<< rndm << endl;
		k++;
		//cout << "aux: " << aux << "    k: " << k <<endl;
	}

	if (aux%2==0){
		//buscan los ultimos dos indivuos a enfrentarse
		for(int j=0; duel1.size()!=aux/2; j++){
			cout << "duel 1 j: " << j <<" "<< duel_couple[j]<<endl; 
			if(!duel_couple[j]){
				//cout << "ingrese al if" << endl;
				duel1.push_back(j);
				cout<<"apile el numero " << j<< endl;
				duel_couple[j]=true;
			}

		}
		for(int j=0; duel2.size()!=aux/2; j++){
			cout << "duel 2 j: " << j << " "<< duel_couple[j] << endl;
			if(!duel_couple[j]){
				duel2.push_back(j);
				cout <<"apile2 el numero " << j << endl;
				duel_couple[j]=true;
			}

		}
	}else{
		int k=0;
		while(duel_couple[k])
			k++;

		cout<<"K: " <<k << endl;

			//al equipo de indice K hay q pasarlo al poceso de cruce

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
		
		rndm=rand()%aux1;
		while(e1[rndm])
			rndm=rand()%aux1;
		e1[rndm]=true;
		fire.push_back(rndm);
		rndm=rand()%aux2;
		while(e2[rndm])
			rndm=rand()%aux2;
		e2[rndm]=true;
		water.push_back(rndm);
		rndm=rand()%aux3;
		while(e3[rndm])
			rndm=rand()%aux3;
		e3[rndm]=true;
		earth.push_back(rndm);
		k++;
	}//se generaron los diferentes equipos
	// los elementos q quedaron solos, el ultimo equipo
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
			aux1=atoi(line.c_str()); //number of lines
		}else{
			to_int1(line);
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
			aux2=atoi(line.c_str());
		}else{
			to_int2(line);
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
			aux3=atoi(line.c_str());
		}else{
			to_int3(line);
			//search_bigger(x, y);
			//cout << "mayor de x: " << x_cont << "\n";
			//cout << "mayor de y: " << y_cont << "\n";

    	}
		i++;
	}
	    myfile3.close();
	if (aux1<=aux2 && aux1<=aux3)
		aux=aux1;
	if (aux2<=aux1 && aux2<=aux3)
		aux=aux2;
	if (aux3<=aux2 && aux3<=aux1)
		aux=aux3;
	//for(int k=0;k<x.size();k++)
		//cout << x[k] << " " << y[k] << endl;


		
	}
  	else cout << "Unable to open file\n";











  generate_teams();
  generate_duel();
  for(int i=0; i<aux/2; i++)
  	cout << i << " " << duel1[i] << " vs " << duel2[i]<< endl;
  cout<<"equipos de trios"<< endl;
  for(int i=0; i<aux; i++)
  	cout << fire[i] << " " << water[i] << " " << earth[i] << endl;
  cout << x.size() << endl;
  for(int i=0; i<x3.size(); i++)
  	cout << x[i] << " " << y[i] << " " << endl;
  cout << x2.size() << endl;
  for(int i=0; i<x3.size(); i++)
  	cout << x2[i] << " " << y2[i] << " " << endl;
  cout << x3.size() << endl;
  for(int i=0; i<x3.size(); i++)
  	cout << x3[i] << " " << y3[i] << " " << endl;
  	cout << x.size() << " " << x2.size() << " " << x3.size()<< endl;
	cout << aux1 << " " << aux2 << " "  << aux3 << endl;


  torneo(0);

  return 0;
}


