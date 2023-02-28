# 6 DOF Robot Arm Development Process
I've recently decided to increase the arm's degrees of freedom from 4 to 6. This design demo builds upon the Niryo One concept by adding new elements. 


## Demo (02/05/2023)

https://user-images.githubusercontent.com/110358483/216531680-9f43c2e4-7e79-4f10-bad0-22ec088e3362.mp4

Further Plan：
- Complete initial design 
- Complete simple drive selection and calculations
- Consider electrical device selection, including sensors, motors and control boards

## Initial design (02/08/2023)
1. The following is the initial design, the orange part can be printed by the 3D printer
2. Drive mechanism selection: Belt-drive for the bottom part (provide better speed stability for the heavier part) and servo for the simple movement of the upper part (cheaper and lighter)
3. The gripper part of the robot arm is designed to be able to install a variety of parts based on the current work requirements
4. The control board is temporarily chosen as raspberry Pi, considering that it can work with several different devices later.

![image](https://user-images.githubusercontent.com/110358483/217668174-f154ac08-14d3-46f3-9299-00e5b8e42595.png)

Further Plan：
- Improve some details (fasteners. wiring, strengthen structure)
- Base detail (finished) 

<img src="https://user-images.githubusercontent.com/110358483/218883227-5657cfed-86e4-4804-b06e-efb53c76a231.png" width=45% height=20%><img src="https://user-images.githubusercontent.com/110358483/221021521-7c02e040-e7d2-4044-862d-d4614aeb2ec5.png" width=45% height=50%>

<img src="https://user-images.githubusercontent.com/110358483/221029898-16054fc7-17e2-4f69-ab38-b0aef476f300.png" width=45% height=20%><img src="https://user-images.githubusercontent.com/110358483/221722830-9700262c-5925-41bc-8c8e-dc7ff225d33e.png" width=45% height=20%>

Figure 01: Base Assembly (left up) && Shoulder Assembly (right up) && Arm Assembly (left bottom) && wrist Assembly


- Update BOM and STL file

</br>

# Included Functions:
This is the feature I currently have in mind after updating the robot arm. Later updates consider merging the previous features and updating the existing data

### Control 
Provides a variety of control methods, including and not limited to：
- Bluetooth
- Image Recognition
- Direct commands through the computer


### Work with 3D printer and image recognition
- Automatic detection of print finish by image recognition and then start the next print by changing the printer bed.
- Simple and precise actions can be performed, including applying printer glue, holding the cooling finish product, changing printer bed.
- The gripper part can be replace by a vacuum pump for a stable movement.

<img src="https://user-images.githubusercontent.com/110358483/217673938-57c56cf8-5fe9-4f63-9147-d532731035c1.png" width=45% height=20%> <img src="https://user-images.githubusercontent.com/110358483/217674406-281e0e8a-1295-4408-92ac-2e92b8a8b605.png" width=45% height=20%>

Check out my 3D printer design here: https://github.com/jiayao09/CoreXY-3D-Printer
