
/*
#include <iostream>
#include <vector>
#include <algorithm>

class Aeroflot {
public:
    int flightNumber;
    std::string departureCity;
    std::string destinationCity;
    std::string arrivalTime;
    std::string departureTime;
    std::string registrationSection;

    Aeroflot(int number, const std::string& departure, const std::string& destination,
        const std::string& arrival, const std::string& departureT, const std::string& registration)
        : flightNumber(number), departureCity(departure), destinationCity(destination),
        arrivalTime(arrival), departureTime(departureT), registrationSection(registration) {}

    // Перегрузка оператора < для сортировки по названию пункта назначения
    bool operator<(const Aeroflot& other) const {
        return destinationCity < other.destinationCity;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<Aeroflot> flights;

    // Ввод данных с клавиатуры
    int numberOfFlights;
    std::cout << "Введите количество рейсов: ";
    std::cin >> numberOfFlights;

    for (int i = 0; i < numberOfFlights; ++i) {
        int number;
        std::string departure, destination, arrival, departureTime, registration;

        std::cout << "Введите данные для рейса " << i + 1 << ":\n";
        std::cout << "Номер рейса: ";
        std::cin >> number;

        std::cout << "Пункт отправления: ";
        std::cin >> departure;

        std::cout << "Пункт назначения: ";
        std::cin >> destination;

        std::cout << "Время прибытия: ";
        std::cin >> arrival;

        std::cout << "Время отправления: ";
        std::cin >> departureTime;

        std::cout << "Номер секции для регистрации: ";
        std::cin >> registration;

        flights.emplace_back(number, departure, destination, arrival, departureTime, registration);
    }

    // Сортировка по названию пункта назначения
    std::sort(flights.begin(), flights.end());

    // Вывод на консоль
    std::cout << "\nТаблица рейсов:\n";
    std::cout << "-----------------------------------------------------------------------------\n";
    std::cout << "| № | Пункт отправления | Пункт назначения | Время прибытия | Время отправления | Место регистрации |\n";
    std::cout << "-----------------------------------------------------------------------------\n";

    if (flights.empty()) {
        std::cout << "Нет доступных рейсов.\n";
    }
    else {
        for (size_t i = 0; i < flights.size(); ++i) {
            const Aeroflot& flight = flights[i];
            std::cout << "| " << i + 1 << " | " << flight.departureCity << " | " << flight.destinationCity
                << " | " << flight.arrivalTime << " | " << flight.departureTime << " | "
                << flight.registrationSection << " |\n";
        }
    }

    std::cout << "-----------------------------------------------------------------------------\n";

    return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>

class Student {
public:
    std::string lastName;
    std::string firstName;
    std::string dateOfBirth;
    std::string phoneNumber;

    Student(const std::string& last, const std::string& first, const std::string& dob, const std::string& phone)
        : lastName(last), firstName(first), dateOfBirth(dob), phoneNumber(phone) {}

    // Перегрузка оператора < для сортировки по фамилии
    bool operator<(const Student& other) const {
        return lastName < other.lastName;
    }

    // Перегрузка оператора == для поиска по фамилии
    bool operator==(const std::string& targetLastName) const {
        return lastName == targetLastName;
    }
};

class StudentDatabase {
private:
    std::vector<Student> students;

public:
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    void removeStudent(const std::string& targetLastName) {
        auto it = std::remove_if(students.begin(), students.end(),
            [targetLastName](const Student& student) {
                return student == targetLastName;
            });

        students.erase(it, students.end());
    }

    Student* findStudent(const std::string& targetLastName) {
        auto it = std::find_if(students.begin(), students.end(),
            [targetLastName](const Student& student) {
                return student == targetLastName;
            });

        if (it != students.end()) {
            return &(*it);
        }
        else {
            return nullptr;
        }
    }

    void sortByLastName() {
        std::sort(students.begin(), students.end());
    }

    void displayStudents() const {
        std::cout << "------------------------------------------------------------------------\n";
        std::cout << "| Фамилия     | Имя          | Дата рождения | Телефон          |\n";
        std::cout << "------------------------------------------------------------------------\n";

        for (const auto& student : students) {
            std::cout << "| " << student.lastName << " | " << student.firstName
                << " | " << student.dateOfBirth << " | " << student.phoneNumber << " |\n";
        }

        std::cout << "------------------------------------------------------------------------\n";
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    StudentDatabase database;
    int choice;

    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Удалить студента\n";
        std::cout << "3. Найти студента по фамилии\n";
        std::cout << "4. Сортировать студентов по фамилии\n";
        std::cout << "5. Вывести список студентов\n";
        std::cout << "0. Выйти\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string last, first, dob, phone;
            std::cout << "Введите фамилию: ";
            std::cin >> last;
            std::cout << "Введите имя: ";
            std::cin >> first;
            std::cout << "Введите дату рождения: ";
            std::cin >> dob;
            std::cout << "Введите номер телефона: ";
            std::cin >> phone;

            database.addStudent(Student(last, first, dob, phone));
            break;
        }

        case 2: {
            std::string targetLastName;
            std::cout << "Введите фамилию студента для удаления: ";
            std::cin >> targetLastName;
            database.removeStudent(targetLastName);
            break;
        }

        case 3: {
            std::string targetLastName;
            std::cout << "Введите фамилию студента для поиска: ";
            std::cin >> targetLastName;
            Student* foundStudent = database.findStudent(targetLastName);
            if (foundStudent) {
                std::cout << "Студент найден:\n";
                std::cout << "Фамилия: " << foundStudent->lastName << "\n";
                std::cout << "Имя: " << foundStudent->firstName << "\n";
                std::cout << "Дата рождения: " << foundStudent->dateOfBirth << "\n";
                std::cout << "Телефон: " << foundStudent->phoneNumber << "\n";
            }
            else {
                std::cout << "Студент не найден.\n";
            }
            break;
        }

        case 4: {
            database.sortByLastName();
            std::cout << "Студенты отсортированы по фамилии.\n";
            break;
        }

        case 5: {
            database.displayStudents();
            break;
        }

        case 0:
            std::cout << "Программа завершена.\n";
            break;

        default:
            std::cout << "Некорректный выбор. Пожалуйста, выберите снова.\n";
        }
    } while (choice != 0);

    return 0;
}
*/
#include <iostream>
#include <fstream>
#include <stack>
#include <string>

