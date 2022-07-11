# minitalk bonus
Sending a string of chars to another process using only SIGUSR1 and SIGUSR2. It supports UNICODE.

Update: would be cool to create a queing system for the signals, so that the server signal handler doesn't do that much as it does in my code(you would have the fastest minitalk I guess). Check out the sigqueue and rt_sigqueue, it is super interesting to know how the kernel sends a signal and how it packs info with that sent SIG.
