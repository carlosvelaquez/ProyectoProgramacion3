#include "Runner.h"

int main(){
  Runner runner;
  int codigo = runner.run();

  if (codigo != 0) {
    std::cout << "[MAIN] Error en Runner. Salió con código " << codigo << '\n';
  }else{
    std::cout << "[MAIN] Runner salió con codigo 0." << '\n';
  }

  return 0;
}
