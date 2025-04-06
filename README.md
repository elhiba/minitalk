<p align="center">
	<img src=".badge/minitalkm.png"/>
</p> 

<h1 align="center">MiniTalk</h1>

<p align="center">
  <img src="https://github.com/elhiba/minitalk/actions/workflows/c-cpp.yml/badge.svg" alt="CI">
</p>

MiniTalk is a small project that has helped me understand how to communicate with other programs.

**Mandatory:**

1. **Build the project:**
	Run the following command:
	```shell
   make
   ```

2. **Open two terminal windows:**
   In the first terminal, start the server:
   ```shell
   ./server
   ```
   In the second terminal, run the client:
   ```shell
   ./client <pid> <your message>
   ```
   For example:
   ```shell
   ./client 9472 "Hi there!"
   ```

**Bonus:**
1. **Build the project:**
   Run the following command:
   ```shell
   make bonus
   ```
2. To run the bonus server, use:
   ```shell
   ./server_bonus
   ```
3. In another terminal, run the bonus client:
   ```shell
   ./client_bonus <pid> "your message"
   ```

> By Odin, by Thor! Use your brain!
