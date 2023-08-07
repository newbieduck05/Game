#include "DoubleBuffer.h"

void DoubleBuffer::InitBuffer()
{
    screenIndex = 0;
    COORD size = { BufferWidth, BufferHeight };

    SMALL_RECT rect = { 0,0, BufferWidth, BufferHeight };
    
    hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    SetConsoleScreenBufferSize(hBuffer[0], size);
    
    SetConsoleWindowInfo(hBuffer[0], TRUE, &rect);
   
    hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    
    SetConsoleScreenBufferSize(hBuffer[1], size);
    
    SetConsoleWindowInfo(hBuffer[1], TRUE, &rect);
   
    CONSOLE_CURSOR_INFO Info;
    Info.dwSize = 1;
    Info.bVisible = FALSE;
    
    SetConsoleCursorInfo(hBuffer[0], &Info);
    SetConsoleCursorInfo(hBuffer[1], &Info);
}

void DoubleBuffer::FlipBuffer()
{
    SetConsoleActiveScreenBuffer(hBuffer[screenIndex]);
    
    screenIndex = !screenIndex;
}

void DoubleBuffer::ClearBuffer()
{
    COORD pos = { 0, 0 };
    DWORD dw;

    FillConsoleOutputCharacter(hBuffer[screenIndex], ' ', BufferWidth * BufferHeight, pos, &dw);
}

void DoubleBuffer::WriteBuffer(int x, int y, const char* shape, int color)
{
    COORD pos = { x * 2, y };
    
    SetConsoleCursorPosition(hBuffer[screenIndex], pos);
    
    SetConsoleTextAttribute(hBuffer[screenIndex], color);
    
    DWORD dw;
    WriteFile(hBuffer[screenIndex], shape, strlen(shape), &dw, NULL);
}

void DoubleBuffer::DestroyBuffer()
{
    CloseHandle(hBuffer[0]);
    CloseHandle(hBuffer[1]);
}
