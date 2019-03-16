// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(TPE, Log, All);

#define TPE_LOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))
#define TPE_LOG_S(Verbosity) UE_LOG(TPE, Verbosity, TEXT("%s"), *TPE_LOG_CALLINFO)
#define TPE_LOG(Verbosity, Format, ...) UE_LOG(TPE, Verbosity, TEXT("%s%s"), *TPE_LOG_CALLINFO, *FString::Printf(TEXT(Format), ##__VA_ARGS__))

#define TPE_CHECK(Expr, ...) { if(!(Expr)) { TPE_LOG(Error, "ASSERTION : %s", TEXT("'"#Expr"'")); return __VA_ARGS__; } }
