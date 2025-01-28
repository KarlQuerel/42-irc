<a id="top"></a>

# ft_irc
`ft_irc` is a lightweight Internet Relay Chat (IRC) server implementation. It adheres to the IRC protocol as defined in [RFC 1459](https://datatracker.ietf.org/doc/html/rfc1459), providing essential features for real-time communication between clients. Designed with simplicity and efficiency in mind, it allows multiple users to connect, exchange messages, and participate in channels seamlessly.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)

## Introduction
The project implements a functional IRC server, enabling clients to communicate in real time. The server supports standard IRC commands, multi-client connections, and basic authentication. It focuses on providing a modular, scalable, and efficient solution for text-based communication.

A bot feature is also included, offering additional automation capabilities.

## Features
- **Multi-client Support:** Manages concurrent client connections via sockets.

- **Message Broadcasting:** Delivers messages to all participants within a channel.

- **IRC Command Handling:** Implements commands like `JOIN`, `KICK`, `PRIVMSG`, `NICK`, `QUIT`, etc...

- **Channel Management:** Facilitates creation, joining, and leaving of communication channels.

- **Authentication:** Ensures secure client-server interaction through password-protected access.

- **Bot:** An automated bot providing additional functionalities such as responding to specific commands or interacting with users in channels.

## Technologies Used

### Programming Language
- **C++:** Utilized for its performance and control over system-level operations.

### Libraries
- **Socket API:** Manages network communication.
- **Standard Template Library (STL):** Handles data structures and algorithms.

### Development Tools
- **Make:** Automates the build process.

## Installation
1. Clone this repository to your local machine:
	```sh
	git clone https://github.com/KarlQuerel/42-irc.git
	cd 42-irc
	```

2. Navigate to the project directory and compile the corresponding component:

- For the server:
	```sh
	cd IRC
	make
	```

- For the bot:
	```sh
	cd Bonus
	make
	```
3. Run the server:
	```sh
	./ircserver <port> <password>
	```
- `<port>`: port number (e.g., 1200).
- `<password>`: server password for client connections.
4. Run the bot
	```sh
	./ircbot localhost <port> <password>
	```

## Usage
### Connecting to the Server
To connect to the IRC server, use any IRC client such as irssi:

1. Open the IRC client.

2. Connect using the command:

	```sh
	/connect localhost <port> <password>
	```
### Bot Animation
Once the bot is running, join the bad_apple_bot channel:

```sh
/join bad_apple_bot
```
Then run:

```sh
!apple
```

For more information, refer to the [subject PDF](https://github.com/KarlQuerel/42-irc/blob/main/docs/en.subject.pdf).

[Back to Top](#top)