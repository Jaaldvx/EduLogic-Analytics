#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <iomanip>

using namespace std;

// Clase Base para representar un Módulo de Aprendizaje
class ModuloAprendizaje {
protected:
    string nombreModulo;
    float puntaje;
public:
    ModuloAprendizaje(string n, float p) : nombreModulo(n), puntaje(p) {}
    virtual void analizarProgreso() = 0; // Método virtual puro (Polimorfismo)
    virtual ~ModuloAprendizaje() {}
};

// Módulo específico para Métodos Numéricos
class MetodosNumericos : public ModuloAprendizaje {
public:
    MetodosNumericos(float p) : ModuloAprendizaje("Metodos Numericos", p) {}
    
    void analizarProgreso() override {
        cout << "Modulo: " << nombreModulo << " | Puntaje: " << puntaje << endl;
        if (puntaje < 7.5) {
            cout << "  -> RECOMENDACION: Revisar precision de punto flotante y convergencia de Newton-Raphson." << endl;
        } else {
            cout << "  -> ESTADO: Dominio avanzado de metodos iterativos." << endl;
        }
    }
};

// Módulo específico para Lógica Digital (VHDL/Sistemas Combinacionales)
class LogicaDigital : public ModuloAprendizaje {
public:
    LogicaDigital(float p) : ModuloAprendizaje("Logica Digital", p) {}
    
    void analizarProgreso() override {
        cout << "Modulo: " << nombreModulo << " | Puntaje: " << puntaje << endl;
        if (puntaje < 7.5) {
            cout << "  -> RECOMENDACION: Fortalecer Tablas de Verdad y Mapas de Karnaugh." << endl;
        } else {
            cout << "  -> ESTADO: Competencia optima en diseno de hardware." << endl;
        }
    }
};

// Clase para gestionar el perfil del Estudiante
class Estudiante {
private:
    string nombre;
    vector<unique_ptr<ModuloAprendizaje>> modulos;
public:
    Estudiante(string n) : nombre(n) {}
    
    void agregarModulo(unique_ptr<ModuloAprendizaje> m) {
        modulos.push_back(move(m));
    }
    
    void mostrarReporte() {
        cout << "\n============================================" << endl;
        cout << "REPORTE ANALITICO DE: " << nombre << endl;
        cout << "============================================" << endl;
        for (auto& m : modulos) {
            m->analizarProgreso();
            cout << "--------------------------------------------" << endl;
        }
    }
};

int main() {
    // Inicialización del sistema EduLogic
    Estudiante jaqueline("Jaqueline Diaz");

    // Simulando datos reales de un semestre en la UNAM
    jaqueline.agregarModulo(make_unique<MetodosNumericos>(6.8));
    jaqueline.agregarModulo(make_unique<LogicaDigital>(9.2));

    // Ejecución del motor de diagnóstico
    jaqueline.mostrarReporte();

    return 0;
}
