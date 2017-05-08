# esp8266-http-led-control
Control ESP8266 (Witty Cloud) integrated RGB led over HTTP

Depends on [platformio](http://platformio.org/)

## Setup

To setup for CLion, run:
```bash
./init.sh
```

After upload to monitor, run:
```bash
./monitor.sh
```


## Development

To build the code, do PLATFORMIO_BUILD build (NOT RUN) on CLion.

To upload the code, do PLATFORMIO_UPLOAD build (NOT RUN) on CLion.

## Essentials

Strictly necessary parts are:
```c++
#include <Arduino.h>

void setup(void) {}

void loop(void) {}

```

and build from there..

Have fun!