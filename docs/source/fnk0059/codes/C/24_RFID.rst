##############################################################################
Chapter RFID
##############################################################################

Now, we will learn to use the RFID (Radio Frequency Identification) wireless communication technology.

Project 24.1 Read UID
*********************************

In this project, we will read the unique ID number (UID) of the RFID card, recognize the type of the RFID card and display the information through serial port.

Component List
============================================

+-------------------------+------------------------------+-------------------------------+
| Control board x1        | USB cable x1                 | RFID-RC522 x1                 |
|                         |                              |                               |
| |Chapter06_00|          | |Chapter06_01|               | |Chapter24_00|                |
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
.. |Chapter24_00| image:: ../_static/imgs/24_RFID/Chapter24_00.png
.. |Chapter06_03| image:: ../_static/imgs/6_RGB_LED/Chapter06_03.png
.. |Chapter06_04| image:: ../_static/imgs/6_RGB_LED/Chapter06_04.png

Circuit knowledge
==============================

RFID
-------------------------------

RFID (Radio Frequency Identification) is a wireless communication technology. A complete RFID system is generally composed of the responder and reader. Generally, we use tags as responders, and each tag has a unique code, which is attached to the object to identify the target object. The reader is a device for reading (or writing) tag information.

Products derived from RFID technology can be divided into three categories: passive RFID products, active RFID products and semi active RFID products. And Passive RFID products are the earliest, the most mature and most widely used products in the market among others. It can be seen everywhere in our daily life such as, the bus card, dining card, bank card, hotel access cards, etc., and all of these belong to close-range contact recognition. The main operating frequency of Passive RFID products are: 125KHZ (low frequency), 13.56MHZ (high frequency), 433MHZ (ultrahigh frequency), 915MHZ (ultrahigh frequency). Active and semi active RFID products work at higher frequencies.

The RFID module we use is a passive RFID product with the operating frequency of 13.56MHz.

Component Knowledge
====================================

MFRC522 RFID Module
-------------------------------------

The MFRC522 is a highly integrated reader/writer IC for contactless communication at 13.56MHz.

The MFRC522's internal transmitter is able to drive a reader/writer antenna designed to communicate with ISO/IEC 14443 A/MIFARE cards and transponders without additional active circuitry. The receiver module provides a robust and efficient implementation for demodulating and decoding signals from ISO/IEC 14443 A/MIFARE compatible cards and transponders. The digital module manages the complete ISO/IEC 14443A framing and error detection (parity and CRC) functionality.

This RFID Module uses MFRC522 as the control chip, and SPI (Peripheral Interface Serial) as the reserved interface.

.. image:: ../_static/imgs/24_RFID/Chapter24_01.png
    :align: center

Mifare1 S50 Card
--------------------------------------

Mifare1 S50 is often called Mifare Standard with the capacity of 1K bytes. And each card has a 4-bytes global unique identifier number (USN/UID), which can be rewritten 100 thousand times and read infinite times. Its storage period can last for 10 years. The ordinary Mifare1 S50 Card and non-standard Mifare1 S50 Card equipped for this kit are shown below.

.. image:: ../_static/imgs/24_RFID/Chapter24_02.png
    :align: center

The Mifare1 S50 capacity (1K byte) is divided into 16 sectors (Sector0-Sector15). Each sector contains 4 data block (Block0-Block3. 64 blocks of 16 sectors will be numbered according absolute address, from 0 to 63). And each block contains 16 bytes (Byte0-Byte15), 64*16=1024. As is shown in the following table:

+------------+-----------+--------------------------------------+---------------+--------------------+
| Sector No. | Block No. | Storage area                         | Block type    | Absolute block No. |
+============+===========+======================================+===============+====================+
|            | block 0   | vendor code                          | vendor block  | 0                  |
|            +-----------+--------------------------------------+---------------+--------------------+
| sector 0   | block 1   |                                      | data block    | 1                  |
|            +-----------+--------------------------------------+---------------+--------------------+
|            | block 2   |                                      | data block    | 2                  |
|            +-----------+--------------------------------------+---------------+--------------------+
|            | block 3   | Password A-access control-password B | control block | 3                  |
+------------+-----------+--------------------------------------+---------------+--------------------+
|            | block 0   |                                      | data block    | 4                  |
|            +-----------+--------------------------------------+---------------+--------------------+
| sector 1   | block 1   |                                      | data block    | 5                  |
|            +-----------+--------------------------------------+---------------+--------------------+
|            | block 2   |                                      | data block    | 6                  |
|            +-----------+--------------------------------------+---------------+--------------------+
|            | block 3   | Password A-access control-password B | control block | 7                  |
+------------+-----------+--------------------------------------+---------------+--------------------+
| ......     | ......    | ......                               | ......        | ......             |
+------------+-----------+--------------------------------------+---------------+--------------------+
|            | block 0   |                                      | data block    | 60                 |
|            +-----------+--------------------------------------+---------------+--------------------+
| sector 0   | block 1   |                                      | data block    | 61                 |
|            +-----------+--------------------------------------+---------------+--------------------+
|            | block 2   |                                      | data block    | 62                 |
|            +-----------+--------------------------------------+---------------+--------------------+
|            | block 3   | Password A-access control-password B | control block | 63                 |
+------------+-----------+--------------------------------------+---------------+--------------------+

Each sector has a set of independent password and access control which are put in the last block of each sector, and the block is also known as sector trailer, that is Block 3 in each sector. Sector 0, block 0 (namely absolute address 0) of S50 is used to store the vendor code, which has been solidified and can’t be changed, and the card serial number is stored here. In addition to the manufacturer and the control block, the rest of the cards are data blocks, which can be used to store data. Data block can be used for two kinds of applications:

(1) used as general data storage and can be operated for reading and writing.

