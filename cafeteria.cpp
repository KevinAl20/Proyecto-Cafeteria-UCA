#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Cantidad de productos del menu
const int N = 8;

// Descuento aplicado a estudiantes UCA
const float DESCUENTO_ESTUDIANTE = 0.10;

// Muestra el menu principal del sistema
void mostrarMenuPrincipal()
{
    cout << "\n----------- MENU PRINCIPAL -----------\n";
    cout << "1. Menu\n";
    cout << "2. Pedido\n";
    cout << "3. Total\n";
    cout << "4. Modificar\n";
    cout << "5. Cancelar\n";
    cout << "6. Factura\n";
    cout << "7. Ventas\n";
    cout << "8. Salir\n";
    cout << "---------------------------------------\n";
}

// Muestra todos los productos disponibles
void mostrarProductos(string nombre[], float precio[], int stock[], int n)
{
    cout << "\n--- MENU DE PRODUCTOS ---\n";

    for (int i = 0; i < n; i++)
    {
        cout << (i + 1) << ". " << nombre[i] << " | Precio: $" << precio[i] << " | Stock: " << stock[i] << "\n";
    }
}

// Revisa si el pedido no tiene productos agregados
bool pedidoVacio(int pedidos[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (pedidos[i] > 0)
        {
            return false;
        }
    }

    return true;
}

// Calcula el subtotal multiplicando precio por cantidad
float calcularSubtotal(float precio[], int pedidos[], int n)
{
    float subtotal = 0;

    for (int i = 0; i < n; i++)
    {
        subtotal += precio[i] * pedidos[i];
    }

    return subtotal;
}

int main()
{
    // Arreglos paralelos del sistema
    string nombre[N] = {"Pupusa", "Baleada", "Sandwich", "Jugo", "Gaseosa", "Cafe", "Ensalada", "Pastel"};
    float precio[N] = {0.75, 1.25, 2.00, 1.00, 0.75, 0.50, 1.50, 1.00};
    int stock[N] = {50, 30, 20, 40, 60, 80, 15, 10};
    int pedidos[N] = {0};

    string nombreEstudiante;
    string carnet;
    char continuar;

    // Ciclo para atender a varios estudiantes
    do
    {
        cout << "\n--- NUEVO ESTUDIANTE ---\n";
        cout << "Nombre: ";
        getline(cin, nombreEstudiante);

        cout << "Carnet: ";
        getline(cin, carnet);

        char esEstudiante;
        cout << "¿Es estudiante UCA? (S/N): ";
        cin >> esEstudiante;
        cin.ignore(1000, '\n');

        // Se limpia el pedido al iniciar un nuevo estudiante
        for (int i = 0; i < N; i++)
        {
            pedidos[i] = 0;
        }

        int opcion;
        bool enMenu = true;

        // Ciclo del menu del estudiante actual
        while (enMenu)
        {
            mostrarMenuPrincipal();
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Opcion invalida.\n";
                continue;
            }

            cin.ignore(1000, '\n');

            switch (opcion)
            {
            case 1:
                mostrarProductos(nombre, precio, stock, N);
                break;

            case 2:
                cout << "\nOpcion de pedido en desarrollo.\n";
                break;

            case 3:
                cout << "\nOpcion de total en desarrollo.\n";
                break;

            case 4:
                cout << "\nOpcion de modificar en desarrollo.\n";
                break;

            case 5:
                cout << "\nOpcion de cancelar en desarrollo.\n";
                break;

            case 6:
                cout << "\nOpcion de factura en desarrollo.\n";
                break;

            case 7:
                cout << "\nOpcion de ventas en desarrollo.\n";
                break;

            case 8:
                cout << "\nSaliendo del menu...\n";
                enMenu = false;
                break;

            default:
                cout << "Opcion invalida.\n";
            }
        }

        cout << "\n¿Atender a otro estudiante? (S/N): ";
        cin >> continuar;
        cin.ignore(1000, '\n');

    } while (continuar == 'S' || continuar == 's');

    return 0;
}