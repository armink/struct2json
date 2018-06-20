
typedef struct McBaseOrdrS
{
    int64           ordrNo;
    int64           intrlOrdrNo;
    int64           exePrc;
    int64           elstcPrc;
    int64           ordrQty;
    int64           effectTime;
    int32           ordSide;
    int32           ordrType;
    int32           usrSqno;
    int32           prdctSqno;
    int32           orgSqno;
    int32           extOrdType;
    int32           ordrRestr;
} McBaseOrdrT,  *pMcBaseOrdrT;

typedef struct OrderFS 
{
    int64       ordrNo;
    int64       intrlOrdrNo;
    int64       exePrc;
    int64       elstcPrc;
    int64       ordrEntTim;
    int64       ordrActvTim;
    int64       ordrExpTim;
    int64       ordrTranTime;
    int64       ordrQty;
    int64       remQty;
    int64       exeQty;
    int64       mtchPrc;
    int32       usrSqno;
    int32       prdctSqno;
    int32       orgSqno;
    int32       ordrMask;
    int32       execInstMask;
    int16       ordrSts; 
    int16       extOrdrType;
    int16       cnclReason;
}OrderFT, *pOrderFT;

typedef struct tagOsSListEntry
{
    uint32 next;
    uint32 prev;
}osSListEntryT, *pOsSListEntryT;

typedef struct OrderTS 
{
    osSListEntryT   unrO;
    osSListEntryT   unrAuO;
    osSListEntryT   unrAuOaO;
    osSListEntryT   elstcOrdrLst;
    osSListEntryT   usrDefLst[MAX_LIST_MEM_TYPE];
    
    uint32           priceLdr;
    uint32           slotNo;
    
    char            filler[6];

    int32           free;
    int32           sltOpen;
}OrderTT, *pOrderTT;

typedef struct OrderS
{
    OrderFT orderF;
    OrderTT orderT;
}OrderT, *pOrderT;

