#ifndef _QUADTREE_H
#define _QUADTREE_H

#include "Node.h"
#include "Coordinate.h"
#include <stdlib.h>
#include <stdint.h>


#define UPLEFT    00
#define UPRIGHT   01
#define DOWNLEFT  10
#define DOWNRIGHT 11
#define SAME      99


void initQuadTree(Node *root,Coordinate maximum,Coordinate minimum);
int Compare(Coordinate root,Coordinate toAdd);

Node *addNodeQuad(Node **rootPtr, Node *nodeToAdd);
#endif // _QUADTREE_H
