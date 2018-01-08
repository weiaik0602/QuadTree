#include "QuadTree.h"
/*
int Compare(Node root,Coordinate check)
{
  if(check.x>root.max.x||check.y>root.max.y ||check.x<root.min.x||check.y<root.min.y)
    return OUTBOUND;
  if(root.coor.x==check.x && root.coor.y==check.y)
    return SAME;
  else if(check.x  > root.coor.x || check.x  == root.coor.x ){
    if(check.y > root.coor.y ||check.y == root.coor.y)
      return UPRIGHT;
    else
      return DOWNRIGHT;
  }
  else if(check.x  < root.coor.x){
    if(check.y > root.coor.y ||check.y == root.coor.y)
      return UPLEFT;
    else
      return DOWNLEFT;
  }
}


Coordinate calculateCentre(Coordinate max,Coordinate min){
    Coordinate mid;
    mid.x=(max.x+min.x)/2;
    mid.y=(max.y+min.y)/2;
    return mid;
}
void initQuadTree(Node *root,Coordinate maximum,Coordinate minimum){
  root->max.x=maximum.x;
  root->max.y=maximum.y;
  root->min.x=minimum.x;
  root->min.y=minimum.y;
  root->upleft=NULL;
  root->upright=NULL;
  root->downleft=NULL;
  root->downright=NULL;
  root->coor=calculateCentre(root->max,root->min);
}

Coordinate Divide4Seg(Node *root){
  Coordinate temp;
//  if(root->upleft==NULL&&root->upright==NULL  /
  //  &&root->downleft==NULL&&root->downright==NULL){
    temp=root->coor;
    //calculateCoor(root->max,root->min);
  }


Node  *QuadTreeAdd(Node **rootPtr,Node *nodeToAdd){
  if (*rootPtr == NULL){
      *rootPtr = nodeToAdd;
      return *rootPtr;
  }
  else
    _QuadTreeAdd(rootPtr,nodeToAdd);
}*/

/*
Node *addNodeQuad(Node **rootPtr, Node *nodeToAdd)
{
  Coordinate maxCoor,minCoor;
  Node *root=*rootPtr;
  if (root == NULL){
      root = nodeToAdd;
      return root;
  }
  else{
    int cmpval=Compare(*root,nodeToAdd->coor);
    if(cmpval==UPLEFT){
      root->upleft=addNodeQuad(&(root->upleft),nodeToAdd);
      maxCoor.x=(root->max.x+root->min.x)/2;
      maxCoor.y=root->max.y;
      minCoor.x=root->min.x;
      minCoor.y=(root->min.y+root->max.y)/2;
      root->upleft->max=maxCoor;
      root->upleft->min=minCoor;
    }
    else if(cmpval==UPRIGHT){
      root->upright=addNodeQuad(&(root->upright),nodeToAdd);
      maxCoor.x=root->max.x;
      maxCoor.y=root->max.y;
      minCoor.x=(root->min.x+root->max.x)/2;
      minCoor.y=(root->min.y+root->max.y)/2;
      root->upright->max=maxCoor;
      root->upright->min=minCoor;
    }
    else if(cmpval==DOWNLEFT){
      root->downleft=addNodeQuad(&(root->downleft),nodeToAdd);
      maxCoor.x=(root->max.x+root->min.x)/2;
      maxCoor.y=(root->max.y+root->min.y)/2;;
      minCoor.x=root->min.x;
      minCoor.y=root->min.y;
      root->downleft->max=maxCoor;
      root->downleft->min=minCoor;
    }
    else if(cmpval==DOWNRIGHT){
      root->downright=addNodeQuad(&(root->downright),nodeToAdd);
      maxCoor.x=(root->max.x+root->min.x)/2;
      maxCoor.y=root->max.y;
      minCoor.x=(root->min.y+root->max.y)/2;
      minCoor.y=root->min.y;
      root->downright->max=maxCoor;
      root->downright->min=minCoor;
    }
    else if(cmpval==OUTBOUND){

    }
    else{
      root=root;
    }
    return root;
  }
}
*/

