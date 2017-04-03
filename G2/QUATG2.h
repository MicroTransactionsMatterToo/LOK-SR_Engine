// Copyrgith Ennis Massey 3/04/17
//
// Created by Ennis Massey on 3/04/17.
//

#ifndef KAINRECONSTRUCTION_QUATG2_H
#define KAINRECONSTRUCTION_QUATG2_H

typedef enum _G2Bool_Enum {
    G2FALSE
} G2Bool_Enum;

typedef struct _G2SVector3_Type {
    long x;
    long y;
    long z;
} G2SVector3_Type;

typedef struct _G2LVector3_Type {
    long x;
    long y;
    long z;
} G2LVector3_Type;

typedef struct _G2Matrix_Type {
    short rotScale[3][3];
    short scaleFlag;
    struct _G2LVector3_Type trans;
} G2Matrix_Type;

typedef struct _G2Quat_Type {
    short x;
    short y;
    short z;
    short w;
} G2Quat_Type;

#endif //KAINRECONSTRUCTION_QUATG2_H
