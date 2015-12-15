# Sworm OS
Sworm OS is a hobbyist OS, built mostly from scratch and in development since 30.12.2014. Restarted 20th February 2015. Name change, sept. 2015

This repository contains the source code and a Makefile for a ```i686-elf``` targeting assembler and cross-compiler.

## Contributing

Fork the repository.
Add bugfixes or new features.
Pull request.

### Requierments for dev env.

Please refer to [the wiki](https://github.com/makerimages/SwormOS/wiki/Building-and-Testing) for refrence.

## TO-DO
- [X] Interrupts
- [X] Exception handling
- [X] PIT
- [X] PMM
- [X] ACPI
- [X] Convert to C
- [X] Keyboard driver - Issue #31
- [X] Virtual Memory Management - Issue #36
- [ ] File system (VFS too) - Issue #32
- [ ] Commands



## Thank you:
* The wiki, forums and IRC of osdev.org for being there. If it weren't for them, I'd still be stuck at writing a bootloader.
* Jonas 'Sortie' Termansen - GDT and IDT implementation sources.
* @exetwezz - All the things related to PR #13.
* @levex - His 4th(?) rewrite of levos, is where the base paging code is derived from.
