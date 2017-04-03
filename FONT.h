#ifndef _FONT_H_
#define _FONT_H_

typedef struct FontChar {
    short x;
    short y;
    signed char c;
    signed char color;
} FontChar;

typedef struct FontTracker {
    FontChar font_buffer[256];
    long font_xpos;
    long font_ypos;
    long font_buffIndex;
    short font_tpage;
    short font_clut;
    short font_vramU;
    short font_vramV;
    short font_width;
    short sprite_sort_push;
    short font_vramX;
    short font_vramY;
    signed char color_global;
    signed char color_local;
} FontTracker;


#endif