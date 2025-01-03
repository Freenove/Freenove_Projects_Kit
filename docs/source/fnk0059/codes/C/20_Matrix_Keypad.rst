##############################################################################
Chapter Matrix Keypad
##############################################################################

We've already learned and used a push button switch before, now let us try to use a keypad, a device integrated with a number of Push Button Switches as Keys for the purposes of Input.

Project 20.1 Get Input Characters
******************************************

First, try to understand how the keypad works and get the input characters.

Component List
===============================================

+-------------------------+------------------------------+-------------------------------+
| Control board x1        | USB cable x1                 | Keypad x1                     |
|                         |                              |                               |
| |Chapter06_00|          | |Chapter06_01|               | |Chapter20_00|                |
+-------------------------+------------------------------+-------------------------------+
| Freenove Projects Board                                                                |
|                                                                                        |
| |Chapter06_04|                                                                         |
+----------------------------------------------------------------------------------------+

.. |Chapter06_00| image:: ../_static/imgs/6_RGB_LED/Chapter06_00.png
.. |Chapter06_01| image:: ../_static/imgs/6_RGB_LED/Chapter06_01.png
.. |Chapter20_00| image:: ../_static/imgs/20_Matrix_Keypad/Chapter20_00.png
.. |Chapter06_04| image:: ../_static/imgs/6_RGB_LED/Chapter06_04.png

Component Knowledge
================================

4x4 keypad
----------------------------------

A Keypad Matrix is a device that integrates a number of keys in one package. As is shown below, a 4x4 Keypad Matrix integrates 16 keys (think of this as 16 Push Button Switches in one module):

.. image:: ../_static/imgs/20_Matrix_Keypad/Chapter20_01.png
    :align: center

Similar to the integration of an LED Matrix, the 4x4 Keypad Matrix has each row of keys connected with one pin and this is the same for the columns. Such efficient connections reduce the number of processor ports required. The internal circuit of the Keypad Matrix is shown below.

.. image:: ../_static/imgs/20_Matrix_Keypad/Chapter20_02.png
    :align: center

The method of usage is similar to the Matrix LED, by using a row or column scanning method to detect the state of each key’s position by column and row. Take column scanning method as an example, send low level to the first 1 column (Pin1), detect level state of row 5, 6, 7, 8 to judge whether the key A, B, C, D are pressed. Then send low level to column 2, 3, 4 in turn to detect whether other keys are pressed. Therefore, you can get the state of all of the keys.

Circuit
================================

Use pin 9-2 on control board to connect 4x4 keypad.

.. list-table:: 
    :width: 100%
    :align: center
    :class: product-table

    *   -   Schematic diagram
    *   -   |Chapter20_03|
    *   -   Hardware connection
    *   -   |Chapter20_04|
    *   -   |Chapter20_05|

.. |Chapter20_03| image:: ../_static/imgs/20_Matrix_Keypad/Chapter20_03.png
.. |Chapter20_04| image:: ../_static/imgs/20_Matrix_Keypad/Chapter20_04.png
.. |Chapter20_05| image:: ../_static/imgs/20_Matrix_Keypad/Chapter20_05.png

Sketch
====================================

Get_Input_Characters
-------------------------------------

Before writing code, we need to import the library needed.

Click “Add .ZIP Library...” and then find Keypad.zip in libraries folder (this folder is in the folder unzipped form the ZIP file we provided). This library can facilitate our operation of keypad.

Now write the code to obtain the keypad characters, and send them to the serial port.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_20.1_Get_Input_Characters/Sketch_20.1_Get_Input_Characters.ino
    :linenos: 
    :language: c
    :dedent:

In the code, we use a Keypad class provided by the Keypad library to operate the keypad. The following code is to instantiate a keypad object, and the last two parameters represent the number of the row and column of the keypad.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_20.1_Get_Input_Characters/Sketch_20.1_Get_Input_Characters.ino
    :linenos: 
    :language: c
    :dedent:
    :lines: 22-22

The two-dimensional arrays record the keypad characters, and these characters can be returned when you press the keyboard.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_20.1_Get_Input_Characters/Sketch_20.1_Get_Input_Characters.ino
    :linenos: 
    :language: c
    :dedent:
    :lines: 10-16

These two arrays record the row and column's connection pins of keypad.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_20.1_Get_Input_Characters/Sketch_20.1_Get_Input_Characters.ino
    :linenos: 
    :language: c
    :dedent:
    :lines: 18-19

Send the input obtained from the keyboard to the computer via the serial port in function loop().

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_20.1_Get_Input_Characters/Sketch_20.1_Get_Input_Characters.ino
    :linenos: 
    :language: c
    :dedent:
    :lines: 28-35

Verify and upload the code, open the Serial Monitor and press the keypad, and then you will see the characters you press being printed out.

.. image:: ../_static/imgs/20_Matrix_Keypad/Chapter20_06.png
    :align: center