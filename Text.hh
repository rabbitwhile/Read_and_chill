/** @file Text.hh
	@brief Classe Text
*/

#ifndef TEXT_HH
#define TEXT_HH

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include "Frase.hh"


using namespace std;

class Text{

	private:
		string titol;
		string autor;
		map<int,Frase> contingut;
		int numparaules;
		int numfrases;
		
                vector<pair<int,string> > taulafreq;
		
		bool sort_comp(const pair<int,string>& lhs, const pair<int,string>& rhs){
			return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second.size()<rhs.second.size() ) || (!(rhs.first<lhs.first) && !(rhs.second.size()<lhs.second.size() )&& lhs.second<rhs.second);
		}
		
	public:
		/* Constructores */

		/** @brief Creadora per defecte.
			\pre cert
			\post crea un text sense titol ni autor ni contingut(buit)
		*/ 
		Text();
	
		/* Destructora */
		
		/** @brief Destructora per defecte.
			\pre cert
			\post destrueix el text
		*/
		~Text();
		
		/* Modificadores*/

		
		
		/* Consultores */
		
		/** @brief el p.i te contingut
			\pre text triat
			\post nombre de frases del contingut del p.i 
		*/
		int const consultar_numfrases();
		
		/** @brief el p.i te contingut
			\pre text triat
			\post nombre de paraules del contingut del p.i
		*/
		int const consultar_numparaules();
		
		/** @brief el p.i te autor, titol i contingut
			\pre text triat
			\post mostra l'autor, titol, nombre de frases i de paraules i cites associades del p.i
		*/ 
		void const info_text();
		
		/** @brief el p.i te autor, titol i contingut
			\pre text triat
			\post mostra l'autor del p.i
		*/ 
		void const autor_text();
		
		/** @brief el p.i te autor, titol i contingut
			\pre text triat
			\post mostra el contingut del p.i dividit en les diferents frases que te per ordre d'entrada original del p.i
		*/ 
		void const contingut_text();
                
               
                
                /** @brief el p.i te contingut
			\pre text triat
			\post mostra el contingut del p.i dividit en les diferents frases que te per ordre d'escritura original del p.i
		*/ 
		void const taula_frequencies();
		
		/** @brief mostra les frases del p.i entre un interval concret
			\pre text triat
			\post mostra les diferentes frases entre la "x" i la "y" del p.i
		*/
		void const interval_frases(int x, int y);

		/** @brief mostra frases del p.i
			\pre text triat
			\post mostra frases del p.i segons lexpressio
		*/
		void const expressio_frases(string s1, string s2);

		/** @brief mostra frases del p.i
			\pre text triat
			\post mostra les diferents frases del p.i on apareix les paraules consecutives 
		*/
		void const paraules_frase(Frase k);
		
		/** @brief mostra les cites del p.i
			\pre text triat
			\post mostra totes les cites del p.i
		*/
		void const cites_text();
		
		/* Llegir */
		
		/** @brief llegeix el p.i
			\pre cert
			\post llegeix el titol, l'autor i el contigut del p.i
		*/
		void llegir_text();
};

#endif
