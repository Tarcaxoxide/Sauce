cd kernel
clean
make setup
make buildimg
cd ..
cd gnu-efi
make clean
make
make bootloader
cd ..

