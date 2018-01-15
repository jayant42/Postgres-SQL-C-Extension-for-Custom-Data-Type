#include "postgres.h"
#include "fmgr.h"
#include "utils/builtins.h"

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(txn_status_out_function );
Datum
txn_status_out_function(PG_FUNCTION_ARGS)
{
    short int input = PG_GETARG_INT32(0);
	
	
	if(input < 0 || input > 6)
	{
		ereport(ERROR,
            (
             errcode(ERRCODE_INVALID_INPUT),
             errmsg("passed value is not allowed"),
             errdetail("value %d is not valid", input),
             errhint("possible values are begin , commit , complete , incomplete ,prepare , rollback  ")
            )
        );
	}
	
	
	//max size of 11 due to biggest possible output could be incomplete 
	char *buffer = palloc(11 * sizeof(char));	
	    
	switch(input)
	{
		case 1:
			memcpy(buffer,"begin",6);			
			break;
		case 3:			
			memcpy(buffer,"commit",7);			
			break;
		case 5:
			memcpy(buffer,"complete",9);			
			break;		
		case 6:
			memcpy(buffer,"incomplete",11);
			break;		
		case 2:
			memcpy(buffer,"prepare",7);		
			break;			
		case 4:
			memcpy(buffer,"rollback",9);
		break;
		default:
			break;
	}

    PG_RETURN_TEXT_P(cstring_to_text(&buffer));
}