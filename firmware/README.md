# Firmware

Firmware for the HAST chamber controller, based on [Zephyr RTOS](https://zephyrproject.org/)
and running on an ESP32-S3.

## Layout

`firmware/` is the [west](https://docs.zephyrproject.org/latest/develop/west/index.html)
workspace; `app/` is the application and the west manifest repository.

| Path                | Content                                                       |
|---------------------|---------------------------------------------------------------|
| `app/west.yml`      | West manifest (Zephyr version and modules)                    |
| `app/CMakeLists.txt`| Application build definition                                  |
| `app/prj.conf`      | Kconfig options shared by all boards                          |
| `app/VERSION`       | Firmware version, exposed as `APP_VERSION_STRING`             |
| `app/src/`          | Application sources                                           |
| `app/boards/`       | Board overlays, or a custom board definition for the HAST PCB |
| `app/tests/`        | Twister test suites, run on `native_sim`                      |

Zephyr, its modules and build outputs are fetched/generated in this folder and gitignored.

## Setup

Install the [Zephyr SDK](https://docs.zephyrproject.org/latest/develop/getting_started/index.html)
(with the `xtensa-espressif_esp32s3_zephyr-elf` toolchain) and `west`, then:

```sh
cd firmware
west init -l app
west update
west packages pip --install
west blobs fetch hal_espressif
```

## Build and flash

```sh
west build -b esp32s3_devkitc/esp32s3/procpu app
west flash
west espressif monitor
```

Run the tests on the host:

```sh
west twister -T app/tests -p native_sim
```

## CI

[`.github/workflows/firmware.yml`](../.github/workflows/firmware.yml) sets up the
west workspace and SDK, builds for the board in the `BOARD` variable, runs Twister if `app/tests/`
exists, and attaches `zephyr.bin`/`zephyr.elf` to the release. Change `BOARD`
when the custom HAST board definition lands in `app/boards/`.
