#include "postgres.h"
#include "fmgr.h"
#include "utils/builtins.h"

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(txn_status_in_function);
Datum
txn_status_in_function(PG_FUNCTION_ARGS)
{
    char* arg = PG_GETARG_CSTRING(0);
	
	int i;
	int16 result = 0;
	
	if(strlen(arg) > 11)
	{
		ereport(ERROR,
            (
             errcode(ERRCODE_INVALID_TEXT),
             errmsg("passed string values is not allowed"),
             errdetail("value %s is not valid", arg),
             errhint("possible values are begin , commit , complete , incomplete ,prepare , rollback  ")
            )
        );
	}
	
	    
	switch(arg[0])
	{
		case 'b':
			if(strcmp(arg,"begin")
				result = 1; 
			break;
		case 'c':
			if(strcmp(arg,"commit")
				result = 3; 
			else if(strcmp(arg,"complete")
				result = 5; 
			break;		
		case 'i':
			if(strcmp(arg,"incomplete")
				result = 6; 
			break;		
		case 'r':
			if(strcmp(arg,"prepare")
				result = 2; 
			break;			
		case 'r':
			if(strcmp(arg,"rollback")
				result = 4; 
			break;
		default:
			result = 0;
			break;
	}

	pfree(arg);
	
	if(result == 0)
	{
		ereport(ERROR,
            (
             errcode(ERRCODE_INVALID_TEXT),
             errmsg("passed string values is not allowed"),
             errdetail("value %s is not valid", arg),
             errhint("possible values are begin , commit , complete , incomplete ,prepare , rollback  ")
            )
        );
	}

    PG_RETURN_INT16(result);
}