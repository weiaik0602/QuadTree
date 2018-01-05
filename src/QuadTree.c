#include "QuadTree.h"

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
  if(root->upleft==NULL&&root->upright==NULL  /
    &&root->downleft==NULL&&root->downright==NULL){
    temp=root->coor;
    root->coor=calculateCentre(root->max,root->min);
  }
}
Node *QuadTreeAdd(Node **rootPtr,Node *nodeToAdd){
  Coordinate maxCoor,minCoor,temp;
  Node *root=*rootPtr;
  if (root == NULL){
      root = nodeToAdd;
      return root;
  }
  else{
    int cmpval=Compare(*root,nodeToAdd->coor);
    if(root->upleft==NULL&&root->upright==NULL  /
      &&root->downleft==NULL&&root->downright==NULL){
      temp=root->coor;
      root->coor=calculateCentre(root->max,root->min);
      QuadTreeAdd(&(root),nodeToAdd);
    }
    int cmpval=Compare(*root,nodeToAdd->coor);
    if(cmpval==UPLEFT){
      root->upleft=addNodeQuad(&(root->upleft),nodeToAdd);

    }
    else if(cmpval==UPRIGHT){

    }
    else if(cmpval==DOWNLEFT){
      root->downleft=addNodeQuad(&(root->downleft),nodeToAdd);

    }
    else if(cmpval==DOWNRIGHT){
      root->downright=addNodeQuad(&(root->downright),nodeToAdd);

    }
  }


}
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


/*
Coordinate searchNodeQuad(Node **rootPtr, Coordinate coorToSearch)
{
  Coordinate PassThrough[10];
  Coordinate *CoorPtr=PassThrough;
  Node *root=*rootPtr;
  if (root == NULL){
    //  return NULL;
  }
  else{
    int cmpval=Compare(*root,coorToSearch);
    if(cmpval==UPLEFT){
      PassThrough[0]=searchNodeQuad(&(root->upleft),coorToSearch);

    }
    else if(cmpval==UPRIGHT){
      //root->upright=searchNodeQuad(&(root->upright),coorToSearch);

    }
    else if(cmpval==DOWNLEFT){
      //root->downleft=searchNodeQuad(&(root->downleft),coorToSearch);
    }
    else if(cmpval==DOWNRIGHT){
    //  root->downright=searchNodeQuad(&(root->downright),coorToSearch);

    }
    else if(cmpval==OUTBOUND){

    }
    else{
      root=root;
    }
    //return root;
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
*/
