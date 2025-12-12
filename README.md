# DCCFleischmannAccessories
Electronic modules to control, pilot of Fleischmann Turnouts


## Mimic pannel
An arduino Uno header to comtrol up to 4 Fleischmann motorised turnouts.

Future version 3.1
![MimicPanelPCB 3.1](/images/mimicpannelheader.png?raw=true)

Current version 2.0
![MimicPanelPCB 2.0 PCB](/images/mimicpannel.jpg?raw=true)

## Turnout modules
### Turnout Sink
Contains a relay and an ethernet RJ receiver to pilot one turnout

![TurnoutRelay3D](/images/turnout-relay-sink.png?raw=true)

### Turnout Source
Contains a connector for the AC16 power supply, 4 ethernet RJ connectors to supply 4 `Turnout Sink` via Ethernet cable and the header to connect to a `Turnout Controller` module

![TurnoutSourceFace3D](/images/source-face.png?raw=true)
![TurnoutSourceTop3D](/images/source-top.png?raw=true)

### Turnout Controller
Contains header to receive LED, buttons, DCC signal and connect to an Arduino UnoR4 and a `Turnout Source` module.

![TurnoutController3D](/images/controller.png?raw=true)