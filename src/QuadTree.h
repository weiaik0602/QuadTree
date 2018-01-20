#ifndef _QUADTREE_H
#define _QUADTREE_H
#include <stdlib.h>
#include <stdint.h>
#include "Node.h"
#include "Coordinate.h"
#include "CException.h"
#include "exception.h"
#include "math.h"
#include "stdio.h"



#define UPLEFT    00
#define UPRIGHT   01
#define DOWNLEFT  10
#define DOWNRIGHT 11
#define SAME      99
#define OUTBOUND  98
#define DATASAME  20
#define COLLISION_RANGE  10.0




QuadTree *QuadTreeAdd(QuadTree **rootPtr,Coordinate coorAdd);
QuadTree *QuadTreeDelete(QuadTree **root,Coordinate coorDel);
void QuadCheck(QuadTree *root);

/////////////Sub Func//////////////////////////
void calculateUPLEFT(QuadTree *root);
void calculateUPRIGHT(QuadTree *root);
void calculateDOWNLEFT(QuadTree *root);
void calculateDOWNRIGHT(QuadTree *root);
void calculateMID(QuadTree *root);
void calculateDistance(Coordinate a,Coordinate b);
void _QuadCheck(QuadTree *root,Pointer *point);
Pointer* insertPointer(QuadTree *root,Pointer* point,int mode);
Pointer* insertUPLEFTPointer(Pointer *point);
Pointer* insertNULLPointer(QuadTree *root,Pointer* point,int mode);
Pointer* insertUPRIGHTPointer(Pointer *root);
Pointer* insertDOWNRIGHTPointer(Pointer *root);
Pointer* insertDOWNLEFTPointer(Pointer *root);
void checkInPointer(Coordinate Coor,Pointer *point);
void checkInTree(Coordinate Coor,QuadTree *root);
#endif // _QUADTREE_H
