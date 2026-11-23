// a command line program that accepts a path to a C source file as its only argument.
#include <stdio.h>

int main(int argc, char *argv[]) {

    // Ensure correct command convention.
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: <file_name>\n");
        return 1;
    }

    const char *filename = argv[1];
    char *outFilename;

    // --lex
    if(argv[3] == "--lex") {
        handleLexer(argv[1]);
    // -- parse
    } else if {

    // --codegen
    } else if {

    // no flags    
    } else {

    }



}



char handleLexer(char *argveeone) { 
    
    
}
