# Simple_Shell

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
    >./hsh [filename] 
- Start by 'echo' output:
    > echo "/bin/ls" | ./hsh
- Uses the PATH environment variable
- Built-ins commands
- Special characters like:
    > ", ', \, |, &, #
- Commands with arguments
- Exit built-in with arguments
- Ctrl+C shortcut
- View, Set and Unset environmental variables
- cd command
- ; command separator
- help built-in command

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

<img src="https://lh3.googleusercontent.com/UD8tua2RoUv6y3fSukQWzvD4pCXIg5Xj34VfjldXjPM4dlYDHhvbUrFhCV7aXsUOWTqSIOmBcWNe3-CFC2w1wDffHZ6AYLbx5SwyUe6N0WmmAJgXNVDVxnik-NxfRsWjcTWA6QulVj6U57uk9FR-ffmc-WCaqqWnJDp_rooFXH9J7rNavKTjGO1ODGooRuvriDTksOpz4hfgNv0AAuRSoNkFxFStxokf2lCE82YnfEWSLOP-zGRXThRvjb7mnwzcqAkgETTcMAR5H9-E483lH23tDJ1JHlxJKE4HxorKlNo29bD7IT1odasb1IWqdHbnZE4ORo_9oiPEJziZHOxWfxrfAXNIKX5IOGzIVn1FZbgdUHtEmOzgblvI5ImuX9DTfTgygupDvtYM8QjoulO7fmQMnZZrOcFlID2aoVbX7hA0snK8xrP-ldm1TAFnHBkk3wSKEw3g04gyoRx1s_hBfhA67sLqr_J6dgUuUu3msmUJXMPeJEcDL6jiUbfYiYXrpinKSGoh4flRf1uaELRUA2AliaO7gqNULRsgra2mgSIHJr397EqHgTLu73a7YEAB832fD0XmaX6UAX7r0VxE9ChnCDoDAQUHFxg3R_oPmBtxlBiYLJXLbJBvh2zkA20762DUdLcQLpZXEU_vg1u2nZlik2CKkg4K0u6mVdb44xf3HnGnaGNOjtZFiiNOr5us6ZcILkV3g3uMBIHETd2ZLg=w252-h96-no?authuser=4">

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
Copyright (c) [2021] [Hernan Montenegro, Tomas Martinez]

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
