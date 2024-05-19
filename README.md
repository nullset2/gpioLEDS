# gpioLEDS
Makes a LED blink on and off from a Raspberry Pi 1

INSTRUCTIONS:

Load your Rasperry Pi and make sure to install WiringPi:

- sudo apt-get update
- sudo apt-get upgrade
- sudo apt-get install git-core
- git clone git://git.drogon.net/wiringPi
- cd wiringPi
- ./build

Then, clone this repo to your Raspberry Pi, and then connect this circuit to the GPIO:

![_WjPskSx](https://github.com/nullset2/gpioLEDS/assets/1520184/a26eb3df-edd3-49ba-ba7b-dfd5f4f2bb25)

And finally, compile the C script with the following gcc call:

gcc -o gpioLEDS.c -lwiringpi

The LED should flash intermittently!

beerware license

