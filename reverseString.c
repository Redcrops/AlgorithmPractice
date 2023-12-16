#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverseMessage(char *message)
{
    int len = strlen(message);
    int right = len - 1;
    int left = len - 1;
    int idx = 0;
    char *acceptMessage = (char *)malloc(sizeof(char) * (len + 1));
    if (!acceptMessage)
    {
        return NULL;
    }
    memset(acceptMessage, 0, sizeof(char) * (len + 1));

    while (left >= 0)
    {
        if (message[left] != ' ')
        {
            right = left;

            while (message[left] != ' ')
            {
                left--;
            }

            for (int jdx = left + 1; jdx <= right; jdx++)
            {
                acceptMessage[idx] = message[jdx];
                idx++;
            }
            acceptMessage[idx] = ' ';
            idx++;
        }
        left--;
    }
    if (acceptMessage[idx] == ' ')
    {
        acceptMessage[idx - 1] = '\0';
    }

    return acceptMessage;
}

int main()
{
    char message[] = "   i   am   from    china   ";
    char *reversedMessage = reverseMessage(message);
    printf("%s\n", reversedMessage);
    if (reversedMessage)
    {
        free(reversedMessage);
        reversedMessage = NULL;
    }
    free(reversedMessage);
}
