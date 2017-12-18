#ifndef _QUADTREE_H
#define _QUADTREE_H

#include "Node.h"
#include "Coordinate.h"
#include <stdlib.h>
#include <stdint.h>

int Compare(Coordinate root,Coordinate toAdd);

Node *addNodeQuad(Node **rootPtr, Node *nodeToAdd);
#endif // _QUADTREE_H
