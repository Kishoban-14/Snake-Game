#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    const char *s  = u8"\u0444";
    cout << s << endl;
    printf("%s\n", s);
}