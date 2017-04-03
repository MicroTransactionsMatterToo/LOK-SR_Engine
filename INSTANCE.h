#ifndef _INSTANCE_H_
#define _INSTANCE_H_

#include "DRAW.h"
#include "G2/ANIMG2.h"

struct NodeType {
	struct NodeType* prev;
	struct NodeType* next;
};

struct Object {
	long oflags;
	short id;
	short sfxFileHandle;
	short numModels;
	short numAnims;
    struct _G2AnimKeylist_Type animList;
    struct _Model* modelList;
    short introDist;
    short vvIntroDist;
    short removeDist;
    short vvRemoveDist;
    va_list data;
    const char* script;
    const char* name;
    void* soundData;
    long oflags2;
    short sectionA;
    short sectionB;
    short sectionC;
    short numberOfEffects;
};

typedef struct _Instance {
	struct NodeType node;
	struct _Instance* next;
	struct _Instance* prev;
	long instanceID;
	long flags;
	long flags2;
} Instance ;

#endif