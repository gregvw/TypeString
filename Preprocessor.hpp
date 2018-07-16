#pragma once
#ifndef PREPROCESSOR_HPP
#define PREPROCESSOR_HPP

#define PREPROC_ARRAY_1(T)  T##0
#define PREPROC_ARRAY_2(T)  PREPROC_ARRAY_1(T)  , T##1
#define PREPROC_ARRAY_3(T)  PREPROC_ARRAY_2(T)  , T##2
#define PREPROC_ARRAY_4(T)  PREPROC_ARRAY_3(T)  , T##3
#define PREPROC_ARRAY_5(T)  PREPROC_ARRAY_4(T)  , T##4
#define PREPROC_ARRAY_6(T)  PREPROC_ARRAY_5(T)  , T##5
#define PREPROC_ARRAY_7(T)  PREPROC_ARRAY_6(T)  , T##6
#define PREPROC_ARRAY_8(T)  PREPROC_ARRAY_7(T)  , T##7
#define PREPROC_ARRAY_9(T)  PREPROC_ARRAY_8(T)  , T##8
#define PREPROC_ARRAY_10(T) PREPROC_ARRAY_9(T)  , T##9
#define PREPROC_ARRAY_11(T) PREPROC_ARRAY_10(T) , T##10
#define PREPROC_ARRAY_12(T) PREPROC_ARRAY_11(T) , T##11
#define PREPROC_ARRAY_13(T) PREPROC_ARRAY_12(T) , T##12
#define PREPROC_ARRAY_14(T) PREPROC_ARRAY_13(T) , T##13
#define PREPROC_ARRAY_15(T) PREPROC_ARRAY_14(T) , T##14
#define PREPROC_ARRAY_16(T) PREPROC_ARRAY_15(T) , T##15
#define PREPROC_ARRAY_17(T) PREPROC_ARRAY_16(T) , T##16
#define PREPROC_ARRAY_18(T) PREPROC_ARRAY_17(T) , T##17
#define PREPROC_ARRAY_19(T) PREPROC_ARRAY_18(T) , T##18
#define PREPROC_ARRAY_20(T) PREPROC_ARRAY_19(T) , T##19
#define PREPROC_ARRAY_21(T) PREPROC_ARRAY_20(T) , T##20
#define PREPROC_ARRAY_22(T) PREPROC_ARRAY_21(T) , T##21
#define PREPROC_ARRAY_23(T) PREPROC_ARRAY_22(T) , T##22
#define PREPROC_ARRAY_24(T) PREPROC_ARRAY_23(T) , T##23
#define PREPROC_ARRAY_25(T) PREPROC_ARRAY_24(T) , T##24
#define PREPROC_ARRAY_26(T) PREPROC_ARRAY_25(T) , T##25
#define PREPROC_ARRAY_27(T) PREPROC_ARRAY_26(T) , T##26
#define PREPROC_ARRAY_28(T) PREPROC_ARRAY_27(T) , T##27
#define PREPROC_ARRAY_29(T) PREPROC_ARRAY_28(T) , T##28
#define PREPROC_ARRAY_30(T) PREPROC_ARRAY_29(T) , T##29
#define PREPROC_ARRAY_31(T) PREPROC_ARRAY_30(T) , T##30
#define PREPROC_ARRAY_32(T) PREPROC_ARRAY_31(T) , T##31
#define PREPROC_ARRAY_N(N,T) PREPROC_ARRAY_##N(T)

#define PREPROC_REPEAT_1(T)  T
#define PREPROC_REPEAT_2(T)  PREPROC_REPEAT_1(T)  , T 
#define PREPROC_REPEAT_3(T)  PREPROC_REPEAT_2(T)  , T
#define PREPROC_REPEAT_4(T)  PREPROC_REPEAT_3(T)  , T
#define PREPROC_REPEAT_5(T)  PREPROC_REPEAT_4(T)  , T
#define PREPROC_REPEAT_6(T)  PREPROC_REPEAT_5(T)  , T
#define PREPROC_REPEAT_7(T)  PREPROC_REPEAT_6(T)  , T
#define PREPROC_REPEAT_8(T)  PREPROC_REPEAT_7(T)  , T
#define PREPROC_REPEAT_9(T)  PREPROC_REPEAT_8(T)  , T
#define PREPROC_REPEAT_10(T) PREPROC_REPEAT_9(T)  , T
#define PREPROC_REPEAT_11(T) PREPROC_REPEAT_10(T) , T
#define PREPROC_REPEAT_12(T) PREPROC_REPEAT_11(T) , T
#define PREPROC_REPEAT_13(T) PREPROC_REPEAT_12(T) , T
#define PREPROC_REPEAT_14(T) PREPROC_REPEAT_13(T) , T
#define PREPROC_REPEAT_15(T) PREPROC_REPEAT_14(T) , T
#define PREPROC_REPEAT_16(T) PREPROC_REPEAT_15(T) , T
#define PREPROC_REPEAT_17(T) PREPROC_REPEAT_16(T) , T
#define PREPROC_REPEAT_18(T) PREPROC_REPEAT_17(T) , T
#define PREPROC_REPEAT_19(T) PREPROC_REPEAT_18(T) , T
#define PREPROC_REPEAT_20(T) PREPROC_REPEAT_19(T) , T
#define PREPROC_REPEAT_21(T) PREPROC_REPEAT_20(T) , T
#define PREPROC_REPEAT_22(T) PREPROC_REPEAT_21(T) , T
#define PREPROC_REPEAT_23(T) PREPROC_REPEAT_22(T) , T
#define PREPROC_REPEAT_24(T) PREPROC_REPEAT_23(T) , T
#define PREPROC_REPEAT_25(T) PREPROC_REPEAT_24(T) , T
#define PREPROC_REPEAT_26(T) PREPROC_REPEAT_25(T) , T
#define PREPROC_REPEAT_27(T) PREPROC_REPEAT_26(T) , T
#define PREPROC_REPEAT_28(T) PREPROC_REPEAT_27(T) , T
#define PREPROC_REPEAT_29(T) PREPROC_REPEAT_28(T) , T
#define PREPROC_REPEAT_30(T) PREPROC_REPEAT_29(T) , T
#define PREPROC_REPEAT_31(T) PREPROC_REPEAT_30(T) , T
#define PREPROC_REPEAT_32(T) PREPROC_REPEAT_31(T) , T

#define PREPROC_REPEAT_N(N,T) PREPROC_REPEAT_##N(T)

#define TEMPLATE_DECL(N)  PREPROC_ARRAY_N(N,typename T)
#define TEMPLATE_PARAM(N) PREPROC_ARRAY_N(N,T)

#endif  // PREPROCESSOR_HPP
