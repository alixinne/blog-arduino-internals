# blog-arduino-internals

This repository contains the source code for the analysis detailed in the blog
article
http://vtavernier.github.io/posts/arduino-internals-whats-behind-the-magic/.

The detailed report is published at
https://vtavernier.github.io/blog-arduino-internals/.

## Usage

Install dependencies:

	# PlatformIO
	pip install --user platformio
	
	# Page generation dependencies
	pip install -r requirements.txt

Generate the report:

	make

## Details

This repository is a single PlatformIO project with three defined environments:
* [`arduino`](src/arduino): compiles the example program using the Arduino
  framework primitives.
* [`avr`](src/avr): equivalent program, only using AVR primitives.
* [`template`](src/template): a proof of concept C++ template-based wrapper for
  implementing the same program, but in a way that can be optimized by
  `avr-gcc`.

The goal of the `template` variant is to generate the same code as the `avr`
variant, but with the same readability as the `arduino` variant.

## Author

Vincent Tavernier <vince.tavernier@gmail.com>
