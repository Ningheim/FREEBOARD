# FREEBOARD
A 60% RGB Backlit Keyboard with a OLED display, rotary encoder, and adjustable inclination stands.

This keyboard is powered by an Orpheus/Raspberry Pi Pico and an additional MCP23017 for extra GPIO pins. The firmware is entirely coded in [QMK](https://qmk.fm/) and the case is a little wider than a Framework 13 for reference, at about 320x165mm it's made to be compact and accessible to be used alongside a laptop. I made this because I wanted to fix a lot of things with the layout of other wormier and logitech keyboards where the keys weren't as inline as I'd hoped whilst still including function keys and appealing RGB factors.

## Here are the pictures to the project
### Intended Layout ([Plate Generator](https://kbplate.ai03.com/)):
<img width="821" height="313" alt="LAYOUT" src="https://github.com/user-attachments/assets/9b65434e-cad4-46cb-b08a-8eb8d06a1bae" />

### Schematic (KiCAD):
<img width="1825" height="855" alt="SCHEMATIC" src="https://github.com/user-attachments/assets/8fb747b1-f755-4a76-8f32-738cdba652da" />

### PCB (KiCAD):
<img width="1600" height="603" alt="PCB" src="https://github.com/user-attachments/assets/c2d6ad7b-6073-4399-9658-c3d35f5f3e2a" />
<img width="1399" height="729" alt="FINALPCB" src="https://github.com/user-attachments/assets/c28a9758-44ab-4554-9b7d-9159b98df035" />

### CASE (Onshape [[Document Link]](https://cad.onshape.com/documents/8cd69c605bee1d154198ffc3/w/f18789aa034f433dfb01300c/e/379cd418fcd399b0823d03fd?renderMode=0&uiState=6a71e7e218279ebdb2fef9ea))
<img width="967" height="641" alt="CASE" src="https://github.com/user-attachments/assets/8c5fbac4-1bda-4e8e-9039-d1c019e69522" />

## Case Assembly

You can use adhesive for some of the parts but it isn't required as they should sit flush without any glue, you can also sand things down to fit flush if your 3d printed had a printing issue. All of the parts I'm naming in this section have corresponding names in the onshape document.

1. Put the `Plastic Spacer` in first, then the `Plastic Window` into the slot on the inside of the `Base Case`, The window is meant to be made out of clear material like transparent plastic or something so you can see the Silkscreen design on the bottom side of the board.
2. Cut a two 1mm diameter rods to 64mm and Thread each one through the holes of each set of tilt stands you as shown in the assembly tab on the onshape document. The stands should be able to turn/revolve around the axis of the rods, and you can make the rods of any material it just has to be firm. To lock the rods in, melt plastic or insert rubber friction pads into each of the 6 empty rectangular indents on the back of the `Base Case`
3. Then you can put in the PCB with the `Plate` ontop of it. Now we have the `Top Cover` and `Translucent Emblem` left, so put the `Translucent Emblem` into the matching cutout on the `Top Cover`, and insert those joined pieces into the top of the case, to keep everything pressed down. Lastly, add the encoder knob and you're done!

## How To Flash


## BOM
- PCB - $37.84
- Switches, Keycaps, Encoder, Display - $15
- Plastic Case - Free (Printing Legion)
- Electronic Components - $22.18
- Display Connector - $7
- Total: ~$83.02












