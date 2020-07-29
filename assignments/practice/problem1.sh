## @file problemq.sh
 #  @brief 
 #  
 #  sh file to connect to bluetooth device
 #  
 #  @author Dibyendu 
 #  @bug I didn't find any bugs from my side   
 #

#
 ######################################################################
 #  Initialization block
 #  ---------------------
 #  This block contains initialization code for this particular file.
 #  It typically contains Includes, constants or global variables used
 #  throughout the file.
 ######################################################################
 #

#!/bin/bash

#
 ######################################################################
 #  Process block
 #  -------------
 #  Solve all your problems here 
 ######################################################################
 #

## 
 #  @brief Description on function_1
 #  
 #  Full description of the function
 #  sh file to connect to bluetooth device in Linux
 #
 # starts bluetooth if not started
systemctl start bluetooth
#open bluetoothctl
bluetoothctl
# register agent
agent on
# scan devices
scan on
# then just pair to the device u want to pair with



#
 ######################################################################
 #  Main callback
 #  -------------
 #  All your function callbacks and shell commands go below
 ######################################################################
 #

# Make sure you comment every line #