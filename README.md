# QtImageProcessor
QtImageProcessor is a simple image processing app that allows to modify intensities of RGB<br>
colors of pixels in an image.The intesities of RGB colors (Red, Green, Blue) can be increased<br>
or decreased to reflect the effect in the image uploaded by the user.

# FEATURES
QtImageProcessor allows to increase or decrease the intensities of constituents colors of pixels <br>
from (0 - 255).<br>
 - upload your own image<br>
 - increase or decrease the intensity of Red color<br>
 - increase or decrease the intensity of Green color<br>
 - increase or decrease the intensity of Blue color<br>
 - save your image after enhancement<br>
# REQUIREMENTS
1. Qt 6.4.2<br>
2. meson 1.3.2<br>
3. ninja 1.11.1<br>
# CONFIGURATION
  The configuration steps in this README file are for Ubuntu 22.04.However these steps should be similar<br>
  for all Debian Distros.You can also set up this application in othre Linux distrosWindows/Mac or others by<br>
  fulfilling the requirements listed above.<br>
  1.Install Qt.<br>
  
    sudo apt update
    sudo apt install qt6-tools-dev
  2.Install meson and ninja <br>

    sudo apt install meson ninja-build 
  3.Clone this repository<br>
  
    git clone https://github.com/slackup1719/QtImageProcessor.git
    cd QtImageProcessor
  
  5.Initialize the build by going into the source directory and issuing the following commands.<br>

    meson setup builddir
  6.Now we are ready to build our code.<br>

    cd builddir
    meson compile
  7. Once the executable is built we can run it.<br>
  
    ./QtImageProcessor
# START GUIDE
You can now use QtImageProcessor to enhance your images' color intensity.<br>
