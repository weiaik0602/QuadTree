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
  TEST_ASSERT_EQUAL(Tree.downleft->data.y,-2);
  TEST_ASSERT_EQUAL(Tree.upright->data.x,2);
  TEST_ASSERT_EQUAL(Tree.upright->data.y,2);
  TEST_ASSERT_EQUAL(Tree.downright->data.x,2);
  TEST_ASSERT_EQUAL(Tree.downright->data.y,-2);


}
//////////////////////////////////////////////////////////////////////////////
void test_insertNULLPointer_UPLEFT(void){
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
    Pointer *test=(Pointer*)calloc(1,sizeof(Pointer));
    test=insertNULLPointer(TreePtr,test,UPLEFT);
    TEST_ASSERT_EQUAL_PTR(test->A,NULL);
    TEST_ASSERT_EQUAL_PTR(test->B,NULL);
    TEST_ASSERT_EQUAL_PTR(test->C,NULL);
    TEST_ASSERT_EQUAL_PTR(test->D,TreePtr->upright);
    TEST_ASSERT_EQUAL_PTR(test->E,TreePtr->downright);
    TEST_ASSERT_EQUAL_PTR(test->F,TreePtr->downleft);
    TEST_ASSERT_EQUAL_PTR(test->G,NULL);
    TEST_ASSERT_EQUAL_PTR(test->H,NULL);
    TEST_ASSERT_EQUAL_PTR(test->I,TreePtr->upleft);
}
void test_insertNULLPointer_UPRIGHT(void){
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
    Pointer *test=(Pointer*)calloc(1,sizeof(Pointer));
    test=insertNULLPointer(TreePtr,test,UPRIGHT);
    TEST_ASSERT_EQUAL_PTR(test->A,NULL);
    TEST_ASSERT_EQUAL_PTR(test->B,NULL);
    TEST_ASSERT_EQUAL_PTR(test->C,NULL);
    TEST_ASSERT_EQUAL_PTR(test->D,NULL);
    TEST_ASSERT_EQUAL_PTR(test->E,NULL);
    TEST_ASSERT_EQUAL_PTR(test->F,TreePtr->downright);
    TEST_ASSERT_EQUAL_PTR(test->G,TreePtr->downleft);
    TEST_ASSERT_EQUAL_PTR(test->H,TreePtr->upleft);
    TEST_ASSERT_EQUAL_PTR(test->I,TreePtr->upright);
}

