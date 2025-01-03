##############################################################################
Chapter LED Blink
##############################################################################

Earlier we tried to make the LED marked "L" blink. Now let us use Freenove Projects Board to reproduce this phenomenon and try to understand its principle.

Project 1.1 LED Blink
****************************

Component List
============================

.. note::
    
    The control board you received may be black or blue. They are the same in use. Only the black control board is used to display the hardware connection in this document.

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

Component Knowledge
============================

Let us learn about the basic features of components to use them better.

Analog signal and Digital signal
------------------------------------

An Analog Signal is a continuous signal in both time and value. On the contrary, a Digital Signal or discrete-time signal is a time series consisting of a sequence of quantities. Most signals in life are analog signals. A familiar example of an Analog Signal would be how the temperature throughout the day is continuously changing and could not suddenly change instantaneously from 0℃ to 10℃. 

However, Digital Signals can instantaneously change in value. This change is expressed in numbers as 1 and 0 (the basis of binary code). Their differences can more easily be seen when compared when graphed as below.

.. image:: ../_static/imgs/1_LED_Blink/Chapter01_03.png
    :align: center 

In practical applications, we often use binary as the digital signal, that is a series of 0's and 1's. Since a binary signal only has two values (0 or 1) it has great stability and reliability. Lastly, both analog and digital signals can be converted into the other.

Low level and high level
------------------------------------

In a circuit, the form of binary (0 and 1) is presented as low level and high level.

Low level is generally equal to ground voltage(0V), while high level is to the operating voltage of components.

The low level of the control board is 0V and high level is 5V, as shown below. When IO port on control board outputs high level, components of small power can be directly lit, like LED.

.. image:: ../_static/imgs/1_LED_Blink/Chapter01_04.png
    :align: center 

LED
------------------------------------

An LED is a type of diode. All diodes only work if current is flowing in the correct direction and have two Poles. An LED will only work (light up) when its longer pin (+) is connected to the positive output from a power source and the shorter pin is connected to the negative (-), negative output also referred to as Ground (GND). This type of component is known as "Polar" (think One-Way Street).

All common 2-lead diodes are the same in this respect. Diodes work only if the voltage of its positive electrode is higher than its negative electrode and there is a narrow range of operating voltage for most common diodes of 1.9 and 3.4V. If you use much more than 3.3V the LED will be damaged and burn out.

.. image:: ../_static/imgs/1_LED_Blink/Chapter01_05.png
    :align: center 

.. note::
    
    LEDs cannot be directly connected to a power supply, which usually ends in a damaged component. A resistor with a specified resistance value must be connected in series to the LED you plan to use.

Current
------------------------------------

The unit of current(I) is ampere(A). 1A=1000mA, 1mA=1000μA.

Closed loop consisting of electronic components is necessary for current to flow.

In the figures below: the left one is a loop circuit, so current flows through the circuit. The right one is not a loop circuit, so there is no current.

.. image:: ../_static/imgs/1_LED_Blink/Chapter01_06.png
    :align: center 

Resistor
------------------------------------

Resistors use Ohms (Ω) as the unit of measurement of their resistance (R). 1MΩ=1000kΩ, 1kΩ=1000Ω.

A resistor is a passive electrical component that limits or regulates the flow of current in an electronic circuit.

On the left, we see a physical representation of a resistor, and on the right is the symbol used to represent the presence of a resistor in a circuit diagram or schematic.

.. image:: ../_static/imgs/1_LED_Blink/Chapter01_07.png
    :align: center 

The bands of color on a resistor is a shorthand code used to identify its resistance value. For more details of resistor color codes, please refer to the card in the kit package.

With a fixed voltage, there will be less current output with greater resistance added to the circuit. The relationship between Current, Voltage and Resistance can be expressed by this formula: I=V/R known as Ohm’s Law where I = Current, V = Voltage and R = Resistance. Knowing the values of any two of these allows you to solve the value of the third.

In the following diagram, the current through R1 is: I=U/R=5V/10kΩ=0.0005A=0.5mA.

.. image:: ../_static/imgs/1_LED_Blink/Chapter01_08.png
    :align: center 

.. warning::
    
    Never connect the two poles of a power supply with anything of low resistance value (i.e. a metal object or bare wire) this is a Short and results in high current that may damage the power supply and electronic components.

Code Knowledge
==========================

Before start writing code, we should learn about the basic programming knowledge.

Comments
----------------------

Comments are the words used to explain for the sketches, and they won't affect the running of code.

There are two ways to use comments of sketches.

1. Symbol "//"

Contents behind ”//” comment out the code in a single line.

.. code-block:: c
    
    // this is a comment area in this line.

The content in front of "//" will not be affected.

.. code-block:: c
    
    delay(1000);              // wait for a second

1. Symbol "/*"and "*/"

Code can also be commented out by the contents starting with a “/*” and finishing with a “*/” and you can place it anywhere in your code, on the same line or several lines.

.. code-block:: c
    
    /* this is comment area. */

Or

.. code-block:: c
    
    /* 
        this is a comment line. 
        this is a comment line. 
    */

Data type
----------------------

When programming, we often use digital, characters and other data. C language has several basic data types as follows: 

