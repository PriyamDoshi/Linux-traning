#!/bin/bash

command=/usr/bin/htop
if [ -f $command ]
then  
    echo " $command is avaible"
else
    echo "installing $command  ...."
    sudo apt update && sudo apt install -y htop
fi

$command    
