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
    va_list data;
    va_list introData;
    struct _Instance* parent;
    long introNum;
    long birthStreamUnitID;
    long currentStreamUnitID;
    long introUniqueID;
    struct MATRIX* matrix;
    struct MATRIX* oldMatrix;
    struct SoundInstance soundInstanceTbl[];
    unsigned long macCheckDistance;
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
    va_list tfacelevel;
    va_list collideInfo;
    long bspTree;
    short cachedTFace;
    short cachedBSPTree;
    struct _Normal oldWNormal;
    struct _Normal wNormal;
    struct _SVector offset;
    va_list dsignal;
    va_list shadow0;
    va_list shadow1;
    va_list extraLight;
    struct _Position extraLightDir;
    short extraLightScale;
    struct _HModel* hModelList;
    short fadeValue;
    short lightMatrix;
    void (*processFunc)(void);
    void (*collideFunc)(void);
    void (*additionalCollideFunc)(void);
    va_list additionalDrawFunc;
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
    va_list InstanceState;
    char introName[];
    va_list extraData;
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
    _Instance* instance;
    long attribute;
} InstanceObject;

#endif