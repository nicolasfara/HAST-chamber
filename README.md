# HAST chamber

Open hardware Highly Accelerated Stress Test (HAST) chamber.

## Repository layout

| Folder                          | Component                        | Tooling    |
|---------------------------------|----------------------------------|------------|
| [`cad/`](cad/)                  | Mechanical design                | FreeCAD    |
| [`electronics/`](electronics/)  | Schematic and PCB                | KiCad 9    |
| [`firmware/`](firmware/)        | Controller firmware (ESP32-S3)   | Zephyr RTOS |

Each folder has its own README with details on its contents and workflow.

## CI/CD

| Workflow                 | Purpose                                                  |
|--------------------------|----------------------------------------------------------|
| `dispatcher.yml`         | Entry point; avoids duplicate runs on internal PRs       |
| `check-and-release.yml`  | Runs the component pipelines, then releases on `master`  |
| `electronics.yml`        | KiCad exports (schematic PDF, Gerbers, PCB render)       |
| `firmware.yml`           | Zephyr build + Twister tests (skipped until set up)     |

Every push to `master` creates a release tagged `vYYYY.MM.DD-<sha>` with the
electronics outputs and, once available, the firmware binaries.

## License

[Apache-2.0](LICENSE)
