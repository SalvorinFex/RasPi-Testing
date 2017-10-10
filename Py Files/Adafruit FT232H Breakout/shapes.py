import time

import Adafruit_GPIO.FT232H as FT232H

# Temporarily disable FTDI serial drivers to use the FT232H device.
FT232H.use_FT232H()

# Create an FT232H device instance.
ft232h = FT232H.FT232H()

import Adafruit_Nokia_LCD as LCD
import Adafruit_FT232H as FT232H

from PIL import Image
from PIL import ImageDraw
from PIL import ImageFont

# Temporarily disable FTDI serial drivers to use the FT232H device.
FT232H.use_FT232H()

# Create an FT232H device instance.
ft232h = FT232H.FT232H()

# Create an FT232H SPI object with the specified chip select pin.
ft232h_spi = FT232H.SPI(ft232h, cs=8)

# Create the Nokia display object.
disp = LCD.PCD8544(9, 10, spi=ft232h_spi, gpio=ft232h)

# The code below is exactly the same as the Nokia LCD library's shapes.py example:
  
# Initialize library.
disp.begin(contrast=60)

# Clear display.
disp.clear()
disp.display()

# Create blank image for drawing.
# Make sure to create image with mode '1' for 1-bit color.
image = Image.new('1', (LCD.LCDWIDTH, LCD.LCDHEIGHT))

# Get drawing object to draw on image.
draw = ImageDraw.Draw(image)

# Draw a white filled box to clear the image.
draw.rectangle((0,0,LCD.LCDWIDTH,LCD.LCDHEIGHT), outline=255, fill=255)

# Draw some shapes.
draw.ellipse((2,2,22,22), outline=0, fill=255)
draw.rectangle((24,2,44,22), outline=0, fill=255)
draw.polygon([(46,22), (56,2), (66,22)], outline=0, fill=255)
draw.line((68,22,81,2), fill=0)
draw.line((68,2,81,22), fill=0)

# Load default font.
font = ImageFont.load_default()

# Alternatively load a TTF font.
# Some nice fonts to try: http://www.dafont.com/bitmap.php
# font = ImageFont.truetype('Minecraftia.ttf', 8)

# Write some text.
draw.text((8,30), 'Hello World!', font=font)

# Display image.
disp.image(image)
disp.display()

print 'Press Ctrl-C to quit.'
while True:
	time.sleep(1.0)