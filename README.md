# RobotArm
This a robotic arm with a 4 DOF developed based on MeArm model for further development. Take a look at my BOM and assembly drawing PDF to build the same model.
(check out start.ino)

<img src="https://user-images.githubusercontent.com/110358483/217950253-55d2c72d-19f0-4276-a32f-84d50591aed0.jpg" width=45% height=20%>
Figure 1:Robotic arm with Laser cutting update
</br>
</br>

https://user-images.githubusercontent.com/110358483/185725085-09091f4c-c75e-4899-8eab-52e4dab4b233.mp4


# list of file
- Detail BOM
- STL file for 3D printing
- Laser cutting file for gripper version 2 (optional)
- Assembly drawings for installation
- Code for the above video （Control Board：Arduino）


</br>

#  RECENT UPDATE:
I've recently decided to increase the arm's degrees of freedom from 4 to 6. This design demo builds upon the Niryo One concept by adding new elements. The detail drawing and bill of materials (BOM) will be updated later. The new design expands on the original functionality by including new interfaces and hardware.

![image](https://user-images.githubusercontent.com/110358483/217668174-f154ac08-14d3-46f3-9299-00e5b8e42595.png)

### Check out the development process here:  https://github.com/jiayao09/RobotArm/tree/6-DOF-Robot-Arm



</br>

# Included Functions:
### Control by coding

https://user-images.githubusercontent.com/110358483/185726008-0d00c303-87b9-40a1-b045-875e55abf965.mp4

### Control by phone with the HC-06 Bluetooth module (check out start.ino)

https://user-images.githubusercontent.com/110358483/185725174-6e9ee21b-cd90-49b7-b49f-77a15e82c952.mp4

</br>

### Control by Wearable-Controller
Check out more information here: https://github.com/jiayao09/Wearable_Controller.git
- Sensor and control board:
   - Arduino uno
   - Servo KN99 X 4
   - NRF24L01

<img src="https://user-images.githubusercontent.com/110358483/185727059-d2c78070-4f85-48c9-85f0-b0151b72b232.png" width=45% height=20%>

</br>

### Control by ESP32 cam for image recognition (Pending)
- Add object or color detection
- Move to detect object position

