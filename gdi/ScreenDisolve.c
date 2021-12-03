#include <windows.h>

void screenDissolve()
{
    HDC hdc = GetDC(NULL);
    int w = GetSystemMetrics(SM_CXSCREEN);
    int h = GetSystemMetrics(SM_CYSCREEN);
    
    while (1)
    {
        StretchBlt(hdc, 1, -1, w, h, hdc, 0, 0, w, h, SRCINVERT);
    }
}

int main()
{
    screenDissolve();
    return 0;
}
