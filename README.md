# Pza Emulator for Tenma-72-2710 power supply

The **main goals** of this emulator are:
- to provide the exact same USB interface that the Tenma-72-2710 power supply.
- to run on a RaspberryPi Pico H to be cheap and easily integrated on a test bench.

> Why not virtual USB interfaces ?

To have a solution independent from OS and their implementation specificities

# Requirements

It does not have many requirements, so you might just clone the repo and run it. install the following package first.

```
sudo apt update
sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi  libstdc++-arm-none-eabi-newlib build-essential
pip install pyserial
```

# Build the pico firmware

the project can be build with the following commmand, the `cmake` may take a couple of minutes.

```
cd pico-firmware
mkdir build 
cd build
cmake ..
make -j8
```

# flash the RaspberryPi Pico

Drag and drop the src/serial.uf2 on the Pico in bootsel mode, or use the following command:

```
cp src/serial.uf2 /media/<user>/RPI-RP2/
```
# Run test

Use the script tenma-control/tenma\_72\_2710 to test the pico firmware, you can use the same script to control the **Tenma-72-2710** power supply.

### Get the Tenma command help
```
tenma-control/tenma_72_2710.py -h
```

### Get the Tenma model info
```
tenma-control/tenma_72_2710.py -v /dev/serial/by-id/usb-Nuvoton_USB_Virtual_COM_E6614C311B888B35-if00
```

### Get the Tenma ON/OFF state
```
tenma-control/tenma_72_2710.py -s /dev/serial/by-id/usb-Nuvoton_USB_Virtual_COM_E6614C311B888B35-if00
```

### Set the Tenma output to ON
```
tenma-control/tenma_72_2710.py --on /dev/serial/by-id/usb-Nuvoton_USB_Virtual_COM_E6614C311B888B35-if00
```

### Set the Tenma output to OFF
```
tenma-control/tenma_72_2710.py --off /dev/serial/by-id/usb-Nuvoton_USB_Virtual_COM_E6614C311B888B35-if00
```

### Set the Tenma Voltage (mV)
```
tenma-control/tenma_72_2710.py -sv 5000 /dev/serial/by-id/usb-Nuvoton_USB_Virtual_COM_E6614C311B888B35-if00
```

### Get the Tenma Voltage (V)
```
tenma-control/tenma_72_2710.py -gv /dev/serial/by-id/usb-Nuvoton_USB_Virtual_COM_E6614C311B888B35-if00
```

### Set the Tenma Current (mA)
```
tenma-control/tenma_72_2710.py -sc 3500 /dev/serial/by-id/usb-Nuvoton_USB_Virtual_COM_E6614C311B888B35-if00
```

### Get the Tenma Current (A)
```
tenma-control/tenma_72_2710.py -gc /dev/serial/by-id/usb-Nuvoton_USB_Virtual_COM_E6614C311B888B35-if00
```



