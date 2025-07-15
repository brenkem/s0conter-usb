# BoiTus (BOIlerstaTUS)
This simply RP2040 board delivers the status of the ANEWAND boiler via a single
GPIO pin linked to the operation hour meter.


# hardware
waveshare RP2040-Zero
https://www.waveshare.com/rp2040-zero.htm


# build firmware
## prepare for build
    mkdir build
    cd build
    cmake ..
## build/rebuild
    make

# read out status
## config to cache response
    cat /dev/ttyACM0
## trigger via request
    echo "g" > /dev/ttyACM0


# used pinout
    X1 = 13;
