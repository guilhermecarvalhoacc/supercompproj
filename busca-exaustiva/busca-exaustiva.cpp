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
    vector<int> cidades_idxs;
    for (int i = 0; i < N; i++) {
        cin >> y1;
        cin >> x1;
        Cidade c;
        c.x = x1;
        c.y = y1;
        c.id = i;
        cidades.push_back(c);
        cidades_idxs.push_back(c.id);
    }
    vector<Cidade> vetor_caminho= cidades;
    double distancia_resultado = INFINITY;
    while(next_permutation(cidades_idxs.begin(), cidades_idxs.end())){
        for (int i = 0; i < cidades_idxs.size(); i++)
        {
            vetor_caminho[i] = cidades[cidades_idxs[i]];
            
        }

        double nova_distancia = calcula_distancia(vetor_caminho);
        if (nova_distancia < distancia_resultado){
            distancia_resultado = nova_distancia;
            
        }

    }
    
    cout << distancia_resultado << " 1" << std::endl;
    int len_final = vetor_caminho.size();
    for (int i = 0; i < len_final; i++){
        std::cout << vetor_caminho[i].id<< " ";
    }
    cout << "" << std::endl;
    cout << "\n";

    return 0;
}

