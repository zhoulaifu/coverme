; ModuleID = 'foo.c_.bc'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: nounwind uwtable
define void @foo(double %x) #0 {
entry:
  %x.addr = alloca double, align 8
  store double %x, double* %x.addr, align 8
  br label %while.cond

while.cond:                                       ; preds = %while.body, %entry
  %0 = load double, double* %x.addr, align 8
  %cmp = fcmp ole double %0, 1.000000e+01
  call void @__pen(double %0, double 1.000000e+01)
  br i1 %cmp, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %1 = load double, double* %x.addr, align 8
  %inc = fadd double %1, 1.000000e+00
  store double %inc, double* %x.addr, align 8
  br label %while.cond

while.end:                                        ; preds = %while.cond
  ret void
}

declare void @__pen(double, double)

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.7.0 (trunk 234701)"}
