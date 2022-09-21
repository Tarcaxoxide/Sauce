

qemu-system-x86_64 -display gtk,zoom-to-fit=on -smp 2 -serial stdio -machine q35 -s -drive format=raw,file=Sauce.img -m 2G -cpu qemu64 -drive if=pflash,format=raw,unit=0,file="OVMFbin/OVMF_CODE-pure-efi.fd",readonly=on -drive if=pflash,format=raw,unit=1,file="OVMFbin/OVMF_VARS-pure-efi.fd"