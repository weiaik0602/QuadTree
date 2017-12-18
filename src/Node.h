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
  void *data;
};
#endif // _NODE_H
