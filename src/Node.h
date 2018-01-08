#ifndef _NODE_H
#define _NODE_H

#include "Coordinate.h"
typedef struct Node Node;
struct Node {
  Node *upleft;
  Node *upright;
  Node *downleft;
  Node *downright;
  Coordinate coor;
  Coordinate mid;
  Coordinate max;
  Coordinate min;
  Coordinate data;
};

typedef struct QuadTree QuadTree;
struct QuadTree{

  QuadTree *upleft;
  QuadTree *upright;
  QuadTree *downleft;
  QuadTree *downright;
  int NOD;
  Coordinate max;
  Coordinate min;
  Coordinate mid;
  Coordinate data;

};

#endif // _NODE_H
