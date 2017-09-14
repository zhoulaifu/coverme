; ModuleID = 's_erf.bc'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: nounwind uwtable
define double @erf(double %x) #0 {
entry:
  %retval = alloca double, align 8
  %x.addr = alloca double, align 8
  %hx = alloca i32, align 4
  %ix = alloca i32, align 4
  %i = alloca i32, align 4
  %R = alloca double, align 8
  %S = alloca double, align 8
  %P = alloca double, align 8
  %Q = alloca double, align 8
  %s = alloca double, align 8
  %y = alloca double, align 8
  %z = alloca double, align 8
  %r = alloca double, align 8
  store double %x, double* %x.addr, align 8
  %0 = bitcast double* %x.addr to i32*
  %add.ptr = getelementptr inbounds i32, i32* %0, i64 1
  %1 = load i32, i32* %add.ptr, align 4
  store i32 %1, i32* %hx, align 4
  %2 = load i32, i32* %hx, align 4
  %and = and i32 %2, 2147483647
  store i32 %and, i32* %ix, align 4
  %3 = load i32, i32* %ix, align 4
  %cmp = icmp sge i32 %3, 2146435072
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %4 = load i32, i32* %hx, align 4
  %shr = lshr i32 %4, 31
  %shl = shl i32 %shr, 1
  store i32 %shl, i32* %i, align 4
  %5 = load i32, i32* %i, align 4
  %sub = sub nsw i32 1, %5
  %conv = sitofp i32 %sub to double
  %6 = load double, double* %x.addr, align 8
  %div = fdiv double 1.000000e+00, %6
  %add = fadd double %conv, %div
  store double %add, double* %retval
  br label %return

if.end:                                           ; preds = %entry
  %7 = load i32, i32* %ix, align 4
  %cmp1 = icmp slt i32 %7, 1072365568
  br i1 %cmp1, label %if.then3, label %if.end39

if.then3:                                         ; preds = %if.end
  %8 = load i32, i32* %ix, align 4
  %cmp4 = icmp slt i32 %8, 1043333120
  br i1 %cmp4, label %if.then6, label %if.end16

if.then6:                                         ; preds = %if.then3
  %9 = load i32, i32* %ix, align 4
  %cmp7 = icmp slt i32 %9, 8388608
  br i1 %cmp7, label %if.then9, label %if.end13

if.then9:                                         ; preds = %if.then6
  %10 = load double, double* %x.addr, align 8
  %mul = fmul double 8.000000e+00, %10
  %11 = load double, double* %x.addr, align 8
  %mul10 = fmul double 0x3FF06EBA8214DB69, %11
  %add11 = fadd double %mul, %mul10
  %mul12 = fmul double 1.250000e-01, %add11
  store double %mul12, double* %retval
  br label %return

if.end13:                                         ; preds = %if.then6
  %12 = load double, double* %x.addr, align 8
  %13 = load double, double* %x.addr, align 8
  %mul14 = fmul double 0x3FC06EBA8214DB69, %13
  %add15 = fadd double %12, %mul14
  store double %add15, double* %retval
  br label %return

if.end16:                                         ; preds = %if.then3
  %14 = load double, double* %x.addr, align 8
  %15 = load double, double* %x.addr, align 8
  %mul17 = fmul double %14, %15
  store double %mul17, double* %z, align 8
  %16 = load double, double* %z, align 8
  %17 = load double, double* %z, align 8
  %18 = load double, double* %z, align 8
  %19 = load double, double* %z, align 8
  %mul18 = fmul double %19, 0xBEF8EAD6120016AC
  %add19 = fadd double 0xBF77A291236668E4, %mul18
  %mul20 = fmul double %18, %add19
  %add21 = fadd double 0xBF9D2A51DBD7194F, %mul20
  %mul22 = fmul double %17, %add21
  %add23 = fadd double 0xBFD4CD7D691CB913, %mul22
  %mul24 = fmul double %16, %add23
  %add25 = fadd double 0x3FC06EBA8214DB68, %mul24
  store double %add25, double* %r, align 8
  %20 = load double, double* %z, align 8
  %21 = load double, double* %z, align 8
  %22 = load double, double* %z, align 8
  %23 = load double, double* %z, align 8
  %24 = load double, double* %z, align 8
  %mul26 = fmul double %24, 0xBED09C4342A26120
  %add27 = fadd double 0x3F215DC9221C1A10, %mul26
  %mul28 = fmul double %23, %add27
  %add29 = fadd double 0x3F74D022C4D36B0F, %mul28
  %mul30 = fmul double %22, %add29
  %add31 = fadd double 0x3FB0A54C5536CEBA, %mul30
  %mul32 = fmul double %21, %add31
  %add33 = fadd double 0x3FD97779CDDADC09, %mul32
  %mul34 = fmul double %20, %add33
  %add35 = fadd double 1.000000e+00, %mul34
  store double %add35, double* %s, align 8
  %25 = load double, double* %r, align 8
  %26 = load double, double* %s, align 8
  %div36 = fdiv double %25, %26
  store double %div36, double* %y, align 8
  %27 = load double, double* %x.addr, align 8
  %28 = load double, double* %x.addr, align 8
  %29 = load double, double* %y, align 8
  %mul37 = fmul double %28, %29
  %add38 = fadd double %27, %mul37
  store double %add38, double* %retval
  br label %return

