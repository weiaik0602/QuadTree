#include "QuadTree.h"

int Compare(Coordinate root,Coordinate check)
{
  if(root.x==check.x && root.y==check.y)
    return 99;
  if(check.x  > root.x || check.x  == root.x ){
    if(check.y > root.y ||check.y == root.y)
      return 01;
    else
      return 11;
  }
  else if(check.x  < root.x){
    if(check.y > root.y ||check.y == root.y)
      return 00;
    else
      return 10;
  }
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
    if(cmpval==00){
      root->upleft=addNodeQuad(&(root->upleft),nodeToAdd);
    }
    else if(cmpval==01){
      root->upright=addNodeQuad(&(root->upright),nodeToAdd);
    }
    else if(cmpval==10){
      root->downleft=addNodeQuad(&(root->downleft),nodeToAdd);
    }
    else if(cmpval==11){
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
    if(cmpval==00){
      root->upleft=removeNodeQuad(&(root->upleft),coor);
    }
    else if(cmpval==01){
      root->upright=removeNodeQuad(&(root->upright),coor);
    }
    else if(cmpval==10){
      root->downleft=removeNodeQuad(&(root->downleft),coor);
    }
    else if(cmpval==11){
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
    if(cmpval==00){
      return(searchNodeQuad(&(root->upleft),coor));
    }
    else if(cmpval==01){
      return(searchNodeQuad(&(root->upright),coor));
    }
    else if(cmpval==10){
      return(searchNodeQuad(&(root->downleft),coor));
    }
    else if(cmpval==11){
      return(searchNodeQuad(&(root->downright),coor));
    }
    else{
      return root;
    }

  }
}
