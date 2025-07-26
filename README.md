# Arduino Autonomous Car with Phone-Controlled Ackerman Steering

## Project Overview
This project is an Arduino-based car featuring phone-controlled Ackerman steering, mimicking real car dynamics, and autonomous navigation with ultrasonic sensors. Designed and built over four weeks in the summer before starting my Electrical Engineering degree at the University of Waterloo, this solo project demonstrates self-driven learning in CAD design, embedded systems, wireless communication, and hardware troubleshooting. Evolving through three prototypes, it showcases iterative design and problem-solving for a pre-university student.

## Features
- **Phone-Controlled Ackerman Steering**: Uses a smartphone app via Bluetooth (HC-05 module) to control an MG90S servo, achieving realistic car-like steering with a custom Ackerman mechanism.
- **Autonomous Navigation**: Employs three HC-SR04 ultrasonic sensors (5 cm front, 20 cm sides) with a rocking motion (0.5s forward, 0.2s backward) to escape obstacles.
- **Optimized Power System**: Powered by two 18650 batteries (7.4V, 3000mAh) with PWM control and PPTC fuses, refined from initial 9V and 25C LiPo batteries for weight and reliability.
- **High-Speed Performance**: Driven by two 25,000 RPM DC motors (3-12V) with an L298N driver for fast, responsive movement.

## Components
- **Microcontroller**: Arduino Uno R3
- **Motors**: 2x DC motors (3-12V, 25,000 RPM) for propulsion
- **Motor Driver**: L298N dual H-bridge for motor control
- **Servo**: MG90S micro servo for Ackerman steering
- **Sensors**: 3x HC-SR04 ultrasonic sensors (1 front, 2 sides) for obstacle detection
- **Power**: 2x 18650 Li-ion batteries (3000mAh, 7.4V in series) with a 5V buck converter for Arduino and servo
- **Communication**: HC-05 Bluetooth module for phone control
- **Chassis**: Laser-cut 1/8-inch plywood, designed in Tinkercad
- **Additional**: PPTC fuses, thicker gauge wires, custom Ackerman steering mechanism (plywood, screws, bent needle), breadboard for prototyping

## Development Timeline
- **Chassis Design and Assembly (20 hours)**:
  - Designed chassis in Tinkercad for 1/8-inch plywood, incorporating two DC motors, wheels, Arduino Uno, L298N, HC-05, and two 9V batteries (one for motors/L298N, one for Arduino).
  - Laser-cut chassis and assembled prototype one for basic phone-controlled forward/backward movement.
- **Ackerman Steering Mechanism (50 hours)**:
  - Iterated three steering designs over one week:
    - **Attempt 1**: Metal rods in wire coating glued to chassis sides; failed due to weak support.
    - **Attempt 2**: Rods through chassis holes; failed due to thin chassis instability.
    - **Final Design**: Standalone mechanism using round plywood pieces (from Dollarama), rods, and plywood connectors. Linked wheels with a bent needle driven by MG90S servo, screwed to chassis.
  - Programmed servo for proportional steering via phone inputs, achieving ±5° accuracy.
- **Power System Optimization (30 hours)**:
  - Initial 9V batteries overheated within 10 seconds.
  - Tested 7.4V 3000mAh 25C LiPo battery; too heavy and caused motor connector pin failure due to high current.
  - Switched to two 18650 batteries, added PPTC fuses, and used thicker wires with PWM control for reliability.
- **Phone-Controlled Functionality (25 hours)**:
  - Integrated HC-05 Bluetooth module with Arduino Bluetooth Controller app for forward/backward movement and steering.
  - Tuned for low-latency control and smooth Ackerman steering.
- **Autonomous Navigation (25 hours)**:
  - Added three HC-SR04 sensors (5 cm front, 20 cm sides).
  - Programmed navigation logic with obstacle avoidance and a rocking motion (0.5s forward, 0.2s backward, max three cycles) to escape narrow spaces.
  - Tuned sensor ranges and set reverse power to 255.
- **Testing and Debugging (20 hours)**:
  - Debugged steering failures, battery overheating, and high-current issues.
  - Tested phone control, steering accuracy, and autonomous navigation in real-world scenarios.
- **Documentation and Media (10 hours)**:
  - Created Tinkercad schematics, documented code, and captured prototype photos and videos.
  - Total: **160 hours** over 4 weeks (summer 2025).

## Challenges and Solutions
1. **Steering Mechanism Failures**:
   - **Issue**: Initial designs (wire coating, chassis holes) lacked stability for Ackerman steering.
   - **Solution**: Built a standalone mechanism with plywood and rods, using a servo-driven bent needle for precise wheel linkage, screwed to the chassis.
2. **Battery Overheating and Weight**:
   - **Issue**: 9V batteries overheated; 25C LiPo was heavy and caused motor pin failure.
   - **Solution**: Adopted two 18650 batteries for lightweight, rechargeable power, with PPTC fuses and PWM to manage current.
3. **Obstacle Navigation**:
   - **Issue**: Car got stuck in narrow spaces due to excessive reversing.
   - **Solution**: Implemented a rocking motion (0.5s forward, 0.2s backward) with a three-cycle limit, followed by a sharp turn.
4. **High Motor Speed Control**:
   - **Issue**: 25,000 RPM motors caused instability at full power.
   - **Solution**: Used PWM via L298N to regulate speed and protect components.

## Media
- **Prototype 1 Photos**: Images of the initial chassis with 9V batteries and basic phone control.
  - [Prototype 1](https://github.com/yourusername/arduino-car/raw/main/images/prototype1.jpg)
- **Phone Control Video**: Demonstrates Ackerman steering via smartphone, mimicking real car dynamics.
  - [Video Link](https://youtube.com/your-phone-control-video)
- **Autonomous Mode Video**: Shows obstacle avoidance and rocking motion in action.
  - [Video Link](https://youtube.com/your-autonomous-video) *(To be uploaded)*

## Code
The full Arduino code is available in this repository:
- [Main Sketch](https://github.com/yourusername/arduino-car/blob/main/arduino_car.ino)
Key features include:
- Bluetooth serial communication for phone-based steering and movement.
- Proportional servo control for Ackerman steering.
- Ultrasonic sensor logic for obstacle detection and rocking motion.
- PWM-based motor control for speed regulation.

## Future Improvements
- Add a toggle switch to alternate between phone and autonomous modes.
- Implement sensor data logging to analyze navigation performance.
- Enhance steering with a PID controller for smoother turns.

## Skills Demonstrated
- **CAD Design**: Designed chassis in Tinkercad for laser cutting.
- **Embedded Systems**: Programmed Arduino for motor control, sensor integration, and Bluetooth communication.
- **Mechanical Design**: Iterated Ackerman steering mechanism for real-car-like dynamics.
- **Power Management**: Optimized battery selection and current control with PWM and fuses.
- **Problem-Solving**: Addressed steering, power, and navigation challenges through iterative design.
- **Self-Learning**: Developed all skills independently before university coursework.

## Contact
For questions or collaboration, reach me at [maseehwardak5@gmail.com] or [LinkedIn Profile]. Check out my [portfolio website](#) for more projects.
