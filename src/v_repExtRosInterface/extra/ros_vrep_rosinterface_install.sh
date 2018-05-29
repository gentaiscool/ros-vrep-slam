#!/bin/bash

set -e

mkdir -p ~/Downloads

ARCH="$(uname -m)"

if [[ "$ARCH" != "x86_64" ]]; then
	echo "error: this script is for 64-bit machines" 2>&1
	exit 1
fi

echo "Installing some required Ubuntu packages... (may ask password for sudo apt-get)"
sudo apt-get install -y ros-kinetic-desktop-full git cmake python-tempita python-catkin-tools python-lxml default-jre >/dev/null

while true; do
	read -p "Where do you want to install V-REP? [$HOME] " VREP_DESTDIR
	if [[ "$VREP_DESTDIR" = "" ]]; then
		VREP_DESTDIR="$HOME"
	fi
	if [[ -d "$VREP_DESTDIR" ]]; then
		break
	else
		echo "error: $VREP_DESTDIR does not exist or it is not a directory" 1>&2
	fi
done

VREP_RELEASE="V-REP_PRO_EDU_V3_3_2_64_Linux"
VREP_ROOT="$VREP_DESTDIR/$VREP_RELEASE"

if [[ -d "$VREP_ROOT" ]]; then
	echo "V-REP appears to be already installed in $VREP_ROOT. Skipping installation..."
else
	if [[ -f "$HOME/Downloads/$VREP_RELEASE.tar.gz" ]]; then
		echo "V-REP appears to be already downloaded. Skipping download..."
	else
		echo "Downloading $VREP_RELEASE..."
		cd ~/Downloads
		wget -q "http://coppeliarobotics.com/files/$VREP_RELEASE.tar.gz"
	fi
	echo "Installing $VREP_RELEASE..."
	cd "$VREP_DESTDIR"
	if ! tar zxf "$HOME/Downloads/$VREP_RELEASE.tar.gz" &>/dev/null; then
		rm -rf "$VREP_ROOT"
		echo "error: V-REP failed to unpack (corrupted download?)"
		echo "Try deleting $HOME/Downloads/$VREP_RELEASE.tar.gz and try again."
		exit 1
	fi
fi

if grep -q export.VREP_ROOT=.*$VREP_ROOT ~/.bashrc; then
	echo "Your ~/.bashrc appears to already contain VREP_ROOT"
else
	echo "Updating ~/.bashrc with VREP_ROOT path..."
	echo "export VREP_ROOT=\"$VREP_ROOT\"" >> ~/.bashrc
fi

SAXON_BIN="$(which saxon 2>/dev/null || true)"
if [[ -x "$SAXON_BIN" ]]; then
	echo "Saxon appears to be already installed. Skipping installation..."
else
	if [[ -f "$HOME/Downloads/SaxonHE9-7-0-8J.zip" ]]; then
		echo "Saxon appears to be already downloaded. Skipping download..."
	else
		echo "Downloading Saxon XSLT Processor..."
		cd ~/Downloads
		wget -q http://downloads.sourceforge.net/project/saxon/Saxon-HE/9.7/SaxonHE9-7-0-8J.zip
	fi

	echo "Installing Saxon..."
	mkdir -p ~/saxon/bin
	cd ~/saxon
	unzip -q ~/Downloads/SaxonHE9-7-0-8J.zip
	echo -e '#!/bin/sh\njava -jar "`dirname "$0"`/../saxon9he.jar" "$@"' > bin/saxon
	chmod a+x bin/saxon
	echo 'export PATH="$PATH:$HOME/saxon/bin"' >> ~/.bashrc
	export PATH="$PATH:$HOME/saxon/bin"
fi

if [[ -d ~/python-packages/v_repStubsGen ]]; then
	echo "v_repStubsGen appears to be already installed. Skipping installation..."
else
	echo "Installing v_repStubsGen..."
	mkdir -p ~/python-packages
	cd ~/python-packages
	git clone -q https://github.com/fferri/v_repStubsGen.git
	echo 'export PYTHONPATH="$PYTHONPATH:$HOME/python-packages"' >> ~/.bashrc
	export PYTHONPATH="$PYTHONPATH:$HOME/python-packages"
fi

if [[ -d ~/catkin_ws ]]; then
	CATKIN_WS_BACKUP="$HOME/catkin_ws.bak"
	CATKIN_WS_BACKUP_SEQ=0

	while [[ -d "$CATKIN_WS_BACKUP-$CATKIN_WS_BACKUP_SEQ" ]]; do
		CATKIN_WS_BACKUP_SEQ=$((CATKIN_WS_BACKUP_SEQ+1))
	done

	mv ~/catkin_ws "$CATKIN_WS_BACKUP-$CATKIN_WS_BACKUP_SEQ"
	echo "Old catkin workspace (~/catkin_ws) has been moved to $CATKIN_WS_BACKUP-$CATKIN_WS_BACKUP_SEQ"
fi

echo "Initializing catkin workspace..."
source /opt/ros/kinetic/setup.bash
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/src
catkin_init_workspace >/dev/null
cd ..
catkin build --no-status --no-notify --no-summary >/dev/null
source devel/setup.bash
echo "Installing v_repExtRosInterface..."
cd ~/catkin_ws/src
git clone -q https://github.com/fferri/v_repExtRosInterface.git vrep_ros_interface
cd ..
echo "Building..."
catkin build --no-status --no-notify --no-summary >/dev/null
echo "Installing RosInterface plugin..."
cp -iv devel/lib/libv_repExtRosInterface.so "$VREP_ROOT/"
echo "Finished"

