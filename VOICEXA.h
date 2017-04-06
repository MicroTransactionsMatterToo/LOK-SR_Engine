// Copyrgith Ennis Massey 6/04/17
//
// Created by Ennis Massey on 6/04/17.
//

#ifndef KAINRECONSTRUCTION_VOICEXA_H
#define KAINRECONSTRUCTION_VOICEXA_H

#include "LOAD3D.h"

typedef struct VoiceCommand {
    unsigned char voiceCmd;
    unsigned char nextVoiceStatus;
    unsigned short voiceCmdParam;
} VoiceCommand;

typedef struct XAFileInfo {
    unsigned int startPos;
} XAFileInfo;

typedef struct XAVoiceListEntry {
    unsigned short length;
} XAVoiceListEntry;

typedef struct XAVoiceTracker {
    CdlLOC currentPos;
    unsigned int currentSector;
    unsigned int endSector;
    void (*prevCallback)(void);
    void* cdResult[];
    CdCommand cdCmdQueue[];
    void* requestQueue[];
    VoiceCommand voiceCmdQueue[];
    unsigned char cdCmdIn;
    unsigned char cdCmdOut;
    unsigned char reqIn;
    unsigned char reqOut;
    unsigned char reqsQueued;
    unsigned char voiceCmdIn;
    unsigned char voiceCmdOut;
    unsigned char voiceCmdsQueued;
    unsigned char unused1;
    unsigned char voiceStatus;
    unsigned char cdStatus;
    signed short fileNum;
    signed short unused2;
    XAFileInfo xaFileInfo[];
} XAVoiceTracker;

#endif //KAINRECONSTRUCTION_VOICEXA_H
