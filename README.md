# Simple_Shell

<img src="https://lh3.googleusercontent.com/4CPStcWGKXIBEPt57tx_5siuQXaBeDHLT07PZ84HtVmew_7dafivfVf0SLy_0381qzFSFs2_Iq0v5UUaSFgyQcVbBxeF07oQF388bTaXIveKvdMndGpHgr5ksuheGA-v5cz8vNsWow-bXjkVWHtyi95CLV_FznBcmGzrmySsI0RmuxGQK-yC3fzqnCyCOF4cYHyLnWn3XAtiEzLyLQmLPBA51Kr9HJaN8ZxgMW7FyaZLtUwpXhRmdDhYmRBM5rFnDO6kzC7-AWD4P0Vx9L3RbjTY5ZulJyxpm7Apr-hMlRvy4RAb6DPvulfNdHWL3d1IOrUvgv8qgpEHdRRrXMKvTA04HpFODx7sWlRDm6GJC50DWI-_-Bc7EGr4Mxvsmq6V3m75Og00B0hRfKIEtlEEykUUs7R_dFIYjnz27YMc01APcxNyEcJfIWcyQyx3mNOTH7UkpQqV3x70RSWozLDn1tIXCM-UZp2PVA_nLx61vCdktV5bUtK6utIhvuWewjOEa0BMv2CKkiz-9QpOLVsXeV9xpuAdZKOKb2RHVdd1NKGH32qMLOZBoqInba6UOwiLDs86734Ka1vVH_3gqUjG47hStIEovr7AI0Zy1SwWRN_9yqFasbKELzQoQffXxJoTKL3f-cFKXnRUPje5czOemJOERIK6vhAfI4oDDecQbWmXbH2F-4nuYj-aAH_MgA00cVF8wlIeSoneu5Q4nBBNkw=s260-no?authuser=4">

> A simple UNIX command interpreted made by two mad guys.

---

### Table of Contents
Quick acess to

- [Description](#description)
- [How To Use](#how-to-use)
- [References](#references)
- [License](#license)
- [Author Info](#author-info)

---

## Description

First of all, a Shell in computing, is a computer program wich exposes an operating system's services to a human user or another program. In general, operating system shells use either a command-line inferface (CLI) or graphical user inferface (GUI), depending on computer's role and particular operation. It is named a shell because it is the outermost layer around the operating system.

We used Bash as our Shell father to execute our own Shell program made in C. Our Shell can handle those following tasks:
- Start reading a file  with:
    >[filename] ./hsh
- Start by 'echo' output:
    > echo "/bin/ls" | ./hsh
- Uses the PATH environment variable
- Built-ins commands
- Special characters like:
    > ", ', `, \, *, &, #
- Commands with arguments
- Exit built-in with arguments
- Ctrl+C shortcut
- View, Set and Unset environmental variables
- cd command
- ; command separator

#### Technologies

- Bash
- C

[Back To The Top](#Simple_Shell)

---

## How To Use

#### Installation
Clone this repository:
```bash
    git clone [this repository link]
```
And execute the following file:
```bash
    ./hsh
```
Now you will see this:

<img src="https://lh3.googleusercontent.com/RZkm-RjhRHeYQrqo6cZNO2K1tGKZ8eQhXJH4XUDThGEd8gtIEnrdK9EGgiy84PWFJ3anj6EJvzfBNQ-GfusAUpTCwzaD_ZoSRRlkr5s1Obc4tBOzevYf_4LTXKPyG6Gm2XeuJWmOtBG8y51tO0leBj5Yw6Z8Uu1cnDTUAq2ToB7vM7dSibl-PFVjiDPYyZwEf-32kgxCkrpQpI3ak1U-GRJjPq8gC0SafMV_8aACmoEhoWJapGk9W11644DMsIEsg3VFh7GjV29nu8M0BmOFxhaBf7wyQkYFkyGgfLomz3Q2RF2of-s44TufrzbOIn-yYHgZVcRV5MzWjTH6erXNxmD440A4uKhv-KfS1NyOOPgiqC8_GXLk46tMKY67PDYdjPIwev9ysHbEEabtHOf11J0A33KL5Og6NA6LwtzYJ4aZNwDOg3Nax0x-RqJDmk-k7FqAX1q4ROLT16w1OswFkSmU7nWpNC-JctIqGJN1MFTDWEbq5hQpq420prpMizqkG8enDcgvm0uR-DimLZLn7hq4kSWEJZZ6Xm1Ql9NvILC5fZ3m7VoSSwk-NwsLS1u2EF9Gvs7Gui9wA-J4zDAZA3EpNGSvhy275J3jK55VhDCAFfRE6R8Clz8YxVpB4vqp2nY3QrXpmmYXvPOd-1Wlix9u8Rwdqq1TTQin_2hRMEHriiRlF3HUOY_IZ86WWGUmdm-lF5Mj4vDYxDIuopYI5g=w252-h96-no?authuser=4">

Great! that means you done everything right.

[Back To The Top](#Simple_Shell)

---

## References
[Wikipedia - Shell](https://en.wikipedia.org/wiki/Shell_(computing))


Man pages

- [getline()](https://man7.org/linux/man-pages/man3/getline.3.html)
- [isatty()](https://man7.org/linux/man-pages/man3/isatty.3.html)
- [open()](https://man7.org/linux/man-pages/man2/open.2.html)
- [read()](https://man7.org/linux/man-pages/man2/read.2.html)
- [fork()](https://man7.org/linux/man-pages/man2/fork.2.html)

Several google reserches...

---

## License 

MIT License

Copyright (c) [2021] [Hernan Montenegro, Tomas Martinez]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

[Back To The Top](#Simple_Shell)

---

## Author Info
Hernan Montenegro
- itch.io - [DreadZitoDev](https://dreadzitodev.itch.io)
- Twitch Game Development Streams - [DreadZitoDev](https://dreadzitodev.itch.io)
- Website - comming soon...

Tomás Martínez
- With love

[Back To The Top](#Simple_Shell)