if.end39:                                         ; preds = %if.end
  %30 = load i32, i32* %ix, align 4
  %cmp40 = icmp slt i32 %30, 1072955392
  br i1 %cmp40, label %if.then42, label %if.end75

if.then42:                                        ; preds = %if.end39
  %31 = load double, double* %x.addr, align 8
  %call = call double @fabs(double %31) #3
  %sub43 = fsub double %call, 1.000000e+00
  store double %sub43, double* %s, align 8
  %32 = load double, double* %s, align 8
  %33 = load double, double* %s, align 8
  %34 = load double, double* %s, align 8
  %35 = load double, double* %s, align 8
  %36 = load double, double* %s, align 8
  %37 = load double, double* %s, align 8
  %mul44 = fmul double %37, 0xBF61BF380A96073F
  %add45 = fadd double 0x3FA22A36599795EB, %mul44
  %mul46 = fmul double %36, %add45
  %add47 = fadd double 0xBFBC63983D3E28EC, %mul46
  %mul48 = fmul double %35, %add47
  %add49 = fadd double 0x3FD45FCA805120E4, %mul48
  %mul50 = fmul double %34, %add49
  %add51 = fadd double 0xBFD7D240FBB8C3F1, %mul50
  %mul52 = fmul double %33, %add51
  %add53 = fadd double 0x3FDA8D00AD92B34D, %mul52
  %mul54 = fmul double %32, %add53
  %add55 = fadd double 0xBF6359B8BEF77538, %mul54
  store double %add55, double* %P, align 8
  %38 = load double, double* %s, align 8
  %39 = load double, double* %s, align 8
  %40 = load double, double* %s, align 8
  %41 = load double, double* %s, align 8
  %42 = load double, double* %s, align 8
  %43 = load double, double* %s, align 8
  %mul56 = fmul double %43, 0x3F888B545735151D
  %add57 = fadd double 0x3F8BEDC26B51DD1C, %mul56
  %mul58 = fmul double %42, %add57
  %add59 = fadd double 0x3FC02660E763351F, %mul58
  %mul60 = fmul double %41, %add59
  %add61 = fadd double 0x3FB2635CD99FE9A7, %mul60
  %mul62 = fmul double %40, %add61
  %add63 = fadd double 0x3FE14AF092EB6F33, %mul62
  %mul64 = fmul double %39, %add63
  %add65 = fadd double 0x3FBB3E6618EEE323, %mul64
  %mul66 = fmul double %38, %add65
  %add67 = fadd double 1.000000e+00, %mul66
  store double %add67, double* %Q, align 8
  %44 = load i32, i32* %hx, align 4
  %cmp68 = icmp sge i32 %44, 0
  br i1 %cmp68, label %if.then70, label %if.else

if.then70:                                        ; preds = %if.then42
  %45 = load double, double* %P, align 8
  %46 = load double, double* %Q, align 8
  %div71 = fdiv double %45, %46
  %add72 = fadd double 0x3FEB0AC160000000, %div71
  store double %add72, double* %retval
  br label %return

if.else:                                          ; preds = %if.then42
  %47 = load double, double* %P, align 8
  %48 = load double, double* %Q, align 8
  %div73 = fdiv double %47, %48
  %sub74 = fsub double 0xBFEB0AC160000000, %div73
  store double %sub74, double* %retval
  br label %return

