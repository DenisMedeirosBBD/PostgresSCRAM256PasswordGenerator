CC=cc

# Uncomment the next 2 lines for Ubuntu family:
CFLAGS= -O2 -Wall -I /usr/include/postgresql
LIBS = -L /usr/lib/x86_64-linux-gnu/ -lpq

# Uncomment the next 2 lines for Red Hat family:
#CFLAGS= -O2 -Wall -I /usr/pgsql-10/include/
#LIBS= -L /usr/pgsql-10/lib/ -lpq

.RECIPEPREFIX = +

all: pg-password-generator

pg-password-generator: pg-password-generator.c
+ $(CC) pg-password-generator.c -o pg-password-generator $(CFLAGS) $(LIBS)

clean:
+ rm -f pg-password-generator

