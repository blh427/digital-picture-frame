This is a digital picture frame project based upon a description at this web-site:

https://spectrum.ieee.org/geek-life/hands-on/build-the-ultimate-digital-picture-frame

I started out with an Adafruit breakout board for the Avago APDS9960 Gesture Sensor:
- Adafruit item number 3595

1. I tried to use a port of the Sparkfun software for their version of
the breakout but could not get the gesture detection capability to
work. The port of the Sparkfun software is available via the web site
above.

2. Next, I ported over Adafruit's Arduino code. That seems to work OK.

----

As of today (1/1/2018), the state of the project is as follows:

1. Installed the latest copy of Raspbian on the Raspberry Pi.

2. Installed Kodi and various updates. Played with Kodi enough to see
how it works.

3. Ported the Adafruit 9960 code. The results of this work are in the
directory (Adafruit_APDS9960-master) (the original zip file is there
as well). I used both the Adafruit code and the ported Sparkfun code
to port the Adafruit code. The other directory
(apds-9960-raspberry-pi-library) is the ported Sparkfun code that I
may have modified it here or ther while I was trying to get it to
work. Look in the makefile to see how to build things and to see what
is available. Three executables can be built (gesture_sensor,
color_sensor, proximity_sensor). I have played with gesture_sensor the
most though the other programs seemed to behave somewhat
appropriately.

---

Next Steps.

1. Get the gesture interrupt working.

2. Finish up the overall code for the 9960 sensor.

---

Overall System Design

Here is the general strategy for the entire picture frame project.

1. Pictures will be hosted in a directory on a dazoo server accessible
via sftp.

2. A cron job will rsync this directory with a picture directory on
the Raspberry Pi.

3. The gesture sensor will allow the viewer to scroll through pictures
using the xbmc (kodi) interface (http://kodi.wiki/view/List_of_built-in_functions).

4. Photos will be organized by year, with each year represented as a directory
that contains all photos for a given year. To start a slide show for a given year,
use the kodi SlideShow function.

This will need to be refined a bit but this is the general strategy.
