# Kernel Development Roadmap

A simple progress tracker for the 32-bit Bare-Metal x86 Kernel project. Mark tasks as complete and add the completion date (`YYYY-MM-DD`) as you finish each stage.

---

## 🎯 Phase 1: Core Boot & Video Subsystem
- [x] **1.1 Multiboot Stub & Build Pipeline**  
  *Completion Date:* 2026-10-03  
  *Details:* Assembly entry (`boot.s`), C entry (`kernel.c`), linker script (`linker.ld`), and QEMU setup.

- [ ] **1.2 Basic VGA Terminal Driver**  
  *Completion Date:* ____-__-__  
  *Details:* Character rendering, text color attributes, clearing screen, and string printing.

- [ ] **1.3 Terminal Cursor & Line Scrolling**  
  *Completion Date:* ____-__-__  
  *Details:* Hardware cursor positioning via CRT controller ports (`0x3D4`/`0x3D5`) and 25-line screen scrolling.

---

## 🛡️ Phase 2: CPU & Interrupt Infrastructure
- [ ] **2.1 Global Descriptor Table (GDT)**  
  *Completion Date:* ____-__-__  
  *Details:* Code/Data descriptors setup, loading GDT pointer (`lgdt`), and segment register reload (`CS` far jump).

- [ ] **2.2 Interrupt Descriptor Table (IDT)**  
  *Completion Date:* ____-__-__  
  *Details:* IDT setup, loading IDT pointer (`lidt`), and low-level interrupt service routine (ISR) handlers.

- [ ] **2.3 Programmable Interrupt Controller (PIC)**  
  *Completion Date:* ____-__-__  
  *Details:* Remapping 8259 PIC master/slave vectors (`0x20-0x28`) to prevent CPU exception collisions.

- [ ] **2.4 CPU Exceptions & Kernel Panic**  
  *Completion Date:* ____-__-__  
  *Details:* Handling CPU faults (ISR 0-31) and implementing a diagnostic Kernel Panic display.

---

## ⌨️ Phase 3: Hardware Drivers & Timing
- [ ] **3.1 PS/2 Keyboard Driver**  
  *Completion Date:* ____-__-__  
  *Details:* Handling IRQ 1 interrupts, reading scancodes from port `0x60`, and translating scancodes to ASCII.

- [ ] **3.2 Programmable Interval Timer (PIT)**  
  *Completion Date:* ____-__-__  
  *Details:* Configuring 8253/8254 PIT (IRQ 0) for hardware ticks and system delay functions.

- [ ] **3.3 Serial Port Logging (UART 16550)**  
  *Completion Date:* ____-__-__  
  *Details:* COM1 driver writing directly to QEMU terminal console for debugging output.

---

## 🧠 Phase 4: Memory Management
- [ ] **4.1 Physical Memory Manager (PMM)**  
  *Completion Date:* ____-__-__  
  *Details:* Parsing Multiboot memory map and creating a bitmap allocator for 4 KiB RAM frames.

- [ ] **4.2 Virtual Memory Manager (VMM)**  
  *Completion Date:* ____-__-__  
  *Details:* Setting up x86 2-level paging (Page Directory & Page Tables) and enabling CR0 paging bit.

- [ ] **4.3 Kernel Heap Allocator**  
  *Completion Date:* ____-__-__  
  *Details:* Dynamic memory allocation implementing `kmalloc` and `kfree`.