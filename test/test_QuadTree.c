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




void test_QuadTreeDelete_removeOneCoor(void){

    Coordinate max={100,100};
    Coordinate min={-100,-100};
    QuadTree Tree={NULL,NULL,NULL,NULL,0,max,min};
    QuadTree *TreePtr=&Tree;
    //remove 1 element
    TreePtr=QuadTreeAdd(&TreePtr,Cn22);
    TEST_ASSERT_EQUAL(Tree.data.x,Cn22.x);
    TEST_ASSERT_EQUAL(Tree.data.y,Cn22.y);
    TreePtr=QuadTreeDelete(&TreePtr,Cn22);
    TEST_ASSERT_EQUAL_PTR(TreePtr,NULL);
    free(TreePtr);
}

void test_QuadTreeDelete_removeMultiple(void){
    Coordinate max={100,100};
    Coordinate min={-100,-100};
    QuadTree Tree={NULL,NULL,NULL,NULL,0,max,min};
    QuadTree *TreePtr=&Tree;
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
    TreePtr=QuadTreeDelete(&TreePtr,Cn22);
    TEST_ASSERT_EQUAL(Tree.upleft,NULL);
    TEST_ASSERT_EQUAL(Tree.downleft->data.x,-2);
    TEST_ASSERT_EQUAL(Tree.downleft->data.y,-2);
    TEST_ASSERT_EQUAL(Tree.downright->data.x,2);
    TEST_ASSERT_EQUAL(Tree.downright->data.y,-2);
    TEST_ASSERT_EQUAL(Tree.upright->data.x,2);
    TEST_ASSERT_EQUAL(Tree.upright->data.y,2);
    //remove C22 from upright
    TreePtr=QuadTreeDelete(&TreePtr,C22);
    TEST_ASSERT_EQUAL(Tree.upleft,NULL);
    TEST_ASSERT_EQUAL(Tree.upright,NULL);
    TEST_ASSERT_EQUAL(Tree.downright->data.x,2);
    TEST_ASSERT_EQUAL(Tree.downright->data.y,-2);
    TEST_ASSERT_EQUAL(Tree.downleft->data.x,-2);
    TEST_ASSERT_EQUAL(Tree.downleft->data.y,-2);
}
void test_QuadTreeDelete_2ndLevel(void){
  Coordinate max={100,100};
  Coordinate min={-100,-100};
  QuadTree Tree={NULL,NULL,NULL,NULL,0,max,min};
  QuadTree *TreePtr=&Tree;
  //add into 4 elements
  TreePtr=QuadTreeAdd(&TreePtr,Cn22);
  TreePtr=QuadTreeAdd(&TreePtr,C22);
  TreePtr=QuadTreeAdd(&TreePtr,Cn2n2);
  TreePtr=QuadTreeAdd(&TreePtr,C2n2);
  TreePtr=QuadTreeAdd(&TreePtr,Cn7575);
  //delete from level 2
  //the data at upleft->downleft come up to upleft->data
  TreePtr=QuadTreeDelete(&TreePtr,Cn7575);
  TEST_ASSERT_EQUAL(Tree.upleft->data.x,-2);
  TEST_ASSERT_EQUAL(Tree.upleft->data.y,2);
  TEST_ASSERT_EQUAL(Tree.downleft->data.x,-2);
  TEST_ASSERT_EQUAL(Tree.downleft->data.y,-2);
  TEST_ASSERT_EQUAL(Tree.upright->data.x,2);
  TEST_ASSERT_EQUAL(Tree.upright->data.y,2);
  TEST_ASSERT_EQUAL(Tree.downright->data.x,2);
  TEST_ASSERT_EQUAL(Tree.downright->data.y,-2);


}

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
