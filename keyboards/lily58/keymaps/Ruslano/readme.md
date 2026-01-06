# Ruslano layout for Lily58

## Features

- Layer on the left OLED

### TODO

- Optimise for lithuanian layout, but works on English too - TODO
- Numpad on Lower layer for left hand
- Navigation, media keys on Raise layer for left hand

## Instructions
Status is always on the left the keymap has to be flashed with different commands:

```bash
# Right hand
qmk flash -kb lily58/rev1 -km Ruslano -bl avrdude-split-left
# Left hand
qmk flash -kb lily58/rev1 -km Ruslano -bl avrdude-split-right
```
