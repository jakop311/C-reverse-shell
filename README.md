# C-reverse-shell

### Info

A simple reverse shell for Windows written in C with Visual Studio 2022.  

The target machine is **Windows** and the attack machine is **Linux**.  
For mine, it was Windows 11 - Ubuntu 20.04

### How to

1. Clone the repository on Visual Studio
```
https://github.com/jakop311/C-reverse-shell.git
```
2. Change the IP_ADDRESS to your Attack Machine

3. Change the LISTENING_PORT to the port you will listen on your Attack Machine

4. Build it

5. Setup netcat on your Attacking Machine
```
nc -lnvp LISTENING_PORT
```
6. Run the reverse shell program
