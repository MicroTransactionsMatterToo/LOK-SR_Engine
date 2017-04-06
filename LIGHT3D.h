#ifndef _LIGHT3D_H_
#define _LIGHT3D_H_

#include "INSTANCE.h"
#include "PSX_STRUCTS.h"

typedef struct LightTableEntry {
    signed short r;
    signed short g;
    signed short b;
    signed short radius;
};

typedef struct LightInstance {
    Instance* lightInstance;
    long r;
    long g;
    long b;
    signed short radius;
    unsigned char segment;
    unsigned char flags;
};

typedef struct LightGroup {
    struct MATRIX lightMatrix;
    struct MATRIX colorMatrix;
} LightGroup;

typedef struct LightList {
    struct CVECTOR ambient;
    long numLightGroups;
    LightGroup* lightGroupList;
} LightList;

typedef struct PointLight {
    struct NodeType node;
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char flags;
    Position position;
    signed short radius;
    long radiusSquared;
} PointLight;

typedef struct SpotLight {
    struct NodeType node;
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char flags;
    Position centroid;
    signed short radius;
    long radiusSquared;
    Position position;
    Position direction;
    signed short cosFalloffAngle;
    signed short attenuationScale;
} SpotLight;

typedef struct LightInfo {
    long numPointLights;
    PointLight pointLightPool[];
    struct NodeType usedPointLightList;
    struct NodeType freePointLightList;
    struct NodeType activePointLightList;
    long numSpotLights;
    SpotLight spotLightPool[];
    struct NodeType usedSpotLightList;
    struct NodeType freeSpotLightList;
    struct NodeType activeSpotLightList;
    long numSavedColors;
} LightInfo;

#endif