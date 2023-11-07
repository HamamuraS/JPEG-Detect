# JPEG-Detect
Small C header to check for a file to be JPEG/JPG.  

imgDetect.h is intended to contain functions related to JPEG/JPG manipulation

`int isJpeg (FILE\*fp);`   
Given an opened binary file, read mode, fp, returns 1 if it's recognized as JPEG/JPG, 0 if not. -1 if an error was produced.  

`long jpegSize(FILE *fp);`  
Given an open binary file, read mode fp, returns it's size in bytes. -1 if an error was produced.
