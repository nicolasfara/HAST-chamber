# Electronics

KiCad project for the HAST chamber control board, targeting JLCPCB fabrication.

| File                     | Content                                      |
|--------------------------|----------------------------------------------|
| `hast-chamber.kicad_pro` | KiCad project                                |
| `hast-chamber.kicad_sch` | Schematic                                    |
| `hast-chamber.kicad_pcb` | PCB layout                                   |
| `hast-chamber.kicad_dru` | JLCPCB design rules ([source][design-rules]) |

## CI

Every push exports the schematic PDF, Gerbers/drill files and a PCB render.
To enforce ERC and DRC, set `run_erc` and `run_drc` to `true` in
[`.github/workflows/electronics.yml`](../.github/workflows/electronics.yml).

[design-rules]: https://github.com/labtroll/KiCad-DesignRules
