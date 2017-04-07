#ifndef _LOAD3D_H_
#define _LOAD3D_H_

typedef struct CdlLOC {
    unsigned char minute;
    unsigned char second;
    unsigned char sector;
    unsigned char track;
} CdlLOC;

typedef struct CdlFILE {
    CdlLOC pos;
    unsigned long size;
    char name[16];
} CdlFILE;

typedef struct CdlFILTER {
    unsigned char file;
    unsigned char chan;
    unsigned short pad;
} CdlFILTER;

typedef struct CdCommand {
    unsigned short flags;
    unsigned char unused;
    unsigned char cdCommand;
    void* cdCmdParam[4];
} CdCommand;

typedef struct _BigFileEntry {
    long fileHash;
    long fileLen;
    long filePos;
    long checkSumFull;
} BigFileEntry;

typedef struct _BigFileDirEntry {
    signed short streamUnitID;
    signed short numFiles;
    long subDirOffset;
} BigFileDirEntry;

typedef struct _BigFileDir {
    long numFiles;
    struct _BigFileEntry fileList[];
} BigFileDir;

typedef struct _BigFile {
    long bigfileBaseOffset;
    BigFileDir* rootDir;
    BigFileDir* currentDir;
    BigFileDir* cachedDir;
    long currentDirID;
    long cachedDirID;
    long searchDirID;
    long numSubDirs;
    BigFileDirEntry* subDirList;
} BigFile;

typedef struct _NonBlockLoadEntry {
    long fileHash;
    long dirHash;
    long filePos;
    long long* loadAddr;
    long loadSize;
    long checksum;
    long checksumType;
    long memType;
    long posInFile;
    void (*retFunc);
    void* retData;
    void* retPointer;
    char fileName[];
} NonBlockLoadEntry;

typedef struct _ReadQueueEntry {
    long readStartPos;
    long readSize;
    long readCurSize;
    void* readStartDest;
    void* readCurDest;
    long readStatus;
    long checksum;
    long checksumType;
    void (*retFunc)(void*, void*);
    void* retData;
    void* retData2;
} ReadQueueEntry;

typedef struct _LoadQueueEntry {
    struct _LoadQueueEntry* next;
    signed short status;
    signed char relocateBinary;
    signed char mempackUsed;
    NonBlockLoadEntry loadEntry;
    long endLoadTime;
} LoadQueueEntry;

typedef struct _LoadStatus {
    ReadQueueEntry currentQueueFile;
    long state;
    long bytesTransferred;
    long lastCheckPos;
    long cdWaitTime;
    long* compSrcAddr;
    long* compDstAddr;
    long compControlbits;
    long compControl;
    long compEndBytes;
    long decompressLen;
    long checksum;
    long long* checkAddr;
    BigFile bigFile;
    void* buffer1;
    void* buffer2;
    unsigned int changeDir;
    long endLoadTime;
    long currentDirLoading;
    long currentSector;
    long sectorTime;
    long seekTime;
} LoadStatus;


#endif