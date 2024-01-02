#include <stdio.h>
#include <string.h>
#define true 1
#define false 0
char getMateBracket(char c)
{
    if (c == '(')
    {
        return ')';
    }
    if (c == ')')
    {
        return '(';
    }
    if (c == '{')
    {
        return '}';
    }
    if (c == '}')
    {
        return '{';
    }
    if (c == '[')
    {
        return ']';
    }
    if (c == ']')
    {
        return '[';
    }
}
int isValid(char *s)
{
    if (strlen(s) % 2 != 0)
    {
        return false;
    }
    for (int idx = 0; idx < strlen(s); idx = idx + 2)
    {
        if (getMateBracket(s[idx + 1]) != s[idx])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    char *s = "(){}[]";
    int result = isValid(s);
    printf("result=%d\n", result);
    return 0;
}