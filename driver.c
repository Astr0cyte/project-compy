// a command line program that accepts a path to a C source file as its only argument.
#include <stdio.h>

int main(int argc, char *argv[]) {

    // CURRENT ASSUMPTION: [0] = command, [1] = filename param, [2] = first flag.
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: %s, <file_name>\n", argv[0]);
        return 1;
    } 

    const char *filename = argv[1];
    const char *firstflag = argv[2];

    // Handle building all filenames from outset
    const char preprocessedFilename = genPpName(*filename);
    const char assemblyFilename = genAsmName(*filename);
    const char executableFilename = genExecName(*filename);

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


char genPpName(char *passedFilename) {
    char container = passedFilename; // Make a copy - do not modify O.G.
    char processedFilename;

    char dot = strrchr(passedFilename, '.');
    char *characters = dot - *passedFilename; // why do we subtract dot - filename? AI suggested this. My hunch is how memory works: I think we are subtracting addresses here. I think 'dot' would be at a higher address (thus a bigger number).

    processedFilename = malloc(characters + 3);
    memcpy(processedFilename, passedFilename, characters);

    // Add preprocessed file extension & null byte.
    processedFilename[characters - 2] = '.';
    processedFilename[characters - 1] = 'i';
    processedFilename[characters] = '\0';

    return processedFilename;
}

char genAsmName(char *passedFilename) {
    char container = passedFilename;
    char processedFilename;

    char dot = strrchr(passedFilename, '.');
    char *characters = dot - *passedFilename; 

    processedFilename = malloc(characters + 3);
    memcpy(processedFilename, passedFilename, characters);

    // Add assembly file extension & null byte.
    processedFilename[characters - 2] = '.';
    processedFilename[characters - 1] = 's';
    processedFilename[characters] = '\0';

    return processedFilename;
}

char genExecName(char *passedFilename) {
    char container = passedFilename; 
    char processedFilename;

    char dot = strrchr(passedFilename, '.');
    char *characters = dot - *passedFilename; 

    processedFilename = malloc(characters + 1);
    memcpy(processedFilename, passedFilename, characters);

    // Add null byte.
    processedFilename[characters] = '\0';

    return processedFilename;
}
