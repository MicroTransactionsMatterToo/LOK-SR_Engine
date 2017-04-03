// Copyrgith Ennis Massey 4/04/17
//
// Created by Ennis Massey on 4/04/17.
//

#ifndef KAINRECONSTRUCTION_SPLINE_H
#define KAINRECONSTRUCTION_SPLINE_H

#include "G2/QUATG2.h"
#include "PSX_STRUCTS.h"

typedef struct vecS {
    short x;
    short y;
    short z;
} vecS;

typedef struct vecL {
    long x;
    long y;
    long z;
};

typedef struct _SplineDef {
    short currkey;
    unsigned short denomFlag;
    long fracCurr;
} SplineDef;

typedef struct _SplineKey {
    short count;
    struct vecS point;
    struct vecL dd;
    struct vecL ds;
} SplineKey;

typedef struct _Spline {
    struct _SplineKey* key;
    short numkeys;
    unsigned char type;
    unsigned char flags;
} Spline;

typedef struct _SplineRotKey {
    short count;
    struct _G2Quat_Type q;
} SplineRotKey;

typedef struct _RSpline {
    struct _SplineRotKey* key;
    short numkeys;
    unsigned char types;
    unsigned char flags;
} RSpline;

typedef struct _MultiSpline {
    struct _Spline* positional;
    struct _RSpline* rotational;
    struct _Spline* scaling;
    struct _Spline* color;
    struct _SplineDef curPositional;
    struct _SplineDef curRotational;
    struct _SplineDef curScaling;
    struct _SplineDef curColor;
    struct MATRIX curRotMatrix;
};



#endif //KAINRECONSTRUCTION_SPLINE_H
