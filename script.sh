docker build . --tag crazyflie-firmware --network host
docker run -it --privileged -v /dev:/dev crazyflie-firmware
