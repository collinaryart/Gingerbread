// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HeatBarWidget.h"
#include "GameFramework/Actor.h"
#include "UIManager.generated.h"

class AGingerbreadDeadCharacter;


UCLASS()
class GINGERBREADDEAD_API AUIManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUIManager();
	
	AGingerbreadDeadCharacter* Player;

	int CurrentDamage = 1;

	int GetCurrentDamage();
	void SetCurrentDamage(int DamageValue);

	UPROPERTY(EditAnywhere)
		UHeatBarWidget* HeatBarUI;

	void IncreaseHeat(float HeatValue);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
