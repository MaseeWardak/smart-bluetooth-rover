# Arduino Smart Rover

## Project overview
This project is an arduino-based rover featuring RC-Control and automatic braking using ultrasonic sensors. It has a custom built steering system and a chassis designed in tinkercad and laser-cut. The main goal of this project was to explore the fundamentals of embedded systems, motor control, and sensor integration while developing a functional prototype that demonstrates practical robotics concepts.

## Features
- **Phone controlled steering**: Uses a smartphone app via Bluetooth (HC-05 module) to control an MG90S servo, achieving realistic car like steering with a custom steering mechanism made from home materials.
- **Obstacle Detection**: Using two ultra-sonic sensors, the rover can detect obstacles within a 40cm range and brake before collision.
- **Optimized power System**: Powered by two 18650 batteries (7.4V, 3000mAh), refined from initial 9V and 25C LiPo batteries for the weight and reliability.
- **High speed Performance**: Driven by two 25,000 RPM DC motors (3-12V) with an L298N driver for fast, responsive movement.

## Components
- **Microcontroller**: Arduino Uno R3
- **Motors**: 2x DC motors (3-12V, 25000 RPM) for movement
- **Motor driver**: L298N dual H-bridge for motor control
- **Servo**: MG90S micro servo for steering
- **Sensors**: 2x HC-SR04 ultrasonic sensors (1 front, 1 Back) for obstacle detection
- **Power**: 2x 18650 Li-ion batteries (3000mAh, 7.4V in series)
- **Communication**: HC-05 Bluetooth module for phone control
- **Chassis**: Laser-cut 1/8-inch plywood, designed in Tinkercad
- **Additional**: custom steering mechanism (plywood, screws, bent needle)

## Development timeline
- **Chassis design and assembly**:
  - Designed the rover in Tinkercad, multiple prototypes were designed. The chassis was then laser-cut using plywood.
  - Assembled a prototype which had basic phone-controlled forward/backward movement.
- **Steering mechanism**:
  - Created three steering designs over one week:
    - **First attempt**: Metal rods in wire coating glued to chassis sides. This failed due to weak support, wire coating was unstable.
    - **Second attempt**: Rods through chassis holes. This failed due to the thin chassis, the chassis itself is only 1/8' thick plywood so it could not hold the tires in a stable position.
    - **Final design**: Standalone mechanism using round plywood pieces, hot glue, and plywood. Linked wheels with a bent needle driven by MG90S servo and then screwed it to chassis. Success!
- **Power system optimization**:
  - Initial 9V batteries that I was using overheated within 10 seconds.
  - I tested 7.4V 3000mAh 25C LiPo battery. Unfortunetly they were too heavy and caused motor connector pin failure due to high current (25c discharge rate could damage the L298n too, very unpractical).
  - I switched to two 18650 batteries, these batteries work perfectly and offer an excellent runtime.
- **Phone-controlled functionality**:
  - Used an HC-05 Bluetooth module with Arduino Bluetooth Controller app for forward/backward movement and steering.
  - Initial code did not work as intended, because the bluetooth controller app could not send two signals simultaneously, so I implemented a toggle-based control system.
  - Toggle-based control was jittery, because the application sent multiple commands with a single press. To avoid this, I added debounce delay which makes the rover ignore repeated commands within a defined timeframe.
- **Automatic braking**:
  - Implemented a smart braking algorithm, which stops the rover when the ultrasonic sensors detect an obstacle in a specific range.
  - Due to the high speed motors of the rover, the rover will move in the opposite direction for a short time inorder to stop in time.
- **Testing and debugging**:
  - Debugged steering failures, battery overheating, and programming bugs.
  - Tested phone control, steering accuracy, and other systems of the rover.
- **Documentation and media**:
  - Created Tinkercad schematics, documented code, and captured prototype photos and videos.

## Media
- **Steering Mechanism**: A short video of how the steering works:
  - [Steering](https://youtu.be/WgILMfuBC3A)
- **Photos**: Images of the Rover throughout different times.
  - [Prototype 1](media)
- **Phone control video**: Demonstrates steering via smartphone, mimicking real car dynamics:
  - [Video Link](https://youtu.be/Wu7gwDVK65I?si=qelxx6BrU68tEiBO)
- **Brake Test**: Short video featuring the Ultra-sonic brakes:
  - [Video Link](https://youtu.be/QtTpKWQm3Ik)

## Code
The full Arduino code is available in this repository:
- [Main Sketch](https://github.com/MaseeWardak/smart-bluetooth-rover/blob/main/Code/Ultrasonic.BluetoothCodeByMasee.ino)

## Future improvements
- Self driving rover.
- This project was made prior to having deep experience with C++, using loops could be very beneficial, which is something I intend to do in the future.

## Contact
For questions or collaboration, reach me at maseehwardak5@gmail.com or www.linkedin.com/in/maseehullah-wardak-8244ba319
