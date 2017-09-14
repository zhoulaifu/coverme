; ModuleID = 'foo.c.pen.bc'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [12 x i8] c"Excellent!\0A\00", align 1
@.str1 = private unnamed_addr constant [11 x i8] c"Well done\0A\00", align 1
@.str2 = private unnamed_addr constant [12 x i8] c"You passed\0A\00", align 1
@.str3 = private unnamed_addr constant [18 x i8] c"Better try again\0A\00", align 1
@.str4 = private unnamed_addr constant [15 x i8] c"Invalid grade\0A\00", align 1
@.str5 = private unnamed_addr constant [19 x i8] c"Your grade is  %c\0A\00", align 1

; Function Attrs: uwtable
define double @_Z7foo_rawd(double %x) #0 {
entry:
  %x.addr = alloca double, align 8
  %grade = alloca i8, align 1
  store double %x, double* %x.addr, align 8
  %0 = load double, double* %x.addr, align 8
  %conv = fptosi double %0 to i8
  %conv1 = sext i8 %conv to i32
  %add = add nsw i32 %conv1, 100
  %conv2 = trunc i32 %add to i8
  store i8 %conv2, i8* %grade, align 1
  %1 = load i8, i8* %grade, align 1
  %conv3 = sext i8 %1 to i32
  switch i32 %conv3, label %sw.default [
    i32 65, label %sw.bb
    i32 66, label %sw.bb4
    i32 67, label %sw.bb4
    i32 68, label %sw.bb6
    i32 70, label %sw.bb8
  ]

sw.bb:                                            ; preds = %entry
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @.str, i32 0, i32 0))
  br label %sw.epilog

sw.bb4:                                           ; preds = %entry, %entry
  %call5 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @.str1, i32 0, i32 0))
  br label %sw.epilog

sw.bb6:                                           ; preds = %entry
  %call7 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @.str2, i32 0, i32 0))
  br label %sw.epilog

sw.bb8:                                           ; preds = %entry
  %call9 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str3, i32 0, i32 0))
  br label %sw.epilog

sw.default:                                       ; preds = %entry
  %call10 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([15 x i8], [15 x i8]* @.str4, i32 0, i32 0))
  br label %sw.epilog

sw.epilog:                                        ; preds = %sw.default, %sw.bb8, %sw.bb6, %sw.bb4, %sw.bb
  %2 = load i8, i8* %grade, align 1
  %conv11 = sext i8 %2 to i32
  %call12 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str5, i32 0, i32 0), i32 %conv11)
  ret double 0.000000e+00
}

declare i32 @printf(i8*, ...) #1

attributes #0 = { uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"PIC Level", i32 2}
!1 = !{!"clang version 3.7.0 (trunk 234701)"}
