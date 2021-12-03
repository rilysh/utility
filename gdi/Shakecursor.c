#include <windows.h>

void cursorShake()
{
    HDC desk = GetDC(NULL);
    POINT mouse;
    int x, y;
    while (1)
    {
        GetCursorPos(&mouse);
        x = mouse.x, y = mouse.y;

        SetCursorPos(x + rand() % 3 + 1, y + rand() % 3 + 1);
        SetCursorPos(x - rand() % 3 + 1, y - rand() % 3 + 1);

        Sleep(10);
    }
}


int main()
{
    cursorShake();
    return 0;
}