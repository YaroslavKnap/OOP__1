#include <iostream>
#include <cmath>
#include <cstdlib>

class FunctionCalculator {
public:
    // функція яка рахує a
    static double calculateA(double x, double y, double z, double b) {
        return (pow(1 + y, 2) * pow(fabs(x + y), 0.3)) / (pow(b, 2) + z / (1 + exp(-(x - z))) + pow(fabs(y), 0.43));
    }

    // функція яка рахує b
    static double calculateB(double x, double y, double z) {
        return x * (y + atan(fabs(x * x + z) / (2 * z + x + sin(y) * sin(y) + exp(-x + z) / (z + 1))));
    }
};

class Data {
public:
    double x, y, z, b;

    void setdata(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->b = FunctionCalculator::calculateB(x, y, z);
    }

    double a() {
        return FunctionCalculator::calculateA(x, y, z, b);
    }
};

int main() {
    double x = 0.48 * 10;
    double y = 0.47 * 10;
    double z = -1.32 * 10;

    // рахуємо b[x, y, z]
    double resultB = FunctionCalculator::calculateB(x, y, z);

    // рахуємо a[x, y, z, b]
    double resultA = FunctionCalculator::calculateA(x, y, z, resultB);

    // вивід результатів 
    std::cout << "znachennya b[x, y, z] = " << resultB << std::endl;
    std::cout << "znachennya a[x, y, z, b] = " << resultA << std::endl;

    // друге завдання
    Data data;
    for (double i = -1; i < 1; i += 0.2) 
    {
        data.setdata(i, y, z);
        std::cout << "Calculation a for x=" << i << ": " << data.a() << std::endl;
    }

    return 0;
}
