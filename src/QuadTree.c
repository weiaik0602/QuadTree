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
              if(root->upleft==NULL)
                root->NOD--;
          }
        }
        else if(cmpval==UPRIGHT){
          if(root->upright==NULL)
              Throw((uintptr_t)(createException("The Coordinate is not existing !!!",0)));
          else{
            root->upright=QuadTreeDelete(&(root->upright),coorDel);
            if(root->upright==NULL)
              root->NOD--;
            }
        }
        else if(cmpval==DOWNLEFT){
          if(root->downleft==NULL)
            Throw((uintptr_t)(createException("The Coordinate is not existing !!!",0)));
          else{
            root->downleft=QuadTreeDelete(&(root->downleft),coorDel);
            if(root->downleft==NULL)
              root->NOD--;
            }
        }
        else if(cmpval==DOWNRIGHT){
          if(root->downright==NULL)
            Throw((uintptr_t)(createException("The Coordinate is not existing !!!",0)));
          else{
            root->downright=QuadTreeDelete(&(root->downright),coorDel);
            if(root->downright==NULL)
              root->NOD--;
            }
        }
        else if(cmpval==SAME){
          return NULL;
        }
      }
      if(root->NOD==1){
        if(root->upleft!=NULL){
          root->data=root->upleft->data;
          root->upleft=NULL;
        }
        else if(root->upright!=NULL){
          root->data=root->upright->data;
          root->upright=NULL;
        }
        else if(root->downleft!=NULL){
          root->data=root->downleft->data;
          root->downleft=NULL;
        }
        else if(root->downright!=NULL){
          root->data=root->downright->data;
          root->downright=NULL;
        }
      }
      return root;
  }
}

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
  //if(result<COLLISION_RANGE){
    printf("(%d,%d) (%d,%d) range %.2f\n",a.x,a.y,b.x,b.y,result);
  //}
}
void QuadCheck(QuadTree *root){
  if(root->upleft!=NULL){
    Pointer *new=(Pointer*)calloc(1,sizeof(Pointer));
    new=insertPointer(root,new,UPLEFT);
    //_QuadCheck(root->upleft,new);
    int a=1;

  }
  else{
    Pointer new;
    //_QuadCheck(root,new);
  }
}
void _QuadCheck(QuadTree *root,Pointer point){

}
Pointer* insertPointer(QuadTree *root,Pointer* point,int mode){
  if(point->A==NULL&&point->B==NULL&&point->C==NULL&&point->D==NULL\
    &&point->E==NULL&&point->F==NULL&&point->G==NULL&&point->H==NULL\
    &&point->I==NULL){
        point=insertNULLPointer(root,point,mode);
      }
  else{
    if(mode==UPLEFT){
      insertUPLEFTPointer(point);
    }
  }
}
Pointer* insertUPLEFTPointer(Pointer *root){
  Pointer *point=(Pointer *)malloc(sizeof(Pointer));
  *point=*root;
  //A
  if(point->A!=NULL&&point->A->NOD>1)
    point->A=point->A->downright;
  //B&C
  if(point->B!=NULL&&point->B->NOD>1){
    point->C=point->B->downright;
    point->B=point->B->downleft;
  }
  //D
  point->D=point->I->upright;
  //E
  point->E=point->I->downright;
  //F
  point->F=point->I->downleft;

  //G&H
  if(point->H!=NULL&&point->H->NOD>1){
    point->G=point->H->downright;
    point->H=point->H->upright;
  }
  //I
  point->I=point->I->upleft;
  return point;
}
Pointer* insertUPRIGHTPointer(Pointer *root){
  Pointer *point=(Pointer *)malloc(sizeof(Pointer));
  *point=*root;
  //A&B
  if(point->B==NULL){
    point->A=NULL;
  }
  else{
    point->A=point->B->downleft;
    point->B=point->B->downright;
  }
  //C
  if(point->C!=NULL&&point->C->NOD>1){
    point->C=point->C->downleft;
  }
  //D&E
  if(point->D!=NULL&&point->D->NOD>1){
    point->E=point->D->upleft;
    point->D=point->D->upleft;
  }
  //F
  point->F=point->I->downright;
  //G
  point->G=point->I->downleft;
  //H
  point->H=point->I->upleft;
  //I
  point->I=point->I->upright;

  return point;
}
Pointer* insertDOWNRIGHTPointer(Pointer *root){
  Pointer *point=(Pointer *)malloc(sizeof(Pointer));
  *point=*root;
  //A
  point->A=point->I->upleft;
  //B
  point->B=point->I->upright;
  //C&D
  if(point->D!=NULL&&point->D->NOD>1){
    point->C=point->D->upleft;
    point->D=point->D->downleft;
  }
  //E
  if(point->E!=NULL)
    point->E=point->E->upleft;
  //F&G
  if(point->F!=NULL&&point->F->NOD>1){
    point->G=point->F->upleft;
    point->F=point->F->upright;
  }
  //H
  point->B=point->I->downleft;
  //I
  point->I=point->I->downright;

  return point;
}
Pointer *insertNULLPointer(QuadTree *root,Pointer* point,int mode){
  Pointer *new=(Pointer *)malloc(sizeof(Pointer));
  if(mode==UPLEFT){
    *new=(Pointer){NULL,NULL,NULL,root->upright,root->downright,\
      root->downleft,NULL,NULL,root->upleft};
  }
  else if(mode==UPRIGHT){
    *new=(Pointer){NULL,NULL,NULL,NULL,NULL,\
      root->downright,root->downleft,root->upleft,root->upright};
  }
  else if(mode==DOWNRIGHT){
    *new=(Pointer){root->upleft,root->upright,NULL,NULL,NULL,\
      NULL,NULL,root->downleft,root->downright};
  }
  else if(mode==DOWNLEFT){
    *new=(Pointer){NULL,root->upleft,root->upright,root->downright,NULL,\
      NULL,NULL,NULL,root->downleft};
  }
  point=new;
  return point;
}











