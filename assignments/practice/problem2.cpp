/** @file problem2.c
 *  @brief Give a description of the file 
 *  
 *  Parses the Json file
 *  
 *  @author Dibyendu Biswas
 *  @bug I didn't find any
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

/* Standard Includes */
#include <cstdio>
#include <iostream>

/* RapidJSON Includes */
#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include "include/rapidjson/filereadstream.h"
#include "include/rapidjson/filewritestream.h"
#include "include/rapidjson/prettywriter.h"

using namespace rapidjson;
using namespace std;

/*
 *#####################################################################
 *  Process block
 *  -------------
 *  Solve all your problems here 
 *#####################################################################
 */

/** 
 *  @brief Description on function_1
 *  
 *  Full description of the function
 *
 *  @return List all Function returns 
 */

 int parse()
{
    /* Open the example.json file in read mode */
        FILE* fp = fopen("example.json", "rb"); 

        /* Declare read buffer */
        char readBuffer[65536];

        /* Declare stream for reading the example stream */
        FileReadStream is(fp, readBuffer, sizeof(readBuffer));

        /* Declare a JSON document. JSON document parsed will be stored in this variable */
        Document d;

        /* Parse example.json and store it in `d` */
        d.ParseStream(is);

        /* Close the example.json file*/
        fclose(fp);

        /* Declare an object to store the value 
         * and assign the document "ethernet" "status" value to eStatus
         */
        Value& wStatus = d["wireless"]["status"];

        /* Print the string value */
        std::cout << "Wireless Status = " << wStatus.GetString() << std::endl;

        /* Modify the string value */
        wStatus.SetString("off");

        

        /* Declare write buffer */ 
        char writeBuffer[65536];

        /* Declare stream for writing the output stream */
        FileWriteStream os(stdout, writeBuffer, sizeof(writeBuffer));

        /* Make the output easier to read for Humans (Pretty) */
        PrettyWriter<FileWriteStream> writer(os);

        /* Write the JSON document `d` into the file `output.json`*/
        d.Accept(writer);
}


/** 
 *  @brief Description on main
 *  
 * Parses the json file given in example.json and prints the status of ethernet and wireless
 *  
 *
 *  
 */
int main() 
{
        parse();

        FILE* f1 = fopen("/etc/wpa_supplicant/wpa_supplicant.conf", "rb"); 
        FILE* f2 = fopen("/etc/localtime","rb");
        char temp[100];
        while((fgets(temp,100,f1)!=NULL)){
            printf("%s",temp);
         }
          while((fgets(temp,100,f2)!=NULL)){
            printf("%s",temp);
         }


        return 0;

}



