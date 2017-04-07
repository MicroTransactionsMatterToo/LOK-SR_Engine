#ifndef _INSTANCE_H_
#define _INSTANCE_H_

#include "DRAW.h"
#include "G2/ANIMG2.h"
#include "VRAM.h"
#include "SOUND.h"

struct NodeType {
	struct NodeType* prev;
	struct NodeType* next;
};

typedef struct ObjectEffect {
    unsigned char effectNumber;
    unsigned char modifierList[];
} ObjectEffect;

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
    struct ObjectEffect* effectList;
    unsigned long relocList;
    va_list reloc_module;
    struct _VramSize vramSize;
} Object;

typedef struct _Instance {
	struct NodeType node;
	struct _Instance* next;
	struct _Instance* prev;
	long instanceID;
	long flags;
	long flags2;
    struct Object* object;
    struct Intro* intro;
    void* data;
    void* introData;
    struct _Instance* parent;
    long introNum;
    long birthStreamUnitID;
    long currentStreamUnitID;
    long introUniqueID;
    struct MATRIX* matrix;
    struct MATRIX* oldMatrix;
    struct SoundInstance soundInstanceTbl[];
    unsigned long maxCheckDistance;
    unsigned long checkMask;
    struct _Position position;
    unsigned char lightGroup;
    struct _Position oldPos;
    unsigned char spectralLightGroup;
    short currentTextureAnimFrame;
    struct _Position initialPos;
    struct _Rotation rotation;
    struct _Rotation oldRotation;
    struct _SVector scale;
    long attachedID;
    long attachedSegment;
    struct MATRIX relativeMatrix;
    struct _TFace* tface;
    struct _TFace* oldTFace;
    void* tfaceLevel;
    void* collideInfo;
    long bspTree;
    short cachedTFace;
    short cachedBSPTree;
    struct _Normal oldWNormal;
    struct _Normal wNormal;
    struct _SVector offset;
    void* dsignal;
    void* shadow0;
    void* shadow1;
    void* extraLight;
    struct _Position extraLightDir;
    short extraLightScale;
    struct _HModel* hModelList;
    short fadeValue;
    short lightMatrix;
    void (*processFunc)(void);
    void (*collideFunc)(void);
    void (*additionalCollideFunc)(void);
    void* additionalDrawFunc;
    int (*queryFunc)(void);
    void (*messageFunc)(void);
    struct _Position shadowPosition;
    short currentModel;
    struct _TFace* waterFace;
    struct _TFace* oldWaterFace;
    struct _Terrain* waterFaceTerrain;
    struct _PlaneConstants halvePlane;
    struct _SVector splitPoint;
    struct _Instance* LinkParent;
    struct _Instance* LinkChild;
    struct _Instance* LinkSibling;
    long ParentLinkNode;
    void* InstanceState;
    char introName[];
    void* extraData;
    short constrictAngle;
    short petrifyValue;
    long xVel;
    long yVel;
    long zVel;
    long xAccl;
    long yAccl;
    long zAccl;
    long maxXVel;
    long maxYVel;
    long maxZVel;
    long currentMainState;
    long currentSubState;
    long work0;
    long work1;
    long work2;
    long work3;
    long work4;
    long work5;
    long work6;
    long work7;
    long work8;
    long work9;
    struct _G2Anim_Type anim;
    G2Bool_Enum rebuildCallback;
    short splineFlags;
    short targetFrame;
    signed short clipBeg;
    short clipEnd;
    struct EventAliasCommandStruct {
        struct _Instance* hostInstance;
        short newanim;
        short newframe;
        short interpframes;
        short speed;
    } aliasCommand;
    long light_color;
    struct CVECTOR* perVertexColor;
} Instance ;

typedef struct InstanceSpline {
    Instance* instance;
    struct _MultiSpline* spline;
    long attribute;
    long isParent;
    long isClass;
    long splineFlags;
};

typedef struct InstanceObject {
    Instance* instance;
    long attribute;
} InstanceObject;

typedef struct _ObjectOwnerInfo {
    long magicnum;
    signed short animID;
    char objectName[];
} ObjectOwnerInfo;

typedef struct ObjectAccess {
    char * objectName;
    void* object;
} ObjectAccess;

typedef struct ObjectFunc {
    char * scriptName;
    void (*initFunc)();
    void (*processFunc)();
    void (*collideFunc)();
    int (*queryFunc)();
    void (*messageFunc)();
    void (*additionalCollideFunc)();
    void (*relocateTuneFunc)();
    void (*relocateInstObFunc)();
} ObjectFunc;

#endif