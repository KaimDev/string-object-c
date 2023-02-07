#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

struct _String
{
    char   *data;
    size_t capacity;
    size_t size;
};

typedef struct _String String;
typedef struct _Person Person;

String* StringNew()
{
    String* string = (String*)malloc(sizeof(String));

    string->size = 0;
    string->capacity = 8;
    string->data = (char*)malloc(sizeof(char) * string->capacity);

    return string;
}

void StringDestroy(String* string)
{
    free(string->data);
    free(string);
}

void StringAdd(String* string, char letter)
{
    if (string->size <= string->capacity)
    {
        string->capacity *= 2;
        char* temp = (char*)realloc(string->data, string->capacity * sizeof(char));
        if (temp == NULL)
        {
            puts("Error realloc");
            return;
        }
        string->data = temp;
    }

    ++string->size;
    string->data[string->size - 1] = letter;
}

size_t StringLength(String* string)
{
    return string->size;
}

void StringAssign(String* string, const char* value)
{
    free(string->data);
    free(string);
    size_t length = strlen(value);
    String* temp = StringNew();

    for (size_t i = 0 ; i < length ; ++i)
    {
        StringAdd(temp, value[i]);
    }

    string = temp;
}

int StringCompare(String* first, String* second)
{
    for (size_t i = 0 ;; ++i)
    {
        if (first->data[i] == '\0' && second->data[i] == '\0')
        {
            break;
        }

        if (first->data[i] > second->data[i])
        {
            return 1;
        }
        else if (first->data[i] < second->data[i])
        {
            return -1;
        }
    }

    return 0;
}


void StringSet(String* string, int32_t index, char letter)
{
    string->data[index] = letter;
}


char* StringGet(String* string, int32_t index)
{
    return &string->data[index];
}

char* StringData(String* string)
{
    return string->data;
}

void Buffer()
{
    char buffer[1024];
    fgets(buffer, 1024, stdin);
}