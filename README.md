# Arduino Smart Rover

## Project overview
This project is an arduino-based rover featuring RC-Control and automatic braking using ultrasonic sensors. It has a custom built steering system and a chassis designed in tinkercad and laser-cut. The main goal of this project was to explore the fundamentals of embedded systems, motor control, and sensor integration while developing a functional prototype that demonstrates practical robotics concepts.

## Features
- **Phone controlled steering**: Using a smartphone app via Bluetooth (HC-05 module) to control an MG90S servo, achieving realistic car-like steering with a custom steering mechanism made from home materials.
- **Obstacle Detection**: Using two ultra-sonic sensors, the rover can detect obstacles within a 19cm range and brake before collision.
- **Optimized power System**: Powered by two 18650 batteries (7.4V, 3000mAh), refined from initial 9V and 25C LiPo batteries for weight and reliability.
- **High speed Performance**: Driven by two 25,000 RPM DC motors (3-12V) with an L298N driver for fast, responsive movement.

## Components
- **Microcontroller**: Arduino Uno R3
- **Motors**: 2x DC motors (3-12V, 25,000 RPM) for movement
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
    - **First attempt**: Metal rods in wire coating glued to chassis sides; failed due to weak support, wire coating was unstable.
    - **Second attempt**: Rods through chassis holes; failed due to thin chassis instability, the chassis itself is only 1/8' thick plywood so it could not hold the tires in a stable position.
    - **Final design**: Standalone mechanism using round plywood pieces, hot glue, and plywood. Linked wheels with a bent needle driven by MG90S servo, screwed to chassis. Success!
  - Programmed servo for proportional steering via phone inputs, achieving ±5° accuracy.
- **Power system optimization**:
  - Initial 9V batteries overheated within 10 seconds.
  - Tested 7.4V 3000mAh 25C LiPo battery; unfortunetly thet were too heavy and caused motor connector pin failure due to high current (25c discharge rate could damage the L298n too, very unpractical).
  - Switched to two 18650 batteries, these batteries work perfectly and offer an excellent runtime.
- **Phone-controlled functionality**:
  - Integrated HC-05 Bluetooth module with Arduino Bluetooth Controller app for forward/backward movement and steering.
  - Initial code did not work as intended, because the bluetooth controller app could not send two signals simultaneously, so a toggle-based control was implemented.
  - Toggle-based control was jittery, because the application sent multiple commands with a single press. To avoid this, a debounce delay was added which makes the rover ignore repeated commands within a 210ms timeframe.
- **Automatic braking**:
  - Implemented a smart braking algorithm, which stops the rover when the ultrasonic sensors detect an obstacle in a 19cm range.
  - Due to the high speed motors of the rover, the rover will move in the opposite direction for 350ms inorder to stop in time.
- **Testing and debugging**:
  - Debugged steering failures, battery overheating, and programming bugs.
  - Tested phone control, steering accuracy, and other systems of the rover.
- **Documentation and media**:
  - Created Tinkercad schematics, documented code, and captured prototype photos and videos.

## Challenges and solutions
1. **Steering mechanism failures**:
   - **Problem**: Initial designs (wire coating, chassis holes) lacked stability for steering.
   - **Solution**: Built a standalone mechanism with plywood and rods, using a servo-driven bent needle for precise wheel linkage, screwed to the chassis.
2. **Battery overheating and weight**:
   - **Problem**: 9V batteries overheated; 25C LiPo was heavy and caused motor pin failure.
   - **Solution**: Adopted two 18650 batteries for lightweight, rechargeable power, with PPTC fuses and PWM to manage current.
3. **Bluetooth control**:
   - **Problem**: Mobile app supports one command at a time, making movement and steering impossible at the same time.
   - **Solution**: Updated Arduino code to work using a toggle based system, with a debounce delay timer that stops repeated commands to avoid jittering.
4. **High motor speed control**:
   - **Problem**: 25,000 RPM motors caused instability at full power.
   - **Solution**: Used PWM via L298N to regulate speed and protect components.

## Media
- **Steering Mechanism**: A short video of how the steering works:
  - [Steering](https://youtu.be/WgILMfuBC3A)
- **Prototype 1 photos**: Images of the initial chassis with 9V batteries and basic phone control.
  - [Prototype 1](media)
- **Phone control video**: Demonstrates steering via smartphone, mimicking real car dynamics.
  - [Video Link](https://youtube.com/phone-control-video)
- **Autonomous mode video**: Shows obstacle avoidance and rocking motion in action.
  - [Video Link](https://youtube.com/autonomous-video) *(To be uploaded)*

## Code
The full Arduino code is available in this repository:
- [Main Sketch](https://github.com/MaseeWardak/arduino-rover/blob/main/arduino_rover.ino)

## Future improvements
- Self driving rover.

## Skills demonstrated
- **CAD design**: Designed chassis in Tinkercad for laser cutting.
- **Embedded systems**: Programmed Arduino for motor control, sensor integration, and Bluetooth communication.
- **Mechanical sesign**: Iterated steering mechanism for real-car-like dynamics.
- **Problem-solving**: Addressed steering, power, and navigation challenges through iterative design.
- **Self-learning**: Developed all skills independently before university coursework.

## Contact
For questions or collaboration, reach me at maseehwardak5@gmail.com or www.linkedin.com/in/maseehullah-wardak-8244ba319
