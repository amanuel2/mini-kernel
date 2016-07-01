#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "network/network.h"
#include "drivers.h"
#define NET_DRIVERS 5


NetworkDriver *nd[NET_DRIVERS];

char *networkDriversNames[] = {
        "Wireless",
        "Ethernet",
        "appletalk",//Apple Talk Printer
        "hyperv", //Virtual Machine Network Adapter ,
        "ppp", //Point-to-Point Protocol. 
        //Can be used to transfer IP traffic from point to point.
};


void initalizeDrivers()
{
    initalize_net_drivers();
}

void destroyDrivers()
{
   destroy_net_drivers(); 
}


void initalize_net_drivers()
{
     for(int i=0; i<NET_DRIVERS; i++)
        nd[i] = createNetworkDriver(networkDriversNames[i]);
}

void destroy_net_drivers()
{
     for(int i=0; i<NET_DRIVERS; i++)
     {
        if(destroyNetworkDriver(nd[i])==true)
            printf("Sucessfully Destroyed %s Network Driver\n", networkDriversNames[i]);
        else
            printf("Unsucessfull Destruciton in %s Network Driver\n", networkDriversNames[i]);
     }
}