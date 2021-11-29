#include <windows.h>
#define PI 3.141592653589793

double FastSin(double x)
{
    x /= 2 * PI;
    x -= (int) x;

    if (x <= 0.5) {
        double t = 2 * x * (2 * x - 1);
        return (PI * t) / ((PI - 4) * t - 1);
    }
    else
    {
        double t = 2 * (1 - x) * (1 - 2 * x);
        return -(PI * t) / ((PI - 4) * t - 1);
    }
}

DWORD Sinewave(LPVOID unref)
{
    UNREFERENCED_PARAMETER(unref);
    HDC hdc = GetDC(GetDesktopWindow());
    int w = GetSystemMetrics(SM_CXSCREEN);
    int h = GetSystemMetrics(SM_CYSCREEN);
    double angle = 0;

    while (1)
    {
        for (float i = 0; i < w + h; i += .99f)
        {
            int sin_pos = FastSin(angle) * 20;
            BitBlt(hdc, 0, i, w, 1, hdc, sin_pos, i, SRCCOPY);
            BitBlt(hdc, i, 0, 1, h, hdc, i, sin_pos, SRCCOPY);
            angle += PI / 40;
        }
        DeleteDC(hdc);
    }
}

int main()
{
    HANDLE handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Sinewave, 0, 0, 0);
    if (handle == INVALID_HANDLE_VALUE) return FALSE;
    WaitForSingleObject(handle, INFINITE);
    return 1;
}
