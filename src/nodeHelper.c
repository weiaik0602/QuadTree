#include "nodeHelper.h"


extern Coordinate a,b,c,d,e,f,g,h,i;
extern Coordinate  Cn22,C22,Cn2n2,C2n2,Cn10,C0n1,C00,C1111,Cn11n11,Cn7575,C31,C35;
extern Coordinate  Cn275,C275,C7575,Cn752,C752,Cn75n2,C75n2,Cn75n75,Cn2n75,C2n75,C75n75;
void giveInitdata(void){

  Cn22=(Coordinate){-2,2};
  C22=(Coordinate){2,2};
  Cn2n2=(Coordinate){-2,-2};
  C2n2=(Coordinate){2,-2};
  Cn10=(Coordinate){-1,0};
  C0n1=(Coordinate){0,-1};
  C00=(Coordinate){0,0};
  C1111=(Coordinate){11,11};
  Cn11n11=(Coordinate){-11,-11};
  Cn7575=(Coordinate){-75,75};
  C31=(Coordinate){3,1};
  C35=(Coordinate){3,5};
  Cn275=(Coordinate){-2,75};
  C275=(Coordinate){2,75};
  C7575=(Coordinate){75,75};
  Cn752=(Coordinate){-75,2};
  C752=(Coordinate){75,2};
  Cn75n2=(Coordinate){-75,-2};
  C75n2=(Coordinate){75,-2};
  Cn75n75=(Coordinate){-75,-75};
  Cn2n75=(Coordinate){-2,-75};
  C2n75=(Coordinate){2,-75};
  C75n75=(Coordinate){75,-75};
}
