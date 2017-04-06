// Copyrgith Ennis Massey 3/04/17
//
// Created by Ennis Massey on 3/04/17.
//

#ifndef KAINRECONSTRUCTION_POOLMMG2_H
#define KAINRECONSTRUCTION_POOLMMG2_H

#include "../INSTANCE.h"

typedef struct _InstancePool {
    long nextInstanceID;
    long numFreeInstances;
    Instance instance[];
    Instance* firstFree;
} InstancePool;

typedef struct _VertexPool {
    struct _PVertex vertex[];
    struct CVECTOR color[];
} VertexPool;

typedef struct _PrimPool {
    long numPrims;
    unsigned long* nextprim;
    unsigned long* lastPrim;
    unsigned long prim[];
};

#endif //KAINRECONSTRUCTION_POOLMMG2_H
