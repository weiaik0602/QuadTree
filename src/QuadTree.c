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
QuadTree *addTo4(QuadTree **rootPtr,Coordinate coorAdd){
  QuadTree *root=*rootPtr;
  int cmpval=CompareMid(*root,coorAdd);
    if(cmpval==UPLEFT){
      if(root->upleft==NULL){
          root->upleft=&(QuadTree){NULL,NULL,NULL,NULL,0,{0,0},{0,0},{0,0},coorAdd};
          root->upleft->NOD++;
        }
      else
          root->upleft=QuadTreeAdd(&(root->upleft),coorAdd);
      calculateUPLEFT(root);
    }
    else if(cmpval==UPRIGHT){
      if(root->upright==NULL){
          root->upright=&(QuadTree){NULL,NULL,NULL,NULL,0,{0,0},{0,0},{0,0},coorAdd};
          root->upright->NOD++;
        }
      else
      root->upright=QuadTreeAdd(&(root->upright),coorAdd);
      calculateUPRIGHT(root);
    }
    else if(cmpval==DOWNLEFT){
      if(root->downleft==NULL){
          root->downleft=&(QuadTree){NULL,NULL,NULL,NULL,0,{0,0},{0,0},{0,0},coorAdd};
          root->downleft->NOD++;
        }
        else
      root->downleft=QuadTreeAdd(&(root->downleft),coorAdd);
      calculateDOWNLEFT(root);
    }
    else if(cmpval==DOWNRIGHT){
      if(root->downright==NULL){
          root->downright=&(QuadTree){NULL,NULL,NULL,NULL,0,{0,0},{0,0},{0,0},coorAdd};
          root->downright->NOD++;
        }
        else
      root->downright=QuadTreeAdd(&(root->downright),coorAdd);
      calculateDOWNRIGHT(root);
    }
    return root;
}
QuadTree *QuadTreeAdd(QuadTree **rootPtr,Coordinate coorAdd){
  QuadTree *root=*rootPtr;

  if (root->NOD == 0){
      root->data =coorAdd;
      root->NOD++;
  }
  else{
    if(root->upleft==NULL&&root->upright==NULL       \
      &&root->downleft==NULL&&root->downright==NULL){
        calculateMID(root);
        //root->NOD++;
        root=addTo4(&(root),root->data);
        root->data=(Coordinate){(uintptr_t)NULL,(uintptr_t)NULL};
      }

    root=addTo4(&(root),coorAdd);
    root->NOD++;
}
    //*rootPtr=root;
    return root;
}

int CompareData(QuadTree root,Coordinate check){
  if(root.data.x==check.x&&root.data.y==check.y)
    return DATASAME;
}

QuadTree *QuadTreeDelete(QuadTree **rootPtr,Coordinate coorDel){
  QuadTree *root=(QuadTree *)malloc(10*sizeof(QuadTree));
  root=*rootPtr;
  if(root==NULL)
    return NULL;
  else{
    if(root->upleft==NULL&&root->upright==NULL       \
      &&root->downleft==NULL&&root->downright==NULL){
        if(CompareData(*root,coorDel)==DATASAME){
          root->data=(Coordinate){(uintptr_t)NULL,(uintptr_t)NULL};
          root->NOD=0;
        }
        else
           Throw((uintptr_t)(createException("The Coordinate is not existing !!!",0)));
      }

      else{

        QuadTree temp=*(root->downright);
        int cmpval=CompareMid(temp,coorDel);
        if(cmpval==UPLEFT){
          if(root->upleft==NULL)
              Throw((uintptr_t)(createException("The Coordinate is not existing !!!",0)));
          else{
              root->upleft=QuadTreeDelete(&(root->upleft),coorDel);
              if(root->upleft->NOD==0)
                root->upleft=NULL;
          }
        }
        else if(cmpval==UPRIGHT){
          if(root->upright==NULL)
              Throw((uintptr_t)(createException("The Coordinate is not existing !!!",0)));
          else{
            root->upright=QuadTreeDelete(&(root->upright),coorDel);
            if(root->upright->NOD==0)
              root->upright=NULL;
            }
        }
        else if(cmpval==DOWNLEFT){
          if(root->downleft==NULL)
            Throw((uintptr_t)(createException("The Coordinate is not existing !!!",0)));
          else{
            root->downleft=QuadTreeDelete(&(root->downleft),coorDel);
            if(root->downleft->NOD==0)
              root->downleft=NULL;
            }
        }
        else if(cmpval==DOWNRIGHT){
          if(root->downright==NULL)
            Throw((uintptr_t)(createException("The Coordinate is not existing !!!",0)));
          else{
            root->downright=QuadTreeDelete(&(root->downright),coorDel);
            if(root->downright->NOD==0)
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
