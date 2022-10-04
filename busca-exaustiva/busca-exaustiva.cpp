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
    float x, y;
};
 
float distancia(Cidade cA, Cidade cB)
{
    float distanciaX = pow(cA.x - cB.x, 2);
    float distanciaY = pow(cA.y - cB.y, 2);
    float distancia = sqrt(distanciaX + distanciaY);
    return distancia;
}


float calcula_distancia(vector<Cidade> cidades)
{   
    float total;
    for (int i = 0; i < cidades.size(); i++){
        float dist;
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
    float x1;
    float y1;
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
    float distancia_resultado = INFINITY;
    vector<Cidade> vetor_final;
    int num_leaf = 0;
    while(next_permutation(cidades_idxs.begin(), cidades_idxs.end())){
        for (int i = 0; i < cidades_idxs.size(); i++)
        {
            vetor_caminho[i] = cidades[cidades_idxs[i]];
            
        }

        float nova_distancia = calcula_distancia(vetor_caminho);
        if (nova_distancia < distancia_resultado){
            distancia_resultado = nova_distancia;
            vetor_final = vetor_caminho;
            ++num_leaf;
            
        }

    }
    cerr << "num_leaf " << num_leaf << endl;
    cout << distancia_resultado << " " << 1 << endl;
    int len_final = vetor_final.size();
    for (int i = 0; i < len_final; i++){
        cout << vetor_final[i].id<< " ";
    }
    cout << endl;
    

    return 0;
}

