/** @file problem2.c
 *  @brief Give a description of the file 
 *  
 *  Parses the Json file and Configures the Ethernet and Wlan settings and 
 *  Renames the hostname and sets the timezone
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
#include<errno.h>

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



/** 
 *  @brief Description on function_1
 *  
 *  Parses the Json file and configure the system change the hostname timzone, and settings for wifi and ethernet
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
         * and assign the document "wireles" "status" value to wStatus
         */
        Value& wStatus = d["wireless"]["status"];

        /* Print the string value */
        std::cout << "Wireless Status = " << wStatus.GetString() << std::endl;

        /* Modify the string value */
        wStatus.SetString("on");

         
        /* Declare an object to store the value 
         * and assign the document "hostname" value to Host
         */
        Value& Host = d["hostname"];

        /* Print the string value */
        std::cout << "Hostname = " << Host.GetString() << std::endl;
        
        char host[100]=" sudo hostnamectl set-hostname ";                     // creating char for system command
        strcat(host,Host.GetString());                  // adding hostname for system command line to the previous command

         /* Declare an object to store the value 
         * and assign the document "hostname" value to Host
         */
        Value& Time = d["timezone"];

        /* Print the string value */
        std::cout << "Timezone = " << Time.GetString() << std::endl;

        char time[100]="sudo timedatectl set-timezone ";    // creating char for changing time system command
        strcat(time,Time.GetString());                          // adding giben timezone to the command line char


        /* System commands Here
        *
        */
        system(host);                           // system command for setting new hostname
        system(time);                           // System command for setting new timezone
        //
        // System commands Ends here


        /* Configering Wifi
        *
        */
        Value& User= d["wireless"]["ssid"];                      // Reading the ssid from wireless

        /* Print the string value */
        std::cout << "SSID = " << User.GetString() << std::endl;        //printing the ssid

        Value& Pass= d["wireless"]["password"];                      // Reading the password from wireless

        /* Print the string value */
        std::cout << "password = " << Pass.GetString() << std::endl;        //printing the ssid
        
        char username[100],password[100];                             // creating strings for username and password
        // copying the strings into the new strings made above
        strcpy(username,User.GetString());                              
        strcpy(password,Pass.GetString());

        FILE* f1;                               // declaring file pointer

           // checking whether the file is open or not
        if ((fp = fopen("/etc/wpa_supplicant/wpa_supplicant.conf", "w")) == NULL){
             unix_error((char*)"Fopen error");
             return 0; 
        }   
        // else rewrite the folder 
        else{
        f1=fopen("/etc/wpa_supplicant/wpa_supplicant.conf", "w");                                 // opeining the wifi configeration file
        fprintf(f1,"network{ \n     ssid=\"%s\" \n     psk=\"%s\" \n} ",username,password);                  //adding the required setups
        fclose(f1); 
        }                                                                                        // closing the file


        /* Ethernet configeration
        *
        */
        Value& Interface= d["ethernet"][0]["device"];                      // Reading the device type from ethernet

        /* Print the string value */
        std::cout << "Interface = " << Interface.GetString() << std::endl;      

        Value& Ip= d["ethernet"][0]["ipAddress"];                      // Reading the IpAddess from ethernet

        /* Print the string value */
        std::cout << "IpAddress = " << Ip.GetString() << std::endl;  

        Value& Mask= d["ethernet"][0]["subnetMask"];                      // Reading the mask from ethernet

        /* Print the string value */
        std::cout << "Mask = " << Mask.GetString() << std::endl;  

        Value& Gateway= d["ethernet"][0]["routerAddress"];                      // Reading the gateway from ethernet

        /* Print the string value */
        std::cout << "Gateway = " << Gateway.GetString() << std::endl;      

        char interface[100];                            // creating strings for interface
        char ip[100];                             // creating strings for ipAddess
        char mask[100];                                 // creating strings for mask
        char gateway[100];                          // creating strings for gateway

        // Copying all the d document strings into new strings 

        strcpy(interface,Interface.GetString());
        strcpy(ip,Ip.GetString());
        strcpy(mask,Mask.GetString());
        strcpy(gateway,Gateway.GetString());


        FILE *f2;                                                               // declaring file pointer
          // checking whether the file is open or not
        if ((fp = fopen("/etc/dhcpcd.conf", "w")) == NULL){
             unix_error((char*)"Fopen error");
             return 0; 
        }   

        // else rewrite the folder
        else{
        f2=fopen("/etc/dhcpcd.conf","w");                                // opening the dhcpd.conf file for configeration
        fprintf(f2,"interface %s\n static ip_address=%s\n static netmask=%s\n static gateway=%s",interface,ip,mask,gateway);  // printing all the values in required format
        fclose(f2);
        }                                                                             //closing the file

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
        parse();                    // calling the parse function
        system("reboot");           // rebooting the system for changes to take place
        return 0;

}



