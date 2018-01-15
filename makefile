INCLUDES =	-I C:/MinGW -I C:\PostgreSQL\pg10\include\postgresql\server\utils

EXTENSION = txn_status_in_function        # the extensions name
DATA = txn_status_in_function--0.0.1.sql  # script files to install
MODULES = txn_status_in_function          # our c module file to build

# postgres build stuff
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)


EXTENSION = txn_status_out_function        # the extensions name
DATA = txn_status_out_function--0.0.1.sql  # script files to install
MODULES = txn_status_out_function          # our c module file to build

# postgres build stuff
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
