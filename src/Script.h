#pragma once

#include "LinkedList.h"
#include "Flag.h"
#include "MultitypeVariables.h"

class Script : public ListItem {
public:
 Zstring name,code;
 Strings keywords;
 Zint pace,max;
 Zstring ritual;
 Strings reagents;
 Numbers quantities;
 Flags flags;
};

class Scripts : public LinkedList {
public:
 CLEARLISTRESET(Script);
};

class ScriptAttachment : public ListItem {
public:
 Zp<Script> script;
 Zint concurrent;
 ScriptAttachment() : ListItem() {}
 ScriptAttachment( Script *s ) : ListItem() { script=s; }
};

class ScriptAttachments : public LinkedList {
public:
 ScriptAttachments() : LinkedList() {}
 ScriptAttachment *Attach( Script *s ) {
  ScriptAttachment *sa=new ScriptAttachment(s);
  Append(sa);
  return sa;
 }
 void Attach( ScriptAttachments *in ) {
  EACH(in->first,ScriptAttachment,sa) {
   Append(new ScriptAttachment(sa->script));
  }
 }
 CLEARLISTRESET(ScriptAttachment);
};

class Execution : public ListItem {
public:
 void Execute( Script *s ) {
  script=s;
  execution=s->code.c_str();
 }
 void Execute( Script *s, Prop *owner, Player *p ) {
  player=p;
  Execute(s);
  Owner(owner);
 }
 void Execute( Script *s, Actor *owner, Player *p ) {
  player=p;
  Execute(s);
  Owner(owner);
 }
 void Execute( Script *s, Scene *owner, Player *p ) {
  player=p;
  Execute(s);
  Owner(owner);
 }
 void Execute( Script *s, Geography *owner, Player *p ) {
  player=p;
  Execute(s);
  Owner(owner);
 }
 void Execute( Script *s, Nation *owner, Player *p ) {
  player=p;
  Execute(s);
  Owner(owner);
 }
 void Execute( Script *s, Empire *owner, Player *p ) {
  player=p;
  Execute(s);
  Owner(owner);
 }
 void Execute( Script *s, Dimension *owner, Player *p ) {
  player=p;
  Execute(s);
  Owner(owner);
 }
 void Execute( Script *s, InSession *x, ScriptedInterview *i ) {
  Execute(s);
  session=x;
  interview=i;
 }
 void Owner( Prop *p      ) { this->p=p; }
 void Owner( Actor *a     ) { this->a=a; }
 void Owner( Scene *s     ) { this->s=s; }
 void Owner( Geography *g ) { this->g=g; }
 void Owner( Nation *n    ) { this->n=n; }
 void Owner( Empire *e    ) { this->e=e; }
 void Owner( Dimension *d ) { this->d=d; }
 void Relevant( Prop *p      ) { prop=p;      }
 void Relevant( Actor *a     ) { actor=a;     }
 void Relevant( Scene *s     ) { scene=s;     }
 void Relevant( Geography *g ) { geography=g; }
 void Relevant( Nation *n    ) { nation=n;    }
 void Relevant( Empire *e    ) { empire=e;    }
 void Relevant( Dimension *d ) { dimension=d; }
 void Relevant( Player *v    ) { victim=v;    }
 // Finds a random member victim in the player's group
 void Member() {
 }
 // Finds a random hire victim in the player's group
 void Hireling() {
 }
 // Executive
 Zp<const char *p> execution;
 Zint pace;
 MultitypeVariables multitypes;
 Zp<Script> script;
 Zdouble pause;
 Flags flags;
 // Owners
 Zp<Prop> p;
 Zp<Actor> a;
 Zp<Scene> s;
 Zp<Geography> g;
 Zp<Nation> n;
 Zp<Empire> e;
 Zp<Dimension> d;
 // Relevants
 Zp<Scene> last;
 Zp<Actor> actor,hire;
 Zp<Player> player,associate,victim;
 Zp<Prop> prop;
 Zp<Geography> geography;
 Zp<Nation> nation;
 Zp<Empire> empire;
 Zp<Dimension> dimension;
// for ScriptedInterviews
 Zp<ScriptedInterview> interview;
 Zp<Session> session;
};

class Executions : public LinkedList {
public:
 CLEARLISTRESET(Execution);
};

class ExecutionHandle : public ListItem {
public:
 Zp<Execution> execution;
 ExecutionHandle( Execution *e ) : ListItem() {
  execution=e;
 }
};

class ExecutionHandles : public LinkedList {
 void Add( Execution *e ) { Append(new ExecutionHandle(e)); }
 CLEARLISTRESET(ExecutionHandle);
};

extern ExecutionHandles scriptExecutions;