if.end75:                                         ; preds = %if.end39
  %49 = load i32, i32* %ix, align 4
  %cmp76 = icmp sge i32 %49, 1075314688
  br i1 %cmp76, label %if.then78, label %if.end83

if.then78:                                        ; preds = %if.end75
  %50 = load i32, i32* %hx, align 4
  %cmp79 = icmp sge i32 %50, 0
  br i1 %cmp79, label %if.then81, label %if.else82

if.then81:                                        ; preds = %if.then78
  store double 1.000000e+00, double* %retval
  br label %return

if.else82:                                        ; preds = %if.then78
  store double -1.000000e+00, double* %retval
  br label %return

if.end83:                                         ; preds = %if.end75
  %51 = load double, double* %x.addr, align 8
  %call84 = call double @fabs(double %51) #3
  store double %call84, double* %x.addr, align 8
  %52 = load double, double* %x.addr, align 8
  %53 = load double, double* %x.addr, align 8
  %mul85 = fmul double %52, %53
  %div86 = fdiv double 1.000000e+00, %mul85
  store double %div86, double* %s, align 8
  %54 = load i32, i32* %ix, align 4
  %cmp87 = icmp slt i32 %54, 1074191214
  br i1 %cmp87, label %if.then89, label %if.else120

if.then89:                                        ; preds = %if.end83
  %55 = load double, double* %s, align 8
  %56 = load double, double* %s, align 8
  %57 = load double, double* %s, align 8
  %58 = load double, double* %s, align 8
  %59 = load double, double* %s, align 8
  %60 = load double, double* %s, align 8
  %61 = load double, double* %s, align 8
  %mul90 = fmul double %61, 0xC023A0EFC69AC25C
  %add91 = fadd double 0xC054526557E4D2F2, %mul90
  %mul92 = fmul double %60, %add91
  %add93 = fadd double 0xC067135CEBCCABB2, %mul92
  %mul94 = fmul double %59, %add93
  %add95 = fadd double 0xC0644CB184282266, %mul94
  %mul96 = fmul double %58, %add95
  %add97 = fadd double 0xC04F300AE4CBA38D, %mul96
  %mul98 = fmul double %57, %add97
  %add99 = fadd double 0xC0251E0441B0E726, %mul98
  %mul100 = fmul double %56, %add99
  %add101 = fadd double 0xBFE63416E4BA7360, %mul100
  %mul102 = fmul double %55, %add101
  %add103 = fadd double 0xBF843412600D6435, %mul102
  store double %add103, double* %R, align 8
  %62 = load double, double* %s, align 8
  %63 = load double, double* %s, align 8
  %64 = load double, double* %s, align 8
  %65 = load double, double* %s, align 8
  %66 = load double, double* %s, align 8
  %67 = load double, double* %s, align 8
  %68 = load double, double* %s, align 8
  %69 = load double, double* %s, align 8
  %mul104 = fmul double %69, 0xBFAEEFF2EE749A62
  %add105 = fadd double 0x401A47EF8E484A93, %mul104
  %mul106 = fmul double %68, %add105
  %add107 = fadd double 0x405B28A3EE48AE2C, %mul106
  %mul108 = fmul double %67, %add107
  %add109 = fadd double 0x407AD02157700314, %mul108
  %mul110 = fmul double %66, %add109
  %add111 = fadd double 0x40842B1921EC2868, %mul110
  %mul112 = fmul double %65, %add111
  %add113 = fadd double 0x407B290DD58A1A71, %mul112
  %mul114 = fmul double %64, %add113
  %add115 = fadd double 0x4061350C526AE721, %mul114
  %mul116 = fmul double %63, %add115
  %add117 = fadd double 0x4033A6B9BD707687, %mul116
  %mul118 = fmul double %62, %add117
  %add119 = fadd double 1.000000e+00, %mul118
  store double %add119, double* %S, align 8
  br label %if.end147

