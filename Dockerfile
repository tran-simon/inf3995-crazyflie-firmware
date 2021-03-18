FROM ubuntu:18.04
LABEL Maintainer="Pierre-Yves Lajoie <pierre-yves.lajoie@polymtl.ca>"
LABEL crazyflie-firmware.version="0.1"


# Install common dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    dpkg \
    git \
    pkg-config \
    python \
    python3 \
    python-dev \
    python-numpy \
    sudo \
    software-properties-common \
    make \
    rake \
    && rm -rf /var/lib/apt/lists/*

# Install crazyflie dependencies
RUN add-apt-repository ppa:team-gcc-arm-embedded/ppa && apt-get update && apt-get install -y \
	gcc-arm-embedded \
	usbutils \
	python3-pyqt5 \
	python3-venv \
	python3-pip


WORKDIR /root

#################################
#          YOUR CODE            #
#################################

ARG UPDATE_CODE=unknown

RUN git clone --depth 1 --branch 2021.01 --recurse-submodule https://github.com/bitcraze/crazyflie-firmware.git

COPY . crazyflie-firmware

RUN git clone --depth 1 --branch 2021.1 https://github.com/bitcraze/crazyflie-clients-python.git

COPY clientSetup.py crazyflie-clients-python/setup.py

RUN cd crazyflie-clients-python &&\
	python3 -m pip install -e .


WORKDIR /root/crazyflie-firmware/inf3995-firmware

#RUN make
