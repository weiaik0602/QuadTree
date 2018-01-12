#include <unity.h>
#include "QuadTree.h"
#include "nodeHelper.h"
#include "Coordinate.h"
#include "CException.h"
#include "exception.h"
#include <stdint.h>

void setUp(void)
{
  giveInitdata();

}

void tearDown(void)
{
}
Coordinate rootCoor={0,0};
Coordinate maxCoor={10,10};
Coordinate minCoor={-10,-10};
/*
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

  Node root;
  initQuadTree(&root,maxCoor,minCoor);
  int v1=Compare(root,a);
  int v2=Compare(root,b);
  int v3=Compare(root,c);
  int v4=Compare(root,d);
  int v5=Compare(root,e);
  int v6=Compare(root,f);
  int v7=Compare(root,g);
  int v8=Compare(root,h);
  int v9=Compare(root,i);

  TEST_ASSERT_EQUAL(v1,UPLEFT);
  TEST_ASSERT_EQUAL(v2,UPRIGHT);
  TEST_ASSERT_EQUAL(v3,DOWNLEFT);
  TEST_ASSERT_EQUAL(v4,DOWNRIGHT);
  TEST_ASSERT_EQUAL(v5,UPLEFT);
  TEST_ASSERT_EQUAL(v6,DOWNRIGHT);
  TEST_ASSERT_EQUAL(v7,SAME);
  TEST_ASSERT_EQUAL(v8,OUTBOUND);
  TEST_ASSERT_EQUAL(v9,OUTBOUND);
}*/
/*
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
*/

//Cn22,C22,Cn2n2,C2n2,Cn10,C0n1,C00,C1111,Cn11n11;

void test_QuadTreeAdd(void){

  Coordinate max={100,100};
  Coordinate min={-100,-100};
  QuadTree Tree={NULL,NULL,NULL,NULL,0,max,min};
  QuadTree *TreePtr=&Tree;

  //1st element will go to data
  //level 1
  TreePtr=QuadTreeAdd(&TreePtr,Cn22);
  TEST_ASSERT_EQUAL(Tree.data.x,Cn22.x);
  TEST_ASSERT_EQUAL(Tree.data.y,Cn22.y);
  //2nd element will make the tree split into 4 segment and the data will become mid
  //level 2
  TreePtr=QuadTreeAdd(&TreePtr,Cn2n2);
  TEST_ASSERT_EQUAL(Tree.upleft->data.x,-2);
  TEST_ASSERT_EQUAL(Tree.upleft->data.y,2);
  TEST_ASSERT_EQUAL(Tree.downleft->data.x,-2);
  TEST_ASSERT_EQUAL(Tree.downleft->data.y,-2);
  TEST_ASSERT_EQUAL(Tree.mid.y,0);
  TEST_ASSERT_EQUAL(Tree.mid.x,0);
  TEST_ASSERT_EQUAL(Tree.data.y,0);
  TEST_ASSERT_EQUAL(Tree.data.x,0);
  //adding 3rd element in the same level 2
  TreePtr=QuadTreeAdd(&TreePtr,C22);
  TEST_ASSERT_EQUAL(Tree.upleft->data.x,-2);
  TEST_ASSERT_EQUAL(Tree.upleft->data.y,2);
  TEST_ASSERT_EQUAL(Tree.downleft->data.x,-2);
  TEST_ASSERT_EQUAL(Tree.downleft->data.y,-2);
  TEST_ASSERT_EQUAL(Tree.upright->data.x,2);
  TEST_ASSERT_EQUAL(Tree.upright->data.y,2);
  //adding 4th element in the same level 2
  TreePtr=QuadTreeAdd(&TreePtr,C2n2);
  TEST_ASSERT_EQUAL(Tree.upleft->data.x,-2);
  TEST_ASSERT_EQUAL(Tree.upleft->data.y,2);
  TEST_ASSERT_EQUAL(Tree.downleft->data.x,-2);
  TEST_ASSERT_EQUAL(Tree.downleft->data.y,-2);
  TEST_ASSERT_EQUAL(Tree.upright->data.x,2);
  TEST_ASSERT_EQUAL(Tree.upright->data.y,2);
  TEST_ASSERT_EQUAL(Tree.downright->data.x,2);
  TEST_ASSERT_EQUAL(Tree.downright->data.y,-2);
  //adding 5th element in the next level (level 3)
  TreePtr=QuadTreeAdd(&TreePtr,Cn7575);
  TEST_ASSERT_EQUAL(Tree.upleft->downright->data.x,-2);
  TEST_ASSERT_EQUAL(Tree.upleft->downright->data.y,2);
  TEST_ASSERT_EQUAL(Tree.upleft->upleft->data.x,-75);
  TEST_ASSERT_EQUAL(Tree.upleft->upleft->data.y,75);
}



