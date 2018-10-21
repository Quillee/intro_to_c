#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
// #> Excercise 17
// #> Extra Credit -> change the code to accept parameters for MAX_DATA and MAX_ROWS and store them

// #> macros that replace the const definition with the value
#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
    int id;
    int set;
    char*  name;
    char* email;
};

struct Database {
    struct Address rows[MAX_DATA];
};

struct Connection {
    // #> struct FILE that represents a stream to a file
    FILE * file;
    struct Database *db;
};

// @EXTRACREDIT: add connection to die and close connection
void Database_close(struct Connection *conn);
void die(const char *message, struct Connection * conn_to_die){
    // #> error reporting
    // #> just an int that stores if there was an error
    // #> set by system calls and lib calls
    if(errno){
        // #> perror -> describes last message sent to std error
        perror(message);
    }else{
        printf("ERROR %s\n", message);
    }
    Database_close(conn_to_die);
    exit(1);
}

void print_address(struct Address *address){
    printf("\tid:%d\n\t%s\n\t%s", address->id, address->name, address->email);
}

void Database_load(struct Connection * conn){
    // #> read data from file and place it in the Connection struct wihin the file attribute
    // ?> fread returns 1 on success?
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1) die("Failed to load database", conn);
}

void Database_close(struct Connection * conn){
    if(conn){
        if(conn->file)
            fclose(conn->file);
        if(conn->db)
            free(conn->db);

        free(conn);
    }
}

void Database_write(struct Connection *conn){
    rewind(conn->file);

    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1)
        die("Failed to write to database", conn);

    rc = fflush(conn->file);
    if(rc == -1)
        die("Cannot flush database", conn);
    
}

// #> open database and set up connection
struct Connection *Database_open(const char *filename, char mode){
    struct Connection *conn = malloc(sizeof(struct Connection));
    if(!conn)
        die("Memory error", conn);

    conn->db = malloc(sizeof(struct Database));
    if(!conn->db)
        die("Memory error", conn);

    // #> fopen opens a stream 
    if(mode == 'c'){
        conn->file = fopen(filename, "w");
    } else{
        conn->file = fopen(filename, "r+");

        if(conn->file){
            Database_load(conn);
        }        
    }

    if(!conn->file)
        die("Failed to open file!", conn);
    return conn;
    
}

/* 
 * #> assumes that you opened a database object already
 * 
 */ 
void Database_create(struct Connection *conn){
    
    if(!conn->db)
        die("Null Pointer Error!",  conn);

    int i = 0;

    for( i = 0 ; i < MAX_ROWS; i++){
        // #> make a prototype to init it
        struct Address a = { .id = i, .set = 0 };
        conn->db->rows[i] = a;
    }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email){
    struct Address *addr = &conn->db->rows[id];
    if(addr->set){
        die("Already set, delete first", conn);
    }

    addr->set =1;
    // ! bug, read the "How To Break It" and fix it
    char *res = strncpy(addr->name, name, MAX_DATA);
    strncat(addr->name, "\0", 1);
    // ! error happens here
    if(!res)
        die("string copy failed", conn);
}

void Database_get(struct Connection *conn, int id){
    struct Address *addr = &conn->db->rows[id];

    if(addr->set){
        print_address(addr);
    }else{
        die("ID not set!", conn);
    }
}


void Database_delete(struct Connection *conn, int id){    
    // ?> this is all you need, why use what he is using?
   // conn->db->rows[id].set = 0;
    struct Address default_addr = { .id = id, .set = 0};
    conn->db->rows[id] = default_addr;
}

void Database_list(struct Connection *conn){
    int i = 0;
    struct Database *db = conn->db;

    for(i = 0; i < MAX_ROWS; i++){
        struct Address *cur = &db->rows[i];

        if(cur->set){
            print_address(cur);
        }
    }
}

void print_settings(){
    printf("\tc -> Create new database\n\tg -> Get value from database\n\t")   ;
    printf("d -> Delete from database\n\tl -> List database\n\n");
}

void print_menu(){
    printf("====================================\n");
    printf("Welcome to the DATABASE! \n");
    printf("====================================\n");
    print_settings();
}


int main(int argc, char const *argv[])
{
    print_menu();
    if(argc < 5)
        die("Usage: ex17 <max data> <max rows> <dbfile> <action> [action params]", NULL);
    
    const char * filename = argv[3];
    char action = argv[5][0];
    // @EXTRACREDIT: allowing 
    struct Connection *conn = Database_open(filename, action, atoi(argv[3]), atoi(argv[4]);

    int id =0;

    if(argc > 3) id = atoi(argv[3]);
    
    if(id >= MAX_ROWS) die("CLI Param too large. There's not enough rows!", conn);

    switch(action){
        case 'c':
        case 'C':
            Database_create(conn);
            Database_write(conn);
            break;
        case 'g':
        case 'G':
            if(argc != 4)
                die("Need an id to get!", conn);
            Database_get(conn, id);
            break;
        case 's':
        case 'S':
            if(argc != 6)
                die("Need an id, email and name to set", conn);
            Database_set(conn, id, argv[4], argv[5]);
            Database_write(conn);
            break;
        case 'd':
        case 'D':
            if(argc != 4)
                die("Need id to delete!", conn);
            Database_delete(conn, id);
            Database_write(conn);
            break;
        case 'l':
        case 'L':
            Database_list(conn);
            break;
        default:
            printf("No valid options detected!\n");
            print_settings();
            break;
    }

    return 0;
}