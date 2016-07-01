C = gcc
C_FLAGS = -std=c99 -o my_kernel -w -lm
obj = my_kernel
drivers_folder = kernel/drivers

all:
	$(C) main.c util/errors/errors.c $(drivers_folder)/network/network.c $(drivers_folder)/drivers.c  $(C_FLAGS)
compile:
	./$(obj)
