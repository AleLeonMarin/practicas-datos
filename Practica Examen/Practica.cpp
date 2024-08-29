#include <iostream>
#include <string>

using namespace std;

struct nodeSales
{
    int sales;
    nodeSales *next;
};

struct nodeEmployee
{
    string name;
    int totalSales;
    nodeEmployee *next;
    nodeSales *salesList;
};

struct nodeFloor
{
    int floor;
    double totalSales;
    nodeFloor *next;
    nodeFloor *prev;
    nodeEmployee *employeeList;
};

void insertFloor(nodeFloor *&head, int floor, double totalSales)
{
    nodeFloor *newNode = new nodeFloor();
    newNode->floor = floor;
    newNode->totalSales = totalSales;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    newNode->employeeList = nullptr;

    if (head == nullptr || head->floor > floor)
    {
        newNode->next = head;
        if (head != nullptr)
        {
            head->prev = newNode;
        }
        head = newNode;
    }
    else
    {
        nodeFloor *current = head;
        while (current->next != nullptr && current->next->floor < floor)
        {
            current = current->next;
        }
        newNode->next = current->next;
        if (current->next != nullptr)
        {
            current->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void insertEmployee(nodeEmployee *&list, string name, int totalSales)
{
    nodeEmployee *newNode = new nodeEmployee();
    newNode->name = name;
    newNode->totalSales = totalSales;
    newNode->next = nullptr;
    newNode->salesList = nullptr;

    if (list == nullptr || list->name > name)
    {
        newNode->next = list;
        list = newNode;
    }
    else
    {
        nodeEmployee *current = list;
        while (current->next != nullptr && current->next->name < name)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void insertSales(nodeSales *&list, int sales)
{
    nodeSales *newNode = new nodeSales();
    newNode->sales = sales;
    newNode->next = nullptr;

    if (list == nullptr || list->sales < sales)
    {
        newNode->next = list;
        list = newNode;
    }
    else
    {
        nodeSales *current = list;
        while (current->next != nullptr && current->next->sales > sales)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void showData(nodeFloor *building)
{
    nodeFloor *currentFloor = building;

    while (currentFloor != nullptr)
    {
        cout << "Piso: " << currentFloor->floor << " | Total de Ventas: " << currentFloor->totalSales << endl;

        nodeEmployee *currentEmployee = currentFloor->employeeList;
        while (currentEmployee != nullptr)
        {
            cout << "  Empleado: " << currentEmployee->name << " | Ventas: " << currentEmployee->totalSales << endl;

            nodeSales *currentSales = currentEmployee->salesList;
            cout << "    Ventas: ";
            while (currentSales != nullptr)
            {
                cout << currentSales->sales << " ";
                currentSales = currentSales->next;
            }
            cout << endl;

            currentEmployee = currentEmployee->next;
        }

        currentFloor = currentFloor->next;
        cout << endl;
    }
}

void revaluateFloor(nodeFloor *&building)
{

    nodeFloor *currentFloor = building;
    double totalSales = 0;
    double totalSalesEmployee = 0;

    while (currentFloor != nullptr)
    {
        nodeEmployee *currentEmployee = currentFloor->employeeList;
        while (currentEmployee != nullptr)
        {
            nodeSales *currentSales = currentEmployee->salesList;
            while (currentSales != nullptr)
            {

                totalSalesEmployee += currentSales->sales;
                currentSales = currentSales->next;
            }

            if (currentEmployee->totalSales != totalSalesEmployee)
            {
                cout << "El empleado " << currentEmployee->name << " del piso " << currentFloor->floor << " tiene un total de ventas incorrecto" << endl;
            }
            currentEmployee->totalSales = totalSalesEmployee;
            totalSales += totalSalesEmployee;
            totalSalesEmployee = 0;
            currentEmployee = currentEmployee->next;
        }

        if (currentFloor->totalSales != totalSales)
        {
            cout << "El piso " << currentFloor->floor << " tiene un total de ventas incorrecto" << endl;
        }
        currentFloor->totalSales = totalSales;
        totalSales = 0;
        currentFloor = currentFloor->next;
    }
}

void deleteFloor(nodeFloor *&head, int floor)
{
    nodeFloor *current = head;

    // Buscar el piso a eliminar
    while (current != nullptr && current->floor != floor)
    {
        current = current->next;
    }

    // Si no se encuentra el piso, terminar la función
    if (current == nullptr)
    {
        cout << "El piso no existe." << endl;
        return;
    }

    // Si es el primer piso y no tiene un piso anterior, no se puede reasignar
    if (current->prev == nullptr)
    {
        cout << "No se puede eliminar el primer piso." << endl;
        return;
    }

    // Reasignar empleados del piso eliminado al piso anterior
    nodeEmployee *currentEmployee = current->employeeList;
    nodeEmployee *&prevEmployeeList = current->prev->employeeList;

    while (currentEmployee != nullptr)
    {
        nodeEmployee *nextEmployee = currentEmployee->next;
        insertEmployee(prevEmployeeList, currentEmployee->name, currentEmployee->totalSales);

        // Reasignar las ventas del empleado
        nodeSales *salesList = currentEmployee->salesList;
        while (salesList != nullptr)
        {
            insertSales(prevEmployeeList->salesList, salesList->sales);
            salesList = salesList->next;
        }

        delete currentEmployee;
        currentEmployee = nextEmployee;
    }

    // Actualizar las sumas de ventas para el piso anterior
    revaluateFloor(head);

    // Eliminar el nodo del piso
    if (current->next != nullptr)
    {
        current->next->prev = current->prev;
    }
    if (current->prev != nullptr)
    {
        current->prev->next = current->next;
    }

    delete current;
}

int main()
{

    nodeFloor *building = nullptr;

    // Insertando pisos

    insertFloor(building, 4, 1150);
    insertFloor(building, 3, 800);
    insertFloor(building, 2, 0);
    insertFloor(building, 1, 1600);

    // Insertando empleados y ventas en Piso 1
    insertEmployee(building->employeeList, "Pedro", 1600);
    insertSales(building->employeeList->salesList, 1000);
    insertSales(building->employeeList->salesList, 500);
    insertSales(building->employeeList->salesList, 0);

    // Insertando empleados y ventas en Piso 2
    insertEmployee(building->next->next->employeeList, "Juan", 800);
    insertSales(building->next->next->employeeList->salesList, 700);

    // Insertando empleados y ventas en Piso 3
    insertEmployee(building->next->next->next->employeeList, "Maria", 1150);
    insertSales(building->next->next->next->employeeList->salesList, 400);
    insertSales(building->next->next->next->employeeList->salesList, 650);

    cout << "-----------------------------------" << endl;
    cout << "Datos iniciales" << endl;
    // Mostrando los datos
    showData(building);

    cout << "-----------------------------------" << endl;
    cout << "Datos revaluandose" << endl;

    revaluateFloor(building);

    cout << "-----------------------------------" << endl;
    cout << "Datos revaluados" << endl;
    showData(building);

    cout << "-----------------------------------" << endl;
    cout << "Insercion de nuevo empleado" << endl;
    insertFloor(building, 5, 0);

    insertEmployee(building->next->next->next->next->employeeList, "Carlos", 1600);
    insertSales(building->next->next->next->next->employeeList->salesList, 800);
    insertSales(building->next->next->next->next->employeeList->salesList, 800);

    showData(building);

    cout << "-----------------------------------" << endl;
    cout << "Datos revaluandose" << endl;

    revaluateFloor(building);
    cout << "-----------------------------------" << endl;
    cout << "Datos revaluados" << endl;

    showData(building);

    cout << "-----------------------------------" << endl;
    cout << "Eliminando piso 5" << endl;

    cout << "-----------------------------------" << endl;
    cout << "Edicion del edificio" << endl;
    deleteFloor(building, 5);

    cout << "-----------------------------------" << endl;
    cout << "Estado actual del edificio" << endl;

    showData(building);

    return 0;
}
