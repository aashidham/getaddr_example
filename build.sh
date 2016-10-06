/home/ubuntu/nacl_sdk/pepper_49/toolchain/linux_pnacl/bin/pnacl-clang++ -L/home/ubuntu/nacl_sdk/pepper_49/lib/pnacl/Release main.c -o a.bc -lnacl_io #-pthread

/home/ubuntu/nacl_sdk/pepper_49/toolchain/linux_pnacl/bin/pnacl-finalize a.bc -o a3.out  
