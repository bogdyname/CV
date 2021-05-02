#include "Graphs.h"

using namespace std;

Graphs::Graphs(float x, float y) :
    x(x), y(y)
{

}

Graphs::~Graphs()
{
    ReleaseDC(hwnd, hdc);
}

bool Graphs::InitWindowsApi()
{
    hwnd = GetConsoleWindow();
    hdc = GetDC(hwnd);

    return true;
}

bool Graphs::DrawGraph()
{
    for (float iter = 0; iter < 3.14 * 10; iter += 0.05)
    {
        SetPixel(hdc, x, 50 + 25 * cos(iter), RGB(50, 200, 150));
        x += 0.1;
    }

    cin.ignore();
    return true;
}
