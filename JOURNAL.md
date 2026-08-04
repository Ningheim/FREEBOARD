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
[LAPSE](https://lapse.hackclub.com/timelapse/rfvNHJk3dFeS)[LAPSE](https://lapse.hackclub.com/timelapse/_yMK92cxTNwy) 

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

# 7/31/2026
[LAPSE](https://lapse.hackclub.com/timelapse/Ccc565L8SkLy)

Finished 3D modelling the PCB. it took a while but it looks extremely nice, I quickly learned how to add 3d models to a global footprint instead of editing each switch's individual one. I got the DSA keycap models from a reddit post. This is the [link](https://drive.google.com/drive/u/0/folders/0B0LNjZf_tzjWZGhwZ0VKUm9PQVE?resourcekey=0-rYUAMYD1-22Btlgdmpb0IQ) I'm really grateful to the creator. Anyways it looks like this now with all the components (Minus the oled display) modeled:

<img width="933" height="466" alt="image" src="https://github.com/user-attachments/assets/ad96d684-277b-43fb-b5e1-8a1b04ab8cc9" />

I swapped out the OLED display footprint for a `Stemma QT 4-Pin Female Connector` Because I decided I was going to connect my display via a `Header to QT` style cable from Adafruit. And in doing this, I allow the connection between the OLED display and my PCB to be a lot more flexible which would allow me to prop the display up on an incline as seen on Wormier's keyboards (I took a lot of inspiration from them, I love their designs) as seen below:

<img width="406" height="268" alt="image" src="https://github.com/user-attachments/assets/651dbd19-7804-4636-b141-3aac73b19ace" />

This would be both aesthetically pleasing and gives the display a little more accessibility. And now I'm tackling the GND plane issue. It took me a while to understand but now I realize I just have to connect all the GND pads together and then do the ground pour to leave no room for errors about my GND connection. I've routed about 45% of the GND net so far and once I finish this I will be able to finally move onto the Case design which I'm pretty excited for. I'm going to make this keyboard near perfect to actually use it in place of my current TKL one. Here's how the PCB looks now (I know, beautiful 🥹) :

<img width="1066" height="563" alt="image" src="https://github.com/user-attachments/assets/851daa67-c56d-4d16-89f7-c2a4c4b53bfa" />

# 8/1/2026
[LAPSE](https://lapse.hackclub.com/timelapse/lMde7KmQML3c) [LAPSE](https://lapse.hackclub.com/timelapse/M3SkIIiRgxoi)

Finally completed the PCB within the first hour of this lapse. Spent the rest modelling the case. I'm double, triple, and quadruple checking each part of my layout just to make sure I don't have any miscalculations or inconsistencies with my work. This is how the finished PCB looked:

<img width="1600" height="603" alt="image" src="https://github.com/user-attachments/assets/108113f4-2088-43a3-b2b8-9206295649dd" />

I'm modelling the case design in Onshape and I guess I'll submit an assembly demo with push-able keys later. Ok scratch that onshape is already struggling on my laptop I doubt adding push-able mates is necessary. Anyways I just finished the bottom plate of my case (for the most part) and it looks amazing imo. I'm adding a transparent plastic window in my next session but it looks like this now at 10mm of thickness:

<img width="1210" height="641" alt="image" src="https://github.com/user-attachments/assets/78a77316-ec20-4662-8dc2-cd7d496007eb" />

It looks great and I'm really happy about how I added the 2 stage stands at the top, I hope they work but yeah this is basically it for now.

# 8/2/2026
[LAPSE](https://lapse.hackclub.com/timelapse/Tz_bAdnx_3QB) [LAPSE](https://lapse.hackclub.com/timelapse/NqZxc6qf-A2T)

I finished the entire Board body in about an hour. I'm moving onto the Firmware now. I finished modelling the Rotary Encoder Knob and Recessed the OLED Display panel a little more to allow this to keep it's low-(ish) profile silhouette. 

<img width="967" height="641" alt="image" src="https://github.com/user-attachments/assets/8e8dd107-7591-4422-925d-f779674da740" />

> Also, for anyone that's looking to model their keyboard like I did with mine, I found the DSA profile models in a Reddit thread which I'm super grateful for. Here's the google [drive link](https://drive.google.com/drive/u/0/folders/0B0LNjZf_tzjWZGhwZ0VKUm9PQVE?resourcekey=0-rYUAMYD1-22Btlgdmpb0IQ)

And I forgot to generate the BOM and fabrication files for JLCPCB or PCBWAY so I made sure to do that. Also I forgot to add the copper fill layer, it wouldn't really be that bad if I left it out but I guess it's always optimal to do so, here's how it looked:

<img width="1399" height="729" alt="image" src="https://github.com/user-attachments/assets/13c845a1-9f3c-4d3d-b285-2ed3ef9bd253" />

Ok, just finished the second lapse. I'm absolutely livid at how terrible Gemini is as an LLM. It kept recommending things and making me go down rabbit holes that were completely unrelated and I had to use Gemini because I ran out of Claude credits 😭 I spent 4 hours of my life coding a dysfunctional firmware because Gemini is so redundant it's actually crazy bro. Anyway I at least mapped the keys into the JSON dictionary and I reverted the files mostly to before I started getting baited by Gemini. I'm honestly just happy I can start from a feasible position now because the amount of time I just wasted is insane. I'm sticking to Claude for life. 

# 8/3/2026
LAPSE

Just some housekeeping adjustments made to the onshape file. Also I realized I forgot to share the link to the native onshape document, [so here it is](https://cad.onshape.com/documents/8cd69c605bee1d154198ffc3/w/f18789aa034f433dfb01300c/e/379cd418fcd399b0823d03fd?renderMode=0&uiState=6a70ef1ef884ff3f2fcfd699). I fixed some interference issues I noticed in assembly, they werent that important but I'm just making sure everything fits together smoothly.

# 8/4/2026

Just finished calculating how much this would cost, with the BOM and everything. Here are the results:

PCB - $37.84
Switches, Keycaps, Encoder, Display - $15
Plastic Case - Free (Printing Legion)
Electronic Components: $22.18
Total: ~$75.02

So not that bad. I hope I have enough currency leftover to buy some RAM. Anyways, I'll be working on the Firmware later today.





