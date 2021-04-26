#include "Graphs.h"

using namespace std;

Graphs::Graphs(float x = 1.0, float y = 1.0) :
    x(x), y(y)
{

}

Graphs::~Graphs()
{
    ReleaseDC(hwnd, hdc);
}

bool Graphs::InitWindowsApi()
{
    HWND hwnd = GetConsoleWindow();
    HDC hdc = GetDC(hwnd);
}

bool Graphs::DrawGraph()
{
    for (float iter = 0; iter < 3.14 * 10; iter += 0.05)
    {
        SetPixel(hdc, x, 50 + 25 * cos(iter), RGB(50, 200, 150));
        x += 0.1;
    }
}

int main()
{
    cin.ignore();

    return 0;
}
