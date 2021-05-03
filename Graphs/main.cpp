#include <iostream>
#include "Graphs.h"

using namespace std;

int main(int argc, char *argv[])
{
    float x = 15;
    float y = 5;

    Graphs graphs(x, y);
    graphs.InitWindowsApi();
    graphs.DrawGraph();

    return 0;
}