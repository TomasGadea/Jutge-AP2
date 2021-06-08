// Grups d'amics  (Ricard Tarré Mira)

#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

typedef map<string,string> grups;
typedef map<string,int> contador;

string dad(grups& G, string s){
	if(G[s] == s) return s;
	return G[s] = dad(G,G[s]);
}
void insert_noms_en_cicle(grups& G,string inici_cicle,vector<string>& not_used, contador& C){
	for(int i = 0; i < not_used.size(); ++i){ G.insert({not_used[i],inici_cicle});}
	string pare = dad(G, inici_cicle);
    C[pare] += not_used.size();
}
void junta_cicles(grups& G,string inici_cicle,string secon_cicle, contador& C){
	string pare = dad(G, inici_cicle);
    string pare2 = dad(G, secon_cicle);
    if(pare != pare2){
    G[pare] = pare2;
    C[pare2] += C[pare];
    C.erase(pare);
    }
}
void create_cicle(grups& G,vector<string>& not_used, contador& C){
	G.insert({not_used[0],not_used[0]});
	for(int i = 0; i < not_used.size(); ++i){ G.insert({not_used[i], not_used[0]});}
	C.insert({not_used[0],not_used.size()});
}

int main(){
     char accio;
     grups G;
     contador C;
     int n;
     string paraula;
     while(cin >> accio){
     	if(accio == 'F'){
             cin >> n;
             vector<string> not_used;
             string inici_cicle;
             bool cicle = false;
             for(int i = 0; i < n; ++i){
             	cin >> paraula;
             	if(G.count(paraula) > 0){
                    if(!cicle){
                    	inici_cicle = paraula;
                    	if(not_used.size()>0){
                    	    insert_noms_en_cicle(G, inici_cicle, not_used, C);

                        }
                        cicle = true;
                    }
                    else{
                    	junta_cicles(G,inici_cicle,paraula, C);
                    }
             	}
             	else{
                    if(!cicle){
                        not_used.push_back(paraula);
                    }
                    else{
                        vector<string> unic;
            			unic.push_back(paraula);
                        insert_noms_en_cicle(G, inici_cicle, unic, C);
                    }
             	}
             }
             if(!cicle) create_cicle(G, not_used, C);
     	}
     	else{
     		cin >> paraula;
     		if(G.count(paraula) > 0){
     			cout << paraula << ": " << C[dad(G, paraula)] << endl;
     		}
     		else{
     			cout << paraula << ": error" << endl;
     		}
     	}
     }
}
