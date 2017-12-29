#include "QuadTree.h"

int Compare(Coordinate root,Coordinate check)
{
  if(root.x==check.x && root.y==check.y)
    return SAME;
  if(check.x  > root.x || check.x  == root.x ){
    if(check.y > root.y ||check.y == root.y)
      return UPRIGHT;
    else
      return DOWNRIGHT;
  }
  else if(check.x  < root.x){
    if(check.y > root.y ||check.y == root.y)
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

Node *addNodeQuad(Node **rootPtr, Node *nodeToAdd)
{
  Node *root=*rootPtr;
  if (*rootPtr == NULL){
      *rootPtr = nodeToAdd;
      return *rootPtr;
  }
  else{
    int cmpval=Compare(root->coor,nodeToAdd->coor);
    if(cmpval==UPLEFT){
      root->upleft=addNodeQuad(&(root->upleft),nodeToAdd);
      initQuadTree(root->upleft,root->max,root->coor);
    }
    else if(cmpval==UPRIGHT){
      root->upright=addNodeQuad(&(root->upright),nodeToAdd);
    }
    else if(cmpval==DOWNLEFT){
      root->downleft=addNodeQuad(&(root->downleft),nodeToAdd);
    }
    else if(cmpval==DOWNRIGHT){
      root->downright=addNodeQuad(&(root->downright),nodeToAdd);
    }
    else{
      root=root;
    }
    return root;
  }
}

Node *removeNodeQuad(Node **rootPtr, Coordinate coor)
{
  Node *root=*rootPtr;
  if(root==NULL){
    return NULL;
  }
  else{
    int cmpval=Compare(root->coor,coor);
    if(cmpval==UPLEFT){
      root->upleft=removeNodeQuad(&(root->upleft),coor);
    }
    else if(cmpval==UPRIGHT){
      root->upright=removeNodeQuad(&(root->upright),coor);
    }
    else if(cmpval==DOWNLEFT){
      root->downleft=removeNodeQuad(&(root->downleft),coor);
    }
    else if(cmpval==DOWNRIGHT){
      root->downright=removeNodeQuad(&(root->downright),coor);
    }
    else{
      root=NULL;
    }
    return root;
  }
}

Node *searchNodeQuad(Node **rootPtr, Coordinate coor)
{
  Node *root=*rootPtr;
  if(root==NULL){
    return NULL;
  }
  else{
    int cmpval=Compare(root->coor,coor);
    if(cmpval==UPLEFT){
      return(searchNodeQuad(&(root->upleft),coor));
    }
    else if(cmpval==UPRIGHT){
      return(searchNodeQuad(&(root->upright),coor));
    }
    else if(cmpval==DOWNLEFT){
      return(searchNodeQuad(&(root->downleft),coor));
    }
    else if(cmpval==DOWNRIGHT){
      return(searchNodeQuad(&(root->downright),coor));
    }
    else{
      return root;
    }

  }
}
