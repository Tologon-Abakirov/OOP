#include <iostream>
#include "ConsoleApplication1.h"
#include <string>
using namespace std;

/*
double power(double n, int p);
int main() {
    setlocale(LC_ALL, ("ru"));
    double base;
    cout << "Введите число n: ";
    cin >> base;
    int exponent;
    cout << "Введите степень : ";
    cin >> exponent;
    double result = power(base, exponent);
    cout << "Результат: " << result << endl;
    return 0;
}
double power(double n, int p) {
    if (p <= 2) {
        return n * n;
    }
    double result = 1.0;
    for (int i = 0; i < p; ++i) {
        result *= n;
    }
    return result;
}
*/



/*
double power(double n, int p = 2) {
    if (p <= 2) {
        return n * n;
    }
    double result = 1.0;
    for (int i = 0; i < p; ++i) {
        result *= n;
    }
    return result;
}
char power(char n, int p = 2) {
    return power(static_cast<double>(n), p);
}
short int power(short int n, int p = 2) {
    return power(static_cast<double>(n), p);
}
long int  power(long int n, int p = 2) {
    return power(static_cast<double>(n), p);
}

float power(float n, int p = 2) {
    return power(static_cast<double>(n), p);
}

int main() {
   cout << "double: " << power(2.5) << endl;
   cout << "char: " << power('A') << endl;
   cout << "long int: " << power(1000000L) << endl;
   cout << "float: " << power(3.14f) << endl;

    return 0;
}


*/



#include <iostream>
#include <string>

// Структура для хранения информации о работнике
struct Worker {
    std::string surname;
    int age;
    std::string specialization;
    double averageSalary;
};

// Функция для ввода информации о работниках на одном заводе
void inputWorkersInfo(Worker workers[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "Введите информацию о работнике #" << i + 1 << ":" << std::endl;
        std::cout << "Фамилия: ";
        std::cin >> workers[i].surname;
        std::cout << "Возраст: ";
        std::cin >> workers[i].age;
        std::cout << "Специальность: ";
        std::cin >> workers[i].specialization;
        std::cout << "Средний оклад: ";
        std::cin >> workers[i].averageSalary;
        std::cout << std::endl;
    }
}

// Функция для подсчета количества слесарей и токарей на заводе
void countSpecializations(const Worker workers[], int size, int& numLocksmiths, int& numTurners) {
    for (int i = 0; i < size; ++i) {
        if (workers[i].specialization == "слесарь") {
            ++numLocksmiths;
        }
        else if (workers[i].specialization == "токарь") {
            ++numTurners;
        }
    }
}

int main() {
    int numFactories;
    std::cout << "Введите количество заводов: ";
    std::cin >> numFactories;

    const int maxWorkersPerFactory = 3; // Предположим, что максимальное количество работников на заводе - 3

    int totalNumLocksmiths = 0;
    int totalNumTurners = 0;

    for (int factoryIndex = 0; factoryIndex < numFactories; ++factoryIndex) {
        Worker factoryWorkers[maxWorkersPerFactory];

        int numWorkers;
        std::cout << "Введите количество работников на заводе " << factoryIndex + 1 << ": ";
        std::cin >> numWorkers;

        inputWorkersInfo(factoryWorkers, numWorkers);

        int numLocksmiths = 0;
        int numTurners = 0;
        countSpecializations(factoryWorkers, numWorkers, numLocksmiths, numTurners);

        totalNumLocksmiths += numLocksmiths;
        totalNumTurners += numTurners;

        std::cout << "На заводе #" << factoryIndex + 1 << " количество слесарей: " << numLocksmiths
            << ", количество токарей: " << numTurners << std::endl;
    }

    std::cout << "Общее количество слесарей: " << totalNumLocksmiths << std::endl;
    std::cout << "Общее количество токарей: " << totalNumTurners << std::endl;

    return 0;
}
