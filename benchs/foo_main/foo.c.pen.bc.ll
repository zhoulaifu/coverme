; ModuleID = 'foo.c.pen.bc'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct._IO_FILE = type { i32, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, %struct._IO_marker*, %struct._IO_FILE*, i32, i32, i64, i16, i8, [1 x i8], i8*, i64, i8*, i8*, i8*, i8*, i64, i32, [20 x i8] }
%struct._IO_marker = type { %struct._IO_marker*, %struct._IO_FILE*, i32 }

@.str = private unnamed_addr constant [28 x i8] c"Good!!!!!!!!!!!!!!!!!!!!!!\0A\00", align 1
@stderr = external global %struct._IO_FILE*
@.str1 = private unnamed_addr constant [27 x i8] c"argc=%d,\0A a=%c,%c, %c, %c\0A\00", align 1

; Function Attrs: uwtable
define i32 @_Z7foo_rawiPPc(i32 %argc, i8** %a) #0 {
entry:
  %argc.addr = alloca i32, align 4
  %a.addr = alloca i8**, align 8
  store i32 %argc, i32* %argc.addr, align 4
  store i8** %a, i8*** %a.addr, align 8
  %0 = load i32, i32* %argc.addr, align 4
  %cmp = icmp sgt i32 %0, 10
  %__LHS = sitofp i32 %0 to double
  call void @__pen(double %__LHS, double 1.000000e+01, i64 69846128, i64 38, i64 1)
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([28 x i8], [28 x i8]* @.str, i32 0, i32 0))
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %1 = load %struct._IO_FILE*, %struct._IO_FILE** @stderr, align 8
  %2 = load i32, i32* %argc.addr, align 4
  %3 = load i8**, i8*** %a.addr, align 8
  %arrayidx = getelementptr inbounds i8*, i8** %3, i64 0
  %4 = load i8*, i8** %arrayidx, align 8
  %arrayidx1 = getelementptr inbounds i8, i8* %4, i64 0
  %5 = load i8, i8* %arrayidx1, align 1
  %conv = sext i8 %5 to i32
  %6 = load i8**, i8*** %a.addr, align 8
  %arrayidx2 = getelementptr inbounds i8*, i8** %6, i64 0
  %7 = load i8*, i8** %arrayidx2, align 8
  %arrayidx3 = getelementptr inbounds i8, i8* %7, i64 1
  %8 = load i8, i8* %arrayidx3, align 1
  %conv4 = sext i8 %8 to i32
  %9 = load i8**, i8*** %a.addr, align 8
  %arrayidx5 = getelementptr inbounds i8*, i8** %9, i64 1
  %10 = load i8*, i8** %arrayidx5, align 8
  %arrayidx6 = getelementptr inbounds i8, i8* %10, i64 0
  %11 = load i8, i8* %arrayidx6, align 1
  %conv7 = sext i8 %11 to i32
  %12 = load i8**, i8*** %a.addr, align 8
  %arrayidx8 = getelementptr inbounds i8*, i8** %12, i64 1
  %13 = load i8*, i8** %arrayidx8, align 8
  %arrayidx9 = getelementptr inbounds i8, i8* %13, i64 1
  %14 = load i8, i8* %arrayidx9, align 1
  %conv10 = sext i8 %14 to i32
  %call11 = call i32 (%struct._IO_FILE*, i8*, ...)* @fprintf(%struct._IO_FILE* %1, i8* getelementptr inbounds ([27 x i8], [27 x i8]* @.str1, i32 0, i32 0), i32 %2, i32 %conv, i32 %conv4, i32 %conv7, i32 %conv10)
  ret i32 0
}

declare i32 @printf(i8*, ...) #1

declare i32 @fprintf(%struct._IO_FILE*, i8*, ...) #1

declare void @__pen(double, double, i64, i64, i64)

attributes #0 = { uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"PIC Level", i32 2}
!1 = !{!"clang version 3.7.0 (trunk 234701)"}
