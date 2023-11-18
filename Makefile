compile:
	arduino-cli compile -b arduino:avr:uno \
		--build-property "compiler.cpp.extra_flags=-Wall -Werror -pedantic" \
		serial-json-data/serial-json-data.ino

upload: compile
	arduino-cli upload -v -p /dev/ttyACM0 -b arduino:avr:uno \
		serial-json-data/serial-json-data.ino

realtime-plotjuggler:
	@cat /dev/ttyACM0 | nc -u localhost 9871
