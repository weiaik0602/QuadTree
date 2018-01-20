#ifndef _NODE_H
#define _NODE_H

#include "Coordinate.h"


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

typedef struct Pointer Pointer;
struct Pointer{
  QuadTree *A;
  QuadTree *B;
  QuadTree *C;
  QuadTree *D;
  QuadTree *E;
  QuadTree *F;
  QuadTree *G;
  QuadTree *H;
  QuadTree *I;
};
#endif // _NODE_H
