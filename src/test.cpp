#define _CRT_STDIO_ISO_WIDE_SPECIFIERS
#define MGL_STATIC_DEFINE
#include <iostream>
#include "expoperate.hpp"
#include <cstdio>
#include <string>
#include <windows.h>
// #include <mgl2/mgl.h>
using namespace std;

extern int words, chars, lines, a;
extern int yyparse(void);
double originx, originy, rotate, scalex = 1, scaley = 1;
extern string s;
extern FILE *yyin;
string subreplace(string resource_str, string sub_str, string new_str);
void draw(string a, string b, string c, string d, string e)
{
    for (double i = stod(a); i <= stod(b); i += stod(c))
    {
        double x = expoperate(subreplace(d, "T", std::to_string(i))).getresult() + originx;
        double y = expoperate(subreplace(e, "T", std::to_string(i))).getresult() + originy;
        std::cout << x << " " << y << std::endl;
    }
}
string subreplace(string resource_str, string sub_str, string new_str)
{
    string dst_str = resource_str;
    int pos = 0;
    while ((pos = dst_str.find(sub_str)) != std::string::npos) // 替换所有指定子串
    {
        dst_str.replace(pos, sub_str.length(), new_str);
    }
    return dst_str;
}

int main()
{
    yyin = fopen("1.txt", "r");
    int n = 0;
    int a;
    while ((a = yyparse()) != -1)
    {

        if (a == 1 || a == 2)
        {
            cout << n << endl;
            n++;
        }
        if (a == 2)
            break;
    };
    cin.get();
}