int: A number that does not have a fractional part, an integer, such as 0, 12, -1;

float: A number that has a fractional part, such as 0.1, -1.2;

char: It means character, such as 'a', '@', '0';

For more about date types, please visit the website: https://www.Arduino.cc-Resources-Reference-Data Types.

Constant
---------------------------

A constant is a kind of data that cannot be changed, such as int type 0, 1, float type 0.1, -0.1, char type 'a', 'B'.

Variable
A variable is a kind of data that can be changed. It consists of a name, a value, and a type. Variables need to be defined before using, such as:

.. code-block:: c
    
    int i;

"int" indicates the type, ";" indicates the end of the statement. The statement is usually written in one single line; and these statements form the code.
After declaration of the variable, you can use it. The following is an assignment to a variable:

.. code-block:: c
    
    i = 0;                    // after the execution, the value of i is 0

"=" is used to pass the value of a variable or constant on the right side to the variable on the left.
A certain number of variables can be declared in one statement, and a variable can be assigned multiple times. Also, the value of a variable can be passed to other variables. For example:

.. code-block:: c
    
    int i, j;
    i = 0;                    // after the execution, the value of i is 0
    i = 1;                    // after the execution, the value of i is 1
    j = i;                    // after the execution, the value of j is 1

Function
----------------------------

A function is a collection of statements with a sequence of order, which performs a defined task. Let's define a function void blink() as follows:

.. code-block:: c
    
    void blink() {
        digitalWrite(13, HIGH);
        delay(1000);
        digitalWrite(13, LOW);
        delay(1000);
    }

"void" indicates that the function does not return a value (Chapter 4 will detail the return value of functions); 

"()" its inside is parameters of a function (Chapter 2 will detail the parameters of the functions). No content inside it indicates that this function has no parameters;

"{}" contains the entire code of the function.

After the function is defined, it is necessary to be called before it is executed. Let's call the function void blink(), as shown below.

.. code-block:: c
    
    blink();

When the code is executed to a statement calling the function, the function will be executed. After execution of the function is finished, it will go back to the statement and execute the next statement.

.. image:: ../_static/imgs/1_LED_Blink/Chapter01_09.png
    :align: center 

Some functions have one or more parameters. When you call such functions, you need to write parameters inside "()":

.. code-block:: c
    
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);              // wait for a second

Circuit
================================

Now, we will use IO port of control board to provide power for the LED. Pin 13 of the control board is the digital pin. It can output high level or low level. In this way, control board can control the state of LED.

.. list-table:: 
    :width: 80%
    :align: center
    :class: product-table

    *   -   Schematic diagram
    *   -   |Chapter01_10|
    *   -   Hardware connection

            Insert the Control Board upside down to the Freenove Projects Board, and then turn the corresponding 
            
            switch to the right (On)

    *   -   |Chapter01_11|

            :red:`For other functions that are not being used, it is recommended to turn their DIP switches to the left.`

.. |Chapter01_10| image:: ../_static/imgs/1_LED_Blink/Chapter01_10.png
.. |Chapter01_11| image:: ../_static/imgs/1_LED_Blink/Chapter01_11.png

Sketch
============================

Blink
----------------------------

In order to make the LED blink, we need to make pin 13 of the control board output high and low level alternately.

We highly recommend you type the code manually instead of copying and pasting, so that you can develop your coding skills and learn more.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_01.1_Blink/Sketch_01.1_Blink.ino
    :linenos: 
    :language: c
    :dedent:

The code usually contains two basic functions: void setup() and void loop(). 

After control board is :orange:`reset`, the setup() function will be executed first, and then the loop() function will be executed.

setup() function is generally used to write code to initialize the hardware. And loop() function is used to write code to achieve certain functions. loop() function is executed repeatedly. When the execution reaches the end of loop(), it will jump to the beginning of loop() to run again.

.. c:function:: Reset

    Reset operation will lead the code to be executed from the beginning. Switching on the power, finishing uploading the code and pressing the reset button will trigger reset operation.

.. image:: ../_static/imgs/1_LED_Blink/Chapter01_12.png
    :align: center

In the setup () function, first, we set pin 13 of the control board as output mode, which can make the port output high level or low level.

.. code-block:: c
    
    // initialize digital pin 13 as an output.
    pinMode(13, OUTPUT);

Then, in the loop () function, set pin 13 of the control board to output high level to make LED light up.

.. code-block:: c
    
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)

Wait for 1000ms, which is 1s. delay() function is used to make control board wait for a moment before executing the next statement. The parameter indicates the number of milliseconds to wait for.
.. code-block:: c
    
    delay(1000);              // wait for a second

Then set the pin 13 to output low level, and LED lights   off. One second later, the execution of loop () function will be completed. 

.. code-block:: c
    
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);              // wait for a second

The loop() function is constantly being executed, so LED will keep blinking.

The functions called above are standard functions of the Arduino IDE, which have been defined in the Arduino IDE, and they can be called directly. We will introduce more common standard functions in later chapters.

For more standard functions and the specific use method, please visit https://www.arduino.cc-Resources-Reference-Functions.

Verify and upload the code, then the LED starts blinking.

.. image:: ../_static/imgs/1_LED_Blink/Chapter01_13.png
    :align: center 