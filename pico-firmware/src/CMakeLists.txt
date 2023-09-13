add_executable(serial
        serial.c
        )

# pull in common dependencies
target_link_libraries(serial pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(serial 1)
pico_enable_stdio_uart(serial 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(serial)


add_definitions(-DUSBD_VID=0x0416) # ID_VENDOR_ID
add_definitions(-DUSBD_PID=0x5011) # ID_MODEL_ID 0x5F40
add_definitions(-DUSBD_MANUFACTURER="Nuvoton") # ID_VENDOR
add_definitions(-DUSBD_PRODUCT="USB_Virtual_COM") # ID_MODEL
