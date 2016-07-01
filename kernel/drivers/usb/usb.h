#ifndef _usb_h_
#define _usb_h_
#pragma onceS

static enum USB_DRIVER_LED
{
    RED,
    GREEN,
    BLUE,
    NULL_DR
};
struct usb_driver_info
{
    unsigned char *hex;
    unsigned char *bin;
    enum USB_DRIVER_LED* led;
};
struct usb_driver
{
    char *name;
    int (*disconect)(struct usb_driver* usb);
    struct usb_driver_info *info;
};

int disconect_usb(struct usb_driver* usb);
struct usb_driver* createUsbDriver(const char* name, const unsigned char*hex,
                                    const unsigned char *bin,const char* led);
extern enum USB_DRIVER_LED* ul;                                  
                                    
#endif