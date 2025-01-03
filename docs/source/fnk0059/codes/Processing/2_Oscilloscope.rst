##############################################################################
Chapter Oscilloscope
##############################################################################

We have implemented a simple virtual instrument voltmeter, before. In this chapter, we will make a more complex virtual instrument, oscilloscope. Oscilloscope is a widely used electronic measuring instrument. It can get the electrical signals not directly observed into visible image to facilitate the analysis and study of various electrical signals change process.

Project 2.1 Oscilloscope
************************************

Now, let's use Processing and control board to achieve an oscilloscope.

Component list
======================================

+-------------------------+----------------+
| Control board x1        | USB cable x1   |
|                         |                |
| |Chapter01_00|          | |Chapter01_01| |
+-------------------------+----------------+
| Freenove Projects Board                  |
|                                          |
| |Chapter01_02|                           |
+------------------------------------------+

.. |Chapter01_00| image:: ../_static/imgs/1_LED_Blink/Chapter01_00.png
.. |Chapter01_01| image:: ../_static/imgs/1_LED_Blink/Chapter01_01.png
.. |Chapter01_02| image:: ../_static/imgs/1_LED_Blink/Chapter01_02.png

Circuit
=============================

Use pin A1 on the control board to detect the voltage of rotary potentiometer.

+-------------------------+-----------------------------------------------------------+
| Schematic diagram       | Hardware connection                                       |
|                         |                                                           |
| |Chapter02_00|          | |Chapter02_01|                                            |
+-------------------------+-----------------------------------------------------------+
| Hardware connection                                                                 |
|                                                                                     |
| Insert the Control Board to Freenove Projects Board, and then turn the corresponding|
|                                                                                     |
| switch to the right(ON).                                                            |
|                                                                                     |
| |Chapter02_02|                                                                      |
+-------------------------------------------------------------------------------------+

.. |Chapter02_00| image:: ../_static/imgs/2_Oscilloscope/Chapter02_00.png
.. |Chapter02_01| image:: ../_static/imgs/2_Oscilloscope/Chapter02_01.png
.. |Chapter02_02| image:: ../_static/imgs/2_Oscilloscope/Chapter02_02.png

Sketch
===================================

Sketch Oscilloscope
-------------------------------------

Use Processing to open Oscilloscope.pde and click Run. If the connection succeeds, the follow will be shown:

.. image:: ../_static/imgs/2_Oscilloscope/Chapter02_03.png
    :align: center

The green line is the waveform acquisited. Rotate the potentiometer, then you can see changes of the waveform:

.. image:: ../_static/imgs/2_Oscilloscope/Chapter02_04.png
    :align: center

Disconnect the A1 port from the potentiometer and connect it to the Pin 13 port. Pin 13 port output is 0.5Hz square wave. As is shown below:

.. image:: ../_static/imgs/2_Oscilloscope/Chapter02_05.png
    :align: center

The left side of the software interface is a voltage scale, which is used to indicate the voltage of the waveform.

The "1000ms" on top left corner is the time of a square, and you can press “↑” and “↓” key on keyboard to adjust it.

The "0.00V" on top right corner is the voltage value of current signal.

You can press the space bar on keyboard to pause the display waveform, which is easy to view and analysis.

We believe that with the help of this oscilloscope, you can obtain more intuitive understanding of the actual work of some electronic circuits. It will help you complete the project and eliminate the trouble. You can export this sketch to an application used as a tool.
