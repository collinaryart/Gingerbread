// Fill out your copyright notice in the Description page of Project Settings.


#include "FlamethrowerComponent.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "NiagaraComponent.h"
#include "Camera/CameraComponent.h"

#include "GingerbreadDead/GingerbreadDeadCharacter.h"

void UFlamethrowerComponent::Use()
{
	Super::Use();

	if(NS_Flame)
	{
		if(Player)
		{
			//spawning a bit in front of the player so it comes out of gun
			//FVector SpawnLocation = GetComponentLocation() + Player->GetActorForwardVector() * 50;

			//spawn point at gun socket
			UNiagaraComponent* SpawnedEffect = Cast<UNiagaraComponent>(UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), NS_Flame, Player->HeldWeapon->GetSocketLocation(FName("Muzzle"))));

			//float FlameSize = 1;
			
			FVector ParticleVelocity = Player->GetFirstPersonCameraComponent()->GetForwardVector() * FlameLength;

			if(SpawnedEffect)
			{
				
				SpawnedEffect->SetVariableObject(FName("User.ClassToTell"), Player);

				//setting dynamic fire length
				//SpawnedEffect->SetVariableFloat(FName("User.FlameMinimum"), 200);
				//SpawnedEffect->SetVariableFloat(FName("User.FlameMaximum"), 300);
	
				SpawnedEffect->SetVariableVec3(FName("User.SpawnVelocity"), ParticleVelocity);
			}
		}
	}
	
}

void UFlamethrowerComponent::Detach()
{
	Super::Detach();
}

void UFlamethrowerComponent::Attach(AGingerbreadDeadCharacter* AttachPlayer)
{
	Super::Attach(AttachPlayer);

	if(!AttachPlayer)
	{
		return;
	}

	Player = Cast<AGingerbreadDeadCharacter>(AttachPlayer);
	Player->HeldWeapon = this;

	//taken from the tp_weaponcomponent default class
	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);
	AttachToComponent(Player->GetMesh1P(), AttachmentRules, FName(TEXT("GripPoint")));

	//setting true for animation
	Player->SetHasRifle(true);

	APlayerController* PlayerController = Cast<APlayerController>(Player->GetController());

	if(PlayerController)
	{
		UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if(SubSystem)
		{
			SubSystem->AddMappingContext(WeaponMappingContext,1);
		}
		UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent);
		if(EnhancedInputComponent)
		{
			EnhancedInputComponent->BindAction(ShootHoldAction, ETriggerEvent::Triggered, this, &UFlamethrowerComponent::Use);
		}
	}
	
}

void UFlamethrowerComponent::SetFlameLength(int Num)
{
	FlameLength = Num;
}