void test_insertNULLPointer_DOWNRIGHT(void){
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
    Pointer *test=(Pointer*)calloc(1,sizeof(Pointer));
    test=insertNULLPointer(TreePtr,test,DOWNRIGHT);
    TEST_ASSERT_EQUAL_PTR(test->A,TreePtr->upleft);
    TEST_ASSERT_EQUAL_PTR(test->B,TreePtr->upright);
    TEST_ASSERT_EQUAL_PTR(test->C,NULL);
    TEST_ASSERT_EQUAL_PTR(test->D,NULL);
    TEST_ASSERT_EQUAL_PTR(test->E,NULL);
    TEST_ASSERT_EQUAL_PTR(test->F,NULL);
    TEST_ASSERT_EQUAL_PTR(test->G,NULL);
    TEST_ASSERT_EQUAL_PTR(test->H,TreePtr->downleft);
    TEST_ASSERT_EQUAL_PTR(test->I,TreePtr->downright);
}
void test_insertNULLPointer_DOWNLEFT(void){
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
    Pointer *test=(Pointer*)calloc(1,sizeof(Pointer));
    test=insertNULLPointer(TreePtr,test,DOWNLEFT);
    TEST_ASSERT_EQUAL_PTR(test->A,NULL);
    TEST_ASSERT_EQUAL_PTR(test->B,TreePtr->upleft);
    TEST_ASSERT_EQUAL_PTR(test->C,TreePtr->upright);
    TEST_ASSERT_EQUAL_PTR(test->D,TreePtr->downright);
    TEST_ASSERT_EQUAL_PTR(test->E,NULL);
    TEST_ASSERT_EQUAL_PTR(test->F,NULL);
    TEST_ASSERT_EQUAL_PTR(test->G,NULL);
    TEST_ASSERT_EQUAL_PTR(test->H,NULL);
    TEST_ASSERT_EQUAL_PTR(test->I,TreePtr->downleft);
}
//     N   |  N   | N
//  _______|______|________
//         |      |
//      N  |   1  | 2
//  _______|______|________
//      N  |   4  | 3
//          (1)
//            ||
//             V
//   N    |  N   | N
// _______|______|________
//        |      |
//    N   |  1,1 | 1,2
// _______|______|________
//   N    |  1,4 | 1,3
//         (1,1)
void test_insertUPLEFTPointer(void){
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
  //initialize it
  Pointer *before=(Pointer*)calloc(1,sizeof(Pointer));
  before=insertNULLPointer(TreePtr,before,UPLEFT);
  Pointer *after=(Pointer*)calloc(1,sizeof(Pointer));
  after=insertUPLEFTPointer(before);
  TEST_ASSERT_EQUAL_PTR(after->A,NULL);
  TEST_ASSERT_EQUAL_PTR(after->B,NULL);
  TEST_ASSERT_EQUAL_PTR(after->C,NULL);
  TEST_ASSERT_EQUAL_PTR(after->D,before->I->upright);
  TEST_ASSERT_EQUAL_PTR(after->E,before->I->downright);
  TEST_ASSERT_EQUAL_PTR(after->F,before->I->downleft);
  TEST_ASSERT_EQUAL_PTR(after->G,NULL);
  TEST_ASSERT_EQUAL_PTR(after->H,NULL);
  TEST_ASSERT_EQUAL_PTR(after->I,before->I->upleft);
}
//     N   |  N   | N
//  _______|______|________
//         |      |
//      N  |   1  | 2
//  _______|______|________
//      N  |   4  | 3
//          (1)
//            ||
//             V
//    N   |  N   | N
// _______|______|________
//        |      |
//    1,1 |  1,2 | 2,1
// _______|______|________
//   1,4  | 1,4  | 2,4
//         (1,2)
void test_insertUPRIGHTPointer(void){
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
  //initialize it
  Pointer *before=(Pointer*)calloc(1,sizeof(Pointer));
  before=insertNULLPointer(TreePtr,before,UPLEFT);
  Pointer *after=(Pointer*)calloc(1,sizeof(Pointer));
  after=insertUPRIGHTPointer(before);
  TEST_ASSERT_EQUAL_PTR(after->A,NULL);
  TEST_ASSERT_EQUAL_PTR(after->B,NULL);
  TEST_ASSERT_EQUAL_PTR(after->C,NULL);
  //as D only gt 1 data
  //so D=D and E=NULL
  TEST_ASSERT_EQUAL_PTR(after->D,before->D);
  TEST_ASSERT_EQUAL_PTR(after->E,NULL);
  TEST_ASSERT_EQUAL_PTR(after->F,before->I->downright);
  TEST_ASSERT_EQUAL_PTR(after->G,before->I->downleft);
  TEST_ASSERT_EQUAL_PTR(after->H,before->I->upleft);
  TEST_ASSERT_EQUAL_PTR(after->I,before->I->upright);
}
//     N   |  N   | N
//  _______|______|________
//         |      |
//      N  |   1  | 2
//  _______|______|________
//      N  |   4  | 3
//          (1)
//            ||
//             V
//   1,1  |  1,2 | 2,1
// _______|______|________
//        |      |
//    1,4 |  1,3 | 2,4
// _______|______|________
//   4,1  | 4,2  | 3,1
//         (1,3)
void test_insertDOWNRIGHTPointer(void){
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
  //initialize it
  Pointer *before=(Pointer*)calloc(1,sizeof(Pointer));
  before=insertNULLPointer(TreePtr,before,UPLEFT);
  Pointer *after=(Pointer*)calloc(1,sizeof(Pointer));
  after=insertDOWNRIGHTPointer(before);
  TEST_ASSERT_EQUAL_PTR(after->A,before->I->upleft);
  TEST_ASSERT_EQUAL_PTR(after->B,before->I->upright);
  //as D only gt 1 data
  //so D=D and C=NULL
  TEST_ASSERT_EQUAL_PTR(after->C,NULL);
  TEST_ASSERT_EQUAL_PTR(after->D,before->D);
  TEST_ASSERT_EQUAL_PTR(after->E,before->E);
  TEST_ASSERT_EQUAL_PTR(after->F,before->F);
  TEST_ASSERT_EQUAL_PTR(after->G,NULL);
  TEST_ASSERT_EQUAL_PTR(after->H,before->I->downleft);
  TEST_ASSERT_EQUAL_PTR(after->I,before->I->downright);
}
//     N   |  N   | N
//  _______|______|________
//         |      |
//      N  |   1  | 2
//  _______|______|________
//      N  |   4  | 3
//          (1)
//            ||
//             V
//   N    |  1,1 | 1,2
// _______|______|________
//        |      |
//    N   |  1,4 | 1,3
// _______|______|________
//   N    | 4,1  | 4,2
//         (1,4)
void test_insertDOWNLEFTPointer(void){
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
  //initialize it
  Pointer *before=(Pointer*)calloc(1,sizeof(Pointer));
  before=insertNULLPointer(TreePtr,before,UPLEFT);
  //Pointer *after=(Pointer*)calloc(1,sizeof(Pointer));
  Pointer* after=insertDOWNLEFTPointer(before);
  TEST_ASSERT_EQUAL_PTR(after->A,NULL);
  TEST_ASSERT_EQUAL_PTR(after->B,before->I->upleft);
  TEST_ASSERT_EQUAL_PTR(after->C,before->I->upright);
  TEST_ASSERT_EQUAL_PTR(after->D,before->I->downright);
  //as F only gt 1 data
  //so F=F and E=NULL
  TEST_ASSERT_EQUAL_PTR(after->E,NULL);
  TEST_ASSERT_EQUAL_PTR(after->F,before->F);
  TEST_ASSERT_EQUAL_PTR(after->G,NULL);
  TEST_ASSERT_EQUAL_PTR(after->H,NULL);
  TEST_ASSERT_EQUAL_PTR(after->I,before->I->downleft);
}

