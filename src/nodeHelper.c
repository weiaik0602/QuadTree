#include "nodeHelper.h"

extern Node node1 ,node2, node3, node4,node23,node5,node7, node10,node15, node20, node25, node30, node35, node40;
extern Node node45, node50, node55, node60, node65, node70, node75, node80;
extern Node node85, node90, node95, node100;
extern Coordinate a,b,c,d,e,f,g;
void initNode (Node *node, Node *upleft, Node *upright, Node *downleft,Node *downright, Coordinate coor){
  node->upleft = upleft;
  node->upright = upright;
  node->downleft = downleft;
  node->downright = downright;
  node->coor = coor;
}

void giveInitdata(void){
  node1.data = (int *)1 ;
  node2.data = (int *)2;
  node3.data = (int *)3;
  node4.data = (int *)4;
  node5.data = (int *)5;
  node7.data = (int *)7;
  node10.data = (int *)10 ;
  node15.data = (int *)15 ;
  node20.data = (int *)20 ;
  node23.data = (int *)23 ;
  node25.data = (int *)25 ;
  node30.data = (int *)30 ;
  node35.data = (int *)35 ;
  node40.data = (int *)40 ;
  node45.data = (int *)45 ;
  node50.data = (int *)50 ;
  node55.data = (int *)55 ;
  node60.data = (int *)60 ;
  node65.data = (int *)65 ;
  node70.data = (int *)70 ;
  node75.data = (int *)75 ;
  node80.data = (int *)80 ;
  node85.data = (int *)85 ;
  node90.data = (int *)90 ;
  node95.data = (int *)95 ;
  node100.data = (int *)100 ;
  a.x=-2  ,a.y=2;
  b.x=2   ,b.y=2;
  c.x=-2  ,c.y=-2;
  d.x=2   ,d.y=-2;
  e.x=-1  ,e.y=0;
  f.x=0   ,f.y=-1;
  g.x=0   ,g.y=0;
}
