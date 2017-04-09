 // Copyrgith Ennis Massey 3/04/17
//
// Created by Ennis Massey on 3/04/17.
//

#ifndef KAINRECONSTRUCTION_AADVOICE_H
#define KAINRECONSTRUCTION_AADVOICE_H

 typedef struct AadVolume {
     signed short left;
     signed short right;
 } AadVolume;

 typedef struct AadSequenceHdr {
     unsigned long sequenceID;
     unsigned long quarterNoteTime;
     unsigned short ppqn;
     unsigned short version;
     unsigned short numTracks;
     unsigned short unused;
 } AadSequenceHdr;

 typedef struct AadTempo {
     unsigned long quarterNoteTime;
     unsigned short ppqn;
 } AadTempo;



#endif //KAINRECONSTRUCTION_AADVOICE_H
