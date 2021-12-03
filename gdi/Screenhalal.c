#include <windows.h>
void screenVivorachivatel()
    {
		int sw = GetSystemMetrics(SM_CXSCREEN);
		int sh = GetSystemMetrics(SM_CYSCREEN);
		HDC desk = GetDC(0);
        int n = 10;

        while (1)
        {
            StretchBlt(desk, n, n, sw - n * 2, sh - n * 2, desk, 0, 0, sw, sh, SRCCOPY);
            if (n < sw) n += 12;
            if (n > sh) n = 4;
        }
    }
	int main() 
	{
		screenVivorachivatel();
	}
	