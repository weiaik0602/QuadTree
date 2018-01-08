#ifndef _EXCEPTION_H
#define _EXCEPTION_H

typedef struct Exception Exception;
typedef Exception* ExceptionPtr;
struct Exception{
  char *msg;
  int errorCode;
};

Exception *createException(char *msg,int errorCode);
void freeException(Exception *e);
void dumpException(Exception *e);

#endif // _EXCEPTION_H
