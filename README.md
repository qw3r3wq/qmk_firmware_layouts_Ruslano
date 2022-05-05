# qmk_firmware keymaps Made by Ruslanas G.
## JJ40
[JJ40 keymap.c](keyboards/kprepublic/jj40/keymaps/Ruslano/keymap.c)

### Parts
 - PCB - https://www.aliexpress.com/item/32828781103.html
 - Plate - https://www.aliexpress.com/item/1005001627320105.html
 - CASE - https://www.aliexpress.com/item/1005001390320865.html
 - O Rings - https://www.aliexpress.com/item/32960842413.html
 - Cable https://www.aliexpress.com/item/4001093673456.html
 - Keycaps - Red - https://www.aliexpress.com/item/1005003107660652.html
 - Switches - Kailh plum - https://www.aliexpress.com/item/32909066772.html

### Build
```
qmk compile -kb kprepublic/jj40 -km Ruslano
qmk flash -kb kprepublic/jj40 -km Ruslano
```

### Troubleshooting
[Troubleshooting/tmk_core_rules.mk.patch](Troubleshooting/tmk_core_rules.mk.patch) File might be needed to apply to Debian based distros, to be able to compile.
Without it was receiving size-check error.

## ErgoTravel V1.03
[ErgoTravel V1.03 keymap.c](keyboards/ergotravel/keymaps/Ruslano/keymap.c)

Big Thanks goes to [/u/jpconstantineau](https://www.reddit.com/user/jpconstantineau) for designing it in a first place! You can find Build doc [here](https://github.com/jpconstantineau/ErgoTravel/)
### Parts
 - https://mechboards.co.uk/shop/kits/ergotravel-kit/
 - Halo True From MassDrop https://drop.com/buy/drop-halo-switch-pack
 - Keycaps
   - DROP + MATT3O MT3 /DEV/TTY KEYCAP SET - 1800 Kit https://drop.com/buy/drop-matt3o-mt3-dev-tty-keycap-set - Based on the profile from the iconic IBM® beamspring terminals of the 1970s
   - MATT3O NERD DSA KEYCAP SET - Elvish Numpad Kit https://drop.com/buy/matt3o-nerd-dsa-keycap-set-massdrop-exclusive
 - O Rings - https://www.aliexpress.com/item/32960842413.html

### Build
```
qmk compile -kb ergotravel/rev1 -km Ruslano
qmk flash -kb ergotravel/rev1 -km Ruslano
```

## XD75AM
[XD75AM keymap.c](keyboards/xiudi/xd75/keymaps/Ruslano/keymap.c) ![](https://us-central1-progress-markdown.cloudfunctions.net/progress/10)
### Parts
 - PCB - https://www.aliexpress.com/item/32831044551.html
 - Plate - https://www.aliexpress.com/item/32831072285.html
 - Keycaps Taihao Red&Grey - https://www.aliexpress.com/item/32817324969.html https://ae01.alicdn.com/kf/HTB1MbCiRVXXXXcTXpXXq6xXFXXXC.jpg
 - Case - https://www.aliexpress.com/item/1005001798968638.html
 - Switches - Matias Quiet Click - https://www.keyboardco.com/product/matias-quiet-click-key-switch-modules-x-200.asp

### Build
```
qmk compile -kb xiudi/xd75 -km Ruslano
qmk flash -kb xiudi/xd75 -km Ruslano
```

# Links
 - https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/mod_tap
 - https://github.com/qmk/qmk_firmware/issues/714
 - https://github.com/algernon/ergodox-layout#tools
 - https://github.com/qmk/qmk_firmware/tree/master/docs
   - https://docs.qmk.fm/#/feature_layers
   - https://github.com/qmk/qmk_firmware/blob/master/docs/ref_functions.md
   - https://docs.qmk.fm/#/newbs_building_firmware
   - https://config.qmk.fm/#/lily58/rev1/LAYOUT
 - https://docs.qmk.fm/#/newbs_building_firmware
