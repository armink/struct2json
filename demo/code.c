/*
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
*/
cJSON *struct_to_json_McBaseOrdrT(void* struct_obj)
{
	s2j_create_json_obj(json_obj_2);
	McBaseOrdrT *struct_obj_2 = (McBaseOrdrT *)struct_obj;
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, double, ordrNo);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, double, intrlOrdrNo);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, double, exePrc);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, double, elstcPrc);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, double, ordrQty);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, double, effectTime);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, int, ordSide);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, int, ordrType);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, int, usrSqno);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, int, prdctSqno);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, int, orgSqno);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, int, extOrdType);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, int, ordrRestr);
	return json_obj_2;
}
void *json_to_struct_McBaseOrdrT(cJSON* json_obj)
{
	s2j_create_struct_obj(struct_obj_2, McBaseOrdrT);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, double, ordrNo);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, double, intrlOrdrNo);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, double, exePrc);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, double, elstcPrc);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, double, ordrQty);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, double, effectTime);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, int, ordSide);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, int, ordrType);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, int, usrSqno);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, int, prdctSqno);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, int, orgSqno);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, int, extOrdType);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, int, ordrRestr);
	return struct_obj_2;
}
/*
typedef struct OrderFS
{
	int64 ordrNo;
	int64 intrlOrdrNo;
	int64 exePrc;
	int64 elstcPrc;
	int64 ordrEntTim;
	int64 ordrActvTim;
	int64 ordrExpTim;
	int64 ordrTranTime;
	int64 ordrQty;
	int64 remQty;
	int64 exeQty;
	int64 mtchPrc;
	int32 usrSqno;
	int32 prdctSqno;
	int32 orgSqno;
	int32 ordrMask;
	int32 execInstMask;
	int16 ordrSts;
	int16 extOrdrType;
	int16 cnclReason;
	
}OrderFT, *pOrderFT;
*/
cJSON *struct_to_json_OrderFT(void* struct_obj)
{
	s2j_create_json_obj(json_obj_2);
	OrderFT *struct_obj_2 = (OrderFT *)struct_obj;
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, double, ordrNo);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, double, intrlOrdrNo);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, double, exePrc);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, double, elstcPrc);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, double, ordrEntTim);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, double, ordrActvTim);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, double, ordrExpTim);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, double, ordrTranTime);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, double, ordrQty);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, double, remQty);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, double, exeQty);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, double, mtchPrc);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, int, usrSqno);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, int, prdctSqno);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, int, orgSqno);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, int, ordrMask);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, int, execInstMask);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, int, ordrSts);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, int, extOrdrType);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, int, cnclReason);
	return json_obj_2;
}
void *json_to_struct_OrderFT(cJSON* json_obj)
{
	s2j_create_struct_obj(struct_obj_2, OrderFT);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, double, ordrNo);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, double, intrlOrdrNo);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, double, exePrc);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, double, elstcPrc);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, double, ordrEntTim);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, double, ordrActvTim);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, double, ordrExpTim);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, double, ordrTranTime);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, double, ordrQty);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, double, remQty);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, double, exeQty);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, double, mtchPrc);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, int, usrSqno);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, int, prdctSqno);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, int, orgSqno);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, int, ordrMask);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, int, execInstMask);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, int, ordrSts);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, int, extOrdrType);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, int, cnclReason);
	return struct_obj_2;
}
/*
typedef struct tagOsSListEntry
{
	uint32 next;
	uint32 prev;
	
}osSListEntryT, *pOsSListEntryT;
*/
cJSON *struct_to_json_osSListEntryT(void* struct_obj)
{
	s2j_create_json_obj(json_obj_2);
	osSListEntryT *struct_obj_2 = (osSListEntryT *)struct_obj;
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, int, next);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, int, prev);
	return json_obj_2;
}
void *json_to_struct_osSListEntryT(cJSON* json_obj)
{
	s2j_create_struct_obj(struct_obj_2, osSListEntryT);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, int, next);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, int, prev);
	return struct_obj_2;
}
/*
typedef struct OrderTS
{
	osSListEntryT unrO;
	osSListEntryT unrAuO;
	osSListEntryT unrAuOaO;
	osSListEntryT elstcOrdrLst;
	osSListEntryT usrDefLst[MAX_LIST_MEM_TYPE];
	uint32 priceLdr;
	uint32 slotNo;
	char filler[6];
	int32 free;
	int32 sltOpen;
	
}OrderTT, *pOrderTT;
*/
cJSON *struct_to_json_OrderTT(void* struct_obj)
{
	s2j_create_json_obj(json_obj_2);
	OrderTT *struct_obj_2 = (OrderTT *)struct_obj;
	s2j_json_set_struct_element_by_func(json_obj_2, struct_obj_2,osSListEntryT,unrO);
	s2j_json_set_struct_element_by_func(json_obj_2, struct_obj_2,osSListEntryT,unrAuO);
	s2j_json_set_struct_element_by_func(json_obj_2, struct_obj_2,osSListEntryT,unrAuOaO);
	s2j_json_set_struct_element_by_func(json_obj_2, struct_obj_2,osSListEntryT,elstcOrdrLst);
	s2j_json_set_struct_array_element_by_func(json_obj_2, struct_obj_2, osSListEntryT,usrDefLst,MAX_LIST_MEM_TYPE);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, int, priceLdr);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, int, slotNo);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, string, filler);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, int, free);
	s2j_json_set_basic_element(json_obj_2, struct_obj_2, int, sltOpen);
	return json_obj_2;
}
void *json_to_struct_OrderTT(cJSON* json_obj)
{
	s2j_create_struct_obj(struct_obj_2, OrderTT);
	s2j_struct_get_struct_element_by_func(struct_obj_2, json_obj, osSListEntryT,unrO);
	s2j_struct_get_struct_element_by_func(struct_obj_2, json_obj, osSListEntryT,unrAuO);
	s2j_struct_get_struct_element_by_func(struct_obj_2, json_obj, osSListEntryT,unrAuOaO);
	s2j_struct_get_struct_element_by_func(struct_obj_2, json_obj, osSListEntryT,elstcOrdrLst);
	s2j_struct_get_struct_array_element_by_func(struct_obj_2, json_obj, osSListEntryT,usrDefLst);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, int, priceLdr);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, int, slotNo);
	s2j_struct_get_basic_element(struct_obj_2,json_obj,string, filler);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, int, free);
	s2j_struct_get_basic_element(struct_obj_2,json_obj, int, sltOpen);
	return struct_obj_2;
}
/*
typedef struct OrderS
{
	OrderFT orderF;
	OrderTT orderT;
	
}OrderT, *pOrderT;
*/
cJSON *struct_to_json_OrderT(void* struct_obj)
{
	s2j_create_json_obj(json_obj_2);
	OrderT *struct_obj_2 = (OrderT *)struct_obj;
	s2j_json_set_struct_element_by_func(json_obj_2, struct_obj_2,OrderFT,orderF);
	s2j_json_set_struct_element_by_func(json_obj_2, struct_obj_2,OrderTT,orderT);
	return json_obj_2;
}
void *json_to_struct_OrderT(cJSON* json_obj)
{
	s2j_create_struct_obj(struct_obj_2, OrderT);
	s2j_struct_get_struct_element_by_func(struct_obj_2, json_obj, OrderFT,orderF);
	s2j_struct_get_struct_element_by_func(struct_obj_2, json_obj, OrderTT,orderT);
	return struct_obj_2;
}
int main(void)
 {
		TEST_S2J_STRUCT(McBaseOrdrT, 0);
		TEST_S2J_STRUCT(OrderFT, 0);
		TEST_S2J_STRUCT(osSListEntryT, 0);
		TEST_S2J_STRUCT(OrderTT, 0);
		TEST_S2J_STRUCT(OrderT, 0);
	return 0;
}