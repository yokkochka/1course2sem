#include <iostream>
using namespace std;

int isNumber(char symb);
char* poiskNumberPstr(char* str, int& len);
void delNsymbl(char* str, int n);
void vstavkaPstr(char* str, char* pstr);
int dlina(char* str);
char* zamenaNumber(char* str, char* pstr, int& kol);


int dlina(char* str) {
    int dlina = 0;
    while (*str) {
        dlina++;
        str++;
    }
    return dlina;
}

int isNumber(char symb) {
    if ((symb >= '0') && (symb <= '9')) {
        return 1;
    }
    return 0;
}

char* poiskNumberPstr(char* str, int& len) {
    len = 0;
    char* start = str;
    while ((!isNumber(*start)) and (*start != '\0')) start++;

    char* temp = start;
    while (isNumber(*temp)) { len++; temp++; }

    if (len == 0)return 0;
    return start;
}


void delNsymbl(char* str, int n) {
    while (*str = *(str + n)) str++;
}

void vstavkaPstr(char* str, char* pstr) {
    int len = dlina(str);
    int lenPstr = dlina(pstr);
    char* vvv = str;
    for (str = str + len; str >= vvv; str--)
    {
        *(str + lenPstr) = *str;
    }
    for (int i = 0; *pstr; pstr++, vvv++)
    {
        *vvv =*pstr;
    }

    
}

char* zamenaNumber(char* str, char* pstr, int& kol)
{
    kol = 0;
    int len = 0;
    char* a = poiskNumberPstr(str, len);
    while (a != 0)
    {
        kol++;
        delNsymbl(a, len);
        vstavkaPstr(a, pstr);
        a = poiskNumberPstr(a, len);
    }
    return str;
}