/*
void test_QuadTreeDelete_removeOneCoor(void){

    Coordinate max={100,100};
    Coordinate min={-100,-100};
    QuadTree Tree={NULL,NULL,NULL,NULL,0,max,min};
    QuadTree *TreePtr=&Tree;
    //remove 1 element
    TreePtr=QuadTreeAdd(&TreePtr,Cn22);
    TEST_ASSERT_EQUAL(Tree.data.x,Cn22.x);
    TEST_ASSERT_EQUAL(Tree.data.y,Cn22.y);
    TreePtr=QuadTreeDelete(TreePtr,Cn22);
    TEST_ASSERT_EQUAL_PTR(TreePtr,NULL);
    free(TreePtr);
}
*/
void test_QuadTreeDelete_removeMultiple(void){
  Coordinate max={100,100};
  Coordinate min={-100,-100};
   QuadTree Tree={NULL,NULL,NULL,NULL,0,max,min};
//  QuadTree *TreePtr=(QuadTree *)calloc(5000000, sizeof(QuadTree));
  QuadTree *TreePtr= (QuadTree *)calloc(5000000, sizeof(QuadTree));
  TreePtr=&Tree;
    //add into 4 elements
    TreePtr=QuadTreeAdd(&TreePtr,Cn22);
    TreePtr=QuadTreeAdd(&TreePtr,C22);
    TreePtr=QuadTreeAdd(&TreePtr,Cn2n2);
    TreePtr=QuadTreeAdd(&TreePtr,C2n2);

    //check
    TEST_ASSERT_EQUAL(Tree.upleft->data.x,-2);
    TEST_ASSERT_EQUAL(Tree.upleft->data.y,2);
    TEST_ASSERT_EQUAL(Tree.downleft->data.x,-2);
    TEST_ASSERT_EQUAL(Tree.downleft->data.y,-2);
    TEST_ASSERT_EQUAL(Tree.upright->data.x,2);
    TEST_ASSERT_EQUAL(Tree.upright->data.y,2);
    TEST_ASSERT_EQUAL(Tree.downright->data.x,2);
    TEST_ASSERT_EQUAL(Tree.downright->data.y,-2);

    //remove n22 from UL
    TreePtr=QuadTreeDelete(TreePtr,Cn22);
    TEST_ASSERT_EQUAL(Tree.upleft,NULL);
    TEST_ASSERT_EQUAL(Tree.downleft->data.x,-2);
    TEST_ASSERT_EQUAL(Tree.downleft->data.y,-2);
    TEST_ASSERT_EQUAL(Tree.downright->data.x,2);
    TEST_ASSERT_EQUAL(Tree.downright->data.y,-2);
    TEST_ASSERT_EQUAL(Tree.upright->data.x,2);
    TEST_ASSERT_EQUAL(Tree.upright->data.y,2);
/*
    TreePtr=QuadTreeDelete(TreePtr,C2n2);
    TEST_ASSERT_EQUAL(Tree.downright,NULL);
    TEST_ASSERT_EQUAL(Tree.upleft->data.x,-2);
    TEST_ASSERT_EQUAL(Tree.upleft->data.y,2);
    TEST_ASSERT_EQUAL(Tree.upright->data.x,2);
    TEST_ASSERT_EQUAL(Tree.upright->data.y,2);
    TEST_ASSERT_EQUAL(Tree.downleft->data.x,-2);
    TEST_ASSERT_EQUAL(Tree.downleft->data.y,-2);
*/
}
/*
void test_calculateDistance(void){
//calculateDistance(Cn22,C35);
  //printf("%f",x);
  //TEST_ASSERT_EQUAL_D(x,0);
}

void test_QuadCheck(void){
  Coordinate max={100,100};
  Coordinate min={-100,-100};
   QuadTree Tree={NULL,NULL,NULL,NULL,0,max,min};
//  QuadTree *TreePtr=(QuadTree *)calloc(5000000, sizeof(QuadTree));
  QuadTree *TreePtr= (QuadTree *)calloc(10, sizeof(QuadTree));
  TreePtr=&Tree;
    //add into 4 elements
    TreePtr=QuadTreeAdd(&TreePtr,Cn22);
    TreePtr=QuadTreeAdd(&TreePtr,C22);
    TreePtr=QuadTreeAdd(&TreePtr,Cn2n2);
    TreePtr=QuadTreeAdd(&TreePtr,C2n2);

    QuadCheck(Cn22,&Tree,UPLEFT);
}
*/
