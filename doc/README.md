VirtaCoin 2.9.0
=====================

Copyright (c) 2014 VirtaCoin Developers


Setup
---------------------
[VirtaCoin Core] is the original VirtaCoin client and it builds the backbone of the network. However, it downloads and stores the entire history of VirtaCoin transactions (which may soon grow to a file size of several GBs); depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more. Thankfully you only have to do this once.

Running
---------------------
The following are some helpful notes on how to run VirtaCoin on your native platform. 

### Unix

You need the Qt4 run-time libraries to run VirtaCoin-Qt. On Debian or Ubuntu:

	sudo apt-get install libqtgui4

Unpack the files into a directory and run:

- bin/32/virtacoin-qt (GUI, 32-bit) or bin/32/virtacoind (headless, 32-bit)
- bin/64/virtacoin-qt (GUI, 64-bit) or bin/64/virtacoind (headless, 64-bit)



### Windows

Unpack the files into a directory, and then run virtacoin-qt.exe.

### OSX

Drag VirtaCoin-Qt to your applications folder, and then run VirtaCoin-Qt.


Building
---------------------
The following are developer notes on how to build VirtaCoin on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [OSX Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-msw.md)

Development
---------------------
The VirtaCoin repo's [root README](https://github.com/virtacoin/VirtaCoinProject/blob/master/README.md) contains relevant information on the development process and automated testing.

- [Coding Guidelines](coding.md)
- [Multiwallet Qt Development](multiwallet-qt.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Translation Process](translation_process.md)
- [Unit Tests](unit-tests.md)

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [Files](files.md)
- [Tor Support](tor.md)

License
---------------------
Distributed under the [MIT/X11 software license](http://www.opensource.org/licenses/mit-license.php).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](http://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
