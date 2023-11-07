/*
 * imgDetect.h, imgDetect.c
 * 
 * Description: Small C header to check for a file to be JPEG/JPG.
 *
 * Copyright (c) 2023 Santiago Ezequiel Hamamura
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef IMG_DETECT
#define IMG_DETECT

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define START_BYTES 3

extern char expectedInitialBytes[START_BYTES];

#define END_BYTES 2

extern char expectedEndBytes[END_BYTES];

#define SEEK_SET_CHECK(fp, pos, msg) do { \
    if (fseek((fp), (pos), SEEK_SET)) { \
        perror((msg)); \
        return -1; \
    } \
}while (0)

#define CHECK_FREAD_COUNT_EQUALS(val1, val2, error_msg, num) do {\
    if ((val1)!=(val2)) { \
        printf((error_msg), (num)); \
        return -1; \
    } \
}while(0)

int match(int index, FILE* fp);   //will fread next byte and compare it with expectedInitialBytes[index]

//checks for file to be a jpeg/jpg
int isJpeg(FILE*fp);

//returns byte length of jpeg file up to FFD9
long jpegSize(FILE *fp);

#endif