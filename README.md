# Analyze_IR
リモコンの赤外線を解析するよ

コンパイル↓
inputIr.c
gcc inputIr.c -o inputIr -lwiringPi

decodeIr.c
gcc decodeIr.c -o decodeIr

実行↓
./inputIr | ./decodeIr
