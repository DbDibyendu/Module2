/** @file problem4.c
 *  @brief 
 *  
 *  Opening a file db.txt and searching the word iotiot in it
 *   
 *  @author Dibyendu Biswas 
 *  @bug I didn't find a bug from my side
 */

/*
 *#####################################################################
 *  Initialization block
 *  ---------------------
 *  This block contains initialization code for this particular file.
 *  It typically contains Includes, constants or global variables used
 *  throughout the file.
 *#####################################################################
 */

/* --- Standard Includes --- */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

/* --- Project Includes --- */


/*
 *#####################################################################
 *  Process block
 *  -------------
 *  Solve all your problems here 
 *#####################################################################
 */
 
 
/**************************
 * Error-handling functions
 **************************/
/* $begin errorfuns */
/* $begin unixerror */
void unix_error(char *msg) /* unix-style error */
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(0);
}
/* $end unixerror */

void posix_error(int code, char *msg) /* posix-style error */
{
    fprintf(stderr, "%s: %s\n", msg, strerror(code));
    exit(0);
}

void app_error(char *msg) /* application error */
{
    fprintf(stderr, "%s\n", msg);
    exit(0);
}
/* $end errorfuns */

FILE *Fopen(const char *filename, const char *mode)
{
   FILE *fp;

   if ((fp = fopen(filename, mode)) == NULL)
   unix_error((char*)"Fopen error");

   return fp;
}

char *Fgets(char *ptr, int n, FILE *stream)
{
   char *rptr;

   if (((rptr = fgets(ptr, n, stream)) == NULL) && ferror(stream))
   app_error((char*)"Fgets error");

   return rptr;
}


/**
 * @brief      Search the given string in the file
 *
 * @param      fname  The file name
 * @param      str    The string to search
 *
 * @return     Returns -1 on Error and 0 on not found and 1 on SUCCESS
 */
int searchInFile(char *fname, char *str) {
    FILE *fp;
    int line_num = 1;
    int find_result = 0;
    char temp[512];
    

    if((fp = fopen(fname, "r")) == NULL) {
        printf("Error: Opening the file.\n");
      return(-1);
    }

    while(Fgets(temp, 512, fp) != NULL) {
        if((strstr(temp, str)) != NULL) {
            printf("A match found on line: %d\n", line_num);
            printf("\n%s\n", temp);
            find_result++;
            fclose(fp);             // closing the file and returning 1
            return (1);
        }
        line_num++;
   
    }

    if(find_result == 0) {
        printf("\nSorry, couldn't find a match.\n");
        fclose(fp);                    // closing the file 
        return 0;             
    }
    
    //Close the file if still open and free the memory
    if(fp) {
        fclose(fp);
        free(fp);
    }
              
    return(0);

}

int main (void)
{
     

        /*Make sure you comment every line */
        searchInFile("db.txt", "iotiot");
        return 0;
        
}
