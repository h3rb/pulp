#pragma once

enum FormationPositionType {
 0=fp_front,
 1=fp_forward,
 2=fp_middle,
 3=fp_rearward,
 4=fp_rear
};

string FormationPositionToString( FormationPositionType t );

class GroupFormation : public ListItem {
public:
 Zstring name;
 Indexed<char> formation;
 void Set(
  char a, char b, char c, char d, char e,
  char f, char g, char h, char i, char j,
  char k, char l, char m, char n, char o,
  char p, char q, char s, char t, char u,
  char v, char w, char x, char y, char z
 ) {
  formation.Size(5,5);
  formation(0,0)=a;
  formation(1,0)=b;
  formation(2,0)=c;
  formation(3,0)=d;
  formation(4,0)=e;
  formation(0,1)=f;
  formation(1,1)=g;
  formation(2,1)=h;
  formation(3,1)=i;
  formation(4,1)=j;
  formation(0,2)=k;
  formation(1,2)=l;
  formation(2,2)=m;
  formation(3,2)=n;
  formation(4,2)=o;
  formation(0,3)=p;
  formation(1,3)=q;
  formation(2,3)=s;
  formation(3,3)=t;
  formation(4,3)=u;
  formation(0,4)=v;
  formation(1,4)=w;
  formation(2,4)=x;
  formation(3,4)=y;
  formation(4,4)=z;
 }
};

class GroupFormations : public LinkedList {
public:
 CLEARLISTRESET(GroupFormation);
 GroupFormations();
};

class GroupPosition : public ListItem {
 Zint x,y;
 Zp<Player> player;
};

class GroupPositions : public LinkedList {
public:
 CLEARLISTRESET(GroupPosition);
};

class Group : public ListItem {
 Zp<leader> leader;
 GroupFormation formation;
 GroupPositions positions; // players in the group
 Zbool guarded;
 // True means leader takes B position
 // otherwise takes A position
 void TakePosition( Player *p ) {
 }
 void FindByType(
};

class Groups : public LinkedList {
};

extern Groups groups;
