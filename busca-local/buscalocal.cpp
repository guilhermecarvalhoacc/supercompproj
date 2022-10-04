#include <algorithm>
#include <iostream>
#include <string>   
#include <vector>
#include<math.h>
#include <random>       
#include <chrono>   
using namespace std;

struct Cidade
{
    int id;
    double x, y;
};
 
double distancia(Cidade cA, Cidade cB)
{
    double distanciaX = pow(cA.x - cB.x, 2);
    double distanciaY = pow(cA.y - cB.y, 2);
    double distancia = sqrt(distanciaX + distanciaY);
    return distancia;
}


double calcula_distancia(vector<Cidade> cidades)
{   
    double total;
    for (int i = 0; i < cidades.size(); i++){
        double dist;
        if (i < cidades.size()-1)
            dist = distancia(cidades[i],cidades[i+1]);
        else
            dist = distancia(cidades[i],cidades[0]);
        total = total + dist;
        
    }
    return total;
}


int main(){
    int N;
    double x1;
    double y1;
    cin >> N;
    vector<Cidade> cidades;
    for (int i = 0; i < N; i++) {
        cin >> y1;
        cin >> x1;
        Cidade c;
        c.x = x1;
        c.y = y1;
        c.id = i;
        cidades.push_back(c);
    }
    unsigned seed = 10;

    shuffle (cidades.begin(), cidades.end(), default_random_engine(seed));
    

    vector<Cidade> vetor_solucao = cidades;
    double distancia_total = 1000000;
    vector<Cidade> vetor_final = cidades;
    double nova_distancia;
    for (int i = 0; i < 10*N; i++){

        for (int j = 0; j < cidades.size() - 1; j++){
            nova_distancia = calcula_distancia(vetor_solucao);
            if(nova_distancia < distancia_total){
                distancia_total = nova_distancia;
                vetor_final = vetor_solucao; 
            }  
            swap(vetor_solucao[j], vetor_solucao[j + 1]);
        }
        cerr << "local: " << distancia_total << " ";
        int len_final2 = vetor_final.size();
        for (int i = 0; i < len_final2; i++){
            cerr<< vetor_final[i].id << " ";
        }
        cerr << std::endl;


    }
    cout << distancia_total << " 0" << std::endl;
    int len_final = vetor_final.size();
    for (int i = 0; i < len_final; i++){
        std::cout << vetor_final[i].id << " ";
    }
    cout << "" << std::endl;

    return 0;
}

