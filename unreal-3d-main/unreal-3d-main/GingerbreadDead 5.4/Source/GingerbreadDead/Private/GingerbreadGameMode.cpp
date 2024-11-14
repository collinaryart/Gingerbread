// Fill out your copyright notice in the Description page of Project Settings.


#include "GingerbreadDead/Public/GingerbreadGameMode.h"

AGingerbreadGameMode::AGingerbreadGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGingerbreadGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//tick to decrease heat level over time
}
