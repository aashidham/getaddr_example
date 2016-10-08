# getaddr_example
1. Download this respository: <pre>git clone https://github.com/aashidham/getaddr_example</pre>
2. Run a static file server from this directory. This is how you do it in Python: <pre>python -m SimpleHTTPServer</pre>
3. Open Chrome from the command line, so you can see stdout. This is how you do it on OSX: <pre>/Applications/Google\ Chrome.app/Contents/MacOS/Google\ Chrome  --allow-nacl-socket-api=192.168.1.124</pre>
4. Navigate to <code>192.168.1.124:8080</code>. You should see the following in the console:<pre>MacBookPro:~ user: /Applications/Google\ Chrome.app/Contents/MacOS/Google\ Chrome --allow-nacl-socket-api=192.168.1.124
[21858,2019947280:00:42:46.740706] Native Client module will be loaded at base address 0x00000e4500000000
Could create thread
entered thread
getaddrinfo error EAI_SYSTEM in syscall Success
[21858,2019947280:00:42:46.764207] NaCl untrusted code called _exit(0x1)
[21846:33283:1006/004246:ERROR:nacl_process_host.cc(337)] NaCl process exited with status 256 (0x100)
</pre>
You need to use the private IP address of your computer (you can look this up on <code>ifconfig</code>). You cannot use localhost or 127.0.0.1 because opening TCP sockets aren't allowed from these places.
The third-to-last line of the output comes from line 45 in <code>main.c</code>, and I'm not sure why.

# getaddr_example run main.c natively
1. Comment out line 45 and line 17 from <code>main.c</code>, both lines come from the pnacl toolchain.
2. Run <pre>g++ main.c -pthread</pre>
3. Run <code>a.out</code> and you should see the correct output:<pre>MacBookPro:~/getaddr_example$ ./a.out
Could create thread
entered thread
was able to go through syscallhostname: sea15s08-in-f100.1e100.net
hostname: sea15s08-in-f4.1e100.net
hostname: sea15s08-in-f100.1e100.net
hostname: pc-in-x63.1e100.net
hostname: pc-in-x63.1e100.net
hostname: pc-in-x63.1e100.net
Could join thread
</pre>
This is the correct output, and I can't replicate it inside PNaCl. I think I have accomplished all the requirements for the use of the nacl_io library: https://developer.chrome.com/native-client/devguide/coding/nacl_io I've done Google has asked for:

I link the application with <code>-lnacl_io</code>

I call <code>nacl_io_init</code> at startup.

I make sure socket API calls from the background thread.