if.else120:                                       ; preds = %if.end83
  %70 = load double, double* %s, align 8
  %71 = load double, double* %s, align 8
  %72 = load double, double* %s, align 8
  %73 = load double, double* %s, align 8
  %74 = load double, double* %s, align 8
  %75 = load double, double* %s, align 8
  %mul121 = fmul double %75, 0xC07E384E9BDC383F
  %add122 = fadd double 0xC09004616A2E5992, %mul121
  %mul123 = fmul double %74, %add122
  %add124 = fadd double 0xC083EC881375F228, %mul123
  %mul125 = fmul double %73, %add124
  %add126 = fadd double 0xC064145D43C5ED98, %mul125
  %mul127 = fmul double %72, %add126
  %add128 = fadd double 0xC031C209555F995A, %mul127
  %mul129 = fmul double %71, %add128
  %add130 = fadd double 0xBFE993BA70C285DE, %mul129
  %mul131 = fmul double %70, %add130
  %add132 = fadd double 0xBF84341239E86F4A, %mul131
  store double %add132, double* %R, align 8
  %76 = load double, double* %s, align 8
  %77 = load double, double* %s, align 8
  %78 = load double, double* %s, align 8
  %79 = load double, double* %s, align 8
  %80 = load double, double* %s, align 8
  %81 = load double, double* %s, align 8
  %82 = load double, double* %s, align 8
  %mul133 = fmul double %82, 0xC03670E242712D62
  %add134 = fadd double 0x407DA874E79FE763, %mul133
  %mul135 = fmul double %81, %add134
  %add136 = fadd double 0x40A3F219CEDF3BE6, %mul135
  %mul137 = fmul double %80, %add136
  %add138 = fadd double 0x40A8FFB7688C246A, %mul137
  %mul139 = fmul double %79, %add138
  %add140 = fadd double 0x409802EB189D5118, %mul139
  %mul141 = fmul double %78, %add140
  %add142 = fadd double 0x40745CAE221B9F0A, %mul141
  %mul143 = fmul double %77, %add142
  %add144 = fadd double 0x403E568B261D5190, %mul143
  %mul145 = fmul double %76, %add144
  %add146 = fadd double 1.000000e+00, %mul145
  store double %add146, double* %S, align 8
  br label %if.end147

if.end147:                                        ; preds = %if.else120, %if.then89
  %83 = load double, double* %x.addr, align 8
  store double %83, double* %z, align 8
  %84 = bitcast double* %z to i32*
  store i32 0, i32* %84, align 4
  %85 = load double, double* %z, align 8
  %sub148 = fsub double -0.000000e+00, %85
  %86 = load double, double* %z, align 8
  %mul149 = fmul double %sub148, %86
  %sub150 = fsub double %mul149, 5.625000e-01
  %call151 = call double @__ieee754_exp(double %sub150)
  %87 = load double, double* %z, align 8
  %88 = load double, double* %x.addr, align 8
  %sub152 = fsub double %87, %88
  %89 = load double, double* %z, align 8
  %90 = load double, double* %x.addr, align 8
  %add153 = fadd double %89, %90
  %mul154 = fmul double %sub152, %add153
  %91 = load double, double* %R, align 8
  %92 = load double, double* %S, align 8
  %div155 = fdiv double %91, %92
  %add156 = fadd double %mul154, %div155
  %call157 = call double @__ieee754_exp(double %add156)
  %mul158 = fmul double %call151, %call157
  store double %mul158, double* %r, align 8
  %93 = load i32, i32* %hx, align 4
  %cmp159 = icmp sge i32 %93, 0
  br i1 %cmp159, label %if.then161, label %if.else164

if.then161:                                       ; preds = %if.end147
  %94 = load double, double* %r, align 8
  %95 = load double, double* %x.addr, align 8
  %div162 = fdiv double %94, %95
  %sub163 = fsub double 1.000000e+00, %div162
  store double %sub163, double* %retval
  br label %return

if.else164:                                       ; preds = %if.end147
  %96 = load double, double* %r, align 8
  %97 = load double, double* %x.addr, align 8
  %div165 = fdiv double %96, %97
  %sub166 = fsub double %div165, 1.000000e+00
  store double %sub166, double* %retval
  br label %return

return:                                           ; preds = %if.else164, %if.then161, %if.else82, %if.then81, %if.else, %if.then70, %if.end16, %if.end13, %if.then9, %if.then
  %98 = load double, double* %retval
  ret double %98
}

; Function Attrs: nounwind readnone
declare double @fabs(double) #1

declare double @__ieee754_exp(double) #2

