# 7 Segment Display

### Description
For this project you will create a C module to control a 7 segment display and
an application that uses the module to count from 0 to 9 on that display.


### Getting Started
Instructions for setting up Teensy/AVR software: https://docs.google.com/document/d/14hde-FlAY3FuboliV8YoHGabpAtk_yKehl3FWuhFWz4/

Before you begin, run the following command in the main folder of your project `7_segment_display`:

```
git submodule update --init
```

[7 Segment Display Datasheet]
(https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=1&cad=rja&uact=8&ved=0ahUKEwjF2oKFj4_LAhXElYMKHbXiBTQQFggqMAA&url=http%3A%2F%2Fcal-eng.com%2F_support%2Fdatasheets%2FLiteON_(LTD-6410G).pdf&usg=AFQjCNF7AcWebgHL70nlOMK6ikmZIfNtuw)

### Instructions
Start by taking a look at the files in the `src` directory. These are the source files of your project - the files that compose your unique program. The other directory, `lib`, contains included libraries; code that you can access from within your program. The `Makefile` in the top project directory contains instructions for the `make` program used to compile your program. The `.gitignore` and `.gitmodules` files are settings for git source control and not related to the program. You should not edit anything but files in the `src` directory.

The `main.c` file contains the "main loop" of your program. The implementation of a main loop is a conditional loop, such as a `for` or `while` loop that is always `true` and will run forever. Within this loop, you want to measure time and increment the number on the 7-segment display. You should call functions from your `seven_segment_display.c` file to control the display.

The `seven_segment_display.c` file contains functions for the 7-segment-display. It is a module file - providing the "API" for the display hardware. The module acts as a state machine: use the `SSD_SetDisplay` function to update the module settings, and then call the `SSD_Tick` function to update the state.

Be sure to fill out the enum in `seven_segment_display.h`, which should be useful for using the `seven_segment_display.c` file.

Start with the `seven_segment_display.c` and `seven_segment_display.h` files and then use them to write your `main.c` file. The end goal should be a program that controls the LEDs in the seven segment display, to display 0 through 9, counting upwards each second or whichever time interval you choose.





