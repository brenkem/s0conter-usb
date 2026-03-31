# S0 Conter via USB (s0counter-usb)
This simply RP2040 board delivers multiple counters of S0 interfaces.


# hardware
waveshare RP2040-Zero
https://www.waveshare.com/rp2040-zero.htm


# build firmware
## prepare for build
    mkdir build
    cd build
    export PICO_SDK_PATH="../../pico-sdk"
    cmake ..
## build/rebuild
    make

# read out status
## config to cache response
    cat /dev/ttyACM0
## trigger via request
    echo "g" > /dev/ttyACM0


# used pinout
    PIN_S0_1 = 2; // PCB Pin 4
    PIN_S0_2 = 6; // PCB Pin 9
    PIN_S0_3 = 9; // PCB Pin 12
