# create .bc from source
%.bc: %.c
	clang -emit-llvm -O0 -c $*.c -o $*.bc

# create human-readable assembly (.ll) from .bc
%.ll: %.bc
	llvm-dis -f $^
