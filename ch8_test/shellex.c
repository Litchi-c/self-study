#include "include/csapp.h"

#define MAXARGS 128

/* Function prototypes */

void eval(char *cmdline);
int parseLine(char *buf, char **argv);
int builtInCommand(char **argv);

int main(){
    char cmd_line[MAXARGS]; // Commands line

    while (1){
        // read
        printf(">");
        Fgets(cmd_line, MAXLINE, stdin);

        if (feof(stdin)){
            exit(0);
        }

        // evaluate
        eval(cmd_line);
    }
}


// eval - Evaluate a command line
void eval(char *cmd_line){
    char *argv[MAXARGS]; // args list exec()
    char buf[MAXLINE];
    int bg;  //bool: should the job run in bg or fg?
    pid_t pid;

    strcpy(buf, cmd_line);

    bg = parseLine(buf, argv);

    if (argv[0] == NULL)
        return; // Ignore empty lines.
    
    if (!(builtInCommand(argv))){
    // return true, if first argv is a builtin command.
        if ((pid = Fork()) == 0){
        // Child runs user job.

            if (execve(argv[0], argv, environ) < 0){
                printf("%s: Command not found.\n", argv[0]);
                exit(0);
            }
        }

        if (!bg){
        // parent waits for fg job to terminate.
            int status;
            if (waitpid(pid, &status, 0) < 0)
                unix_error("waitfg: waitpid error");
        }
        else
        // if the job is bg
            printf("%d %s", pid, cmd_line);

    }
}

// If first arg is a builtin command, run it and return true.
int builtInCommand(char **argv){
    
    if (!strcmp(argv[0], "quit")){
    // COMMAND: quit
        exit(0);
    }
    if (!strcmp(argv[0], "&")) {
    // Ignore singleton &
        return 1;
    }
    return 0;  // not a builtin command. 
}

// parseline - Parse the command line and build the argv array.
int parseLine(char *buf, char **argv){
    char *delim; // Points to first space delimiter.
    int argc;
    int bg; //bool: Is bg job?

    buf[strlen(buf) - 1] = ' '; // ex: "ls ...\n" replace "ls ... "
    while (*buf && (*buf == ' ')) // ignore leading space
    // ex "   ls ..." replace "ls ..."
        buf++;
    
    // Build the argv list.
    argc = 0;
    while ((delim = strchr(buf, ' '))){
// ex:
//   buf -> "ls -a -b -c "
// argv[0] = "ls"
// argv[1] = "-a" 
// argv[2] = "-b"
// argv[3] = "-c"
// argv[4] = NULL

        argv[argc++] = buf;
        *delim = '\0';
        buf = delim + 1;
        while (*buf &&(*buf == ' ')){
            // Ignore spaces.
            buf++;
        }
    }
    argv[argc] = NULL;

    if (argc == 0)
        // Ignore blank line.
        return 1;

    // Should the job run in the bg?
    if ((bg = (*argv[argc - 1] == '&')) != 0)
        argv[--argc] = NULL;
    
    return bg;
}