; Function Attrs: nounwind uwtable
define double @erfc(double %x) #0 {
entry:
  %retval = alloca double, align 8
  %x.addr = alloca double, align 8
  %hx = alloca i32, align 4
  %ix = alloca i32, align 4
  %R = alloca double, align 8
  %S = alloca double, align 8
  %P = alloca double, align 8
  %Q = alloca double, align 8
  %s = alloca double, align 8
  %y = alloca double, align 8
  %z = alloca double, align 8
  %r = alloca double, align 8
  store double %x, double* %x.addr, align 8
  %0 = bitcast double* %x.addr to i32*
  %add.ptr = getelementptr inbounds i32, i32* %0, i64 1
  %1 = load i32, i32* %add.ptr, align 4
  store i32 %1, i32* %hx, align 4
  %2 = load i32, i32* %hx, align 4
  %and = and i32 %2, 2147483647
  store i32 %and, i32* %ix, align 4
  %3 = load i32, i32* %ix, align 4
  %cmp = icmp sge i32 %3, 2146435072
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %4 = load i32, i32* %hx, align 4
  %shr = lshr i32 %4, 31
  %shl = shl i32 %shr, 1
  %conv = uitofp i32 %shl to double
  %5 = load double, double* %x.addr, align 8
  %div = fdiv double 1.000000e+00, %5
  %add = fadd double %conv, %div
  store double %add, double* %retval
  br label %return

if.end:                                           ; preds = %entry
  %6 = load i32, i32* %ix, align 4
  %cmp1 = icmp slt i32 %6, 1072365568
  br i1 %cmp1, label %if.then3, label %if.end37

if.then3:                                         ; preds = %if.end
  %7 = load i32, i32* %ix, align 4
  %cmp4 = icmp slt i32 %7, 1013972992
  br i1 %cmp4, label %if.then6, label %if.end7

if.then6:                                         ; preds = %if.then3
  %8 = load double, double* %x.addr, align 8
  %sub = fsub double 1.000000e+00, %8
  store double %sub, double* %retval
  br label %return

if.end7:                                          ; preds = %if.then3
  %9 = load double, double* %x.addr, align 8
  %10 = load double, double* %x.addr, align 8
  %mul = fmul double %9, %10
  store double %mul, double* %z, align 8
  %11 = load double, double* %z, align 8
  %12 = load double, double* %z, align 8
  %13 = load double, double* %z, align 8
  %14 = load double, double* %z, align 8
  %mul8 = fmul double %14, 0xBEF8EAD6120016AC
  %add9 = fadd double 0xBF77A291236668E4, %mul8
  %mul10 = fmul double %13, %add9
  %add11 = fadd double 0xBF9D2A51DBD7194F, %mul10
  %mul12 = fmul double %12, %add11
  %add13 = fadd double 0xBFD4CD7D691CB913, %mul12
  %mul14 = fmul double %11, %add13
  %add15 = fadd double 0x3FC06EBA8214DB68, %mul14
  store double %add15, double* %r, align 8
  %15 = load double, double* %z, align 8
  %16 = load double, double* %z, align 8
  %17 = load double, double* %z, align 8
  %18 = load double, double* %z, align 8
  %19 = load double, double* %z, align 8
  %mul16 = fmul double %19, 0xBED09C4342A26120
  %add17 = fadd double 0x3F215DC9221C1A10, %mul16
  %mul18 = fmul double %18, %add17
  %add19 = fadd double 0x3F74D022C4D36B0F, %mul18
  %mul20 = fmul double %17, %add19
  %add21 = fadd double 0x3FB0A54C5536CEBA, %mul20
  %mul22 = fmul double %16, %add21
  %add23 = fadd double 0x3FD97779CDDADC09, %mul22
  %mul24 = fmul double %15, %add23
  %add25 = fadd double 1.000000e+00, %mul24
  store double %add25, double* %s, align 8
  %20 = load double, double* %r, align 8
  %21 = load double, double* %s, align 8
  %div26 = fdiv double %20, %21
  store double %div26, double* %y, align 8
  %22 = load i32, i32* %hx, align 4
  %cmp27 = icmp slt i32 %22, 1070596096
  br i1 %cmp27, label %if.then29, label %if.else

if.then29:                                        ; preds = %if.end7
  %23 = load double, double* %x.addr, align 8
  %24 = load double, double* %x.addr, align 8
  %25 = load double, double* %y, align 8
  %mul30 = fmul double %24, %25
  %add31 = fadd double %23, %mul30
  %sub32 = fsub double 1.000000e+00, %add31
  store double %sub32, double* %retval
  br label %return

