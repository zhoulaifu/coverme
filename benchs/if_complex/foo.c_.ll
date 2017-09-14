; ModuleID = 'foo.c_.bc'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: nounwind uwtable
define void @foo(double %x) #0 {
entry:
  %x.addr = alloca double, align 8
  store double %x, double* %x.addr, align 8
  %0 = load double, double* %x.addr, align 8
  %cmp = fcmp ole double %0, 3.000000e+00
  call void @__pen(double %0, double 3.000000e+00)
  br i1 %cmp, label %land.lhs.true, label %lor.lhs.false

lor.lhs.false:                                    ; preds = %entry
  %1 = load double, double* %x.addr, align 8
  %cmp1 = fcmp oge double %1, 0.000000e+00
  call void @__pen(double %1, double 0.000000e+00)
  br i1 %cmp1, label %land.lhs.true, label %if.end

land.lhs.true:                                    ; preds = %lor.lhs.false, %entry
  %2 = load double, double* %x.addr, align 8
  %3 = load double, double* %x.addr, align 8
  %mul = fmul double 2.000000e+00, %3
  %add = fadd double %mul, 3.000000e+00
  %cmp2 = fcmp ogt double %2, %add
  call void @__pen(double %2, double %add)
  br i1 %cmp2, label %if.then, label %if.end

if.then:                                          ; preds = %land.lhs.true
  br label %if.end

if.end:                                           ; preds = %if.then, %land.lhs.true, %lor.lhs.false
  ret void
}

declare void @__pen(double, double)

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.7.0 (trunk 234701)"}
