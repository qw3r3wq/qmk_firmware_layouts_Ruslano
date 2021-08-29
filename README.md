# qmk_firmware keymaps Made by Ruslanas
## JJ40
[JJ40 keymap.c](keyboards/jj40/keymaps/Ruslano/keymap.c)
### Parts
 - PCB https://www.aliexpress.com/item/32828781103.html
 - Plate https://www.aliexpress.com/item/1005001627320105.html
 - CASE https://www.aliexpress.com/item/1005001390320865.html
### Build
```
qmk compile -kb jj40 -km Ruslano
qmk flash -kb jj40 -km Ruslano
```
### Troubleshooting
[Troubleshooting/tmk_core_rules.mk.patch](Troubleshooting/tmk_core_rules.mk.patch) File might be needed to apply to Debian based distros, to be able to compile.
Without it was receiving size-check error.
## ErgoTravel V1.03
[ErgoTravel V1.03](keyboards/ergotravel/keymaps/Ruslano/keymap.c)
### Parts
 - https://mechboards.co.uk/shop/kits/ergotravel-kit/
 - Halo True From MassDrop https://drop.com/buy/drop-halo-switch-pack
 - Keycaps
   - DROP + MATT3O MT3 /DEV/TTY KEYCAP SET 1800 Kit https://drop.com/buy/drop-matt3o-mt3-dev-tty-keycap-set - Based on the profile from the iconic IBM® beamspring terminals of the 1970s
   - Elfish Numpad https://drop.com/buy/matt3o-nerd-dsa-keycap-set-massdrop-exclusive
### Build
```
qmk compile -kb ergotravel/rev1 -km Ruslano
qmk flash -kb ergotravel/rev1 -km Ruslano
```
# Links
 - https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/mod_tap
 - https://github.com/qmk/qmk_firmware/issues/714
 - https://github.com/algernon/ergodox-layout#tools
