#pragma once

#include "Interview.h"

class ScriptedResponse : public ListItem {
public:
 Strings keywords;
 Zp<Script> resulting;
 ScriptedResponse *Clone() {
  ScriptedResponse *s=new ScriptedResponse;
  s->keywords.Add(&keywords);
  s->resulting=resulting;
  return s;
 }
};

class ScriptedResponses : public LinkedList {
public:
 ScriptedResponses *Clone() {
  ScriptedResponses *sr = new ScriptedResponses;
  FOREACH(ScriptedResponse,s) sr->Append(s->Clone());
  return sr;
 }
 ScriptedResponse *findByKeyword( string keyword ) {
  FOREACH(ScriptedResponse,s) if ( s->keywords.matches(keyword) ) return s;
  return null;
 }
 CLEARLISTRESET(ScriptedResponse);
};

class ScriptedInterview : public Interview {
public:
 Zstring name;
 Zstring query;
 ScriptedResponses responses;
 ScriptedInterview() : Interview() {}
 ScriptedInterview( string in ) : Interview() { fromString(in); }
 ScriptedInterview *Clone() {
  ScriptedInterview *s=new ScriptedInterview;
  return s;
 }
 string Query( InSession *session ) {
  return query.value;
 }
 void Response( InSession *session, string in ) {
  string first=string("");
  string_argument_case(in,&first);
  ScriptedResponse *result=responses.findByKeyword(first);
  if ( result ) {
   Execution *e=session->executions.Execute(result->resulting,session,this);
  }
 }
};

class ScriptedInterviews : public LinkedList {
public:
};
