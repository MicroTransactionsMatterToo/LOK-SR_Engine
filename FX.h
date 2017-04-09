// Copyrgith Ennis Massey 6/04/17
//
// Created by Ennis Massey on 6/04/17.
//

#ifndef KAINRECONSTRUCTION_FX_H
#define KAINRECONSTRUCTION_FX_H

#include "INSTANCE.h"

typedef struct _FX_MATRIX {
    struct NodeType node;
    long flags;
    struct MATRIX lwTransform;
} FX_MATRIX;

typedef struct _FX_PRIM {
    struct NodeType node;
    TextureMT3* texture;
    long flags;
    long timeToLive;
    void* process;
    struct _FX_MATRIX* matrix;
    long color;
    long startColor;
    long endColor;
    signed short colorFadeValue;
    signed short colorFadeStep;
    Position position;
    signed short fadeStep;
    void* fadeValue[4];
    Position v0;
    signed short work0;
    Position v1;
    signed short work1;
    Position v2;
    signed short work2;
    Position v3;
    signed short work3;
} FX_PRIM;



typedef struct _FXTracker {
    FX_MATRIX matrixPool[];
    struct NodeType usedMatrixList;
    struct NodeType freeMatrixList;
    FX_PRIM primPool[];
    struct NodeType usedPrimList;
    struct NodeType usedPrimListSprite;
    struct NodeType freePrimList;
} FXTracker;

typedef struct __BubbleParams {
    signed short DisperseFrames;
    signed short KillScale;
    signed short MinSplashSize;
    signed short MaxSpeed;
    signed short MaxSpeedRange;
    signed short ScaleRate;
    signed short ScaleRateRange;
    signed short StartScale;
    signed short StartScaleRange;
    signed short UniqueBubbles;
} __BubbleParams;

typedef struct _GenericParticleParams {
    signed short model;
    signed short texture;
    signed short size;
    unsigned char StartOnInit;
    unsigned char type;
    signed short birthRadius;
    signed char startSegment;
    signed char endSegment;
    Position direction;
    unsigned char spectral_colorize;
    unsigned char absolute_direction;
    Position acceleration;
    signed short useInstanceModel;
    long startColor;
    long endColor;
    signed short lifeTime;
    signed short primLifeTime;
    signed short startFadeValue;
    signed short fadeStep;
    signed char numberBirthParticles;
    signed char z_undulation_mode;
    signed short scaleSpeed;
    Position offset;
    signed short startScale;
} GenericParticleParams;

typedef struct _GenericGlowParams {
    signed short id;
    signed short StartOnInit;
    unsigned char segment;
    unsigned char segmentEnd;
    signed short numSegments;
    signed short color_num;
    signed short numColors;
    long atuColorCycleRate;
    signed short width;
    signed short height;
    long lifetime;
    signed short fadein_time;
    signed short fadeout_time;
} GenericGlowParams;

typedef struct _GenericRibbonParams {
    signed short id;
    signed short StartOnInit;
    signed short startSegment;
    signed short endSegment;
    signed short type;
    signed short ribbonLifeTime;
    signed short faceLifeTime;
    signed short startFadeValue;
    long startColor;
    long endColor;
} GenericRibbonParams;

typedef struct _GenericLightningParams {
    signed short type;
    signed short lifeTime;
    signed short deg;
    signed short deg_inc;
    Position start_offset;
    signed short startSeg;
    Position end_offset;
    signed short endSeg;
    signed short matrixSeg;
    signed short width;
    signed short small_width;
    signed short segs;
    signed short sine_size;
    signed short variation;
    long color;
    long glow_color;
} GenericLightningParams;

typedef struct _GenericBlastringParams {
    signed short type;
    signed short lifeTime;
    signed short matrixSeg;
    signed short segment;
    SVector offset;
    signed short sortInWorld;
    signed short radius;
    signed short size1;
    signed short size2;
    signed short endRadius;
    signed short endRadious;
    signed short colorchange_radius;
    unsigned int vel;
    unsigned int accl;
    signed short height1;
    signed short height2;
    signed short height3;
    signed short predator_offset;
    long startColor;
    long endColor;
} GenericBlastringParams;

typedef struct _GenericFlashParams {
    signed short type;
    signed short timeToColor;
    long color;
    signed short timeAtColor;
    signed short timeFromColor;
} GenericFlashParams;

