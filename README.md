# Mini_talk

This repository is part of the 42 Cursus. It contains the implementation of Mini_talk, a project designed to handle inter-process communication (IPC).

## Table of Contents
- [Project Overview](#project-overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## Project Overview
Mini_talk is a simple project that demonstrates inter-process communication between a server and a client using Unix signals. The server waits for messages from the client, and the client sends messages to the server to be displayed.

## Features
- Server-client communication using Unix signals
- Simple and efficient message handling
- Error handling for signal operations

## Installation
To install and set up the project locally, follow these steps:

1. Clone the repository:
    ```sh
    git clone https://github.com/elkadirianas/Mini_talk.git
    ```
2. Navigate to the project directory:
    ```sh
    cd Mini_talk
    ```
3. Compile the project:
    ```sh
    make
    ```

## Usage
To run the server:
```sh
./server
```
To run the client and send a message to the server:
```sh
./client <server_pid> <message>
```

## Example
1. Open a terminal and start the server:
    ```sh
    ./server
    ```
   The server will display its PID.

2. Open another terminal and run the client with the server's PID and a message:
    ```sh
    ./client 12345 "Hello, server!"
    ```
   Replace `12345` with the actual PID of the server. The server will display the received message.

## Contributing
Contributions are welcome! Please follow these steps to contribute:

1. Fork the repository.
2. Create a new branch:
    ```sh
    git checkout -b feature/your-feature-name
    ```
3. Make your changes and commit them:
    ```sh
    git commit -m "Add some feature"
    ```
4. Push to the branch:
    ```sh
    git push origin feature/your-feature-name
    ```
5. Open a pull request.
