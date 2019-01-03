## Welcome to Hades

Hades is an extremely small scale rocket that is built to perform reflect the development of large scale rockets and other space flight endeavors. In order to follow this philosophy, we are using the most efficient/low-powered parts as possible. Our flight computer consists of an Arduino Micro, which uses the ATmega32U processor, which handles pyro events, stabilization through thrust vectoring, and landing procedures.

Primarily, the software and algorithms for this project will be written in C++, which is inline with the language that the Arduino operates in. Other tasks such as simulation of the rocket will be designed in MATLAB or SimuLink. Our selection of motor was the Estes F15-0, because of its long burntime of 4 seconds. It's thrust curve is also provided in this repository as "F15_TC.mat".
Along with the trust curves, the simulations are also given in this repository. Uploadable Arduino files can be found in the "control_sys" folder, and other source files should be taken as building blocks for the custom stablization and control software for the Arduino.

## Current Progress
## As of Dec 2018:
1. Single Stage Thrust Vectoring Development
2. Pyro Events
