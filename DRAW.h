#ifndef _DRAW_HEADER_
#define _DRAW_HEADER_

#include "PSX_STRUCTS.h"

/*!
 * Single Dimensional Vector
 */
typedef struct _SVector {
    short x;
    short y;
    short z;
    short pad;
} SVector;

/*!
 * Single Dimesnional Vector with no padding
 */
typedef struct _SVectorNoPad {
    short x;
    short y;
    short z;
} SVectorNoPad;

/*!
 * XYZ Coordinate position
 */
typedef struct _Position {
    short x;
    short y;
    short z;
} Position;

typedef struct _Rotation {
    short x;
    short y;
    short z;
    short pad;
} Rotation;

/*!
 * Geometric normal
 */
typedef struct _Normal {
    short x;
    short y;
    short z;
    short pad;
} Normal;


typedef struct _PlaneConstants {
    short a;
    short b;
    short c;
    short flags;
    long d;
} PlaneConstants;

typedef struct _Vertex {
    short x;
    short y;
    short z;
} Vertex;

/*!
 * Geometric Face
 * @property
 */
typedef struct _Face {
    unsigned short v0;
    unsigned short v1;
    unsigned short v2;
} Face;

typedef struct _MVertex {
    struct _Vertex vertex;
    unsigned short normal;
} MVertex;

typedef struct _MFace {
    struct _Face face;
    unsigned char normal;
    unsigned char flags;
    long color;
} MFace;

/*!
 * RGBA Colour
 */
typedef struct _RGBAColor {
    unsigned char r; /*!< Red value */
    unsigned char g; /*!< Green Value */
    unsigned char b; /*!< Blue value */
    unsigned char a; /*!< Alpha (Transparency) value */
} RGBAColor;

/*!
 * Horizontal/Vertical only vertex
 */
typedef struct _PVertex {
    short x;
    short y;
    long otz;
} PVertex;


typedef struct _Sphere {
    struct _Position position;
    unsigned short radius;
    unsigned long radiusSquared;
} Sphere;

typedef struct _Sphere_noSq {
    struct _Position position;
    unsigned short radius;
} Sphere_noSq;

typedef struct _Model {
    long numVertices;
    struct _MVertex* vertexList;
    long numNormals;
    struct _SVectorNoPad* normalList;
    long numFaces;
    struct _MFace* faceList;
} Model;

typedef struct _BVertex {
    short x;
    short y;
    short z;
    short pad;
} BVertex;

typedef struct _BFace {
    short v0;
    short v1;
    short v2;
    short pad;
} BFace;

typedef struct _BGObject {
    short flags;
    short numFaces;
    struct _BVertex *vertexList;
    struct _BFace *faceList;
    short x;
    short y;
    short z;
    short radius;
    long numVertices;
};

typedef struct _HFace {
    short v0;
    short v1;
    short v2;
    unsigned char attr;
    signed char pad;
    unsigned short normal;
    unsigned short n0;
} HFace;

typedef struct _HSphere {
    long attr;
    unsigned char id;
    unsigned char rank;
    short pad;
    struct _Position position;
    unsigned short radius;
    unsigned long radiusSquared;
} HSphere;

typedef struct _HBox {
    short flags;
    unsigned char id;
    unsigned char rank;
    short minX;
    short minY;
    short minZ;
    short maxX;
    short maxY;
    short maxZ;
    short refMinX;
    short refMinY;
    short refMinZ;
    short refMaxX;
    short refMaxY;
    short refMaxZ;
} HBox;

typedef struct _HPrim {
    unsigned char hpFlags;
    unsigned char withFlags;
    unsigned char type;
    unsigned char segment;
    struct {
        struct _HSphere* hsphere;
        struct _HBox* hbox;
        struct _HFace* hface;
    } data;
} HPrim;

typedef struct _HModel {
    struct _HPrim* hPrimList;
    long numHPrings;
} HModel;

typedef struct _HInfo {
    long numHFaces;
    struct _HFace* hfaceList;
    long numHSpheres;
    struct _HSphere* hsphereList;
    long numHBoxes;
    struct _HBox* hboxList;
} HInfo;

typedef struct _Segment {
    long flags;
    short firstTri;
    short lastTri;
    short firstVertex;
    short lastVertex;
    short px;
    short py;
    short pz;
    short parent;
    struct _HInfo* hInfo;
} Segment;

typedef struct _TFace {
    struct _Face face;
    unsigned char attr;
    signed char sortPush;
    unsigned short normal;
    unsigned short textoff;
} TFace;

typedef struct _TVertex {
    struct _Vertex vertex;
    unsigned short rgb15;
    unsigned char r0;
    unsigned char g0;
    unsigned char b0;
    unsigned char code;
} TVertex;

typedef struct Vector3d {
    short vx;
    short vy;
    short vz;
    short pad1;
    short errorx;
    short errory;
    short errorz;
    short pad2;
} Vector3d;

typedef struct Rotation3d {
    short vx;
    short vy;
    short vz;
    short pad1;
    short errorx;
    short errory;
    short errorz;
    short pad2;
    long attribute;
} Rotation3d;

typedef struct _Vector {
    long x;
    long y;
    long z;
} Vector;



#endif