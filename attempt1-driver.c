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

    // If this succeeds, the driver must produce an executable in the same directory as the input file, with the same name.

    // handle --lex option -> .l extension
    if(argv[3] == "--lex") {
        addLexerExtension(argv[1]);
    }


    // no extension

    char dot = strrchr(filename, '.'); // finds dot location in memory
    char *characters = dot - filename; // calculates number of characters in file name (excluding the extension).

    outFilename = malloc(characters + 1); // allocate the number of characters into memory + 1 for /0. Using outFilename for the buffer pointer.

    // copy the file name into that memory slot.
    memcpy(outFilename, filename, characters); //memcpy(dest, src, n): Copies n bytes from src into dest.

    // manually assign the null byte at the end of the buffer.
    outFilename[characters] = '\0'; 




}

char addLexerExtension(char *argveeone) { // does this parameter automatically dereference what is in argv[1]? Thus, is this a string? I dont think so. 
    
    char filename = argveeone; 
    char outFilename;
    char dot = strrchr(filename, '.');
    char *characters = dot - filename; // why do we subtract dot - filename? AI suggested this. My hunch is how memory works: I think we are subtracting addresses here. I think 'dot' would be at a higher address (thus a bigger number).

    outFilename = malloc(characters + 3);
    memcpy(outFilename, filename, characters);
    outFilename[characters - 2] = '.';
    outFilename[characters - 1] = 'l';
    outFilename[characters] = '\0';

}
