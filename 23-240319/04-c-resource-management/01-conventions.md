* May need to "(de)initialize the library"
  * Windows sockets: `WSAStartup`, `WSACleanup`
* Initialization
  * Dedication function, or
  * `pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;`, or
  * Zero-initialized (`memset`)
* Deinitialization
  * Dedicated function, or
  * No deinitialization needed
* Copy
  * Not copyable, or
  * Dedicated function (deep copy/you don't know the size)
* Move or shallow copy, if you know the size: bytewise (`memcpy`)
* Memory and buffers are either:
  * Fully (de)allocated by the user (I/O buffer)
  * Fully (de)allocated by the library (references into internal)
