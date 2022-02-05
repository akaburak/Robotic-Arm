# Robotic-Arm
 This is a Robotic Arm design that is able to rotate 360 degrees and grip objects from a certain range.
 Industrial robotic arms have static parts along with the dynamic parts. 
 The specifications of the arm may vary according to the needs of the field that the arm is going to be used.
 Working principle of the robotic arm is fairly basic. In order to control the rotation of the arm pieces, servo motors have been used. 
 In order to drive the servo motors, Arduino have been used.
 In order to synchronize the servo motors, synchronous Arduino code have been written. Source code is included in the files.
 As for the tower rotation, dc motor have been used. There is also a dc motor drive code included in the files.
 ### Mechanical Design
 The main concern of the mechanical design of the robotic arm is mostly the torque required to rotate the arm pieces. There are four servo motors which are used to rotate the arm pieces. They are labeled as "Big", "Alpha", "Beta" and "Grip". In order to lower the load on the servos, there have been attempts to reduce the weight of the pieces. Some of them have failed and resulted in an unstable design. However, many of them have succeeded and resulted in a very weight efficient system. 
 ### Code
 As for the code, there are two different alternatives. The servo codes can be written from scratch using the duty cycle of the servos or built-in servo functions in Arduino can be used. At first, the code was written from scratch but it wasn't fast enough to respond to the code. Later on, the code was rewritten using built-in servo functions.
 #
 ## Future of the project
 The way to improve this project includes automation. At this stage, the movement can be provided both by the code and the button control from the breadbord circuit. However, by using proximity sensors and a camera, the whole process can be automated. The camera can be controlled by the Arduino to perceive the target, calculate the distance and decide on an action plan.
#
### What is included in the files
* All of the sldprt files of the robotic arm
* Stl files of the robotic arm
* Sldasm file of the robotic arm
* All of the servo codes and the dc motor code
