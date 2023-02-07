#include <stdio.h>
#include "String.h"

int32_t main()
{
    String* string = ReadLine();

    printf("> %s", StringData(string));

    StringDestroy(string);
    return EXIT_SUCCESS;
}