class TrainSortingNode {
private:
    std::stack<std::string> leftDirection;   // Стек для левого направления
    std::stack<std::string> rightDirection;  // Стек для правого направления

public:
    // Добавление вагона в левое направление
    void addLeftWagon(const std::string& wagon) {
        leftDirection.push(wagon);
    }

    // Добавление вагона в правое направление
    void addRightWagon(const std::string& wagon) {
        rightDirection.push(wagon);
    }

    // Удаление вагона из вершины левого направления
    void removeLeftWagon() {
        if (!leftDirection.empty()) {
            leftDirection.pop();
        }
        else {
            std::cout << "Левое направление пусто.\n";
        }
    }

    // Удаление вагона из вершины правого направления
    void removeRightWagon() {
        if (!rightDirection.empty()) {
            rightDirection.pop();
        }
        else {
            std::cout << "Правое направление пусто.\n";
        }
    }

    // Вывод информации о состоянии узла
    void displayNodeState() const {
        std::cout << "Состояние узла:\n";
        std::cout << "Левое направление: ";
        displayStackContents(leftDirection);
        std::cout << "Правое направление: ";
        displayStackContents(rightDirection);
    }

private:
    // Вспомогательная функция для вывода содержимого стека
    void displayStackContents(const std::stack<std::string>& stack) const {
        if (stack.empty()) {
            std::cout << "Пусто\n";
        }
        else {
            std::stack<std::string> temp = stack;
            while (!temp.empty()) {
                std::cout << temp.top() << " ";
                temp.pop();
            }
            std::cout << "\n";
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    TrainSortingNode sortingNode;
    int choice;

    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Добавить вагон в левое направление\n";
        std::cout << "2. Удалить вагон из левого направления\n";
        std::cout << "3. Добавить вагон в правое направление\n";
        std::cout << "4. Удалить вагон из правого направления\n";
        std::cout << "5. Вывести состояние узла\n";
        std::cout << "0. Выйти\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string wagon;
            std::cout << "Введите тип вагона для левого направления: ";
            std::cin >> wagon;
            sortingNode.addLeftWagon(wagon);
            break;
        }

        case 2: {
            sortingNode.removeLeftWagon();
            break;
        }

        case 3: {
            std::string wagon;
            std::cout << "Введите тип вагона для правого направления: ";
            std::cin >> wagon;
            sortingNode.addRightWagon(wagon);
            break;
        }

        case 4: {
            sortingNode.removeRightWagon();
            break;
        }

        case 5: {
            sortingNode.displayNodeState();
            break;
        }

        case 0:
            std::cout << "Программа завершена.\n";
            break;

        default:
            std::cout << "Некорректный выбор. Пожалуйста, выберите снова.\n";
        }
    } while (choice != 0);

    return 0;
}
