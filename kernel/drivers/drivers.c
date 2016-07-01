#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "network/network.h"
#include "usb/usb.h"
#include "drivers.h"
#define NET_DRIVERS 5
#define USB_DRIVERS 3


NetworkDriver *nd[NET_DRIVERS];
struct usb_driver *ud[USB_DRIVERS];

char *networkDriversNames[NET_DRIVERS] = {
        "Wireless",
        "Ethernet",
        "appletalk",//Apple Talk Printer
        "hyperv", //Virtual Machine Network Adapter ,
        "ppp", //Point-to-Point Protocol. 
        //Can be used to transfer IP traffic from point to point.
};

char *usbDriversNames[USB_DRIVERS] = {
       "atm", // Brand
       "image",
       "host"
};

char *usbDriver_LED[USB_DRIVERS] = {
    "Red",
    "Green",
    "Blue"
};

unsigned char *usbDriverHEX[USB_DRIVERS] = {
    "0x00",
    "0x01",
    "0x05"
};
unsigned char *usbDriverBIN[USB_DRIVERS] = {
    "000",
    "001",
    "005"
};


void initalizeDrivers()
{
    initalize_net_drivers();
    initalize_usb_drivers();
}

void destroyDrivers()
{
   destroy_net_drivers();
   destroy_usb_drivers();
}


void initalize_net_drivers()
{
     for(int i=0; i<NET_DRIVERS; i++)
        nd[i] = createNetworkDriver(networkDriversNames[i]);
}

void initalize_usb_drivers()
{
    for(int i=0; i<USB_DRIVERS; i++)
      ud[i] = createUsbDriver(usbDriversNames[i],
                            usbDriverHEX[i],
                            usbDriverBIN[i],
                            usbDriver_LED[i]);    
}

void destroy_usb_drivers(){
     for(int i=0; i<NET_DRIVERS; i++)
     {
        if(disconect_usb(ud[i])==true)
            printf("Sucessfully Destroyed %s USB Driver\n", usbDriversNames[i]);
        else
            printf("Unsucessfull Destruciton in %s Usb Driver\n", usbDriversNames[i]);
     }
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