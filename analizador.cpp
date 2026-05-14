#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Estudiante {
    string nombre;
    float calificacionMetodos;
    float calificacionCircuitos;
};

void generarRecomendacion(Estudiante e) {
    cout << "--- Analisis de EduLogic para: " << e.nombre << " ---" << endl;
    
    if (e.calificacionMetodos < 7.0) {
        cout << "[!] Alerta: Reforzar Metodos Numericos (Error de truncamiento)." << endl;
    } else {
        cout << "[+] Dominio aceptable en Metodos Numericos." << endl;
    }

    if (e.calificacionCircuitos < 7.0) {
        cout << "[!] Alerta: Revisar leyes de Kirchhoff y analisis de nodos." << endl;
    } else {
        cout << "[+] Dominio aceptable en Circuitos Electricos." << endl;
    }
    cout << "-------------------------------------------" << endl;
}

int main() {
    // Simulacion de datos de entrada
    Estudiante usuario = {"Jacqueline Diaz", 6.5, 8.5};
    generarRecomendacion(usuario);
    
    return 0;
}