if.else:                                          ; preds = %if.end7
  %26 = load double, double* %x.addr, align 8
  %27 = load double, double* %y, align 8
  %mul33 = fmul double %26, %27
  store double %mul33, double* %r, align 8
  %28 = load double, double* %x.addr, align 8
  %sub34 = fsub double %28, 5.000000e-01
  %29 = load double, double* %r, align 8
  %add35 = fadd double %29, %sub34
  store double %add35, double* %r, align 8
  %30 = load double, double* %r, align 8
  %sub36 = fsub double 5.000000e-01, %30
  store double %sub36, double* %retval
  br label %return

if.end37:                                         ; preds = %if.end
  %31 = load i32, i32* %ix, align 4
  %cmp38 = icmp slt i32 %31, 1072955392
  br i1 %cmp38, label %if.then40, label %if.end75

if.then40:                                        ; preds = %if.end37
  %32 = load double, double* %x.addr, align 8
  %call = call double @fabs(double %32) #3
  %sub41 = fsub double %call, 1.000000e+00
  store double %sub41, double* %s, align 8
  %33 = load double, double* %s, align 8
  %34 = load double, double* %s, align 8
  %35 = load double, double* %s, align 8
  %36 = load double, double* %s, align 8
  %37 = load double, double* %s, align 8
  %38 = load double, double* %s, align 8
  %mul42 = fmul double %38, 0xBF61BF380A96073F
  %add43 = fadd double 0x3FA22A36599795EB, %mul42
  %mul44 = fmul double %37, %add43
  %add45 = fadd double 0xBFBC63983D3E28EC, %mul44
  %mul46 = fmul double %36, %add45
  %add47 = fadd double 0x3FD45FCA805120E4, %mul46
  %mul48 = fmul double %35, %add47
  %add49 = fadd double 0xBFD7D240FBB8C3F1, %mul48
  %mul50 = fmul double %34, %add49
  %add51 = fadd double 0x3FDA8D00AD92B34D, %mul50
  %mul52 = fmul double %33, %add51
  %add53 = fadd double 0xBF6359B8BEF77538, %mul52
  store double %add53, double* %P, align 8
  %39 = load double, double* %s, align 8
  %40 = load double, double* %s, align 8
  %41 = load double, double* %s, align 8
  %42 = load double, double* %s, align 8
  %43 = load double, double* %s, align 8
  %44 = load double, double* %s, align 8
  %mul54 = fmul double %44, 0x3F888B545735151D
  %add55 = fadd double 0x3F8BEDC26B51DD1C, %mul54
  %mul56 = fmul double %43, %add55
  %add57 = fadd double 0x3FC02660E763351F, %mul56
  %mul58 = fmul double %42, %add57
  %add59 = fadd double 0x3FB2635CD99FE9A7, %mul58
  %mul60 = fmul double %41, %add59
  %add61 = fadd double 0x3FE14AF092EB6F33, %mul60
  %mul62 = fmul double %40, %add61
  %add63 = fadd double 0x3FBB3E6618EEE323, %mul62
  %mul64 = fmul double %39, %add63
  %add65 = fadd double 1.000000e+00, %mul64
  store double %add65, double* %Q, align 8
  %45 = load i32, i32* %hx, align 4
  %cmp66 = icmp sge i32 %45, 0
  br i1 %cmp66, label %if.then68, label %if.else71

if.then68:                                        ; preds = %if.then40
  store double 0x3FC3D4FA80000000, double* %z, align 8
  %46 = load double, double* %z, align 8
  %47 = load double, double* %P, align 8
  %48 = load double, double* %Q, align 8
  %div69 = fdiv double %47, %48
  %sub70 = fsub double %46, %div69
  store double %sub70, double* %retval
  br label %return

if.else71:                                        ; preds = %if.then40
  %49 = load double, double* %P, align 8
  %50 = load double, double* %Q, align 8
  %div72 = fdiv double %49, %50
  %add73 = fadd double 0x3FEB0AC160000000, %div72
  store double %add73, double* %z, align 8
  %51 = load double, double* %z, align 8
  %add74 = fadd double 1.000000e+00, %51
  store double %add74, double* %retval
  br label %return

if.end75:                                         ; preds = %if.end37
  %52 = load i32, i32* %ix, align 4
  %cmp76 = icmp slt i32 %52, 1077673984
  br i1 %cmp76, label %if.then78, label %if.else167

