#pragma once
#using <System.Data.dll>          // чтобы пользоваться DataTable

using namespace System;
using namespace System::Data;

public ref class Function
{
private:
    double a, b, c;
    bool isQuadratic;             // true → y = a·x² + b·x + c ;  false → y = a·x + b

public:
    /* ----------  Конструкторы  ---------- */

    // y = x   (a = 1, b = 0), линейная
    Function() : a(1), b(0), c(0), isQuadratic(false) {}

    // y = a·x + b , линейная
    Function(double A, double B) : a(A), b(B), c(0), isQuadratic(false) {}

    // y = a·x² + b·x + c , квадратичная
    Function(double A, double B, double C) : a(A), b(B), c(C), isQuadratic(true) {}

    /* ----------  Свойства  ---------- */

    property double A {
        double get() { return a; }
        void set(double value) { a = value; }
    }
    property double B {
        double get() { return b; }
        void set(double value) { b = value; }
    }
    property double C {
        double get() { return c; }
        void set(double value) { c = value; }
    }

    property bool IsQuadratic {
        bool get() { return isQuadratic; }
        void set(bool value) { isQuadratic = value; }
    }

    /* ----------  Методы  ---------- */

    // Вычислить значение функции в точке x
    double Value(double x);

    // Получить таблицу значений в диапазоне [from .. to] с шагом step
    // (предполагается, что from ≤ to и step > 0 проверены на форме)
    DataTable^ GetTable(double from, double to, double step);
};
