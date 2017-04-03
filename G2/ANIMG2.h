// Copyrgith Ennis Massey 3/04/17
//
// Created by Ennis Massey on 3/04/17.
//

#ifndef KAINRECONSTRUCTION_ANIMG2_H

#include <zconf.h>
#include "QUATG2.h";
#include "../DRAW.h";
#include "../INSTANCE.h"
#include "../SPLINE.h"
#include "../SIGNAL.h"

typedef struct TextureFT3 {
    unsigned char u0;
    unsigned char v0;
    unsigned short clut;
    unsigned char u1;
    unsigned char v1;
    unsigned short tpage;
    unsigned char u2;
    unsigned char v2;
    unsigned short attr;
} TextureFT3;

typedef struct TextureMT3 {
    unsigned char u0;
    unsigned char v0;
    unsigned short clut;
    unsigned char u1;
    unsigned char v1;
    unsigned short tpage;
    unsigned char u2;
    unsigned char v2;
    signed char pad1;
    signed char sortPush;
    long color;
} TextureMT3;

typedef struct _G2AnimQuatInfo_Type {
    struct _G2Quat_Type srcQuat;
    struct _G2Quat_Type destQuat;
    struct _G2SVector3_Type srcScale;
    struct _G2SVector3_Type destScale;
    struct _G2SVector3_Type srcTrans;
    struct _G2SVector3_Type destTrans;
} G2AnimQuatInfo_Type;

typedef struct _G2AnimAlphaTable_Type {
    unsigned short size;
    long data[];
} G2AnimAlphaTable_Type;

typedef struct _G2AnimInterpStateBlock_Type {
    struct _G2AnimInterpStateBlock_Type* next;
    struct _G2AnimQuatInfo_Type quatInfo;
} G2AnimInterpStateBlock_Type;

typedef struct _G2AnimInterpInfo_Type {
    short keyData;
    short index;
} G2AnimInterpInfo_Type;

typedef struct _G2AnimChanStatus_Type {
    short keyData;
    short index;
} G2AnimChanStatus_Type;

typedef struct _G2AnimChanStatusBlock_Type {
    struct _G2AnimChanStatusBlock_Type* next;
    struct _G2AnimChanStatus_Type chunks[8];
} G2AnimChanStatusBlock_Type;

typedef struct _G2AnimFxHeader_Type {
    unsigned char sizeAndSection;
    char type;
    unsigned short keyframeID;
} G2AnimFxHeader_Type;

typedef struct _G2AnimKeylist_Type {
    unsigned char seectionCount;
    unsigned char s0TailTime;
    unsigned char s1TailTime;
    unsigned char s2TailTime;
    unsigned short keyCount;
    short timePerKey;
    unsigned short pad00;
    short pad01;
    unsigned short pad10;
    short pad11;
    struct _G2AnimFxHeader_Type* fxList;
} G2AnimKeylist_Type;

typedef struct _G2AnimSection_Type {
    unsigned char flags;
    unsigned char sectionID;
    unsigned char firstSeg;
    unsigned char segCount;
    short elapsedTime;
    short storedTime;
    short loopStartTime;
    short loopEndTime;
    double swAlarmTable;
    long speedAdjustment;
    unsigned short keylistID;
    unsigned long alarmFlags;
    void (*callback)(void);
    va_list callbackData;
    struct _G2AnimKeylist_Type keylist;
    struct _G2AnimChanStatusBlock_Type chanStatusBlockList;
    struct _G2AnimInterpInfo_Type interInfo;
} G2AnimSection_Type;

typedef struct _G2Anim_Type {
    unsigned char sectionCount;
    unsigned char masterSection;
    unsigned short controllerList;
    unsigned short disabledControllerList;
    unsigned short pad;
    struct _G2SVector3_Type rootTrans;
    unsigned short flags;
    struct _Model* modelData;
    struct _G2Matrix_Type* segMatrices;
    unsigned long disabledBits[3];
    struct _G2AnimSection_Type section;
} G2Anim_Type;

typedef struct AniTexInfo {
    struct TextureMT3* texture;
    long numFrames;
    long speed;
} AniTexInfo;

typedef struct DrMoveAniTexSrcInfo {
    short pixSrcX;
    short pixSrcY;
    short clutSrcX;
    short clutSrcY;
} DrMoveAniTexSrcInfo;

typedef struct DrMoveAniTexDestInfo {
    short pixDstX;
    short pixDstY;
    short pixW;
    short pixH;
    short clutDstX;
    short clutDstY;
    short clutW;
    short clutH;
    short pixCurrentX;
    short pixCurrentY;
    short clutCurrentX;
    short clutCurrentY;
    long numFrames;
    long speed;
    struct DrMoveAniTexSrcInfo frame;
} DrMoveAniTexDestInfo;

typedef struct DrMoveAniTex {
    long numAniTextues;
    struct DrMoveAniTexDestInfo* aniTextInfo;
} DrMoveAniTex;

typedef struct Intro {
    char name[];
    long intronum;
    long UniqueID;
    struct _Rotation rotation;
    struct _Position position;
    short maxRad;
    long maxRadSq;
    long flags;
    va_list data;
    struct _Instance* instance;
    struct _MultiSpline* multiSpline;
    va_list dsignal;
    short specturalLightGroup;
    short meshColor;
    struct _Position spectralPosition;
    short spad;
} Intro;

typedef struct _Terrain {
    short UnitChangeFlags;
    short spad;
    long lpad2;
    long numIntros;
    struct Intro* introList;
    long numVertices;
    long numFaces;
    long numNormals;
    struct _TVertex* vertexlist;
    struct _TFace* faceList;
    struct _Normal* normalList;
};

#define KAINRECONSTRUCTION_ANIMG2_H

#endif //KAINRECONSTRUCTION_ANIMG2_H
