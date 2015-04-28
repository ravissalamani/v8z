// Copyright 2014 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_COMPILER_X64_INSTRUCTION_CODES_X64_H_
#define V8_COMPILER_X64_INSTRUCTION_CODES_X64_H_

namespace v8 {
namespace internal {
namespace compiler {

// X64-specific opcodes that specify which assembly sequence to emit.
// Most opcodes specify a single instruction.
#define TARGET_ARCH_OPCODE_LIST(V) \
  V(X64Add)                        \
  V(X64Add32)                      \
  V(X64And)                        \
  V(X64And32)                      \
  V(X64Cmp)                        \
  V(X64Cmp32)                      \
  V(X64Test)                       \
  V(X64Test32)                     \
  V(X64Or)                         \
  V(X64Or32)                       \
  V(X64Xor)                        \
  V(X64Xor32)                      \
  V(X64Sub)                        \
  V(X64Sub32)                      \
  V(X64Imul)                       \
  V(X64Imul32)                     \
<<<<<<< HEAD
=======
  V(X64ImulHigh32)                 \
  V(X64UmulHigh32)                 \
>>>>>>> 4.3
  V(X64Idiv)                       \
  V(X64Idiv32)                     \
  V(X64Udiv)                       \
  V(X64Udiv32)                     \
  V(X64Not)                        \
  V(X64Not32)                      \
  V(X64Neg)                        \
  V(X64Neg32)                      \
  V(X64Shl)                        \
  V(X64Shl32)                      \
  V(X64Shr)                        \
  V(X64Shr32)                      \
  V(X64Sar)                        \
  V(X64Sar32)                      \
<<<<<<< HEAD
  V(X64Push)                       \
  V(X64PushI)                      \
  V(X64CallCodeObject)             \
  V(X64CallAddress)                \
  V(PopStack)                      \
  V(X64CallJSFunction)             \
=======
  V(X64Ror)                        \
  V(X64Ror32)                      \
  V(X64Lzcnt32)                    \
>>>>>>> 4.3
  V(SSEFloat64Cmp)                 \
  V(SSEFloat64Add)                 \
  V(SSEFloat64Sub)                 \
  V(SSEFloat64Mul)                 \
  V(SSEFloat64Div)                 \
  V(SSEFloat64Mod)                 \
<<<<<<< HEAD
  V(X64Int32ToInt64)               \
  V(X64Int64ToInt32)               \
=======
  V(SSEFloat64Sqrt)                \
  V(SSEFloat64Round)               \
  V(SSEFloat64Max)                 \
  V(SSEFloat64Min)                 \
  V(SSECvtss2sd)                   \
  V(SSECvtsd2ss)                   \
>>>>>>> 4.3
  V(SSEFloat64ToInt32)             \
  V(SSEFloat64ToUint32)            \
  V(SSEInt32ToFloat64)             \
  V(SSEUint32ToFloat64)            \
<<<<<<< HEAD
  V(SSELoad)                       \
  V(SSEStore)                      \
  V(X64LoadWord8)                  \
  V(X64StoreWord8)                 \
  V(X64StoreWord8I)                \
  V(X64LoadWord16)                 \
  V(X64StoreWord16)                \
  V(X64StoreWord16I)               \
  V(X64LoadWord32)                 \
  V(X64StoreWord32)                \
  V(X64StoreWord32I)               \
  V(X64LoadWord64)                 \
  V(X64StoreWord64)                \
  V(X64StoreWord64I)               \
  V(X64StoreWriteBarrier)
=======
  V(SSEFloat64ExtractLowWord32)    \
  V(SSEFloat64ExtractHighWord32)   \
  V(SSEFloat64InsertLowWord32)     \
  V(SSEFloat64InsertHighWord32)    \
  V(SSEFloat64LoadLowWord32)       \
  V(AVXFloat64Add)                 \
  V(AVXFloat64Sub)                 \
  V(AVXFloat64Mul)                 \
  V(AVXFloat64Div)                 \
  V(AVXFloat64Max)                 \
  V(AVXFloat64Min)                 \
  V(X64Movsxbl)                    \
  V(X64Movzxbl)                    \
  V(X64Movb)                       \
  V(X64Movsxwl)                    \
  V(X64Movzxwl)                    \
  V(X64Movw)                       \
  V(X64Movl)                       \
  V(X64Movsxlq)                    \
  V(X64Movq)                       \
  V(X64Movsd)                      \
  V(X64Movss)                      \
  V(X64Lea32)                      \
  V(X64Lea)                        \
  V(X64Dec32)                      \
  V(X64Inc32)                      \
  V(X64Push)                       \
  V(X64StoreWriteBarrier)          \
  V(X64StackCheck)
>>>>>>> 4.3


// Addressing modes represent the "shape" of inputs to an instruction.
// Many instructions support multiple addressing modes. Addressing modes
// are encoded into the InstructionCode of the instruction and tell the
// code generator after register allocation which assembler method to call.
//
// We use the following local notation for addressing modes:
//
<<<<<<< HEAD
// R = register
// O = register or stack slot
// D = double register
// I = immediate (handle, external, int32)
// MR = [register]
// MI = [immediate]
// MRN = [register + register * N in {1, 2, 4, 8}]
// MRI = [register + immediate]
// MRNI = [register + register * N in {1, 2, 4, 8} + immediate]
#define TARGET_ADDRESSING_MODE_LIST(V) \
  V(MR)   /* [%r1] */                  \
  V(MRI)  /* [%r1 + K] */              \
  V(MR1I) /* [%r1 + %r2 + K] */        \
  V(MR2I) /* [%r1 + %r2*2 + K] */      \
  V(MR4I) /* [%r1 + %r2*4 + K] */      \
  V(MR8I) /* [%r1 + %r2*8 + K] */
=======
// M = memory operand
// R = base register
// N = index register * N for N in {1, 2, 4, 8}
// I = immediate displacement (32-bit signed integer)

#define TARGET_ADDRESSING_MODE_LIST(V) \
  V(MR)   /* [%r1            ] */      \
  V(MRI)  /* [%r1         + K] */      \
  V(MR1)  /* [%r1 + %r2*1    ] */      \
  V(MR2)  /* [%r1 + %r2*2    ] */      \
  V(MR4)  /* [%r1 + %r2*4    ] */      \
  V(MR8)  /* [%r1 + %r2*8    ] */      \
  V(MR1I) /* [%r1 + %r2*1 + K] */      \
  V(MR2I) /* [%r1 + %r2*2 + K] */      \
  V(MR4I) /* [%r1 + %r2*3 + K] */      \
  V(MR8I) /* [%r1 + %r2*4 + K] */      \
  V(M1)   /* [      %r2*1    ] */      \
  V(M2)   /* [      %r2*2    ] */      \
  V(M4)   /* [      %r2*4    ] */      \
  V(M8)   /* [      %r2*8    ] */      \
  V(M1I)  /* [      %r2*1 + K] */      \
  V(M2I)  /* [      %r2*2 + K] */      \
  V(M4I)  /* [      %r2*4 + K] */      \
  V(M8I)  /* [      %r2*8 + K] */
>>>>>>> 4.3

}  // namespace compiler
}  // namespace internal
}  // namespace v8

#endif  // V8_COMPILER_X64_INSTRUCTION_CODES_X64_H_
