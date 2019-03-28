# PostgresSCRAM256PasswordGenerator
This is a simple program to generate password hashes using SCRAM-SHA-256 for Postgres (supported after version 10).
It uses functions provided by `libpq` and in order to compile the program, the operating system needs to have it installed (at least the version 10).
  
### Dependencies
In Ubuntu 18.04 or newer, the `libpq` (currently version 10.6) can be installed by `apt`. For example:

`$ sudo apt-get install libpq-dev`

In Red Hat/ CentOS family, the `libpq` can be installed using the Postgres official repository (version must be > 10). For example:
  
`$ yum -y install https://download.postgresql.org/pub/repos/yum/testing/12/redhat/rhel-7-x86_64/pgdg-centos12-12-1.noarch.rpm`
 
`$ yum update`
 
`$ yum install postgresql10-devel`
  
### How to compile the program
  
In order to compile te program, you must install `autoconf` and `automake` tools in your operating system.

`$ autoreconf -iv`

`$ ./configure`

`$ make`

`$ make install`

If you are using a different location for the Postgres LibPQ, please set the following environment variables before running the commands above.

Example for Postgres 10 installed in CentOS using Postgres repository:

`$ export LIBPQ_LIBS="pq"`

`$ export CPPFLAGS=-I/usr/pgsql-10/include/`
  
### How to use the program
  
Run it by using the following structure:
  
`$ ./pg-password-generator <username> <password>`
 
Then the output of the program will be something like:

```
./pg-password-generator denis 123
Encrypted password:
----------------------------------------
SCRAM-SHA-256$4096:HOxSomOWe7BgQPI/4Aftyw==$7RRjYNfA1dHw0J4bnXNtXhGO+DnUE4o4QFPfOh+wc3Q=:mWCezK1R+9I564I6QO327quciMZXvTI2XnBP14kJcbs=
----------------------------------------
