//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <ctime>
//#include <cstring>
//
//#ifdef _WIN32
//#include <windows.h>
//#else
//#include <unistd.h>
//#endif
//
//class Timer {
//private:
//    int seconds;
//
//public:
//    // Конструктор для указания времени в секундах (целое число)
//    Timer(int initialSeconds) : seconds(initialSeconds) {}
//
//    // Конструктор для указания времени в формате строки "MM:SS"
//    Timer(const char* timeString) {
//        int minutes, seconds;
//        sscanf(timeString, "%d:%d", &minutes, &seconds);
//        this->seconds = minutes * 60 + seconds;
//    }
//
//    // Конструктор для указания времени в минутах и секундах
//    Timer(int minutes, int seconds) : seconds(minutes * 60 + seconds) {}
//
//    // Запуск таймера
//    void run() {
//        while (seconds > 0) {
//            displayTime();
//            sleep(1);
//            seconds--;
//        }
//        ringBell();
//    }
//
//private:
//    // Отображение текущего времени
//    void displayTime() {
//        int minutes = seconds / 60;
//        int remainingSeconds = seconds % 60;
//        std::cout << "Time left: " << minutes << " minutes and " << remainingSeconds << " seconds" << std::endl;
//    }
//
//    // Звонок колокола
//    void ringBell() {
//        std::cout << "\a\a\aRing! Ring! Ring!" << std::endl;
//    }
//
//    // Функция задержки для платформы Windows и Unix
//    void sleep(int seconds) {
//#ifdef _WIN32
//        Sleep(seconds * 1000);
//#else
//        usleep(seconds * 1000000);
//#endif
//    }
//};
//
//int main() {
//    // Примеры использования конструкторов
//    Timer timer1(300); // 300 секунд (5 минут)
//    Timer timer2("10:30"); // 10 минут и 30 секунд
//    Timer timer3(2, 45); // 2 минуты и 45 секунд
//
//    // Запуск таймеров
//    std::cout << "Timer 1:" << std::endl;
//    timer1.run();
//
//    std::cout << "Timer 2:" << std::endl;
//    timer2.run();
//
//    std::cout << "Timer 3:" << std::endl;
//    timer3.run();
//
//    return 0;
//}
//


//#include <iostream>
//#include <string>
//
//class Nomenclature {
//private:
//    std::string productName;
//    double wholesalePrice;
//    double retailMarkup;
//    int quantityInStock;
//
//public:
//    // Конструктор по умолчанию
//    Nomenclature() : productName(""), wholesalePrice(0.0), retailMarkup(0.0), quantityInStock(0) {}
//
//    // Конструктор с параметрами
//    Nomenclature(const std::string& name, double wholesale, double markup, int quantity)
//        : productName(name), wholesalePrice(wholesale), retailMarkup(markup), quantityInStock(quantity) {}
//
//    // Деструктор
//    ~Nomenclature() {
//        // Здесь можно добавить код для освобождения ресурсов, если это необходимо
//    }
//
//    // Функция для подсчета возможного чистого дохода при продаже товара
//    double calculateNetIncome() const {
//        double retailPrice = wholesalePrice * (1 + retailMarkup / 100);
//        return retailPrice * quantityInStock;
//    }
//
//    // Функция для вывода всех данных о товаре на экран
//    void displayProductInfo() const {
//        std::cout << "Product Name: " << productName << std::endl;
//        std::cout << "Wholesale Price: $" << wholesalePrice << std::endl;
//        std::cout << "Retail Markup: " << retailMarkup << "%" << std::endl;
//        std::cout << "Quantity in Stock: " << quantityInStock << std::endl;
//        std::cout << "Net Income: $" << calculateNetIncome() << std::endl;
//    }
//};
//
//int main() {
//    // Пример использования класса Nomenclature
//    Nomenclature product1("Widget", 10.0, 20.0, 100);
//
//    // Вывод информации о товаре
//    std::cout << "Product 1 Information:" << std::endl;
//    product1.displayProductInfo();
//
//    return 0;
//}



#include <iostream>
#include <string>
#include <ctime>

class Soft {
private:
    std::string programName;
    std::string developer;
    double diskSpace;
    time_t licenseExpirationDate;

public:
    // Конструктор по умолчанию
    Soft() : programName(""), developer(""), diskSpace(0.0), licenseExpirationDate(0) {}

    // Конструктор с параметрами
    Soft(const std::string& name, const std::string& dev, double space, time_t expirationDate)
        : programName(name), developer(dev), diskSpace(space), licenseExpirationDate(expirationDate) {}

    // Деструктор
    ~Soft() {
        // Здесь можно добавить код для освобождения ресурсов, если это необходимо
    }

    // Функция для подсчета количества дней до завершения лицензии
    int daysUntilLicenseExpires() const {
        time_t currentTime;
        time(&currentTime);
        double secondsRemaining = difftime(licenseExpirationDate, currentTime);
        return static_cast<int>(secondsRemaining / (60 * 60 * 24));
    }

    // Функция для вывода всех данных о программном обеспечении на экран
    void displaySoftwareInfo() const {
        std::cout << "Program Name: " << programName << std::endl;
        std::cout << "Developer: " << developer << std::endl;
        std::cout << "Disk Space: " << diskSpace << " GB" << std::endl;
        std::cout << "Days until License Expiration: " << daysUntilLicenseExpires() << " days" << std::endl;
    }
};

int main() {
    // Пример использования класса Soft
    time_t expirationDate;
    time(&expirationDate);
    expirationDate += 30 * 24 * 60 * 60;  // Добавим 30 дней к текущей дате

    Soft software1("MyApp", "MyCompany", 2.5, expirationDate);

    // Вывод информации о программном обеспечении
    std::cout << "Software 1 Information:" << std::endl;
    software1.displaySoftwareInfo();

    return 0;
}
