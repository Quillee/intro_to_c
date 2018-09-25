#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

struct Database {
    struct Address rows[MAX_DATA];
};

struct Connection {
    FILE * file;
    struct Database *db;
};

void die(const char *message){
    // ?
    if(errno){
        // ?
        perror(message);
    }else{
        printf("ERROR %s\n", message);
    }

    exit(1);
}

void print_address(struct Address *address){
    printf("id:%d\v%s\v%s", address->id, address->name, address->email);
}

void load_database(struct Connection * conn){
    // #> read data from file and place it in the Connection struct wihin the file attribute
    // ?> fread returns 1 on success?
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1) die("Failed to load database");
}

void close_database(struct Connection * conn){
    if(conn){
        if(conn->file)
            fclose(conn->file);
        if(conn->db)
            free(conn->db);

        free(conn);
    }
}

void write_to_database(struct Connection *conn){
    rewind(conn->file);

    int rc = fwrite(conn->db, sizeof(struct Database), conn->file);
    if(rc != 1)
        die("Failed to write to database");

    rc = fflush(conn->file);
    
    
}

// #> open database and set up connection
struct Connection *open_database(const char *filename, char mode){
    struct Connection *conn = malloc(sizeof(struct Connection));
    if(!conn)
        die("Memory error");

    conn->db = malloc(sizeof(struct Database));
    if(!conn->db)
        die("Memory error");

    if(mode == 'c'){
        conn->file = fopen(filename, "w");
    } else{
        conn->file = fopen(filename, "r+");

        if(conn->file){
            load_database(conn);
        }        
    }

    if(!conn->file)
        die("Failed to open file!");
    return conn;
    
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

