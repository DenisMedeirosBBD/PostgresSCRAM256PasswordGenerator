# PostgresSCRAM256PasswordGenerator
This is a simple program to generate password hashes using SCRAM-SHA-256 for Postgres (supported after version 10).
It uses functions provided by `libpq` and in order to compile the program, the operating system needs to have it installed (at least the version 10).

  
### Dependencies
In Ubuntu 18.04 or newer, the `libpq` (currently version 10.6) can be installed by `apt`. For example:

`$ sudo apt-get install libpq-dev`

In Red Hat/ CentOS family, the `libpq` can be installed using the Postgres official repository (version must be > 10). For example:
  
`$ sudo yum -y install https://download.postgresql.org/pub/repos/yum/10/redhat/rhel-7-x86_64/pgdg-centos10-10-2.noarch.rpm`
 
`$ sudo yum install postgresql10-devel`
  
### How to compile the program
  
In order to compile te program, you must install `autoconf` and `automake` tools in your operating system.

`$ autoreconf -iv`

`$ ./configure`

`$ make`

`$ sudo make install`


If you are using a different location for the Postgres LibPQ, please set the following environment variables before running the commands above.

Example for Postgres 10 installed in CentOS using Postgres repository:

`$ export LIBPQ_CFLAGS="-I/usr/pgsql-10/include/"`

`$ export LIBPQ_LIBS="pq"`

`$ export CPPFLAGS="-I/usr/pgsql-10/include/"`

`$ export LDFLAGS="-L/usr/pgsql-10/lib/"`
 
After the make install, the program will be copied to /usr/bin by default, but this place can be change during the configure script. For example:

```
./configure --prefix=/yourdirectory
```

### How to install it via RPM

There is a RPM package with that program in the releases section. It requires the `postgresql10-devel`, but this can be changed if necessary (the specs file is in the root of the repository).

`$ sudo yum sudo yum install https://github.com/DenisMedeirosBBD/PostgresSCRAM256PasswordGenerator/releases/download/1.0/pg-password-generator-1.0-1.el7.x86_64.rpm`


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
