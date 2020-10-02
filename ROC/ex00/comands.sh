sudo apt-get install pulseaudio pulseaudio-module-zeroconf alsa-utils avahi-daemon
sudo modprobe snd-bcm2835                      # load module for single boot
echo "snd-bcm2835" | sudo tee -a /etc/modules  # load module for persistance
sudo vim /etc/pulse/default.pa
load-module module-native-protocol-tcp auth-ip-acl=127.0.0.1;192.168.0.0/16
load-module module-zeroconf-publish
pulseaudio -D
sudo apt-get install pulseaudio-utils
sudo pulseaudio --system 
