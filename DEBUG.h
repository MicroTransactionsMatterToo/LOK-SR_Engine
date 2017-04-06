#ifndef _DEBUG_H_
#define _DEBUG_H_

#include "G2/MAING2.h"

void DEBUG_SetGameTime(void* var);
long DEBUG_KeepGameTime(void* var);

typedef enum DEBUG_LINE_TYPE {
    BIT,
    LONG,
    ACTION,
    ACTION_WITH_LINE,
    MENU,
    ENDLIST,
    FORMAT,
    INFO
} DEBUG_LINE_TYPE;

typedef struct DebugMenuLine {
    DEBUG_LINE_TYPE type;
    long lower;
    long upper;
    char * text;
    long long* var_address;
    long bit_mask;
} DebugMenuLine;

typedef struct debug_dispatch_t {
    DEBUG_LINE_TYPE type;
    void (*fn)(void);
} debug_dispatch_t;

typedef struct debug_format_t {
    unsigned int xpos;
    unsigned int ypos;
    unsigned int is_centered;
} debug_format_t;


#endif