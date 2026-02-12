# jliang602_Traffic_Light

This program will simulate a signalized crosswalk using an Arduino Mega 2560 microcontroller. The vehicle traffic light will use green, yellow, and red. It stays green and then changes when a pedestrian appraoches the crosswalk and presses the button. The walk sign will appear once the traffic light turns red. After the pedestrian signal cycle is done, the traffic light will change back to green.

The image below shows the flowchart for the main program, the basic structure.

![Main Program Flowchart](./Flowcharts/Flowchart_Main.png)

The delay was self-created using a Arduino Mega 2560 timer. Below is the flowchart for just the timer.

![Timer.c Flowchart](./Flowcharts/Flowchart_Timer.c.png)

Below is the wiring schematic.
