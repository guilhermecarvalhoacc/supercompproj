#include <algorithm>
#include <iostream>
#include <string>   
#include <vector>
#include<math.h>

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

Cidade cidade_mais_proxima(Cidade cidade, std::vector<Cidade> cidades){

    int len = cidades.size();
    double d;
    double min_d=100000000000;
    Cidade cidade_mais_proxima = cidade;
    for (int i = 0; i < len; i++) {
        Cidade c = cidades[i];
        d = distancia(cidade,c);
        if (d < min_d && c.id != cidade.id){
            min_d = d;
            cidade_mais_proxima = c;
        }
    }
    return cidade_mais_proxima;
}

int main(){
    int N;
    double x1;
    double y1;
    std::cin >> N;
    std::vector<Cidade> cidades;
    for (int i = 0; i < N; i++) {
        std::cin >> y1;
        std::cin >> x1;
        Cidade c;
        c.x = x1;
        c.y = y1;
        c.id = i;
        cidades.push_back(c);
    }
    Cidade cidade_ataul = cidades[0];
    std::vector<Cidade> caminho;
    caminho.push_back(cidade_ataul);
    cidades.erase(cidades.begin() + 0);
    while (cidades.size() != 0){
        Cidade cidade_mp = cidade_mais_proxima(cidade_ataul,cidades);
        for (int i = 0; i < cidades.size(); i++)
            if (cidades[i].id == cidade_mp.id){
                cidades.erase(cidades.begin() + i);
            }
        caminho.push_back(cidade_mp);
        cidade_ataul = cidade_mp;
    }

    double total;
    for (int i = 0; i < caminho.size(); i++){
        double dist;
        if (i < caminho.size()-1)
            dist = distancia(caminho[i],caminho[i+1]);
        else
            dist = distancia(caminho[i],caminho[0]);
        total = total + dist;
        
    }
    std::cout << total << " 0" << std::endl;
    int len_caminho = caminho.size();
    for (int i = 0; i < len_caminho; i++){
        std::cout << caminho[i].id << " ";
    }
    std::cout << "" << std::endl;

    return 0;
}