if.then78:                                        ; preds = %if.end75
  %53 = load double, double* %x.addr, align 8
  %call79 = call double @fabs(double %53) #3
  store double %call79, double* %x.addr, align 8
  %54 = load double, double* %x.addr, align 8
  %55 = load double, double* %x.addr, align 8
  %mul80 = fmul double %54, %55
  %div81 = fdiv double 1.000000e+00, %mul80
  store double %div81, double* %s, align 8
  %56 = load i32, i32* %ix, align 4
  %cmp82 = icmp slt i32 %56, 1074191213
  br i1 %cmp82, label %if.then84, label %if.else115

if.then84:                                        ; preds = %if.then78
  %57 = load double, double* %s, align 8
  %58 = load double, double* %s, align 8
  %59 = load double, double* %s, align 8
  %60 = load double, double* %s, align 8
  %61 = load double, double* %s, align 8
  %62 = load double, double* %s, align 8
  %63 = load double, double* %s, align 8
  %mul85 = fmul double %63, 0xC023A0EFC69AC25C
  %add86 = fadd double 0xC054526557E4D2F2, %mul85
  %mul87 = fmul double %62, %add86
  %add88 = fadd double 0xC067135CEBCCABB2, %mul87
  %mul89 = fmul double %61, %add88
  %add90 = fadd double 0xC0644CB184282266, %mul89
  %mul91 = fmul double %60, %add90
  %add92 = fadd double 0xC04F300AE4CBA38D, %mul91
  %mul93 = fmul double %59, %add92
  %add94 = fadd double 0xC0251E0441B0E726, %mul93
  %mul95 = fmul double %58, %add94
  %add96 = fadd double 0xBFE63416E4BA7360, %mul95
  %mul97 = fmul double %57, %add96
  %add98 = fadd double 0xBF843412600D6435, %mul97
  store double %add98, double* %R, align 8
  %64 = load double, double* %s, align 8
  %65 = load double, double* %s, align 8
  %66 = load double, double* %s, align 8
  %67 = load double, double* %s, align 8
  %68 = load double, double* %s, align 8
  %69 = load double, double* %s, align 8
  %70 = load double, double* %s, align 8
  %71 = load double, double* %s, align 8
  %mul99 = fmul double %71, 0xBFAEEFF2EE749A62
  %add100 = fadd double 0x401A47EF8E484A93, %mul99
  %mul101 = fmul double %70, %add100
  %add102 = fadd double 0x405B28A3EE48AE2C, %mul101
  %mul103 = fmul double %69, %add102
  %add104 = fadd double 0x407AD02157700314, %mul103
  %mul105 = fmul double %68, %add104
  %add106 = fadd double 0x40842B1921EC2868, %mul105
  %mul107 = fmul double %67, %add106
  %add108 = fadd double 0x407B290DD58A1A71, %mul107
  %mul109 = fmul double %66, %add108
  %add110 = fadd double 0x4061350C526AE721, %mul109
  %mul111 = fmul double %65, %add110
  %add112 = fadd double 0x4033A6B9BD707687, %mul111
  %mul113 = fmul double %64, %add112
  %add114 = fadd double 1.000000e+00, %mul113
  store double %add114, double* %S, align 8
  br label %if.end148

if.else115:                                       ; preds = %if.then78
  %72 = load i32, i32* %hx, align 4
  %cmp116 = icmp slt i32 %72, 0
  br i1 %cmp116, label %land.lhs.true, label %if.end121

land.lhs.true:                                    ; preds = %if.else115
  %73 = load i32, i32* %ix, align 4
  %cmp118 = icmp sge i32 %73, 1075314688
  br i1 %cmp118, label %if.then120, label %if.end121

if.then120:                                       ; preds = %land.lhs.true
  store double 2.000000e+00, double* %retval
  br label %return

