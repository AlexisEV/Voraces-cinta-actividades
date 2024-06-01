#include <iostream>
#include <vector>
#include <algorithm>

struct fichero{
  int longitud;
  int id;
  fichero(int i, int l){
    id = i;
    longitud = l;
  }

  bool operator<(const fichero& otro) const{
    return longitud < otro.longitud;
  }

  fichero& operator=(const fichero& otro){
    if(this != &otro){
      id = otro.id;
      longitud = otro.longitud;
    }
    return *this;
  }
};

int almacenarCinta(std::vector<fichero>& ficheros){
  std::sort(ficheros.begin(),ficheros.end());
  int d = 0;
  for (int i = 0; i<ficheros.size();i++){
    d = d+ficheros[i].longitud*(ficheros.size()-i);
  }
  return d;
}

int main() {
  std::vector<fichero> ficheros = {{1,5},{2,10},{3,3}};
  int D = almacenarCinta(ficheros);
  std::cout << "Solucion, los ficheros deben estar ordenados de la siguiente manera para minimizar el tiempo de recuperación (D):\n\n";
  for (int i = 0; i<ficheros.size();i++){
    std::cout << i+1 << "° : fichero con el id " << ficheros[i].id << " y longitud " << ficheros[i].longitud << '\n';
  }
  std::cout << "\nEl D minimizado es: " << D;

}