#include "unity.h"
#include "QuadTree.h"
#include "nodeHelper.h"
#include "Coordinate.h"
#include <stdint.h>

void setUp(void)
{
  giveInitdata();
}

void tearDown(void)
{
}

void test_initQuadTree(void){
  Node root;
  Coordinate max={10,10};
  Coordinate min={-10,-10};
  initQuadTree(&root,max,min);
  TEST_ASSERT_EQUAL(root.max.x,10);
  TEST_ASSERT_EQUAL(root.max.y,10);
  TEST_ASSERT_EQUAL(root.min.x,-10);
  TEST_ASSERT_EQUAL(root.min.y,-10);
  TEST_ASSERT_EQUAL(root.coor.x,0);
  TEST_ASSERT_EQUAL(root.coor.y,0);
}
void test_QuadTree_Compare(void)
{
  Coordinate root={0,0};

  int v1=Compare(root,a);
  int v2=Compare(root,b);
  int v3=Compare(root,c);
  int v4=Compare(root,d);
  int v5=Compare(root,e);
  int v6=Compare(root,f);
  int v7=Compare(root,g);

  TEST_ASSERT_EQUAL(v1,0);
  TEST_ASSERT_EQUAL(v2,01);
  TEST_ASSERT_EQUAL(v3,10);
  TEST_ASSERT_EQUAL(v4,11);
  TEST_ASSERT_EQUAL(v5,0);
  TEST_ASSERT_EQUAL(v6,11);
  TEST_ASSERT_EQUAL(v7,99);
}

void test_addNodeQuad(void){
  Coordinate rootCoor={0,0};
  initNode(&node1,NULL,NULL,NULL,NULL,rootCoor);
  initNode(&node5,NULL,NULL,NULL,NULL,a);
  initNode(&node10,NULL,NULL,NULL,NULL,b);
  initNode(&node15,NULL,NULL,NULL,NULL,c);
  initNode(&node20,NULL,NULL,NULL,NULL,d);
  initNode(&node25,NULL,NULL,NULL,NULL,e);
  initNode(&node30,NULL,NULL,NULL,NULL,f);
  initNode(&node35,NULL,NULL,NULL,NULL,g);
  Node *root = &node1;
  Coordinate max={100,100};
  Coordinate min={-100,-100};
  initQuadTree(root,max,min);
  addNodeQuad(&root,&node5);
  TEST_ASSERT_EQUAL(root,&node1);
  TEST_ASSERT_EQUAL_PTR(&node5,node1.upleft);

  addNodeQuad(&root,&node10);
  TEST_ASSERT_EQUAL(root,&node1);
  TEST_ASSERT_EQUAL_PTR(&node5,node1.upleft);
  TEST_ASSERT_EQUAL_PTR(&node10,node1.upright);

  addNodeQuad(&root,&node15);
  TEST_ASSERT_EQUAL(root,&node1);
  TEST_ASSERT_EQUAL_PTR(&node5,node1.upleft);
  TEST_ASSERT_EQUAL_PTR(&node10,node1.upright);
  TEST_ASSERT_EQUAL_PTR(&node15,node1.downleft);


  addNodeQuad(&root,&node20);
  TEST_ASSERT_EQUAL(root,&node1);
  TEST_ASSERT_EQUAL_PTR(&node5,node1.upleft);
  TEST_ASSERT_EQUAL_PTR(&node10,node1.upright);
  TEST_ASSERT_EQUAL_PTR(&node15,node1.downleft);
  TEST_ASSERT_EQUAL_PTR(&node20,node1.downright);


  addNodeQuad(&root,&node25);
  TEST_ASSERT_EQUAL(root,&node1);
  TEST_ASSERT_EQUAL_PTR(&node5,node1.upleft);
  TEST_ASSERT_EQUAL_PTR(&node10,node1.upright);
  TEST_ASSERT_EQUAL_PTR(&node15,node1.downleft);
  TEST_ASSERT_EQUAL_PTR(&node20,node1.downright);
  TEST_ASSERT_EQUAL_PTR(&node25,node5.downright);

  addNodeQuad(&root,&node30);
  TEST_ASSERT_EQUAL(root,&node1);
  TEST_ASSERT_EQUAL_PTR(&node5,node1.upleft);
  TEST_ASSERT_EQUAL_PTR(&node10,node1.upright);
  TEST_ASSERT_EQUAL_PTR(&node15,node1.downleft);
  TEST_ASSERT_EQUAL_PTR(&node20,node1.downright);
  TEST_ASSERT_EQUAL_PTR(&node25,node5.downright);
  TEST_ASSERT_EQUAL_PTR(&node30,node20.upleft);

  addNodeQuad(&root,&node35);
  TEST_ASSERT_EQUAL(root,&node1);
  TEST_ASSERT_EQUAL_PTR(&node5,node1.upleft);
  TEST_ASSERT_EQUAL_PTR(&node10,node1.upright);
  TEST_ASSERT_EQUAL_PTR(&node15,node1.downleft);
  TEST_ASSERT_EQUAL_PTR(&node20,node1.downright);
  TEST_ASSERT_EQUAL_PTR(&node25,node5.downright);
  TEST_ASSERT_EQUAL_PTR(&node30,node20.upleft);
}
