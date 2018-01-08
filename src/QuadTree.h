#ifndef _QUADTREE_H
#define _QUADTREE_H
#include <stdlib.h>
#include <stdint.h>
#include "Node.h"
#include "Coordinate.h"




#define UPLEFT    00
#define UPRIGHT   01
#define DOWNLEFT  10
#define DOWNRIGHT 11
#define SAME      99
#define OUTBOUND  98

int Compare(Node root,Coordinate check);
void calculateUPLEFT(QuadTree *root);
void calculateUPRIGHT(QuadTree *root);
void calculateDOWNLEFT(QuadTree *root);
void calculateDOWNRIGHT(QuadTree *root);
void calculateMID(QuadTree *root);
QuadTree *QuadTreeAdd(QuadTree **rootPtr,Coordinate *coorAdd);
#endif // _QUADTREE_H
