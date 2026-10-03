> **Status:** 🚧 Active Development, Still Learning and Optimizing. Most of the concepts are not yet understood by me but I am trying my best 
> **Architecture:** x86 (32-bit Protected Mode)  
> **Specification:** Multiboot v1 Compliant  

A micro-kernel written from scratch in GNU Assembly (`GAS`) and freestanding C, built to boot directly via Multiboot-compliant bootloaders (like QEMU and GRUB).

---

## 🛠️ Toolchain & Prerequisites

This project is built on Windows 10/11 using WSL2 (Ubuntu).

```bash
sudo apt update
sudo apt install build-essential binutils qemu-system-x86 grub2-common -y
📁 Project Structure
Plaintext
.
├── boot.s        # Assembly entry point, Multiboot header & stack setup
├── kernel.c      # Freestanding C kernel logic & VGA driver
├── linker.ld     # Linker script mapping kernel memory starting at 1MB
├── .gitignore    # Excludes compiled binary artifacts from Git
└── README.md     # Project documentation & daily dev log


##Daily Development Log:

### Day 1 — Bootloader Stub, Linker Script & VGA Memory (2026-10-03)
- **Implemented:** Built initial Multiboot-compliant kernel entry in GNU Assembly (`boot.s`), freestanding C kernel (`kernel.c`), and linker script (`linker.ld`). Booted successfully in QEMU.
- **Key Concepts:** Multiboot v1 header signatures (`0x1BADB002`), 32-bit Protected Mode initialization, 16 KiB call stack setup (`ESP`), memory section mapping at `0x100000` (1 MB), and volatile memory-mapped I/O at VGA video buffer (`0xB8000`).
- **Challenges & Fixes:** 
  - **Toolchain & Syntax Mismatches:** Resolved assembly compilation errors when switching between Intel/NASM syntax and AT&T/GAS syntax (`as`).
  - **WSL2 Networking & Package Setup:** Fixed WSL2 DNS resolution and package manager connection issues to install `build-essential`, `qemu-system-x86`, and `binutils`.
- **Status:** Bare-metal kernel binary builds cleanly and renders text directly to the screen inside QEMU.