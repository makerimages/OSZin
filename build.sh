rm -rf dist
mkdir -p dist
mkdir dist/drivers
i686-elf-as src/boot.s -o dist/boot.o
i686-elf-g++ -c src/Kernel.cpp -o dist/Kernel.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
i686-elf-g++ -c src/drivers/Interrupts.cpp -o dist/drivers/Interrupts.o  -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
i686-elf-g++ -c src/drivers/System.cpp -o dist/drivers/System.o  -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
i686-elf-g++ -c src/drivers/Terminal.cpp -o dist/drivers/Terminal.o  -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
i686-elf-gcc -T src/linker.ld -o dist/OSZin.bin -ffreestanding -O2 -nostdlib dist/boot.o dist/Kernel.o dist/drivers/Terminal.o dist/drivers/System.o dist/drivers/Interrupts.o -lgcc
cd dist
mkdir -p isodir
mkdir -p isodir/boot
cp OSZin.bin isodir/boot/OSZin.bin
mkdir -p isodir/boot/grub
cp ../src/grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue --output=OSZin.iso isodir
cd ..