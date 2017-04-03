#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "DRAW.h";
#include "PSX_STRUCTS.h"

typedef struct _CameraKey {
    short x;
    short y;
    short z;
    short id;
    short rx;
    short rz;
    short flags;
    short tx;
    short ty;
    short tz;
    short pad;
} CameraKey;

typedef struct _CameraCore_Type {
    struct _Position position;
    short pad1;
    struct MATRIX vvNormalWorVecMat[];
    long vvPlaneConsts[];
    struct MATRIX* wcTransform;
    long farPLane;
    long projDistance;
    long nearPlane;
    struct MATRIX* wcTransform2;
    struct MATRIX* cwTransform2;
    Normal viewVolumeNormal[];
    int leftX;
    int rightX;
    int topY;
    int bottomY;
    struct _Rotation rotation;
    struct _SVector screenScale;
    struct _Position debugPos;
    struct _Rotation debugRot;
    struct _Position nondebugPos;
    short pad6;
} CameraCore_Type;

typedef struct Camera {
    CameraCore_Type core;
    long shake;
    short shakeFrame;
    short shakeScale;
    long flags;
    long lock;
    short mode;
    short posState;
    short rotState;
    short tiltState;
    short distanceState;
    short lagZ;
    short tilt;
    Position focusPoint;
    short focusDistance;
    struct _Instance* focusInstance;
    Position oldFocusInstancePos;
    Position newFocusInstancePos;
    Rotation oldFocusInstanceRot;
    Rotation newFocusInstanceRot;
    SVector focusInstanceVelVec;
    Position focusLeadPicot;
    Position focusOffset;
    Rotation focusRotation;
    short tiltVel;
    short tiltAccl;
    SVector positionVel;
    SVector positionAccl;
    SVector focusPointVel;
    short focusDistanceVel;
    short focusDistanceAccl;
    SVector focusRotVel;
    SVector focusRotAccl;
    SVector maxFocusVel;
    SVector rotationVel;
    SVector rotationAccl;
    short maxVel;
    short maxRot;
    Position targetPos;
    short targetTilg;
    Rotation targetRotation;
    short targetFocusDistance;
    Position targetFocusPoint;
    short collisionTargetFocusDistance;
    Rotation targetFocusRotation;
    short tfaceTilt;
    Rotation collisionTargetFocusRotation;
    short smooth;
    CameraKey cameraKey;
    Sphere focusSphere;
    Sphere smallBaseSphere;
    Sphere posSphere;
    short lookTimer;
    short lookSavedMode;
    short presetIndex;
    short presetFocusDistance[3];
    long minFocusDistance;
    long maxFocusDistance;
    long minTilt;
    long maxTilt;
    long pad[3];
    long minXYDist;
    long maxXYDist;
    long oppositeError;
    long tempsplinePointAhed;
    long noTeleport;
    long focusDistanceList[3][3];
    long tiltList[3][3];
    long cineControl;
    short stack;
    short targetStack;
    long savedMode[3];
    long sadeTargetFocusDistance[3];
    Rotation svedFocusRotation;
    short savedFocusDistance;
    short signalFocusDistance;

};

#endif