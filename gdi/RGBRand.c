#include <windows.h>

void rgbRandom()
{
    HDC desk = GetDC(NULL);
    int w = GetSystemMetrics(SM_CXSCREEN);
    int h = GetSystemMetrics(SM_CYSCREEN);
    
    while (1)
    {
        SelectObject(desk, CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255)));
        PatBlt(desk, 0, 0, w, h, PATINVERT);
        Sleep(50);
    }
}

int main()
{
   rgbRandom();
   return 0;
}