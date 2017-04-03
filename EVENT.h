// Copyrgith Ennis Massey 4/04/17
//
// Created by Ennis Massey on 4/04/17.
//

#ifndef KAINRECONSTRUCTION_EVENT_H
#define KAINRECONSTRUCTION_EVENT_H

#include "SCRIPT.h"

typedef struct EventBasicObject {
    short id;
} EventBasicObject;

typedef struct Event {
    short eventNumber;
    short numInstances;
    unsigned char numActions;
    unsigned char processingPuppetShow;
    void* eventVariables[];
    EventBasicObject instanceList;
    ScriptPCode conditionalList;
    ScriptPCode actionList;
} Event;

typedef struct EventPointers {
    long numPuzzles;
    Event* eventInstances[];
};


#endif //KAINRECONSTRUCTION_EVENT_H