/* My data
  (-75,75)  | (-2,75) | (2,75)  | (75,75)
  ---------------------------------------
  (-75,2)   | (-2,2)  | (2,2)   | (75,2)
  ----------------------------------------
  (-75,-2)  | (-2,-2) | (2,-2)  | (75,-2)
  ----------------------------------------
  (-75,-75) | (-2,-75)| (2,-75) | (75,-75)

  Quarant 1=(-75,75),(-2,75),(-75,2),(-2,2)
  Quarant 2= (2,75) , (75,75),(2,2), (75,2)
  Quarant 3= (2,-2),(75,-2),(2,-75),(75,-75)
  Quarant 4=(-75,-2),(-2,-2),(-75,-75),(-2,-75)
  This function will be outputing the coordinate that should
  should check from particular Coordinate
  Example 1
  Coordinate (-75,75)
  This coordinate will be checked with its nearby coordinate which is
  (-2,75),(-2,2)and (-75,2)
  Example 2
  Coordinate (-2,2)
  This will be checked with the 8 coordinate surrounding it
  (-75,75),(-2,75),(2,75),(2,2),(2,-2),(-2,-2),(-75,-2),(-75,2)
*/

void test_QuadCheck_without_filtering(void){
  //This test is without filtering
  //where it will display all the results even it is far away
  Coordinate max={100,100};
  Coordinate min={-100,-100};
  QuadTree Tree={NULL,NULL,NULL,NULL,0,max,min};
  QuadTree *TreePtr=&Tree;
  //add into 16 elements
  TreePtr=QuadTreeAdd(&TreePtr,Cn22);
  TreePtr=QuadTreeAdd(&TreePtr,C22);
  TreePtr=QuadTreeAdd(&TreePtr,Cn2n2);
  TreePtr=QuadTreeAdd(&TreePtr,C2n2);
  TreePtr=QuadTreeAdd(&TreePtr,Cn7575);
  TreePtr=QuadTreeAdd(&TreePtr,Cn275);
  TreePtr=QuadTreeAdd(&TreePtr,C275);
  TreePtr=QuadTreeAdd(&TreePtr,C7575);
  TreePtr=QuadTreeAdd(&TreePtr,Cn752);
  TreePtr=QuadTreeAdd(&TreePtr,C752);
  TreePtr=QuadTreeAdd(&TreePtr,Cn75n2);
  TreePtr=QuadTreeAdd(&TreePtr,C75n2);
  TreePtr=QuadTreeAdd(&TreePtr,Cn75n75);
  TreePtr=QuadTreeAdd(&TreePtr,Cn2n75);
  TreePtr=QuadTreeAdd(&TreePtr,C2n75);
  TreePtr=QuadTreeAdd(&TreePtr,C75n75);

  QuadCheck(TreePtr);
}
