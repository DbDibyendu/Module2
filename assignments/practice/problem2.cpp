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

 int write()
{

	/* Declare an object to store the JSON document in  */
        Document d;

        /* Declare the First JSON object */
        d.SetObject();

        /* Declare new JSON object called as wireless */
        Value wireless(kObjectType);

        /* Lets store the JSON object members for wireless */
        wireless.AddMember("device","wlan0",d.GetAllocator());
        wireless.AddMember("status", "on", d.GetAllocator());
        wireless.AddMember("ssid", "Hegde-Jio", d.GetAllocator());
        wireless.AddMember("password", "secretpassword", d.GetAllocator());

        /* Add this object as a member to the JSON  document `d`*/
        d.AddMember("wireless", wireless, d.GetAllocator());

        Value eth0(kObjectType);

        /* Lets store the JSON object members for wireless */
        eth0.AddMember("device", "eth0", d.GetAllocator());
        eth0.AddMember("status", "on", d.GetAllocator());
        eth0.AddMember("allocation", "static", d.GetAllocator());
        eth0.AddMember("ipAddress", "192.168.0.100", d.GetAllocator());
        eth0.AddMember("subnetMask", "255.255.255.0", d.GetAllocator());
        eth0.AddMember("routerAddress", "192.168.0.1", d.GetAllocator());

        /* Add this object as a member to the JSON  document `d`*/
        d.AddMember("eth0", eth0, d.GetAllocator());


        Value eth1(kObjectType);

        /* Lets store the JSON object members for wireless */
        eth1.AddMember("device", "eth1", d.GetAllocator());
        eth1.AddMember("status", "on", d.GetAllocator());
        eth1.AddMember("allocation", "static", d.GetAllocator());
        eth1.AddMember("ipAddress", "null", d.GetAllocator());
        eth1.AddMember("subnetMask", "null", d.GetAllocator());
        eth1.AddMember("routerAddress", "null", d.GetAllocator());

        /* Add this object as a member to the JSON  document `d`*/
        d.AddMember("eth1", eth1, d.GetAllocator());

            /* Declare the ethernet JSON array object*/
        Value ethernet(kArrayType);

        /* Add eth0 and eth1 Entries to the ethernet JSON array object*/
        ethernet.PushBack(eth0, d.GetAllocator());
        ethernet.PushBack(eth1, d.GetAllocator());

        /* Add ethernet JSON array object to the document `d`*/
        d.AddMember("ethernet", ethernet, d.GetAllocator());



        /* Open the output.json file in write mode */
        FILE *out = fopen("output.json", "wb");

        /* Declare write buffer */ 
        char writeBuffer[65536];

        /* Declare stream for writing the output stream */
        FileWriteStream os(out, writeBuffer, sizeof(writeBuffer));

        /* Make the output easier to read for Humans (Pretty) */
        PrettyWriter<FileWriteStream> writer(os);

        /* Write the JSON document `d` into the file `output.json`*/
        d.Accept(writer);

        /* Close the output.json file*/
        fclose(out);
        /* Print Done */
        std::cout << "\n Done!, check the output.json file. \n"<< std::endl;

        return 0;
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

        Value& eStatus = d["ethernet"]["status"];

        /* Print the string value */
        std::cout << "Ethernet Status = " << eStatus.GetString() << std::endl;

        /* Modify the string value */
        eStatus.SetString("off");

        Value& wStatus = d["wireless"]["status"];

        /* Print the string value */
        std::cout << "Wireless Status = " << wStatus.GetString() << std::endl;

        /* Modify the string value */
        wStatus.SetString("off");

       
        write();

        return 0;
        
}