(2) used as data value, and can be operated for initializing the value, adding value, subtracting and reading the value.

The sector trailer block in each sector is the control block, including a 6-byte password A, 4-byte access control and 6-byte password B. For example, the control block of a brand new card is as follows:

.. list-table:: 
    :width: 50%
    :align: center
    :class: product-table

    *   -   A0 A1 A2 A3 A4 A5
        -   FF 07 80 69
        -   B0 B1 B2 B3 B4 B5

    *   -   password A
        -   access control
        -   password B


The default password of a brand new card is generally A0A1A2A3A4A5 for password A, B0B1B2B3B4B5 for password B, or both the password A and password B are 6 FF. Access control is used to set the access conditions for each block (including the control block itself) in a sector.

Blocks of S50 are divided into data blocks and control blocks. There are four operations, "read", "write", "add value", "subtract value (including transmission and storage)" for data blocks, and there are two operations, "read" and "write" for control blocks.

For more details about how to set data blocks and control blocks, please refer to Datasheet.

By default, after verifying password A or password B, we can do reading or writing operation to data blocks. And after verifying password A, we can do reading or writing operation to control blocks. But password A can never be read. If you choose to verify password A and then you forget the password A, the block will never be able to read again. **It is highly recommended that beginners should not try to change the contents of control blocks.**

Circuit
==================================

The connection of the control board and HC-SR04 is shown below.

.. list-table:: 
    :width: 70%
    :align: center
    :class: product-table

    *   -   Schematic diagram
    *   -   |Chapter24_03|
    *   -   Hardware connection
    *   -   |Chapter24_04|

.. |Chapter24_03| image:: ../_static/imgs/24_RFID/Chapter24_03.png
.. |Chapter24_04| image:: ../_static/imgs/24_RFID/Chapter24_04.png

Sketch
==================================

RFID_Read_UID
----------------------------------

Before writing code, we need to import the library needed.

Click “Add .ZIP Library...” and then find RFID.zip in libraries folder (this folder is in the folder unzipped form the ZIP file we provided). This library makes it easy to operate the RFID module.

This sketch will read the unique ID number (UID) of the card, recognize the type of the card and display the information through serial port.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_24.1_RFID_Read_UID/Sketch_24.1_RFID_Read_UID.ino
    :linenos: 
    :language: c
    :dedent:

After including the RFID library, we need to construct an RFID class object before using the function in RFID library. Its constructor needs to be written to two pins, respectively to the SDA pin and the RST pin.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_24.1_RFID_Read_UID/Sketch_24.1_RFID_Read_UID.ino
    :linenos: 
    :language: c
    :dedent:
    :lines: 12-12

In setup, initialize the serial port, SPI and RFID.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_24.1_RFID_Read_UID/Sketch_24.1_RFID_Read_UID.ino
    :linenos: 
    :language: c
    :dedent:
    :lines: 18-20

In loop(), use findCard() waiting for the card approaching. Once it detects the card, this function will return MI_OK and save the card type data in parameter str and then enter the if statement.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_24.1_RFID_Read_UID/Sketch_24.1_RFID_Read_UID.ino
    :linenos: 
    :language: c
    :dedent:
    :lines: 27-27

After entering if statement, call the sub function ShowCardType(). Then determine the type of the card according to the content of STR and print the type out through the serial port.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_24.1_RFID_Read_UID/Sketch_24.1_RFID_Read_UID.ino
    :linenos: 
    :language: c
    :dedent:
    :lines: 30-30

Then use the.anticoll() to read UID of the card and use serial port to print it out.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_24.1_RFID_Read_UID/Sketch_24.1_RFID_Read_UID.ino
    :linenos: 
    :language: c
    :dedent:
    :lines: 27-43

After verifying and uploading the code to control board, open the serial port monitor and place a card on the sensing area of RFID module. Then serial port monitoring window will display the displacement ID number and the type of the card. If the induction time is too short, it may lead to incomplete-information display.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_24.1_RFID_Read_UID/Sketch_24.1_RFID_Read_UID.ino
    :linenos: 
    :language: c
    :dedent:
    :lines: 30-30

.. image:: ../_static/imgs/24_RFID/Chapter24_05.png
    :align: center

Project 24.2 Read and write
******************************************

In this project, we will read and write a card.

Component list
===========================================

Same with last section.

Circuit
========================================

Same with last section.

Sketch
======================================

RFID_Read_And_Write
-----------------------------------------

In this sketch, first read the data in particular location of the S50 M1 Card, then write data in that position and read it. Display these data through the serial port.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_24.2_RFID_Read_And_Write/Sketch_24.2_RFID_Read_And_Write.ino
    :linenos: 
    :language: c
    :dedent:

In the sub function of writeCard () and readCard (), we must first verify the password A, and then use the corresponding sub function to read and write. Here we read and wirte data block 0 (absolute NO.4) of the first sector.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_24.2_RFID_Read_And_Write/Sketch_24.2_RFID_Read_And_Write.ino
    :linenos: 
    :language: c
    :dedent:
    :lines: 80-80

In loop (), compare the contents of the data block NO.4 after written with the original contents.

.. literalinclude:: ../../../freenove_Kit/Sketches/Sketch_24.2_RFID_Read_And_Write/Sketch_24.2_RFID_Read_And_Write.ino
    :linenos: 
    :language: c
    :dedent:
    :lines: 68-73

After verifying and uploading the code to control board, open the serial port monitor and place a card on the sensing area of RFID module, then the serial port monitoring window will display displacement ID numbers of the card, the type of this card and the contents (before and after writing operation) of data block. If the induction time is too short, it may lead to incomplete information display.

.. image:: ../_static/imgs/24_RFID/Chapter24_06.png
    :align: center