if.end121:                                        ; preds = %land.lhs.true, %if.else115
  %74 = load double, double* %s, align 8
  %75 = load double, double* %s, align 8
  %76 = load double, double* %s, align 8
  %77 = load double, double* %s, align 8
  %78 = load double, double* %s, align 8
  %79 = load double, double* %s, align 8
  %mul122 = fmul double %79, 0xC07E384E9BDC383F
  %add123 = fadd double 0xC09004616A2E5992, %mul122
  %mul124 = fmul double %78, %add123
  %add125 = fadd double 0xC083EC881375F228, %mul124
  %mul126 = fmul double %77, %add125
  %add127 = fadd double 0xC064145D43C5ED98, %mul126
  %mul128 = fmul double %76, %add127
  %add129 = fadd double 0xC031C209555F995A, %mul128
  %mul130 = fmul double %75, %add129
  %add131 = fadd double 0xBFE993BA70C285DE, %mul130
  %mul132 = fmul double %74, %add131
  %add133 = fadd double 0xBF84341239E86F4A, %mul132
  store double %add133, double* %R, align 8
  %80 = load double, double* %s, align 8
  %81 = load double, double* %s, align 8
  %82 = load double, double* %s, align 8
  %83 = load double, double* %s, align 8
  %84 = load double, double* %s, align 8
  %85 = load double, double* %s, align 8
  %86 = load double, double* %s, align 8
  %mul134 = fmul double %86, 0xC03670E242712D62
  %add135 = fadd double 0x407DA874E79FE763, %mul134
  %mul136 = fmul double %85, %add135
  %add137 = fadd double 0x40A3F219CEDF3BE6, %mul136
  %mul138 = fmul double %84, %add137
  %add139 = fadd double 0x40A8FFB7688C246A, %mul138
  %mul140 = fmul double %83, %add139
  %add141 = fadd double 0x409802EB189D5118, %mul140
  %mul142 = fmul double %82, %add141
  %add143 = fadd double 0x40745CAE221B9F0A, %mul142
  %mul144 = fmul double %81, %add143
  %add145 = fadd double 0x403E568B261D5190, %mul144
  %mul146 = fmul double %80, %add145
  %add147 = fadd double 1.000000e+00, %mul146
  store double %add147, double* %S, align 8
  br label %if.end148

if.end148:                                        ; preds = %if.end121, %if.then84
  %87 = load double, double* %x.addr, align 8
  store double %87, double* %z, align 8
  %88 = bitcast double* %z to i32*
  store i32 0, i32* %88, align 4
  %89 = load double, double* %z, align 8
  %sub149 = fsub double -0.000000e+00, %89
  %90 = load double, double* %z, align 8
  %mul150 = fmul double %sub149, %90
  %sub151 = fsub double %mul150, 5.625000e-01
  %call152 = call double @__ieee754_exp(double %sub151)
  %91 = load double, double* %z, align 8
  %92 = load double, double* %x.addr, align 8
  %sub153 = fsub double %91, %92
  %93 = load double, double* %z, align 8
  %94 = load double, double* %x.addr, align 8
  %add154 = fadd double %93, %94
  %mul155 = fmul double %sub153, %add154
  %95 = load double, double* %R, align 8
  %96 = load double, double* %S, align 8
  %div156 = fdiv double %95, %96
  %add157 = fadd double %mul155, %div156
  %call158 = call double @__ieee754_exp(double %add157)
  %mul159 = fmul double %call152, %call158
  store double %mul159, double* %r, align 8
  %97 = load i32, i32* %hx, align 4
  %cmp160 = icmp sgt i32 %97, 0
  br i1 %cmp160, label %if.then162, label %if.else164

if.then162:                                       ; preds = %if.end148
  %98 = load double, double* %r, align 8
  %99 = load double, double* %x.addr, align 8
  %div163 = fdiv double %98, %99
  store double %div163, double* %retval
  br label %return

if.else164:                                       ; preds = %if.end148
  %100 = load double, double* %r, align 8
  %101 = load double, double* %x.addr, align 8
  %div165 = fdiv double %100, %101
  %sub166 = fsub double 2.000000e+00, %div165
  store double %sub166, double* %retval
  br label %return

if.else167:                                       ; preds = %if.end75
  %102 = load i32, i32* %hx, align 4
  %cmp168 = icmp sgt i32 %102, 0
  br i1 %cmp168, label %if.then170, label %if.else171

if.then170:                                       ; preds = %if.else167
  store double 0.000000e+00, double* %retval
  br label %return

if.else171:                                       ; preds = %if.else167
  store double 2.000000e+00, double* %retval
  br label %return

return:                                           ; preds = %if.else171, %if.then170, %if.else164, %if.then162, %if.then120, %if.else71, %if.then68, %if.else, %if.then29, %if.then6, %if.then
  %103 = load double, double* %retval
  ret double %103
}

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind readnone "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind readnone }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.7.0 (trunk 234701)"}
