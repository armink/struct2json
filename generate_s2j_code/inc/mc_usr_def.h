/***
example
***/

#ifndef _MC_USER_DEF_
#define _MC_USER_DEF_

/*****************************************************************************
 **
 **  Header File
 **
 *****************************************************************************/
/* Standard C header files */
#include <stdio.h>       /* define standard i/o functions        */
#include <stdlib.h>      /* define standard library functions    */
#include <string.h>      /* define string handling functions     */

#ifdef __cplusplus
extern "C" {
#endif


/*****************************************************************************
 **
 ** Type Defination
 **
 *****************************************************************************/


/*****************************************************************************
 **
 ** Macro
 **
 *****************************************************************************/

/******************************************************************************
 **
 **  Structure
 **
 ******************************************************************************/

typedef int int32;
typedef long long int64;


typedef struct UsrDefOrdrS
{
    char    usrName[8];
    int64   usrSqno;
}UsrDefOrdrT, *pUsrDefOrdrT;

typedef struct McBaseOrdrS
{
	int64 ordrNo;
	int64 intrlOrdrNo;
	int64 exePrc;
	int64 elstcPrc;
	int64 ordrQty;
	int64 effectTime;
	int32 ordSide;
	int32 ordrType;
	int32 usrSqno;
	int32 prdctSqno;
	int32 orgSqno;
	int32 extOrdType;
	int32 ordrRestr;

} McBaseOrdrT, *pMcBaseOrdrT;

typedef struct McBaseOrdrArray
{
	McBaseOrdrT mcBaseOrdrArray[2] ;

} McBaseOrdrArrayT;

typedef struct McOcoBaseOrdrS
{
	McBaseOrdrT mcBaseOrdr;
	void * pUsrDef;

} McOcoBaseOrdrT, *pMcOcoBaseOrdrT;


#ifdef __cplusplus
}
#endif

#endif /* _MC_USER_DEF_ */
