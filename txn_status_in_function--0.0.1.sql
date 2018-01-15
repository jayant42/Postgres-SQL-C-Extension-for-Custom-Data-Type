\echo Use "CREATE EXTENSION txn_status_in_function.c" to load this file. \quit
CREATE OR REPLACE FUNCTION txn_status_in_function(text) RETURNS integer
AS '$libdir/txn_status_in_function
LANGUAGE C IMMUTABLE STRICT;
