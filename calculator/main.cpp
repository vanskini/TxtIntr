#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>

const double PI = 3.14159265358979323846;

void help(const char* p) {
    std::cout << "Использование: " << p << " -o <asin|acos> [-m rad|deg] <число>\n"
              << "Пример: " << p << " -o asin -m deg 0.5\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) { help(argv[0]); return 0; }

    std::string op, mode = "rad";
    double x = 0;
    bool hasX = false;

    for (int i = 1; i < argc; ++i) {
        std::string a = argv[i];
        if ((a == "-o" || a == "--operation") && i + 1 < argc) op = argv[++i];
        else if ((a == "-m" || a == "--mode") && i + 1 < argc) mode = argv[++i];
        else if (a == "-h" || a == "--help") { help(argv[0]); return 0; }
        else { x = std::stod(a); hasX = true; }
    }

    if (op.empty() || !hasX) { help(argv[0]); return 1; }
    if (x < -1 || x > 1) {
        std::cerr << "Ошибка: аргумент должен быть в [-1, 1]\n";
        return 1;
    }

    double r;
    if (op == "asin") r = std::asin(x);
    else if (op == "acos") r = std::acos(x);
    else { std::cerr << "Неизвестная операция: " << op << "\n"; return 1; }

    if (mode == "deg") r = r * 180.0 / PI;

    std::cout << std::setprecision(10) << r << std::endl;
    return 0;
}
