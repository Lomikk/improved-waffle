#include "Function.h"

using namespace System;
using namespace System::Data;

/* ----------  ���������� ��������  ---------- */
double Function::Value(double x)
{
    if (isQuadratic)
        return a * x * x + b * x + c;
    else
        return a * x + b;
}

/* ----------  ���������� �������  ---------- */
DataTable^ Function::GetTable(double from, double to, double step)
{
    DataTable^ table = gcnew DataTable();
    table->Columns->Add("X", double::typeid);
    table->Columns->Add("Y", double::typeid);

    for (double x = from; x <= to + 1e-12; x += step)   // ��������� ������, ����� �������� to
    {
        double y = Value(x);
        DataRow^ row = table->NewRow();
        row["X"] = x;
        row["Y"] = y;
        table->Rows->Add(row);
    }
    return table;
}
