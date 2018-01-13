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
QuadTree *addTo4(QuadTree **rootPtr,Coordinate coorAdd){
  QuadTree *root=*rootPtr;
  int cmpval=CompareMid(*root,coorAdd);
    if(cmpval==UPLEFT){
      if(root->upleft==NULL){
          QuadTree *new=(QuadTree *)malloc(sizeof(QuadTree));
          *new=(QuadTree){NULL,NULL,NULL,NULL,0,{0,0},{0,0},{0,0},coorAdd};
          root->upleft=new;
          root->upleft->NOD++;
        }
      else
          root->upleft=QuadTreeAdd(&(root->upleft),coorAdd);
      calculateUPLEFT(root);
      calculateMID(root->upleft);
    }
    else if(cmpval==UPRIGHT){
      if(root->upright==NULL){
        QuadTree *new=(QuadTree *)malloc(sizeof(QuadTree));
        *new=(QuadTree){NULL,NULL,NULL,NULL,0,{0,0},{0,0},{0,0},coorAdd};
        root->upright=new;
          root->upright->NOD++;
        }
      else
      root->upright=QuadTreeAdd(&(root->upright),coorAdd);
      calculateUPRIGHT(root);
      calculateMID(root->upright);
    }
    else if(cmpval==DOWNLEFT){
      if(root->downleft==NULL){
        QuadTree *new=(QuadTree *)malloc(sizeof(QuadTree));
        *new=(QuadTree){NULL,NULL,NULL,NULL,0,{0,0},{0,0},{0,0},coorAdd};
        root->downleft=new;
          root->downleft->NOD++;
        }
        else
      root->downleft=QuadTreeAdd(&(root->downleft),coorAdd);
      calculateDOWNLEFT(root);
      calculateMID(root->downleft);
    }
    else if(cmpval==DOWNRIGHT){
      if(root->downright==NULL){
        QuadTree *new=(QuadTree *)malloc(sizeof(QuadTree));
        *new=(QuadTree){NULL,NULL,NULL,NULL,0,{0,0},{0,0},{0,0},coorAdd};
        root->downright=new;
        root->downright->NOD++;
        }
        else
      root->downright=QuadTreeAdd(&(root->downright),coorAdd);
      calculateDOWNRIGHT(root);
      calculateMID(root->downright);
    }
    return root;
}
QuadTree *QuadTreeAdd(QuadTree **rootPtr,Coordinate coorAdd){
  QuadTree *root=*rootPtr;
  if(root==NULL)
    root=&(QuadTree){NULL,NULL,NULL,NULL,0,{0,0},{0,0},{0,0},coorAdd};
  if (root->NOD == 0){
      root->data =coorAdd;
      root->NOD++;
  }
  else{
    if(root->upleft==NULL&&root->upright==NULL       \
      &&root->downleft==NULL&&root->downright==NULL){
        calculateMID(root);
        root=addTo4(&(root),root->data);
        root->data=(Coordinate){0,0};
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
void QuadTreeInit(QuadTree *Tree){
  Coordinate max={100,100};
  Coordinate min={-100,-100};
  Tree= (QuadTree *)calloc(5000000, sizeof(QuadTree));
  *Tree=(QuadTree){NULL,NULL,NULL,NULL,0,max,min};
}
QuadTree *QuadTreeDelete(QuadTree **rootPtr,Coordinate coorDel){
  QuadTree *root=*rootPtr;
  if(root==NULL)
    return NULL;
  else{

    if(root->upleft==NULL&&root->upright==NULL       \
      &&root->downleft==NULL&&root->downright==NULL){
        if(CompareData(*root,coorDel)==DATASAME){
          return NULL;
        }
        else
           Throw((uintptr_t)(createException("The Coordinate is not existing !!!",0)));
      }

      else{
        int cmpval=CompareMid(*root,coorDel);
        if(cmpval==UPLEFT){
          if(root->upleft==NULL)
              Throw((uintptr_t)(createException("The Coordinate is not existing !!!",0)));
          else{
              root->upleft=QuadTreeDelete(&(root->upleft),coorDel);
          }
        }
        else if(cmpval==UPRIGHT){
          if(root->upright==NULL)
              Throw((uintptr_t)(createException("The Coordinate is not existing !!!",0)));
          else{
            root->upright=QuadTreeDelete(&(root->upright),coorDel);
            }
        }
        else if(cmpval==DOWNLEFT){
          if(root->downleft==NULL)
            Throw((uintptr_t)(createException("The Coordinate is not existing !!!",0)));
          else{
            root->downleft=QuadTreeDelete(&(root->downleft),coorDel);
            }
        }
        else if(cmpval==DOWNRIGHT){
          if(root->downright==NULL)
            Throw((uintptr_t)(createException("The Coordinate is not existing !!!",0)));
          else{
            root->downright=QuadTreeDelete(&(root->downright),coorDel);
            }
        }
        else if(cmpval==SAME){
          return NULL;
        }
      }
      return root;
  }
}
/*
void QuadSearch(QuadTree *root,Quad *Quadrant){
  if(root->upleft!=NULL||root->upright!=NULL||  \
     root->downleft!=NULL||root->downright!=NULL){
    if(root->upleft!=NULL){
      QuadSearch(root,Quadrant);
    }
    else{
      //QuadCheck(root->upleft->data,root);
    }
    if(root->upright!=NULL){
      QuadSearch(root,Quadrant);
    }
    else{
    //  QuadCheck(root->upright->data,root);
    }
    if(root->downleft!=NULL){
      QuadSearch(root,Quadrant);
    }
    else{
    //  QuadCheck(root->downleft->data,root);
    }
    if(root->downright!=NULL){
      QuadSearch(root,Quadrant);
    }
    else{
    //  QuadCheck(root->downright->data,root);
    }
  }
}
void calculateDistance(Coordinate a,Coordinate b){
  double x=a.x-b.x;
  double y=a.y-b.y;
  x=x*x;
  y=y*y;
  double result=sqrt(x+y);
  if(result<COLLISION_RANGE){
    printf("(%d,%d) (%d,%d) range %f",a.x,a.y,b.x,b.y,result);
  }
}
void QuadCheck(Coordinate Coor,QuadTree *root,int mode){
  int lvl=1;
  int *lvlptr=&lvl;
  _QuadCheck(Coor,root,mode,lvlptr);
}
void _QuadCheck(Coordinate Coor,QuadTree *root,int mode,int *level){
  if(*level==1){
    if(mode==UPLEFT){
      QuadTree temp=*root;
      checkUpRight(&temp,Coor,level,mode);
      //checkDownLeft(root,Coor,level,mode);
    //  checkDownRight(root,Coor,level,mode);
    }
    else if(mode==UPRIGHT){
      checkUpLeft(root,Coor,level,mode);
      checkDownLeft(root,Coor,level,mode);
      checkDownRight(root,Coor,level,mode);
    }
    else if(mode==DOWNLEFT){
      checkUpLeft(root,Coor,level,mode);
      checkUpRight(root,Coor,level,mode);
      checkDownRight(root,Coor,level,mode);
    }
    else if(mode==DOWNRIGHT){
      checkUpLeft(root,Coor,level,mode);
      checkUpRight(root,Coor,level,mode);
      checkDownLeft(root,Coor,level,mode);
    }
  }
}
void checkUpRight(QuadTree *root,Coordinate Coor,int level,int mode){
  if(root->upright!=NULL){
    if(root->upright->NOD==1)
        calculateDistance(Coor,(root->upright->data));
    else{
      if(mode==UPLEFT){
        checkUpLeft(root->upright,Coor,level++,mode);
        checkDownLeft(root->upright,Coor,level++,mode);
      }
      else if(mode==UPRIGHT){
        checkUpLeft(root->upright,Coor,level++,mode);
        checkDownLeft(root->upright,Coor,level++,mode);
      }
      else if(mode==DOWNLEFT){
        checkDownLeft(root->upright,Coor,level++,mode);
      }
      else if(mode==DOWNRIGHT){
        checkDownRight(root->upright,Coor,level++,mode);
        checkDownLeft(root->upright,Coor,level++,mode);
      }
    }
}
}
void checkUpLeft(QuadTree *root,Coordinate Coor,int level,int mode){
  if(root->upleft!=NULL){
    if(root->upleft->NOD==1)
        calculateDistance(Coor,(root->upleft->data));
    else{
    //  if(mode==UPLEFT){
    //    checkUpLeft(root->upright,Coor,level++,mode);
    //    checkDownLeft(root->upright,Coor,level++,mode);
    //  }
      if(mode==UPRIGHT){
        checkUpRight(root->upleft,Coor,level++,mode);
        checkDownRight(root->upleft,Coor,level++,mode);
      }
      else if(mode==DOWNLEFT){
        checkDownRight(root->upleft,Coor,level++,mode);
        checkDownLeft(root->upleft,Coor,level++,mode);
      }
      else if(mode==DOWNRIGHT){
        checkDownRight(root->upleft,Coor,level++,mode);
      }
    }
}
}
void checkDownLeft(QuadTree *root,Coordinate Coor,int level,int mode){
  if(root->downleft!=NULL){
    if(root->downleft->NOD==1)
        calculateDistance(Coor,(root->downleft->data));
    else{
      if(mode==UPLEFT){
        checkUpLeft(root->downleft,Coor,level++,mode);
        checkUpRight(root->downleft,Coor,level++,mode);
      }
      else if(mode==UPRIGHT){
        checkUpRight(root->downleft,Coor,level++,mode);
      }
    //  else if(mode==DOWNLEFT){
    //    checkDownLeft(root->upright,Coor,level++,mode);
    //  }
      else if(mode==DOWNRIGHT){
        checkDownRight(root->downleft,Coor,level++,mode);
        checkUpLeft(root->downleft,Coor,level++,mode);
      }
    }
}
}
void checkDownRight(QuadTree *root,Coordinate Coor,int level,int mode){
  if(root->downright!=NULL){
    if(root->downright->NOD==1)
        calculateDistance(Coor,(root->downright->data));
    else{
      if(mode==UPLEFT){
        checkUpLeft(root->downright,Coor,level++,mode);
      }
      else if(mode==UPRIGHT){
        checkUpLeft(root->downright,Coor,level++,mode);
        checkUpRight(root->downright,Coor,level++,mode);
      }
      else if(mode==DOWNLEFT){
        checkUpLeft(root->downright,Coor,level++,mode);
        checkDownLeft(root->downright,Coor,level++,mode);
      }
    //  else if(mode==DOWNRIGHT){
      //  checkDownRight(root->downright,Coor,level++,mode);
      //  checkDownLeft(root->downright,Coor,level++,mode);
      //}
    }
}
}
*/
