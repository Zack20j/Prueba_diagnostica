// Implemente reconocimiento de cadenas, expresiones 
// notación científica, ip, correo electrónico.


#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string cadena;
    std::cout << "Ingrese una cadena: ";
    std::getline(std::cin, cadena);

    // 1.23e10
    // -3E-5
    // 2e+8
    std::regex regex_scientific(R"(^[+-]?(\d+(\.\d+)?)[eE][+-]?\d+$)");

    //123.232.56.789
    //444.23.56.1
    std::regex regex_ip(R"(^((25[0-5]|2[0-4]\d|1\d{2}|[1-9]?\d)\.){3}(25[0-5]|2[0-4]\d|1\d{2}|[1-9]?\d)$)");
    //yjoedaniels@gmail.com
    //dsjdsd_fd@gmail.com
    std::regex regex_email(R"(^[\w\.-]+@[\w\.-]+\.\w{2,}$)");

    if (std::regex_match(cadena, regex_scientific))
        std::cout << "Notacion cientifica\n";
    else if (std::regex_match(cadena, regex_ip))
        std::cout << "Direccion IP\n";
    else if (std::regex_match(cadena, regex_email))
        std::cout << "Correo electronico\n";
    else
        std::cout << "No reconocido\n";

    return 0;
}
