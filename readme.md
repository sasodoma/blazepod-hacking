# How to connect manually
This was performed using an nRF52840 Dongle and nRF Connect Desktop BLE app

1. Find your device by scanning
1. The advertisement details contain **ManufacturerSpecificData**
    - For example: `D7-09-5A-01-DE-AD-BE-EF`
1. Use last 5 bytes to calculate the checksum using **main.c**
    - In the above example the `offset` is `0x01` and `byte_array` is `{0xDE, 0xAD, 0xBE, 0xEF}`
    - I run **main.c** in [GDB online Debugger](https://www.onlinegdb.com/)
    - The output is 7 bytes, the first 3 are fixed and the rest is calculated
1. On connect send the 7 bytes of data to UART RX characteristic (`6e400002-b5a3-f393-e0a9-e50e24dcca9e`) in UART service (`6e400001-b5a3-f393-e0a9-e50e24dcca9e`)
1. Set color using characteristic `50c912a2-4cb8-4c84-b745-0e58a0280cd6` in service `50c97bfa-4cb8-4c84-b745-0e58a0280cd6`
    - B G R format, fourth byte is optional - `0x01` makes it turn off on tap
1. Receive tap by subscribing to characteristic `50c9727e-4cb8-4c84-b745-0e58a0280cd6` in service `50c928bd-4cb8-4c84-b745-0e58a0280cd6`
    - I don't know what the format for this message is but the value changes on every tap
  
# Disclaimer
This project is not affiliated with, endorsed by, or supported by PLAY COYOTTA LTD or BlazePod. BlazePod® is a registered trademark of PLAY COYOTTA LTD. All trademarks, service marks, and company names mentioned are the property of their respective owners. This software is provided as-is, and the use of this software is at your own risk.
