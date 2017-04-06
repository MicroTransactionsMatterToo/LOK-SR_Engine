#ifndef _LOAD3D_H_
#define _LOAD3D_H_

typedef struct CdlLOC {
    unsigned char minute;
    unsigned char second;
    unsigned char sector;
    unsigned char track;
} CdlLOC;

typedef struct CdlFILE {
    CdlLOC pos;
    unsigned long size;
    char name[16];
} CdlFILE;

typedef struct CdlFILTER {
    unsigned char file;
    unsigned char chan;
    unsigned short pad;
} CdlFILTER;

typedef struct CdCommand {
    unsigned short flags;
    unsigned char unused;
    unsigned char cdCommand;
    void* cdCmdParam[4];
} CdCommand;

#endif