void calculateUPLEFT(QuadTree *root){
  root->upleft->max.x=(root->max.x+root->min.x)/2;
  root->upleft->max.y=root->max.y;
  root->upleft->min.x=root->min.x;
  root->upleft->min.y=(root->min.y+root->max.y)/2;
}
void calculateUPRIGHT(QuadTree *root){
  root->upright->max.x=root->max.x;
  root->upright->max.y=root->max.y;
  root->upright->min.x=(root->min.x+root->max.x)/2;
  root->upright->min.y=(root->min.y+root->max.y)/2;
}
void calculateDOWNLEFT(QuadTree *root){
  root->downleft->max.x=(root->max.x+root->min.x)/2;
  root->downleft->max.y=(root->max.y+root->min.y)/2;
  root->downleft->min.x=root->min.x;
  root->downleft->min.y=root->min.y;
}
void calculateDOWNRIGHT(QuadTree *root){
  root->downright->max.x=(root->max.x+root->min.x)/2;
  root->downright->max.y=root->max.y;
  root->downright->min.x=(root->min.y+root->max.y)/2;
  root->downright->min.y=root->min.y;
}
void calculateMID(QuadTree *root){
  root->mid.x=(root->max.x+root->min.x)/2;
  root->mid.y=(root->max.y+root->min.y)/2;
}
int CompareMid(QuadTree root,Coordinate check)
{
  int x=4;
  int y=x;

  if(check.x>root.max.x||check.y>root.max.y ||check.x<root.min.x||check.y<root.min.y)
    return OUTBOUND;
  if(root.mid.x==check.x && root.mid.y==check.y)
    return SAME;
  else if(check.x  > root.mid.x || check.x  == root.mid.x ){
    if(check.y > root.mid.y ||check.y == root.mid.y)
      return UPRIGHT;
    else
      return DOWNRIGHT;
  }
  else if(check.x  < root.mid.x){
    if(check.y > root.mid.y ||check.y == root.mid.y)
      return UPLEFT;
    else
      return DOWNLEFT;
  }
}
QuadTree *addTo4(QuadTree **rootPtr,Coordinate *coorAdd){
  QuadTree *root=*rootPtr;
  int cmpval=CompareMid(*root,*coorAdd);
    if(cmpval==UPLEFT){
      root->upleft=QuadTreeAdd(&(root->upleft),coorAdd);
      calculateUPLEFT(root);
    }
    else if(cmpval==UPRIGHT){
      root->upright=QuadTreeAdd(&(root->upright),coorAdd);
      calculateUPRIGHT(root);
    }
    else if(cmpval==DOWNLEFT){
      root->downleft=QuadTreeAdd(&(root->downleft),coorAdd);
      calculateDOWNLEFT(root);
    }
    else if(cmpval==DOWNRIGHT){
      root->downright=QuadTreeAdd(&(root->downright),coorAdd);
      calculateUPRIGHT(root);
    }
}
QuadTree *QuadTreeAdd(QuadTree **rootPtr,Coordinate *coorAdd){
  Coordinate maxCoor,minCoor,temp;
  QuadTree *root=*rootPtr;
  if(root==NULL){
    //*root=(QuadTree){NULL,NULL,NULL,NULL,{0,0},{0,0},{0,0},coorAdd};
    QuadTree new={NULL,NULL,NULL,NULL,{0,0},{0,0},{0,0},coorAdd};
    *rootPtr=&new;
    return *rootPtr;
  }
  else if (root->data == NULL){
      root->data =coorAdd;
      return root;
  }
  else{
    if(root->upleft==NULL&&root->upright==NULL       \
      &&root->downleft==NULL&&root->downright==NULL){
        calculateMID(root);
        root=addTo4(&(root),root->data);
      }

  int cmpval=CompareMid(*root,*coorAdd);
    if(cmpval==UPLEFT){
      root->upleft=QuadTreeAdd(&(root->upleft),coorAdd);
      calculateUPLEFT(root);
    }
    else if(cmpval==UPRIGHT){
      root->upright=QuadTreeAdd(&(root->upright),coorAdd);
      calculateUPRIGHT(root);
    }
    else if(cmpval==DOWNLEFT){
      root->downleft=QuadTreeAdd(&(root->downleft),coorAdd);
      calculateDOWNLEFT(root);
    }
    else if(cmpval==DOWNRIGHT){
      root->downright=QuadTreeAdd(&(root->downright),coorAdd);
      calculateUPRIGHT(root);
    }
}
}
