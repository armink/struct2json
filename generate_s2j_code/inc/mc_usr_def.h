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

typedef int (*fun_ptr_CbT)(int,int);

typedef enum WEEK_DAY
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
}enumWEEK_DAY_T;


typedef struct McUsrInfoS
{
    int *pInt;
    int *pIntArray[2];
    fun_ptr_CbT fun;
    fun_ptr_CbT funArray[2];
    enum WEEK_DAY day1;
    enumWEEK_DAY_T day2;
    enumWEEK_DAY_T day2Array[2];
    unsigned char    id;
    unsigned char    idArray[2];
    char    usrType;
    char    usrName[8];
    char    usrNameArray[2][8];
    int32   usrSqno;
    int32     ussSqnoArray[2];
    int64   jobSqno;
    int64   jobSqnoArray[2];
    float     rate;
    float     rateArray[2];
    double     price;
    double     priceArray[2];
} McUsrInfoT, *pMcUsrInfoT;

typedef struct McBaseOrdrS
{
    short   taskSqno;
    short   taskSqnoArray[2];
    double     price;
    double     priceArray[2];
} McBaseOrdrT, *pMcBaseOrdrT;

typedef struct McBaseOrdrArray
{
    McBaseOrdrT mcBaseOrdrArray[2];
} McBaseOrdrArrayT;

typedef struct McOcoBaseOrdrS
{
    McBaseOrdrArrayT mcBaseOrdrAry;
    void * pUsrDef;
} McOcoBaseOrdrT, *pMcOcoBaseOrdrT;


#ifdef __cplusplus
}
#endif

#endif /* _MC_USER_DEF_ */
