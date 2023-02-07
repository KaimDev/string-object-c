#ifndef E070E5AC_0D41_4EF1_94DD_83C9F15AA563
#define E070E5AC_0D41_4EF1_94DD_83C9F15AA563

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

struct _String
{
    char   *data;
    size_t capacity;
    size_t size;
};

typedef struct _String String;
typedef struct _Person Person;

String* StringNew();
void StringDestroy(String*);
void StringAdd(String*, char /*letra*/);
size_t StringLength(String*); // Size
void StringAssign(String*, const char* /*Text*/);
int StringCompare(String*, String*);
void StringSet(String*, int32_t /*index*/, char /*letra*/);
char* StringGet(String*, int32_t /*index*/);
char* StringData(String*); // Data

String* ReadLine();

#endif /* E070E5AC_0D41_4EF1_94DD_83C9F15AA563 */
