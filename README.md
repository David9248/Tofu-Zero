# Tofu-Zero

Open Source Macro Keyboard based on QMK with VIAL integration. It runs on an RP2040 Zero and comes with 1 OLED screen, 1 encoder, a 3x3 matrix, and RGB lighting.

## Components

**Required:**
- 1x Custom PCB
- 1x RP2040 Zero
- 1x OLED 128x64
- 1x Rotary Encoder with Switch
- 9x WS2812B-2020 RGB LEDs
- 9x Mechanical Switches
- 9x Rectifier Diodes

**Optional:**
- Enclosure
- Keycaps
- M2 Screws and Spacers

## Assembly Guide

### 1. Soldering the WS2812B-2020 LEDs

Start with the WS2812B-2020 LEDs as they are the only SMD components. We recommend using a heat gun soldering station or heated bed, but you can also use a soldering iron with caution.

**⚠️ IMPORTANT - LED Orientation**

The footprint displayed on the PCB may not match the actual LED orientation (especially for LEDs from AliExpress). You **must** verify the pin alignment with a multimeter before soldering.

![LED Footprint Reference](https://github.com/user-attachments/assets/748cdca5-cc81-4f36-9494-4d9022a87ade)

**Steps:**
1. Take an LED from the strip
2. Use a multimeter to identify each pin connection
3. Confirm the correct orientation with the PCB traces
4. Rotate the LED accordingly before soldering

### 2. Soldering the Diodes

Solder the diodes next, as they become difficult to access after mounting the switches.

**⚠️ Note:** Diodes are polarized! The side with the stripe must be in the correct orientation as marked on the PCB.

### 3. Mounting the OLED Screen and RP2040 Zero

You have two assembly options:

**Option A - Direct Mounting:**
1. Solder the RP2040 Zero first
2. Solder the OLED screen carefully to avoid shorts
3. Trim the pins close to the board

*Result: Screen sits close to the board*

**Option B - Elevated Mounting (Recommended):**
1. Solder 4 female pin headers to the OLED position
2. Cut the headers to appropriate height
3. Solder the RP2040 Zero
4. Mount the OLED on the headers
5. Use M2 spacers and nuts to secure the screen

*Result: Screen sits elevated above the board (looks better and easier to assemble)*

### 4. Remaining Components

Solder the rotary encoder - it only fits one way, making installation straightforward.

**You're done with assembly!** Now proceed to programming.

## Firmware

We use QMK firmware with VIAL integration. You're free to modify the code or create your own implementation.

### Quick Setup (Pre-Assembled Units)

If you bought a pre-assembled Tofu-Zero and just want to configure the keys and LEDs:

1. **Install VIAL** from [https://get.vial.today/](https://get.vial.today/)
2. Plug in your keyboard - it should be automatically detected by VIAL
3. Use the VIAL interface to:
   - Remap any key on any layer
   - Configure LED lighting effects
   - Adjust encoder behavior
   - Set up macros

No firmware flashing required!

### Flashing the Firmware

#### Prerequisites

1. **Install QMK MSYS** from [https://msys.qmk.fm/](https://msys.qmk.fm/)
2. Follow the [QMK Setup Guide](https://qmk.fm/guide) for proper installation

#### Compilation and Flashing

1. Download the project files from the repository
2. Navigate to the correct folder in your QMK/VIAL directory
3. Compile the firmware:

```bash
qmk compile -kb minimini -km vial
```

4. Enter bootloader mode on your RP2040:
   - Hold the BOOT button on the RP2040
   - While holding, plug it into your computer
   - Keep holding for a moment after connecting
   - The device should appear as a drive on your PC

5. Copy the compiled file:
   - Locate `minimini_vial.uf2` in your VIAL root folder (typically `C:\Users\User\vial-qmk`)
   - Drag and drop it to the RP2040 drive

**Done!** Your Tofu-Zero is now programmed.

## Customizing the OLED Animation

The firmware currently supports 7 frames for the OLED animation. You can customize the displayed GIF by changing the bit array for each frame.

### Steps to Change the GIF

1. **Prepare your image:**
   - Use an image with mainly one color for best results
   - Convert to 64x64 pixels using [ezgif.com](https://ezgif.com)
   - Split the GIF into individual frames

2. **Convert frames to code:**
   - Go to [image2cpp](https://javl.github.io/image2cpp/)
   - Upload each frame
   - Settings:
     - Black background
     - Code output format: "Plain bytes"
     - Draw mode: "Vertical"
     - Color depth: 1 bit per pixel
   - If the image appears incorrect after uploading, try changing the draw mode

3. **Update the firmware:**
   - Replace the bit arrays in the firmware code with the output from image2cpp
   - Recompile and flash the updated firmware

## Electrical Schematic

![Circuit Diagram](https://github.com/user-attachments/assets/428d17b6-ffaf-4d72-b75a-794e290490d2)

![PCB Layout](https://github.com/user-attachments/assets/e1d5e043-dcdf-40a2-8cfe-6a1a88485f12)

## Additional Files

All project files, including PCB design files, firmware source code, and 3D models for the enclosure, can be found in the repository.

## Contributing

Contributions are welcome! Feel free to:
- Submit bug reports
- Propose new features
- Submit pull requests with improvements

## License

This project is open source. Please check the LICENSE file for details.

## Support

For questions, issues, or suggestions, please open an issue in the repository.

---

**Enjoy your Tofu-Zero macro keyboard!**
