; ModuleID = 'loop01.bc'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: nounwind uwtable
define void @foo() #0 {
entry:
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  store i32 -1, i32* %i, align 4
  store i32 0, i32* %j, align 4
  store i32 3, i32* %k, align 4
  store i32 0, i32* %j, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc.11, %entry
  %0 = load i32, i32* %j, align 4
  %cmp = icmp slt i32 %0, 5
  br i1 %cmp, label %for.body, label %for.end.13

for.body:                                         ; preds = %for.cond
  store i32 0, i32* %i, align 4
  br label %for.cond.1

for.cond.1:                                       ; preds = %for.inc.8, %for.body
  %1 = load i32, i32* %i, align 4
  %cmp2 = icmp slt i32 %1, 5
  br i1 %cmp2, label %for.body.3, label %for.end.10

for.body.3:                                       ; preds = %for.cond.1
  store i32 0, i32* %k, align 4
  br label %for.cond.4

for.cond.4:                                       ; preds = %for.inc, %for.body.3
  %2 = load i32, i32* %k, align 4
  %cmp5 = icmp slt i32 %2, 5
  br i1 %cmp5, label %for.body.6, label %for.end

for.body.6:                                       ; preds = %for.cond.4
  %3 = load i32, i32* %i, align 4
  %4 = load i32, i32* %j, align 4
  %add = add nsw i32 %3, %4
  %5 = load i32, i32* %k, align 4
  %add7 = add nsw i32 %add, %5
  br label %for.inc

for.inc:                                          ; preds = %for.body.6
  %6 = load i32, i32* %k, align 4
  %inc = add nsw i32 %6, 1
  store i32 %inc, i32* %k, align 4
  br label %for.cond.4

for.end:                                          ; preds = %for.cond.4
  br label %for.inc.8

for.inc.8:                                        ; preds = %for.end
  %7 = load i32, i32* %i, align 4
  %inc9 = add nsw i32 %7, 1
  store i32 %inc9, i32* %i, align 4
  br label %for.cond.1

for.end.10:                                       ; preds = %for.cond.1
  br label %for.inc.11

for.inc.11:                                       ; preds = %for.end.10
  %8 = load i32, i32* %j, align 4
  %inc12 = add nsw i32 %8, 1
  store i32 %inc12, i32* %j, align 4
  br label %for.cond

for.end.13:                                       ; preds = %for.cond
  store i32 0, i32* %i, align 4
  br label %for.cond.14

for.cond.14:                                      ; preds = %for.inc.17, %for.end.13
  %9 = load i32, i32* %i, align 4
  %cmp15 = icmp slt i32 %9, 10
  br i1 %cmp15, label %for.body.16, label %for.end.19

for.body.16:                                      ; preds = %for.cond.14
  %10 = load i32, i32* %i, align 4
  br label %for.inc.17

for.inc.17:                                       ; preds = %for.body.16
  %11 = load i32, i32* %i, align 4
  %inc18 = add nsw i32 %11, 1
  store i32 %inc18, i32* %i, align 4
  br label %for.cond.14

for.end.19:                                       ; preds = %for.cond.14
  store i32 0, i32* %j, align 4
  br label %for.cond.20

for.cond.20:                                      ; preds = %for.inc.30, %for.end.19
  %12 = load i32, i32* %j, align 4
  %cmp21 = icmp slt i32 %12, 5
  br i1 %cmp21, label %for.body.22, label %for.end.32

for.body.22:                                      ; preds = %for.cond.20
  store i32 0, i32* %i, align 4
  br label %for.cond.23

for.cond.23:                                      ; preds = %for.inc.27, %for.body.22
  %13 = load i32, i32* %i, align 4
  %cmp24 = icmp slt i32 %13, 5
  br i1 %cmp24, label %for.body.25, label %for.end.29

for.body.25:                                      ; preds = %for.cond.23
  %14 = load i32, i32* %i, align 4
  %15 = load i32, i32* %j, align 4
  %add26 = add nsw i32 %14, %15
  br label %for.inc.27

for.inc.27:                                       ; preds = %for.body.25
  %16 = load i32, i32* %i, align 4
  %inc28 = add nsw i32 %16, 1
  store i32 %inc28, i32* %i, align 4
  br label %for.cond.23

for.end.29:                                       ; preds = %for.cond.23
  br label %for.inc.30

for.inc.30:                                       ; preds = %for.end.29
  %17 = load i32, i32* %j, align 4
  %inc31 = add nsw i32 %17, 1
  store i32 %inc31, i32* %j, align 4
  br label %for.cond.20

for.end.32:                                       ; preds = %for.cond.20
  ret void
}

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.7.0 (tags/RELEASE_370/final)"}
