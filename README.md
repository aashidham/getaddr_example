# getaddr_example
1. Download this respository: <pre>git clone https://github.com/aashidham/getaddr_example</pre>
2. Run a static file server from this directory. This is how you do it in Python: <pre>python -m SimpleHTTPServer</pre>
3. Open Chrome from the command line, so you can see stdout. This is how you do it on OSX: <pre>/Applications/Google\ Chrome.app/Contents/MacOS/Google\ Chrome</pre>
4. Navigate to <code>localhost:8080</code>. You should see the following in the console:<pre>MacBookPro:~ user: /Applications/Google\ Chrome.app/Contents/MacOS/Google\ Chrome
[21210,2019947280:23:16:45.931976] Native Client module will be loaded at base address 0x0000465700000000
[21211,2019947280:23:16:49.583005] Native Client module will be loaded at base address 0x00002ee900000000
[21212,2019947280:23:16:49.801433] Native Client module will be loaded at base address 0x0000463900000000
Could create thread
entered thread
getaddrinfo error EAI_SYSTEM in syscall Success
</pre>
The last line of the output comes from line 45 in <code>main.c</code>, and I'm not sure why.

# getaddr_example run main.c natively
1. Comment out line 45 and line 17, both lines come from the pnacl toolchain.
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
This is the correct output, and I can't replicate it inside PNaCl. I think I have accomplished all the requirements for the use of the nacl_io library: https://developer.chrome.com/native-client/devguide/coding/nacl_io

I link the application with <code>-lnacl_io</code>
I call <code>nacl_io_init</code> at startup.
I make sure socket API calls from the background thread.
