// Fill out your copyright notice in the Description page of Project Settings.


#include "GingerbreadDeadGameState.h"

float AGingerbreadDeadGameState::GetMultiplier(APlayerState* PlayerState)
{
	float FlameMultiplier = 0;
	
	return FMath::Clamp(FlameMultiplier, 0.f, 1.0f);
}
