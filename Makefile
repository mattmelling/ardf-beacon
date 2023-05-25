UPLOAD_PORT ?= /dev/ttyUSB0

upload:
	pio run --target upload --upload-port ${UPLOAD_PORT}
