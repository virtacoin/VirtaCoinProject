
Debian
====================
This directory contains files used to package virtacoind/virtacoin-qt
for Debian-based Linux systems. If you compile virtacoind/virtacoin-qt yourself, there are some useful files here.

## virtacoin: URI support ##


virtacoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install virtacoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your virtacoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/virtacoin128.png` to `/usr/share/pixmaps`

virtacoin-qt.protocol (KDE)