typedef struct _FXHalvePlane {
    void* next;
    void* continue_process;
    Instance instance;
    unsigned char effectType;
    unsigned char type;
    signed short lifeTime;
    long diffTime;
    PlaneConstants ringPlane;
    long currentColor;
    long long* colorArray;
    signed short numColors;
    signed short colorBlendLife;
} FXHalvePlane;

typedef struct _FXGlowEffect {
    void* next;
    void* continue_process;
    Instance* instance;
    unsigned char effectType;
    unsigned char type;
    signed short lifeTime;
    unsigned long diffTime;
    long long* colorArray;
    long currentColor;
    signed short numColors;
    signed short colorBlendCycle;
    signed short width;
    signed short height;
    unsigned char numSegments;
    unsigned char SegmentInc;
    signed short segment;
    signed short fadein_time;
    signed short fadeout_time;
} FXGlowEffect;

typedef struct _FXGeneralEffect {
    void* next;
    void* continue_process;
    Instance instance;
    unsigned char effectType;
    unsigned char type;
    signed short lifeTime;
} FXGeneralEffect;

typedef struct _FXRibbon {
    void* next;
    void* continue_process;
    Instance instance;
    unsigned char effectType;
    unsigned char type;
    signed short lifeTime;
    signed short numberVerts;
    signed short endIndex;
    struct SVECTOR* vertexPool;
    signed short startSegment;
    signed short endSegment;
    long startColor;
    long endColor;
    signed short colorStepValue;
    signed short faceLifeTime;
    signed short startFadeValue;
    signed short fadeStep;
} FXRibbon;

typedef struct _FXParticle {
    void* next;
    void* continue_process;
    Instance instance;
    unsigned char effectType;
    unsigned char type;
    signed short lifeTime;
    TextureMT3* texture;
    void* fxprim_modify_process;
    void* fxprim_process;
    signed short size;
    signed short primLifeTime;
    signed short birthRadius;
    signed short scaleSpeed;
    Position direction;
    unsigned short flag_bits;
    Position acceleration;
    signed short startScale;
    Position offset;
    signed char startSegment;
    signed char z_undulate;
    long startColor;
    long endColor;
    signed short colorStepValue;
    signed char numberBirthParticles;
    signed char endSegment;
    signed short startFadeValue;
    signed short fadeStep;
} FXParticle;

typedef struct _FXLightBeam {
    void* next;
    void* continue_process;
    Instance* instance;
    unsigned char effectType;
    unsigned char type;
    signed short lifeTime;
    signed short startSeg;
    signed short endSeg;
    long color;
} FXLightBeam;

typedef struct _FXBlastringEffect {
    void* next;
    void* continue_process;
    Instance* instance;
    unsigned char effectType;
    unsigned char type;
    signed short lifeTime;
    SVector position;
    struct MATRIX matrix;
    signed short segment;
    signed short pad;
    unsigned int radius;
    unsigned int size1;
    unsigned int size2;
    unsigned int endRadius;
    unsigned int colorchange_radius;
    unsigned int vel;
    unsigned int accl;
    unsigned int height1;
    unsigned int height2;
    unsigned int height3;
    signed short predator_offset;
    signed short sortInWorld;
    long color;
    long startColor;
    long endColor;
} FXBlastringEffect;

typedef struct _FXLightning {
    void* next;
    void* continue_process;
    struct _Instance* instance;
    unsigned char effectType;
    unsigned char type;
    signed short lifeTime;
    signed short deg;
    signed short deg_inc;
    struct _Position start_offset;
    signed short startSeg;
    struct _Instance* end_instance;
    struct _Position end_offset;
    signed short endSeg;
    signed short matrixSeg;
    signed short width;
    signed short small_width;
    signed short segs;
    signed short sine_size;
    signed short variation;
    long color;
    long glow_color;
} FXLightning;

typedef struct _FXFlash {
    void* next;
    void* continue_process;
    Instance* instance;
    unsigned char effectType;
    unsigned char type;
    signed short lifeTime;
    long timeToColor;
    long timeAtColor;
    long timeFromColor;
    long currentTime;
    long color;
} FXFLash;

typedef struct FXSplinter {
    signed short flags;
    signed short soundFx;
    signed short chunkVelXY;
    signed short chunkVelZ;
    signed short chunkVelRng;
    signed short triVelRng;
    signed short lifetime;
    signed short faceLimit;
    signed short rotRateRng;
    signed short gravityZ;
} FXSplinter;







#endif //KAINRECONSTRUCTION_FX_H
