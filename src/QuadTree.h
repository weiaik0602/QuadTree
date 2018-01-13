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

int Compare(Node root,Coordinate check);
void calculateUPLEFT(QuadTree *root);
void calculateUPRIGHT(QuadTree *root);
void calculateDOWNLEFT(QuadTree *root);
void calculateDOWNRIGHT(QuadTree *root);
void calculateMID(QuadTree *root);
void QuadTreeInit(QuadTree *Tree);
QuadTree *QuadTreeAdd(QuadTree **rootPtr,Coordinate coorAdd);
QuadTree *QuadTreeDelete(QuadTree **root,Coordinate coorDel);
void QuadCheck(Coordinate Coor,QuadTree *root,int mode);
void calculateDistance(Coordinate a,Coordinate b);
void QuadCheck(Coordinate Coor,QuadTree *root,int mode);
void checkDownRight(QuadTree *root,Coordinate Coor,int level,int mode);
void checkDownLeft(QuadTree *root,Coordinate Coor,int level,int mode);
void checkUpRight(QuadTree *root,Coordinate Coor,int level,int mode);
void checkUpLeft(QuadTree *root,Coordinate Coor,int level,int mode);
#endif // _QUADTREE_H
