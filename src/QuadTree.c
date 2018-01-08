#include "QuadTree.h"

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
  root->downright->max.x=root->max.x;
  root->downright->max.y=(root->max.y+root->min.y)/2;
  root->downright->min.x=(root->min.x+root->max.y)/2;
  root->downright->min.y=root->min.y;
}
void calculateMID(QuadTree *root){
  root->mid.x=(root->max.x+root->min.x)/2;
  root->mid.y=(root->max.y+root->min.y)/2;
}
int CompareMid(QuadTree root,Coordinate check)
{
  int val;
  if(check.x>root.max.x||check.y>root.max.y ||check.x<root.min.x||check.y<root.min.y)
    val= OUTBOUND;
  if(root.mid.x==check.x && root.mid.y==check.y)
    val=SAME;
  else if(check.x  > root.mid.x || check.x  == root.mid.x ){
    if(check.y > root.mid.y ||check.y == root.mid.y)
      val=UPRIGHT;
    else
      val=DOWNRIGHT;
  }
  else if(check.x  < root.mid.x){
    if(check.y > root.mid.y ||check.y == root.mid.y)
      val=UPLEFT;
    else
      val=DOWNLEFT;
  }

  return val;
}
QuadTree *addTo4(QuadTree **rootPtr,Coordinate *coorAdd){
  QuadTree *root=*rootPtr;
  int cmpval=CompareMid(*root,*coorAdd);
    if(cmpval==UPLEFT){
      if(root->upleft==NULL)
          root->upleft=&(QuadTree){NULL,NULL,NULL,NULL,{0,0},{0,0},{0,0},coorAdd};
      else
          root->upleft=QuadTreeAdd(&(root->upleft),coorAdd);
      calculateUPLEFT(root);
    }
    else if(cmpval==UPRIGHT){
      if(root->upright==NULL)
          root->upright=&(QuadTree){NULL,NULL,NULL,NULL,{0,0},{0,0},{0,0},coorAdd};
      else
      root->upright=QuadTreeAdd(&(root->upright),coorAdd);
      calculateUPRIGHT(root);
    }
    else if(cmpval==DOWNLEFT){
      if(root->downleft==NULL)
          root->downleft=&(QuadTree){NULL,NULL,NULL,NULL,{0,0},{0,0},{0,0},coorAdd};
      else
      root->downleft=QuadTreeAdd(&(root->downleft),coorAdd);
      calculateDOWNLEFT(root);
    }
    else if(cmpval==DOWNRIGHT){
      if(root->downright==NULL)
          root->downright=&(QuadTree){NULL,NULL,NULL,NULL,{0,0},{0,0},{0,0},coorAdd};
      else
      root->downright=QuadTreeAdd(&(root->downright),coorAdd);
      calculateDOWNRIGHT(root);
    }
    return root;
}
QuadTree *QuadTreeAdd(QuadTree **rootPtr,Coordinate *coorAdd){
  QuadTree *root=*rootPtr;

  if (root->data == NULL){
      root->data =coorAdd;
  }
  else{
    if(root->upleft==NULL&&root->upright==NULL       \
      &&root->downleft==NULL&&root->downright==NULL){
        calculateMID(root);
        root=addTo4(&(root),root->data);
        root->data=&(root->mid);
      }

    root=addTo4(&(root),coorAdd);
}
    //*rootPtr=root;
    return root;
}
int CompareData(QuadTree root,Coordinate check){
  if(root.data->x==check.x&&root.data->y==check.y)
    return DATASAME;
}

QuadTree *QuadTreeDelete(QuadTree **rootPtr,Coordinate *coorDel){
 // QuadTree *root=(QuadTree *)malloc(10*sizeof(QuadTree));
  QuadTree *root=*rootPtr;
  if(root==NULL)
    return NULL;
  else{
    if(root->upleft==NULL&&root->upright==NULL       \
      &&root->downleft==NULL&&root->downright==NULL){
        if(CompareData(*root,*coorDel)==DATASAME){
          root->data=NULL;
        }
        else
           Throw((uintptr_t)(createException("The Coordinate is not existing !!!",0)));
      }

      else{

        QuadTree temp=*(root->downright);
        int cmpval=CompareMid(temp,*coorDel);
        if(cmpval==UPLEFT){
          if(root->upleft==NULL)
              Throw((uintptr_t)(createException("The Coordinate is not existing !!!",0)));
          else{
              root->upleft=QuadTreeDelete(&(root->upleft),coorDel);
              if(root->upleft->data==NULL)
                root->upleft=NULL;
          }
        }
        else if(cmpval==UPRIGHT){
          if(root->upright==NULL)
              Throw((uintptr_t)(createException("The Coordinate is not existing !!!",0)));
          else{
            root->upright=QuadTreeDelete(&(root->upright),coorDel);
            if(root->upright->data==NULL)
              root->upright=NULL;
            }
        }
        else if(cmpval==DOWNLEFT){
          if(root->downleft==NULL)
            Throw((uintptr_t)(createException("The Coordinate is not existing !!!",0)));
          else{
            root->downleft=QuadTreeDelete(&(root->downleft),coorDel);
            if(root->downleft->data==NULL)
              root->downleft=NULL;
            }
        }
        else if(cmpval==DOWNRIGHT){
          if(root->downright==NULL)
            Throw((uintptr_t)(createException("The Coordinate is not existing !!!",0)));
          else{
            root->downright=QuadTreeDelete(&(root->downright),coorDel);
            if(root->downright->data==NULL)
              root->downright=NULL;
            }
        }
        else if(cmpval==SAME){
          return NULL;
        }
      }
      return root;
  }
}
