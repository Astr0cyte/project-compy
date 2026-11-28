// a command line program that accepts a path to a C source file as its only argument.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* genPpName(char *passedFilename) {
    char *container = passedFilename; // container now points the address of first char of filename.

    char *dot = strrchr(passedFilename, '.'); // points to the address of the LAST INSTANCE OF a dot (last instance = defined strrchr behaviour).
    size_t characters = dot - passedFilename; // 'dot' is at a higher address (thus a bigger number). Size_t was recommended by Claude as it is standard practice.

    char *processedFilename = (char *) malloc(characters + 3);
    memcpy(processedFilename, passedFilename, characters);

    // Add preprocessed file extension & null byte.
    processedFilename[characters - 2] = '.';
    processedFilename[characters - 1] = 'i';
    processedFilename[characters] = '\0';

    return processedFilename;
}

char* genAsmName(char *passedFilename) {
    char *container = passedFilename; // container now points the address of first char of filename.

    char *dot = strrchr(passedFilename, '.'); // points to the address of the LAST INSTANCE OF a dot (last instance = defined strrchr behaviour).
    size_t characters = dot - passedFilename; // 'dot' is at a higher address (thus a bigger number). Size_t was recommended by Claude as it is standard practice.

    char *processedFilename = (char *) malloc(characters + 3);
    memcpy(processedFilename, passedFilename, characters);

    // Add assembly file extension & null byte.
    processedFilename[characters - 2] = '.';
    processedFilename[characters - 1] = 's';
    processedFilename[characters] = '\0';

    return processedFilename;
}

char* genExecName(char *passedFilename) {
    char *container = passedFilename; // container now points the address of first char of filename.

    char *dot = strrchr(passedFilename, '.'); // points to the address of the LAST INSTANCE OF a dot (last instance = defined strrchr behaviour).
    size_t characters = dot - passedFilename; // 'dot' is at a higher address (thus a bigger number). Size_t was recommended by Claude as it is standard practice.

    char *processedFilename = (char *) malloc(characters + 1);
    memcpy(processedFilename, passedFilename, characters);

    // Add null byte.
    processedFilename[characters] = '\0';

    return processedFilename;
}

int runPreProcessor(char *passedInFilename, char *passedOutFilename) {
    if(!passedInFilename || !passedOutFilename) {
        return NULL;
    }

    size_t total_len = strlen(passedInFilename) + strlen(passedOutFilename) + 1;
    char command[total_len];
    snprintf(command, sizeof(command), "gcc -E -P %s -o %s\0", passedInFilename, passedOutFilename);

    return system(command);
}

int main(int argc, char *argv[]) {

    // CURRENT ASSUMPTION: [0] = command, [1] = filename param, [2] = first flag.
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: %s, <file_name>\n", argv[0]);
        return 1;
    } 
    
    // argv is an array of addresses.
    // declaration and execution. "Declaration with an initialiser".
    // Execution: writing the address stored in argv[1] into the 8-byte pointer variable.
    const char *filename = argv[1];  // Not an ordinary char. This is a char pointer!
    const char *firstflag = argv[2]; 

    // Handle building all filenames from outset
    const char *preprocessedFilename = genPpName(filename); // The function first needs the address, then dereferences ONCE IT HAS IT.
    const char *assemblyFilename = genAsmName(filename);
    const char *executableFilename = genExecName(filename); 

    int returnCode = runPreProcessor(filename, preprocessedFilename); // returns exit codes for main to use.
    // TODO: add reaction to returned result.

    // handle compilation steps
    if(strcmp(*firstflag, "--lex") == 0) {
        // handle --lex
    } else if (strcmp(*firstflag, "--parse") == 0){
        // handle --parse
    } else if (strcmp(*firstflag, "--codegen") == 0) {
        // handle --codegen
    } else {

    }
}



