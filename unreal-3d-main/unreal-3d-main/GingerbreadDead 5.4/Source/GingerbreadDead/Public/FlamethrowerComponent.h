// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemComponent.h"
#include "NiagaraSystem.h"
#include "GingerbreadDead/GingerbreadDeadCharacter.h"
#include "FlamethrowerComponent.generated.h"

/**
 * 
 */

class UInputAction;
class UInputMappingContext;

UCLASS()
class GINGERBREADDEAD_API UFlamethrowerComponent : public UItemComponent
{
	GENERATED_BODY()

public:

	virtual void Use() override;
	virtual void Detach() override;
	virtual void Attach(AGingerbreadDeadCharacter* AttachPlayer) override;


	void SetFlameLength(int Num);
	int FlameLength = 2000;

	UPROPERTY(EditAnywhere)
		UInputMappingContext* WeaponMappingContext;

	UPROPERTY(EditAnywhere)
		UInputAction* ShootHoldAction;
	
	UPROPERTY(EditAnywhere)
		UNiagaraSystem* NS_Flame;

};
