#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "INSTANCE.h"
#include "DRAW.h"

typedef struct __AttackItem {
    unsigned char anim;
    unsigned char framesIn;
    unsigned char framesOut;
    unsigned char switchDelay;
    unsigned char ignoreDelay;
    unsigned char segmentToGlow;
    unsigned char startCollisionFrame;
    unsigned char handsToCollide;
    unsigned char endCollisionFrame;
    unsigned char ribbonStartFrame;
    unsigned char ribbonStartSegment;
    unsigned char ribbonEndSegement;
    unsigned char ribbonLifeTime;
    unsigned char ribbonFaceLifeTime;
    unsigned char knockBackFrames;
    unsigned char glowFadeInFrames;
    unsigned char glowFadeOutFrames;
    unsigned short ribbonStartOpacity;
    unsigned long ribbonStartColor;
    unsigned long ribbonEndColor;
    unsigned long glowColor;
    unsigned short knockBackDistance;
    unsigned short hitPowerScale;
} AttackItem;

typedef struct __ThrowItem {
    unsigned char prepAnim;
    unsigned char perpAnimFramesIn;
    unsigned char prepAnimAlphaIn;
    unsigned char coilAnim;
    unsigned char coilAnimFramesIn;
    unsigned char coilAnimAlphaIn;
    unsigned char throwAnim;
    unsigned char throwAnimFramesInFactor;
    unsigned char throwFrameToLaunch;
    unsigned char framesOut;
    short launchPointX;
    short launchPointY;
    short launchPointZ;
    short maxXRotation;
    short minXRotation;
    short maxZRotation;
    short minZRotation;
    short velocity;
    short gravity;
    short coilRot;
    short pad;
} ThrowItem;

typedef struct __EngagedInstance {
    Instance* instance;
    unsigned long distance;
} EngagedInstance;

typedef struct __FitPoint {
    short x;
    short y;
} FitPoint;

typedef struct __SensoryData {
    int Flags;
    SVector ForwardNormal;
    SVector AboveNormal;
    SVector BelowNormal;
    SVector BelowPoint;
    SVector Delta;
    Instance* HitMonster;
    Instance* CurrentAutoFace;
    Instance* LastAutoFace;
    struct __EngagedInstance* EngagedList;
    unsigned long EngagedMask;
    Vector lookAtPoint;
};




#endif