# Self-recompiling C++ program
Just an idea of how one can write a program that re-compiles itself *ad infinitum*

## Running
```bash
g++ main.cc -o main.run
./main.run
```

## Killing
```bash
# 'head -64' is useful when the program has been left running for too long
ps aux | grep "/tmp/x.run" | head -64 | awk '{print $2}' | xargs kill -9
```
