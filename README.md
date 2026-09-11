# DCC and DIY Turnout Accessories
Electronic modules to control, pilot of Fleischmann or Kato Turnouts

## Project status: active vs. abandoned

Only part of the repository is under active development. Bruno has confirmed:

| Directory | Status |
|---|---|
| `CMRI/` | **Abandoned.** |
| `DCC-Decoder/` | **Abandoned — but done, not broken.** Built, tested, and validated; there is nothing left to do on it. |
| `Fleischmann/` (decoder sketches, `Mimic-Panel`, `Turnout-Source`/`Turnout-Sink`/`Turnout-Controller`) | **Abandoned.** The tested/validated Mimic-Panel hardware (the working version described in its README as "2.x") is kept as a reference: it establishes the baseline design and its known defects for `Loconet/LoconetTurnout`, which should fix them rather than repeat them, even though the LocoNet board is simpler. |
| `Kato/DCCDetection/` | **Abandoned.** |
| `Kato/Mimic-Panel/` | **Abandoned.** |
| `Kato/YD6016Interface/` | **Active.** |
| `Loconet/` (`LoconetLeader`, `LoconetFollower`, `LoconetTurnout`) | **Active.** |


## Loconet module
Define new loconet compatible module to pilot the Kato turnout and make the interface between JMRI and the layout
* A Loconet master shield
* A Loconet turnout shield
* A Loconet follower shield to stack upon the turnout shield

## Fleischmann modules
### Mimic pannel
An arduino Uno header to control up to 4 Fleischmann motorised turnouts.

Fleischmann tested version 2.0
![MimicPanelPCB 2.0 PCB](/images/mimicpannel.jpg?raw=true)

