#include <windows.h>

DWORD TransparentBlt_run(LPVOID unref)
{
    UNREFERENCED_PARAMETER(unref);
    HDC hdc = GetDC(GetDesktopWindow());
    int w = GetSystemMetrics(SM_CXSCREEN);
    int h = GetSystemMetrics(SM_CYSCREEN);

    COLORREF colorref = (RGB(rand() % 255, rand() % 255, rand() % 255));
    while (1)
    {
        TransparentBlt(hdc, rand() % 255, rand() % 255, w, h, hdc, rand() % 255, rand() % 255, rand() % 255, rand() % 255, colorref);
    }
    DeleteDC(hdc); // If reached not possible as it's in (while)
}

int main()
{
    HANDLE handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)TransparentBlt_run, 0, 0, 0);
    if (handle == INVALID_HANDLE_VALUE) return FALSE;
    WaitForSingleObject(handle, INFINITE);
    return 0;
}
