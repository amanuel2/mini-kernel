C = gcc
C_FLAGS = -std=c99 -o my_kernel -w -lm
obj = my_kernel
drivers_folder = kernel/drivers
util_folder = util
C_Files_Obj = $(util_folder)/errors/errors.c $(drivers_folder)/network/network.c $(drivers_folder)/usb/usb.c $(drivers_folder)/drivers.c

all:
	$(C) main.c $(C_Files_Obj) $(C_FLAGS)
compile:
	./$(obj)
