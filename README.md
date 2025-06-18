NightWare Zone is an open source C++ project developed for educational purposes.
Its goal is to demonstrate, in a controlled manner, how modern ransomware works: from infection to file encryption and display of the ransom note.

This project should not be used in real systems. Only for academic, research or study purposes in isolated environments.

>[!WARNING]
> The use and execution of this code is the sole responsibility of the user.
We are not responsible for any damage caused.
Run only in virtual environments, without real data, and without an internet connection.



## Features



## initial  Infection :

    Phishing (simulated emails with malicious attachments)

    Exploiting flaws in outdated systems

    Downloading simulated infected files

    Brute force attacks on systems with weak passwords
    
## Execução e persistência:

    escalation of privilege

    lateral network propagation

    Disabling antivirus and firewall

## File encryption:

       Encryption with AES or RSA

       Renaming files with extensions such as .locked or .encrypted

## Ramsom Note:

     Display of message with payment instructions (simulated)

     Countdown to deletion (simulated)

## Project Structure

     NightWareZone/
     ├── src/
     │   ├── main.cpp
     │   ├── encryption.cpp
     │   ├── payload.cpp
     │   └── utils.h
     ├── README.md
    └── LICENSE




## requeriments

     C++17 our better

     Linux, Windows or macOS system

     Virtual machine (recommended: VirtualBox or VMware)
     
## Compilers (exemmplo)

``` g++ src/*.cpp -o nightware -std=c++17 ```







  ## Safe testing

    Use isolated virtual machines

    Preferably offline
 
    Environments such as Cuckoo, REMnux or FLARE-VM are recommended

## License

Code licensed under the MIT License.
Use restricted to legal, educational and research purposes.


