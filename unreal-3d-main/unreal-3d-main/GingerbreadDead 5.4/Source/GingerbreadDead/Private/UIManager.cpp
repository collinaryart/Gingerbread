// Fill out your copyright notice in the Description page of Project Settings.


#include "UIManager.h"

#include "FlamethrowerComponent.h"
#include "GingerbreadDead/GingerbreadDeadCharacter.h"

#include "Blueprint/WidgetLayoutLibrary.h"


// Sets default values
AUIManager::AUIManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Player = Cast<AGingerbreadDeadCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	//Player = HeatBarUI->Player;
}

int AUIManager::GetCurrentDamage()
{
	return CurrentDamage;
}

void AUIManager::SetCurrentDamage(int DamageValue)
{
	CurrentDamage = DamageValue;
}

void AUIManager::IncreaseHeat(float HeatValue)
{
	HeatBarUI->CurrentHeat = HeatBarUI->CurrentHeat + HeatValue;
}

// Called when the game starts or when spawned
void AUIManager::BeginPlay()
{
	Super::BeginPlay();
	
	HeatBarUI->AddToViewport();
	Player = HeatBarUI->Player;

	
}

// Called every frame
void AUIManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(HeatBarUI->CurrentHeat > 100)
	{
		HeatBarUI->CurrentHeat = 100;
	}

	float NewHeatLevel = HeatBarUI->CurrentHeat - (DeltaTime*5);
	
	if(HeatBarUI && NewHeatLevel >= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Heat: %f"), NewHeatLevel);
		HeatBarUI->UpdateHeatBar(NewHeatLevel);
	}

	if(NewHeatLevel >= 90)
	{
		HeatBarUI->UpdateHeatBarColour(FLinearColor(0.040f,0.58f,1.0f,1.0f));
		if(Player->GetHasRifle())
		{
			UFlamethrowerComponent* Flamethrower = Cast<UFlamethrowerComponent>(Player->HeldWeapon);
			Flamethrower->SetFlameLength(10000);

		}
		SetCurrentDamage(5);
	}
	else if(NewHeatLevel < 90 && NewHeatLevel > 70)
	{
		HeatBarUI->UpdateHeatBarColour(FLinearColor(0.130f,0.08f,1.0f,1.0f));
		if(Player->GetHasRifle())
		{
			UFlamethrowerComponent* Flamethrower = Cast<UFlamethrowerComponent>(Player->HeldWeapon);
			Flamethrower->SetFlameLength(7000);

		}
		SetCurrentDamage(3);
	}
	else if(NewHeatLevel <= 70 && NewHeatLevel > 40)
	{
		HeatBarUI->UpdateHeatBarColour(FLinearColor(1.0f,0.23f,0.50f,1.0f));
		if(Player->GetHasRifle())
		{
			UFlamethrowerComponent* Flamethrower = Cast<UFlamethrowerComponent>(Player->HeldWeapon);
			Flamethrower->SetFlameLength(5000);

		}
		SetCurrentDamage(2);
	}
	else if(NewHeatLevel <= 40)
	{
		HeatBarUI->UpdateHeatBarColour(FLinearColor(1.0f,0.59f,0.18f,1.0f));
		if(Player->GetHasRifle())
		{
			UFlamethrowerComponent* Flamethrower = Cast<UFlamethrowerComponent>(Player->HeldWeapon);
			Flamethrower->SetFlameLength(3000);

		}
		SetCurrentDamage(1);
	}
		


	//doing this because wasn't updating??
	//UWidgetLayoutLibrary::RemoveAllWidgets(GetWorld());
	//HeatBarUI->AddToViewport();

}

