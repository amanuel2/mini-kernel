#include "usb.h"

extern void die(const char *message);

int disconect_usb(struct usb_driver* usb)
{
    free(usb);
}

struct usb_driver* createUsbDriver(const char* name, const unsigned char*hex,
                                    const unsigned char *bin,const char* led)
{
    if(led != "red" && led != "green", led != "blue")
        die("Unkown Or Unsported LED_COLOR");
    struct usb_driver_info *ui;
    enum USB_DRIVER_LED *ul;
    struct usb_driver* ud = malloc(sizeof(struct usb_driver));
    ui->hex = hex;
    ui->bin = bin;
    if(led == "red")
         ul = RED;
    else if(led == "blue")  
         ul = BLUE;
    else if(led == "green")
         ul = GREEN;
    else    
         ul = NULL_DR;
    ui->led = ul;     
    ud->name = name;
    ud->info = ui;
}