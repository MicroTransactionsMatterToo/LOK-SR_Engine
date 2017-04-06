// Copyrgith Ennis Massey 6/04/17
//
// Created by Ennis Massey on 6/04/17.
//

#ifndef KAINRECONSTRUCTION_MEMCARD_H
#define KAINRECONSTRUCTION_MEMCARD_H
#include "../INSTANCE.h"

typedef struct menu_format_t {
    unsigned int xpos;
    unsigned int ypos;
    unsigned int lineskip;
    unsigned int itemskip;
    unsigned int width;
    unsigned int center;
    unsigned int border;
} menu_format_t;

typedef struct menu_stacl_t {
    int (*fn);
    unsigned int index;
    menu_format_t format;
} menu_stack_t;

typedef struct menu_item_t {
    char * text;
    int (*fn)(long param, long flags);
    long parameter;
    long flags;
} menu_item_t;

typedef struct mcmenu_t {
    unsigned int nmenus;
    unsigned int nitems;
    unsigned int nbytes;
    menu_stack_t stack[];
    menu_item_t items[];
    char bytes[];
    void (*drawFn);
    void* opaque;
} mcmenu_t;

typedef struct menuface_t {
    unsigned int x;
    unsigned int y;
    unsigned int w;
    unsigned int h;
    unsigned int loaded;
} menuface_t;

typedef struct mcmenu_table_t {
    int (*data_size);
    void (*initialize);
    void (*terminate);
    void (*begin);
    void (*end);
    int (*set_buffer)(int buffer_size);
    int (*main);
    int (*pause);
    char * versionID;
} mcmenu_table_t;

typedef struct memcard_t {
    struct Object* object;
    mcmenu_table_t* table;
    mcmenu_t* mcmenu;
    signed short running;
    signed short wrongVerison;
    GameTracker* gt;
};

#endif //KAINRECONSTRUCTION_MEMCARD_H