///////////////////////////////////////////////////////////////////////////////
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

Quad* putQuad(QuadTree *root,Quad *quadrant,int lvl){
  if(root->NOD==1){
    quadrant->data=root->data;
    quadrant->level=lvl;
  }
  else{
    Quad *new=(Quad *)malloc(sizeof(Quad));
    *new=(Quad){NULL,NULL,NULL,NULL,{0,0},lvl};
    quadrant=new;
    if(root->upleft!=NULL){
      if(root->upleft->NOD==1){
         Quad *new=(Quad *)malloc(sizeof(Quad));
         *new=(Quad){NULL,NULL,NULL,NULL,{0,0},lvl+1};
        quadrant->Q1=new;

        quadrant->Q1->data=root->upleft->data;}
      else
        quadrant->Q1=putQuad(root->upleft,quadrant->Q1,lvl+1);
      }
      if(root->upright!=NULL){
        if(root->upright->NOD==1){
          Quad *new=(Quad *)malloc(sizeof(Quad));
          *new=(Quad){NULL,NULL,NULL,NULL,{0,0},lvl+1};
          quadrant->Q2=new;
          quadrant->Q2->data=root->upright->data;}

        else
          quadrant->Q2=putQuad(root->upleft,quadrant->Q2,lvl+1);
        }
        if(root->downright!=NULL){
          if(root->downright->NOD==1){
            Quad *new=(Quad *)malloc(sizeof(Quad));
            *new=(Quad){NULL,NULL,NULL,NULL,{0,0},lvl+1};
            quadrant->Q3=new;
            quadrant->Q3->data=root->downright->data;}

          else
            quadrant->Q3=putQuad(root->downright,quadrant->Q3,lvl+1);
          }
          if(root->downleft!=NULL){
            if(root->downleft->NOD==1){
              Quad *new=(Quad *)malloc(sizeof(Quad));
              *new=(Quad){NULL,NULL,NULL,NULL,{0,0},lvl+1};
              quadrant->Q4=new;
              quadrant->Q4->data=root->downleft->data;}

            else
              quadrant->Q4=putQuad(root->downleft,quadrant->Q4,lvl+1);
            }
            return quadrant;
  }
}
