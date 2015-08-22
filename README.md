# gpioLEDS
Makes a LED blink on and off from a Raspberry Pi 1

INSTRUCTIONS:

Load your Rasperry Pi and make sure to install WiringPi:

sudo apt-get update
sudo apt-get upgrade
sudo apt-get install git-core
git clone git://git.drogon.net/wiringPi
cd wiringPi
./build

Then, clone this repo to your Raspberry Pi, and then connect this circuit to the GPIO:

https://dl.dropboxusercontent.com/u/22713174/circuit.png

And finally, compile the C script with the following gcc call:

gcc -o gpioLEDS.c -lwiringpi

The LED should flash intermittently!

beerware license

