#include "imgDetect.h"

char expectedInitialBytes[START_BYTES] = {0xFF, 0xD8, 0xFF};

int isJpeg(FILE*fp)
{
    long curr_pos = ftell(fp);
    
    char initialReadBytes[START_BYTES];

    int readBytes = fread(initialReadBytes, 1, START_BYTES, fp);

    SEEK_SET_CHECK(fp, curr_pos, "isJpeg-fseek");

    CHECK_FREAD_COUNT_EQUALS(
        readBytes, 
        START_BYTES, 
        "Couldn't read all three initial bytes! fread returned %d\n", 
        readBytes
    );

    return memcmp(initialReadBytes, expectedInitialBytes, START_BYTES)==0;
}

char expectedEndBytes[END_BYTES]={0xFF, 0xD9};

long jpegSize(FILE *fp)
{
    long curr_pos = ftell(fp); 

    SEEK_SET_CHECK(fp, 0, "jpegSize-fseek");
    

    //let's look up for the consecutive jpeg end bytes, FF-D9
    while (!feof(fp)){

        if (match(0, fp) && match(1, fp)){
            
            long retVal = ftell(fp);

            printf(
            "File length is %.3lfKiB | %.3lfKB\n", 
            retVal/(float)1024, retVal/(float)1000
            );

            SEEK_SET_CHECK(fp, curr_pos, "jpegSize-fseek");

            return retVal;
        }
    }

    printf("Couldn't find end bytes FFD9\n");

    return -1;
}

int match(int index, FILE* fp)
{
    char byte;
    int readBytes = fread(&byte, 1, 1, fp);

    CHECK_FREAD_COUNT_EQUALS(
        readBytes, 
        1, 
        "Couldn't read byte! fread returned %d\n", 
        readBytes
    );

    return byte == expectedEndBytes[index];
}