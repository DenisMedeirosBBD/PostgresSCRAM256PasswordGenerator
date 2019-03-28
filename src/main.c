#include <config.h> /* Comes for the autoconf. */
#include <stdio.h>
#include <stdlib.h>

#ifdef HAVE_POSTGRESQL_LIBPQ_FE_H
#  include<postgresql/libpq-fe.h>
#elif HAVE_LIBPQ_FE_H
#  include<libpq-fe.h>
#endif

#define ALGORITHM "scram-sha-256"

int main(int argc, char* argv[])
{

    int lib_version;
    char *encrypted_password, *user, *password;
    PGconn *conn;

    if (argc != 3)
    {
        printf("Expected input: ./pg-password-generator <username> <password>\n");
        return 1;
    }

    user = argv[1];
    password = argv[2];

    /* Get the version of Postgres library (if < 10, can't generate SCRAM-SHA-256). */
    lib_version = PQlibVersion();

    if (lib_version < 100000)
    {
        printf("This program needs at least the LibPQ version 10 to work.\n");
        return 2;
    }

    /* Create a dummy connection (necessary for PQencryptPasswordConn). */
    conn = PQconnectdb("");

    /* Generate the encrypted password using SCRAM=SHA-256. */
    encrypted_password = PQencryptPasswordConn(conn, password, user, ALGORITHM);

    if (encrypted_password == NULL)
    {
        printf("It was not possible to generate the password.");
        return 3;
    }

    /* Print out the result. */

    printf("Encrypted password: ");
    printf("\n----------------------------------------\n");
    printf("%s", encrypted_password);
    printf("\n----------------------------------------\n");

    free(encrypted_password);

    return 0;
}

