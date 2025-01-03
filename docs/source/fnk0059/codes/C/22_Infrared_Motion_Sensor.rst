##############################################################################
Chapter Infrared Motion Sensor
##############################################################################

This Infrared MotionSensor can detect the infrared spectrum (heat signatures) emitted by living humans and animals. Now let us try to use it.

Project 22.1 Infrared Motion Sensor

Now, we'll use the Infrared Motion Sensor to detect human motion.

Component List
============================

+-------------------------+------------------------------+-------------------------------+
| Control board x1        | USB cable x1                 | Infrared Motion Sensor x1     |
|                         |                              |                               |
| |Chapter06_00|          | |Chapter06_01|               | |Chapter22_00|                |
+-------------------------+------------------------------+-------------------------------+
| Jumper Wire x4                                                                         |
|                                                                                        |
| |Chapter06_03|                                                                         |
+----------------------------------------------------------------------------------------+
| Freenove Projects Board                                                                |
|                                                                                        |
| |Chapter06_04|                                                                         |
+----------------------------------------------------------------------------------------+

.. |Chapter06_00| image:: ../_static/imgs/6_RGB_LED/Chapter06_00.png
.. |Chapter06_01| image:: ../_static/imgs/6_RGB_LED/Chapter06_01.png
.. |Chapter22_00| image:: ../_static/imgs/22_Infrared_Motion_Sensor/Chapter22_00.png
.. |Chapter06_03| image:: ../_static/imgs/6_RGB_LED/Chapter06_03.png
.. |Chapter06_04| image:: ../_static/imgs/6_RGB_LED/Chapter06_04.png

Component Knowledge
=============================

Infrared Motion Sensor
------------------------------

Infrared Motion Sensor is an integrated sensor that can detect the infrared spectrum (heat signatures) emitted by living humans and animals. It can detect whether someone is moving within the detecting range by detecting the infrared infrared spectrum (heat signatures) emitted by human body. Here is the HC-SR501 infrared motion sensor and its back:

.. image:: ../_static/imgs/22_Infrared_Motion_Sensor/Chapter22_01.png
    :align: center

Description: 

1.	Working voltage: 5v-20v(DC), static current: 65uA.

2.	Automatic trigger. When a living body enters into the active area of sensor, the module will output high level (3.3V: Though the high level of control board is 5v, 3.3v is identified as high level here). When the body leaves the sensor’s active detection area, it will output high level lasting for time period T, then output low level(0V). Delay time T can be adjusted by the potentiometer R1. 

3.	According to the position of Fresnel lenses dome, you can choose non-repeatable trigger modes or repeatable modes. 

L: non-repeatable trigger mode. The module output high level after sensing a body, then when the delay time is over, the module will output low level. During high level time, the sensor no longer actively senses bodies.  

H: repeatable trigger mode. The distinction from the L mode is that it can sense a body until that body leaves during the period of high level output. After this, it starts to time and output low level after delaying T time.

4.	Induction block time: the induction will stay in block condition and does not induce external signal at lesser time intervals (less than delay time) after outputting high level or low level.

5.	 Initialization time: the module needs about 1 minute to initialize after being powered ON. During this period, it will alternately output high or low level. 

6.	One characteristic of this sensor is when a body moves close to or moves away from the sensor's dome edge, the sensor will work at high sensitively. When a body moves close to or moves away from the sensor’s dome in a vertical direction (perpendicular to the dome), the sensor cannot detect well (please take note of this deficiency). Actually this makes sense when you consider that this sensor is usually placed on a celling as part of a security product. Note: The Sensing Range (distance before a body is detected) is adjusted by the potentiometer.

We can regard this sensor as a simple inductive switch when in use.

Circuit
=================================

Use pin 2 on the control board to connect out-pin of HC-SR501 infrared motion sensor.

+-------------------------+----------------------------------+
| Schematic diagram       | Hardware connection              |
|                         |                                  |
| |Chapter22_02|          | |Chapter22_03|                   |
+-------------------------+----------------------------------+
| Hardware connection                                        |
|                                                            |
| |Chapter22_04|                                             |
+------------------------------------------------------------+
| |Chapter22_05|                                             |
+------------------------------------------------------------+

.. |Chapter22_02| image:: ../_static/imgs/22_Infrared_Motion_Sensor/Chapter22_02.png
.. |Chapter22_03| image:: ../_static/imgs/22_Infrared_Motion_Sensor/Chapter22_03.png
.. |Chapter22_04| image:: ../_static/imgs/22_Infrared_Motion_Sensor/Chapter22_04.png
.. |Chapter22_05| image:: ../_static/imgs/22_Infrared_Motion_Sensor/Chapter22_05.png

Sketch
==================================

Infrared_Motion_Sensor
----------------------------------

Now, write code to get the results measured by the HC-SR501 infrared motion sensor, and display that through LED.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_22.1_Infrared_Motion_Sensor/Sketch_22.1_Infrared_Motion_Sensor.ino
    :linenos: 
    :language: c
    :dedent:

This code is relatively simple. We have obtained the sensor's output signal, and control an LED accordingly.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_22.1_Infrared_Motion_Sensor/Sketch_22.1_Infrared_Motion_Sensor.ino
    :linenos: 
    :language: c
    :dedent:
    :lines: 18-18

Verify and upload the code, put the sensor on a stationary table and wait for about a minute. And then try to get close to or away from the sensor, and observe whether the LED is turned on or turned off automatically.

You can rotate the potentiometer on the sensor to adjust the detection effect, or use different modes by changing jumper.

Apart from that, you can use this sensor to control some other modules to achieve different functions by re-editing the code, such as the induction lamp, induction door.