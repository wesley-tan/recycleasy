# RECYCLEASY - Automated Bottle Draining System
## Dartmouth College Recycling Solution

### Overview
RECYCLEASY is an automated solution designed to improve recycling efficiency at Dartmouth College dining establishments. 
The system automatically drains liquid from disposed bottles, addressing the issue of contaminated recyclables in the Zero-Sort™ waste collection system.
Our site can be found here: [Visit RECYCLEASY](https://sites.google.com/dartmouth.edu/recycleasy)

### Hardware Requirements
- Arduino board
- IR sensor (connected to pin 10)
- 3 LEDs:
  - Green LED (pin 8)
  - Red LED (pin 7)
  - Blue LED (pin 5)
- 23-gallon trash can (modified)
- PVC pipe
- Wire mesh
- Servo motor
- Rotating door
- Liquid waste tank
- Container for emptied bottles

### Circuit Setup
1. Connect the Green LED to pin 8 (system ready indicator)
2. Connect the Red LED to pin 7 (system active indicator)
3. Connect the Blue LED to pin 5 (unused in current implementation)
4. Connect the IR sensor to pin 10
5. Ensure all components are properly grounded

### Code Functionality
The system operates as follows:

1. **Initialization**
   - System starts with the Green LED on, indicating ready state
   - Serial communication is initialized for debugging (9600 baud rate)

2. **Main Operation**
   - Continuously monitors the IR sensor for bottle detection
   - When a bottle is detected (IR sensor reads LOW):
     - System activates (Green LED off, Red LED on)
     - Waits for 2 seconds (configurable via `waitTime`)
     - Returns to ready state (Green LED on, Red LED off)
   - Prevents multiple activations while processing a bottle

### Usage Instructions
1. Power on the system
2. Wait for the Green LED to illuminate (system ready)
3. Insert bottle into the designated opening
4. System will automatically:
   - Detect the bottle
   - Activate the draining mechanism
   - Store the liquid waste
   - Collect the empty bottle

### Performance Metrics
- Final prototype: 10.6% liquid retention, around 90% water drained

### Project Documentation
For more information, visit: https://sites.google.com/dartmouth.edu/recycleasy
