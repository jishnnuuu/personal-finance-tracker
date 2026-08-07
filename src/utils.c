#include "../include/utils.h"


bool readString(const char *prompt,
                char *buffer,
                size_t size)
{
    printf("%s", prompt);

    if (fgets(buffer, size, stdin) == NULL)
    {
        return false;
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    return true;
}

bool readInt(const char *prompt, int *value)
{
    char buffer[100];

    printf("%s", prompt);

    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        return false;
    }

    return sscanf(buffer, "%d", value) == 1;
}

bool readFloat(const char *prompt,
               float *value)
{
    char buffer[100];

    printf("%s", prompt);

    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        return false;
    }

    return sscanf(buffer, "%f", value) == 1;
}

