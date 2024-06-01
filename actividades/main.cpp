#include <iostream>
#include <vector>
#include <algorithm>

struct actividad{
  char id;
  int inicio;
  int final;
  int duracion;
  actividad(char d,int i, int f){
    id = d;
    inicio = i;
    final = f;
    duracion = final-inicio;
  }
  bool operator<=(const actividad& otro) const{
    return final<=otro.final;
  }
  bool operator<(const actividad& otro) const{
    return final<otro.final;
  }

  actividad& operator=(const actividad& otro){
    if (this != &otro){
      inicio = otro.inicio;
      final = otro.final;
    }
    return *this;
  }
};

void seleccionActividades(std::vector<actividad>& actividades, std::vector<actividad>& S){
  std::sort(actividades.begin(),actividades.end());
  S.push_back(actividades[0]);
  int i = 1;
  int prev = 0;
  while(i<actividades.size()){
    actividad x = actividades[i];
    if(x.inicio >= S[prev].final){
      S.push_back(x);
      prev++;
    }
    i++;
  }
}

int main() {
  std::vector<actividad> actividades = {
    {'B',2,5},
    {'C',4,6},
    {'A',1,7},
    {'E',5,8},
    {'D',4,9},
    {'F',6,10},
    {'G',7,11},
    {'H',9,12}
  };
  std::vector<actividad> S;
  seleccionActividades(actividades, S);

  std::cout << "Solución, Las actividades a seleccionar son las siguientes:\n\n";
  for(int i =0; i<S.size();i++){
    std::cout<< i+1 <<"° Actividad " << S[i].id << '\n';
  }
  
  
}