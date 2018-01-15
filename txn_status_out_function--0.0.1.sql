\echo Use "CREATE EXTENSION txn_status_out_function.c" to load this file. \quit
CREATE OR REPLACE FUNCTION txn_status_out_function(integer) RETURNS text
AS '$libdir/txn_status_out_function
LANGUAGE C IMMUTABLE STRICT;
