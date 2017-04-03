// Copyrgith Ennis Massey 3/04/17
//
// Created by Ennis Massey on 3/04/17.
//
#ifndef _STDTYPES_INC_H
#define _STDTYPES_INC_H
#include <stdarg.h>
#endif

#ifndef KAINRECONSTRUCTION_SIGNAL_H
#define KAINRECONSTRUCTION_SIGNAL_H

typedef struct Signal {
    long id;
    struct {
        va_list intro;
        struct Signal gotoLabel;
    } data;
};

typedef struct _MultiSignal {
    long numSignals;
    short signalNum;
    short flags;
    struct Signal signalList[32];
};

#endif //KAINRECONSTRUCTION_SIGNAL_H
