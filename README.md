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
