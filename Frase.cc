#include "Frase.hh"
#include <vector>
#include <sstream>
#include <string>
#include "Taulesaux.hh"

/* Constants */

const char *ER1 = "error";
#include <exception>

Frase::Frase() {
	num_paraules = 0;
}

Frase::~Frase() {}

void Frase::llegir_frase(string s, Taulesaux &tau, int numf) {
    string ant;
		 string op;
		 istringstream iss(s);
		 iss >> op;
		 int l = op.size();
   		 while (char(op[l-1]) != '.' and char(op[l-1]) != '?' and char(op[l-1]) != '!') {
    		if (char(op[l-1]) == ',' or char(op[l-1]) == ':' or char(op[l-1]) == ';') {
    			string tmp = op;
    			op.erase(l-1);
    			frase_in.push_back(make_pair(op, ant));
    			/*
    			int apuntador = map.find(op);
				vector<int> v = apuntador->second;
				v.push_back(numf);
				map.erase(op);
				map.insert(make_pair(op, v));
    			*/
    			tau.insertar_paraula(op, numf);
    			ant = op;
    			string c;
    			char car = tmp[l-1];
   		 		if (car == ',') c = ",";
   		 		else if (car == ':') c = ":";
   		 		else c = ";";
    			frase_in.push_back(make_pair(c, ant));
    			ant = c;
    		}
    		else {
    			frase_in.push_back(make_pair(op, ant));
    			tau.insertar_paraula(op, numf);
    		    ant = op;
    	    }
    		++num_paraules;
    		ws(iss);
    		iss >> op;
    		l = op.size();
   		 }
   		 
   		 char car = op[l-1];
   		 string c;
   		 if (car == '.') c = ".";
   		 else if (car == '?') c = "?";
   		 else c = "!";
   		 op.erase(l-1);
   		 frase_in.push_back(make_pair(op, ant));
   		 frase_in.push_back(make_pair(c, ant)); 
   		 ++num_paraules;
}

void const Frase::escriu_frase() {
	int x = frase_in.size();
	bool primer = true;
	for (int i = 0; i < x; ++i) {
		if (primer) {
			cout << frase_in[i].first;
			primer = false;
		}
		else if (i < x-1) {
			if (frase_in[i].first == "," or frase_in[i].first == ":" or frase_in[i].first == ";") {
				cout << frase_in[i].first;
			}
			else cout << " " << frase_in[i].first;
		}
		else cout << frase_in[i].first;
	}
	cout << endl;
}

int const Frase::consultar_numparaules() {
	return num_paraules;
}

bool const Frase::trobat(string s) {
	int x = frase_in.size();
	bool trobat = false;
	string actual, ant;
	istringstream iss(s);
	iss >> actual;
	int i;
	int k = s.size();
	for (i = 0; i < x and not trobat; ++i) {
		if (actual == frase_in[i].first) trobat = true;
	}
	if (trobat) {
		ant = frase_in[i].second;
		iss >> actual;
		--k;
		while (k > 0 and i<x) {
			if (frase_in[i].first == actual) {
				if (frase_in[i].second != ant) return false; 
			}
			ant = frase_in[i].first;
			iss >> actual;
			--k;
			++i;
		}
		return true;
	}
	return false;
}

void Frase::canvi_paraules(string s1, string s2) {
	int x = frase_in.size();
	for (int i = 0; i < x; ++i) {
		if (s1 == frase_in[i].first) {
			frase_in[i].first = s2;
		}
	}
	//CRIDAR A LA TAULA DE FREQUENCIA
}
