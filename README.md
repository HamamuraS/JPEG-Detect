# JPEG-Detect
Small C header to check for a file to be JPEG/JPG.  

imgDetect.h is intended to contain functions related to JPEG/JPG manipulation

`int isJpeg (FILE\*fp);`   
Given an opened binary file, read mode, fp, returns 1 if it's recognized as JPEG/JPG, 0 if not. -1 if an error was produced.  

`long jpegSize(FILE *fp);`  
Given an open binary file, assumed JPEG, returns bytes number up to FFD9(included). Does not count bytes after FFD9. -1 if an error occurred.     
