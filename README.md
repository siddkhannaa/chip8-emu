# 🎱 Emojicode CHIP-8️⃣ Emulator
![chip8logo_console](img/chip8.png) <br>
moob boon <br>
all 35 opcodes are implemented! (wow)

# 🔨 Setup
emojicode is wack and doesn't work on windows so u have to be running macOS or Linux <br>

make sure you have ncurses and tinfo installed on your machine: <br>
```
sudo apt install libncurses5-dev
sudo apt install libcurseesw5-dev
sudo apt install libtinfo-dev
```

ensure you extract the archive files (`.a` files) into  `packages/keyboard/ncurses` and `packages/keyboard/tinfo` for each respective library. This can be done using the following commands: <br>
```
$ ar x /usr/lib/x86_64-linux-gnu/libncurses.a` <br>           
$ ar x /usr/lib/x86_64-linux-gnu/libtinfo.a` <br>
```
(these steps are neccessary so that we can get keyboard input)
