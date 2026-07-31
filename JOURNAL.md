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
[LAPSE](https://lapse.hackclub.com/timelapse/dE8z8UnWDV4i) [LAPSE](https://lapse.hackclub.com/timelapse/KWQZoNLu7TrB)

Made a lot of nice progress with tracing. I troubleshot the switch matrix and I believe it's good as of now. It's easily subject to change after I add the rotary encoder. I'm not exactly sure how I'm supposed to incorporate the encoder right now. All of the other components are pretty straightforward except for that. I'm running out of pins on the Pico so I'm searching for ways to conserve as many as possible. Today I got Claude to help me code a JSON for a keyboard switch layout/plate and I finally got it looking a little more professional. Here's the polished version of what my keyboard layout will look like:
<img width="821" height="313" alt="image" src="https://github.com/user-attachments/assets/ca33dfb7-e9aa-4203-8d0a-1e8f750d27e0" />

Once I get a response in the channel for help with wiring the power bus lines and the rotary encoder I'll resume and finish off the schematic process for now. I'm liking how it all looks so far. This is the schematic as of right now, once I finish the schematic I'll separate all the groups and finalize the organization of the file:

<img width="870" height="804" alt="image" src="https://github.com/user-attachments/assets/ca15a51b-18e2-4ed3-9897-9c635129494c" />

**Okay it's me 15 hours later**, I made tremendous progress with the Schematic and I was able to almost completely finish the schematic. I haven't assigned footprints yet but everything went extremely well this session. I implemented resistors and capacitors wherever I needed them. I found out I needed them by looking at other submissions to Keeb and asking Claude a few questions. Speaking of Claude, it told me to add a fuse to the VBUS so the PCB I plan on connecting this stuff to wont completely self destruct if the RGB LEDs go crazy. But every time I added the fuse it kept giving me an error so for now I'm sticking with the error-less design. Next session I'll look into the whole fuse idea a little harder and I'll determine whether or not I'll use it; I'll also add footprints to everything and finally start working on laying out traces for the physical PCB. We're almost there!

<img width="1825" height="855" alt="image" src="https://github.com/user-attachments/assets/c8520374-5602-41fd-9222-bfbebb062ad3" />

# 7/29/2026
[LAPSE](https://lapse.hackclub.com/timelapse/_yMK92cxTNwy)

Today I finalized the schematic and footprints.

<img width="1919" height="1029" alt="image" src="https://github.com/user-attachments/assets/edb827b9-a7ee-4dc7-bbae-83109170ed53" />

Took me an hour to do it because I had some trouble with the fuse idea from earlier. I found out that the fuse isn't really necessary. I also understand that I could have added a 33ohm resistor in between each LED's data pins but i decided not to do that since it'd be a pain to handsolder. And I'm going to be adding mill-max hotswap sockets to my finished build. So I hope I get funded for that. I was told I would be funded for everything that would necessarily impact my project. Right now I'll list all the ammenities and complexities I decided to add to the project:
- Per-Key Backlight
- Caps Lock Indicator
- Backlit Branding Logo
- Rotary Encoder
- OLED Display
- Hotswappable Switches

Anyways later today I'll work on the PCB design itself. I'll ask around if there's anything wrong with how I made the schematic but I think I'll be moving on now!

**Its around midnight now** I got done with a 4-5 hour session and i finished organizing everything and whatnot. The board organization is 90% done but i need some rest. Tomorrow I'll finish organizing the components in a few minutes and finally start routing.
<img width="858" height="668" alt="image" src="https://github.com/user-attachments/assets/3a765e0c-4b64-4eed-aca7-ce3004881e84" />

# 7/30/2026
[LAPSE](https://lapse.hackclub.com/timelapse/d9UfakixuzQQ)

Just started routing the PCB. It is not looking good at all. My organization is great though, but when I finished it all and went to fill the copper layer I got hundreds of errors and warnings. This was really discouraging but I know it isn't to important since all of my layouts and traces should be connected. I'll look over it again tomorrow. I suspect it's because I didn't put traces or Vias on any of the GND pads believing the layer fill would connect them all automatically. I'll try to do it manually later on.. Anyways the lapse feature has been working pretty well recently! I haven't gotten any corrupt or inaccessible files after strictly doing lapses from lapse.hackclub.com instead of any other embed or site, but, accidentally of course, I took a break to scroll tiktok and play games without pausing the recording so instead of 5 hours and 48 minutes its more like only 5 hours.
<img width="1786" height="605" alt="image" src="https://github.com/user-attachments/assets/608c62f9-636b-4b99-8bcb-3760b20b9668" />














