
# 7/27/2026
[LAPSE](https://lapse.hackclub.com/timelapse/CAK7ywI3q3qV)

I studied keyboard anatomy and creation for a while before starting this project. I now know I need three things to actually make this keyboard:

- **PCB**
- **Plate**
- **Case**

And as simple as that makes it look, I know it will be a long a grueling process especially since this is the first real keyboard I've made. Today I finished the keyboard matrix, taking inspiration from the Wormier 60% and 65% keyboards for the layout I mapped below:
<img width="1189" height="413" alt="image" src="https://github.com/user-attachments/assets/ff191a45-fb7c-4429-b85a-6c9532385e14" />

Next session I'll be routing the RGB LEDs, OLED display, rotary encoder, and external SoM connector in the schematic.

The layout is a 60%-style board with the function row and PrintScreen key included. It'll have a small margin at the top for an RGB text badge reading "FREEBOARD," along with an OLED screen and a backlit rotary encoder. There will also be a dedicated LED for Caps Lock indication. I took some inspiration from the Logitech G PRO keyboard I currently use, just scaled down a bit. My goal is for this keyboard to sit on top of a Framework 13's keyboard, for gaming and general use.

This was a pretty difficult process, but I'm super excited and feeling good about the progress so far.

*(Also, sorry about the video playing during the lapse, I was watching Mat Armstrong to stay sane through the whole process.)*

# 7/28/2026
LAPSE

Made a lot of nice progress with tracing. I troubleshot the switch matrix and I believe it's good as of now. It's easily subject to change after I add the rotary encoder. I'm not exactly sure how I'm supposed to incorporate the encoder right now. All of the other components are pretty straightforward except for that. I'm running out of pins on the Pico so I'm searching for ways to conserve as many as possible. Today I got Claude to help me code a JSON for a keyboard switch layout/plate and I finally got it looking professional-ish. Here's the polished version of what my keyboard layout will look like:
<img width="821" height="313" alt="image" src="https://github.com/user-attachments/assets/ca33dfb7-e9aa-4203-8d0a-1e8f750d27e0" />

Once I get a response in the channel for help with wiring the power bus lines and the rotary encoder I'll resume and finish off the schematic process for now. I'm liking how it all looks so far. This is the schematic as of right now, once I finish the schematic I'll separate all the groups and finalize the organization of the file:
<img width="870" height="804" alt="image" src="https://github.com/user-attachments/assets/ca15a51b-18e2-4ed3-9897-9c635129494c" />
